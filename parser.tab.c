
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv.h"
#include "tabela.h"
#include "quads.h"      // Incluir o cabeçalho das quádruplas
#include "gen_code.h"   // Incluir o cabeçalho da geração de código

extern int yylex(void);
extern FILE *yyin;
extern int yylineno;
extern char *yytext;

void yyerror(char *s) {fprintf(stderr, "ERRO SINTATICO: %s LINHA: %d\n", yytext, yylineno);}

void erro_semantico(char *msg, char *id, int linha) {
    fprintf(stderr, "ERRO SEMANTICO: %s '%s' LINHA: %d\n", msg, id, linha);
}

tabela *T = NULL;
NO *raiz = NULL;
int tm_tab = 0;
char *escopo_at = "global";
char *funcao_at = NULL;



/* Line 189 of yacc.c  */
#line 102 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUM = 259,
     INT = 260,
     VOID = 261,
     WHILE = 262,
     RETURN = 263,
     PEV = 264,
     VIR = 265,
     SUB = 266,
     SOM = 267,
     DIV = 268,
     MUL = 269,
     FCH = 270,
     ACH = 271,
     FCO = 272,
     ACO = 273,
     FPR = 274,
     APR = 275,
     ELSE = 276,
     IF = 277,
     ATR = 278,
     DIF = 279,
     IGU = 280,
     MAI = 281,
     MAR = 282,
     MEI = 283,
     MEN = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 29 "parser.y"

    char *string;
    NO *no;
    char *tipo;



