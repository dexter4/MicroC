/* ====================================================================== */

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE		11	/* hash array size */
					/* symbol's kind */
#define GLOBAL			0	/* global variable */
#define LOCAL			1	/* local variable */
#define ARGUMENT		2	/* formal argument */
#define MEMBER			3	/* member variable */
#define FUNCTION		4	/* function name */
#define FUNCTIONI		5	/* incomplete function */
					/* symbol's optional type */
#define NO_OPTYPE		0	/* no optional type */
#define STATIC_OPTYPE		1	/* static optional type */
#define EXTERN_OPTYPE		2	/* extern optional type */
					/* symbol's type */
#define VOID_TYPE		0	/* void type */
#define VOID_P_TYPE		1	/* void pointer type */
#define VOID_P_ARRAY_TYPE	2	/* void pointer array type */
#define VOID_P_P_TYPE		3	/* void pointer pointer type */
#define INT_TYPE		4	/* int type */
#define INT_ARRAY_TYPE		5	/* int array type */
#define INT_P_TYPE		6	/* int pointer type */
#define INT_P_ARRAY_TYPE	7	/* int pointer array type */
#define INT_P_P_TYPE		8	/* int pointer pointer type */
#define CHAR_TYPE		9	/* char type */
#define CHAR_ARRAY_TYPE		10	/* char array type */
#define CHAR_P_TYPE		11	/* char pointer type */
#define CHAR_P_ARRAY_TYPE	12	/* char pointer array type */
#define CHAR_P_P_TYPE		13	/* char pointer pointer type */
#define STRUCT_TYPE		14	/* struct type */
#define STRUCT_ARRAY_TYPE	15	/* struct array type */
#define STRUCT_P_TYPE		16	/* struct pointer type */
#define STRUCT_P_ARRAY_TYPE	17	/* struct pointer array type */
#define STRUCT_P_P_TYPE		18	/* struct pointer pointer type */
#define N_A			99	/* notapplicable */
					/* type byte size */
#define POINTER_SIZE		4	/* pointer type byte size */
#define INT_SIZE		4	/* int type byte size */
#define CHAR_SIZE		1	/* char type byte size */

#define MAX_DIGIT		16	/* max digit of number */

/* ====================================================================== */
/* for symbol table */

struct symbol {
  char *name;				/* symbol's name */
  char *stname;				/* symbol's structure name */
  unsigned char kind;			/* symbol's kind */
  unsigned char optype;			/* symbol's optional type */
  unsigned char type;			/* symbol's type */
  unsigned int size;			/* byte size or no of args */
  unsigned int offset;			/* relative memory offset */
  unsigned int ip[128];			/* ip that calls this function */
  unsigned int ipc;			/* ip count in ip[] */
  struct table *mbtable;		/* member table */
  struct symbol *next;			/* next symbol pointer */
};

struct table {
  char *name;				/* function name */
  struct symbol *hash[HASH_SIZE];	/* hash array */
};

struct table *global_table;		/* global symbol table */
struct table *local_table;		/* local symbol table */
struct table *current_table;		/* current symbol table */

struct table *global_sttable;		/* global structure table */
struct table *local_sttable;		/* local structure table */
struct table *current_sttable;		/* current structure table */

struct symbol *current_stsymbol;	/* current structure symbol */
struct table *current_mbtable;		/* current member table */

/* ====================================================================== */

/* hash function for symbol hash table */
int hash_function(char *name)
{
  int hashval;

  for (hashval = 0; *name != '\0';)
    hashval += *name++;
  return hashval % HASH_SIZE;
}

/* create symbol table */
struct table *create_table(char *name)
{
  struct table *tablep;
  int i;

  if ((tablep = (struct table *) malloc(sizeof(*tablep))) == NULL)
    error("can't malloc in create_table");

  tablep->name = name;
  for (i = 0; i < HASH_SIZE; i++)
    tablep->hash[i] = NULL;

  return tablep;
}

