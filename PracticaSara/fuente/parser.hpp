/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    TSEMIC = 258,
    TASSIG = 259,
    TDOSPUNTOS = 260,
    TCOMA = 261,
    TIDENTIFIER = 262,
    TINTEGER = 263,
    TFLOAT = 264,
    TLLAVEI = 265,
    TLLAVED = 266,
    TPARENI = 267,
    TPAREND = 268,
    TREF = 269,
    TEQUAL = 270,
    TMAYOR = 271,
    TMENOR = 272,
    TMAYOREQ = 273,
    TMENOREQ = 274,
    TNOTEQUAL = 275,
    TPLUS = 276,
    TMINUS = 277,
    TMUL = 278,
    TDIV = 279,
    TAND = 280,
    TOR = 281,
    TNOT = 282,
    RDEF = 283,
    RMAIN = 284,
    RIF = 285,
    RELSE = 286,
    RWHILE = 287,
    RFOREVER = 288,
    RBREAK = 289,
    RCONTINUE = 290,
    RREAD = 291,
    RPRINT = 292,
    RLET = 293,
    RIN = 294,
    RINTEGER = 295,
    RFLOAT = 296,
    TFOR = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 36 "parser.y" /* yacc.c:1909  */

    string *str ; 
    expresionstruct *expr;
    sentenciastruct *sen;
    int number;
    vector<string> *lid;
    vector<int> *numlist;

#line 106 "parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
