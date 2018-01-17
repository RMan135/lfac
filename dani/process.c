#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "process.h"
#include "gin.tab.h"


extern int yyerror(char *);

Data* cast(Data* data, int type) {
  if (data->type == type) return data;

  Data* result;
  result = malloc(sizeof(Data));

  // int int 

  if (data->type == int_type && type == float_type) {
    result->type = float_type;
    result->float_value = (double) data->int_value;
    return result;
  } 
  
  if (data->type == int_type && type == char_type) {
    result->type = char_type;
    result->chr_value = (char) data->int_value;
    return result;
  }

  if (data->type == int_type && type == string_type) {

    char str[12];
    sprintf(str, "%d", data->int_value);

    result->type = string_type;
    result->str_value = strdup(str);
    return result;
  }

  // float int
  // float float
  // float char
  // float string
  
  if (data->type == char_type && type == int_type) {
    result->type = int_type;
    result->int_value = (int) data->chr_value;
    return result;
  }

  if (data->type == char_type && type == float_type) {
    result->type = float_type;
    result->float_value = (float)((int) data->chr_value);
    return result;
  }

  // char char

  if (data->type == char_type && type == string_type) {
    result->type = string_type;

    char x[2] = { '\0' };
    x[0] = data->chr_value;

    result->str_value = strdup(x);
    return result;
  }


  return data;
}