/* return pointer type of input type */
unsigned char type_to_ptype(unsigned char type)
{
  switch (type) {
    case VOID_TYPE:		return VOID_P_TYPE;
    case VOID_P_TYPE:		return VOID_P_P_TYPE;
    case INT_TYPE:		return INT_P_TYPE;
    case INT_P_TYPE:		return INT_P_P_TYPE;
    case CHAR_TYPE:		return CHAR_P_TYPE;
    case CHAR_P_TYPE:		return CHAR_P_P_TYPE;
    case STRUCT_TYPE:		return STRUCT_P_TYPE;
    case STRUCT_P_TYPE:		return STRUCT_P_P_TYPE;
    default:
      error("invalid type: \"%d\" in type_to_ptype()", type);
  }
}

/* return original type of input pointer type */
unsigned char ptype_to_type(unsigned char type)
{
  switch (type) {
    case VOID_P_TYPE:		return VOID_TYPE;
    case VOID_P_P_TYPE:		return VOID_P_TYPE;
    case INT_P_TYPE:		return INT_TYPE;
    case INT_P_P_TYPE:		return INT_P_TYPE;
    case CHAR_P_TYPE:		return CHAR_TYPE;
    case CHAR_P_P_TYPE:		return CHAR_P_TYPE;
    case STRUCT_P_TYPE:		return STRUCT_TYPE;
    case STRUCT_P_P_TYPE:	return STRUCT_P_TYPE;
    default:
      error("invalid type: \"%d\" in ptype_to_type()", type);
  }
}

/* return array type of input type */
unsigned char type_to_atype(unsigned char type)
{
  switch (type) {
    case VOID_P_TYPE:		return VOID_P_ARRAY_TYPE;
    case INT_TYPE:		return INT_ARRAY_TYPE;
    case INT_P_TYPE:		return INT_P_ARRAY_TYPE;
    case CHAR_TYPE:		return CHAR_ARRAY_TYPE;
    case CHAR_P_TYPE:		return CHAR_P_ARRAY_TYPE;
    case STRUCT_TYPE:		return STRUCT_ARRAY_TYPE;
    case STRUCT_P_TYPE:		return STRUCT_P_ARRAY_TYPE;
    default:
      error("invalid type: \"%d\" in type_to_atype()", type);
  }
}

/* return original type of input array type */
unsigned char atype_to_type(unsigned char type)
{
  switch (type) {
    case VOID_P_ARRAY_TYPE:	return VOID_P_TYPE;
    case INT_ARRAY_TYPE:	return INT_TYPE;
    case INT_P_ARRAY_TYPE:	return INT_P_TYPE;
    case CHAR_ARRAY_TYPE:	return CHAR_TYPE;
    case CHAR_P_ARRAY_TYPE:	return CHAR_P_TYPE;
    case STRUCT_ARRAY_TYPE:	return STRUCT_TYPE;
    case STRUCT_P_ARRAY_TYPE:	return STRUCT_P_TYPE;
    default:
      error("invalid type: \"%d\" in atype_to_type()", type);
  }
}

/* return 1 for an array type, 0 for not an array type */
int is_array(unsigned char type)
{
  if(type == VOID_P_ARRAY_TYPE ||
     type == INT_ARRAY_TYPE ||
     type == INT_P_ARRAY_TYPE ||
     type == CHAR_ARRAY_TYPE ||
     type == CHAR_P_ARRAY_TYPE ||
     type == STRUCT_ARRAY_TYPE ||
     type == STRUCT_P_ARRAY_TYPE)
    return 1;
  return 0;
}

/* return 1 for a pointer type, 0 for not a pointer type */
int is_pointer(unsigned char type)
{
  if(type == VOID_P_TYPE ||
     type == VOID_P_ARRAY_TYPE ||
     type == INT_P_TYPE ||
     type == INT_P_ARRAY_TYPE ||
     type == CHAR_P_TYPE ||
     type == CHAR_P_ARRAY_TYPE ||
     type == STRUCT_P_TYPE ||
     type == STRUCT_P_ARRAY_TYPE)
    return 1;
  return 0;
}

