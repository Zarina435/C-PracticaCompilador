/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

   #include <stdio.h>
   #include <iostream>
   #include <vector>
   #include <string>
   using namespace std; 

   extern int yylex();
   extern int yylineno;
   extern char *yytext;
   void yyerror (const char *msg) {
     printf("line %d: %s at '%s'\n", yylineno, msg, yytext) ;
   }

   #include "Codigo.hpp"
   #include "Exp.hpp"
   #include "TablaSimbolos.hpp"
   #include "PilaTablaSimbolos.hpp"
   //#include "Aux.hpp"

   /* Funciones que se usan*/
   expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) ;
   expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) ;
   vector<int> *unir(vector<int> lis1, vector<int> lis2);
   vector<string> *unirStrings (vector<string> lis1, vector<string> lis2);

   Codigo codigo;
   PilaTablaSimbolos stPila;
   string procedimiento;
   bool errores= false;

#line 98 "parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
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
#line 36 "parser.y" /* yacc.c:355  */

    string *str ; 
    expresionstruct *expr;
    sentenciastruct *sen;
    int number;
    vector<string> *lid;
    vector<int> *numlist;

#line 190 "parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 207 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    89,   118,   133,   143,   144,   147,   159,
     173,   182,   188,   193,   197,   203,   204,   208,   207,   229,
     230,   234,   233,   250,   253,   257,   256,   271,   274,   282,
     289,   298,   311,   329,   337,   349,   358,   365,   374,   388,
     373,   425,   473,   476,   483,   489,   508,   525,   542,   561,
     580,   599,   616,   633,   649,   666,   679,   687,   695,   703,
     720,   737
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TSEMIC", "TASSIG", "TDOSPUNTOS",
  "TCOMA", "TIDENTIFIER", "TINTEGER", "TFLOAT", "TLLAVEI", "TLLAVED",
  "TPARENI", "TPAREND", "TREF", "TEQUAL", "TMAYOR", "TMENOR", "TMAYOREQ",
  "TMENOREQ", "TNOTEQUAL", "TPLUS", "TMINUS", "TMUL", "TDIV", "TAND",
  "TOR", "TNOT", "RDEF", "RMAIN", "RIF", "RELSE", "RWHILE", "RFOREVER",
  "RBREAK", "RCONTINUE", "RREAD", "RPRINT", "RLET", "RIN", "RINTEGER",
  "RFLOAT", "TFOR", "$accept", "programa", "$@1", "bloque_ppl", "bloque",
  "decl_bl", "declaraciones", "lista_de_ident", "resto_lista_id", "tipo",
  "decl_de_subprogs", "decl_de_subprograma", "$@2", "argumentos",
  "lista_de_param", "$@3", "clase_par", "resto_lis_de_param", "$@4",
  "lista_de_sentencias", "sentencia", "$@5", "$@6", "M", "N", "variable",
  "expresion", YY_NULLPTR
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
     295,   296,   297
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -22,    -9,    12,    14,  -120,    11,    22,  -120,    -8,    38,
    -120,    39,    42,     5,    47,    25,    48,  -120,    38,  -120,
     -31,    50,    44,    25,    42,    49,  -120,  -120,  -120,  -120,
      53,    55,  -120,    54,    30,    58,    57,    63,    71,    73,
      44,    62,  -120,  -120,   -31,    75,    78,  -120,  -120,  -120,
      55,    55,   183,    55,  -120,    55,  -120,    78,    55,   -31,
    -120,  -120,    55,  -120,    38,    83,  -120,    42,   219,    86,
    -120,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,  -120,  -120,   205,    79,   113,  -120,    77,   233,    85,
     137,    90,    84,    -8,    99,  -120,    79,   259,   150,   150,
     150,   150,   150,     8,     8,    81,    81,    55,    55,  -120,
      44,  -120,  -120,    95,   114,  -120,  -120,   104,  -120,  -120,
     116,  -120,    86,   126,    79,   109,  -120,  -120,  -120,   118,
    -120,   -31,  -120,  -120,  -120,  -120,  -120,    55,  -120,    93,
     259,   122,   170,   186,    38,  -120,  -120,  -120,   185,    79,
      55,   104,  -120,   161,   -31,  -120,    78,  -120,   187,   122,
      55,  -120,   247,   182,  -120,    44,  -120,   184,  -120,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     2,     7,     0,
       3,     0,    12,     0,     0,    16,     0,    10,     0,     6,
       0,     0,    29,    16,    12,     0,    13,    14,     9,    17,
      44,     0,    42,     0,     0,     0,     0,     0,     0,     0,
      29,     0,    15,    11,     0,    20,     0,    55,    56,    57,
       0,     0,     0,     0,    42,     0,    42,     0,     0,     0,
       4,    28,     0,     8,     0,     0,    44,    12,     0,    61,
      42,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42,    42,     0,     0,     0,    35,     0,     0,     0,
       0,     0,     0,     7,     0,    58,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,     0,     0,    42,
      29,    43,    34,     0,     0,    38,    30,    23,    19,    18,
       0,    42,    59,    60,     0,     0,    42,    36,    37,     0,
      24,     0,    41,    31,    43,     5,    33,     0,    21,     0,
      39,    27,     0,     0,     0,    22,    42,    42,     0,     0,
       0,    23,    42,     0,     0,    32,     0,    25,     0,    27,
       0,    26,     0,     0,    42,    29,    43,     0,    42,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,   100,   -91,  -120,  -120,   -18,   -17,   -40,
     171,  -120,  -120,  -120,  -120,  -120,    45,    52,  -120,   -38,
    -120,  -120,  -120,   -53,  -119,   -35,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     8,    10,   111,    11,    13,    14,    17,    28,
      22,    23,    45,    65,    92,   141,   131,   145,   159,    39,
      40,   129,   143,    53,   126,    41,    52
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    84,    61,    86,    63,   121,     1,    43,    18,    26,
      27,    67,     4,    68,    69,   139,    83,    96,    85,    89,
       3,    88,    87,    71,     6,    90,     5,     7,   107,   108,
       9,    79,    80,   134,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    19,    12,    91,   167,    16,    15,
      94,    30,    20,    21,    44,    24,   124,    29,   152,    54,
      55,    56,    47,    48,    49,    46,    62,    50,   133,    57,
     122,   123,   125,   136,    31,    58,    32,    33,    34,    35,
      36,    37,    51,    59,    60,    66,    38,    64,    93,   110,
     113,   138,   115,   149,   150,   117,    71,   118,   127,   155,
     140,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   165,   120,   153,   157,   169,   112,   128,   130,   132,
     135,   158,   137,   162,   142,   144,   148,   166,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     116,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   156,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,   146,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    70,   147,
     151,   160,   164,   119,    42,   168,   154,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     109,   161,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    95,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,   114,     0,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
     163,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
      18,    54,    40,    56,    44,    96,    28,    24,     3,    40,
      41,    46,     0,    50,    51,   134,    53,    70,    55,    59,
      29,    58,    57,    15,    13,    62,    12,     5,    81,    82,
      38,    23,    24,   124,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    39,     7,    64,   166,     6,    10,
      67,     7,     5,    28,     5,     7,   109,     7,   149,     5,
      30,     3,     7,     8,     9,    12,     4,    12,   121,    12,
     107,   108,   110,   126,    30,    12,    32,    33,    34,    35,
      36,    37,    27,    12,    11,     7,    42,    12,     5,    10,
      13,   131,     7,   146,   147,     5,    15,    13,     3,   152,
     137,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   164,    13,   150,   154,   168,     3,     3,    14,     3,
      11,   156,     4,   160,    31,     3,   144,   165,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       3,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,     3,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     5,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,     5,     3,
       5,     4,    10,    93,    23,    11,   151,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
       5,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    13,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    44,    29,     0,    12,    13,     5,    45,    38,
      46,    48,     7,    49,    50,    10,     6,    51,     3,    39,
       5,    28,    53,    54,     7,    50,    40,    41,    52,     7,
       7,    30,    32,    33,    34,    35,    36,    37,    42,    62,
      63,    68,    53,    51,     5,    55,    12,     7,     8,     9,
      12,    27,    69,    66,     5,    30,     3,    12,    12,    12,
      11,    62,     4,    52,    12,    56,     7,    68,    69,    69,
       5,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    69,    66,    69,    66,    68,    69,    52,
      69,    50,    57,     5,    51,    13,    66,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    66,    66,     5,
      10,    47,     3,    13,    13,     7,     3,     5,    13,    46,
      13,    47,    69,    69,    66,    62,    67,     3,     3,    64,
      14,    59,     3,    66,    47,    11,    66,     4,    52,    67,
      69,    58,    31,    65,     3,    60,     5,     3,    50,    66,
      66,     5,    47,    69,    59,    66,     3,    52,    68,    61,
       4,    60,    69,    13,    10,    66,    62,    67,    11,    66
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    45,    44,    46,    47,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    55,    54,    56,
      56,    58,    57,    59,    59,    61,    60,    60,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    64,    65,
      63,    63,    66,    67,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     7,     5,     3,     3,     0,     5,     3,
       2,     3,     0,     1,     1,     2,     0,     0,     6,     3,
       0,     0,     6,     0,     1,     0,     7,     0,     2,     0,
       4,     6,    12,     6,     4,     3,     5,     5,     0,     0,
      22,     6,     0,     0,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     3,     4,
       4,     2
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
#line 90 "parser.y" /* yacc.c:1646  */
    {
               TablaSimbolos st;
               st.anadirVariable(*(yyvsp[-4].str),"programa");
               stPila.empilar(st);

               codigo.anadirInstruccion("goto 5;");
               codigo.anadirInstruccion("Error en una división. No se puede dividir entre 0.;");
               codigo.anadirInstruccion("writeln;");
               codigo.anadirInstruccion("goto");
               codigo.anadirInstruccion("proc main");
            }
