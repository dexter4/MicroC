/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "parser.y" /* yacc.c:339  */


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


#line 201 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    CHAR = 260,
    STRUCT = 261,
    STATIC = 262,
    EXTERN = 263,
    CONST = 264,
    IF = 265,
    ELSE = 266,
    SWITCH = 267,
    CASE = 268,
    DEFAULT = 269,
    WHILE = 270,
    FOR = 271,
    RETURN = 272,
    BREAK = 273,
    CLEAR = 274,
    SLEEP = 275,
    INPUT = 276,
    OUTPUTS = 277,
    OUTPUTC = 278,
    OUTPUT = 279,
    PLUS = 280,
    MINUS = 281,
    MULTIPLY = 282,
    DIVIDE = 283,
    PERCENT = 284,
    LT = 285,
    LE = 286,
    GT = 287,
    GE = 288,
    EQ = 289,
    NE = 290,
    DOUBLEOR = 291,
    DOUBLEAND = 292,
    EXCLAMATION = 293,
    ASSIGN = 294,
    PERIOD = 295,
    ARROW = 296,
    AMPERSAND = 297,
    COMMA = 298,
    SEMICOLON = 299,
    COLON = 300,
    LPAR = 301,
    RPAR = 302,
    LBRACE = 303,
    RBRACE = 304,
    LBRACKET = 305,
    RBRACKET = 306,
    ID = 307,
    OCTNUM = 308,
    HEXNUM = 309,
    NUM = 310,
    CHARCONST = 311,
    STRINGCONST = 312,
    UNDEFINED = 313,
    LIBCALL = 314,
    LIBFRD = 315,
    LIBFWT = 316
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 142 "parser.y" /* yacc.c:355  */

  l_type lval;
  t_type tval;
  o_type oval;
  r_type rval;
  p_type pval;

#line 311 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 326 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   467

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   182,   182,   182,   228,   229,   233,   234,   238,   259,
     281,   285,   292,   298,   304,   313,   317,   324,   329,   334,
     339,   348,   347,   363,   370,   371,   375,   397,   424,   431,
     435,   443,   451,   471,   489,   513,   470,   539,   540,   544,
     548,   555,   582,   608,   609,   613,   614,   618,   619,   620,
     621,   622,   623,   624,   625,   626,   627,   628,   632,   636,
     642,   649,   700,   722,   732,   742,   755,   777,   799,   821,
     852,   879,   891,   895,   902,   928,   940,   944,   948,   952,
     956,   960,   967,   985,   997,  1001,  1008,  1030,  1042,  1046,
    1050,  1057,  1137,  1149,  1153,  1157,  1164,  1263,  1377,  1389,
    1393,  1400,  1409,  1456,  1525,  1539,  1553,  1567,  1655,  1662,
    1654,  1671,  1670,  1694,  1693,  1704,  1710,  1717,  1725,  1724,
    1748,  1756,  1748,  1767,  1766,  1778,  1777,  1797,  1796,  1806,
    1805,  1813,  1820,  1827,  1834,  1842,  1861,  1869,  1868,  1916,
    1917,  1921,  1928,  1938,  1946,  1956,  1966,  1965,  2003,  2009,
    2015,  2023
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "CHAR", "STRUCT",
  "STATIC", "EXTERN", "CONST", "IF", "ELSE", "SWITCH", "CASE", "DEFAULT",
  "WHILE", "FOR", "RETURN", "BREAK", "CLEAR", "SLEEP", "INPUT", "OUTPUTS",
  "OUTPUTC", "OUTPUT", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "PERCENT",
  "LT", "LE", "GT", "GE", "EQ", "NE", "DOUBLEOR", "DOUBLEAND",
  "EXCLAMATION", "ASSIGN", "PERIOD", "ARROW", "AMPERSAND", "COMMA",
  "SEMICOLON", "COLON", "LPAR", "RPAR", "LBRACE", "RBRACE", "LBRACKET",
  "RBRACKET", "ID", "OCTNUM", "HEXNUM", "NUM", "CHARCONST", "STRINGCONST",
  "UNDEFINED", "LIBCALL", "LIBFRD", "LIBFWT", "$accept", "program", "$@1",
  "var_declaration_list", "fun_declaration_list", "var_declaration",
  "type_specifier", "optional_type", "type", "struct_type", "$@2",
  "member_declaration_list", "member_declaration", "var", "num",
  "fun_declaration", "$@3", "$@4", "$@5", "params", "param_list", "param",
  "local_declarations", "statement_list", "statement", "compound_stmt",
  "expression_stmt", "expression", "libfrd_exp", "libfwt_exp",
  "libcall_exp", "unary_expression_assign", "logical_expression", "logop",
  "relational_expression", "relop", "additive_expression", "addop", "term",
  "mulop", "unary_expression", "unaop", "member_expression", "memop",
  "factor", "selection_stmt", "$@6", "$@7", "$@8", "else_stmt", "$@9",
  "if_rpar", "if_else", "case_stmt", "$@10", "$@11", "$@12",
  "iteration_stmt", "$@13", "$@14", "for_stmt", "$@15", "$@16",
  "while_lpar", "while_rpar", "clear_stmt", "sleep_stmt", "funcall_stmt",
  "call", "$@17", "args", "arg_list", "return_stmt", "input_stmt", "$@18",
  "output_stmt", "empty", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

#define YYPACT_NINF -127

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-127)))

