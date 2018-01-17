%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
"program ex" {return HEADER;}
"printd" {return PRINT;}
"start_prg" {return START;}
"max" {return MAX;} 
"end_prg" {return END;}
"if" {return IF;}
"while" {return WHILE;}
"for" {return FOR;}
"{" {return START_ST;}
"}" {return END_ST;}
"int"|"float" {return VAR;}

"function max (int i,int j)" {return FUNC;}
"&&"|"||"|"<="|">="|"=="|"!="|"<"|">"  {return OP_LOGIC;}
[a-zA-Z]+ { yylval.strval =(char*) malloc(100);
	    strcpy(yylval.strval,yytext); 
	    return ID;}
[-]?[1-9][0-9]*|0 { yylval.intval=atoi(yytext); return NR;}
"=" {return ASSIGN;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}


