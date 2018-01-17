%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
"int"|"float"|"char"|"string"|"const"|"bool" {return TIP;}
">"|"<"|">="|"<="|"=="|"!="|"&&"|"||" {return OPERATORI_LOGICI;}
"->" {return ASSIGN;}
"begin_program" {return BGIN_PRGR;}
"end_program" {return END_PRGR;}
"class" {return TIP_CLASA;}
"c_start" {return BGIN_CLASS;}
"c_end" {return END_CLASS;}
"private:" {return PRIVATE;}
"public:" {return PUBLIC;}
"protected:" {return PROTECTED;}
"return" {return RETURN;}
"f_start" {return BGIN_FUNC;}
"f_end" {return END_FUNC;}
"while" {return WHILE;}
"execute" {return EXECUTE;}
"end_while" {return END_WHILE;}
"do" {return DO;}
"conditie_final_do" {return CONDITIE_FINAL_DO;}
"if" {return IF;}
"then" {return THEN;}
"end_then" {return END_THEN;}
"else" {return ELSE;}
"end_else" {return END_ELSE;}
"for" {return FOR;}
"end_for" {return END_FOR;}
\^\^[a-zA-Z0-9]+ {return ID;}
0|[1-9][0-9]* {return NR;}
(0|[1-9][0-9]*)","[0-9]+ {return NR_REAL;}
-?[1-9][0-9]* {return NR_NEG;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
