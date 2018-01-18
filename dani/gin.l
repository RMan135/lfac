%{
#include <stdlib.h>
#include "tree.h"
#include "gin.tab.h"

void yyerror(char *);

char buffer[256];                                                               /* string buffer */
char * s;

%}

%x STRING_PARSE

number ([1-9][0-9]*)|0

%%

"float"              { return REAL;}                                            /* types */
"int"                { return INT;}
"void"               { return VOID;}
"char"               { return CHAR;}
"string"             { return STRING;}
"class"              { return CLASS;}

"+"                  { return PLUS;}                                            /* operators */
"-"                  { return MINUS;}
"*"                  { return TIMES;}
"/"                  { return DIVIDE;}
"%"                  { return MOD;}

"="                  { return ASSIGN_SYMBOL;}
"!="                 { return NEQ;}
"=="                 { return EQ;}
"<"                  { return LE;}
"<="                 { return LEQ;}
">"                  { return GE;}
">="                 { return GEQ;}
"&&"                 { return AND;}
"||"                 { return OR;}
"!"                  { return NOT;}

"if"                 { return IF;}                                              /* flow */
"while"              { return WHILE;}
"for"                { return FOR;}
"else"               { return ELSE;}
"return"             { return RETURN;}
"constant"           { return CONST;}
"{"                  { return BGIN;}
"}"                  { return END;}

"true"               { return TRUE;}                                            /* bool */
"false"              { return FALSE;}

"print"              { return PRINT;}                                           /* print */

[_a-zA-Z][_a-zA-Z0-9]*  {
                            yylval.sIndex = strdup(yytext);                     /* identifier */
                            return ID;          
                        }          


{number}    { 
                yylval.iValue = atoi(yytext);                                   /* int */
                return INTEGER;
            }

{number}(\.[0-9]+)  {
                        yylval.fValue = atof(yytext);                           /* float */
                        return FLOAT;
                    }


\"                      {
                            BEGIN STRING_PARSE;                                 /* string */
                            s = buffer;
                        }                     
<STRING_PARSE>\\n       { *s++ = '\n'; }
<STRING_PARSE>\\t       { *s++ = '\t'; }
<STRING_PARSE>\\\"      { *s++ = '\"'; }
<STRING_PARSE>\"        { *s = 0;
                            BEGIN 0;
                            char* x;
                            x = malloc(sizeof(buffer));
                            strcpy(x, buffer);
                            yylval.sValue = x;
                            return STR;
                        }
<STRING_PARSE>\n        { printf("Found newline in string!"); exit(1); }
<STRING_PARSE>.         { *s++ = *yytext; }


['](.)[']   {
                yylval.cValue = yytext[1];                                      /* character */
                return CHR;
            }

[\[\]();.|^&,]  {
                    return *yytext;                                             /* other chars */
                }

[ \t\n]+ ;                                                                      /* whitespace chars */

.   {
        yyerror("Found unknown character!");
        exit(0);
    }

%%

int yywrap(void)
{
    return 1;
}