/* return prefix name for table name */
char *prefix_name(char *name, char *prefix) {
  char *rname;

  rname = (char *) malloc(strlen(name) + 4);
  strcpy(rname, prefix);
  strcat(rname, name);
  return rname;
}

/* return 4 bytes aligned value */
int align4(int i)
{
  if ((i % 4) != 0)
    return i + 4 - (i % 4);
  else
    return i;
}

/* return 4 bytes aligned offset & set current offset */
int align_offset(int *offsetp, unsigned int size, unsigned char type)
{
  int offset = *offsetp;

  if (type != CHAR_TYPE)
    offset = align4(offset);
  *offsetp = offset + size;
  return offset + size - 4;
}

/* return 4 bytes aligned MEMBER offset & set current MEMBER offset */
int align_mboffset(int *offsetp, unsigned int size, unsigned char type)
{
  int offset = *offsetp;

  if (type != CHAR_TYPE)
    offset = align4(offset);
  *offsetp = offset + size;
  return offset;
}

/* add symbol to symbol table */
struct symbol *add_symbol(struct table *tablep, char *name, unsigned char kind,
		 unsigned char optype, unsigned char type, char *stname,
		 unsigned int size, unsigned int offset)
{
  int hashval;
  int i;
  struct symbol *symbolp;

  if ((symbolp = (struct symbol *) malloc(sizeof(*symbolp))) == NULL)
    error("can't malloc in add_symbol()");

  /* initialize members */
  symbolp->name = name;
  symbolp->kind = kind;
  symbolp->optype = optype;
  symbolp->type = type;
  symbolp->stname = stname;
  symbolp->size = size;
  symbolp->offset = offset;
  for (i = 0; i < (sizeof(symbolp->ip)/sizeof(unsigned int)); i++)
    symbolp->ip[i] = 0;
  symbolp->ipc = 0;

  /* if structure name symbol, create it's member table */
  if ((tablep == current_sttable) || (tablep == global_sttable))
    symbolp->mbtable = create_table(prefix_name(name, "(m)"));
  else symbolp->mbtable = NULL;

  /* link symbol to table */
  hashval = hash_function(name);
  symbolp->next = tablep->hash[hashval];
  tablep->hash[hashval] = symbolp;
  return symbolp;
}

/* find symbol in symbol table */
struct symbol *find_symbol(struct table *tablep, char *name)
{
  struct symbol *symbolp;

  for (symbolp = tablep->hash[hash_function(name)]; symbolp != NULL;
       symbolp = symbolp->next)
    if (strcmp(name, symbolp->name) == 0)
      return symbolp;
  return NULL;
}

/* find symbol in current symbol table then global table */
struct symbol *lookup_symbol(char *name)
{
  struct symbol *symbolp;

  if ((symbolp = find_symbol(local_table, name)) == NULL)
    if ((symbolp = find_symbol(global_table, name)) == NULL)
      return NULL;
  return symbolp;
}

/* find structure in current structure table then global table */
struct symbol *lookup_struct(char *name)
{
  struct symbol *symbolp;

  if ((symbolp = find_symbol(current_sttable, name)) == NULL)
    if ((symbolp = find_symbol(global_sttable, name)) == NULL)
      return NULL;
  return symbolp;
}

/* return byte size of input type */
unsigned int size_of_type(unsigned char type, char *stname)
{
  struct symbol *symbolp;

  switch (type) {
    case VOID_P_TYPE:		return POINTER_SIZE;
    case VOID_P_P_TYPE:		return POINTER_SIZE;
    case INT_TYPE:		return INT_SIZE;
    case INT_P_TYPE:		return POINTER_SIZE;
    case INT_P_P_TYPE:		return POINTER_SIZE;
    case CHAR_TYPE:		return CHAR_SIZE;
    case CHAR_P_TYPE:		return POINTER_SIZE;
    case CHAR_P_P_TYPE:		return POINTER_SIZE;
    case STRUCT_P_TYPE:		return POINTER_SIZE;
    case STRUCT_P_P_TYPE:	return POINTER_SIZE;

    case STRUCT_TYPE:
      symbolp = lookup_struct(stname);
      if (symbolp == NULL)
	error("can't lookup struct \"%s\" in size_of_type()", stname);
      return symbolp->size;

    default:
      error("invalid type: \"%d\" in size_of_type()", type);
  }
}