#define YYTABLE_NINF -138

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -127,     8,  -127,  -127,    99,  -127,  -127,  -127,  -127,   -41,
    -127,  -127,    99,  -127,   -31,    45,     3,  -127,  -127,  -127,
      -6,   -41,  -127,  -127,   -40,    16,  -127,    -4,  -127,  -127,
      18,   -11,  -127,    99,  -127,  -127,  -127,  -127,     1,   179,
     -41,    12,  -127,    14,    19,   -41,    21,    26,  -127,   -22,
    -127,  -127,  -127,    25,  -127,    99,  -127,    18,    29,    44,
    -127,    57,  -127,  -127,    33,    99,  -127,  -127,  -127,   -31,
    -127,   -40,   210,  -127,    50,    63,    18,    72,    73,    89,
      76,  -127,    75,   410,   386,   386,   386,    18,    18,  -127,
    -127,  -127,  -127,   386,  -127,  -127,  -127,    77,    78,    79,
     -21,  -127,  -127,  -127,  -127,    82,  -127,  -127,  -127,   386,
     -13,  -127,   130,    10,    90,    30,   -14,  -127,  -127,  -127,
     114,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,   386,
     386,    85,  -127,   386,   338,  -127,    84,    94,   386,  -127,
      18,  -127,    96,   103,   108,  -127,  -127,   112,   262,   386,
     386,   386,   386,   120,  -127,  -127,  -127,  -127,  -127,   410,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,   410,   410,
    -127,  -127,  -127,   410,  -127,   -14,  -127,  -127,   -41,   122,
    -127,   121,  -127,  -127,   338,  -127,   123,   127,  -127,  -127,
    -127,  -127,  -127,   129,   133,   134,   128,   386,  -127,  -127,
       7,    10,  -127,   140,  -127,   144,  -127,   314,   146,  -127,
    -127,  -127,   386,   386,   386,  -127,  -127,   148,   137,  -127,
     386,   314,  -127,   314,   314,  -127,  -127,   314,   362,   154,
     156,   157,  -127,   386,   150,  -127,  -127,  -127,  -127,  -127,
     155,  -127,   386,   386,   386,  -127,  -127,   195,   314,  -127,
     160,   161,   162,  -127,  -127,  -127,  -127,  -127,   314,  -127,
    -127,  -127,   314,  -127,  -127
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,   151,     1,     0,     5,    19,    17,    18,     0,
      15,    16,     3,     4,     0,     0,    14,    20,     7,    28,
      23,     0,     6,    10,    33,    12,    13,     0,    33,     8,
       0,     0,    11,     0,    30,    31,    29,    32,     0,     0,
       0,     0,    25,     0,    19,     0,     0,    37,    40,     0,
      22,    24,     9,    41,    34,     0,    26,     0,     0,     0,
      39,     0,    42,   151,     0,    35,    44,    27,    43,     0,
     151,     0,   120,    46,     0,     0,     0,     0,     0,     0,
       0,   133,     0,     0,     0,     0,     0,     0,     0,    95,
      93,    94,    60,     0,   151,    36,   107,     0,     0,     0,
     102,   104,    45,    47,    48,     0,    64,    65,    63,     0,
      62,    71,    75,    83,    87,     0,    92,    98,    49,    50,
       0,    51,    52,    53,    54,   136,    55,    56,    57,     0,
       0,     0,   131,     0,     0,   143,   102,     0,     0,   145,
       0,   146,     0,     0,     0,   105,   106,     0,   120,     0,
       0,     0,     0,     0,    59,    61,   135,    72,    73,     0,
      84,    85,    76,    77,    78,    79,    80,    81,     0,     0,
      88,    89,    90,     0,    69,    91,    99,   100,     0,     0,
     108,     0,   118,   123,     0,   144,     0,     0,   149,   150,
     148,   101,    58,     0,     0,     0,     0,   151,    70,    87,
      74,    82,    86,    96,   121,     0,   111,   120,     0,   125,
     134,   147,     0,     0,     0,   103,   142,     0,   139,   140,
       0,   120,   116,   120,   120,   119,   132,   120,     0,     0,
       0,     0,   138,     0,     0,   122,   109,   112,   124,   129,
       0,   126,     0,     0,     0,   141,    97,   151,   120,   127,
       0,     0,     0,   117,   110,   113,   115,   130,   120,    68,
      66,    67,   120,   128,   114
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -127,  -127,   145,     2,  -127,   196,  -127,
    -127,  -127,   172,    -9,   -23,   204,  -127,  -127,  -127,  -127,
    -127,   164,  -127,   147,  -126,  -127,  -125,   -39,  -127,  -127,
    -127,   -70,  -127,  -127,    58,  -127,    53,  -127,    55,  -127,
     -80,  -127,   125,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,   135,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     4,    12,    13,    40,    15,    16,    17,
      27,    41,    42,   136,   101,    18,    31,    59,    70,    46,
      47,    48,    65,    72,   102,   103,   104,   105,   106,   107,
     108,   138,   110,   159,   111,   168,   112,   169,   113,   173,
     114,   115,   116,   178,   117,   118,   205,   247,   224,   254,
     262,   223,   255,   119,   207,   120,   221,   121,   208,   228,
     241,   258,   248,   133,   227,   122,   123,   124,   125,   153,
     217,   218,   126,   127,   187,   128,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,     5,   109,   141,    29,    24,    14,    38,     3,   184,
      30,    19,    28,    23,    21,     6,     7,     8,     9,    10,
      11,    19,    56,   157,   158,  -137,   176,   177,    57,   152,
      26,    49,   160,   161,    61,    39,    53,   170,   171,   172,
     137,    45,   -21,    32,    33,   142,   143,   144,     6,     7,
       8,     9,    43,   131,   147,    87,    88,    45,    52,   209,
      71,    50,    66,   100,   145,   146,   -38,    69,    54,    55,
     155,    34,    35,    36,    37,    58,    93,    67,   109,   199,
      62,   225,    19,    34,    35,    36,    37,    96,   199,   199,
     180,   181,    63,   202,   183,   235,   129,   236,   237,   155,
     100,   238,     6,     7,     8,     9,    10,    11,    64,   130,
     193,   194,   195,   196,    87,    88,    89,   186,   132,   134,
     139,   140,   257,   149,   150,   151,   154,    90,   179,   174,
     182,    91,   263,   135,   152,    93,   264,   109,   185,   100,
     188,    19,    34,    35,    36,    37,    96,   189,    97,    98,
      99,   109,   190,   109,   109,   160,   161,   109,   216,   191,
     162,   163,   164,   165,   166,   167,   197,   204,   206,   203,
     210,   211,   212,   229,   230,   231,   213,   214,   109,   215,
     233,   234,    44,     7,     8,     9,    10,    11,   109,   240,
     220,   222,   109,   226,   245,   232,   219,   242,   100,   243,
     244,   246,   249,   250,   251,   252,   253,   259,   260,   261,
      68,    25,   100,    51,   100,   100,    22,   198,   100,    60,
      74,   200,    75,    76,   201,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,   100,
     175,   148,     0,     0,   156,     0,   256,     0,    90,   100,
       0,     0,    91,   100,    92,     0,    93,     0,    94,    95,
       0,     0,    19,    34,    35,    36,    37,    96,     0,    97,
      98,    99,    74,     0,    75,    76,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,     0,    91,     0,    92,     0,    93,     0,
      94,   192,     0,     0,    19,    34,    35,    36,    37,    96,
       0,    97,    98,    99,    74,     0,    75,    76,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,     0,     0,    91,     0,    92,     0,
      93,     0,    94,    87,    88,    89,    19,    34,    35,    36,
      37,    96,     0,    97,    98,    99,    90,     0,     0,     0,
      91,     0,    92,     0,    93,     0,     0,    87,    88,    89,
      19,    34,    35,    36,    37,    96,     0,    97,    98,    99,
      90,     0,     0,     0,    91,     0,     0,     0,    93,   239,
       0,    87,    88,    89,    19,    34,    35,    36,    37,    96,
       0,    97,    98,    99,    90,     0,     0,     0,    91,     0,
       0,     0,    93,     0,     0,    87,    88,    89,    19,    34,
      35,    36,    37,    96,     0,    97,    98,    99,    90,     0,
       0,     0,    91,     0,     0,     0,    93,     0,     0,     0,
       0,     0,    19,    34,    35,    36,    37,    96
};

