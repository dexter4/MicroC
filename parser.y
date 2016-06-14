/* ====================================================================== */

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "symbol.c"

/* ====================================================================== */

#define MAX_NO_CODES	10240	/* maximum number of codes generated */
#define MAX_LINE	2560	/* max code line length */
#define NO_TMP_REGIS	27	/* r0 ~ r26 for temporaly registers */
#define REGI_RETURN	27	/* r27 is for return value */
#define MAX_FUNCTION    100     /* maximum number of functions */

#define MAX_CASE	100	
#define MAX_FOR		100

#define NO_EXP			0
#define UNARY_MULTIPLY_EXP	1
#define MEMBER_PERIOD_EXP	2
#define MEMBER_PERIOD_EXP2	3
#define MEMBER_ARROW_EXP	4
#define FACTOR_VAR_EXP		5
#define FACTOR_ARRAY_EXP	6

#define NO_REGI			32
#define NO_IP			0

/* ====================================================================== */

extern FILE *yyin;		/* FILE * for input file */
extern char *yytext;		/* current lexeme is stored here */
extern int yyleng;		/* current lexeme's length */

extern char *lex;		/* lexeme of ID and NUM from scanner */
extern int source_line_no;	/* souce line number */

/* ====================================================================== */

void regi_init(void);
void regi_free(int i);
int regi_new(void);
void backpatch(unsigned int ip1, unsigned int ip2);
void backpatch_delete(unsigned int tip);
void backpatch_funcalls(void);
void print_code(void);
int yyerror(char *message);

/* ====================================================================== */

char *prog_name;		/* program file name from argv[] */
char *source_file_name;		/* source program file name without dir */
char option_symbol;		/* -s option means print symbol table */

int position;			/* current symbol's kind */

int global_offset;		/* global variable offset */
int local_offset;		/* local variable offset */
int *current_offset;		/* current offset pointer */

int mboffset;			/* member variable offset */
int *current_mboffset;		/* current member offset pointer */

int opoffset;			/* opposite side memory offset */
int *current_opoffset;		/* current opposite offset pointer */

int farg_count;			/* no of formal args in function declaration */
int farg_size;
int aarg_count;			/* no of actual args in function call */

int local_backpatch_ip;	

int switch_exp;
int switch_ip;
int case_count;
int case_break[MAX_CASE];
int is_default;
int is_break;
int break_ip;

int for_ip;
int for_ip2;
int for_count = 0;
int for_out[MAX_CASE];

int fun_count = 0;		/* no of functions  */
int section_line[MAX_FUNCTION];	/* section line location */
char *fun_name[MAX_FUNCTION];	/* all function name  */

int have_return = 0;

char *current_fun_name = 0;	/* current function name */

unsigned int ip = 0;		/* instruction pointer */

char *code[MAX_NO_CODES];	/* generated codes */
char regi_used[NO_TMP_REGIS];	/* 1 if register is used */

char *member_name;
unsigned char last_exp;

/* ====================================================================== */

typedef struct l_type_struct {	/* lex attribute for var and num */
  char *lex;
} l_type;

typedef struct t_type_struct {	/* type attribute for type_specifier */
  unsigned char optype;		/* optional type; static, extern */
  unsigned char type;		/* type; void, int, char, struct ... */
  char *stname;			/* structure name */
} t_type;

typedef struct o_type_struct {	/* operator attribute for relop, addop... */
  int operator;
} o_type;

typedef struct r_type_struct {  /* #register attribute for expressions */
  char *rlex;
  unsigned int rip;
  unsigned int lastip1;
  unsigned int lastip2;
  unsigned char lastexp;
  unsigned char regi;
  unsigned char pregi;
} r_type;

typedef struct p_type_struct {  /* ip attribute for backpatching */
  unsigned int ip;
} p_type;

%}

/* ====================================================================== */

%start program

%union {
  l_type lval;
  t_type tval;
  o_type oval;
  r_type rval;
  p_type pval;
}

%token VOID INT CHAR STRUCT STATIC EXTERN CONST
%token IF ELSE SWITCH CASE DEFAULT WHILE FOR RETURN BREAK
%token CLEAR SLEEP INPUT OUTPUTS OUTPUTC OUTPUT
%token PLUS MINUS MULTIPLY DIVIDE PERCENT
%token LT LE GT GE EQ NE
%token DOUBLEOR DOUBLEAND EXCLAMATION
%token ASSIGN
%token PERIOD ARROW AMPERSAND
%token COMMA SEMICOLON COLON
%token LPAR RPAR LBRACE RBRACE LBRACKET RBRACKET
%token ID OCTNUM HEXNUM NUM CHARCONST STRINGCONST
%token UNDEFINED
%token LIBCALL
%token LIBFRD
%token LIBFWT

%type <lval> var num
%type <tval> type_specifier optional_type type struct_type
%type <oval> memop
%type <rval> expression_stmt expression unary_expression_assign
             logical_expression relational_expression additive_expression
	     unary_expression member_expression term factor call
%type <pval> if_rpar if_else while_lpar while_rpar

%expect 1

/* ====================================================================== */

%%

program
  :
  {
    struct symbol *symbolp;
    
    /* start parsing, create global table, initialize current table & offset */
    position = GLOBAL;
    current_table = global_table = create_table("_global");
    current_offset = &global_offset;
    *current_offset = 0;

    /* create global structure table, initialize current structure table */
    current_sttable = global_sttable = create_table("(s)_global");

    /* initialize opposite offset for string constant, static, extern vars */
    current_opoffset = &opoffset;
    *current_opoffset = 0;
    
    /* code generate */
    generate("%d: ld gp, 0(0)", ip++);
    generate("%d: st 0, 0(0)", ip++);
    generate("%d: lda fp, -%%d(gp)", ip++);
    generate("%d: lda sp, -%%d(gp)", ip++);
    generate("%d: push fp", ip++);
    generate("%d: lda 0, 2(pc)", ip++);
    generate("%d: push 0", ip++);
    symbolp = add_symbol(global_table, "main", FUNCTIONI, NO_OPTYPE, VOID_TYPE,
                         "n/a", 0, 0);
    generate("%d: ldc pc, %%d", ip++);
    symbolp->ip[0] = ip - 1;
    symbolp->ipc = 1;
    generate("%d: halt", ip++);
  }
    var_declaration_list fun_declaration_list
  { /* code generate */
    backpatch(2, align4(global_offset));
    backpatch(3, align4(global_offset));
    backpatch_funcalls();
    print_code();
  
    /* end whole program parsing, print global table */
    if (option_symbol == 1) {    
      print_table(global_table);
    }
  }
;

var_declaration_list
  : var_declaration_list var_declaration
  | empty
;

fun_declaration_list
  : fun_declaration_list fun_declaration
  | fun_declaration
;

var_declaration
  : type_specifier var SEMICOLON
  {
    char *var = $<lval>2.lex;
    unsigned int size;
    int offset;

    /* error 00: wrong void variable */
    if ($<tval>1.type == VOID_TYPE)
      error("00: wrong void variable \'%s\'", var);

    /* error 01: redefined variable */
    if (find_symbol(current_table, var) != NULL)
      error("01: redefined variable \'%s\'", var);

    /* add symbol & set current offset. size_of_type() return byte size of
       input type */
    size = size_of_type($<tval>1.type, $<tval>1.stname);
    offset = align_offset(current_offset, size, $<tval>1.type);
    add_symbol(current_table, $<lval>2.lex, position, $<tval>1.optype,
               $<tval>1.type, $<tval>1.stname, size, offset);
  }
  | type_specifier var LBRACKET num RBRACKET SEMICOLON
  {
    char *var = $<lval>2.lex;
    unsigned int n;
    unsigned int size;
    int offset;

    /* error 02: wrong void array */
    if ($<tval>1.type == VOID_TYPE)
      error("02: wrong void array \'%s\'", var);

    /* error 03: redefined array */
    if (find_symbol(current_table, var) != NULL)
      error("03: redefined array \'%s\'", var);

    /* add array type symbol & set current offset */
    n = atoi($<lval>4.lex);
    size = n * size_of_type($<tval>1.type, $<tval>1.stname);
    offset = align_offset(current_offset, size, $<tval>1.type);
    add_symbol(current_table, $<lval>2.lex, position, $<tval>1.optype,
               type_to_atype($<tval>1.type), $<tval>1.stname, size, offset);
  }
  | type_specifier SEMICOLON
;

