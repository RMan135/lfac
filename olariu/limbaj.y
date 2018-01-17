%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID TIP ASSIGN NR START_PROGRAM SFARSIT_PROGRAM START_FUNCTIE SFARSIT_FUNCTIE CLASS ACCES START_CLASA SFARSIT_CLASA OPERATIE OPERATOR_COMPARARE VAL_BOOL DACA ATUNCI SFARSIT_ATUNCI ALTFEL SFARSIT_ALTFEL EXECUTA CAT_TIMP SFARSIT_CAT_TIMP PENTRU SFARSIT_PENTRU 
%start progr
%left OPERATIE
%left OPERATOR_COMPARARE
%left VAL_BOOL
%%
progr: declaratii bloc {printf("program corect sintactic\n");}
     ;

declaratii :  declaratie ';'
	   | declaratii declaratie ';'
	   ;
declaratie : declarare_variabila
	   | functie corp_functie
	   | declarare_clasa
           ;
declarare_variabila : TIP ID 
	             | TIP ID ASSIGN asignare_valoare
		    
		     ;
asignare_valoare: NR 
		| VAL_BOOL
 	        ;

/* functie */
functie : TIP ID '(' lista_param ')'
        | TIP ID '(' ')'
corp_functie : START_FUNCTIE list SFARSIT_FUNCTIE
lista_param : param
            | lista_param ','  param 
            ;
param : TIP ID
     	    ; 

/* bloc */
bloc : START_PROGRAM list SFARSIT_PROGRAM  
     ;
     
/* lista instructiuni */
list :  statement ';' 
     | list statement ';'
     | bloc_instructiuni
     | list  bloc_instructiuni
     ;

/* instructiune */
statement: ID ASSIGN expresie  		 
         | ID '(' lista_apel ')'
         ;
        
lista_apel : termen
           | lista_apel ',' termen
           ;

expresie : termen
	 | expresie OPERATIE expresie
	 | '('expresie OPERATIE expresie')' 
;
termen : NR 
	| ID ;
bloc_instructiuni: DACA conditia ATUNCI list SFARSIT_ATUNCI 
	        		 ALTFEL list SFARSIT_ALTFEL
	  | CAT_TIMP conditia
	    list 
	    SFARSIT_CAT_TIMP
          | PENTRU '('statement conditia statement ')' EXECUTA 
		list
	    SFARSIT_PENTRU
	  ;
conditia : conditia OPERATOR_COMPARARE conditia
	 |termen
	 ;

/*CLASE */
declarare_clasa : CLASS ID START_CLASA  ACCES declaratii SFARSIT_CLASA
	        ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 