static const yytype_int16 yycheck[] =
{
       9,     2,    72,    83,    44,    14,     4,    30,     0,   134,
      50,    52,    21,    44,    12,     3,     4,     5,     6,     7,
       8,    52,    44,    36,    37,    46,    40,    41,    50,    50,
      27,    40,    25,    26,    57,    46,    45,    27,    28,    29,
      79,    39,    48,    27,    48,    84,    85,    86,     3,     4,
       5,     6,    51,    76,    93,    25,    26,    55,    44,   184,
      69,    49,    63,    72,    87,    88,    47,    65,    47,    43,
     109,    53,    54,    55,    56,    50,    46,    44,   148,   159,
      51,   207,    52,    53,    54,    55,    56,    57,   168,   169,
     129,   130,    48,   173,   133,   221,    46,   223,   224,   138,
     109,   227,     3,     4,     5,     6,     7,     8,    51,    46,
     149,   150,   151,   152,    25,    26,    27,   140,    46,    46,
      44,    46,   248,    46,    46,    46,    44,    38,    14,    39,
      45,    42,   258,    44,    50,    46,   262,   207,    44,   148,
      44,    52,    53,    54,    55,    56,    57,    44,    59,    60,
      61,   221,    44,   223,   224,    25,    26,   227,   197,    47,
      30,    31,    32,    33,    34,    35,    46,    45,    47,   178,
      47,    44,    43,   212,   213,   214,    43,    43,   248,    51,
      43,   220,     3,     4,     5,     6,     7,     8,   258,   228,
      50,    47,   262,    47,   233,    47,   197,    43,   207,    43,
      43,    51,    47,   242,   243,   244,    11,    47,    47,    47,
      65,    15,   221,    41,   223,   224,    12,   159,   227,    55,
      10,   168,    12,    13,   169,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,   248,
     115,    94,    -1,    -1,   109,    -1,   247,    -1,    38,   258,
      -1,    -1,    42,   262,    44,    -1,    46,    -1,    48,    49,
      -1,    -1,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    61,    10,    -1,    12,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    42,    -1,    44,    -1,    46,    -1,
      48,    49,    -1,    -1,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    10,    -1,    12,    13,    -1,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    44,    -1,
      46,    -1,    48,    25,    26,    27,    52,    53,    54,    55,
      56,    57,    -1,    59,    60,    61,    38,    -1,    -1,    -1,
      42,    -1,    44,    -1,    46,    -1,    -1,    25,    26,    27,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    61,
      38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,    47,
      -1,    25,    26,    27,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,    25,    26,    27,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    61,    38,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    52,    53,    54,    55,    56,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,    65,   138,     3,     4,     5,     6,
       7,     8,    66,    67,    68,    69,    70,    71,    77,    52,
      75,    68,    77,    44,    75,    70,    27,    72,    75,    44,
      50,    78,    27,    48,    53,    54,    55,    56,    76,    46,
      68,    73,    74,    51,     3,    68,    81,    82,    83,    75,
      49,    74,    44,    75,    47,    43,    44,    50,    50,    79,
      83,    76,    51,    48,    51,    84,   138,    44,    67,    68,
      80,    75,    85,   138,    10,    12,    13,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      38,    42,    44,    46,    48,    49,    57,    59,    60,    61,
      75,    76,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    96,    98,   100,   102,   103,   104,   106,   107,   115,
     117,   119,   127,   128,   129,   130,   134,   135,   137,    46,
      46,    76,    46,   125,    46,    44,    75,    89,    93,    44,
      46,   102,    89,    89,    89,    76,    76,    89,    85,    46,
      46,    46,    50,   131,    44,    89,   130,    36,    37,    95,
      25,    26,    30,    31,    32,    33,    34,    35,    97,    99,
      27,    28,    29,   101,    39,   104,    40,    41,   105,    14,
      89,    89,    45,    89,    88,    44,    76,   136,    44,    44,
      44,    47,    49,    89,    89,    89,    89,    46,    96,   102,
      98,   100,   102,    75,    45,   108,    47,   116,   120,    88,
      47,    44,    43,    43,    43,    51,    89,   132,   133,   138,
      50,   118,    47,   113,   110,    86,    47,   126,   121,    89,
      89,    89,    47,    43,    89,    86,    86,    86,    86,    47,
      89,   122,    43,    43,    43,    89,    51,   109,   124,    47,
      89,    89,    89,    11,   111,   114,   138,    86,   123,    47,
      47,    47,   112,    86,    86
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    64,    63,    65,    65,    66,    66,    67,    67,
      67,    68,    68,    68,    68,    69,    69,    70,    70,    70,
      70,    72,    71,    71,    73,    73,    74,    74,    75,    76,
      76,    76,    76,    78,    79,    80,    77,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    87,    88,
      88,    89,    89,    89,    89,    89,    90,    91,    92,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     101,   102,   102,   103,   103,   103,   104,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   108,   109,
     107,   110,   107,   112,   111,   111,   113,   114,   116,   115,
     117,   118,   115,   120,   119,   121,   119,   123,   122,   124,
     122,   125,   126,   127,   128,   129,   129,   131,   130,   132,
     132,   133,   133,   134,   134,   134,   136,   135,   137,   137,
     137,   138
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     2,     1,     2,     1,     3,     6,
       2,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     2,     1,     3,     6,     1,     1,
       1,     1,     1,     0,     0,     0,    12,     1,     1,     3,
       1,     2,     4,     2,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       1,     2,     1,     1,     1,     1,     8,     8,     8,     2,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     3,     6,     1,     1,
       1,     3,     1,     4,     1,     2,     2,     1,     0,     0,
       8,     0,     6,     0,     3,     1,     1,     1,     0,     5,
       0,     0,     5,     0,     6,     0,     6,     0,     4,     0,
       3,     1,     1,     1,     4,     2,     1,     0,     5,     1,
       1,     3,     1,     2,     3,     2,     0,     4,     3,     3,
       3,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 182 "parser.y" /* yacc.c:1646  */
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
#line 1684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 214 "parser.y" /* yacc.c:1646  */
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
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 239 "parser.y" /* yacc.c:1646  */
    {
    char *var = (yyvsp[-1].lval).lex;
    unsigned int size;
    int offset;

    /* error 00: wrong void variable */
    if ((yyvsp[-2].tval).type == VOID_TYPE)
      error("00: wrong void variable \'%s\'", var);

    /* error 01: redefined variable */
    if (find_symbol(current_table, var) != NULL)
      error("01: redefined variable \'%s\'", var);

    /* add symbol & set current offset. size_of_type() return byte size of
       input type */
    size = size_of_type((yyvsp[-2].tval).type, (yyvsp[-2].tval).stname);
    offset = align_offset(current_offset, size, (yyvsp[-2].tval).type);
    add_symbol(current_table, (yyvsp[-1].lval).lex, position, (yyvsp[-2].tval).optype,
               (yyvsp[-2].tval).type, (yyvsp[-2].tval).stname, size, offset);
  }
#line 1725 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 260 "parser.y" /* yacc.c:1646  */
    {
    char *var = (yyvsp[-4].lval).lex;
    unsigned int n;
    unsigned int size;
    int offset;

    /* error 02: wrong void array */
    if ((yyvsp[-5].tval).type == VOID_TYPE)
      error("02: wrong void array \'%s\'", var);

    /* error 03: redefined array */
    if (find_symbol(current_table, var) != NULL)
      error("03: redefined array \'%s\'", var);

    /* add array type symbol & set current offset */
    n = atoi((yyvsp[-2].lval).lex);
    size = n * size_of_type((yyvsp[-5].tval).type, (yyvsp[-5].tval).stname);
    offset = align_offset(current_offset, size, (yyvsp[-5].tval).type);
    add_symbol(current_table, (yyvsp[-4].lval).lex, position, (yyvsp[-5].tval).optype,
               type_to_atype((yyvsp[-5].tval).type), (yyvsp[-5].tval).stname, size, offset);
  }
#line 1751 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 286 "parser.y" /* yacc.c:1646  */
    { /* assign type & optype & structure name attribute values.
       type_to_ptype() return pointer type of input type */
    (yyval.tval).optype = (yyvsp[-2].tval).optype;
    (yyval.tval).type = type_to_ptype((yyvsp[-1].tval).type);
    (yyval.tval).stname = (yyvsp[-1].tval).stname;
  }
#line 1762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 293 "parser.y" /* yacc.c:1646  */
    {
    (yyval.tval).optype = (yyvsp[-1].tval).optype;
    (yyval.tval).type = (yyvsp[0].tval).type;
    (yyval.tval).stname = (yyvsp[0].tval).stname;
  }
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 299 "parser.y" /* yacc.c:1646  */
    {
    (yyval.tval).optype = NO_OPTYPE;
    (yyval.tval).type = type_to_ptype((yyvsp[-1].tval).type);
    (yyval.tval).stname = (yyvsp[-1].tval).stname;
  }
#line 1782 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 305 "parser.y" /* yacc.c:1646  */
    {
    (yyval.tval).optype = NO_OPTYPE;
    (yyval.tval).type = (yyvsp[0].tval).type;
    (yyval.tval).stname = (yyvsp[0].tval).stname;
  }
#line 1792 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 314 "parser.y" /* yacc.c:1646  */
    { /* assign optional type attribute value to lift */
    (yyval.tval).optype = STATIC_OPTYPE;
  }
#line 1800 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 318 "parser.y" /* yacc.c:1646  */
    {
    (yyval.tval).optype = EXTERN_OPTYPE;
  }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 325 "parser.y" /* yacc.c:1646  */
    { /* assign type & structure name attribute value to lift */
    (yyval.tval).type = INT_TYPE;
    (yyval.tval).stname = "n/a";
  }
#line 1817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 330 "parser.y" /* yacc.c:1646  */
    {
    (yyval.tval).type = CHAR_TYPE;
    (yyval.tval).stname = "n/a";
  }
#line 1826 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 335 "parser.y" /* yacc.c:1646  */
    {
    (yyval.tval).type = VOID_TYPE;
    (yyval.tval).stname = "n/a";
  }
#line 1835 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 340 "parser.y" /* yacc.c:1646  */
    {
    (yyval.tval).type = STRUCT_TYPE;
    (yyval.tval).stname = (yyvsp[0].tval).stname;
  }
#line 1844 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 348 "parser.y" /* yacc.c:1646  */
    { 
    /* add structure symbol in current structure table */
    current_stsymbol = add_symbol(current_sttable, (yyvsp[0].lval).lex, position, N_A,
                                  N_A, "n/a", 0, 0);
    current_mbtable = current_stsymbol->mbtable;
    current_mboffset = &mboffset;
    *current_mboffset = 0;
  }
#line 1857 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 357 "parser.y" /* yacc.c:1646  */
    { /* structure size = last current member offset */
    current_stsymbol->size = align4(*current_mboffset);

    /* assign lex attribute value for structure name to lift */
    (yyval.tval).stname = (yyvsp[-4].lval).lex;
  }
#line 1868 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 364 "parser.y" /* yacc.c:1646  */
    { /* assign lex attribute value for structure name to lift */
    (yyval.tval).stname = (yyvsp[0].lval).lex;
  }
#line 1876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 376 "parser.y" /* yacc.c:1646  */
    {
    char *var = (yyvsp[-1].lval).lex;
    struct symbol *symbolp;
    unsigned int size;
    int offset;

    /* error 10: wrong void member */
    if ((yyvsp[-2].tval).type == VOID_TYPE)
      error("10: wrong void member \'%s\'", var);

    /* error 11: redefined member */
    symbolp = find_symbol(current_mbtable, var);
    if (symbolp != NULL) 
      error("11: redefined member \'%s\'", var);

    /* add member symbol & set current member offset */
    size = size_of_type((yyvsp[-2].tval).type, (yyvsp[-2].tval).stname);
    offset = align_mboffset(current_mboffset, size, (yyvsp[-2].tval).type);
    add_symbol(current_mbtable, var, MEMBER, N_A, (yyvsp[-2].tval).type,
	       (yyvsp[-2].tval).stname, size, offset);
  }
#line 1902 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 398 "parser.y" /* yacc.c:1646  */
    {
    char *var = (yyvsp[-4].lval).lex;
    struct symbol *symbolp;
    unsigned int n;
    unsigned int size;
    int offset;

    /* error 12: wrong void array member */
    if ((yyvsp[-5].tval).type == VOID_TYPE)
      error("12: wrong void array member \'%s\'", var);

    /* error 13: redefine array member */
    symbolp = find_symbol(current_mbtable, var);
    if (symbolp != NULL)
      error("13: redefined array member \'%s\'", var);
    
    /* add array type member symbol & set current member offset */
    n = atoi((yyvsp[-2].lval).lex);
    size = n * size_of_type((yyvsp[-5].tval).type, (yyvsp[-5].tval).stname);
    offset = align_mboffset(current_mboffset, size, (yyvsp[-5].tval).type);
    add_symbol(current_mbtable, (yyvsp[-4].lval).lex, MEMBER, N_A,
               type_to_atype((yyvsp[-5].tval).type), (yyvsp[-5].tval).stname, size, offset);
  }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 425 "parser.y" /* yacc.c:1646  */
    { /* assign lexeme attribute value */
    (yyval.lval).lex = lex;
  }
#line 1938 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 432 "parser.y" /* yacc.c:1646  */
    { /* assign lexeme attribute value */
    (yyval.lval).lex = lex;
  }
#line 1946 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 436 "parser.y" /* yacc.c:1646  */
    { /* convert & assign octal to decimal number */
    char *ptr;
    char *str = (char *) malloc(MAX_DIGIT);

    sprintf(str, "%u", (unsigned int) (strtol(lex + 1, &ptr, 8)));
    (yyval.lval).lex = str;
  }
#line 1958 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 444 "parser.y" /* yacc.c:1646  */
    { /* convert & assign hexadecimal to decimal number */
    char *ptr;
    char *str = (char *) malloc(MAX_DIGIT);

    sprintf(str, "%u", (unsigned int) (strtol(lex + 2, &ptr, 16)));
    (yyval.lval).lex = str;
  }
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 452 "parser.y" /* yacc.c:1646  */
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
    (yyval.lval).lex = str;
  }
