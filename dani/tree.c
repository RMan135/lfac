#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "tree.h"
#include "gin.tab.h"

extern int yyerror(char *);

nodeType *add_constant_node(Data* value) {
  nodeType *node;

  if ((node = malloc(sizeof(nodeType))) == NULL) {
    yyerror("out of memory");
    return 0;
  }

  node->type = typeCon;
  node->con.value = value;

  return node;
}

nodeType *add_identifier_node(char* id) {
  nodeType *node;

  if ((node = malloc(sizeof(nodeType))) == NULL) {
    yyerror("out of memory");
    return 0;
  }

  node->type = typeId;
  node->id.i = id;
  /* printf("Identifier %d %s\n", node->id.i, node->id.i);*/

  return node;
}

nodeType *add_opr_node(int operation, int operands_count, ...) {
  nodeType *node;

  if ((node = malloc(sizeof(nodeType) + (operands_count-1) * sizeof(nodeType *))) == NULL) {
    yyerror("out of memory");
    return 0;
  }

  node->type = typeOpr;
  node->opr.operation = operation;
  node->opr.operands_count = operands_count;

  va_list ap;
  va_start(ap, operands_count);

  for (int i = 0; i < operands_count; ++i)
    node->opr.operand[i] = va_arg(ap, nodeType*);

  va_end(ap);
  return node;
}

Data* declare_identifier(conNodeType type, idNodeType id) {
    identifierType* node;

    if ((node = malloc(sizeof(identifierType))) == NULL) {
        yyerror("out of memory");
        return 0;
    }

    Data *temp; 
    temp = malloc(sizeof(Data));
    
    node->type = type.value->type;
    node->name = id.i;
    node->new_scope = 0;
    node->next = identifiers_stack;
    node->data = temp;
    node->data->type = node->type;

    switch (node->type) {
      case int_type:
        node->data->int_value = 0;
        break;
      case float_type:
        node->data->float_value = 0.0;
        break;
      case char_type:
        node->data->chr_value = ' ';
        break;
      case string_type:
        do { char x[2] = {'\0'};
        node->data->str_value = strdup(x); } while(0);
        break;
      case custom_type:
        break;
      default:
        yyerror("Unknow type at initialization\n");
        return 0;
    }

    /* printf("ADD %s\n", node->name);*/
    identifiers_stack = node;

    return node->data;
}

Data* declare_and_set_identifier(conNodeType type, idNodeType id, Data* value) {
    identifierType* node;
    
    if (!value) return 0;

    if (type.value->type != value->type) {
      yyerror("The left side of the assignment doesn't have the same type as the right side");
      return 0;
    }

    if ((node = malloc(sizeof(identifierType))) == NULL) {
      yyerror("out of memory");
      return 0;
    }

    Data* temp_value;
    temp_value = malloc(sizeof(Data));
    *temp_value = *value;

    node->type = type.value->type;
    node->data = temp_value;
    node->new_scope = 0;
    node->name = id.i;
    node->next = identifiers_stack;

    /* printf("ADD %s %d\n", node->name, node->data->int_value);*/

    identifiers_stack = node;

    return node->data;
}

Data* set_identifier(char* id, Data* value) {
  identifierType* head = identifiers_stack;

  if (!value) return 0;

  if (id) id = strdup(id);

  char *i = strtok(id, ".");
  if (!i) return 0;

  /* printf("SET %s %d\n", id.i, value->int_value);*/
  while (head) {
    if (strcmp(head->name, i) == 0) {
      if (head->type == custom_type) {
        identifierType *backup = identifiers_stack;
        identifiers_stack = head->data->stack_value;
        Data *result = set_identifier(NULL, value);
        identifiers_stack = backup;
        if (result) {
          return result;
        }

        return 0;
      }

      if (head->type != value->type) {
        yyerror("The left side of the assignment doesn't have the same type as the right side");
        return 0;
      }

      Data* temp_value;
      temp_value = malloc(sizeof(Data));
      *temp_value = *value;

      free(head->data);
      head->data = temp_value;

      return head->data;
    }

    head = head->next;
  }

  yyerror("Identifier couldn't be set");
  return 0;
}