/* Line 214 of yacc.c  */
#line 175 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 187 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   211

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    12,    16,    18,    20,    22,
      26,    33,    37,    39,    41,    42,    50,    57,    63,    65,
      67,    69,    70,    74,    78,    82,    84,    87,    92,    95,
     100,   104,   107,   108,   111,   115,   119,   123,   124,   126,
     128,   130,   132,   134,   137,   139,   142,   148,   154,   158,
     166,   174,   180,   186,   190,   193,   197,   201,   205,   207,
     212,   214,   219,   224,   228,   230,   234,   236,   238,   240,
     242,   244,   246,   250,   254,   256,   260,   264,   268,   272,
     274,   278,   282,   284,   286,   290,   295,   299,   304,   306,
     307,   311,   313,   317,   321
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      31,     0,    -1,    32,    -1,    32,    33,    -1,    32,     1,
       9,    -1,    32,     1,    15,    -1,    33,    -1,    34,    -1,
      36,    -1,    35,     3,     9,    -1,    35,     3,    18,     4,
      17,     9,    -1,    35,     1,     9,    -1,     5,    -1,     6,
      -1,    -1,    35,     3,    20,    37,    38,    19,    41,    -1,
      35,     3,    20,     1,    19,    41,    -1,    35,     3,    20,
       1,    15,    -1,    39,    -1,     6,    -1,     1,    -1,    -1,
      39,    10,    40,    -1,    39,     1,    10,    -1,    39,     1,
      19,    -1,    40,    -1,    35,     3,    -1,    35,     3,    18,
      17,    -1,    35,     1,    -1,    16,    42,    43,    15,    -1,
      16,     1,    15,    -1,    42,    34,    -1,    -1,    43,    44,
      -1,    43,     1,     9,    -1,    43,     1,    15,    -1,    43,
       1,    19,    -1,    -1,    45,    -1,    41,    -1,    46,    -1,
      47,    -1,    48,    -1,    49,     9,    -1,     9,    -1,     1,
       9,    -1,    22,    20,    49,    19,    44,    -1,    22,    20,
       1,    19,    44,    -1,    22,     1,    44,    -1,    22,    20,
      49,    19,    44,    21,    44,    -1,    22,    20,     1,    19,
      44,    21,    44,    -1,     7,    20,    49,    19,    44,    -1,
       7,    20,     1,    19,    44,    -1,     7,     1,    44,    -1,
       8,     9,    -1,     8,    49,     9,    -1,     8,     1,     9,
      -1,    50,    23,    49,    -1,    51,    -1,    50,    23,     1,
       9,    -1,     3,    -1,     3,    18,    49,    17,    -1,     3,
      18,     1,    17,    -1,    53,    52,    53,    -1,    53,    -1,
      51,    52,     1,    -1,    29,    -1,    28,    -1,    27,    -1,
      26,    -1,    25,    -1,    24,    -1,    53,    12,    54,    -1,
      53,    11,    54,    -1,    54,    -1,    53,    12,     1,    -1,
      53,    11,     1,    -1,    54,    14,    55,    -1,    54,    13,
      55,    -1,    55,    -1,    54,    14,     1,    -1,    54,    13,
       1,    -1,     4,    -1,    50,    -1,    20,    49,    19,    -1,
       3,    20,    56,    19,    -1,    20,     1,    19,    -1,     3,
      20,     1,    19,    -1,    57,    -1,    -1,    57,    10,    49,
      -1,    49,    -1,    57,     1,    10,    -1,    57,     1,    19,
      -1,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    68,    71,    72,    73,    79,    82,    88,
      96,   104,   108,   109,   113,   113,   133,   134,   138,   141,
     144,   145,   151,   154,   155,   156,   162,   170,   178,   182,
     185,   189,   192,   198,   201,   202,   203,   204,   210,   213,
     216,   219,   222,   228,   231,   234,   238,   244,   245,   246,
     252,   256,   262,   263,   267,   277,   288,   292,   302,   305,
     309,   324,   345,   349,   358,   361,   365,   366,   367,   368,
     369,   370,   374,   380,   386,   389,   390,   394,   402,   408,
     411,   412,   416,   419,   422,   426,   440,   441,   445,   448,
     454,   457,   460,   461,   462
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUM", "INT", "VOID", "WHILE",
  "RETURN", "PEV", "VIR", "SUB", "SOM", "DIV", "MUL", "FCH", "ACH", "FCO",
  "ACO", "FPR", "APR", "ELSE", "IF", "ATR", "DIF", "IGU", "MAI", "MAR",
  "MEI", "MEN", "$accept", "programa", "declaracao_lista", "declaracao",
  "var_declaracao", "tipo_especificador", "fun_declaracao", "$@1",
  "params", "param_lista", "param", "composto_declaracao",
  "local_declaracoes", "statement_lista", "statement",
  "expressao_declaracao", "selecao_declaracao", "iteracao_declaracao",
  "retorno_declaracao", "expressao", "var", "simples_expressao",
  "relacional", "soma_expressao", "termo", "fator", "args", "arg_lista", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    32,    32,    32,    32,    33,    33,    34,
      34,    34,    35,    35,    37,    36,    36,    36,    38,    38,
      38,    38,    39,    39,    39,    39,    40,    40,    40,    41,
      41,    42,    42,    43,    43,    43,    43,    43,    44,    44,
      44,    44,    44,    45,    45,    45,    46,    46,    46,    46,
      46,    47,    47,    47,    48,    48,    48,    49,    49,    49,
      50,    50,    50,    51,    51,    51,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    54,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      57,    57,    57,    57,    57
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     3,     3,     1,     1,     1,     3,
       6,     3,     1,     1,     0,     7,     6,     5,     1,     1,
       1,     0,     3,     3,     3,     1,     2,     4,     2,     4,
       3,     2,     0,     2,     3,     3,     3,     0,     1,     1,
       1,     1,     1,     2,     1,     2,     5,     5,     3,     7,
       7,     5,     5,     3,     2,     3,     3,     3,     1,     4,
       1,     4,     4,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     1,     3,     4,     3,     4,     1,     0,
       3,     1,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,     0,     0,     6,     7,     0,     8,     1,
       0,     3,     0,     0,     4,     5,    11,     9,     0,     0,
       0,     0,     0,     0,    17,     0,    20,    13,     0,     0,
       0,    25,    10,     0,    16,    28,    26,     0,     0,     0,
       0,    37,     0,    15,    23,    24,    22,    30,    31,     0,
       0,    27,     0,     0,    60,    82,     0,     0,    44,    29,
       0,     0,    39,    33,    38,    40,    41,    42,     0,    83,
      58,    64,    74,    79,    34,    35,    36,     0,     0,     0,
       0,     0,    54,     0,     0,     0,     0,     0,    43,     0,
      71,    70,    69,    68,    67,    66,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    91,     0,     0,     0,    53,
       0,     0,    56,    55,    86,    84,    48,     0,     0,     0,
      57,    65,    76,    83,    73,    75,    72,    63,    81,    78,
      80,    77,    62,    61,    87,    85,     0,     0,    45,     0,
       0,     0,     0,    59,    92,    93,    90,    52,    51,    47,
      46,     0,     0,    50,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    22,    29,    30,
      31,    62,    41,    50,    63,    64,    65,    66,    67,    68,
      69,    70,    96,    71,    72,    73,   106,   107
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -79
static const yytype_int16 yypact[] =
{
     173,   -79,   -79,     4,   160,   -79,   -79,    64,   -79,   -79,
      36,   -79,    -2,   134,   -79,   -79,   -79,   -79,    30,   130,
      33,    51,   132,    59,   -79,    62,   -79,    75,   155,   123,
     131,   -79,   -79,     9,   -79,   -79,    86,    62,    -8,   173,
     171,   173,   112,   -79,   -79,   -79,   -79,   -79,   -79,   161,
      32,   -79,    35,   144,   127,   -79,    18,    78,   -79,   -79,
      88,    26,   -79,   -79,   -79,   -79,   -79,   -79,   178,   165,
     143,    31,   167,   -79,   -79,   -79,   -79,    92,    82,    68,
      96,   180,   -79,   181,   172,   174,    68,   102,   -79,   106,
     -79,   -79,   -79,   -79,   -79,   -79,   191,   110,   114,     2,
     120,   124,   177,   179,   176,   -79,   182,   138,   188,   -79,
     183,   184,   -79,   -79,   -79,   -79,   -79,   185,   186,   189,
     -79,   -79,   -79,   -79,   167,   -79,   167,   108,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   136,     2,   -79,    68,
      68,    68,    68,   -79,   -79,   -79,   -79,   -79,   -79,   187,
     190,    68,    68,   -79,   -79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   195,   159,   -13,   -79,   -79,   -79,   -79,
     168,    12,   -79,   -79,   -78,   -79,   -79,   -79,   -79,   -57,
      76,   -79,   135,   111,    85,    84,   -79,   -79
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -90
static const yytype_int16 yytable[] =
{
      83,   109,    44,    85,     9,    54,    55,    16,   116,    28,
      40,    45,   -32,   -32,   -32,   -32,   -32,   -32,   -32,    79,
     103,   105,    60,   111,   -32,   -32,    28,    86,    49,   -32,
     118,   -32,   120,    53,    20,    54,    55,    34,    80,    56,
      57,    58,    97,    98,    17,    14,    87,    59,    33,    43,
      23,    15,    60,    18,    61,    90,    91,    92,    93,    94,
      95,   147,   148,   149,   150,    12,    24,    13,    32,   108,
      25,    54,    55,   153,   154,    56,    57,    58,    33,    81,
     146,    54,    55,   104,    33,    54,    55,    82,    60,    84,
      61,    54,    55,   102,   -19,    54,    55,   110,    60,    54,
      55,   -89,    60,   117,    42,    54,    55,   119,    60,    54,
      55,   122,    60,    54,    55,   125,    60,    54,    55,    97,
      98,   128,    60,    54,    55,   130,    60,    54,    55,    51,
      60,    21,    38,    26,    60,   -14,   -14,     1,    27,   136,
      60,    39,    37,    17,    60,    77,   144,    78,   137,   -14,
     -18,   -21,    18,    74,    19,   145,    35,   -88,    36,    75,
      -2,    10,    12,    76,    52,     1,     2,    90,    91,    92,
      93,    94,    95,   123,   123,   123,   123,   123,     1,     2,
     100,   101,   124,   126,   129,   131,    47,    88,    89,   112,
     113,   114,   121,   115,   132,   134,   133,   138,   143,    11,
      48,   135,   139,   140,   141,   142,    99,    46,   151,     0,
     127,   152
};

static const yytype_int16 yycheck[] =
{
      57,    79,    10,    60,     0,     3,     4,     9,    86,    22,
       1,    19,     3,     4,     5,     6,     7,     8,     9,     1,
      77,    78,    20,    80,    15,    16,    39,     1,    41,    20,
      87,    22,    89,     1,     4,     3,     4,    25,    20,     7,
       8,     9,    11,    12,     9,     9,    20,    15,    16,    37,
      17,    15,    20,    18,    22,    24,    25,    26,    27,    28,
      29,   139,   140,   141,   142,     1,    15,     3,     9,     1,
      19,     3,     4,   151,   152,     7,     8,     9,    16,     1,
     137,     3,     4,     1,    16,     3,     4,     9,    20,     1,
      22,     3,     4,     1,    19,     3,     4,     1,    20,     3,
       4,    19,    20,     1,    18,     3,     4,     1,    20,     3,
       4,     1,    20,     3,     4,     1,    20,     3,     4,    11,
      12,     1,    20,     3,     4,     1,    20,     3,     4,    17,
      20,     1,     1,     1,    20,     5,     6,     5,     6,     1,
      20,    10,    19,     9,    20,    18,    10,    20,    10,    19,
      19,    19,    18,     9,    20,    19,     1,    19,     3,    15,
       0,     1,     1,    19,     3,     5,     6,    24,    25,    26,
      27,    28,    29,    97,    98,    99,   100,   101,     5,     6,
      13,    14,    97,    98,   100,   101,    15,     9,    23,     9,
       9,    19,     1,    19,    17,    19,    17,     9,     9,     4,
      41,    19,    19,    19,    19,    19,    71,    39,    21,    -1,
      99,    21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    31,    32,    33,    34,    35,    36,     0,
       1,    33,     1,     3,     9,    15,     9,     9,    18,    20,
       4,     1,    37,    17,    15,    19,     1,     6,    35,    38,
      39,    40,     9,    16,    41,     1,     3,    19,     1,    10,
       1,    42,    18,    41,    10,    19,    40,    15,    34,    35,
      43,    17,     3,     1,     3,     4,     7,     8,     9,    15,
      20,    22,    41,    44,    45,    46,    47,    48,    49,    50,
      51,    53,    54,    55,     9,    15,    19,    18,    20,     1,
      20,     1,     9,    49,     1,    49,     1,    20,     9,    23,
      24,    25,    26,    27,    28,    29,    52,    11,    12,    52,
      13,    14,     1,    49,     1,    49,    56,    57,     1,    44,
       1,    49,     9,     9,    19,    19,    44,     1,    49,     1,
      49,     1,     1,    50,    54,     1,    54,    53,     1,    55,
       1,    55,    17,    17,    19,    19,     1,    10,     9,    19,
      19,    19,    19,     9,    10,    19,    49,    44,    44,    44,
      44,    21,    21,    44,    44
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 61 "parser.y"
    {
        (yyval.no) = novo(PrgK, "programa", NULL, 1, (yyvsp[(1) - (1)].no));
        raiz = (yyval.no);
    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    {
        (yyval.no) = novo(PrgK, "declaracao_lista", NULL, 2, (yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no));
    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { yyerrok; (yyval.no) = (yyvsp[(1) - (3)].no); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 72 "parser.y"
    { yyerrok; (yyval.no) = (yyvsp[(1) - (3)].no); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 73 "parser.y"
    {
        (yyval.no) = novo(PrgK, "declaracao_lista_single", NULL, 1, (yyvsp[(1) - (1)].no));
    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {
        if (busca(T, tm_tab, (yyvsp[(2) - (3)].string), escopo_at) != -1) {
            erro_semantico("Variavel ja declarada", (yyvsp[(2) - (3)].string), yylineno);
        } else {
            add(&T, &tm_tab, strdup((yyvsp[(2) - (3)].string)), "var", (yyvsp[(1) - (3)].tipo), yylineno, escopo_at);
        }
        (yyval.no) = novo(PrgK, "var_declaracao", (yyvsp[(1) - (3)].tipo), 2, novo(IdK, strdup((yyvsp[(2) - (3)].string)), (yyvsp[(1) - (3)].tipo), 0), novo(IdK, strdup((yyvsp[(2) - (3)].string)), "id", 0));
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {
        if (busca(T, tm_tab, (yyvsp[(2) - (6)].string), escopo_at) != -1) {
            erro_semantico("Array ja declarado", (yyvsp[(2) - (6)].string), yylineno);
        } else {
            add(&T, &tm_tab, strdup((yyvsp[(2) - (6)].string)), "array", (yyvsp[(1) - (6)].tipo), yylineno, escopo_at);
        }
        (yyval.no) = novo(PrgK, "var_declaracao_array", (yyvsp[(1) - (6)].tipo), 3, novo(IdK, strdup((yyvsp[(2) - (6)].string)), (yyvsp[(1) - (6)].tipo), 0), novo(IdK, strdup((yyvsp[(2) - (6)].string)), "id", 0), novo(ConstK, strdup((yyvsp[(4) - (6)].string)), "int", 0));
    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    { yyerrok; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    { (yyval.tipo) = strdup("int"); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 109 "parser.y"
    { (yyval.tipo) = strdup("void"); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {
        char *current_func_name = strdup((yyvsp[(2) - (3)].string));
        funcao_at = current_func_name;
        escopo_at = current_func_name;

        if (busca(T, tm_tab, current_func_name, "global") != -1) {
            erro_semantico("Funcao ja declarada", current_func_name, yylineno);
        } else {
            add(&T, &tm_tab, current_func_name, "func", (yyvsp[(1) - (3)].tipo), yylineno, "global");
        }
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {
        (yyval.no) = novo(FnK, strdup(funcao_at), (yyvsp[(1) - (7)].tipo), 2, (yyvsp[(5) - (7)].no), (yyvsp[(7) - (7)].no));

        escopo_at = "global";
        if (funcao_at != NULL) {
            free(funcao_at);
            funcao_at = NULL;
        }
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    { yyerrok; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    { yyerrok; ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {
        (yyval.no) = novo(PrgK, "void_params", "void", 0);
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {yyerrok;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {
        (yyval.no) = novo(PrgK, "empty_params", NULL, 0);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {
        (yyval.no) = novo(PrgK, "param_list", NULL, 2, (yyvsp[(1) - (3)].no), (yyvsp[(3) - (3)].no));
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    { yyerrok; ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    { yyerrok; ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {
        if (busca(T, tm_tab, (yyvsp[(2) - (2)].string), escopo_at) != -1) {
            erro_semantico("Parametro ja declarado", (yyvsp[(2) - (2)].string), yylineno);
        } else {
            add(&T, &tm_tab, strdup((yyvsp[(2) - (2)].string)), "parametro", (yyvsp[(1) - (2)].tipo), yylineno, escopo_at);
        }
        (yyval.no) = novo(ParamK, strdup((yyvsp[(2) - (2)].string)), (yyvsp[(1) - (2)].tipo), 0);
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {
        if (busca(T, tm_tab, (yyvsp[(2) - (4)].string), escopo_at) != -1) {
            erro_semantico("Parametro array ja declarado", (yyvsp[(2) - (4)].string), yylineno);
        } else {
            add(&T, &tm_tab, strdup((yyvsp[(2) - (4)].string)), "param_array", (yyvsp[(1) - (4)].tipo), yylineno, escopo_at);
        }
        (yyval.no) = novo(ParamK, strdup((yyvsp[(2) - (4)].string)), (yyvsp[(1) - (4)].tipo), 0);
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 178 "parser.y"
    {yyerrok;;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 182 "parser.y"
    {
        (yyval.no) = novo(PrgK, "composto_declaracao",NULL, 2, (yyvsp[(2) - (4)].no), (yyvsp[(3) - (4)].no));
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 185 "parser.y"
    { yyerrok; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {
        (yyval.no) = novo(PrgK, "local_declaracoes",NULL, 2, (yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no));
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {
        (yyval.no) = novo(PrgK, "empty", NULL, 0);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {
        (yyval.no) = novo(PrgK, "statement_lista",NULL, 2, (yyvsp[(1) - (2)].no), (yyvsp[(2) - (2)].no));
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 201 "parser.y"
    { yyerrok; ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    { yyerrok; ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    { yyerrok; ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {
        (yyval.no) = novo(PrgK, "empty", NULL, 0);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 228 "parser.y"
    {
        (yyval.no) = novo(PrgK, "expressao_declaracao",NULL, 1, (yyvsp[(1) - (2)].no));
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {
        (yyval.no) = novo(PrgK, "empty_expression_statement", NULL, 0);
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    { yyerrok; ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {
        if (strcmp((yyvsp[(3) - (5)].no)->tipo, "int") != 0) {
            erro_semantico("Condicao do if deve ser inteira", "", yylineno);
        }
        (yyval.no) = novo(PrgK, "if_statement", NULL, 2, (yyvsp[(3) - (5)].no), (yyvsp[(5) - (5)].no));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { yyerrok; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    { yyerrok; ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    {
        if (strcmp((yyvsp[(3) - (7)].no)->tipo, "int") != 0) {
            erro_semantico("Condicao do if deve ser inteira", "", yylineno);
        }
        (yyval.no) = novo(PrgK, "if_else_statement", NULL, 3, (yyvsp[(3) - (7)].no), (yyvsp[(5) - (7)].no), (yyvsp[(7) - (7)].no));
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    { yyerrok; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {
        if (strcmp((yyvsp[(3) - (5)].no)->tipo, "int") != 0) {
            erro_semantico("Condicao do while deve ser inteira", "", yylineno);
        }
        (yyval.no) = novo(PrgK, "while_statement", NULL, 2, (yyvsp[(3) - (5)].no), (yyvsp[(5) - (5)].no));
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    { yyerrok; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    { yyerrok; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    {
        if (funcao_at == NULL || strcmp(funcao_at, "") == 0) {
            erro_semantico("Return fora de funcao", "", yylineno);
        }
        int idx = busca(T, tm_tab, funcao_at, "global");
        if (idx != -1 && strcmp(T[idx].tipo, "void") != 0) {
            erro_semantico("Funcao deve retornar void", "", yylineno);
        }
        (yyval.no) = novo(PrgK, "return_void", "void", 0);
    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 277 "parser.y"
    {
        if (funcao_at == NULL || strcmp(funcao_at, "") == 0) {
            erro_semantico("Return fora de funcao", "", yylineno);
        }
        int idx = busca(T, tm_tab, funcao_at, "global");
        if (idx != -1 && strcmp(T[idx].tipo, (yyvsp[(2) - (3)].no)->tipo) != 0) {
            erro_semantico("Tipo de retorno incompativel", "", yylineno);
        }

        (yyval.no) = novo(PrgK, "return_expr", (yyvsp[(2) - (3)].no)->tipo, 1, (yyvsp[(2) - (3)].no));
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    { yyerrok; ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].no)->tipo, "void") == 0) {
            erro_semantico("Atribuicao invalida para void", "", yylineno);
        }
        if ((strcmp((yyvsp[(1) - (3)].no)->tipo, "erro") != 0)&&(strcmp((yyvsp[(1) - (3)].no)->tipo, (yyvsp[(3) - (3)].no)->tipo) != 0)) {
            erro_semantico("Tipos incompativeis na atribuicao", "", yylineno);
        }

        (yyval.no) = novo(PrgK, "assignment", (yyvsp[(1) - (3)].no)->tipo, 2, (yyvsp[(1) - (3)].no), (yyvsp[(3) - (3)].no));
    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    { yyerrok; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {
        int idx = busca(T, tm_tab, (yyvsp[(1) - (1)].string), escopo_at);
        char *tipo_var = "erro";

        if (idx == -1) {
            idx = busca(T, tm_tab, (yyvsp[(1) - (1)].string), "global");
        }

        if (idx == -1) {
            erro_semantico("Variavel nao declarada", (yyvsp[(1) - (1)].string), yylineno);
        } else {
            tipo_var = T[idx].tipo;
        }
        (yyval.no) = novo(IdK, strdup((yyvsp[(1) - (1)].string)), tipo_var, 0);
    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    {
        int idx = busca(T, tm_tab, (yyvsp[(1) - (4)].string), escopo_at);
        char *tipo_array = "erro";

        if (idx == -1) {
            idx = busca(T, tm_tab, (yyvsp[(1) - (4)].string), "global");
        }

        if (idx == -1) {
            erro_semantico("Array nao declarado", (yyvsp[(1) - (4)].string), yylineno);
        } else if (strcmp(T[idx].tipo_dado, "array") != 0) {
            erro_semantico("Variavel nao e array", (yyvsp[(1) - (4)].string), yylineno);
            tipo_array = T[idx].tipo;
        } else {
            if (strcmp((yyvsp[(3) - (4)].no)->tipo, "int") != 0) {
                erro_semantico("Indice do array deve ser inteiro", "", yylineno);
            }
            tipo_array = T[idx].tipo;
        }
        (yyval.no) = novo(IdK, strdup((yyvsp[(1) - (4)].string)), tipo_array, 1, (yyvsp[(3) - (4)].no));
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    { yyerrok; ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 349 "parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].no)->tipo, "int") != 0 || strcmp((yyvsp[(3) - (3)].no)->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        (yyval.no) = novo(PlusK, (yyvsp[(2) - (3)].no)->val, "int", 2, (yyvsp[(1) - (3)].no), (yyvsp[(3) - (3)].no)); // Usando PlusK para relacionais também
        // Liberar $2->val pois ele foi strdup'd em 'relacional'
        free((yyvsp[(2) - (3)].no)->val);
        free((yyvsp[(2) - (3)].no)); // Liberar o nó temporário para o operador
    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 358 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    { yyerrok; ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 365 "parser.y"
    { (yyval.no) = novo(PrgK, "<", NULL, 0); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 366 "parser.y"
    { (yyval.no) = novo(PrgK, "<=", NULL, 0); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
    { (yyval.no) = novo(PrgK, ">", NULL, 0); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 368 "parser.y"
    { (yyval.no) = novo(PrgK, ">=", NULL, 0); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 369 "parser.y"
    { (yyval.no) = novo(PrgK, "==", NULL, 0); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 370 "parser.y"
    { (yyval.no) = novo(PrgK, "!=", NULL, 0); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].no)->tipo, "int") != 0 || strcmp((yyvsp[(3) - (3)].no)->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        (yyval.no) = novo(PlusK, "+", "int", 2, (yyvsp[(1) - (3)].no), (yyvsp[(3) - (3)].no));
    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 380 "parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].no)->tipo, "int") != 0 || strcmp((yyvsp[(3) - (3)].no)->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        (yyval.no) = novo(PlusK, "-", "int", 2, (yyvsp[(1) - (3)].no), (yyvsp[(3) - (3)].no) );
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 386 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    { yyerrok; ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 390 "parser.y"
    { yyerrok; ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 394 "parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].no)->tipo, "int") != 0 || strcmp((yyvsp[(3) - (3)].no)->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }

        (yyval.no) = novo(PlusK, "*", "int", 2, (yyvsp[(1) - (3)].no), (yyvsp[(3) - (3)].no));

    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 402 "parser.y"
    {
        if (strcmp((yyvsp[(1) - (3)].no)->tipo, "int") != 0 || strcmp((yyvsp[(3) - (3)].no)->tipo, "int") != 0) {
            erro_semantico("Operandos devem ser inteiros", "", yylineno);
        }
        (yyval.no) = novo(PlusK, "/", "int", 2, (yyvsp[(1) - (3)].no), (yyvsp[(3) - (3)].no));
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 408 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 411 "parser.y"
    { yyerrok; ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 412 "parser.y"
    { yyerrok; ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 416 "parser.y"
    {
        (yyval.no) = novo(ConstK, strdup((yyvsp[(1) - (1)].string)), "int", 0);
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 419 "parser.y"
    {
        (yyval.no) = (yyvsp[(1) - (1)].no);
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 422 "parser.y"
    {

        (yyval.no) = (yyvsp[(2) - (3)].no);
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 426 "parser.y"
    {
        int idx = busca(T, tm_tab, (yyvsp[(1) - (4)].string), "global");
        char *tipo_retorno = "erro";

        if (idx == -1) {
            erro_semantico("Funcao nao declarada", (yyvsp[(1) - (4)].string), yylineno);
        } else if (strcmp(T[idx].tipo_dado, "func") != 0) {
            erro_semantico("Identificador nao e uma funcao", (yyvsp[(1) - (4)].string), yylineno);
            tipo_retorno = T[idx].tipo;
        } else {
            tipo_retorno = T[idx].tipo;
        }
        (yyval.no) = novo(CallK, strdup((yyvsp[(1) - (4)].string)), tipo_retorno, 1, (yyvsp[(3) - (4)].no));
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 440 "parser.y"
    { yyerrok; ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 441 "parser.y"
    { yyerrok; ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 445 "parser.y"
    {
        (yyval.no) = novo(PrgK, "args_list", NULL, 1, (yyvsp[(1) - (1)].no));
    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 448 "parser.y"
    {
        (yyval.no) = novo(PrgK, "empty_args", NULL, 0);
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 454 "parser.y"
    {
        (yyval.no) = novo(PrgK, "arg_list", NULL, 2, (yyvsp[(1) - (3)].no), (yyvsp[(3) - (3)].no)); // Lista de argumentos com mais de um
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 457 "parser.y"
    {
        (yyval.no) = novo(PrgK, "arg_list_single", NULL, 1, (yyvsp[(1) - (1)].no)); // Único argumento
    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 460 "parser.y"
    { yyerrok; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 461 "parser.y"
    { yyerrok; ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 462 "parser.y"
    { (yyval.no) = NULL; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2421 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 465 "parser.y"


int main(int argc, char *argv[]) {
    inicia(&T, &tm_tab);
    initQuadList(&quadList); // Inicializa a lista de quádruplas

    if (argc > 1) {
        FILE *input = fopen(argv[1], "r");
        yyin = input;
    } else {
        yyin = stdin;
    }
    yyparse();
    imprime(T, tm_tab); // Imprime a tabela de símbolos

    if (raiz != NULL) {
        imp_ARV(raiz, 0); // Imprime a AST
        gen_intermediate_code(raiz); // GERA O CÓDIGO INTERMEDIÁRIO
        printQuads(&quadList); // Imprime as quádruplas geradas
        free_arv(raiz); // Libera a memória da AST
    }

    freeQuadList(&quadList); // Libera a memória da lista de quádruplas
    // TODO: Adicionar free_tabela(T, tm_tab) para liberar a tabela de símbolos e evitar vazamento de memória
    return 0;
}