#line 1990 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 471 "parser.y" /* yacc.c:1646  */
    { /* create local table, set current table, initialize offset &
       formal argument count */
    position = ARGUMENT;
    current_table = local_table = create_table((yyvsp[0].lval).lex);
    current_offset = &local_offset;
    *current_offset = 0;
    farg_count = 0;
    farg_size = 0;

    fun_count++;
    section_line[fun_count] = ip;
    fun_name[fun_count] = (yyvsp[0].lval).lex;

    /* create local structure table, set current structure table */
    current_sttable = local_sttable =
    				create_table(prefix_name((yyvsp[0].lval).lex, "(s)"));
  }
#line 2012 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 489 "parser.y" /* yacc.c:1646  */
    { /* add function name to global table, set local position */
    char *var = (yyvsp[-4].lval).lex;
    struct symbol *symbolp;
    symbolp = find_symbol(global_table, var);

    /* error 20: redefined function */
    if (symbolp != NULL) {
      if (symbolp->kind != FUNCTIONI) {
        error("20: redefined function \'%s\'", var);
      } else {
        symbolp->kind = FUNCTION;
	symbolp->optype = (yyvsp[-5].tval).optype;
	symbolp->type = (yyvsp[-5].tval).type;
	symbolp->stname = (yyvsp[-5].tval).stname;
	symbolp->size = farg_count;
	symbolp->offset = ip;
      }
    } else 
      add_symbol(global_table, (yyvsp[-4].lval).lex, FUNCTION, (yyvsp[-5].tval).optype,
                 (yyvsp[-5].tval).type, (yyvsp[-5].tval).stname, farg_count, ip);
    farg_size = *current_offset;
    position = LOCAL;
  }
#line 2040 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 513 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: lda sp, -%%d(sp)", ip++);
    local_backpatch_ip = ip;
  }
#line 2049 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 518 "parser.y" /* yacc.c:1646  */
    {
    char *var = (yyvsp[-10].lval).lex;
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
#line 2072 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 545 "parser.y" /* yacc.c:1646  */
    { /* count formal argument during looping */
    farg_count++;
  }
#line 2080 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 549 "parser.y" /* yacc.c:1646  */
    {
    farg_count++;
  }
#line 2088 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 556 "parser.y" /* yacc.c:1646  */
    { /* add parameter to current local table & set current offset */
    char *var = (yyvsp[0].lval).lex;
    struct symbol *symbolp = find_symbol(current_table, var);
    unsigned int size;

    /* error 30: wrong optional type parameter */
    if ((yyvsp[-1].tval).optype != NO_OPTYPE)
      error("30: wrong optional type parameter \'%s\'", var);

    /* error 31: wrong void parameter */
    if ((yyvsp[-1].tval).type == VOID_TYPE)
      error("31: wrong void parameter \'%s\'", var);

    /* error 99: wrong structure parameter(C-Step Only) */
    if ((yyvsp[-1].tval).type == STRUCT_TYPE)
      error("99: wrong structure parameter \'%s\'(C-Step Only)", var);

    /* error 32: redefined parameter */
    if (symbolp != NULL)
      error("32: redefined parameter \'%s\'", var);

    size = size_of_type((yyvsp[-1].tval).type, (yyvsp[-1].tval).stname);
    add_symbol(current_table, var, position, (yyvsp[-1].tval).optype, (yyvsp[-1].tval).type,
	       (yyvsp[-1].tval).stname, size, *current_offset);
    *current_offset = *current_offset + 4;
  }
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 583 "parser.y" /* yacc.c:1646  */
    { /* add array parameter to current local table & set current offset */
    char *var = (yyvsp[-2].lval).lex;
    struct symbol *symbolp = find_symbol(current_table, var);
    unsigned int size = POINTER_SIZE;

    /* error 33: wrong optional type array parameter */
    if((yyvsp[-3].tval).optype != NO_OPTYPE)
      error("33: wrong optional type array parameter \'%s\'",var);

    /* error 34: wrong void array parameter */
    if((yyvsp[-3].tval).type == VOID_TYPE)
      error("34: wrong void array parameter \'%s\'", var);

    /* error 35: redefined array parameter */
    if(symbolp != NULL)
      error("35: redefined array parameter \'%s\'", var);

    add_symbol(current_table, var, position, (yyvsp[-3].tval).optype,
               type_to_ptype((yyvsp[-3].tval).type), (yyvsp[-3].tval).stname, size,
	       *current_offset);
    *current_offset = *current_offset + 4;
  }
#line 2146 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 637 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).rip = ip;
    regi_free((yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).pregi);
  }
#line 2156 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 643 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).rip = ip;
  }
#line 2164 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 650 "parser.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].rval).pregi == NO_REGI) {
      char *var = (yyvsp[-1].rval).rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int offset = symbolp->offset;

      if (symbolp->kind == GLOBAL) {
	if (symbolp->type == CHAR_TYPE)
	  generate("%d: stb %d, -%d(gp)", ip++, (yyvsp[0].rval).regi, offset);
	else
	  generate("%d: st %d, -%d(gp)", ip++, (yyvsp[0].rval).regi, offset);
      } else {
	if (symbolp->type == CHAR_TYPE)
	  generate("%d: stb %d, -%d(fp)", ip++, (yyvsp[0].rval).regi, offset + 8);
	else
	  generate("%d: st %d, -%d(fp)", ip++, (yyvsp[0].rval).regi, offset + 8);
      }

    } else {
      char *var = (yyvsp[-1].rval).rlex;
      struct symbol *symbolp = lookup_symbol(var);

      if ((yyvsp[-1].rval).lastexp == FACTOR_ARRAY_EXP &&
	  symbolp->type == CHAR_ARRAY_TYPE)
	generate("%d: stb %d, 0(%d)", ip++, (yyvsp[0].rval).regi, (yyvsp[-1].rval).pregi);
      else if ((yyvsp[-1].rval).lastexp == UNARY_MULTIPLY_EXP &&
	       (symbolp->type == CHAR_P_TYPE ||
		symbolp->type == CHAR_P_ARRAY_TYPE))
	generate("%d: stb %d, 0(%d)", ip++, (yyvsp[0].rval).regi, (yyvsp[-1].rval).pregi);
      else if ((yyvsp[-1].rval).lastexp == MEMBER_PERIOD_EXP ||
	       (yyvsp[-1].rval).lastexp == MEMBER_PERIOD_EXP2 ||
	       (yyvsp[-1].rval).lastexp == MEMBER_ARROW_EXP) {
	struct symbol *ssymbolp = lookup_struct(symbolp->stname);
	struct symbol *msymbolp = find_symbol(ssymbolp->mbtable, member_name);

	if (msymbolp->type == CHAR_TYPE ||
	    msymbolp->type == CHAR_ARRAY_TYPE)
	  generate("%d: stb %d, 0(%d)", ip++, (yyvsp[0].rval).regi, (yyvsp[-1].rval).pregi);
      }
      else
	generate("%d: st %d, 0(%d)", ip++, (yyvsp[0].rval).regi, (yyvsp[-1].rval).pregi);
      regi_free((yyvsp[-1].rval).pregi);
    }
    (yyval.rval).regi = (yyvsp[0].rval).regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
  }