#line 1426 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "parser.y" /* yacc.c:1646  */
    {
               vector<int> tmp1; 
               tmp1.push_back(4);
               codigo.completarInstrucciones(tmp1, codigo.obtenRef());

               if(errores==false){
                  codigo.anadirInstruccion("halt");
                  codigo.escribir();
               }else{
                  YYABORT;
               }
               //stPila.tope().print();
               stPila.desempilar();
            }
#line 1445 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 122 "parser.y" /* yacc.c:1646  */
    {
			         if (!(yyvsp[-1].sen)->exits.empty()) {
				         yyerror("Error semántico. Break fuera de un bucle");
				         errores=true;
			         }else if (!(yyvsp[-1].sen)->continues.empty()) {
				         yyerror("Error semántico. Continue fuera de una estructura de control");
				         errores=true;;
			         }
               }
#line 1459 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 136 "parser.y" /* yacc.c:1646  */
    {
         (yyval.sen) = new sentenciastruct;
         (yyval.sen)->exits = (yyvsp[-1].sen)->exits;
         (yyval.sen)->continues = (yyvsp[-1].sen)->continues;
         }
#line 1469 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "parser.y" /* yacc.c:1646  */
    {
                     for(vector<string>::iterator i = (yyvsp[-2].lid)->begin(); i != (yyvsp[-2].lid)->end(); i++){
                        if (!stPila.tope().existeId(*i)){
                           stPila.tope().anadirVariable(*i, *(yyvsp[0].str));
                        }else{
                           yyerror("Id duplicado.");
                           errores=true;;
                        }
                     }
                     codigo.anadirDeclaraciones(*(yyvsp[-2].lid), *(yyvsp[0].str));
                  }