/* return name of input kind */
char *kind_name(unsigned char kind)
{
  switch (kind) {
    case GLOBAL:		return "global";
    case LOCAL:			return "local";
    case ARGUMENT:		return "argument";
    case MEMBER:		return "member";
    case FUNCTION:		return "function";
    case FUNCTIONI:		return "functioni";
    default:
      error("invalid kind: \"%d\" in kind_name()", kind);
  }
}

/* return optional type name of input optype */
char *optype_name(unsigned char optype)
{
  switch (optype) {
    case NO_OPTYPE:		return "no_opt";
    case STATIC_OPTYPE:		return "static";
    case EXTERN_OPTYPE:		return "extern";
    case N_A:			return "n/a";
    default:
      error("invalid optype: \"%d\" in optype_name()", optype);
  }
}

/* return type name of input type */
char *type_name(unsigned char type)
{
  switch (type) {
    case VOID_TYPE:		return "void";
    case VOID_P_TYPE:		return "void *";
    case VOID_P_ARRAY_TYPE:	return "void * ary";
    case VOID_P_P_TYPE:		return "void **";
    case INT_TYPE:		return "int";
    case INT_ARRAY_TYPE:	return "int ary";
    case INT_P_TYPE:		return "int *";
    case INT_P_ARRAY_TYPE:	return "int * ary";
    case INT_P_P_TYPE:		return "int **";
    case CHAR_TYPE:		return "char";
    case CHAR_ARRAY_TYPE:	return "char ary";
    case CHAR_P_TYPE:		return "char *";
    case CHAR_P_ARRAY_TYPE:	return "char * ary";
    case CHAR_P_P_TYPE:		return "char **";
    case STRUCT_TYPE:		return "strt";
    case STRUCT_ARRAY_TYPE:	return "strt ary";
    case STRUCT_P_TYPE:		return "strt *";
    case STRUCT_P_ARRAY_TYPE:	return "strt * ary";
    case STRUCT_P_P_TYPE:	return "strt **";
    case N_A:			return "n/a";
    default:
      error("invalid type: \"%d\" in type_name()", type);
  }
}

/* print symbol table */
void print_table(struct table *tablep)
{
  struct symbol *symbolp;
  int i;
  char *kn;
  char *on;
  char *tn;
  static int isfirst = 1;

  if (isfirst) {
    fprintf(stdout, "========== ========== ========== ========== ========== "
	    "========== ====== ======\n");
    fprintf(stdout, "table      symbol     kind       opt_type   type       "
	    "strt_name    size offset\n");
    fprintf(stdout, "========== ========== ========== ========== ========== "
	    "========== ====== ======\n");
    isfirst = 0;
  }

  /* print symbol's values */
  for (i = 0; i < HASH_SIZE; i++) {
    for (symbolp = tablep->hash[i]; symbolp != NULL; symbolp = symbolp->next) {
      kn = kind_name(symbolp->kind);
      on = optype_name(symbolp->optype);
      tn = type_name(symbolp->type);
      fprintf(stdout, "%-10.10s %-10.10s %-10.10s %-10.10s %-10.10s %-10.10s "
              "%6d %6d\n", tablep->name, symbolp->name, kn, on, tn,
	      symbolp->stname, symbolp->size, symbolp->offset);
    }
  }
  fprintf(stdout, "---------- ---------- ---------- ---------- ---------- "
          "---------- ------ ------\n");

  /* print it's structure symbol table then it's member table */
  if (tablep == local_table)
    print_table(local_sttable);
  else if (tablep == global_table)
    print_table(global_sttable);
  else if ((tablep == local_sttable) || (tablep == global_sttable)) {
    for (i = 0; i < HASH_SIZE; i++) {
      for (symbolp = tablep->hash[i]; symbolp != NULL;
           symbolp = symbolp->next) {
	print_table(symbolp->mbtable);
      }
    }
  }
}

/* ====================================================================== */