type_specifier
  : optional_type type MULTIPLY
  { /* assign type & optype & structure name attribute values.
       type_to_ptype() return pointer type of input type */
    $<tval>$.optype = $<tval>1.optype;
    $<tval>$.type = type_to_ptype($<tval>2.type);
    $<tval>$.stname = $<tval>2.stname;
  }
  | optional_type type
  {
    $<tval>$.optype = $<tval>1.optype;
    $<tval>$.type = $<tval>2.type;
    $<tval>$.stname = $<tval>2.stname;
  }
  | type MULTIPLY
  {
    $<tval>$.optype = NO_OPTYPE;
    $<tval>$.type = type_to_ptype($<tval>1.type);
    $<tval>$.stname = $<tval>1.stname;
  }
  | type
  {
    $<tval>$.optype = NO_OPTYPE;
    $<tval>$.type = $<tval>1.type;
    $<tval>$.stname = $<tval>1.stname;
  }
;

optional_type
  : STATIC
  { /* assign optional type attribute value to lift */
    $<tval>$.optype = STATIC_OPTYPE;
  }
  | EXTERN
  {
    $<tval>$.optype = EXTERN_OPTYPE;
  }
;

type
  : INT
  { /* assign type & structure name attribute value to lift */
    $<tval>$.type = INT_TYPE;
    $<tval>$.stname = "n/a";
  }
  | CHAR
  {
    $<tval>$.type = CHAR_TYPE;
    $<tval>$.stname = "n/a";
  }
  | VOID
  {
    $<tval>$.type = VOID_TYPE;
    $<tval>$.stname = "n/a";
  }
  | struct_type
  {
    $<tval>$.type = STRUCT_TYPE;
    $<tval>$.stname = $<tval>1.stname;
  }
;

struct_type
  : STRUCT var
  { 
    /* add structure symbol in current structure table */
    current_stsymbol = add_symbol(current_sttable, $<lval>2.lex, position, N_A,
                                  N_A, "n/a", 0, 0);
    current_mbtable = current_stsymbol->mbtable;
    current_mboffset = &mboffset;
    *current_mboffset = 0;
  }
    LBRACE member_declaration_list RBRACE
  { /* structure size = last current member offset */
    current_stsymbol->size = align4(*current_mboffset);

    /* assign lex attribute value for structure name to lift */
    $<tval>$.stname = $<lval>2.lex;
  }
  | STRUCT var
  { /* assign lex attribute value for structure name to lift */
    $<tval>$.stname = $<lval>2.lex;
  }
;

member_declaration_list
  : member_declaration_list member_declaration
  | member_declaration
;

member_declaration
  : type_specifier var SEMICOLON
  {
    char *var = $<lval>2.lex;
    struct symbol *symbolp;
    unsigned int size;
    int offset;

    /* error 10: wrong void member */
    if ($<tval>1.type == VOID_TYPE)
      error("10: wrong void member \'%s\'", var);

    /* error 11: redefined member */
    symbolp = find_symbol(current_mbtable, var);
    if (symbolp != NULL) 
      error("11: redefined member \'%s\'", var);

    /* add member symbol & set current member offset */
    size = size_of_type($<tval>1.type, $<tval>1.stname);
    offset = align_mboffset(current_mboffset, size, $<tval>1.type);
    add_symbol(current_mbtable, var, MEMBER, N_A, $<tval>1.type,
	       $<tval>1.stname, size, offset);
  }
  | type_specifier var LBRACKET num RBRACKET SEMICOLON
  {
    char *var = $<lval>2.lex;
    struct symbol *symbolp;
    unsigned int n;
    unsigned int size;
    int offset;

    /* error 12: wrong void array member */
    if ($<tval>1.type == VOID_TYPE)
      error("12: wrong void array member \'%s\'", var);

    /* error 13: redefine array member */
    symbolp = find_symbol(current_mbtable, var);
    if (symbolp != NULL)
      error("13: redefined array member \'%s\'", var);
    
    /* add array type member symbol & set current member offset */
    n = atoi($<lval>4.lex);
    size = n * size_of_type($<tval>1.type, $<tval>1.stname);
    offset = align_mboffset(current_mboffset, size, $<tval>1.type);
    add_symbol(current_mbtable, $<lval>2.lex, MEMBER, N_A,
               type_to_atype($<tval>1.type), $<tval>1.stname, size, offset);
  }
;

var
  : ID
  { /* assign lexeme attribute value */
    $<lval>$.lex = lex;
  }
;

num
  : NUM
  { /* assign lexeme attribute value */
    $<lval>$.lex = lex;
  }
  | OCTNUM
  { /* convert & assign octal to decimal number */
    char *ptr;
    char *str = (char *) malloc(MAX_DIGIT);

    sprintf(str, "%u", (unsigned int) (strtol(lex + 1, &ptr, 8)));
    $<lval>$.lex = str;
  }
  | HEXNUM
  { /* convert & assign hexadecimal to decimal number */
    char *ptr;
    char *str = (char *) malloc(MAX_DIGIT);

    sprintf(str, "%u", (unsigned int) (strtol(lex + 2, &ptr, 16)));
    $<lval>$.lex = str;
  }
  | CHARCONST
  { /* convert & assign a character to decimal number */
    char c1 = *(lex + 1);
    char c2 = *(lex + 2);
    char *str = (char *) malloc(MAX_DIGIT);

    if (c2 == '\'') {
      sprintf(str, "%u", (unsigned int) c1);
    } else {
      if (c1 == '\\' && c2 == 'n')
	sprintf(str, "%u", 10);
      else if (c1 == '\\' && c2 == 't')
	sprintf(str, "%u", 9);
    }
    $<lval>$.lex = str;
  }
;

fun_declaration
  : type_specifier var
  { /* create local table, set current table, initialize offset &
       formal argument count */
    position = ARGUMENT;
    current_table = local_table = create_table($<lval>2.lex);
    current_offset = &local_offset;
    *current_offset = 0;
    farg_count = 0;
    farg_size = 0;

    fun_count++;
    section_line[fun_count] = ip;
    fun_name[fun_count] = $<lval>2.lex;

    /* create local structure table, set current structure table */
    current_sttable = local_sttable =
    				create_table(prefix_name($<lval>2.lex, "(s)"));
  }
    LPAR params RPAR
  { /* add function name to global table, set local position */
    char *var = $<lval>2.lex;
    struct symbol *symbolp;
    symbolp = find_symbol(global_table, var);

    /* error 20: redefined function */
    if (symbolp != NULL) {
      if (symbolp->kind != FUNCTIONI) {
        error("20: redefined function \'%s\'", var);
      } else {
        symbolp->kind = FUNCTION;
	symbolp->optype = $<tval>1.optype;
	symbolp->type = $<tval>1.type;
	symbolp->stname = $<tval>1.stname;
	symbolp->size = farg_count;
	symbolp->offset = ip;
      }
    } else 
      add_symbol(global_table, $<lval>2.lex, FUNCTION, $<tval>1.optype,
                 $<tval>1.type, $<tval>1.stname, farg_count, ip);
    farg_size = *current_offset;
    position = LOCAL;
  }
    LBRACE local_declarations
  {
    generate("%d: lda sp, -%%d(sp)", ip++);
    local_backpatch_ip = ip;
  } 
    statement_list RBRACE
  {
    char *var = $<lval>2.lex;
    struct symbol *symbolp;
    symbolp = lookup_symbol(var);

    backpatch(local_backpatch_ip - 1, align4(local_offset - farg_size));
    if (have_return == 0 || symbolp->name == "main") {
      generate("%d: ldc %d, 0", ip++, REGI_RETURN);
      generate("%d: lda sp, 0(fp)", ip++);
      generate("%d: ld fp, 0(fp)", ip++);
      generate("%d: ld pc, -4(sp)", ip++);
    }
    have_return = 0;
    
    /* end a function parsing, print local table */
    if (option_symbol == 1)
      print_table(current_table);
  }
;

params
  : param_list
  | VOID
;

param_list
  : param_list COMMA param
  { /* count formal argument during looping */
    farg_count++;
  }
  | param
  {
    farg_count++;
  }
;

param
  : type_specifier var
  { /* add parameter to current local table & set current offset */
    char *var = $<lval>2.lex;
    struct symbol *symbolp = find_symbol(current_table, var);
    unsigned int size;

    /* error 30: wrong optional type parameter */
    if ($<tval>1.optype != NO_OPTYPE)
      error("30: wrong optional type parameter \'%s\'", var);

    /* error 31: wrong void parameter */
    if ($<tval>1.type == VOID_TYPE)
      error("31: wrong void parameter \'%s\'", var);

    /* error 99: wrong structure parameter(C-Step Only) */
    if ($<tval>1.type == STRUCT_TYPE)
      error("99: wrong structure parameter \'%s\'(C-Step Only)", var);

    /* error 32: redefined parameter */
    if (symbolp != NULL)
      error("32: redefined parameter \'%s\'", var);

    size = size_of_type($<tval>1.type, $<tval>1.stname);
    add_symbol(current_table, var, position, $<tval>1.optype, $<tval>1.type,
	       $<tval>1.stname, size, *current_offset);
    *current_offset = *current_offset + 4;
  }
  | type_specifier var LBRACKET RBRACKET
  { /* add array parameter to current local table & set current offset */
    char *var = $<lval>2.lex;
    struct symbol *symbolp = find_symbol(current_table, var);
    unsigned int size = POINTER_SIZE;

    /* error 33: wrong optional type array parameter */
    if($<tval>1.optype != NO_OPTYPE)
      error("33: wrong optional type array parameter \'%s\'",var);

    /* error 34: wrong void array parameter */
    if($<tval>1.type == VOID_TYPE)
      error("34: wrong void array parameter \'%s\'", var);

    /* error 35: redefined array parameter */
    if(symbolp != NULL)
      error("35: redefined array parameter \'%s\'", var);

    add_symbol(current_table, var, position, $<tval>1.optype,
               type_to_ptype($<tval>1.type), $<tval>1.stname, size,
	       *current_offset);
    *current_offset = *current_offset + 4;
  }