#line 1485 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 160 "parser.y" /* yacc.c:1646  */
    {
                     for(vector<string>::iterator i = (yyvsp[-2].lid)->begin(); i != (yyvsp[-2].lid)->end(); i++){
                        if (!stPila.tope().existeId(*i)){
                           stPila.tope().anadirVariable(*i, *(yyvsp[0].str));
                        }else{
                           yyerror("Id duplicado.");
                           errores=true;;
                        }
                     }
                     codigo.anadirDeclaraciones(*(yyvsp[-2].lid), *(yyvsp[0].str));
                  }
#line 1501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 174 "parser.y" /* yacc.c:1646  */
    {
                     (yyval.lid) = new vector<string>;
                     (yyval.lid) = (yyvsp[0].lid); //añadir resto_lista_id
                     (yyval.lid)->insert((yyval.lid)->begin(), *(yyvsp[-1].str)); //añadir al principio id
                  }
#line 1511 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 183 "parser.y" /* yacc.c:1646  */
    {
                     (yyval.lid)  = new vector<string>(*(yyvsp[0].lid));
                     (yyval.lid)->insert((yyval.lid)->begin(), *(yyvsp[-1].str));
                  }
#line 1520 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 188 "parser.y" /* yacc.c:1646  */
    {
                     (yyval.lid) = new vector<string>;
                  }
