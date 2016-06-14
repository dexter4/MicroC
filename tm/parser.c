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

//
#include <unistd.h>
#include "tmlibinclude.h"

//

/* ====================================================================== */
#define IADDR_SIZE      10240   /* size of instruction memory */
#define DADDR_SIZE      131072   /* size of data memory */


#define NO_REGS         32      /* number of registers */

#define PC_REG          31      /* reg[PC_REG] is program counter */
#define GP_REG          30      /* reg[GP_REG] is global pointer */
#define FP_REG          29      /* reg[FP_REG] is frame pointer */
#define SP_REG          28      /* reg[SP_REG] is stack pointer */

#define MAX_LINE        1280    /* line buffer length */


/* ====================================================================== */

extern char *yytext;		/* the current lexeme */

/* ====================================================================== */

void load_program(void);
void regs_init(void);
void regs_print(void);
void iMem_init(void);
void iMem_print_1(int i);
void iMem_print_b_n(int base, int n);
void dMem_init(void);
void dMem_print_b_n(int base, int n);
void breakp_init(void);
void breakp_toggle(int i);
void breakp_print(void);
void help_print(void);
void fetch_and_execute(void);
void fetch_and_execute_debug(void);

/* ====================================================================== */

typedef struct {		/* type INSTRUCTION */
  int iop;			/* instruction operator */
  int iarg1;			/* instruction argument 1 */
  int iarg2;			/* instruction argument 2 */
  int iarg3;			/* instruction argument 3 */
} INSTRUCTION;

/* ====================================================================== */

int reg[NO_REGS];		/* registers */
INSTRUCTION iMem[IADDR_SIZE];	/* instruction memory */
unsigned char dMem[DADDR_SIZE];		/* data memory */
char breakp[IADDR_SIZE];	/* breakpoint */

int iMem_addr;			/* iMem address when loading a program */

int halt = 0;			/* halt = 1 at HALT or breakpoint */
int breakflag = 0;		/* breakflag = 1 at breakpoint */

int debug_mode = 0;		/* execution debugging mode */
int trace = 0;			/* instruction trace during debugging mode */

extern FILE *yyin;		/* current FILE * to parse */
extern char *lex;		/* current lexeme of INTNUM */



#line 145 "parser.tab.c" /* yacc.c:339  */

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
    HALT = 258,
    IN = 259,
    OUTC = 260,
    OUTS = 261,
    OUT = 262,
    ADD = 263,
    SUB = 264,
    MUL = 265,
    DIV = 266,
    LT = 267,
    LE = 268,
    GT = 269,
    GE = 270,
    EQ = 271,
    NE = 272,
    LDB = 273,
    LD = 274,
    LDA = 275,
    LDC = 276,
    STB = 277,
    ST = 278,
    JLT = 279,
    JLE = 280,
    JGT = 281,
    JGE = 282,
    JEQ = 283,
    JNE = 284,
    SLP = 285,
    CLR = 286,
    PUSH = 287,
    POP = 288,
    PC = 289,
    SP = 290,
    FP = 291,
    GP = 292,
    COLON = 293,
    COMMA = 294,
    LPAR = 295,
    RPAR = 296,
    INTNUM = 297,
    UNDEFINED = 298,
    LIB = 299,
    FRD = 300,
    FWT = 301
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 86 "parser.y" /* yacc.c:355  */

  int ival;

#line 236 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  46
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   118,   122,   127,   132,   140,   147,   154,
     164,   176,   188,   200,   212,   224,   236,   248,   260,   272,
     284,   297,   309,   321,   331,   344,   356,   368,   380,   392,
     404,   416,   428,   436,   442,   450,   457,   467,   477,   493,
     507,   518,   522,   526,   530,   537,   546
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "HALT", "IN", "OUTC", "OUTS", "OUT",
  "ADD", "SUB", "MUL", "DIV", "LT", "LE", "GT", "GE", "EQ", "NE", "LDB",
  "LD", "LDA", "LDC", "STB", "ST", "JLT", "JLE", "JGT", "JGE", "JEQ",
  "JNE", "SLP", "CLR", "PUSH", "POP", "PC", "SP", "FP", "GP", "COLON",
  "COMMA", "LPAR", "RPAR", "INTNUM", "UNDEFINED", "LIB", "FRD", "FWT",
  "$accept", "program", "line", "instruction", "iMem_address", "register",
  "displacement", "empty", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

