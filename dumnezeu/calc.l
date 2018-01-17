%{
#include <stdio.h>
#include "y.tab.h"
%}
%%
[0-9]+ { yylval.intval = atoi(yytext); return NUMAR;}
[a-zA-Z] { yylval.charval = yytext[0]; return CHAR;}
quit {return QUIT;}
[ \t] ;
\n {return 0;}
. {return yytext[0];}

