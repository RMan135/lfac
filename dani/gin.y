%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "tree.h"

int yylex(void);
void yyerror(char *s);

FILE* yyin;
int yylineno;

%}

%union {
    int iValue;
    double fValue;
    char* sValue;
    char cValue;
    char* sIndex;
    nodeType *nPtr;
};


%token ASSIGN_SYMBOL AND OR TRUE FALSE NOT REAL INT VOID CHAR STRING BGIN END CLASS

%token <iValue> INTEGER
%token <fValue> FLOAT
%token <sValue> STR
%token <cValue> CHR
%token <sIndex> ID
%token WHILE IF PRINT FOR RETURN CONST
%nonassoc IFX
%nonassoc ELSE

%left GEQ LEQ EQ NEQ GE LE AND OR
%left MINUS PLUS
%left TIMES DIVIDE MOD
%left '&' '|' '^' NOT
%nonassoc NEG

%type <nPtr> statement statement_block instruction assignment declaration type atom
%type <nPtr> if_block while_block for_block 
%type <nPtr> expression aritmetic_expressions boolean_expressions binary_expressions
%type <nPtr> param_list param_list_elem function_block function_call expression_list
%type <nPtr> class_block class_declarations_element class_declarations


%%


program : statements { exit(0); }
        ;

statements : statements statement  { execute_tree($2); remove_tree($2); }
           | /* NULL */
           ;

statement : ';'                          { $$ = add_opr_node(';', 2, NULL, NULL); }
          | instruction ';'              { $$ = $1; }
          | if_block
          | for_block
          | while_block
          | function_block               { $$ = $1; }
          | class_block
          | BGIN statement_block END     { $$ = $2; }
          ;

statement_block : statement                        { $$ = $1; }
                | statement_block statement        { $$ = add_opr_node(';', 2, $1, $2); }
                ;

instruction : assignment
            | declaration
            | expression
            ;

if_block : IF '(' expression ')' statement %prec IFX      { $$ = add_opr_node(IF, 2, $3, $5); }
         | IF '(' expression ')' statement ELSE statement { $$ = add_opr_node(IF, 3, $3, $5, $7); }
         ;

for_block : FOR '(' instruction ';' expression ';' assignment ')' statement { $$ = add_opr_node(FOR, 4, $3, $5, $7, $9); }
          ;

while_block : WHILE '(' expression ')' statement      { $$ = add_opr_node(WHILE, 2, $3, $5); }
            ;

class_block : CLASS ID BGIN class_declarations END { $$ = add_opr_node('@', 2, add_identifier_node($2), $4); }
            ;

function_block : type ID '(' param_list ')' statement { $$ = add_opr_node('_', 4, $1, add_identifier_node($2), $4, $6);}
               | type ID '('  ')' statement { $$ = add_opr_node('_', 4, $1, add_identifier_node($2), NULL, $5);}
               ;

function_call : PRINT '(' expression ')'    { $$ = add_opr_node(PRINT, 1, $3); }
              | ID '(' expression_list ')'  { $$ = add_opr_node('%', 2, add_identifier_node($1), $3); } 
              | ID '(' ')'  { $$ = add_opr_node('%', 2, add_identifier_node($1), NULL); } 
              ;

param_list_elem : type ID { $$ = add_opr_node('~', 2, $1, add_identifier_node($2)); }
                | CONST type ID { $$ = add_opr_node('~', 2, $2, add_identifier_node($3)); }
                ;

param_list : param_list_elem
           | param_list ',' param_list_elem { $$ = add_opr_node(';', 2, $1, $3); }
           ;

expression_list : expression
                | expression_list ',' expression { $$ = add_opr_node(';', 2, $1, $3); }
                ;

declaration : type ID { $$ = add_opr_node('~', 2, $1, add_identifier_node($2)); }
            | type ID ASSIGN_SYMBOL expression { $$ = add_opr_node('~', 3, $1, add_identifier_node($2), $4); }
            | type ID brackets { $$ = add_opr_node(';', 2, NULL, NULL); }
            | CONST type ID ASSIGN_SYMBOL expression { $$ = add_opr_node(';', 2, NULL, NULL); }
            | ID ID { $$ = add_opr_node('#', 2, add_identifier_node($1), add_identifier_node($2)); }
            ;

assignment : ID ASSIGN_SYMBOL expression { $$ = add_opr_node(ASSIGN_SYMBOL, 2, add_identifier_node($1), $3); }
           | ID brackets ASSIGN_SYMBOL expression { $$ = add_opr_node(';', 2, NULL, NULL); }
           | ID '.' ID ASSIGN_SYMBOL expression  { char s[200] = {'\0'}; 
                                                   sprintf(s, "%s.%s", $1, $3); 
                                                   $$ = add_opr_node(ASSIGN_SYMBOL, 2, add_identifier_node(strdup(s)), $5); }
           ;