Data* process(int oper, Data *left, Data *right) {
  Data *result;

  result = malloc(sizeof(Data));

  right = cast(right, left->type);
  left = cast(left, right->type);

  int current_case = (left->type+1)*10 + (right->type+1);

  switch (current_case) {
    case 11: // int int
      switch (oper) {
        case PLUS:       
          result->type = int_type;
          result->int_value = left->int_value + right->int_value;
          return result;
        case MINUS:
          result->type = int_type;
          result->int_value = left->int_value - right->int_value;
          return result;
        case TIMES:
          result->type = int_type;
          result->int_value = left->int_value * right->int_value;
          return result;
        case DIVIDE:
          result->type = int_type;
          result->int_value = left->int_value / right->int_value;
          return result;
        case MOD:
          result->type = int_type;
          result->int_value = left->int_value % right->int_value;
          return result;
        case '&':
          result->type = int_type;
          result->int_value = left->int_value & right->int_value;
          return result;
        case '|':
          result->type = int_type;
          result->int_value = left->int_value | right->int_value;
          return result;
        case '^':
          result->type = int_type;
          result->int_value = left->int_value ^ right->int_value;
          return result;
        case LE:
          result->type = int_type;
          result->int_value = left->int_value < right->int_value;
          return result;
        case GE:
          result->type = int_type;
          result->int_value = left->int_value > right->int_value;
          return result;
        case GEQ:
          result->type = int_type;
          result->int_value = left->int_value >= right->int_value;
          return result;
        case LEQ:
          result->type = int_type;
          result->int_value = left->int_value <= right->int_value;
          return result;
        case NEQ:
          result->type = int_type;
          result->int_value = left->int_value != right->int_value;
          return result;
        case EQ:
          result->type = int_type;
          result->int_value = left->int_value == right->int_value;
          return result;
        case AND:
          result->type = int_type;
          result->int_value = left->int_value && right->int_value;
          return result;
        case OR:
          result->type = int_type;
          result->int_value = left->int_value || right->int_value;
          return result;
        default:
          yyerror("This operrator is not defined on int\n");
          return 0;
      }

    case 22: // float
      switch (oper) {
        case PLUS:       
          result->type = float_type;
          result->float_value = left->float_value + right->float_value;
          return result;
        case MINUS:
          result->type = float_type;
          result->float_value = left->float_value - right->float_value;
          return result;
        case TIMES:
          result->type = float_type;
          result->float_value = left->float_value * right->float_value;
          return result;
        case DIVIDE:
          result->type = float_type;
          result->float_value = left->float_value / right->float_value;
          return result;
        case LE:
          result->type = int_type;
          result->int_value = left->float_value < right->float_value;
          return result;
        case GE:
          result->type = int_type;
          result->int_value = left->float_value > right->float_value;
          return result;
        case GEQ:
          result->type = int_type;
          result->int_value = left->float_value >= right->float_value;
          return result;
        case LEQ:
          result->type = int_type;
          result->int_value = left->float_value <= right->float_value;
          return result;
        case NEQ:
          result->type = int_type;
          result->int_value = left->float_value != right->float_value;
          return result;
        case EQ:
          result->type = int_type;
          result->int_value = left->float_value == right->float_value;
          return result;
        case AND:
          result->type = int_type;
          result->int_value = left->float_value && right->float_value;
          return result;
        case OR:
          result->type = int_type;
          result->int_value = left->float_value || right->float_value;
          return result;
        default:
          yyerror("This operrator is not defined on float\n");
          return 0;
      }

    case 33: // char char
      switch (oper) {
        case PLUS:       
          result->type = char_type;
          result->chr_value = left->chr_value + right->chr_value;
          return result;
        case MINUS:
          result->type = char_type;
          result->chr_value = left->chr_value - right->chr_value;
          return result;
        case TIMES:
          result->type = char_type;
          result->chr_value = left->chr_value * right->chr_value;
          return result;
        case DIVIDE:
          result->type = char_type;
          result->chr_value = left->chr_value / right->chr_value;
          return result;
        case '&':
          result->type = int_type;
          result->int_value = left->chr_value & right->chr_value;
          return result;
        case '|':
          result->type = int_type;
          result->int_value = left->chr_value | right->chr_value;
          return result;
        case '^':
          result->type = int_type;
          result->int_value = left->chr_value ^ right->chr_value;
          return result;
        case LE:
          result->type = int_type;
          result->int_value = left->chr_value < right->chr_value;
          return result;
        case GE:
          result->type = int_type;
          result->int_value = left->chr_value > right->chr_value;
          return result;
        case GEQ:
          result->type = int_type;
          result->int_value = left->chr_value >= right->chr_value;
          return result;
        case LEQ:
          result->type = int_type;
          result->int_value = left->chr_value <= right->chr_value;
          return result;
        case NEQ:
          result->type = int_type;
          result->int_value = left->chr_value != right->chr_value;
          return result;
        case EQ:
          result->type = int_type;
          result->int_value = left->chr_value == right->chr_value;
          return result;
        case AND:
          result->type = int_type;
          result->int_value = left->chr_value && right->chr_value;
          return result;
        case OR:
          result->type = int_type;
          result->int_value = left->chr_value || right->chr_value;
          return result;
        default:
          yyerror("This operrator is not defined on char\n");
          return 0;
      }

    case 44: // string string
      switch (oper) {
        case PLUS:       
          result->type = string_type;

          char *str;
          str = malloc(sizeof(left->str_value) + sizeof(right->str_value) + 5);

          memset(str, '\0', sizeof(str));
          strcat(str, left->str_value);
          strcat(str, right->str_value);
          result->str_value = str;
          return result;
        case LE:
          result->type = int_type;
          result->int_value = strcmp(left->str_value, right->str_value) < 0;
          return result;
        case GE:
          result->type = int_type;
          result->int_value = strcmp(left->str_value, right->str_value) > 0;
          return result;
        case GEQ:
          result->type = int_type;
          result->int_value = strcmp(left->str_value, right->str_value) >= 0;
          return result;
        case LEQ:
          result->type = int_type;
          result->int_value = strcmp(left->str_value, right->str_value) <= 0;
          return result;
        case NEQ:
          result->type = int_type;
          result->int_value = strcmp(left->str_value, right->str_value) != 0;
          return result;
        case EQ:
          result->type = int_type;
          result->int_value = strcmp(left->str_value, right->str_value) == 0;
          return result;
        case AND:
          result->type = int_type;
          result->int_value = 1;
          return result;
        case OR:
          result->type = int_type;
          result->int_value = 1;
          return result;
        default:
          yyerror("This operrator is not defined on string\n");
          return 0;
      }


    default:
      yyerror("There is no opperator defined for what are you trying to do\n");
      return 0;
  }

}