#line 2219 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 701 "parser.y" /* yacc.c:1646  */
    {
    if ((yyvsp[0].rval).lastexp == FACTOR_ARRAY_EXP ||
	(yyvsp[0].rval).lastexp == MEMBER_PERIOD_EXP) {
      backpatch_delete((yyvsp[0].rval).lastip2);
      regi_free((yyvsp[0].rval).pregi);
      (yyval.rval).regi = (yyvsp[0].rval).regi;
      (yyval.rval).pregi = NO_REGI;
      (yyval.rval).rlex = (yyvsp[0].rval).rlex;
      (yyval.rval).lastip1 = NO_IP;
      (yyval.rval).lastip2 = NO_IP;
      (yyval.rval).lastexp = NO_EXP;

    } else {
      (yyval.rval).regi = (yyvsp[0].rval).regi;
      (yyval.rval).pregi = (yyvsp[0].rval).pregi;
      (yyval.rval).rlex = (yyvsp[0].rval).rlex;
      (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
      (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
      (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
    }
  }
#line 2245 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 723 "parser.y" /* yacc.c:1646  */
    {
      (yyval.rval).regi = (yyvsp[0].rval).regi;
      (yyval.rval).pregi = (yyvsp[0].rval).pregi;
      (yyval.rval).rlex = (yyvsp[0].rval).rlex;
      (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
      (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
      (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
 
  }
#line 2259 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 733 "parser.y" /* yacc.c:1646  */
    {
      (yyval.rval).regi = (yyvsp[0].rval).regi;
      (yyval.rval).pregi = (yyvsp[0].rval).pregi;
      (yyval.rval).rlex = (yyvsp[0].rval).rlex;
      (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
      (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
      (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
 
  }
#line 2273 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 743 "parser.y" /* yacc.c:1646  */
    {
      (yyval.rval).regi = (yyvsp[0].rval).regi;
      (yyval.rval).pregi = (yyvsp[0].rval).pregi;
      (yyval.rval).rlex = (yyvsp[0].rval).rlex;
      (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
      (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
      (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
 
  }
#line 2287 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 756 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();

    generate("%d: frd %d, %d, %d",ip++,(yyvsp[-5].rval).regi,(yyvsp[-3].rval).regi,(yyvsp[-1].rval).regi);
    regi_free((yyvsp[-5].rval).regi);
    regi_free((yyvsp[-3].rval).regi);
    regi_free((yyvsp[-1].rval).regi);
 

    generate("%d: lda %d, 0(%d)", ip++, regi, REGI_RETURN);
    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
 }
#line 2309 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 778 "parser.y" /* yacc.c:1646  */
    {

    int regi = regi_new();

    generate("%d: fwt %d, %d, %d",ip++,(yyvsp[-5].rval).regi,(yyvsp[-3].rval).regi,(yyvsp[-1].rval).regi);
    regi_free((yyvsp[-5].rval).regi);
    regi_free((yyvsp[-3].rval).regi);
    regi_free((yyvsp[-1].rval).regi);
 

    generate("%d: lda %d, 0(%d)", ip++, regi, REGI_RETURN);
    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
 }
#line 2332 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 800 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();

    generate("%d: lib %d, %d, %d",ip++,(yyvsp[-5].rval).regi,(yyvsp[-3].rval).regi,(yyvsp[-1].rval).regi);
    regi_free((yyvsp[-5].rval).regi);
    regi_free((yyvsp[-3].rval).regi);
    regi_free((yyvsp[-1].rval).regi);
 

    generate("%d: lda %d, 0(%d)", ip++, regi, REGI_RETURN);
    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;

 }
#line 2355 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 822 "parser.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].rval).lastexp == FACTOR_VAR_EXP ||
	(yyvsp[-1].rval).lastexp == FACTOR_ARRAY_EXP ||
	(yyvsp[-1].rval).lastexp == MEMBER_PERIOD_EXP ||
	(yyvsp[-1].rval).lastexp == MEMBER_PERIOD_EXP2 ||
	(yyvsp[-1].rval).lastexp == MEMBER_ARROW_EXP) {
      backpatch_delete((yyvsp[-1].rval).lastip1);
      regi_free((yyvsp[-1].rval).regi);
      (yyval.rval).regi = NO_REGI;
      (yyval.rval).pregi = (yyvsp[-1].rval).pregi;
      (yyval.rval).rlex = (yyvsp[-1].rval).rlex;
      (yyval.rval).lastip1 = NO_IP;
      (yyval.rval).lastip2 = NO_IP;
      (yyval.rval).lastexp = NO_EXP;
    }

    else if ((yyvsp[-1].rval).lastexp == UNARY_MULTIPLY_EXP) {
      backpatch_delete((yyvsp[-1].rval).lastip1);
      regi_free((yyvsp[-1].rval).regi);
      (yyval.rval).regi = NO_REGI;
      (yyval.rval).pregi = (yyvsp[-1].rval).pregi;
      (yyval.rval).rlex = (yyvsp[-1].rval).rlex;
      (yyval.rval).lastip1 = NO_IP;
      (yyval.rval).lastip2 = NO_IP;
      //$<rval>$.lastexp = NO_EXP;
    }
  }
#line 2387 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 853 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();

    /* logical-OR operation */
    if ((yyvsp[-1].oval).operator == DOUBLEOR) {
      generate("%d: ldc %d, 1", ip++, regi);
      generate("%d: jgt %d, 2(pc)", ip++, (yyvsp[-2].rval).regi);
      generate("%d: jgt %d, 1(pc)", ip++, (yyvsp[0].rval).regi);
      generate("%d: ldc %d, 0", ip++, regi);

    /* logical-AND operation */
    } else if ((yyvsp[-1].oval).operator == DOUBLEAND) {
      generate("%d: ldc %d, 0", ip++, regi);
      generate("%d: jle %d, 2(pc)", ip++, (yyvsp[-2].rval).regi);
      generate("%d: jle %d, 1(pc)", ip++, (yyvsp[0].rval).regi);
      generate("%d: ldc %d, 1", ip++, regi);
    }
    regi_free((yyvsp[-2].rval).regi);
    regi_free((yyvsp[0].rval).regi);
    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
  }
#line 2418 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 880 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).regi = (yyvsp[0].rval).regi;
    (yyval.rval).pregi = (yyvsp[0].rval).pregi;
    (yyval.rval).rlex = (yyvsp[0].rval).rlex;
    (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
    (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
    (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
  }
#line 2431 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 892 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = DOUBLEOR;
  }
#line 2439 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 896 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = DOUBLEAND;
  }
#line 2447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 903 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();

    if ((yyvsp[-1].oval).operator == LT)
      generate("%d: lt %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
    else if ((yyvsp[-1].oval).operator == LE)
      generate("%d: le %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
    else if ((yyvsp[-1].oval).operator == GT)
      generate("%d: gt %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
    else if ((yyvsp[-1].oval).operator == GE)
      generate("%d: ge %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
    else if ((yyvsp[-1].oval).operator == EQ)
      generate("%d: eq %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
    else if ((yyvsp[-1].oval).operator == NE)
      generate("%d: ne %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);

    regi_free((yyvsp[-2].rval).regi);
    regi_free((yyvsp[0].rval).regi);
    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
  }
#line 2477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 929 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).regi = (yyvsp[0].rval).regi;
    (yyval.rval).pregi = (yyvsp[0].rval).pregi;
    (yyval.rval).rlex = (yyvsp[0].rval).rlex;
    (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
    (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
    (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
  }
#line 2490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 941 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = LT;
  }
#line 2498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 945 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = LE;
  }
#line 2506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 949 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = GT;
  }
#line 2514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 953 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = GE;
  }
#line 2522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 957 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = EQ;
  }
#line 2530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 961 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = NE;
  }
#line 2538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 968 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();

    if ((yyvsp[-1].oval).operator == PLUS)
      generate("%d: add %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
    else if ((yyvsp[-1].oval).operator == MINUS)
      generate("%d: sub %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
      
    regi_free((yyvsp[-2].rval).regi);
    regi_free((yyvsp[0].rval).regi);
    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
  }
#line 2560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 986 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).regi = (yyvsp[0].rval).regi;
    (yyval.rval).pregi = (yyvsp[0].rval).pregi;
    (yyval.rval).rlex = (yyvsp[0].rval).rlex;
    (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
    (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
    (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
  }
#line 2573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 998 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = PLUS;
  }
#line 2581 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1002 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = MINUS;
  }
#line 2589 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1009 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();

    if ((yyvsp[-1].oval).operator == MULTIPLY)
      generate("%d: mul %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
    else if ((yyvsp[-1].oval).operator == DIVIDE)
      generate("%d: div %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
    else if ((yyvsp[-1].oval).operator == PERCENT){
      generate("%d: div %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, (yyvsp[0].rval).regi);
      generate("%d: mul %d, %d, %d", ip++, regi, (yyvsp[0].rval).regi, regi);
      generate("%d: sub %d, %d, %d", ip++, regi, (yyvsp[-2].rval).regi, regi);
    }
    regi_free((yyvsp[-2].rval).regi);
    regi_free((yyvsp[0].rval).regi);
    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
  }
#line 2615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1031 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).regi = (yyvsp[0].rval).regi;
    (yyval.rval).pregi = (yyvsp[0].rval).pregi;
    (yyval.rval).rlex = (yyvsp[0].rval).rlex;
    (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
    (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
    (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
  }
#line 2628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1043 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = MULTIPLY;
  }
#line 2636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1047 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = DIVIDE;
  }
#line 2644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1051 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = PERCENT;
  }
#line 2652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1058 "parser.y" /* yacc.c:1646  */
    {
    /* !var */
    if ((yyvsp[-1].oval).operator == EXCLAMATION) {
      int regi = regi_new();

      /* logical-NOT operation */
      generate("%d: ldc %d, 0", ip++, regi);
      generate("%d: le %d, %d, %d", ip++, regi, (yyvsp[0].rval).regi, regi);

      regi_free((yyvsp[0].rval).regi);
      (yyval.rval).regi = regi;
      (yyval.rval).pregi = NO_REGI;
      (yyval.rval).rlex = NULL;
      (yyval.rval).lastip1 = NO_IP;
      (yyval.rval).lastip2 = NO_IP;
      (yyval.rval).lastexp = NO_EXP;

    /* &var */
    } else if ((yyvsp[-1].oval).operator == AMPERSAND) {
      char *var = (yyvsp[0].rval).rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int offset = symbolp->offset;

      /* error 99: invalid type error variable(C-Step Only) */
      if (!((yyvsp[0].rval).lastexp == FACTOR_VAR_EXP ||
	    (yyvsp[0].rval).lastexp == FACTOR_ARRAY_EXP))
	error("99: invalid type error variable \'%s\'(with '&')(C-Step Only)",
	      var);

      if ((yyvsp[0].rval).lastexp == FACTOR_VAR_EXP) {
	backpatch_delete((yyvsp[0].rval).lastip1);
	if (symbolp->kind == GLOBAL) {
	  generate("%d: lda %d, -%d(gp)", ip++, (yyvsp[0].rval).regi, offset);
	} else {
	  generate("%d: lda %d, -%d(fp)", ip++, (yyvsp[0].rval).regi, offset + 8);
	}
	(yyval.rval).regi = (yyvsp[0].rval).regi;
	(yyval.rval).pregi = (yyvsp[-1].rval).pregi;
	(yyval.rval).rlex = (yyvsp[-1].rval).rlex;
	(yyval.rval).lastip1 = NO_IP;
	(yyval.rval).lastip2 = NO_IP;
	(yyval.rval).lastexp = NO_EXP;

      } else if ((yyvsp[0].rval).lastexp == FACTOR_ARRAY_EXP) {
	backpatch_delete((yyvsp[0].rval).lastip1);
	regi_free((yyvsp[0].rval).regi);
	(yyval.rval).regi = (yyvsp[0].rval).pregi;
	(yyval.rval).pregi = NO_REGI;
	(yyval.rval).rlex = (yyvsp[0].rval).rlex;
	(yyval.rval).lastip1 = NO_IP;
	(yyval.rval).lastip2 = NO_IP;
	(yyval.rval).lastexp = NO_EXP;
      }

    /* *var */
    } else if ((yyvsp[-1].oval).operator == MULTIPLY) {
      char *var = (yyvsp[0].rval).rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int regi;

      /* error 54: invalid type error variable */
      if (!is_pointer(symbolp->type))
	error("54: invalid type error variable \'%s\'(with '*')", var);

      if ((yyvsp[0].rval).lastexp == FACTOR_ARRAY_EXP) {
	backpatch_delete((yyvsp[0].rval).lastip2);
	regi_free((yyvsp[0].rval).pregi);
      }
      regi = regi_new();
      generate("%d: ld %d, 0(%d)", ip++, regi, (yyvsp[0].rval).regi);

      (yyval.rval).regi = regi;
      (yyval.rval).pregi = (yyvsp[0].rval).regi;	// cross!
      (yyval.rval).rlex = (yyvsp[0].rval).rlex;
      (yyval.rval).lastip1 = ip - 1;
      (yyval.rval).lastip2 = NO_IP;
      (yyval.rval).lastexp = UNARY_MULTIPLY_EXP;
    }
  }
#line 2736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1138 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).regi = (yyvsp[0].rval).regi;
    (yyval.rval).pregi = (yyvsp[0].rval).pregi;
    (yyval.rval).rlex = (yyvsp[0].rval).rlex;
    (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
    (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
    (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
  }
#line 2749 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1150 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = EXCLAMATION;
  }
#line 2757 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1154 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = AMPERSAND;
  }
#line 2765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1158 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = MULTIPLY;
  }
#line 2773 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1165 "parser.y" /* yacc.c:1646  */
    {
    char* var = (yyvsp[-2].rval).rlex;		// ex: junho
    char* member = (yyvsp[0].lval).lex;	// ex: name
    struct symbol* symbolp;		// variable symbol pointer
    struct symbol* ssymbolp;		// struct symbol pointer
    struct symbol* msymbolp;		// member symbol pointer
    int operator = (yyvsp[-1].oval).operator;

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
      backpatch_delete((yyvsp[-2].rval).lastip1);
      regi_free((yyvsp[-2].rval).regi);

      if ((yyvsp[-2].rval).lastexp == FACTOR_VAR_EXP) {
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
	(yyval.rval).regi = regi2;
	(yyval.rval).pregi = regi3;
	(yyval.rval).rlex = var;
	(yyval.rval).lastip1 = ip - 2;
	(yyval.rval).lastip2 = ip - 1;
	(yyval.rval).lastexp = MEMBER_PERIOD_EXP;
	member_name = member;
      
      } else if ((yyvsp[-2].rval).lastexp == FACTOR_ARRAY_EXP) {
	int regi1 = regi_new();
	int regi2 = regi_new();

	generate("%d: ldc %d, %d", ip++, regi1, msymbolp->offset);
	generate("%d: add %d, %d, %d", ip++, regi1, (yyvsp[-2].rval).pregi, regi1);
	generate("%d: ld %d, 0(%d)", ip++, regi2, regi1);

	regi_free((yyvsp[-2].rval).pregi);
	(yyval.rval).regi = regi2;
	(yyval.rval).pregi = regi1;
	(yyval.rval).rlex = var;
	(yyval.rval).lastip1 = ip - 1;
	(yyval.rval).lastip2 = NO_IP;
	(yyval.rval).lastexp = MEMBER_PERIOD_EXP2;
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
      generate("%d: add %d, %d, %d", ip++, regi1, (yyvsp[-2].rval).regi, regi1);
      generate("%d: ld %d, 0(%d)", ip++, regi2, regi1);

      regi_free((yyvsp[-2].rval).regi);
      (yyval.rval).regi = regi2;
      (yyval.rval).pregi = regi1;
      (yyval.rval).rlex = var;
      (yyval.rval).lastip1 = ip - 1;
      (yyval.rval).lastip2 = NO_IP;
      (yyval.rval).lastexp = MEMBER_ARROW_EXP;
      member_name = member;
    }
  }
#line 2876 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1264 "parser.y" /* yacc.c:1646  */
    {
    char* var = (yyvsp[-5].rval).rlex;		// ex: junho
    char* member = (yyvsp[-3].lval).lex;	// ex: name
    struct symbol* symbolp;		// variable symbol pointer
    struct symbol* ssymbolp;		// struct symbol pointer
    struct symbol* msymbolp;		// member symbol pointer
    int operator = (yyvsp[-4].oval).operator;

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
      backpatch_delete((yyvsp[-5].rval).lastip1);
      regi_free((yyvsp[-5].rval).regi);

      if ((yyvsp[-5].rval).lastexp == FACTOR_VAR_EXP) {
	int regi1 = regi_new();
	int regi2 = regi_new();
	int regi3 = regi_new();
	int offset = symbolp->offset;

	generate("%d: ldc %d, %d", ip++, regi1,
	    size_of_type(atype_to_type(msymbolp->type), msymbolp->stname));
	generate("%d: mul %d, %d, %d", ip++, regi1, (yyvsp[-1].rval).regi, regi1);
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
	regi_free((yyvsp[-1].rval).regi);
	(yyval.rval).regi = regi2;
	(yyval.rval).pregi = regi3;
	(yyval.rval).rlex = var;
	(yyval.rval).lastip1 = ip - 2;
	(yyval.rval).lastip2 = ip - 1;
	(yyval.rval).lastexp = MEMBER_PERIOD_EXP;
	member_name = member;

      } else if ((yyvsp[-5].rval).lastexp == FACTOR_ARRAY_EXP) {
	int regi1 = regi_new();
	int regi2 = regi_new();

	generate("%d: ldc %d, %d", ip++, regi1,
	    size_of_type(atype_to_type(msymbolp->type), msymbolp->stname));
	generate("%d: mul %d, %d, %d", ip++, regi1, (yyvsp[-1].rval).regi, regi1);
	generate("%d: ldc %d, %d", ip++, regi2, msymbolp->offset);
	generate("%d: add %d, %d, %d", ip++, regi1, regi1, regi2);
	generate("%d: add %d, %d, %d", ip++, regi1, (yyvsp[-5].rval).pregi, regi1);
	generate("%d: ld %d, 0(%d)", ip++, regi2, regi1);

	regi_free((yyvsp[-5].rval).pregi);
	regi_free((yyvsp[-1].rval).regi);
	(yyval.rval).regi = regi2;
	(yyval.rval).pregi = regi1;
	(yyval.rval).rlex = var;
	(yyval.rval).lastip1 = ip - 1;
	(yyval.rval).lastip2 = NO_IP;
	(yyval.rval).lastexp = MEMBER_PERIOD_EXP2;
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
      generate("%d: mul %d, %d, %d", ip++, regi1, (yyvsp[-1].rval).regi, regi1);
      generate("%d: ldc %d, %d", ip++, regi2, msymbolp->offset);
      generate("%d: add %d, %d, %d", ip++, regi1, regi1, regi2);
      generate("%d: add %d, %d, %d", ip++, regi1, (yyvsp[-5].rval).regi, regi1);
      generate("%d: ld %d, 0(%d)", ip++, regi2, regi1);

      regi_free((yyvsp[-5].rval).regi);
      regi_free((yyvsp[-1].rval).regi);
      (yyval.rval).regi = regi2;
      (yyval.rval).pregi = regi1;
      (yyval.rval).rlex = var;
      (yyval.rval).lastip1 = ip - 1;
      (yyval.rval).lastip2 = NO_IP;
      (yyval.rval).lastexp = MEMBER_ARROW_EXP;
      member_name = member;
    }
  }
#line 2994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1378 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).regi = (yyvsp[0].rval).regi;
    (yyval.rval).pregi = (yyvsp[0].rval).pregi;
    (yyval.rval).rlex = (yyvsp[0].rval).rlex;
    (yyval.rval).lastip1 = (yyvsp[0].rval).lastip1;
    (yyval.rval).lastip2 = (yyvsp[0].rval).lastip2;
    (yyval.rval).lastexp = (yyvsp[0].rval).lastexp;
  }
#line 3007 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1390 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = PERIOD;
  }
#line 3015 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1394 "parser.y" /* yacc.c:1646  */
    {
    (yyval.oval).operator = ARROW;
  }
#line 3023 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1401 "parser.y" /* yacc.c:1646  */
    {
    (yyval.rval).regi = (yyvsp[-1].rval).regi;
    (yyval.rval).pregi = (yyvsp[-1].rval).pregi;
    (yyval.rval).rlex = (yyvsp[-1].rval).rlex;
    (yyval.rval).lastip1 = (yyvsp[-1].rval).lastip1;
    (yyval.rval).lastip2 = (yyvsp[-1].rval).lastip2;
    (yyval.rval).lastexp = (yyvsp[-1].rval).lastexp;
  }
#line 3036 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1410 "parser.y" /* yacc.c:1646  */
    {
    char *var = (yyvsp[0].lval).lex;
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

      (yyval.rval).regi = regi;
      (yyval.rval).pregi = NO_REGI;
      (yyval.rval).rlex = var;
      (yyval.rval).lastip1 = ip - 1;
      (yyval.rval).lastip2 = NO_IP;
      (yyval.rval).lastexp = FACTOR_VAR_EXP;
     
    } else {
      int regi = regi_new();
      int offset = symbolp->offset;

      if (is_array(symbolp->type))
	generate("%d: lda %d, -%d(gp)", ip++, regi, offset + 8);
      else
	generate("%d: ld %d, -%d(fp)", ip++, regi, offset + 8);

      (yyval.rval).regi = regi;
      (yyval.rval).pregi = NO_REGI;
      (yyval.rval).rlex = var;
      (yyval.rval).lastip1 = ip - 1;
      (yyval.rval).lastip2 = NO_IP;
      (yyval.rval).lastexp = FACTOR_VAR_EXP;
    }
  }
#line 3087 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1457 "parser.y" /* yacc.c:1646  */
    {
    char *var = (yyvsp[-3].lval).lex;
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
      generate("%d: mul %d, %d, %d", ip++, (yyvsp[-1].rval).regi, regi1,
	        (yyvsp[-1].rval).regi);
      generate("%d: ld %d, -%d(fp)", ip++, regi1, offset + 8);
      generate("%d: add %d, %d, %d", ip++, regi1, regi1, (yyvsp[-1].rval).regi);
      generate("%d: ld %d, -%d(%d)", ip++, regi2, offset, regi1);
      generate("%d: lda %d, -%d(%d)", ip++, regi3, offset, regi1);

      regi_free(regi1);
      regi_free((yyvsp[-1].rval).regi);
      regi_free((yyvsp[-1].rval).pregi);
      (yyval.rval).regi = regi2;
      (yyval.rval).pregi = regi3;
      (yyval.rval).rlex = var;
      (yyval.rval).lastip1 = ip - 2;
      (yyval.rval).lastip2 = ip - 1;
      (yyval.rval).lastexp = FACTOR_ARRAY_EXP;

    } else {
      int regi1 = regi_new();
      int regi2 = regi_new();
      int regi3 = regi_new();
      int offset = symbolp->offset;
      int tsize = size_of_type(atype_to_type(symbolp->type), symbolp->stname);

      generate("%d: ldc %d, %d", ip++, regi1, tsize);
      generate("%d: mul %d, %d, %d", ip++, (yyvsp[-1].rval).regi, regi1,
                (yyvsp[-1].rval).regi);
      if (symbolp->kind == GLOBAL) {
	generate("%d: add %d, gp, %d", ip++, regi1, (yyvsp[-1].rval).regi);
	generate("%d: ld %d, -%d(%d)", ip++, regi2, offset, regi1);
	generate("%d: lda %d, -%d(%d)", ip++, regi3, offset, regi1);
      } else {
	generate("%d: add %d, fp, %d", ip++, regi1, (yyvsp[-1].rval).regi);
	generate("%d: ld %d, -%d(%d)", ip++, regi2, offset + 8, regi1);
	generate("%d: lda %d, -%d(%d)", ip++, regi3, offset + 8, regi1);
      }
      regi_free(regi1);
      regi_free((yyvsp[-1].rval).regi);
      regi_free((yyvsp[-1].rval).pregi);
      (yyval.rval).regi = regi2;
      (yyval.rval).pregi = regi3;
      (yyval.rval).rlex = var;
      (yyval.rval).lastip1 = ip - 2;
      (yyval.rval).lastip2 = ip - 1;
      (yyval.rval).lastexp = FACTOR_ARRAY_EXP;
    }
  }
#line 3160 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1526 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();
    int num = atoi((yyvsp[0].lval).lex);

    generate("%d: ldc %d, %d", ip++, regi, num);

    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
  }
#line 3178 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1540 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();
    int num = atoi((yyvsp[0].lval).lex);

    generate("%d: ldc %d, %d", ip++, regi, num);
      
    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
  }
#line 3196 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1554 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();
    int num = atoi((yyvsp[0].lval).lex);

    generate("%d: ldc %d, %d", ip++, regi, -num);

    (yyval.rval).regi = regi;
    (yyval.rval).pregi = NO_REGI;
    (yyval.rval).rlex = NULL;
    (yyval.rval).lastip1 = NO_IP;
    (yyval.rval).lastip2 = NO_IP;
    (yyval.rval).lastexp = NO_EXP;
  }
#line 3214 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1568 "parser.y" /* yacc.c:1646  */
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
      (yyval.rval).regi = regi2;
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
	      (yyval.rval).regi = regi2;
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
	    (yyval.rval).regi = regi2;
	    break;
	  }

	  lex++;
	}
      }
    }
    *current_opoffset = *current_opoffset + (offset_count * 4);
  }
