%{
#include <stdio.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token TIP OPERATORI_LOGICI TIP_CLASA PUBLIC PRIVATE PROTECTED RETURN ASSIGN BGIN_PRGR END_PRGR BGIN_CLASS END_CLASS BGIN_FUNC END_FUNC
WHILE EXECUTE END_WHILE DO CONDITIE_FINAL_DO IF THEN END_THEN ELSE END_ELSE FOR END_FOR ID NR NR_REAL NR_NEG 
%start program
 %right  '='
 %left  '+'  '-'
 %left  '*'  '/' '%'
%%
program: declaratii bloc {printf("program corect sintactic\n");}
     ;

declaratii :  declaratie ';'
	   | declaratii declaratie ';'
	   ;
declaratie : declaratie_variabila
           | declaratie_vector
           //| declaratie_matrice
           | declaratie_clasa corp_clasa 
           | declaratie_functie corp_functie 
           | declaratie_functie
           ;  

declaratie_variabila : TIP ID // conectare cu fisierul .l
                     | TIP ID ASSIGN NR
                     | TIP ID ASSIGN NR_NEG
                     | TIP ID ASSIGN NR_REAL
                     ;
declaratie_vector : TIP ID '[' NR ']'
                  ;
declaratie_matrice : TIP ID '[' NR ']' '[' NR ']'

/* FUNCTIE */
                   ;
declaratie_functie : TIP ID '(' ')'
                   | TIP ID '('lista_param ')'
                   ;
corp_functie : BGIN_FUNC continut_functie END_FUNC
             ;
continut_functie : declaratie_variabile_functie
                 | fbloc_logic 
                 | continut_functie fbloc_logic   
                 | statement ';'
                 | continut_functie statement ';'
                 | RETURN expresie ';' 
                 ;

declaratie_variabile_functie : declaratii_functie ';'
                   | declaratie_variabile_functie
declaratii_functie ';'
                   ; 
declaratii_functie : declaratie_variabila
                   | declaratie_vector
                   | declaratie_matrice
                   ;  

fbloc_logic : IF '(' conditie_logica ')' THEN continut_functie END_THEN
            | IF '(' conditie_logica ')' THEN continut_functie END_THEN ELSE continut_functie END_ELSE
            | WHILE '(' conditie_logica ')' EXECUTE continut_functie END_WHILE
            | DO continut_functie CONDITIE_FINAL_DO '(' conditie_logica ')'
            | FOR ID ASSIGN NR WHILE '(' conditie_logica ')' EXECUTE continut_functie END_FOR
            ;
/*FINAL FUNCTIE*/

lista_param : param
            | lista_param ','  param 
            ;
            
param : TIP ID
      ; 

/*CLASA*/
declaratie_clasa : TIP_CLASA ID 
                 ;

corp_clasa : BGIN_CLASS continut_clasa END_CLASS
           ;

continut_clasa : tip_constrangere declaratie_variabile_clasa
               | tip_constrangere declaratie_functie ';'
               | continut_clasa tip_constrangere declaratie_functie ';'
               | tip_constrangere declaratie_functie corp_functie ';' /*in cazul in care vrem sa explicitam metodele in clasa*/
               | continut_clasa tip_constrangere declaratie_functie corp_functie ';'                
               ;

tip_constrangere : PUBLIC
                 | PRIVATE
                 | PROTECTED
                 ;

declaratie_variabile_clasa : declaratii_clasa ';'
                           | declaratie_variabile_clasa declaratii_clasa ';'
                           ;
declaratii_clasa : declaratie_variabila
                 | declaratie_vector
                 | declaratie_matrice
                 ;
/*SFARSIT CLASA*/

\\print
print: PRINT '(' ID ')'
	| PRINT '(' NR ')' { printf ("%d\n", $3)}
	;
/* BLOC */
bloc : BGIN_PRGR list END_PRGR  
     ;
     
/* lista instructiuni&blocuri */
list :  statement ';' 
     | list statement ';'
     | bloc_logic 
     | list bloc_logic 
     ;

/* instructiune */
statement: ID '(' lista_param2 ')'
         | ID '.' ID '(' lista_param2 ')'
         | ID '.' ID '(' ')'
         | ID '.' ID ASSIGN NR
         | ID '.' ID ASSIGN NR_NEG
         | ID '.' ID ASSIGN NR_REAL
         | ID ASSIGN ID '(' lista_param2 ')'
         | ID ASSIGN expresie 
         | ID '[' NR ']' ASSIGN NR
         | ID '[' NR ']' ASSIGN NR_NEG
         | ID '[' NR ']' ASSIGN NR_REAL
         | ID '[' NR ']''[' NR ']' ASSIGN NR
         | ID '[' NR ']''[' NR ']' ASSIGN NR_NEG
         | ID '[' NR ']''[' NR ']' ASSIGN NR_REAL
       
         ;
        


expresie: '(' expresie '+' expresie ')'
        | '(' expresie '-' expresie ')'
        | '(' expresie '*' expresie ')' 
        | '(' expresie '/' expresie ')'
        | '(' expresie '%' expresie ')'
		| '(' expresie '&&' expresie ')'
		| '(' expresie '||' expresie ')'
		| '!' expresie
        | e
        ;
//operatii intre stringuri
		expresie_caractere : '(' expresie_caractere ')' {$$ = $2;}
	| expresie_caractere '+' expresie_caractere {
			char* s=malloc(sizeof(char) * (strlen($1) + strlen($3) +2)); 
			strcpy(s,$1); 
			strcat(s,$3); 
			$$=s;}
	| expresie_caractere '-' expresie_caractere {
			if (strlen($1) >= strlen($3))
			{
				char* s=malloc(sizeof(char) * (strlen($1) + 2));
				strcpy(s,$1);
				if (strstr(s,$3) != NULL)
				{
				   strcpy(strstr(s,$3),strstr(s,$3)+strlen($3));
				   $$ = s;
				}else
				{
				   $$ = $1;
				}
			}
			else { $$ = $1;}
		      }
e : NR
  | NR_NEG
  | ID 
  | NR_REAL
  | declaratie_functie
  | declaratie_matrice
  | ID '[' NR ']' /*vector*/
  | ID '.' ID
  | ID '.' ID '(' lista_param2 ')'
  ;

lista_param2 : param2
             | lista_param2 ','  param2 /*aici putem apela functiile si direct cu numere ex. f(2,-3) */
             ;
            
param2 : TIP ID
       | e
       ;
conditie_logica : expresie OPERATORI_LOGICI expresie
                | '(' conditie_logica ')' OPERATORI_LOGICI expresie /* ex. (a+b)<5 == 3*/
                | expresie OPERATORI_LOGICI '(' conditie_logica ')'
                | '(' conditie_logica ')' OPERATORI_LOGICI '(' conditie_logica ')'
                ;

bloc_logic : IF '(' conditie_logica ')' THEN list END_THEN
            | IF '(' conditie_logica ')' THEN list END_THEN ELSE statement END_ELSE
            | WHILE '(' conditie_logica ')' EXECUTE list END_WHILE
            | DO list CONDITIE_FINAL_DO '(' conditie_logica ')'
            | FOR ID ASSIGN NR WHILE '(' conditie_logica ')' EXECUTE list END_FOR
            ;




%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 
1