#line 1528 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 194 "parser.y" /* yacc.c:1646  */
    { 
         (yyval.str) = new std::string("int");
         }
#line 1536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 198 "parser.y" /* yacc.c:1646  */
    { 
         (yyval.str) = new std::string("real");
         }
#line 1544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 208 "parser.y" /* yacc.c:1646  */
    {  
                           procedimiento= *(yyvsp[0].str);
                           if (!stPila.tope().existeId(*(yyvsp[0].str))){
							         stPila.tope().anadirProcedimiento(*(yyvsp[0].str));
                           }else{
                              yyerror("Id duplicado.");
                              errores=true;;
                           }
                           TablaSimbolos st; 
						         stPila.empilar(st); 

                           codigo.anadirInstruccion("proc " + *(yyvsp[0].str)); 
                        }
#line 1562 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 222 "parser.y" /* yacc.c:1646  */
    { 
                           //stPila.tope().print();
                           stPila.desempilar();
                           codigo.anadirInstruccion("endproc " + *(yyvsp[-4].str)); 
                        }
#line 1572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 234 "parser.y" /* yacc.c:1646  */
    { 
                    for(vector<string>::iterator i = (yyvsp[-3].lid)->begin(); i != (yyvsp[-3].lid)->end(); i++){
                       if (!stPila.tope().existeId(*i)){
                          stPila.anadirParametro(procedimiento, *i, *(yyvsp[-1].str), *(yyvsp[0].str));
                       }else{
                           yyerror("Id duplicado.");
                           errores=true;;
                        }
                    }

                    codigo.anadirParametros(*(yyvsp[-3].lid), *(yyvsp[0].str), *(yyvsp[-1].str));
                  }
#line 1589 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 250 "parser.y" /* yacc.c:1646  */
    {
               (yyval.str) = new std::string("val");
            }
#line 1597 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 253 "parser.y" /* yacc.c:1646  */
    { (yyval.str) = new std::string("ref"); }
#line 1603 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 257 "parser.y" /* yacc.c:1646  */
    { 
                        for(vector<string>::iterator i = (yyvsp[-3].lid)->begin(); i != (yyvsp[-3].lid)->end(); i++){
                           if (!stPila.tope().existeId(*i)){
                              stPila.anadirParametro(procedimiento, *i, *(yyvsp[-1].str), *(yyvsp[0].str));
                           }else{
                              yyerror("Id duplicado.");
                              errores=true;;
                           }
                        }
                        
                        codigo.anadirParametros(*(yyvsp[-3].lid), *(yyvsp[0].str), *(yyvsp[-1].str));  
                     }
#line 1620 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 275 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.sen) = new sentenciastruct;
                        (yyval.sen)->exits = *unir((yyvsp[-1].sen)->exits, (yyvsp[0].sen)->exits);
                        (yyval.sen)->continues= *unir((yyvsp[-1].sen)->continues, (yyvsp[0].sen)->continues);
                        delete (yyvsp[-1].sen); delete (yyvsp[0].sen);
                     }
#line 1631 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 282 "parser.y" /* yacc.c:1646  */
    {  
                       (yyval.sen) = new sentenciastruct;
                       (yyval.sen)->exits = * new vector<int>;
                       (yyval.sen)->continues = * new vector<int>;
                     }
#line 1641 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 290 "parser.y" /* yacc.c:1646  */
    {
               (yyval.sen)= new sentenciastruct;
               codigo.anadirInstruccion(*(yyvsp[-3].str) + " := " + (yyvsp[-1].expr)->str + ";") ; 
               (yyval.sen)->exits = * new vector<int>;
               (yyval.sen)->continues = * new vector<int>;
               (yyval.sen)->tipo= "asignacion";
               delete (yyvsp[-3].str) ; delete (yyvsp[-1].expr);
            }
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 299 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-4].expr)->tipo != "comparacion" && (yyvsp[-4].expr)->tipo != "bool"){
                  yyerror("Error semántico en el if.");
                  errores=true;;
               }
               (yyval.sen) = new sentenciastruct;
	      	   codigo.completarInstrucciones((yyvsp[-4].expr)->trues,(yyvsp[-2].number));
    	  	      codigo.completarInstrucciones((yyvsp[-4].expr)->falses,(yyvsp[0].number));
	      	   (yyval.sen)->exits = (yyvsp[-1].sen)->exits;
               (yyval.sen)->continues = (yyvsp[-1].sen)->continues;
               //delete $2 ;
            }