expression: atom                       
          | ID                            { $$ = add_identifier_node($1); }
          | ID '.' ID                     { char s[200] = {'\0'}; sprintf(s, "%s.%s", $1, $3); $$ = add_identifier_node(strdup(s)); }
          | aritmetic_expressions
          | boolean_expressions
          | binary_expressions
          | function_call
          | '(' expression ')'            { $$ = $2; }
          ;

aritmetic_expressions : MINUS expression %prec NEG    { $$ = add_opr_node(NEG, 1, $2); }
                      | expression PLUS expression    { $$ = add_opr_node(PLUS, 2, $1, $3); }
                      | expression MINUS expression   { $$ = add_opr_node(MINUS, 2, $1, $3); }
                      | expression TIMES expression   { $$ = add_opr_node(TIMES, 2, $1, $3); }
                      | expression DIVIDE expression  { $$ = add_opr_node(DIVIDE, 2, $1, $3); }
                      | expression MOD expression     { $$ = add_opr_node(MOD, 2, $1, $3); }
                      ;

boolean_expressions : expression LE expression      { $$ = add_opr_node(LE, 2, $1, $3); }
                    | expression GE expression      { $$ = add_opr_node(GE, 2, $1, $3); }
                    | expression GEQ expression     { $$ = add_opr_node(GEQ, 2, $1, $3); }
                    | expression LEQ expression     { $$ = add_opr_node(LEQ, 2, $1, $3); }
                    | expression EQ expression      { $$ = add_opr_node(EQ, 2, $1, $3); }
                    | expression NEQ expression     { $$ = add_opr_node(NEQ, 2, $1, $3); }
                    | expression AND expression     { $$ = add_opr_node(AND, 2, $1, $3); }
                    | expression OR expression      { $$ = add_opr_node(OR, 2, $1, $3); }
                    | NOT expression %prec NEG      { $$ = add_opr_node(NOT, 1, $2); }
                    ;

binary_expressions : expression '&' expression      { $$ = add_opr_node('&', 2, $1, $3); }
                   | expression '|' expression      { $$ = add_opr_node('|', 2, $1, $3); }
                   | expression '^' expression      { $$ = add_opr_node('^', 2, $1, $3); }
                   ;

type : INT { Data* value;
             value = malloc(sizeof(Data));
             value->type = int_type;
             $$ = add_constant_node(value); }
     | REAL { Data* value;
             value = malloc(sizeof(Data));
             value->type = float_type;
             $$ = add_constant_node(value);  }
     | CHAR { Data* value;
             value = malloc(sizeof(Data));
             value->type = char_type;
             $$ = add_constant_node(value);  }
     | STRING { Data* value;
             value = malloc(sizeof(Data));
             value->type = string_type;
             $$ = add_constant_node(value);  }
     ;

atom : INTEGER { Data* value; 
                 value = malloc(sizeof(Data));
                 value->type = int_type; 
                 value->int_value = $1; 
                 $$ = add_constant_node(value); }
     | FLOAT   { Data* value; 
                 value = malloc(sizeof(Data));
                 value->type = float_type; 
                 value->float_value = $1; 
                 $$ = add_constant_node(value); }
     | STR     { Data* value;
                 value = malloc(sizeof(Data));
                 value->type = string_type;
                 value->str_value = $1;
                 $$ = add_constant_node(value); }
     | CHR     { Data* value;
                 value = malloc(sizeof(Data));
                 value->type = char_type;
                 value->chr_value = $1;
                 $$ = add_constant_node(value); }
     | TRUE    { Data* value;
                 value = malloc(sizeof(Data));
                 value->type = int_type; 
                 value->int_value = 1; 
                 $$ = add_constant_node(value); }
     | FALSE   { Data* value;
                 value = malloc(sizeof(Data));
                 value->type = int_type; 
                 value->int_value = 0; 
                 $$ = add_constant_node(value); }
     ;

brackets : brackets '[' INTEGER ']' 
         | '[' INTEGER ']' 
         ;

class_declarations_element : declaration ';' { $$ = $1; }
                           | function_block
                           ;

class_declarations : class_declarations_element
                   | class_declarations class_declarations_element { $$ = add_opr_node(';', 2, $1, $2); }
                   ;


%%



void yyerror(char *s) {
  fprintf(stdout, "%s\n", s);
}

int main(int argc, char** argv) {
  if(argc>0)
    yyin = fopen(argv[1], "r");

  yyparse();
  return 0;
}
