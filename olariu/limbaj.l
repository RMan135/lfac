%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
"boolean"|"constanta"|"intreg"|"real"|"caracter"|"sir_caractere" {return TIP;}
"start_program" {return START_PROGRAM;}
"sfarsit_program" {return SFARSIT_PROGRAM;}
"start_functie" {return START_FUNCTIE;}
"sfarsit_functie" {return SFARSIT_FUNCTIE;}
"start_clasa" {return START_CLASA;}
"sfarsit_clasa" {return SFARSIT_CLASA;}
"class" {return CLASS;}
"public:"|"private:"|"protected:" {return ACCES;}
"daca" {return DACA;}
"atunci" {return ATUNCI;}
"sfarsit_atunci" {return SFARSIT_ATUNCI;}
"altfel" {return ALTFEL;}
"sfarsit_altfel" {return SFARSIT_ALTFEL;}

"cat_timp" {return CAT_TIMP;}
"executa" {return EXECUTA;};
"sfarsit_cat_timp" {return SFARSIT_CAT_TIMP;}

"pentru" {return PENTRU;}
"sfarsit_pentru" {return SFARS-IT_PENTRU;}
[_a-zA-Z][_a-zA-Z0-9]* {return ID;}
"=" {return ASSIGN;}
[0-9]+ {return NR;}

"+"|"-"|"*"|"/"|"%" {return OPERATIE;}
"<"|">"|"<="|"=>" {return OPERATOR_COMPARARE;}



[ \t] ;
\n {yylineno++;}
. {return yytext[0];}

 