#define YYPACT_NINF -17

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-17)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,   103,   -17,   -17,   -13,   -17,    37,   -17,   -17,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,   -16,   -17,    50,    50,    50,
      50,    50,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,    -7,    -6,    -5,    -4,    -3,    -2,    -1,     0,
      49,    51,    52,    57,    58,    59,    60,    61,    62,    63,
      77,    78,    79,    80,   -17,   -17,   -17,   -17,    81,   107,
     108,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,    50,    50,    50,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   -17,
     122,   123,   124,   125,   126,   127,   128,   129,   131,   132,
     133,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,    48,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      46,     0,     3,     1,     0,     2,     0,    39,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     0,     4,    41,    44,    43,    42,    40,     6,     7,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    45,    32,    34,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    36,    37,    38,    20,
      21,    22,    24,    25,    26,    27,    28,    29,    30,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,   -17,   -17,   -17,   -17,   -10,    13,   -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,    42,     6,    48,    75,     2
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     7,    74,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,    39,    40,    41,    43,    44,    45,    46,    89,   179,
      90,    91,    47,   128,   129,   130,    92,    93,    94,    95,
      96,    97,    98,     3,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    99,   100,   101,   102,
     103,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,     4,   104,   105,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,     0,     0,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189
};

static const yytype_int16 yycheck[] =
{
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    38,    42,    37,    38,    39,
      40,    41,    39,    39,    39,    39,    39,    39,    39,    39,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    44,    45,    46,    34,    35,    36,    37,    39,    41,
      39,    39,    42,   103,   104,   105,    39,    39,    39,    39,
      39,    39,    39,     0,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    39,    39,    39,    39,
      39,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    42,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    -1,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      39,    39,    39,    -1,    -1,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    54,     0,    42,    49,    51,    38,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    44,
      45,    46,    50,    34,    35,    36,    37,    42,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    42,    53,    52,    52,    52,    52,
      52,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    52,    52,
      52,    39,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      40,    40,    39,    39,    39,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    51,
      52,    52,    52,    52,    52,    53,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     2,     2,     2,     2,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       7,     7,     7,     4,     7,     7,     7,     7,     7,     7,
       7,     7,     2,     1,     2,     2,     6,     6,     6,     2,
       1,     1,     1,     1,     1,     1,     0
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
        case 5:
#line 128 "parser.y" /* yacc.c:1646  */
    {
    iMem[iMem_addr].iop = HALT;
  }
#line 1434 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 133 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[0].ival);

    iMem[iMem_addr].iop = IN;
    iMem[iMem_addr].iarg1 = r;
  }
#line 1445 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[0].ival);

    iMem[iMem_addr].iop = OUTC;
    iMem[iMem_addr].iarg1 = r;
  }
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[0].ival);
 
    iMem[iMem_addr].iop = OUTS;
    iMem[iMem_addr].iarg1 = r;
  }
#line 1467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 155 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[0].ival);

    iMem[iMem_addr].iop = OUT;
    iMem[iMem_addr].iarg1 = r;
  }
#line 1478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 165 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = ADD;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 177 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = SUB;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 189 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = MUL;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 201 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = DIV;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 213 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = LT;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1553 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 225 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = LE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 237 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = GT;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 249 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = GE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 261 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = EQ;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1613 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 273 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-4].ival);
    int s = (yyvsp[-2].ival);
    int t = (yyvsp[0].ival);

    iMem[iMem_addr].iop = NE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 285 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = LD;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1643 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 298 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = LD;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 310 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = LDA;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 322 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-2].ival);
    int d = (yyvsp[0].ival);

    iMem[iMem_addr].iop = LDC;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
  }
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 332 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = STB;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 345 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = ST;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 357 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = JLT;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 369 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = JLE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1746 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 381 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = JGT;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1761 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 393 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = JGE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1776 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 405 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = JEQ;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1791 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 417 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[-5].ival);
    int d = (yyvsp[-3].ival);
    int s = (yyvsp[-1].ival);

    iMem[iMem_addr].iop = JNE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
