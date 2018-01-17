%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID TIP ASSIGN NR START_PROGRAM SFARSIT_PROGRAM START_FUNCTIE SFARSIT_FUNCTIE
%start progr
%%
progr: declaratii bloc {printf("program corect sintactic\n");}
     ;

declaratii :  declaratie ';'
	   | declaratii declaratie ';'
	   ;
declaratie : TIP ID 
	   | functie
           | TIP ID '(' lista_param ')'
           | TIP ID '(' ')'
           ;
lista_param : param
            | lista_param ','  param 
            ;
            
param : TIP ID
      ; 
/* functie */
functie : START_FUNCTIE list SFARSIT_FUNCTIE


/* bloc */
bloc : START_PROGRAM list SFARSIT_PROGRAM  
     ;
     
/* lista instructiuni */
list :  statement ';' 
     | list statement ';'
     ;

/* instructiune */
statement: ID ASSIGN ID
         | ID ASSIGN NR  		 
         | ID '(' lista_apel ')'
         ;
        
lista_apel : NR
           | lista_apel ',' NR
           ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 