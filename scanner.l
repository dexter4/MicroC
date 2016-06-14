/* ====================================================================== */

%{

typedef struct l_type_struct {  /* lex attribute for var and num */
  char *lex;
} l_type;

typedef struct t_type_struct {  /* type attribute for type_specifier */
  unsigned char optype;         /* optional type; static, extern */
  unsigned char type;           /* type; void, int, char, struct ... */
  char *stname;                 /* structure name */
} t_type;

typedef struct o_type_struct {  /* operator attribute for relop, addop... */
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

/* ====================================================================== */

#include "parser.h"
#include <string.h>

/* ====================================================================== */

#define	ACCEPT(x) return(x)
#define	ACCEPT_LEX(x) \
{ \
  yytext[yyleng] = '\0'; \
  lex = malloc(yyleng + 1); \
  strcpy(lex, yytext); \
  return(x); \
}

/* ====================================================================== */

extern char *source_file_name;	/* source program file name */

char *lex;			/* current lexeme of ID or NUM */
int source_line_no = 1;		/* source line number */

/* ====================================================================== */

%}

digit				[0-9]
letter				[a-zA-Z]

%%


"LIBFRD"                         ACCEPT(LIBFRD);
"libfrd"                         ACCEPT(LIBFRD);

"LIBFWT"                         ACCEPT(LIBFWT);
"libfwt"                         ACCEPT(LIBFWT);

"LIBCALL"                       ACCEPT(LIBCALL);
"libcall"                       ACCEPT(LIBCALL);

	/* keywords */
"void"				ACCEPT(VOID);
"int"				ACCEPT(INT);
"char"				ACCEPT(CHAR);
"struct"			ACCEPT(STRUCT);
"static"			ACCEPT(STATIC);
"extern"			ACCEPT(EXTERN);
"const"				ACCEPT(CONST);

"if"				ACCEPT(IF);
"else"				ACCEPT(ELSE);
"switch"			ACCEPT(SWITCH);
"case"				ACCEPT(CASE);
"default"			ACCEPT(DEFAULT);
"while"				ACCEPT(WHILE);
"for"				ACCEPT(FOR);
"return"			ACCEPT(RETURN);
"break"				ACCEPT(BREAK);

"clear"                         ACCEPT(CLEAR);
"sleep"				ACCEPT(SLEEP);
"input"				ACCEPT(INPUT);
"outputc"                       ACCEPT(OUTPUTC);
"outputs"                       ACCEPT(OUTPUTS);
"output"			ACCEPT(OUTPUT);

	/* special symbols */
"+"				ACCEPT(PLUS);
"-"				ACCEPT(MINUS);
"*"				ACCEPT(MULTIPLY);
"/"				ACCEPT(DIVIDE);
"%"				ACCEPT(PERCENT);

"<"				ACCEPT(LT);
"<="				ACCEPT(LE);
">"				ACCEPT(GT);
">="				ACCEPT(GE);
"=="				ACCEPT(EQ);
"!="				ACCEPT(NE);

"||"				ACCEPT(DOUBLEOR);
"&&"				ACCEPT(DOUBLEAND);
"!"				ACCEPT(EXCLAMATION);

"="				ACCEPT(ASSIGN);

"."				ACCEPT(PERIOD);
"->"				ACCEPT(ARROW);
"&"				ACCEPT(AMPERSAND);

","				ACCEPT(COMMA);
";"				ACCEPT(SEMICOLON);
":"				ACCEPT(COLON);

"("				ACCEPT(LPAR);
")"				ACCEPT(RPAR);
"{"				ACCEPT(LBRACE);
"}"				ACCEPT(RBRACE);
"["				ACCEPT(LBRACKET);
"]"				ACCEPT(RBRACKET);

	/* identifier */
({letter}|"_")({letter}|{digit}|"_")*	ACCEPT_LEX(ID);

	/* numbers */
"0"[0-7]([0-7])*			ACCEPT_LEX(OCTNUM);
"0"(x|X)[0-9a-fA-F]([0-9a-fA-F])*	ACCEPT_LEX(HEXNUM);
("0"|([1-9]{digit}*))			ACCEPT_LEX(NUM);

	/* character & string constant */
"'"(.|..)"'"			ACCEPT_LEX(CHARCONST);
\"				{
				  char c = '\"';

				  yytext[0] = c;
				  yyleng = 1;
				  do {
				    c = input();
				    yytext[yyleng] = c;
				    yyleng++;
				    if (c == '\n')
				      source_line_no++;
				    else if (c == EOF) {
				      ACCEPT(UNDEFINED);
				    }
				  } while (c != '\"');
				  ACCEPT_LEX(STRINGCONST);
				}
				
	/* whitespaces */
" "|"\t"|"\r"			;
"\n"				{ source_line_no++; }

	/* comments */
"//".*"\n"			{ source_line_no++; }
"/*"				{
				  char h;	// head char of 2 inputs
				  char t = 0;	// tail char of 2 inputs

				  do {
				    h = t;	// shift tail to head
				    if ((t = input()) == '\n')
				      source_line_no++;
				  } while (!(h == '*' && t == '/'));
				}

	/* error */
.				{
				  fprintf(stderr, "%s: ", source_file_name);
				  fprintf(stderr, "line %d: ", source_line_no);
				  fprintf(stderr, "undefined token \'%s\'\n",
				          yytext);
				  fflush(stderr);
				  exit(-1);
				  // ACCEPT_LEX(UNDEFINED);
				}

%%

/* ====================================================================== */