int is_identifier_set_in_scope(idNodeType id) {
  identifierType* head = identifiers_stack;

  /* printf("SET? (in scope) %d %s\n", id.i, id.i);*/
  while (head) {
    if (head->new_scope == 1) return 0;

    if (strcmp(head->name, id.i) == 0) {
      return 1;
    }

    head = head->next;
  }

  return 0;
}

int is_identifier_set(char* id) {
  identifierType* head = identifiers_stack;

  if (id) id = strdup(id);

  /* printf("SET? %d %s\n", id.i, id.i);*/
  char *i = strtok(id, ".");
  if (!i) return 1;

  while (head) {
    if (head->new_scope != 1) {
      if (strcmp(head->name, i) == 0) {
        if (head->type == custom_type) {
          identifierType *backup = identifiers_stack;
          identifiers_stack = head->data->stack_value;
          int result = is_identifier_set(NULL);
          identifiers_stack = backup;
          return result;
        }

        return 1;
      }
    }

    head = head->next;
  }

  return 0;
}

Data* get_identifier(char *id) {
  identifierType* head = identifiers_stack;

  if (id) id = strdup(id);

  char *i = strtok(id, ".");
  if (!i) return 0;

  /* printf("GET %d %s\n", id.i, id.i);*/
  while (head) {
    if (head -> new_scope != 1) {
      if (strcmp(head->name, i) == 0) {
        if (head->type == custom_type) {
          identifierType *backup = identifiers_stack;
          identifiers_stack = head->data->stack_value;
          Data *result = get_identifier(NULL);
          identifiers_stack = backup;
          if (result) {
            return result;
          } else {
            return head->data;
          }
        }

        return head->data;
      }
    }

    head = head->next;
  }

  yyerror("Identifier not found");
  return 0;
}

nodeType* copy_tree(nodeType *node) {
  nodeType* temp;

  if (!node) return 0;

  if (node->type == typeOpr) {
    if ((temp = malloc(sizeof(nodeType) + (node->opr.operands_count-1) * sizeof(nodeType *))) == NULL) {
      yyerror("out of memory");
      return 0;
    }
  } else if ((temp = malloc(sizeof(nodeType))) == NULL) {
    yyerror("out of memory");
    return 0;
  }

  *temp = *node;

  if (node->type == typeOpr) {
    for (int i = 0; i < node->opr.operands_count; ++i) {
      temp->opr.operand[i] = copy_tree(node->opr.operand[i]);
    }
  } else if (node->type == typeCon) {
    Data *temp2;
    temp2 = malloc(sizeof(Data));
    *(temp2) = *(node->con.value);
    temp->con.value = temp2;
  } else if (node->type == typeId) {
    temp->id.i = strdup(node->id.i); 
  }

  return temp;
}

void declare_function(idNodeType id, nodeType *params, nodeType *block) {
    identifierType* node;

    if ((node = malloc(sizeof(identifierType))) == NULL) {
      yyerror("out of memory");
      return;
    }
    
    functionType *temp;

    if ((temp = malloc(sizeof(functionType))) == NULL) {
      yyerror("out of memory");
      return;
    }

    if ((node->data = malloc(sizeof(Data))) == NULL) {
      yyerror("out of memory");
      return;
    }

    temp->params = copy_tree(params);
    temp->block = copy_tree(block);

    node->type = function_type;
    node->name = id.i;
    node->data->function_value = temp;
    node->next = identifiers_stack;

    identifiers_stack = node;
}