#line 3302 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1655 "parser.y" /* yacc.c:1646  */
    {
    is_break = 0;
    generate("%d: jle %d, %%d(pc)", ip++, (yyvsp[0].rval).regi);
    regi_free((yyvsp[0].rval).regi);
    regi_free((yyvsp[0].rval).pregi);
  }
#line 3313 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1662 "parser.y" /* yacc.c:1646  */
    {
    backpatch((yyvsp[-1].pval).ip - 1, ip - (yyvsp[-1].pval).ip +1 );
    if(is_break == 1)

      backpatch(break_ip, ip);

  }
#line 3325 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1671 "parser.y" /* yacc.c:1646  */
    {
    case_count = 0;
    is_default = 0;
    is_break = 0;

    switch_exp = (yyvsp[-1].rval).regi;
  }
#line 3337 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1679 "parser.y" /* yacc.c:1646  */
    {
    int i;

    if (is_default == 0)
      backpatch(switch_ip - 1, ip - switch_ip);

    for (i = 2; i <= case_count; i++)
      backpatch(case_break[i] - 1, ip);
    if(is_break == 1)
      backpatch(break_ip, ip);
  }
#line 3353 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1694 "parser.y" /* yacc.c:1646  */
    {
    is_break = 0;
    generate("%d: ldc pc, %%d", ip++);
  }
