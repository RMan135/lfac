typedef enum { int_type, float_type, char_type, string_type, function_type, class_type, custom_type } DataTypes; 


typedef struct {
  struct nodeTypeTag* block;
  struct nodeTypeTag* params;
} functionType;

typedef struct {
  struct nodeTypeTag* block;
} classType;

typedef struct DataTag {
  DataTypes type;

  union {
    int int_value;
    double float_value;
    char* str_value;
    char chr_value;
    struct identifierTypeTag* stack_value;

    functionType* function_value;
    classType* class_value;
  };

} Data;

typedef struct identifierTypeTag {
  DataTypes type;
  Data* data;

  char* name;
  int new_scope;

  struct identifierTypeTag* next;
} identifierType;

identifierType* identifiers_stack;

typedef enum { typeCon, typeId, typeOpr } nodeEnum;

/* constants */
typedef struct {
  Data* value;                  /* value of constant */
} conNodeType;

/* identifiers */
typedef struct {
    char* i;                      /* subscript to sym array */
} idNodeType;

/* operators */
typedef struct {
    int operation;                   /* operator */
    int operands_count;                   /* number of operands */
    struct nodeTypeTag *operand[1];  /* operands, extended at runtime */
} oprNodeType;


typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */

    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        oprNodeType opr;        /* operators */
    };
} nodeType;