void declare_class(idNodeType id, nodeType *block) {
    identifierType* node;

    if ((node = malloc(sizeof(identifierType))) == NULL) {
      yyerror("out of memory");
      return;
    }
    
    classType *temp;

    if ((temp = malloc(sizeof(classType))) == NULL) {
      yyerror("out of memory");
      return;
    }

    if ((node->data = malloc(sizeof(Data))) == NULL) {
      yyerror("out of memory");
      return;
    }

    temp->block = copy_tree(block);

    node->type = class_type;
    node->name = id.i;
    node->data->type = class_type;
    node->data->class_value = temp;
    node->next = identifiers_stack;

    identifiers_stack = node;
}

nodeType* combine_trees(nodeType *node1, nodeType *node2) {
  if (node1->type == typeOpr && 
      node1->opr.operation == '~' && 
      !(node2->type == typeOpr && node2->opr.operation == ';')) {
    return
      add_opr_node(
        '~',
        3,
        node1->opr.operand[0],
        node1->opr.operand[1],
        node2);
  }

  if (node1->type == typeOpr && 
      node1->opr.operation == ';' && 
      node2->type == typeOpr && 
      node2->opr.operation == ';') {
    nodeType *left, *right;
    left = 
      add_opr_node(
          '~', 
          3, 
          node1->opr.operand[1]->opr.operand[0],
          node1->opr.operand[1]->opr.operand[1],
          node2->opr.operand[1]);

    right = combine_trees(node1->opr.operand[0], node2->opr.operand[0]);
    if (!right) return 0;

    return 
      add_opr_node(
        ';',
        2,
        left,
        right);
  } 

  yyerror("Incorrect number of arguments");
  return 0;
}