;

local_declarations
  : local_declarations var_declaration
  | empty
;

statement_list
  : statement_list statement
  | empty
;

statement
  : compound_stmt
  | expression_stmt
  | selection_stmt
  | case_stmt
  | iteration_stmt
  | clear_stmt
  | sleep_stmt
  | funcall_stmt
  | return_stmt
  | input_stmt
  | output_stmt
;

compound_stmt
  : LBRACE statement_list RBRACE
;

expression_stmt
  : expression SEMICOLON
  {
    $<rval>$.rip = ip;
    regi_free($<rval>1.regi);
    regi_free($<rval>1.pregi);
  }
  | SEMICOLON
  {
    $<rval>$.rip = ip;
  }
;

expression
: unary_expression_assign expression
  {
    if ($<rval>1.pregi == NO_REGI) {
      char *var = $<rval>1.rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int offset = symbolp->offset;

      if (symbolp->kind == GLOBAL) {
	if (symbolp->type == CHAR_TYPE)
	  generate("%d: stb %d, -%d(gp)", ip++, $<rval>2.regi, offset);
	else
	  generate("%d: st %d, -%d(gp)", ip++, $<rval>2.regi, offset);
      } else {
	if (symbolp->type == CHAR_TYPE)
	  generate("%d: stb %d, -%d(fp)", ip++, $<rval>2.regi, offset + 8);
	else
	  generate("%d: st %d, -%d(fp)", ip++, $<rval>2.regi, offset + 8);
      }

    } else {
      char *var = $<rval>1.rlex;
      struct symbol *symbolp = lookup_symbol(var);

      if ($<rval>1.lastexp == FACTOR_ARRAY_EXP &&
	  symbolp->type == CHAR_ARRAY_TYPE)
	generate("%d: stb %d, 0(%d)", ip++, $<rval>2.regi, $<rval>1.pregi);
      else if ($<rval>1.lastexp == UNARY_MULTIPLY_EXP &&
	       (symbolp->type == CHAR_P_TYPE ||
		symbolp->type == CHAR_P_ARRAY_TYPE))
	generate("%d: stb %d, 0(%d)", ip++, $<rval>2.regi, $<rval>1.pregi);
      else if ($<rval>1.lastexp == MEMBER_PERIOD_EXP ||
	       $<rval>1.lastexp == MEMBER_PERIOD_EXP2 ||
	       $<rval>1.lastexp == MEMBER_ARROW_EXP) {
	struct symbol *ssymbolp = lookup_struct(symbolp->stname);
	struct symbol *msymbolp = find_symbol(ssymbolp->mbtable, member_name);

	if (msymbolp->type == CHAR_TYPE ||
	    msymbolp->type == CHAR_ARRAY_TYPE)
	  generate("%d: stb %d, 0(%d)", ip++, $<rval>2.regi, $<rval>1.pregi);
      }
      else
	generate("%d: st %d, 0(%d)", ip++, $<rval>2.regi, $<rval>1.pregi);
      regi_free($<rval>1.pregi);
    }
    $<rval>$.regi = $<rval>2.regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
  }
  | logical_expression
  {
    if ($<rval>1.lastexp == FACTOR_ARRAY_EXP ||
	$<rval>1.lastexp == MEMBER_PERIOD_EXP) {
      backpatch_delete($<rval>1.lastip2);
      regi_free($<rval>1.pregi);
      $<rval>$.regi = $<rval>1.regi;
      $<rval>$.pregi = NO_REGI;
      $<rval>$.rlex = $<rval>1.rlex;
      $<rval>$.lastip1 = NO_IP;
      $<rval>$.lastip2 = NO_IP;
      $<rval>$.lastexp = NO_EXP;

    } else {
      $<rval>$.regi = $<rval>1.regi;
      $<rval>$.pregi = $<rval>1.pregi;
      $<rval>$.rlex = $<rval>1.rlex;
      $<rval>$.lastip1 = $<rval>1.lastip1;
      $<rval>$.lastip2 = $<rval>1.lastip2;
      $<rval>$.lastexp = $<rval>1.lastexp;
    }
  }
  |libcall_exp
  {
      $<rval>$.regi = $<rval>1.regi;
      $<rval>$.pregi = $<rval>1.pregi;
      $<rval>$.rlex = $<rval>1.rlex;
      $<rval>$.lastip1 = $<rval>1.lastip1;
      $<rval>$.lastip2 = $<rval>1.lastip2;
      $<rval>$.lastexp = $<rval>1.lastexp;
 
  }
  |libfrd_exp
  {
      $<rval>$.regi = $<rval>1.regi;
      $<rval>$.pregi = $<rval>1.pregi;
      $<rval>$.rlex = $<rval>1.rlex;
      $<rval>$.lastip1 = $<rval>1.lastip1;
      $<rval>$.lastip2 = $<rval>1.lastip2;
      $<rval>$.lastexp = $<rval>1.lastexp;
 
  }
  |libfwt_exp
  {
      $<rval>$.regi = $<rval>1.regi;
      $<rval>$.pregi = $<rval>1.pregi;
      $<rval>$.rlex = $<rval>1.rlex;
      $<rval>$.lastip1 = $<rval>1.lastip1;
      $<rval>$.lastip2 = $<rval>1.lastip2;
      $<rval>$.lastexp = $<rval>1.lastexp;
 
  }
;

libfrd_exp
 :LIBFRD LPAR expression COMMA expression COMMA expression RPAR
 {
    int regi = regi_new();

    generate("%d: frd %d, %d, %d",ip++,$<rval>3.regi,$<rval>5.regi,$<rval>7.regi);
    regi_free($<rval>3.regi);
    regi_free($<rval>5.regi);
    regi_free($<rval>7.regi);
 

    generate("%d: lda %d, 0(%d)", ip++, regi, REGI_RETURN);
    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
 }
;


libfwt_exp
 :LIBFWT LPAR expression COMMA expression COMMA expression RPAR
 {

    int regi = regi_new();

    generate("%d: fwt %d, %d, %d",ip++,$<rval>3.regi,$<rval>5.regi,$<rval>7.regi);
    regi_free($<rval>3.regi);
    regi_free($<rval>5.regi);
    regi_free($<rval>7.regi);
 

    generate("%d: lda %d, 0(%d)", ip++, regi, REGI_RETURN);
    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
 }
;

libcall_exp
 :LIBCALL LPAR expression COMMA expression COMMA expression RPAR
 {
    int regi = regi_new();

    generate("%d: lib %d, %d, %d",ip++,$<rval>3.regi,$<rval>5.regi,$<rval>7.regi);
    regi_free($<rval>3.regi);
    regi_free($<rval>5.regi);
    regi_free($<rval>7.regi);
 

    generate("%d: lda %d, 0(%d)", ip++, regi, REGI_RETURN);
    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;

 } 
;

unary_expression_assign
  : unary_expression ASSIGN
  {
    if ($<rval>1.lastexp == FACTOR_VAR_EXP ||
	$<rval>1.lastexp == FACTOR_ARRAY_EXP ||
	$<rval>1.lastexp == MEMBER_PERIOD_EXP ||
	$<rval>1.lastexp == MEMBER_PERIOD_EXP2 ||
	$<rval>1.lastexp == MEMBER_ARROW_EXP) {
      backpatch_delete($<rval>1.lastip1);
      regi_free($<rval>1.regi);
      $<rval>$.regi = NO_REGI;
      $<rval>$.pregi = $<rval>1.pregi;
      $<rval>$.rlex = $<rval>1.rlex;
      $<rval>$.lastip1 = NO_IP;
      $<rval>$.lastip2 = NO_IP;
      $<rval>$.lastexp = NO_EXP;
    }

    else if ($<rval>1.lastexp == UNARY_MULTIPLY_EXP) {
      backpatch_delete($<rval>1.lastip1);
      regi_free($<rval>1.regi);
      $<rval>$.regi = NO_REGI;
      $<rval>$.pregi = $<rval>1.pregi;
      $<rval>$.rlex = $<rval>1.rlex;
      $<rval>$.lastip1 = NO_IP;
      $<rval>$.lastip2 = NO_IP;
      //$<rval>$.lastexp = NO_EXP;
    }
  }
