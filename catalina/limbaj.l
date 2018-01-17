%{
#include <stdio.h>
#include "y.tab.h"
%}
%x comment
%x comment_linie
%%

"//" {BEGIN comment_linie; }
<comment_linie>\n {BEGIN 0; yylineno++;}
<comment_linie>. ;
"/*" {BEGIN comment;} 
<comment>"*/" {BEGIN 0;}
<comment>. ;


"main()"			{ return FCT_MAIN; }

"maxim3"			{ return MAXIM3; }
"divizor_comun"			{ return DIVIZOR_COMUN; }
"multiplu_comun"		{ return MULTIPLU_COMUN; }

"var"				{ return VAR; }

"return"			{ return RETURN; }
"print"				{ return PRINT; }
"="				{return ASIGN;}		

-?0|([1-9][0-9]*)		{ yylval.ID_value=atoi(yytext); return NR;    }
[_a-zA-Z][_a-zA-Z0-9]*		{ yylval.ID_name=strdup(yytext); return ID;   }

[ \t] ;
\n                         {yylineno++;}
.                          {return yytext[0];}

%%			 