#line 1671 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 312 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-9].expr)->tipo != "comparacion" && (yyvsp[-9].expr)->tipo != "bool"){
                  yyerror("Error semántico en el while.");
                  errores=true;;
               }
               (yyval.sen) = new sentenciastruct;
               (yyval.sen)->exits = * new vector<int>;
               (yyval.sen)->continues = * new vector<int>;
               
	      	   codigo.completarInstrucciones((yyvsp[-9].expr)->trues,(yyvsp[-7].number));
    	  	      codigo.completarInstrucciones((yyvsp[-9].expr)->falses,(yyvsp[-2].number));
               codigo.completarInstrucciones(*(yyvsp[-5].numlist),(yyvsp[-10].number));
               codigo.completarInstrucciones((yyvsp[-6].sen)->exits, (yyvsp[-2].number));
               codigo.completarInstrucciones((yyvsp[-6].sen)->continues, (yyvsp[-10].number));
               codigo.completarInstrucciones((yyvsp[-1].sen)->exits, (yyvsp[0].number));
               codigo.completarInstrucciones((yyvsp[-1].sen)->continues, (yyvsp[-10].number));
            }
#line 1693 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 330 "parser.y" /* yacc.c:1646  */
    {
               (yyval.sen) = new sentenciastruct;
               codigo.completarInstrucciones(*(yyvsp[-1].numlist), (yyvsp[-3].number));
               codigo.completarInstrucciones((yyvsp[-2].sen)->exits, codigo.obtenRef());
               (yyval.sen)->exits = * new vector<int>;
               (yyval.sen)->continues = (yyvsp[-2].sen)->continues;
            }
#line 1705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 338 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-1].expr)->tipo != "comparacion" && (yyvsp[-1].expr)->tipo != "bool"){
                  yyerror("Error semántico en break.");
                  errores=true;;
               }
               (yyval.sen) = new sentenciastruct;
               codigo.completarInstrucciones((yyvsp[-1].expr)->falses, codigo.obtenRef());
               (yyval.sen)->exits =  * new vector<int>((yyvsp[-1].expr)->trues);
               (yyval.sen)->continues = * new vector<int>;
               delete (yyvsp[-2].str);
            }
#line 1721 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 350 "parser.y" /* yacc.c:1646  */
    {
               (yyval.sen) = new sentenciastruct;
               codigo.anadirInstruccion("goto");
               (yyval.sen)->exits = * new vector<int>;
               
               vector<int> tmp1 ; tmp1.push_back((yyvsp[0].number)) ;
               (yyval.sen)->continues = tmp1;
            }
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 359 "parser.y" /* yacc.c:1646  */
    {
               (yyval.sen) = new sentenciastruct;
					(yyval.sen)->exits = * new vector<int>;
               (yyval.sen)->continues = * new vector<int>;
					codigo.anadirInstruccion("read "+ *(yyvsp[-2].str) + ";");
            }
#line 1745 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 366 "parser.y" /* yacc.c:1646  */
    {
               (yyval.sen) = new sentenciastruct;
					(yyval.sen)->exits = * new vector<int>;
               (yyval.sen)->continues = * new vector<int>;
					codigo.anadirInstruccion("write "+ (yyvsp[-2].expr)->str + ";");
					codigo.anadirInstruccion("writeln;");
            }
#line 1757 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 374 "parser.y" /* yacc.c:1646  */
    {
               if (stPila.tope().existeId(*(yyvsp[0].str))){
						yyerror("Error en el for. El id ya existe.");
                  errores=true;
					}else{
                  stPila.tope().anadirVariable(*(yyvsp[0].str),*(yyvsp[-1].str));
                  //stPila.tope().print();
                  /*TablaSimbolos st;
                  stPila.empilar(st);*/
                  
               }
               codigo.anadirInstruccion(*(yyvsp[-1].str) + " "+ *(yyvsp[0].str) );
            }