#line 1806 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 429 "parser.y" /* yacc.c:1646  */
    {
    int d = (yyvsp[0].ival);

    iMem[iMem_addr].iop = SLP;
    iMem[iMem_addr].iarg1 = d;
  }
#line 1817 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 437 "parser.y" /* yacc.c:1646  */
    { 
    iMem[iMem_addr].iop = CLR;
  }
#line 1825 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 443 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[0].ival);

    iMem[iMem_addr].iop = PUSH;
    iMem[iMem_addr].iarg1 = r;
  }
#line 1836 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 451 "parser.y" /* yacc.c:1646  */
    {
    int r = (yyvsp[0].ival);

    iMem[iMem_addr].iop = POP;
    iMem[iMem_addr].iarg1 = r;
  }
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 458 "parser.y" /* yacc.c:1646  */
    {
    int r1 = (yyvsp[-4].ival);
    int r2 = (yyvsp[-2].ival);
    int r3  = (yyvsp[0].ival);
    iMem[iMem_addr].iop = LIB;
    iMem[iMem_addr].iarg1 = r1;
    iMem[iMem_addr].iarg2 = r2;
    iMem[iMem_addr].iarg3 = r3;
  }
#line 1861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 468 "parser.y" /* yacc.c:1646  */
    {
    int r1 = (yyvsp[-4].ival);
    int r2 = (yyvsp[-2].ival);
    int r3  = (yyvsp[0].ival);
    iMem[iMem_addr].iop = FRD;
    iMem[iMem_addr].iarg1 = r1;
    iMem[iMem_addr].iarg2 = r2;
    iMem[iMem_addr].iarg3 = r3;
  }
#line 1875 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 478 "parser.y" /* yacc.c:1646  */
    {
    int r1 = (yyvsp[-4].ival);
    int r2 = (yyvsp[-2].ival);
    int r3  = (yyvsp[0].ival);
    iMem[iMem_addr].iop = FWT;
    iMem[iMem_addr].iarg1 = r1;
    iMem[iMem_addr].iarg2 = r2;
    iMem[iMem_addr].iarg3 = r3;
  }
#line 1889 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 494 "parser.y" /* yacc.c:1646  */
    {
    int addr;
    sscanf(lex, "%d", &addr);
    free(lex);
    if((addr < 0) || (addr > IADDR_SIZE - 1)) {
      fprintf(stdout,"%d: bad iMem address\n", addr);
      exit(1);
    }
    iMem_addr = addr;
  }
#line 1904 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 508 "parser.y" /* yacc.c:1646  */
    {
    int r;
    sscanf(lex, "%d", &r);
    free(lex);
    if((r < 0) || (r > NO_REGS - 1)) {
      fprintf(stdout,"%d: bad register %d\n", iMem_addr, r);
      exit(1);
    }
    (yyval.ival) = r;
  }
#line 1919 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 519 "parser.y" /* yacc.c:1646  */
    {
    (yyval.ival) = PC_REG;
  }
#line 1927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 523 "parser.y" /* yacc.c:1646  */
    {
    (yyval.ival) = GP_REG;
  }
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 527 "parser.y" /* yacc.c:1646  */
    {
    (yyval.ival) = FP_REG;
  }
#line 1943 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 531 "parser.y" /* yacc.c:1646  */
    {
    (yyval.ival) = SP_REG;
  }
#line 1951 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 538 "parser.y" /* yacc.c:1646  */
    {
    int d;
    sscanf(lex, "%d", &d);
    free(lex);
    (yyval.ival) = d;
  }
#line 1962 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1966 "parser.tab.c" /* yacc.c:1646  */
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
#line 550 "parser.y" /* yacc.c:1906  */


/* ====================================================================== */

void load_program(void)
{
  yyparse();
}

/* ====================================================================== */

void regs_init(void)
{
  int i;

  for (i = 0; i < NO_REGS; i++)
    reg[i] = 0;
}

void regs_print(void)
{
  int i;

  for (i = 0; i < NO_REGS - 1; i++) {
    if ((i % 4) == 3)
      fprintf(stdout, "%04d: %010d,\n", i, reg[i]);
    else
      fprintf(stdout, "%04d: %010d, ", i, reg[i]);
  }
  fprintf(stdout, "%04d: %010d.\n", i, reg[i]);
  fprintf(stdout, "(sp=%04d, fp=%04d, gp=%04d, pc=%04d)\n",
    SP_REG, FP_REG, GP_REG, PC_REG);
}

