/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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
#line 142 "parser.y" /* yacc.c:1909  */

  l_type lval;
  t_type tval;
  o_type oval;
  r_type rval;
  p_type pval;

#line 124 "parser.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