#line 1775 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 388 "parser.y" /* yacc.c:1646  */
    {
               //Asignar la variable
               if ((yyvsp[0].expr)->tipo != "numero" && (yyvsp[0].expr)->tipo != "variable" && (yyvsp[0].expr)->tipo!= "operacion"){
                  yyerror("Error semántico en el for. La primera asignación expresiṕn no puede ser un booleano ni una comparación.");
                  errores=true;
               }
               codigo.anadirInstruccion(*(yyvsp[-3].str) +*(yyvsp[-1].str) + (yyvsp[0].expr)->str);
            }
#line 1788 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 397 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-11].expr)->tipo != "comparacion" && (yyvsp[-11].expr)->tipo != "bool"){
                  yyerror("Error semántico en el for. La expresiṕn no puede ser una operación.");
                  errores=true;
               }else if (*(yyvsp[-18].str) != *(yyvsp[-9].str)) {
			         yyerror("Error semántico en el for. Se debe actualizar la variable de la expresión.");
                  errores=true;
               }
               if ( (yyvsp[-7].expr)->tipo!= "operacion"){
                  yyerror("Error semántico en el for. La actualización de la variable debe ser una operación");
                  errores=true;
               }
               else{
                  codigo.completarInstrucciones((yyvsp[-11].expr)->trues, (yyvsp[-4].number));
                  codigo.completarInstrucciones((yyvsp[-11].expr)->falses, (yyvsp[0].number));
                  //codigo.anadirInstruccion("goto" +$10);
                  codigo.completarInstrucciones(*(yyvsp[-2].numlist), (yyvsp[-12].number));
                  codigo.anadirInstruccion(*(yyvsp[-9].str) +":=" +(yyvsp[-7].expr)->str);

                  codigo.completarInstrucciones((yyvsp[-3].sen)->exits, (yyvsp[0].number));
                  codigo.completarInstrucciones((yyvsp[-3].sen)->continues, (yyvsp[-12].number));

                  (yyval.sen)= new sentenciastruct;
                  (yyval.sen)->exits = * new vector<int>;
                  (yyval.sen)->continues = * new vector<int>;

               }                
            }
#line 1821 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 426 "parser.y" /* yacc.c:1646  */
    {  
                  //stPila.tope().print();
         
                  (yyval.sen) = new sentenciastruct;
                  (yyval.sen)->exits = * new vector<int>;
                  (yyval.sen)->continues = * new vector<int>;
                  
                  vector<string> tmp1 ; 
                  tmp1.push_back(*(yyvsp[-3].str)) ;
                  if ((yyvsp[-2].lid)->size() > 0){
                     tmp1 = *unirStrings(*(yyvsp[-2].lid),tmp1); 
                  }
                  
                  if (!stPila.tope().existeId(*(yyvsp[-5].str))){
                     yyerror(" Error. No existe esa función");
                     errores=true;
                  }else{

                     bool argumentosIguales=stPila.verificarNumArgs(*(yyvsp[-5].str),tmp1.size());
                     if(argumentosIguales==false){
                        yyerror(" Error. Número de argumentos diferente.");
                        errores=true;
                     }else{
                        //Declaraciones para el for
                        vector<string>::const_iterator iter;
                        int x;

                        for ( iter=tmp1.end()-1, x = 0; iter!=tmp1.begin()-1; iter--, x++) {
                           pair<string, string> tiposDoble;
                           string tipo=stPila.obtenerTipo(*iter);

                           tiposDoble = stPila.obtenerTiposParametro(*(yyvsp[-5].str), x);
                           tipo = stPila.obtenerTipo(*iter);
                           if (tipo.compare(tiposDoble.second) != 0){
                              yyerror("Error semántico en la llamada a la función. Tipos incompatibles");
                              errores= true;
                           }else{
                              codigo.anadirInstruccion("param_" + tiposDoble.first + " " + *iter + ";");
                           }
                        }
                        codigo.anadirInstruccion("call "+*(yyvsp[-5].str)+";");
                     }
                  }
            }
#line 1870 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 473 "parser.y" /* yacc.c:1646  */
    { (yyval.number) = codigo.obtenRef(); }
#line 1876 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 476 "parser.y" /* yacc.c:1646  */
    { 
      (yyval.numlist) = new vector<int>;    
      vector<int> tmp1 ; tmp1.push_back(codigo.obtenRef()) ;
      *(yyval.numlist) = tmp1;
      codigo.anadirInstruccion("goto");
   }