;

logical_expression
  : logical_expression logop relational_expression
  {
    int regi = regi_new();

    /* logical-OR operation */
    if ($<oval>2.operator == DOUBLEOR) {
      generate("%d: ldc %d, 1", ip++, regi);
      generate("%d: jgt %d, 2(pc)", ip++, $<rval>1.regi);
      generate("%d: jgt %d, 1(pc)", ip++, $<rval>3.regi);
      generate("%d: ldc %d, 0", ip++, regi);

    /* logical-AND operation */
    } else if ($<oval>2.operator == DOUBLEAND) {
      generate("%d: ldc %d, 0", ip++, regi);
      generate("%d: jle %d, 2(pc)", ip++, $<rval>1.regi);
      generate("%d: jle %d, 1(pc)", ip++, $<rval>3.regi);
      generate("%d: ldc %d, 1", ip++, regi);
    }
    regi_free($<rval>1.regi);
    regi_free($<rval>3.regi);
    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
  }
  | relational_expression
  {
    $<rval>$.regi = $<rval>1.regi;
    $<rval>$.pregi = $<rval>1.pregi;
    $<rval>$.rlex = $<rval>1.rlex;
    $<rval>$.lastip1 = $<rval>1.lastip1;
    $<rval>$.lastip2 = $<rval>1.lastip2;
    $<rval>$.lastexp = $<rval>1.lastexp;
  }
;

logop
  : DOUBLEOR
  {
    $<oval>$.operator = DOUBLEOR;
  }
  | DOUBLEAND
  {
    $<oval>$.operator = DOUBLEAND;
  }
;

