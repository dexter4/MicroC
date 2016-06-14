/* ====================================================================== */

%{

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


%}

/* ====================================================================== */

%start program			/* starting symbol */

%union {
  int ival;
}

%token HALT			/* token HALT */
%token IN OUTC OUTS OUT		/* token IN and OUT */
%token ADD SUB MUL DIV		/* token ADD, SUB, MUL and DIV */
%token LT LE GT GE EQ NE	/* token LT, LE, GT, GE, EQ and NE */
%token LDB LD LDA LDC		/* token LD, LDA and LDC */
%token STB ST			/* token ST */
%token JLT JLE JGT JGE JEQ JNE	/* token JLT, JLE, JGT, JGE, JEQ and JNE */
%token SLP CLR
%token PUSH POP 		/* token PUSH and POP */
%token PC SP FP GP		/* token PC, SP, FP and GP */
%token COLON COMMA 		/* token : and , */
%token LPAR RPAR		/* token (, and ) */
%token INTNUM			/* token integer number */
%token UNDEFINED		/* undefined token */

%token LIB
%token FRD
%token FWT


%type <ival> register displacement	/* non-terminals with ival */

%%

/* ====================================================================== */

program
  : program line
  | empty
;

line
  : iMem_address instruction
;

instruction
  // ------------------------------------------------------------
  : HALT
  {
    iMem[iMem_addr].iop = HALT;
  }
  // ------------------------------------------------------------
  | IN register
  {
    int r = $<ival>2;

    iMem[iMem_addr].iop = IN;
    iMem[iMem_addr].iarg1 = r;
  }
  // ------------------------------------------------------------
  | OUTC register
  {
    int r = $<ival>2;

    iMem[iMem_addr].iop = OUTC;
    iMem[iMem_addr].iarg1 = r;
  }
  | OUTS register
  {
    int r = $<ival>2;
 
    iMem[iMem_addr].iop = OUTS;
    iMem[iMem_addr].iarg1 = r;
  }
  | OUT register
  {
    int r = $<ival>2;

    iMem[iMem_addr].iop = OUT;
    iMem[iMem_addr].iarg1 = r;
  }


  // ------------------------------------------------------------
  | ADD register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = ADD;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | SUB register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = SUB;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | MUL register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = MUL;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | DIV register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = DIV;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | LT register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = LT;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | LE register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = LE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | GT register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = GT;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | GE register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = GE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | EQ register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = EQ;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }
  // ------------------------------------------------------------
  | NE register COMMA register COMMA register
  {
    int r = $<ival>2;
    int s = $<ival>4;
    int t = $<ival>6;

    iMem[iMem_addr].iop = NE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = s;
    iMem[iMem_addr].iarg3 = t;
  }

  | LDB register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = LD;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }

  // ------------------------------------------------------------
  | LD register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = LD;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | LDA register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = LDA;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | LDC register COMMA displacement
  {
    int r = $<ival>2;
    int d = $<ival>4;

    iMem[iMem_addr].iop = LDC;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
  }
// ------------------------------------------------------------
  | STB register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = STB;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }


  | ST register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = ST;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | JLT register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = JLT;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | JLE register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = JLE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | JGT register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = JGT;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | JGE register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = JGE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | JEQ register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = JEQ;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | JNE register COMMA displacement LPAR register RPAR
  {
    int r = $<ival>2;
    int d = $<ival>4;
    int s = $<ival>6;

    iMem[iMem_addr].iop = JNE;
    iMem[iMem_addr].iarg1 = r;
    iMem[iMem_addr].iarg2 = d;
    iMem[iMem_addr].iarg3 = s;
  }
  // ------------------------------------------------------------
  | SLP  displacement 
  {
    int d = $<ival>2;

    iMem[iMem_addr].iop = SLP;
    iMem[iMem_addr].iarg1 = d;
  }

  | CLR
  { 
    iMem[iMem_addr].iop = CLR;
  }
  
  // ------------------------------------------------------------
  | PUSH register
  {
    int r = $<ival>2;

    iMem[iMem_addr].iop = PUSH;
    iMem[iMem_addr].iarg1 = r;
  }
  // ------------------------------------------------------------
  | POP register
  {
    int r = $<ival>2;

    iMem[iMem_addr].iop = POP;
    iMem[iMem_addr].iarg1 = r;
  }
  | LIB register COMMA register COMMA register
  {
    int r1 = $<ival>2;
    int r2 = $<ival>4;
    int r3  = $<ival>6;
    iMem[iMem_addr].iop = LIB;
    iMem[iMem_addr].iarg1 = r1;
    iMem[iMem_addr].iarg2 = r2;
    iMem[iMem_addr].iarg3 = r3;
  }
  | FRD register COMMA register COMMA register
  {
    int r1 = $<ival>2;
    int r2 = $<ival>4;
    int r3  = $<ival>6;
    iMem[iMem_addr].iop = FRD;
    iMem[iMem_addr].iarg1 = r1;
    iMem[iMem_addr].iarg2 = r2;
    iMem[iMem_addr].iarg3 = r3;
  }
  | FWT register COMMA register COMMA register
  {
    int r1 = $<ival>2;
    int r2 = $<ival>4;
    int r3  = $<ival>6;
    iMem[iMem_addr].iop = FWT;
    iMem[iMem_addr].iarg1 = r1;
    iMem[iMem_addr].iarg2 = r2;
    iMem[iMem_addr].iarg3 = r3;
  }



;

iMem_address
  : INTNUM COLON
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
;

register
  : INTNUM
  {
    int r;
    sscanf(lex, "%d", &r);
    free(lex);
    if((r < 0) || (r > NO_REGS - 1)) {
      fprintf(stdout,"%d: bad register %d\n", iMem_addr, r);
      exit(1);
    }
    $<ival>$ = r;
  }
  | PC
  {
    $<ival>$ = PC_REG;
  }
  | GP
  {
    $<ival>$ = GP_REG;
  }
  | FP
  {
    $<ival>$ = FP_REG;
  }
  | SP
  {
    $<ival>$ = SP_REG;
  }
;

displacement
  : INTNUM
  {
    int d;
    sscanf(lex, "%d", &d);
    free(lex);
    $<ival>$ = d;
  }
;

empty
  :
;

%%

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
