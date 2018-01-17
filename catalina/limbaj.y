%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functii.h"       
 
extern FILE* yyin;                 
extern char* yytext;    
extern int yylineno;         

int ID_values[10000];                       
char ID_names[10000][1000]; 
char S[10000];
char P[10000];
int initialized[10000];            
int contor=0;                    

int poz;                                         
char varx[1000];
       
int error=0; 
//functii de verificat erori    
void check_declared();      
void can_use();             
void check_initialized(); 
void afis_erori();         
%}

%union
{
    int ID_value;
    char *ID_name;
}

%token ASIGN VAR RETURN PRINT FCT_MAIN 
%token MAXIM3 DIVIZOR_COMUN MULTIPLU_COMUN       
%token <ID_value> NR <ID_name>ID                                                 
                                                                                      
%type <ID_value> expresie functie_maxim_3 functie_divizor_comun functie_multiplu_comun apel_functie                
                                                                                           
%left '+' '-'           
%left '*' '/'
%nonassoc UMINUS       
%start program        
%%

program : declartii FCT_MAIN '{' instructiuni '}' { 
	if(error==0)		
		{printf("Compilation finished successfully.\n"); printf("%s", P); }
	else { afis_erori(); } 
	}
	| FCT_MAIN '{' instructiuni '}' {  if(error==0){ printf("Compilation finished successfully.\n"); 						printf("%s", P);} }
        ;


declartii : declaratie
          | declartii declaratie
          ;

declaratie : VAR ID ASIGN expresie ';' {strcpy(ID_names[contor], $2);
					ID_values[contor]=$4;
					initialized[contor]=1;
					check_declared();
					contor++;
					}
							                 
	   | VAR ID ';' {strcpy(ID_names[contor], $2);
				initialized[contor]=0;
				check_declared();
				contor++;
				}
	   | ID ASIGN expresie ';' {  char s[100]; sprintf(s, "LINE: %d-> Intructiune incorecta! Sectiune doar de declarari!\n",yylineno);  strcat(S, s); error+=1;}
	   ;

instructiuni: instructiune ';'
	    | instructiuni instructiune ';'
  	    ;

instructiune: ID ASIGN expresie {strcpy(varx, $1);
				can_use();
				ID_values[poz]=$3;
				initialized[poz]=1;
				}       					 
	    | PRINT '(' expresie ')'   { char p[100]; sprintf(p, "Line:%d-> %d\n",yylineno, $3);	strcat(P, p); }
	    | VAR ID { char s[100]; sprintf(s, "LINE: %d-> Declaratie incorecta! Sectiune doar de instructiuni!!\n",yylineno); strcat(S, s); error+=1;}
	    | VAR ID  ASIGN expresie { char s[100]; sprintf(s, "LINE: %d-> Declaratie incorecta!!!!! Sectiune doar de instructiuni!!\n",yylineno);  strcat(S, s); error+=1;}	
            ;

expresie: NR { $$=$1; }
	| ID { strcpy(varx, $1);
		can_use();
		check_initialized();
		$$=ID_values[poz];
		}
	| apel_functie
	| '-' expresie %prec UMINUS        { $$ = -$2; }
	| expresie '+' expresie            { $$ = $1 + $3; }
	| expresie '-' expresie            { $$ = $1 - $3; }
	| expresie '*' expresie            { $$ = $1 * $3; }
	| expresie '/' expresie            { $$ = $1 / $3; }
	| '(' expresie ')'                 { $$ = $2; }
        ;


apel_functie: functie_maxim_3  
	    | functie_divizor_comun
	    | functie_multiplu_comun
            ;

functie_maxim_3: MAXIM3 '(' expresie ',' expresie ',' expresie ')' { $$=MAX3 ( $3, $5, $7); }
		;

functie_divizor_comun: DIVIZOR_COMUN '(' expresie ',' expresie ')'  { $$=GCD ( $3, $5); }
			;

functie_multiplu_comun: MULTIPLU_COMUN '(' expresie ',' expresie ')'  { $$=LCM ( $3, $5); }
			;

%%

int yyerror(char * s, int i)
{
	fprintf(stderr, "LINE: %d %s: ", yylineno, s);
	
}

void check_declared()
{
	int i;
	for(i=0; i<contor; i++)
	if(strcmp(ID_names[contor], ID_names[i])==0)
	{
		//fprintf(stderr, "LINE: %d-> Variabila '%s' a mai fost declarata!\n", yylineno, ID_names[contor]);
char s[100]; 
sprintf(s, "LINE: %d-> Variabila '%s' a mai fost declarata!\n", yylineno, ID_names[contor]);
strcat(S, s);	

	//exit(1);
//strcat(S, "-> Variabila '"); strcat(S, ID_names[contor]); strcat(S, "' a mai fost declarata!\n");	
		 error+=1;
	}
}

void can_use()
{
	int i, gasit=0;
	for(i=0; i<contor; i++)
	{  
		if(strcmp(varx, ID_names[i])==0)
		{  
		    gasit=1;
		    poz=i;
		}
	}
	if(!gasit)
	{
		//fprintf(stderr, "LINE: %d-> Variabila '%s' nu a fost declarata!\n",yylineno, varx);
		//exit(1);
char s[100]; 
sprintf(s, "LINE: %d-> Variabila '%s' nu a fost declarata!\n",yylineno, varx);
strcat(S, s);
		//strcat(S, "Variabila '"); strcat(S, varx); strcat(S, "' nu a fost declarata!\n");
error+=1;
	}   
}

void check_initialized()
{
	if(initialized[poz])
		return;
	else
	{
		//fprintf(stderr, "LINE: %d-> Variabila '%s' nu este initializata!\n",yylineno, varx);
		//exit(1);  
char s[100]; 
sprintf(s, "LINE: %d-> Variabila '%s' nu este initializata!\n",yylineno, varx);
strcat(S, s);		
error+=1;
	}  
}

void afis_erori()
{
	printf("%s", S);
}


int main(int argc, char** argv)
{
    yyin=fopen(argv[1],"r");
    yyparse();
}