relational_expression
  : additive_expression relop additive_expression
  {
    int regi = regi_new();

    if ($<oval>2.operator == LT)
      generate("%d: lt %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
    else if ($<oval>2.operator == LE)
      generate("%d: le %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
    else if ($<oval>2.operator == GT)
      generate("%d: gt %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
    else if ($<oval>2.operator == GE)
      generate("%d: ge %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
    else if ($<oval>2.operator == EQ)
      generate("%d: eq %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
    else if ($<oval>2.operator == NE)
      generate("%d: ne %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);

    regi_free($<rval>1.regi);
    regi_free($<rval>3.regi);
    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
  }
  | additive_expression
  {
    $<rval>$.regi = $<rval>1.regi;
    $<rval>$.pregi = $<rval>1.pregi;
    $<rval>$.rlex = $<rval>1.rlex;
    $<rval>$.lastip1 = $<rval>1.lastip1;
    $<rval>$.lastip2 = $<rval>1.lastip2;
    $<rval>$.lastexp = $<rval>1.lastexp;
  }  
;

relop
  : LT
  {
    $<oval>$.operator = LT;
  }
  | LE
  {
    $<oval>$.operator = LE;
  }
  | GT
  {
    $<oval>$.operator = GT;
  }
  | GE
  {
    $<oval>$.operator = GE;
  }
  | EQ
  {
    $<oval>$.operator = EQ;
  }
  | NE
  {
    $<oval>$.operator = NE;
  }  
;

additive_expression
  : additive_expression addop term
  {
    int regi = regi_new();

    if ($<oval>2.operator == PLUS)
      generate("%d: add %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
    else if ($<oval>2.operator == MINUS)
      generate("%d: sub %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
      
    regi_free($<rval>1.regi);
    regi_free($<rval>3.regi);
    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
  }
  | term
  {
    $<rval>$.regi = $<rval>1.regi;
    $<rval>$.pregi = $<rval>1.pregi;
    $<rval>$.rlex = $<rval>1.rlex;
    $<rval>$.lastip1 = $<rval>1.lastip1;
    $<rval>$.lastip2 = $<rval>1.lastip2;
    $<rval>$.lastexp = $<rval>1.lastexp;
  }  
;

addop
  : PLUS
  {
    $<oval>$.operator = PLUS;
  }    
  | MINUS
  {
    $<oval>$.operator = MINUS;
  }    
;

term
  : term mulop unary_expression
  {
    int regi = regi_new();

    if ($<oval>2.operator == MULTIPLY)
      generate("%d: mul %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
    else if ($<oval>2.operator == DIVIDE)
      generate("%d: div %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
    else if ($<oval>2.operator == PERCENT){
      generate("%d: div %d, %d, %d", ip++, regi, $<rval>1.regi, $<rval>3.regi);
      generate("%d: mul %d, %d, %d", ip++, regi, $<rval>3.regi, regi);
      generate("%d: sub %d, %d, %d", ip++, regi, $<rval>1.regi, regi);
    }
    regi_free($<rval>1.regi);
    regi_free($<rval>3.regi);
    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
  }  
  | unary_expression
  {
    $<rval>$.regi = $<rval>1.regi;
    $<rval>$.pregi = $<rval>1.pregi;
    $<rval>$.rlex = $<rval>1.rlex;
    $<rval>$.lastip1 = $<rval>1.lastip1;
    $<rval>$.lastip2 = $<rval>1.lastip2;
    $<rval>$.lastexp = $<rval>1.lastexp;
  }  
;

mulop
  : MULTIPLY
  {
    $<oval>$.operator = MULTIPLY;
  }      
  | DIVIDE
  {
    $<oval>$.operator = DIVIDE;
  }        
  | PERCENT
  {
    $<oval>$.operator = PERCENT;
  }        
;

unary_expression
  : unaop member_expression
  {
    /* !var */
    if ($<oval>1.operator == EXCLAMATION) {
      int regi = regi_new();

      /* logical-NOT operation */
      generate("%d: ldc %d, 0", ip++, regi);
      generate("%d: le %d, %d, %d", ip++, regi, $<rval>2.regi, regi);

      regi_free($<rval>2.regi);
      $<rval>$.regi = regi;
      $<rval>$.pregi = NO_REGI;
      $<rval>$.rlex = NULL;
      $<rval>$.lastip1 = NO_IP;
      $<rval>$.lastip2 = NO_IP;
      $<rval>$.lastexp = NO_EXP;

    /* &var */
    } else if ($<oval>1.operator == AMPERSAND) {
      char *var = $<rval>2.rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int offset = symbolp->offset;

      /* error 99: invalid type error variable(C-Step Only) */
      if (!($<rval>2.lastexp == FACTOR_VAR_EXP ||
	    $<rval>2.lastexp == FACTOR_ARRAY_EXP))
	error("99: invalid type error variable \'%s\'(with '&')(C-Step Only)",
	      var);

      if ($<rval>2.lastexp == FACTOR_VAR_EXP) {
	backpatch_delete($<rval>2.lastip1);
	if (symbolp->kind == GLOBAL) {
	  generate("%d: lda %d, -%d(gp)", ip++, $<rval>2.regi, offset);
	} else {
	  generate("%d: lda %d, -%d(fp)", ip++, $<rval>2.regi, offset + 8);
	}
	$<rval>$.regi = $<rval>2.regi;
	$<rval>$.pregi = $<rval>1.pregi;
	$<rval>$.rlex = $<rval>1.rlex;
	$<rval>$.lastip1 = NO_IP;
	$<rval>$.lastip2 = NO_IP;
	$<rval>$.lastexp = NO_EXP;

      } else if ($<rval>2.lastexp == FACTOR_ARRAY_EXP) {
	backpatch_delete($<rval>2.lastip1);
	regi_free($<rval>2.regi);
	$<rval>$.regi = $<rval>2.pregi;
	$<rval>$.pregi = NO_REGI;
	$<rval>$.rlex = $<rval>2.rlex;
	$<rval>$.lastip1 = NO_IP;
	$<rval>$.lastip2 = NO_IP;
	$<rval>$.lastexp = NO_EXP;
      }

    /* *var */
    } else if ($<oval>1.operator == MULTIPLY) {
      char *var = $<rval>2.rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int regi;

      /* error 54: invalid type error variable */
      if (!is_pointer(symbolp->type))
	error("54: invalid type error variable \'%s\'(with '*')", var);

      if ($<rval>2.lastexp == FACTOR_ARRAY_EXP) {
	backpatch_delete($<rval>2.lastip2);
	regi_free($<rval>2.pregi);
      }
      regi = regi_new();
      generate("%d: ld %d, 0(%d)", ip++, regi, $<rval>2.regi);

      $<rval>$.regi = regi;
      $<rval>$.pregi = $<rval>2.regi;	// cross!
      $<rval>$.rlex = $<rval>2.rlex;
      $<rval>$.lastip1 = ip - 1;
      $<rval>$.lastip2 = NO_IP;
      $<rval>$.lastexp = UNARY_MULTIPLY_EXP;
    }
  }
  | member_expression
  {
    $<rval>$.regi = $<rval>1.regi;
    $<rval>$.pregi = $<rval>1.pregi;
    $<rval>$.rlex = $<rval>1.rlex;
    $<rval>$.lastip1 = $<rval>1.lastip1;
    $<rval>$.lastip2 = $<rval>1.lastip2;
    $<rval>$.lastexp = $<rval>1.lastexp;
  }
;

unaop
  : EXCLAMATION
  {
    $<oval>$.operator = EXCLAMATION;
  }          
  | AMPERSAND
  {
    $<oval>$.operator = AMPERSAND;
  }            
  | MULTIPLY
  {
    $<oval>$.operator = MULTIPLY;
  }            
;

member_expression
  : member_expression memop var
  {
    char* var = $<rval>1.rlex;		// ex: junho
    char* member = $<lval>3.lex;	// ex: name
    struct symbol* symbolp;		// variable symbol pointer
    struct symbol* ssymbolp;		// struct symbol pointer
    struct symbol* msymbolp;		// member symbol pointer
    int operator = $<oval>2.operator;

    symbolp = lookup_symbol(var);

    /* error 40: not a structure variable */
    ssymbolp = lookup_struct(symbolp->stname);
    if (ssymbolp == NULL)
      error("40: not a structure variable \'%s\'", var);

    /* error 41: undefined member */
    msymbolp = find_symbol(ssymbolp->mbtable, member);
    if (msymbolp == NULL)
      error("41: undefined member \'%s\'", member);

    /* error 43: invalid type error variable (with '.') */
    if (operator == PERIOD) {
      if (symbolp->type != STRUCT_TYPE && symbolp->type != STRUCT_ARRAY_TYPE)
	error("43: invalid type error variable \'%s\'(with '.')", var); 

      /* code generate */
      backpatch_delete($<rval>1.lastip1);
      regi_free($<rval>1.regi);

      if ($<rval>1.lastexp == FACTOR_VAR_EXP) {
	int regi1 = regi_new();
	int regi2 = regi_new();
	int regi3 = regi_new();
	int offset = symbolp->offset;

	generate("%d: ldc %d, %d", ip++, regi1, msymbolp->offset);
	if (symbolp->kind == GLOBAL) {
	  generate("%d: add %d, gp, %d", ip++, regi1, regi1);
	  generate("%d: ld %d, -%d(%d)", ip++, regi2, offset, regi1);
	  generate("%d: lda %d, -%d(%d)", ip++, regi3, offset, regi1);
	} else {
	  generate("%d: add %d, fp, %d", ip++, regi1, regi1);
	  generate("%d: ld %d, -%d(%d)", ip++, regi2, offset + 8, regi1);
	  generate("%d: lda %d, -%d(%d)", ip++, regi3, offset + 8, regi1);
	}
	regi_free(regi1);
	$<rval>$.regi = regi2;
	$<rval>$.pregi = regi3;
	$<rval>$.rlex = var;
	$<rval>$.lastip1 = ip - 2;
	$<rval>$.lastip2 = ip - 1;
	$<rval>$.lastexp = MEMBER_PERIOD_EXP;
	member_name = member;
      
      } else if ($<rval>1.lastexp == FACTOR_ARRAY_EXP) {
	int regi1 = regi_new();
	int regi2 = regi_new();

	generate("%d: ldc %d, %d", ip++, regi1, msymbolp->offset);
	generate("%d: add %d, %d, %d", ip++, regi1, $<rval>1.pregi, regi1);
	generate("%d: ld %d, 0(%d)", ip++, regi2, regi1);

	regi_free($<rval>1.pregi);
	$<rval>$.regi = regi2;
	$<rval>$.pregi = regi1;
	$<rval>$.rlex = var;
	$<rval>$.lastip1 = ip - 1;
	$<rval>$.lastip2 = NO_IP;
	$<rval>$.lastexp = MEMBER_PERIOD_EXP2;
	member_name = member;
      }
    }

    /* error 44: invalid type error variable (with '->') */
    else if (operator == ARROW) {
      if ((symbolp->type != STRUCT_P_ARRAY_TYPE) &&
	  (symbolp->type != STRUCT_P_TYPE))
	error("44: invalid type error variable \'%s\'(with '->')", var);

      /* code generate */
      int regi1 = regi_new();
      int regi2 = regi_new();
      int offset = symbolp->offset;

      generate("%d: ldc %d, %d", ip++, regi1, msymbolp->offset);
      generate("%d: add %d, %d, %d", ip++, regi1, $<rval>1.regi, regi1);
      generate("%d: ld %d, 0(%d)", ip++, regi2, regi1);

      regi_free($<rval>1.regi);
      $<rval>$.regi = regi2;
      $<rval>$.pregi = regi1;
      $<rval>$.rlex = var;
      $<rval>$.lastip1 = ip - 1;
      $<rval>$.lastip2 = NO_IP;
      $<rval>$.lastexp = MEMBER_ARROW_EXP;
      member_name = member;
    }
  }
  | member_expression memop var LBRACKET expression RBRACKET
  {
    char* var = $<rval>1.rlex;		// ex: junho
    char* member = $<lval>3.lex;	// ex: name
    struct symbol* symbolp;		// variable symbol pointer
    struct symbol* ssymbolp;		// struct symbol pointer
    struct symbol* msymbolp;		// member symbol pointer
    int operator = $<oval>2.operator;

    symbolp = lookup_symbol(var);

    /* error 40: not a structure variable */
    ssymbolp = lookup_struct(symbolp->stname);
    if (ssymbolp == NULL)
      error("40: not a structure variable \'%s\'", var);

    /* error 42: undefined array member */
    msymbolp = find_symbol(ssymbolp->mbtable, member);
    if (msymbolp == NULL)
      error("42: undefined array member \'%s\'", member);

    /* error 43: invalid type error variable (with '.') */
    if (operator == PERIOD) {
      if (symbolp->type != STRUCT_TYPE && symbolp->type != STRUCT_ARRAY_TYPE)
	error("43: invalid type error variable \'%s\'(with '.')", var); 

      /* code generate */
      backpatch_delete($<rval>1.lastip1);
      regi_free($<rval>1.regi);

      if ($<rval>1.lastexp == FACTOR_VAR_EXP) {
	int regi1 = regi_new();
	int regi2 = regi_new();
	int regi3 = regi_new();
	int offset = symbolp->offset;

	generate("%d: ldc %d, %d", ip++, regi1,
	    size_of_type(atype_to_type(msymbolp->type), msymbolp->stname));
	generate("%d: mul %d, %d, %d", ip++, regi1, $<rval>5.regi, regi1);
	generate("%d: ldc %d, %d", ip++, regi2, msymbolp->offset);
	generate("%d: add %d, %d, %d", ip++, regi1, regi1, regi2);
	if (symbolp->kind == GLOBAL) {
	  generate("%d: add %d, gp, %d", ip++, regi1, regi1);
	  generate("%d: ld %d, -%d(%d)", ip++, regi2, offset, regi1);
	  generate("%d: lda %d, -%d(%d)", ip++, regi3, offset, regi1);
	} else {
	  generate("%d: add %d, fp, %d", ip++, regi1, regi1);
	  generate("%d: ld %d, -%d(%d)", ip++, regi2, offset + 8, regi1);
	  generate("%d: lda %d, -%d(%d)", ip++, regi3, offset + 8, regi1);
	}
	regi_free(regi1);
	regi_free($<rval>5.regi);
	$<rval>$.regi = regi2;
	$<rval>$.pregi = regi3;
	$<rval>$.rlex = var;
	$<rval>$.lastip1 = ip - 2;
	$<rval>$.lastip2 = ip - 1;
	$<rval>$.lastexp = MEMBER_PERIOD_EXP;
	member_name = member;

      } else if ($<rval>1.lastexp == FACTOR_ARRAY_EXP) {
	int regi1 = regi_new();
	int regi2 = regi_new();

	generate("%d: ldc %d, %d", ip++, regi1,
	    size_of_type(atype_to_type(msymbolp->type), msymbolp->stname));
	generate("%d: mul %d, %d, %d", ip++, regi1, $<rval>5.regi, regi1);
	generate("%d: ldc %d, %d", ip++, regi2, msymbolp->offset);
	generate("%d: add %d, %d, %d", ip++, regi1, regi1, regi2);
	generate("%d: add %d, %d, %d", ip++, regi1, $<rval>1.pregi, regi1);
	generate("%d: ld %d, 0(%d)", ip++, regi2, regi1);

	regi_free($<rval>1.pregi);
	regi_free($<rval>5.regi);
	$<rval>$.regi = regi2;
	$<rval>$.pregi = regi1;
	$<rval>$.rlex = var;
	$<rval>$.lastip1 = ip - 1;
	$<rval>$.lastip2 = NO_IP;
	$<rval>$.lastexp = MEMBER_PERIOD_EXP2;
	member_name = member;
      }
    }

    /* error 44: invalid type error variable (with '->') */
    else if (operator == ARROW) {
      if ((symbolp->type != STRUCT_P_ARRAY_TYPE) &&
	  (symbolp->type != STRUCT_P_TYPE))
	error("44: invalid type error variable \'%s\'(with '->')", var);

      /* code generate */
      int regi1 = regi_new();
      int regi2 = regi_new();
      int offset = symbolp->offset;

      generate("%d: ldc %d, %d", ip++, regi1,
	       size_of_type(atype_to_type(msymbolp->type), msymbolp->stname));
      generate("%d: mul %d, %d, %d", ip++, regi1, $<rval>5.regi, regi1);
      generate("%d: ldc %d, %d", ip++, regi2, msymbolp->offset);
      generate("%d: add %d, %d, %d", ip++, regi1, regi1, regi2);
      generate("%d: add %d, %d, %d", ip++, regi1, $<rval>1.regi, regi1);
      generate("%d: ld %d, 0(%d)", ip++, regi2, regi1);

      regi_free($<rval>1.regi);
      regi_free($<rval>5.regi);
      $<rval>$.regi = regi2;
      $<rval>$.pregi = regi1;
      $<rval>$.rlex = var;
      $<rval>$.lastip1 = ip - 1;
      $<rval>$.lastip2 = NO_IP;
      $<rval>$.lastexp = MEMBER_ARROW_EXP;
      member_name = member;
    }
  }
  | factor
  {
    $<rval>$.regi = $<rval>1.regi;
    $<rval>$.pregi = $<rval>1.pregi;
    $<rval>$.rlex = $<rval>1.rlex;
    $<rval>$.lastip1 = $<rval>1.lastip1;
    $<rval>$.lastip2 = $<rval>1.lastip2;
    $<rval>$.lastexp = $<rval>1.lastexp;
  }      
;

memop
  : PERIOD
  {
    $<oval>$.operator = PERIOD;
  }
  | ARROW
  {
    $<oval>$.operator = ARROW;
  }
;

factor
  : LPAR expression RPAR
  {
    $<rval>$.regi = $<rval>2.regi;
    $<rval>$.pregi = $<rval>2.pregi;
    $<rval>$.rlex = $<rval>2.rlex;
    $<rval>$.lastip1 = $<rval>2.lastip1;
    $<rval>$.lastip2 = $<rval>2.lastip2;
    $<rval>$.lastexp = $<rval>2.lastexp;
  }  
  | var
  {
    char *var = $<lval>1.lex;
    struct symbol *symbolp = lookup_symbol(var);

    /* error 50: undefined variable */
    if (symbolp == NULL)
      error("50: undefined variable \'%s\'", var);

    /* error 51: not a variable */
    if (symbolp -> kind == FUNCTION)
      error("51: not a variable \'%s\'", var);

    /* code generate */
    if (symbolp->kind == GLOBAL) {
      int regi = regi_new();
      int offset = symbolp->offset;

      if (is_array(symbolp->type))
	generate("%d: lda %d, -%d(gp)", ip++, regi, offset);
      else
	generate("%d: ld %d, -%d(gp)", ip++, regi, offset);

      $<rval>$.regi = regi;
      $<rval>$.pregi = NO_REGI;
      $<rval>$.rlex = var;
      $<rval>$.lastip1 = ip - 1;
      $<rval>$.lastip2 = NO_IP;
      $<rval>$.lastexp = FACTOR_VAR_EXP;
     
    } else {
      int regi = regi_new();
      int offset = symbolp->offset;

      if (is_array(symbolp->type))
	generate("%d: lda %d, -%d(gp)", ip++, regi, offset + 8);
      else
	generate("%d: ld %d, -%d(fp)", ip++, regi, offset + 8);

      $<rval>$.regi = regi;
      $<rval>$.pregi = NO_REGI;
      $<rval>$.rlex = var;
      $<rval>$.lastip1 = ip - 1;
      $<rval>$.lastip2 = NO_IP;
      $<rval>$.lastexp = FACTOR_VAR_EXP;
    }
  }
  | var LBRACKET expression RBRACKET
  {
    char *var = $<lval>1.lex;
    struct symbol *symbolp = lookup_symbol(var);

    /* error 52: undefined array */
    if (symbolp == NULL)
      error("52: undefined array \'%s\'", var);
   
    /* error 53: not an array */
    if (symbolp->kind == FUNCTION)
      error("53: not an array \'%s\'", var);

    /* code generate */
    if (symbolp->kind == ARGUMENT) {
      int regi1 = regi_new();
      int regi2 = regi_new();
      int regi3 = regi_new();
      int offset = symbolp->offset;
      int tsize = size_of_type(ptype_to_type(symbolp->type), symbolp->stname);

      generate("%d: ldc %d, %d", ip++, regi1, tsize);
      generate("%d: mul %d, %d, %d", ip++, $<rval>3.regi, regi1,
	        $<rval>3.regi);
      generate("%d: ld %d, -%d(fp)", ip++, regi1, offset + 8);
      generate("%d: add %d, %d, %d", ip++, regi1, regi1, $<rval>3.regi);
      generate("%d: ld %d, -%d(%d)", ip++, regi2, offset, regi1);
      generate("%d: lda %d, -%d(%d)", ip++, regi3, offset, regi1);

      regi_free(regi1);
      regi_free($<rval>3.regi);
      regi_free($<rval>3.pregi);
      $<rval>$.regi = regi2;
      $<rval>$.pregi = regi3;
      $<rval>$.rlex = var;
      $<rval>$.lastip1 = ip - 2;
      $<rval>$.lastip2 = ip - 1;
      $<rval>$.lastexp = FACTOR_ARRAY_EXP;

    } else {
      int regi1 = regi_new();
      int regi2 = regi_new();
      int regi3 = regi_new();
      int offset = symbolp->offset;
      int tsize = size_of_type(atype_to_type(symbolp->type), symbolp->stname);

      generate("%d: ldc %d, %d", ip++, regi1, tsize);
      generate("%d: mul %d, %d, %d", ip++, $<rval>3.regi, regi1,
                $<rval>3.regi);
      if (symbolp->kind == GLOBAL) {
	generate("%d: add %d, gp, %d", ip++, regi1, $<rval>3.regi);
	generate("%d: ld %d, -%d(%d)", ip++, regi2, offset, regi1);
	generate("%d: lda %d, -%d(%d)", ip++, regi3, offset, regi1);
      } else {
	generate("%d: add %d, fp, %d", ip++, regi1, $<rval>3.regi);
	generate("%d: ld %d, -%d(%d)", ip++, regi2, offset + 8, regi1);
	generate("%d: lda %d, -%d(%d)", ip++, regi3, offset + 8, regi1);
      }
      regi_free(regi1);
      regi_free($<rval>3.regi);
      regi_free($<rval>3.pregi);
      $<rval>$.regi = regi2;
      $<rval>$.pregi = regi3;
      $<rval>$.rlex = var;
      $<rval>$.lastip1 = ip - 2;
      $<rval>$.lastip2 = ip - 1;
      $<rval>$.lastexp = FACTOR_ARRAY_EXP;
    }
  }
  | num
  {
    int regi = regi_new();
    int num = atoi($<lval>1.lex);

    generate("%d: ldc %d, %d", ip++, regi, num);

    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
  }  
  | PLUS num
  {
    int regi = regi_new();
    int num = atoi($<lval>2.lex);

    generate("%d: ldc %d, %d", ip++, regi, num);
      
    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
  }  
  | MINUS num
  {
    int regi = regi_new();
    int num = atoi($<lval>2.lex);

    generate("%d: ldc %d, %d", ip++, regi, -num);

    $<rval>$.regi = regi;
    $<rval>$.pregi = NO_REGI;
    $<rval>$.rlex = NULL;
    $<rval>$.lastip1 = NO_IP;
    $<rval>$.lastip2 = NO_IP;
    $<rval>$.lastexp = NO_EXP;
  }  
  | STRINGCONST
  {
    int regi1 = regi_new();
    int regi2 = regi_new();
    int index;
    int j;
    int offset_count = 0;
    unsigned int str1 = 0;
    unsigned int str2 = 0;
    unsigned int length = strlen(lex) - 2;	// - 2("")

    if (length == 0) {
      str1 = 0;

      generate("%d: ldc %d, %d", ip++, regi1, str1);
      generate("%d: ldc %d, %d", ip++, regi2, *current_opoffset);
      generate("%d: st %d, %d(%d)", ip++, regi1, 0, regi2);

      regi_free(regi1);
      offset_count++;
      $<rval>$.regi = regi2;
    } else {
      lex++;

      for (index = 0; index < length;) {
	str1 = 0;

	for (j = 0; j <= 3; j++) {
	  index++;

	  if (j == 0) {
	    str1 =  str1 | *lex;
	  } else if (j == 1) {
	    str2 = *lex;
	    str2 = str2 << 8;
	    str1 = str1 | str2;
	  } else if (j == 2) {
	    str2 = *lex;
	    str2 = str2 << 16;
	    str1 = str1 | str2;
	  } else if (j == 3) {
	    str2 = *lex;
	    str2 = str2 << 24;
	    str1 = str1 | str2;

	    if (index != length) {
	      generate("%d: ldc %d, %d", ip++, regi1, str1);
	      generate("%d: ldc %d, %d", ip++, regi2, *current_opoffset);
	      generate("%d: st %d, %d(%d)", ip++, regi1, offset_count * 4,
		  regi2);

	      regi_free(regi1);
	      offset_count++;
	      $<rval>$.regi = regi2;
	    }
	  }

	  if (index == length) {
	    str2 = 0;

	    generate("%d: ldc %d, %d", ip++, regi1, str1);
	    generate("%d: ldc %d, %d", ip++, regi2, *current_opoffset);
	    generate("%d: st %d, %d(%d)", ip++, regi1, offset_count * 4,
		      regi2);

	    offset_count++;

	    generate("%d: ldc %d, %d", ip++, regi1, str2);
	    generate("%d: ldc %d, %d", ip++, regi2, *current_opoffset);
	    generate("%d: st %d, %d(%d)", ip++, regi1, offset_count * 4,
		      regi2);

	    regi_free(regi1);
	    offset_count++;
	    $<rval>$.regi = regi2;
	    break;
	  }

	  lex++;
	}
      }
    }
    *current_opoffset = *current_opoffset + (offset_count * 4);
  }
;

selection_stmt
  : IF LPAR expression
  {
    is_break = 0;
    generate("%d: jle %d, %%d(pc)", ip++, $<rval>3.regi);
    regi_free($<rval>3.regi);
    regi_free($<rval>3.pregi);
  }
    if_rpar statement
  {
    backpatch($<pval>5.ip - 1, ip - $<pval>5.ip +1 );
    if(is_break == 1)

      backpatch(break_ip, ip);

  }
    else_stmt
  | SWITCH LPAR expression RPAR
  {
    case_count = 0;
    is_default = 0;
    is_break = 0;

    switch_exp = $<rval>3.regi;
  } 
    statement
  {
    int i;

    if (is_default == 0)
      backpatch(switch_ip - 1, ip - switch_ip);

    for (i = 2; i <= case_count; i++)
      backpatch(case_break[i] - 1, ip);
    if(is_break == 1)
      backpatch(break_ip, ip);
  }
;

else_stmt
  : if_else
  {
    is_break = 0;
    generate("%d: ldc pc, %%d", ip++);
  }
    statement
  {
    backpatch($<pval>1.ip, ip);
    if(is_break == 1)
      backpatch(break_ip, ip);
  }
  | empty{

  }
;

if_rpar
  : RPAR
  {
    $<pval>$.ip = ip;
  }
;

if_else
  : ELSE
  {
    $<pval>$.ip = ip;
  }
;

case_stmt
  : CASE num COLON
  {
    int n;
    int regi1 = regi_new();
    int regi2 = regi_new();

    case_count++;
    n = atoi($<lval>2.lex);

    if (case_count >= 2) {
      backpatch(switch_ip - 1, ip - switch_ip);
      case_break[case_count] = ip;
    }

    generate("%d: ldc %d, %d", ip++, regi1, n);
    generate("%d: eq %d, %d, %d", ip++, regi2, switch_exp, regi1);
    generate("%d: jle %d, %%d(pc)", ip++, regi2);

    switch_ip = ip;
    regi_free(regi1);
    regi_free(regi2);
  }
    statement
  |
  {
    case_count++;
    
    if (case_count != 1) {
      case_break[case_count] = ip;
    }
  }
    DEFAULT COLON
  {
    is_default = 1;

    if (case_count > 0)
      backpatch(switch_ip - 1, ip - switch_ip);
  }
    statement
;

iteration_stmt
  : WHILE while_lpar expression
  {
    generate("%d: jle %d, %%d(pc)", ip++, $<rval>3.regi);
    regi_free($<rval>3.regi);
    regi_free($<rval>3.pregi);
  }
    while_rpar statement
  {
    generate("%d: ldc pc, %d", ip++, $<pval>2.ip);
    backpatch($<pval>5.ip - 1, ip - $<pval>5.ip);
  }
  | FOR LPAR expression_stmt expression_stmt
  {
    for_count++;

    generate("%d: jne %d, %%d(pc)", ip++, $<rval>4.regi);   //forë¬??˜í–‰ ë°±íŒ¨ì¹?
    generate("%d: ldc pc, %%d", ip++);   //forë¬??ˆì¶œ ë°±íŒ¨ì¹?

    for_out[for_count] = ip;
    for_ip2 = $<rval>3.rip;
  }
    for_stmt
  {
    generate("%d: ldc pc, %d", ip++, $<rval>4.rip + 2);
    backpatch(for_out[for_count] - 1, ip);
    for_count--;
  }
;

for_stmt
  : expression RPAR
  {
    generate("%d: ldc pc, %d", ip++, for_ip2);
    backpatch(for_out[for_count] - 2, ip - for_out[for_count] + 1);

    regi_free($<rval>1.regi);
    regi_free($<rval>1.pregi);
  }
    statement
  | RPAR
  {
    backpatch(for_out[for_count] - 2, ip - for_out[for_count] + 1);
  }
    statement
;

while_lpar
  : LPAR
  {
    $<pval>$.ip = ip;
  }
;

while_rpar
  : RPAR
  {
    $<pval>$.ip = ip;
  }
;

clear_stmt
  : CLEAR
  {
    generate("%d: clr", ip++);
  }
;

sleep_stmt
  : SLEEP LPAR num RPAR
  {
    int n = atoi($<lval>3.lex);
    generate("%d: slp %d", ip++, n);
  }
;

funcall_stmt
  : unary_expression_assign call
  {
    if ($<rval>1.pregi == NO_REGI) {
      char *var = $<rval>1.rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int offset = symbolp->offset;

      if (symbolp->kind == GLOBAL) {
	generate("%d: st %d, -%d(gp)", ip++, $<rval>2.regi, offset);
      } else {
	generate("%d: st %d, -%d(fp)", ip++, $<rval>2.regi, offset + 8);
      }

    } else {
      generate("%d: st %d, 0(%d)", ip++, $<rval>2.regi, $<rval>1.pregi);
      regi_free($<rval>1.pregi);
    }
    regi_free($<rval>2.regi);
  }
  | call
  {
    regi_free($<rval>1.regi);
  }
;

call
: var
  {
    char *var = $<lval>1.lex;
    struct symbol *symbolp;

    symbolp = lookup_symbol(var);

    /* error 60: undefined function */
    if (symbolp == NULL)
      error("60: undefined function \'%s\'", var);

    /* error 61: not a function */
    if (symbolp->kind != FUNCTION)
      error("61: not a function \'%s\'", var);

    generate("%d: lda sp, -8(sp)", ip++);
    aarg_count = 0;
  }
    LPAR args RPAR
  {
    int regi = regi_new();
    char *var = $<lval>1.lex;
    struct symbol *symbolp;

    symbolp = lookup_symbol(var);

    /* error 62: too few arguments in function */
    if (symbolp->size > aarg_count)
      error("62: too few arguments in function \'%s\'", var);
      
    /* error 63: too many arguments in function */
    else if (symbolp->size < aarg_count)
      error("63: too many arguments in function \'%s\'", var);

    generate("%d: st fp, -%d(fp)", ip++, *current_offset + 8);
    generate("%d: lda fp, -%d(fp)", ip++, *current_offset + 8);
    generate("%d: lda %d, 2(pc)", ip++, regi);
    generate("%d: st %d, -4(fp)", ip++, regi);
    // regi_free(regi);
    generate("%d: ldc pc, %d", ip++, symbolp->offset);
    // regi = regi_new();
    generate("%d: lda %d, 0(%d)", ip++, regi, REGI_RETURN);
    $<rval>$.regi = regi;
    // regi_free(regi);
  }
;

args
  : arg_list
  | empty
;

arg_list
  : arg_list COMMA expression
  {
    generate("%d: push %d", ip++, $<rval>3.regi);
    aarg_count++;
    regi_free($<rval>3.regi);
    regi_free($<rval>3.pregi);
  }
  | expression
  {
    generate("%d: push %d", ip++, $<rval>1.regi);
    aarg_count++;
    regi_free($<rval>1.regi);
    regi_free($<rval>1.pregi);
  }
;

return_stmt
  : RETURN SEMICOLON
  {
    generate("%d: ldc %d, 0", ip++, REGI_RETURN);
    generate("%d: lda sp, 0(fp)", ip++);
    generate("%d: ld fp, 0(fp)", ip++);
    generate("%d: ld pc, -4(sp)", ip++);
    have_return = 1;
  }
  | RETURN expression SEMICOLON
  {
    generate("%d: lda %d, 0(%d)", ip++, REGI_RETURN, $<rval>2.regi);
    generate("%d: lda sp, 0(fp)", ip++);
    generate("%d: ld fp, 0(fp)", ip++);
    generate("%d: ld pc, -4(sp)", ip++);
    have_return = 1;
    regi_free($<rval>2.regi);
    regi_free($<rval>2.pregi);
  }
  | BREAK SEMICOLON
  {
    is_break = 1;
    break_ip = ip;
    generate("%d: ldc pc, %%d", ip++);
  }
;

input_stmt
  : INPUT unary_expression
  {
    if ($<rval>2.lastexp == FACTOR_VAR_EXP ||
	$<rval>2.lastexp == FACTOR_ARRAY_EXP ||
	$<rval>2.lastexp == UNARY_MULTIPLY_EXP ||
	$<rval>2.lastexp == MEMBER_PERIOD_EXP ||
	$<rval>2.lastexp == MEMBER_PERIOD_EXP2 ||
	$<rval>2.lastexp == MEMBER_ARROW_EXP) {
      backpatch_delete($<rval>2.lastip1);
      regi_free($<rval>2.regi);
    }
  }
    SEMICOLON
  {
    int regi = regi_new();

    generate("%d: in %d", ip++, regi);

    if ($<rval>2.pregi == NO_REGI) {
      char *var = $<rval>2.rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int offset = symbolp->offset;
      
      if (symbolp->kind == GLOBAL) {
	generate("%d: st %d, -%d(gp)", ip++, regi, offset);
      } else {
	generate("%d: st %d, -%d(fp)", ip++, regi, offset + 8);
      }

    } else {
      generate("%d: st %d, 0(%d)", ip++, regi, $<rval>2.pregi);
      regi_free($<rval>2.pregi);
    }
    regi_free(regi);
  }
;

output_stmt
  : OUTPUT expression SEMICOLON
  {
    generate("%d: out %d", ip++, $<rval>2.regi);
    regi_free($<rval>2.regi);
    regi_free($<rval>2.pregi);
  }
  | OUTPUTS expression SEMICOLON
  {
    generate("%d: outs %d", ip++, $<rval>2.regi);
    regi_free($<rval>2.regi);
    regi_free($<rval>2.pregi);
  }
  | OUTPUTC expression SEMICOLON
  {
    generate("%d: outc %d", ip++, $<rval>2.regi);
    regi_free($<rval>2.regi);
    regi_free($<rval>2.pregi);
  }
;

empty
  :
;

%%

/* ====================================================================== */

void regi_init(void)
{
  int i;

  for (i = 0; i < NO_TMP_REGIS; i++)
    regi_used[i] = 0;
}

/* ====================================================================== */

void regi_free(int i)
{
  if (i == NO_REGI)
    return;
  regi_used[i] = 0;
}

/* ====================================================================== */

int regi_new(void)
{
  int i;

  for (i = 0; i < NO_TMP_REGIS; i++) {
    if (regi_used[i] == 0) {
      regi_used[i] = 1;
      return i;
    }
  }
  error("error 50: all registers are used!");
}

/* ====================================================================== */

int generate(char *fmt, int i1, int i2, int i3, int i4)
{
  char tmp[MAX_LINE];
  char *p;

  sprintf(tmp, fmt, i1, i2, i3, i4);

  for (p = tmp; *p != '\0'; p++) {
    if ((*p == '-') && (*(p + 1) == '-')) {
      *p = ' ';
      *(p + 1) = '+';
      break;
    }
  }

  p = (char *) malloc(strlen(tmp) + 1);
  strcpy(p, tmp);
  code[ip - 1] = p;
}

/* ====================================================================== */

void backpatch(unsigned int ip1, unsigned int ip2)
{
  char tmp[MAX_LINE];
  char *p;

  sprintf(tmp, code[ip1], ip2);
  p = (char *) malloc(strlen(tmp) + 1);
  strcpy(p, tmp);
  free(code[ip1]);
  code[ip1] = p;
}

/* ====================================================================== */

void backpatch_delete(unsigned int tip)
{
  char tmp[MAX_LINE];
  char *p;

  if (tip == NO_IP) return;

  free(code[tip]);
  ip = ip - 1;
  for (; tip < ip; tip++) {
    sprintf(tmp, "%u", tip);
    for (p = code[tip + 1]; *p != ':'; p++);
    strcat(tmp, p);
    p = (char *) malloc(strlen(tmp) + 1);
    strcpy(p, tmp);
    free(code[tip + 1]);
    code[tip] = p;
  }
}

/* ====================================================================== */

void backpatch_funcalls(void)
{
  int i, j;
  struct symbol *symbolp;
  
  for (i = 0; i < HASH_SIZE; i++)
    for (symbolp = global_table->hash[i]; symbolp != NULL;
	 symbolp = symbolp->next)
      for (j = 0; j < symbolp->ipc; j++)
	backpatch(symbolp->ip[j], symbolp->offset);
}

/* ====================================================================== */

void print_code(void)
{
  int i, j, k = 1;
  char file[MAX_LINE];
  FILE *fp;
  
  i = strlen(prog_name);
  if ((i > 2) && (prog_name[i - 2] == '.') && (prog_name[i - 1] == 'c'))
    prog_name[i - 2] = '\0';
  else if ((i > 2) && (prog_name[i - 2] == '.') && (prog_name[i - 1] == 'C'))
    prog_name[i - 2] = '\0';

  sprintf(file, "%s.tm", prog_name);
  if ((fp = fopen(file, "w")) == NULL) {
    fprintf(stderr, "%s: %s\n", file, strerror(errno));
    exit(1);
  }

  fprintf(fp, "// ====================\n");
  fprintf(fp, "// c startup\n");
  fprintf(fp, "// ====================\n");
  for (i = 0; i < fun_count; i++) {
    for (j = section_line[i]; j < section_line[k]; j++)
      fprintf(fp, "%s\n", code[j]);
    fprintf(fp, "// ====================\n");
    fprintf(fp, "// %s()\n", fun_name[k]);
    fprintf(fp, "// ====================\n");
    k++;
  }
  for (i = section_line[fun_count]; i < ip; i++)
    fprintf(fp, "%s\n", code[i]);
  fprintf(fp, "// ====================\n");
  fclose(fp);  
}

/* ====================================================================== */

int yyerror(char *message)
{
  if (option_symbol == 1) {
    print_table(current_table);
    if (current_table != global_table)
      print_table(global_table);
  }

  fprintf(stderr, "%s: ", source_file_name);
  fprintf(stderr, "line %d: ", source_line_no);
  if (yytext[yyleng - 1] == EOF)
    fprintf(stderr, "%s at %s\n", message,
            "end of file(missing terminating \" character)");
  else 
    fprintf(stderr, "%s at \'%s\'\n", message, yytext);
  fflush(stderr);
}

/* ====================================================================== */

int error(char *fmt, char *s1, char *s2, char *s3, char *s4)
{
  if (option_symbol == 1) {
    print_table(current_table);
    if (current_table != global_table)
      print_table(global_table);
  }

  fprintf(stderr, "%s: ", source_file_name);
  fprintf(stderr, "line %d: error ", source_line_no);
  fprintf(stderr, fmt, s1, s2, s3, s4);
  fprintf(stderr, "\n");
  fflush(stderr);
  exit(-1);
}

/* ====================================================================== */

int main(int argc, char *argv[])
{
  char *sp;

  if (argc == 2) {
    option_symbol = 0;
    prog_name = argv[1];
  } else if (argc == 3) {
    if (strcmp(argv[1], "-s") != 0) {
      fprintf(stderr, "usage: cm [-s] file\n");
      exit(1);
    }
    option_symbol = 1;
    prog_name = argv[2];
  } else {
    fprintf(stderr, "usage: cm [-s] file\n");
    exit(1);
  }
  yyin = fopen(prog_name, "r");
  if (yyin == NULL) {
    fprintf(stderr, "%s: %s\n", prog_name, strerror(errno));
    exit(1);
  }
  
  /* remove directory name in source file name */
  for (sp = source_file_name = prog_name; *sp != '\0'; sp++) {
    if (*sp == '/')
      source_file_name = sp + 1;
  }

  yyparse();

  return 0;
}

/* ====================================================================== */