/* ====================================================================== */

void iMem_init(void)
{
  int i;

  for (i = 0; i < IADDR_SIZE; i++) {
    iMem[i].iop = 0;
    iMem[i].iarg1 = 0;
    iMem[i].iarg2 = 0;
    iMem[i].iarg3 = 0;
  }
}

void iMem_print_1(int i)
{
  int iop, iarg1, iarg2, iarg3;
  char sarg1[32], sarg2[32], sarg3[32];
  char bp;

  if ((i < 0) || (i > IADDR_SIZE - 1))
    return;

  if(breakp[i] == 1)  bp = '*';
  else bp = ':';

  iop = iMem[i].iop;

  iarg1 = iMem[i].iarg1;
  if (iarg1 == PC_REG)
    strcpy(sarg1, "pc");
  else if (iarg1 == GP_REG)
    strcpy(sarg1, "gp");
  else if (iarg1 == FP_REG)
    strcpy(sarg1, "fp");
  else if (iarg1 == SP_REG)
    strcpy(sarg1, "sp");
  else
    sprintf(sarg1, "%d", iarg1);

  iarg2 = iMem[i].iarg2;
  if (iarg2 == PC_REG)
    strcpy(sarg2, "pc");
  else if (iarg2 == GP_REG)
    strcpy(sarg2, "gp");
  else if (iarg2 == FP_REG)
    strcpy(sarg2, "fp");
  else if (iarg2 == SP_REG)
    strcpy(sarg2, "sp");
  else
    sprintf(sarg2, "%d", iarg2);

  iarg3 = iMem[i].iarg3;
  if (iarg3 == PC_REG)
    strcpy(sarg3, "pc");
  else if (iarg3 == GP_REG)
    strcpy(sarg3, "gp");
  else if (iarg3 == FP_REG)
    strcpy(sarg3, "fp");
  else if (iarg3 == SP_REG)
    strcpy(sarg3, "sp");
  else
    sprintf(sarg3, "%d", iarg3);

  switch (iop) {
  case HALT:
    fprintf(stdout, "%d%c halt\n", i, bp);
    break;
  case IN:
    fprintf(stdout, "%d%c in %s\n", i, bp, sarg1);
    break;
  case OUTC:
    fprintf(stdout, "%d%c outc %s\n", i, bp, sarg1);
    break;
  case OUTS:
    fprintf(stdout, "%d%c outs %s\n", i, bp, sarg1);
    break;
  case OUT:
    fprintf(stdout, "%d%c out %s\n", i, bp, sarg1);
    break;
  case ADD:
    fprintf(stdout, "%d%c add %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case SUB:
    fprintf(stdout, "%d%c sub %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case MUL:
    fprintf(stdout, "%d%c mul %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case DIV:
    fprintf(stdout, "%d%c div %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case LT:
    fprintf(stdout, "%d%c lt %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case LE:
    fprintf(stdout, "%d%c le %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case GT:
    fprintf(stdout, "%d%c gt %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case GE:
    fprintf(stdout, "%d%c ge %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case EQ:
    fprintf(stdout, "%d%c eq %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case NE:
    fprintf(stdout, "%d%c ne %s, %s, %s\n", i, bp, sarg1, sarg2, sarg3);
    break;
  case LDB:
    fprintf(stdout, "%d%c ldb %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case LD:
    fprintf(stdout, "%d%c ld %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case LDA:
    fprintf(stdout, "%d%c lda %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case LDC:
    fprintf(stdout, "%d%c ldc %s, %d\n", i, bp, sarg1, iarg2);
    break;
  case STB:
    fprintf(stdout, "%d%c stb %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case ST:
    fprintf(stdout, "%d%c st %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case JLT:
    fprintf(stdout, "%d%c jlt %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case JLE:
    fprintf(stdout, "%d%c jle %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case JGT:
    fprintf(stdout, "%d%c jgt %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case JGE:
    fprintf(stdout, "%d%c jge %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case JEQ:
    fprintf(stdout, "%d%c jeq %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case JNE:
    fprintf(stdout, "%d%c jne %s, %d(%s)\n", i, bp, sarg1, iarg2, sarg3);
    break;
  case SLP:
    fprintf(stdout, "%d%c slp %d\n", i, bp, iarg1);
    break;
  case CLR:
    fprintf(stdout, "%d%c clr \n", i, bp);
    break;
  case PUSH:
    fprintf(stdout, "%d%c push %s\n", i, bp, sarg1);
    break;
  case POP:
    fprintf(stdout, "%d%c pop %s\n", i, bp, sarg1);
    break;
  default:
    break;
  }
}

void iMem_print_b_n(int base, int n)
{
  int i;
  
  if ((base < 0) || (n < 1))
    return;

  for (i = base; i < base + n; i++)
    iMem_print_1(i);
}

/* ====================================================================== */

void dMem_init(void)
{
  int size;
  int i;

  size = DADDR_SIZE - 4;

  for (i = 0; i <= 3; i++) {
    dMem[0 + i] = size;
    size = size >> 8;
  }

  for (i = 4; i < DADDR_SIZE; i++)
    dMem[i] = 0;
}

void dMem_print_b_n(int base, int n)
{
  int i, count = 0;
  int j = 0;
  int intdata;

  if ((base < 0) || (n < 1))
    return;
  
  for (i = base; i < base + n - 1; i++) {
    if (i > DADDR_SIZE - 2) {
      fprintf(stdout, "%04d: %04d.", i, dMem[i]);
      j = 0;

      while (j<=3){
	if(j == 0)
	  fprintf(stdout, "    ---->");

        intdata += dMem[i - j];
	if(j < 3)
	  intdata = intdata << 8;
	
	if(j == 3){
	  fprintf(stdout,"    %04d.", intdata);
	  fprintf(stdout, "\n");
	}
	j++;
      }
      return;
    }
    if ((count % 4) == 3){
      fprintf(stdout, "%04d: %04d,", i, dMem[i]);
      while (j <= 3){
	if(j == 0)
  	  fprintf(stdout, "    ---->");
	
	intdata += dMem[i - j];
	if(j < 3)
	  intdata = intdata << 8;

	if(j == 3){
	  fprintf(stdout,"    %04d.", intdata);
	  fprintf(stdout, "\n");
	}
	j++;
      }
      j = 0;
      intdata = 0;
    }
    else
      fprintf(stdout, "%04d: %04d, ", i, dMem[i]);
    count = count + 1;
  }
  fprintf(stdout, "%04d: %04d.", i, dMem[i]);
  
  j = 0;
  while (j<=3){
    if(j == 0)
      fprintf(stdout, "    ---->");

    intdata += dMem[i - j];
    if(j < 3)
      intdata = intdata << 8;

    if(j == 3){
      fprintf(stdout,"    %04d.", intdata);
      fprintf(stdout, "\n");
    }
    j++;
    intdata = 0;
  }

}

/* ====================================================================== */

void breakp_init(void)
{
  int i;

  for (i = 0; i < IADDR_SIZE; i++)
    breakp[i] = 0;
}

void breakp_toggle(int i)
{
  if((i < 0) || (i > IADDR_SIZE - 1)
     || (iMem[i].iop == 0) || (iMem[i].iop == HALT))
    return;

  if (breakp[i] == 0) {
    breakp[i] = 1;
    iMem_print_1(i);
  } else {
    breakp[i] = 0;
    iMem_print_1(i);
  }
}

void breakp_print(void)
{
  int i;

  for(i = 0; i < IADDR_SIZE; i++)
    if (breakp[i] == 1)
      iMem_print_1(i);
}

/* ====================================================================== */

void help_print(void)
{
  fprintf(stdout, "Enter           Execute 1 instruction.\n");
  fprintf(stdout, "b(reak)         Show current breakpoints.\n");
  fprintf(stdout, "b(reak) n       Toggle breakpint at iMem[n].\n");
  fprintf(stdout, "s(tep) n        Execute n instruction.\n");
  fprintf(stdout, "g(o)            Execute until HALT.\n");
  fprintf(stdout, "r(egs)          Print the contents of all registers.\n");
  fprintf(stdout, "i(Mem) b n      Print iMem[b] to iMem[b+n-1].\n");
  fprintf(stdout, "d(Mem) b n      Print dMem[b] to bMem[b+n-1].\n");
  fprintf(stdout, "t(oggle)        Toggle printing instruction trace.\n");
  fprintf(stdout, "c(lear)         Reset the machine for new execution.\n");
  fprintf(stdout, "h(elp)          Print the help message.\n");
  fprintf(stdout, "q(uit)          Terminate the machine.\n");
}

/* ====================================================================== */

void fetch_and_execute(void)
{
  int pc = reg[PC_REG];
  int iop = iMem[pc].iop;
  int iarg1 = iMem[pc].iarg1;
  int iarg2 = iMem[pc].iarg2;
  int iarg3 = iMem[pc].iarg3;
  char *tmp;

  if ((breakp[pc] == 1) && (breakflag == 0)) {
    halt = 1;
    breakflag = 1;
    return;
  }

  breakflag = 0;

  if (trace == 1)
    iMem_print_1(reg[PC_REG]);

  switch (iop) {
  case HALT:
    halt = 1;
    break;
  case IN:
    {
      char line[MAX_LINE];
      int r, input;

      reg[PC_REG] = pc + 1;
      fprintf(stdout, "<= ");
      fflush(stdout);
    again:
      tmp = fgets(line, MAX_LINE - 2, stdin);
      r = sscanf(line, "%d", &input);
      if (r <= 0)
	goto again;
      reg[iarg1] = input;
    }
    break;

  case OUTC:
    {
      reg[PC_REG] = pc + 1;
      fprintf(stdout, "%c", reg[iarg1]);
      fflush(stdout);
    }
    break; 
  
  case OUTS:
    {
      int i=0;
      
      reg[PC_REG] = pc + 1;
l1:
      fprintf(stdout, "%c", dMem[reg[iarg1]++] );
      if(dMem[reg[iarg1]] != 0)
        goto l1;
      fflush(stdout);
    }
    break;

  case OUT:
    {
      reg[PC_REG] = pc + 1;
      fprintf(stdout, "%d", reg[iarg1]);
      fflush(stdout);
    }
    break;
  case ADD:
    {
      reg[PC_REG] = pc + 1;
      reg[iarg1] = reg[iarg2] + reg[iarg3];
    }
    break;
  case SUB:
    {
      reg[PC_REG] = pc + 1;
      reg[iarg1] = reg[iarg2] - reg[iarg3];
    }
    break;
  case MUL:
    {
      reg[PC_REG] = pc + 1;
      reg[iarg1] = reg[iarg2] * reg[iarg3];
    }
    break;
  case DIV:
    {
      reg[PC_REG] = pc + 1;
      if (reg[iarg3] == 0) {
	fprintf(stdout, "%d: division by zero\n", pc);
	halt = 1;
      } else
	reg[iarg1] = reg[iarg2] / reg[iarg3];
    }
    break;
  case LT:
    {
      reg[PC_REG] = pc + 1;
      if (reg[iarg2] < reg[iarg3])
	reg[iarg1] = 1;
      else
	reg[iarg1] = 0;
    }
    break;
  case LE:
    {
      reg[PC_REG] = pc + 1;
      if (reg[iarg2] <= reg[iarg3])
	reg[iarg1] = 1;
      else
	reg[iarg1] = 0;
    }
    break;
  case GT:
    {
      reg[PC_REG] = pc + 1;
      if (reg[iarg2] > reg[iarg3])
	reg[iarg1] = 1;
      else
	reg[iarg1] = 0;
    }
    break;
  case GE:
    {
      reg[PC_REG] = pc + 1;
      if (reg[iarg2] >= reg[iarg3])
	reg[iarg1] = 1;
      else
	reg[iarg1] = 0;
    }
    break;
  case EQ:
    {
      reg[PC_REG] = pc + 1;
      if (reg[iarg2] == reg[iarg3])
	reg[iarg1] = 1;
      else
	reg[iarg1] = 0;
    }
    break;
  case NE:
    {
      reg[PC_REG] = pc + 1;
      if (reg[iarg2] != reg[iarg3])
	reg[iarg1] = 1;
      else
	reg[iarg1] = 0;
    }
    break;
  case LDB:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];

      if ((a<0) || (a > DADDR_SIZE - 1)){
	fprintf(stdout, "%d: bad dMem[] address %d\n", pc, a);
	exit(1);
      }

      reg[iarg1] = dMem[a];
    }
    break;
  case LD:
    {
      int a;
      int i;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];

      if ((a < 0) || (a > DADDR_SIZE - 1)) {
	fprintf(stdout, "%d: bad dMem[] address %d\n", pc, a);
	
	exit(1);
      }

      reg[iarg1] = 0;
      
      for (i = 3; i >= 0; i--) {
        reg[iarg1] += dMem[a + i];
	if (i > 0)
	  reg[iarg1] = reg[iarg1] << 8;
      }
    }
    break;
  case LDA:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      reg[iarg1] = a;
    }
    break;
  case LDC:
    {
      reg[PC_REG] = pc + 1;
      reg[iarg1] = iarg2;
    }
    break;
  case STB:
    {
      int a;
      char c;
      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      c= (char) reg[iarg1];
      if ((a < 0) || (a > DADDR_SIZE - 1)) {
	fprintf(stdout, "%d: bad dMem[] address %d\n", pc, a);
	exit(1);
      }
      dMem[a] = c;
    }
    break;
  case ST:
    {
      int i;
      int a;
      int regi;

      regi = reg[iarg1];
      
      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      if ((a < 0) || (a > DADDR_SIZE - 1)) {
	fprintf(stdout, "%d: bad dMem[] address %d\n", pc, a);
	exit(1);
      }
     
      for (i = 0; i <= 3; i++) {
        dMem[a + i] = regi;
        regi = regi >> 8;
      }
    }
    break;
  case JLT:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      if (reg[iarg1] < 0)
	reg[PC_REG] = a;
    }
    break;
  case JLE:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      if (reg[iarg1] <= 0)
	reg[PC_REG] = a;
    }
    break;
  case JGT:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      if (reg[iarg1] > 0)
	reg[PC_REG] = a;
    }
    break;
  case JGE:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      if (reg[iarg1] >= 0)
	reg[PC_REG] = a;
    }
    break;
  case JEQ:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      if (reg[iarg1] == 0)
	reg[PC_REG] = a;
    }
    break;
  case JNE:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg2 + reg[iarg3];
      if (reg[iarg1] != 0)
	reg[PC_REG] = a;
    }
    break;

  case SLP:
    {
      int a;

      reg[PC_REG] = pc + 1;
      a = iarg1 * 1000;
      usleep(a);
    }
    break;
  
  case CLR:
    {
      int i;
      reg[PC_REG] = pc + 1;
      i = system("clear");
    }
    break;

  case PUSH:
    {
      int i;
      int regi;

      reg[PC_REG] = pc + 1;
      regi = reg[iarg1];

      for(i = 0; i <= 3; i++) {
        dMem[reg[SP_REG] + i] = regi;
	regi = regi >> 8;
      }

      reg[SP_REG] = reg[SP_REG] - 4;
    }
    break;
  case POP:
    {
      int i;
      reg[PC_REG] = pc + 1;
      reg[SP_REG] = reg[SP_REG] + 4;

      for(i = 0; i <= 3; i++){
        reg[iarg1] = dMem[reg[SP_REG] - i];
        if(i != 3)
          reg[iarg1] = reg[iarg1] << 8;
      }
    }

    break;
  case LIB:
    {
      reg[PC_REG] = pc + 1;
      reg[REGI_RETURN] = libcall_handle(reg[iarg1],reg[iarg2],reg[iarg3] );
      fflush(stdout);
    }
    break;
  case FRD:
    {
      reg[PC_REG] = pc + 1;
      reg[REGI_RETURN] =  libinst_frd(reg[iarg1],reg[iarg2],reg[iarg3]);
    }
    break;
  case FWT:
    {
      reg[PC_REG] = pc + 1;
      reg[REGI_RETURN] = libinst_fwt(reg[iarg1],reg[iarg2],reg[iarg3]);
    }
    break;
  
  default:
    fprintf(stdout, "%d: bad instruction.\n", pc);
    halt = 1;
    break;
  }
}

/* ====================================================================== */

void fetch_and_execute_debug(void)
{
  char line[MAX_LINE];
  char command[MAX_LINE];
  int argc, arg1, arg2;
  char *tmp;

  fprintf(stdout, "%d> ", reg[PC_REG]);
  fflush(stdout);
  tmp = fgets(line, MAX_LINE - 2, stdin);
  argc = sscanf(line, "%s%d%d", command, &arg1, &arg2);
  if (argc <= 0) {			// Enter
    fetch_and_execute();
    if (breakflag == 1) {
      fprintf(stdout, "Stopped at breakpoint.\n");
      halt = 0;
    }
  } else if (argc == 1) {	// argc == 1
    if (command[0] == 'b') {		// break
      breakp_print();
    } else if (command[0] == 'g') {	// go
      while (halt == 0)
	fetch_and_execute();
      if (breakflag == 1) {
	fprintf(stdout, "Stopped at breakpoint.\n");
	halt = 0;
      }
    } else if (command[0] == 'r') {	// regs
      regs_print();
    } else if (command[0] == 't') {	// toggle
      if (trace == 1) {
	trace = 0;
	fprintf(stdout, "Trace is off.\n");
      } else {
	trace = 1;
	fprintf(stdout, "Trace is on.\n");
      }
    } else if (command[0] == 'c') {	// clear
      regs_init();
      dMem_init();
      breakflag = 0;
    } else if (command[0] == 'h') {	// help
      help_print();
    } else if (command[0] == 'q') {	// quit
      fprintf(stdout, "Bye!\n");
      exit(1);
    } else {				// bad command
      fprintf(stdout, "Type h to print help message.\n");
    }
  } else if (argc == 2) {	// argc == 2
    if (command[0] == 'b') {		// break n
      breakp_toggle(arg1);
    } else if (command[0] == 's') {	// step n
      int i;
      for (i = 0; i < arg1; i++) {
	if (halt == 0)
	  fetch_and_execute();
	else
	  break;
      }
      if (breakflag == 1) {
	fprintf(stdout, "Stopped at breakpoint.\n");
	halt = 0;
      }
    } else {				// bad command
      fprintf(stdout, "Type h to print help message.\n");
    }
  } else if (argc == 3) {	// argc == 3
    if (command[0] == 'i') {		// iMem b n
      iMem_print_b_n(arg1, arg2);
    } else if (command[0] == 'd') {	// dMem b, n
      dMem_print_b_n(arg1, arg2);
    } else {
      fprintf(stdout, "Type h to print help message.\n");
    }
  } else {				// bad command
    fprintf(stdout, "Type h to print help message.\n");
  }
}

/* ====================================================================== */

int yyerror(char *message)
{
  fprintf(stdout, "%d: %s at \"%s\"\n", iMem_addr, message, yytext);
  exit(1);
}

/* ====================================================================== */

int main(int argc, char *argv[])
{
  char *file;

  if (argc == 2) {		// process arguments
    file = argv[1];
  } else if (argc == 3) {
    if (strcmp(argv[1], "-d") == 0) {
      debug_mode = 1;
      trace = 1;
    } else {
      fprintf(stdout, "usage: tm [-d] file\n");
      exit(1);
    }
    file = argv[2];
  } else {
    fprintf(stdout, "usage: tm [-d] file\n");
    exit(1);
  }

  yyin = fopen(file, "r");	// open the program file
  if (yyin == NULL) {
    fprintf(stdout, "%s: %s\n", argv[1], strerror(errno));
    exit(1);
  }

  regs_init();			// initialize reg[]
  iMem_init();			// initialize iMem[]
  dMem_init();			// initialize dMem[]
  breakp_init();		// initialize breakp[]

  lib_init();   // ljh code

  load_program();		// load program into iMem[] and
  fclose(yyin);			// close the program file

  if (debug_mode == 1) {	// debug mode prints a intro line
    fprintf(stdout, "Tiny Machine 1.0\n");
    fprintf(stdout, "Type h to print help message.\n");
  }

loop:
  while (halt == 0)		// fetch and execute loop
    if (debug_mode == 1)
      fetch_and_execute_debug();
    else
      fetch_and_execute();

  if (debug_mode == 1) {	// do not exit in debug mode
    halt = 0;
    goto loop;
  }

  return 0;
}

/* ====================================================================== */
