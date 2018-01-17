%{
#include <stdio.h>
#include <string.h>
#include "functie.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
struct structB{
    char* nume;
    int val;
    int asignare;
}B[1000];
int indexV=0;

int getID(char* nume)
{
    int i;
    for (i=0; i<indexV; i++)
	if(strcmp(B[i].nume, nume)==0)
	return i;
    return -1;
}
%}
%union{
    int intval;
    char* strval;
}

%token <strval>ID START END HEADER ASSIGN NR PRINT VAR MAX FUNC IF START_ST END_ST WHILE FOR OP_LOGIC 
%type <intval>e
%type <intval>apel

%start progr
%left '+'
%left '-'
%left '*'
%left '/'
%left '%'
%%

progr : header declaratii main subprogram
      ;
      
header : HEADER
       | header HEADER
       ;

declaratii : declaratie ';'
           | declaratii declaratie ';'
           
declaratie : VAR ID{
		int id;
		id=getID($2);
		if(id!=-1) {
		    printf("Error on line %d. %s is already declared.\n",yylineno,$2);
		    return -1;
		} 
		B[indexV].nume=(char*) malloc(100);
		strcpy(B[indexV].nume,$2); indexV++;
	    }
	   | VAR ID ASSIGN NR{
		int id; 
		id=getID($2);
		if (id!=-1)
		{ 
		    printf("Error on line %d. %s is already declared.\n",yylineno,$2);
		    return -1;
		}
		B[indexV].nume=(char*)malloc(100);
		B[indexV].asignare=1;
		B[indexV].val=$4;
		strcpy(B[indexV].nume,$2); indexV++;
	   
	   }
	   ;

main : START instructiuni END
     ;
     
instructiuni : asignare ';'
	         | print ';'
             | instructiuni asignare ';'
             | instructiuni print ';'
             | apel ';'
             | instructiuni apel ';'
             | instructiuni IF'('e OP_LOGIC e ')' block
             | IF'('e OP_LOGIC e ')' block  
             | instructiuni WHILE '(' e OP_LOGIC e ')' block
             | WHILE '(' e OP_LOGIC e ')' block 
             | instructiuni FOR '(' asignare ';' e OP_LOGIC e ';' e ')' block
       	     | FOR '(' asignare ';' e OP_LOGIC e';' e '=' e ')' block
             ;
block: START_ST instructiuni END_ST


subprogram : FUNC ;
			 
apel : MAX '(' e ',' e ')' {
	    int a=$3; int b=$5;
	    int rezultat=max(a,b);
	    $$=rezultat;
	} 
     ;

asignare : ID ASSIGN e {
                int id;
                id=getID($1);
                if(id==-1){
            	    printf("Error on line %d.%s is not declared.\n",yylineno,$1);
            	    return -1;
                }
		B[id].val=$3;
		B[id].asignare=1; 
	    } 
		
		| VAR ID ASSIGN NR{
		int id; 
		id=getID($2);
		if (id!=-1)
		{ 
		    printf("Error on line %d. %s is already declared.\n",yylineno,$2);
		    return -1;
		}
		B[indexV].nume=(char*)malloc(100);
		B[indexV].asignare=1;
		B[indexV].val=$4;
		strcpy(B[indexV].nume,$2); indexV++;
        
		} 
		 ;

e : '(' e ')' {$$=$2;}
  | e '+' e   {$$=$1 + $3;}
  | e '*' e {$$=$1 * $3;}
  | e '-' e {$$=$1 - $3;}
  | e '/' e {$$=$1 / $3;}
  | e '%' e {$$=$1 % $3;}
  | ID { 
	int id;
	id=getID($1);
	if(id==-1){
	    printf("Error on line %d. %s is not declared.\n", yylineno, $1);
	    return -1;
	}
	if (B[id].asignare==1) $$=B[id].val;
	else {
	    printf("Error on line %d. %s is not initialized.\n",yylineno,$1);
	    return -1;
	}
    }
  | NR { $$=$1;}
  | apel {$$=$1; }
  ;
  
  
print : PRINT '(' ID ')'{
	    int id;
	    id=getID($3);
	    if(id==-1) {
		printf("Error on line %d. %s is not declared!\n",yylineno,$3);
		return -1;
	    }
	    printf("%s = %d\n",B[id].nume, B[id].val);
	} 
	| PRINT '(' ID'+'ID ')'{
	   int id1, id2;
	   id1=getID($3);
	   id2=getID($5);
	    if(id1==-1|| id2==-1) {
		printf("Error on line %d. %s is not declared!\n",yylineno,$3);
		}
		printf("%d\n", B[id1].val+B[id2].val);
	} ';'
      ;


      
%%
int yyerror(char* s){
    printf("Eroare la linia %d\n",yylineno);
}

int main(int argc, char** argv){
    yyin=fopen(argv[1],"r");
    yyparse();
}

               
