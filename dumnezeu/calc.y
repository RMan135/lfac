%{
#include <stdio.h>
#include <string.h>
int result=1;
%}
%union{
  int intval;
  char* strval;
  char charval;
}
%token <charval>CHAR <intval>NUMAR 
%token QUIT

%type <strval> str
%type <strval> expresie_caractere
%type <intval> expresie_numerica

%nonassoc '|' '=' '(' ')'
%left '+'
%left '-'
%left '*'
%left '`'
%left '#'

%start s
%%
s : e
  | QUIT {return 3;}
  ;

e : expresie_caractere {printf("%s\n",$1);}
  | expresie_numerica {printf("%d\n",$1);}
  ;

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
	| expresie_caractere '*' expresie_numerica {
			   char* s=malloc(sizeof(char) * (strlen($1) +2));
			   strcpy(s,$1);
			   int i=1;
			   while(i<$3)
			   {
			     strcat(s,$1);
			     i++;
			   }
			   $$=s;
			 }
	| expresie_caractere '#' expresie_numerica {
				if (strlen($1) >= $3 && $3>0) 
			   	{
					char* s=malloc(sizeof(char) * (strlen($1)+2));
			   		strcpy(s,$1+strlen($1)-$3);
			   		$$ = s;
				}else
				{
					printf("Operatie imposibila.");
					strcpy($$,"");
				}
			 }
	| expresie_numerica '`' expresie_caractere {
				char* s=malloc(sizeof(char) * (strlen($3)+2));
			   	strncpy(s,$3,$1);
			  	$$ = s;
				if (strlen(s) < $1) 
				{
					strcpy($$,"");
					printf("Operatie imposibila.");
				}
			 }
	| str
	;

expresie_numerica : NUMAR
	| expresie_caractere '=' '=' expresie_caractere {
			    	    if (strcmp($1,$4) == 0) $$=1;
			    	    else $$=0;
			  	  }
	| '|' expresie_caractere '|' {
			    $$ = strlen($2);
		      	  }
	| '(' expresie_numerica ')' { $$ = $2;}
	;

str : CHAR {char* s=malloc(sizeof(char)); s[0]=$1; $$=s;}
    | CHAR str {char* s=malloc(sizeof(char) * (strlen($2)+2)); s[0]=$1; strcat(s,$2); $$=s;}
    ;

%%
int main()
{
  while(yyparse()==0);
}