#line 3362 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1699 "parser.y" /* yacc.c:1646  */
    {
    backpatch((yyvsp[-2].pval).ip, ip);
    if(is_break == 1)
      backpatch(break_ip, ip);
  }
#line 3372 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1704 "parser.y" /* yacc.c:1646  */
    {

  }
#line 3380 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1711 "parser.y" /* yacc.c:1646  */
    {
    (yyval.pval).ip = ip;
  }
#line 3388 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1718 "parser.y" /* yacc.c:1646  */
    {
    (yyval.pval).ip = ip;
  }
#line 3396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1725 "parser.y" /* yacc.c:1646  */
    {
    int n;
    int regi1 = regi_new();
    int regi2 = regi_new();

    case_count++;
    n = atoi((yyvsp[-1].lval).lex);

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
#line 3422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1748 "parser.y" /* yacc.c:1646  */
    {
    case_count++;
    
    if (case_count != 1) {
      case_break[case_count] = ip;
    }
  }
#line 3434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1756 "parser.y" /* yacc.c:1646  */
    {
    is_default = 1;

    if (case_count > 0)
      backpatch(switch_ip - 1, ip - switch_ip);
  }
#line 3445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1767 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: jle %d, %%d(pc)", ip++, (yyvsp[0].rval).regi);
    regi_free((yyvsp[0].rval).regi);
    regi_free((yyvsp[0].rval).pregi);
  }
