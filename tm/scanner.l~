/* ====================================================================== */

%{

#include "parser.h"
#include <string.h>

#define	ACCEPT(x) return(x)
#define	ACCEPT_LEX(x) \
{ \
  yytext[yyleng] = '\0'; \
  lex=(char*)malloc(yyleng+1); \
  strcpy(lex, yytext); \
  return(x); \
}

char *lex;

/* ====================================================================== */

%}

digit				[0-9]

/* ====================================================================== */

%%

"FRD"                           ACCEPT(FRD);
"frd"                           ACCEPT(FRD);

"FWT"                           ACCEPT(FWT);
"fwt"                           ACCEPT(FWT);

"lib"                           ACCEPT(LIB);
"LIB"                           ACCEPT(LIB);

"halt"				ACCEPT(HALT);
"HALT"				ACCEPT(HALT);

"in"				ACCEPT(IN);
"IN"				ACCEPT(IN);
"outc"				ACCEPT(OUTC);
"OUTC"				ACCEPT(OUTC);
"outs"				ACCEPT(OUTS);
"OUTS"				ACCEPT(OUTS);
"out"				ACCEPT(OUT);
"OUT"				ACCEPT(OUT);

"add"				ACCEPT(ADD);
"ADD"				ACCEPT(ADD);
"sub"				ACCEPT(SUB);
"SUB"				ACCEPT(SUB);
"mul"				ACCEPT(MUL);
"MUL"				ACCEPT(MUL);
"div"				ACCEPT(DIV);
"DIV"				ACCEPT(DIV);

"lt"				ACCEPT(LT);
"LT"				ACCEPT(LT);
"le"				ACCEPT(LE);
"LE"				ACCEPT(LE);
"gt"				ACCEPT(GT);
"GT"				ACCEPT(GT);
"ge"				ACCEPT(GE);
"GE"				ACCEPT(GE);
"eq"				ACCEPT(EQ);
"EQ"				ACCEPT(EQ);
"ne"				ACCEPT(NE);
"NE"				ACCEPT(NE);

"ldb"				ACCEPT(LDB);
"LDB"				ACCEPT(LDB);
"ld"				ACCEPT(LD);
"LD"				ACCEPT(LD);
"lda"				ACCEPT(LDA);
"LDA"				ACCEPT(LDA);
"ldc"				ACCEPT(LDC);
"LDC"				ACCEPT(LDC);

"stb"				ACCEPT(STB);
"STB"				ACCEPT(STB);
"st"				ACCEPT(ST);
"ST"				ACCEPT(ST);

"jlt"				ACCEPT(JLT);
"JLT"				ACCEPT(JLT);
"jle"				ACCEPT(JLE);
"JLE"				ACCEPT(JLE);
"jgt"				ACCEPT(JGT);
"JGT"				ACCEPT(JGT);
"jge"				ACCEPT(JGE);
"JGE"				ACCEPT(JGE);
"jeq"				ACCEPT(JEQ);
"JEQ"				ACCEPT(JEQ);
"jne"				ACCEPT(JNE);
"JNE"				ACCEPT(JNE);

"slp"				ACCEPT(SLP);
"SLP"				ACCEPT(SLP);
"clr"				ACCEPT(CLR);
"CLR"				ACCEPT(CLR);
"push"				ACCEPT(PUSH);
"PUSH"				ACCEPT(PUSH);
"pop"				ACCEPT(POP);
"POP"				ACCEPT(POP);

"pc"				ACCEPT(PC);
"PC"				ACCEPT(PC);
"sp"				ACCEPT(SP);
"SP"				ACCEPT(SP);
"fp"				ACCEPT(FP);
"FP"				ACCEPT(FP);
"gp"				ACCEPT(GP);
"GP"				ACCEPT(GP);

":"				ACCEPT(COLON);
","				ACCEPT(COMMA);

"("				ACCEPT(LPAR);
")"				ACCEPT(RPAR);

{digit}+			ACCEPT_LEX(INTNUM);
"+"{digit}+			ACCEPT_LEX(INTNUM);
"-"{digit}+			ACCEPT_LEX(INTNUM);

" "				{};
"\t"				{};
"\r"				{};
"\n"				{};

"/*"				skip_comment1();
"//"				skip_comment2();

.				ACCEPT(UNDEFINED);

%%

/* ====================================================================== */

skip_comment1()
{
  int c1,c2;

  c1 = input();
  for(;;) {
    c2 = input();
    if((c1=='*') && (c2=='/'))
      break;
    else {
      c1 = c2;
    }
  }
}

skip_comment2()
{
  int c;

  for(;;)
    if((c=input())=='\n')
      break;
}

/* ====================================================================== */
