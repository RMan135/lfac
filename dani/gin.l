%{
#include <stdlib.h>
#include "tree.h"
#include "gin.tab.h"

void yyerror(char *);
char buf[100];
char *s;
%}

%x STRING_state

number ([1-9][0-9]*)|0

%%
"float"   { return REAL;}
"int"     { return INT;}
"void"    { return VOID;}
"char"    { return CHAR;}
"string"  { return STRING;}

"{" 			{ return BGIN;}
"}" 			{ return END;}
"class" 	{ return CLASS;}

"+" { return PLUS; }
"-" { return MINUS; }
"*" { return TIMES; }
"/" { return DIVIDE; }
"%" { return MOD; }

"=" 			{ return ASSIGN_SYMBOL;}
"!="      { return NEQ;}
"=="      { return EQ;}
"<"       { return LE;}
"<="      { return LEQ;}
">"       { return GE;}
">="      { return GEQ;}
"&&"      { return AND;}
"||"      { return OR;}
"true" 	  { return TRUE;}
"false"		{ return FALSE;}
"!"       { return NOT; }

"if"      { return IF; }
"while"   { return WHILE; }
"for"			{ return FOR; }
"else"    { return ELSE; }
"return"  { return RETURN; }
"constant"   { return CONST;}

"print"   { return PRINT; }

[_a-zA-Z][_a-zA-Z0-9]*  { yylval.sIndex = strdup(yytext); return ID; }


{number} { yylval.iValue = atoi(yytext);
           return INTEGER;
         }

{number}(\.[0-9]+) { yylval.fValue = atof(yytext);
                     return FLOAT;
                    }

\"              { BEGIN STRING_state; s = buf; }
<STRING_state>\\n     { *s++ = '\n'; }
<STRING_state>\\t     { *s++ = '\t'; }
<STRING_state>\\\"    { *s++ = '\"'; }
<STRING_state>\"      { *s = 0;
                  BEGIN 0;
									char* x;
									x = malloc(sizeof(buf));
									strcpy(x, buf);
									yylval.sValue = x;
									return STR;
                }
<STRING_state>\n      { printf("invalid string"); exit(1); }
<STRING_state>.       { *s++ = *yytext; }

['](.)['] { yylval.cValue = yytext[1];
            return CHR;}

[\[\]();.|^&,] {
                return *yytext;
             }


[ \t\n]+ ;       /* ignore whitespace */
.            {   yyerror("Unknown character"); exit(0); }

%%

int yywrap(void) {
    return 1;
}