#line 3455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1773 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: ldc pc, %d", ip++, (yyvsp[-4].pval).ip);
    backpatch((yyvsp[-1].pval).ip - 1, ip - (yyvsp[-1].pval).ip);
  }
#line 3464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1778 "parser.y" /* yacc.c:1646  */
    {
    for_count++;

    generate("%d: jne %d, %%d(pc)", ip++, (yyvsp[0].rval).regi);   //forë¬??˜í–‰ ë°±íŒ¨ì¹?
    generate("%d: ldc pc, %%d", ip++);   //forë¬??ˆì¶œ ë°±íŒ¨ì¹?

    for_out[for_count] = ip;
    for_ip2 = (yyvsp[-1].rval).rip;
  }
#line 3478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1788 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: ldc pc, %d", ip++, (yyvsp[-2].rval).rip + 2);
    backpatch(for_out[for_count] - 1, ip);
    for_count--;
  }
#line 3488 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1797 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: ldc pc, %d", ip++, for_ip2);
    backpatch(for_out[for_count] - 2, ip - for_out[for_count] + 1);

    regi_free((yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).pregi);
  }
#line 3500 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1806 "parser.y" /* yacc.c:1646  */
    {
    backpatch(for_out[for_count] - 2, ip - for_out[for_count] + 1);
  }
#line 3508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1814 "parser.y" /* yacc.c:1646  */
    {
    (yyval.pval).ip = ip;
  }
#line 3516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1821 "parser.y" /* yacc.c:1646  */
    {
    (yyval.pval).ip = ip;
  }
#line 3524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1828 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: clr", ip++);
  }
#line 3532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1835 "parser.y" /* yacc.c:1646  */
    {
    int n = atoi((yyvsp[-1].lval).lex);
    generate("%d: slp %d", ip++, n);
  }
#line 3541 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1843 "parser.y" /* yacc.c:1646  */
    {
    if ((yyvsp[-1].rval).pregi == NO_REGI) {
      char *var = (yyvsp[-1].rval).rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int offset = symbolp->offset;

      if (symbolp->kind == GLOBAL) {
	generate("%d: st %d, -%d(gp)", ip++, (yyvsp[0].rval).regi, offset);
      } else {
	generate("%d: st %d, -%d(fp)", ip++, (yyvsp[0].rval).regi, offset + 8);
      }

    } else {
      generate("%d: st %d, 0(%d)", ip++, (yyvsp[0].rval).regi, (yyvsp[-1].rval).pregi);
      regi_free((yyvsp[-1].rval).pregi);
    }
    regi_free((yyvsp[0].rval).regi);
  }
#line 3564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1862 "parser.y" /* yacc.c:1646  */
    {
    regi_free((yyvsp[0].rval).regi);
  }
#line 3572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1869 "parser.y" /* yacc.c:1646  */
    {
    char *var = (yyvsp[0].lval).lex;
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
#line 3594 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1887 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();
    char *var = (yyvsp[-4].lval).lex;
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
    (yyval.rval).regi = regi;
    // regi_free(regi);
  }
#line 3625 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1922 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: push %d", ip++, (yyvsp[0].rval).regi);
    aarg_count++;
    regi_free((yyvsp[0].rval).regi);
    regi_free((yyvsp[0].rval).pregi);
  }
#line 3636 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1929 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: push %d", ip++, (yyvsp[0].rval).regi);
    aarg_count++;
    regi_free((yyvsp[0].rval).regi);
    regi_free((yyvsp[0].rval).pregi);
  }
#line 3647 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1939 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: ldc %d, 0", ip++, REGI_RETURN);
    generate("%d: lda sp, 0(fp)", ip++);
    generate("%d: ld fp, 0(fp)", ip++);
    generate("%d: ld pc, -4(sp)", ip++);
    have_return = 1;
  }
#line 3659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1947 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: lda %d, 0(%d)", ip++, REGI_RETURN, (yyvsp[-1].rval).regi);
    generate("%d: lda sp, 0(fp)", ip++);
    generate("%d: ld fp, 0(fp)", ip++);
    generate("%d: ld pc, -4(sp)", ip++);
    have_return = 1;
    regi_free((yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).pregi);
  }
#line 3673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1957 "parser.y" /* yacc.c:1646  */
    {
    is_break = 1;
    break_ip = ip;
    generate("%d: ldc pc, %%d", ip++);
  }
#line 3683 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1966 "parser.y" /* yacc.c:1646  */
    {
    if ((yyvsp[0].rval).lastexp == FACTOR_VAR_EXP ||
	(yyvsp[0].rval).lastexp == FACTOR_ARRAY_EXP ||
	(yyvsp[0].rval).lastexp == UNARY_MULTIPLY_EXP ||
	(yyvsp[0].rval).lastexp == MEMBER_PERIOD_EXP ||
	(yyvsp[0].rval).lastexp == MEMBER_PERIOD_EXP2 ||
	(yyvsp[0].rval).lastexp == MEMBER_ARROW_EXP) {
      backpatch_delete((yyvsp[0].rval).lastip1);
      regi_free((yyvsp[0].rval).regi);
    }
  }
#line 3699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1978 "parser.y" /* yacc.c:1646  */
    {
    int regi = regi_new();

    generate("%d: in %d", ip++, regi);

    if ((yyvsp[-2].rval).pregi == NO_REGI) {
      char *var = (yyvsp[-2].rval).rlex;
      struct symbol *symbolp = lookup_symbol(var);
      int offset = symbolp->offset;
      
      if (symbolp->kind == GLOBAL) {
	generate("%d: st %d, -%d(gp)", ip++, regi, offset);
      } else {
	generate("%d: st %d, -%d(fp)", ip++, regi, offset + 8);
      }

    } else {
      generate("%d: st %d, 0(%d)", ip++, regi, (yyvsp[-2].rval).pregi);
      regi_free((yyvsp[-2].rval).pregi);
    }
    regi_free(regi);
  }
#line 3726 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 2004 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: out %d", ip++, (yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).pregi);
  }
#line 3736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 2010 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: outs %d", ip++, (yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).pregi);
  }
#line 3746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 2016 "parser.y" /* yacc.c:1646  */
    {
    generate("%d: outc %d", ip++, (yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).regi);
    regi_free((yyvsp[-1].rval).pregi);
  }
#line 3756 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3760 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2027 "parser.y" /* yacc.c:1906  */


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