#line 1887 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 484 "parser.y" /* yacc.c:1646  */
    {
               (yyval.str)= (yyvsp[0].str);
            }
#line 1895 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 490 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }

               (yyval.expr)= new expresionstruct;
               (yyval.expr)->str= "";
               (yyval.expr)->trues = * new vector<int>(codigo.obtenRef());
               (yyval.expr)->falses = * new vector<int>(codigo.obtenRef()+1);
               *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str); 
               (yyval.expr)->tipo= "comparacion";

            }
#line 1918 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 509 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->str= "";
               (yyval.expr)->trues = * new vector<int>(codigo.obtenRef());
               (yyval.expr)->falses = * new vector<int>(codigo.obtenRef()+1);
               *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str); 
               (yyval.expr)->tipo= "comparacion";
            }
#line 1939 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 526 "parser.y" /* yacc.c:1646  */
    {
                if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->str= "";
               (yyval.expr)->trues = * new vector<int>(codigo.obtenRef());
               (yyval.expr)->falses = * new vector<int>(codigo.obtenRef()+1);
               *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str);
               (yyval.expr)->tipo= "comparacion"; 
            }
#line 1960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 543 "parser.y" /* yacc.c:1646  */
    {
                if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }

               (yyval.expr)= new expresionstruct;
               (yyval.expr)->str= "";
               (yyval.expr)->trues = * new vector<int>(codigo.obtenRef());
               (yyval.expr)->falses = * new vector<int>(codigo.obtenRef()+1);
               *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str); 
               (yyval.expr)->tipo= "comparacion"; 

            }
#line 1983 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 562 "parser.y" /* yacc.c:1646  */
    {
                if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }

               (yyval.expr)= new expresionstruct;
               (yyval.expr)->str= "";
               (yyval.expr)->trues = * new vector<int>(codigo.obtenRef());
               (yyval.expr)->falses = * new vector<int>(codigo.obtenRef()+1);
               *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str);
               (yyval.expr)->tipo= "comparacion"; 

            }
#line 2006 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 581 "parser.y" /* yacc.c:1646  */
    {
                if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }

               (yyval.expr)= new expresionstruct;
               (yyval.expr)->str= "";
               (yyval.expr)->trues = * new vector<int>(codigo.obtenRef());
               (yyval.expr)->falses = * new vector<int>(codigo.obtenRef()+1);
               *(yyval.expr) = makecomparison((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str); 
               (yyval.expr)->tipo= "comparacion";

            }
#line 2029 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 600 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = * new vector<int>;
               (yyval.expr)->falses = * new vector<int>;
               *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str);
               (yyval.expr)->tipo= "operacion"; 

            }
#line 2050 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 617 "parser.y" /* yacc.c:1646  */
    {
                if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = * new vector<int>;
               (yyval.expr)->falses = * new vector<int>;
               *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str); 
               (yyval.expr)->tipo= "operacion";

            }
#line 2071 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 634 "parser.y" /* yacc.c:1646  */
    {
                if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = * new vector<int>;
               (yyval.expr)->falses = * new vector<int>;
               *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str);
               (yyval.expr)->tipo= "operacion";
            }
#line 2091 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 650 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-2].expr)->tipo== "bool" || (yyvsp[-2].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo== "bool" || (yyvsp[0].expr)->tipo=="comparacion"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               codigo.anadirInstruccion("if "+ (yyvsp[0].expr)->str + " = 0 goto 2;");
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = * new vector<int>;
               (yyval.expr)->falses = * new vector<int>;
               *(yyval.expr) = makearithmetic((yyvsp[-2].expr)->str,*(yyvsp[-1].str),(yyvsp[0].expr)->str); 
               (yyval.expr)->tipo= "operacion";
            }
#line 2112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 668 "parser.y" /* yacc.c:1646  */
    {  if (!stPila.tope().existeId(*(yyvsp[0].str))){
               //stPila.tope().print();
						yyerror(" El id es inexistente.");
                  errores=true;
					}
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = * new vector<int>;
               (yyval.expr)->falses = * new vector<int>;
               (yyval.expr)->tipo = "variable";
               (yyval.expr)->str= *(yyvsp[0].str);
            }
