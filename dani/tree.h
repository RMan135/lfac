#include "process.h"

nodeType *add_opr_node(int operation, int operands_count, ...);
nodeType *add_identifier_node(char *id);
nodeType *add_constant_node(Data* value);
void remove_tree(nodeType *p);
Data* execute_tree(nodeType *p);