Data* execute_tree(nodeType *node) {
    if (!node) return NULL;

    Data *left, *right, *result;
    identifierType *backup;

    left = malloc(sizeof(Data));
    right = malloc(sizeof(Data));
    result = malloc(sizeof(Data));
    
    switch(node->type) {
      case typeCon:       
        /* printf("Executin constant: %c\n", node->con.value->int_value);*/
        return node->con.value;
      case typeId:
        /* printf("Executin id: %s\n", node->id.i);*/
        if (is_identifier_set(node->id.i)) {
          return get_identifier(node->id.i);
        }

        yyerror("Undeclared variable");
        return 0;
      case typeOpr:
        /* printf("Executin operation: %c %d\n", node->opr.operation, node->opr.operation);*/
        switch(node->opr.operation) {
        case WHILE: 
          while(execute_tree(node->opr.operand[0])->int_value) 
            execute_tree(node->opr.operand[1]); 

          return 0;
        case FOR:
          for(
            execute_tree(node->opr.operand[0]);
            execute_tree(node->opr.operand[1])->int_value;
            execute_tree(node->opr.operand[2])) {

            execute_tree(node->opr.operand[3]);

          }

          return 0;
        case IF:        
          left = execute_tree(node->opr.operand[0]); 

          if (left->int_value) {
            result = execute_tree(node->opr.operand[1]);
          } else if (node->opr.operands_count > 2) {
            result = execute_tree(node->opr.operand[2]);
          }

          return result;
        case PRINT:     
          result = execute_tree(node->opr.operand[0]);

          if (!result) return 0;

          if (result->type == int_type) {
            printf("%d\n", result->int_value); 
            return 0;
          }

          if (result->type == float_type) {
            printf("%f\n", result->float_value);
            return 0;
          }

          if (result->type == char_type) {
            printf("'%c'\n", result->chr_value);
            return 0;
          }

          if (result->type == string_type) {
            printf("\"%s\"\n", result->str_value);
            return 0;
          }

          /* yyerror("Don't know what kind of type is that\n");*/
          return 0;
        case ';':
          execute_tree(node->opr.operand[0]); 
          return execute_tree(node->opr.operand[1]);

        case '_':
          if (is_identifier_set_in_scope(node->opr.operand[1]->id)) {
            yyerror("Function already declared");
            return 0;
          }

          declare_function(
            node->opr.operand[1]->id,
            node->opr.operand[2],
            node->opr.operand[3]
          );

          return 0;

        case '%':
          if (!is_identifier_set(node->opr.operand[0]->id.i)) {
            yyerror("Function is not defined\n");
            return 0;
          }

          result = get_identifier(node->opr.operand[0]->id.i);

          backup = identifiers_stack;

          /* printf("CREATE SCOPE\n");*/
          // create new scope
          do {
          identifierType *x;
          x = malloc(sizeof(identifierType));
          x -> new_scope = 1;
          x -> next = identifiers_stack;
          identifiers_stack = x; } while(0);

          // combine trees
          if (!!result->function_value->params == !!node->opr.operand[1]) {
            if (!result->function_value->params && !node->opr.operand[1]) 
              left = execute_tree( result->function_value->block );
            else if (
              execute_tree(combine_trees(
                result->function_value->params,
                node->opr.operand[1]
              ))) {
              *left = *execute_tree( result->function_value->block );
            }
          } else {
            left = 0;
            yyerror("Incorrect number of arguments");
          }

          // delete last scope
          while (identifiers_stack) {
            identifierType *temp = identifiers_stack->next;
            /* printf("DELETE %s\n", identifiers_stack->name);*/

            if (identifiers_stack->new_scope == 1) {
              free(identifiers_stack);
              identifiers_stack = temp;
              break;
            } else {
              free(identifiers_stack->data);
              free(identifiers_stack);
              identifiers_stack = temp;
            }
          }

          return left;

        case '~':
          if (is_identifier_set_in_scope(node->opr.operand[1]->id)) {
            yyerror("Variable already declared");
            return 0;
          }

          if (node->opr.operands_count == 2) {
            return 
              declare_identifier(
                node->opr.operand[0]->con, 
                node->opr.operand[1]->id);
          } else {
            return 
              declare_and_set_identifier(
                node->opr.operand[0]->con, 
                node->opr.operand[1]->id, 
                execute_tree(node->opr.operand[2]));
          }

        case ASSIGN_SYMBOL:
          if (is_identifier_set(node->opr.operand[0]->id.i)) {
            return 
              set_identifier(
                node->opr.operand[0]->id.i, 
                execute_tree(node->opr.operand[1]));
          }

          yyerror("Undeclared variable");
          return 0;

        case '@':
          if (is_identifier_set(node->opr.operand[0]->id.i)) {
            yyerror("Class already defined");
            return 0;
          }

          declare_class(
            node->opr.operand[0]->id,
            node->opr.operand[1]
          );

          return 0;
        case '#':
          if (!is_identifier_set(node->opr.operand[0]->id.i)) {
            yyerror("Class not defined");
            return 0;
          }

          left = get_identifier(node->opr.operand[0]->id.i);

          if (left->type != class_type) {
            yyerror("Type is not a class");
            return 0;
          }

          Data* value; 
          value = malloc(sizeof(Data));
          value->type = custom_type; 
          value->stack_value = 0;

          declare_identifier(
            add_constant_node(value)->con, 
            node->opr.operand[1]->id);

          backup = identifiers_stack;
          identifiers_stack = 0;

          execute_tree(left->class_value->block);

          backup->data->stack_value = identifiers_stack;
          identifiers_stack = backup;

          return 0;
        default:
          left = execute_tree(node->opr.operand[0]);
          
          if (!left) return 0;

          if (node->opr.operands_count == 1) {
            switch (node->opr.operation) {
              case NEG:
                result->type = int_type;
                result->int_value = -left->int_value;
                return result;
              case NOT:
                result->type = int_type;
                result->int_value = !left->int_value;
                return result;
              default:
                return 0;
            }
          }

          right = execute_tree(node->opr.operand[1]);
          
          if (!right) return 0;

          return process(node->opr.operation, left, right);
      }
    }

    return 0;
}

void remove_tree(nodeType *node) {
  if (!node) return;

  if (node->type == typeOpr) {
    for (int i = 0; i < node->opr.operands_count; ++i) {
      remove_tree(node->opr.operand[i]);
    }
  } else if (node->type == typeCon) {
    free(node->con.value);
  }

  free(node);
}