#line 2128 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 680 "parser.y" /* yacc.c:1646  */
    {
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = * new vector<int>;
               (yyval.expr)->falses = * new vector<int>;
               (yyval.expr)->str = *(yyvsp[0].str);
               (yyval.expr)->tipo= "numero";
            }
#line 2140 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 688 "parser.y" /* yacc.c:1646  */
    {
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = * new vector<int>;
               (yyval.expr)->falses = * new vector<int>;
               (yyval.expr)->str = *(yyvsp[0].str);
               (yyval.expr)->tipo= "numero";
            }
#line 2152 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 696 "parser.y" /* yacc.c:1646  */
    {
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = (yyvsp[-1].expr)->trues;
               (yyval.expr)->falses = (yyvsp[-1].expr)->falses;
               (yyval.expr)->str = (yyvsp[-1].expr)->str;
               (yyval.expr)->tipo= (yyvsp[-1].expr)->tipo;
            }
#line 2164 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 704 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-3].expr)->tipo!= "comparacion" && (yyvsp[-3].expr)->tipo!="bool" ){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo!= "comparacion" && (yyvsp[0].expr)->tipo!="bool"){
                  yyerror("Tipos incompatibles");
                 errores=true;
               }
               (yyval.expr)= new expresionstruct;
               codigo.completarInstrucciones((yyvsp[-3].expr)->trues, (yyvsp[-1].number));
               (yyval.expr)->trues = (yyvsp[0].expr)->trues;
               (yyval.expr)->falses = *unir((yyvsp[-3].expr)->falses, (yyvsp[0].expr)->falses);
               (yyval.expr)->str= "";
               (yyval.expr)->tipo= "bool";
            }
#line 2185 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 721 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[-3].expr)->tipo!= "comparacion" && (yyvsp[-3].expr)->tipo!="bool"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               if ((yyvsp[0].expr)->tipo!= "comparacion" && (yyvsp[0].expr)->tipo!="bool"){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               (yyval.expr)= new expresionstruct;
               codigo.completarInstrucciones((yyvsp[-3].expr)->falses, (yyvsp[-1].number));
               (yyval.expr)->trues = *unir((yyvsp[-3].expr)->trues, (yyvsp[0].expr)->trues);
               (yyval.expr)->falses = (yyvsp[0].expr)->falses;
               (yyval.expr)->str= "";
               (yyval.expr)->tipo= "bool";
            }
#line 2206 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 738 "parser.y" /* yacc.c:1646  */
    {
               if ((yyvsp[0].expr)->tipo!= "comparacion" && (yyvsp[0].expr)->tipo!="bool" ){
                  yyerror("Tipos incompatibles");
                  errores=true;
               }
               (yyval.expr)= new expresionstruct;
               (yyval.expr)->trues = (yyvsp[0].expr)->falses;
               (yyval.expr)->falses = (yyvsp[0].expr)->trues;
               (yyval.expr)->str= "";
               (yyval.expr)->tipo= "bool";
            }
#line 2222 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2226 "parser.cpp" /* yacc.c:1646  */
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
#line 750 "parser.y" /* yacc.c:1906  */


expresionstruct makecomparison(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 

  tmp.trues.push_back(codigo.obtenRef()) ;
  tmp.falses.push_back(codigo.obtenRef()+1);
  codigo.anadirInstruccion("if " + s1 + " " + s2 + " " + s3 + " goto") ;
  codigo.anadirInstruccion("goto") ;
  return tmp ;
}

expresionstruct makearithmetic(std::string &s1, std::string &s2, std::string &s3) {
  expresionstruct tmp ; 

  tmp.str = codigo.nuevoId() ;

  codigo.anadirInstruccion(tmp.str + " := " + s1 + " " +  s2 + " " +  s3 + ";") ;
  return tmp ;
}

vector<int> *unir(vector<int> lis1, vector<int> lis2){
        vector<int> *aux;
        aux = new vector<int>(lis1);

        aux->insert(aux->end(), lis2.begin(), lis2.end());
        return aux;
}
vector<string> *unirStrings (vector<string> lis1, vector<string> lis2){
        vector<string> *aux;
        aux = new vector<string>(lis1);

        aux->insert(aux->end(), lis2.begin(), lis2.end());
        return aux;
}
