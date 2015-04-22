/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "a.y"

#define YYERROR_VERBOSE 1
#include <stdlib.h>
#include <sstream>
#include <string>
#include <stdarg.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>	
#define YYSTYPE node*
using namespace std;
set<string> mah;
int chars = 1;
int arg_no;
int func_index;
int set_arg=0;
int set_param=0;
int iterat;
int semantic_error=0;
int lines = 1;
string token;
extern char *yytext;
int val=0;
struct symbol{
	string name;
	string type;
	int verify;
	int scope;
};
typedef struct symbol symbol;
struct func_defn{
	string name;
	string type;
	vector<symbol> params;
};
typedef struct func_defn func_defn;
symbol sym;
vector<symbol> v;
vector<func_defn> f;
vector<symbol> v2;
void yyerror (const char *);
int yylex(void);
int scope=1;
struct node{
	string nt;
	string val;
	string typ;
	int scope;
	int np;
	struct node **nptr;
};
bool chec_dec(node *a, node *b)
{
	if(b->typ=="")
		return true;
	else if(b->typ==a->typ)
		return true;
	else 
		return false;
}
void check_symbol(string type)
{
	int i=v.size()-1;
	while(v[i].verify==0 && i>=0)
	{
		if(v[i].type=="scope")
		{}
		else if(v[i].type==type)
			v[i].verify=0;
		else if (v[i].type=="")
		{
			v[i].type=type;
			v[i].verify=0;
		}
		else
		{
			semantic_error=1;
			v[i].verify=0;
			cout << "error: semantic error, Invalid assignment of '" << v[i].type << "' value to '" << type << "' variable line: " << lines   << endl;
			v[i].type=type;
		}
		--i;
	}
	i=v.size()-1;
	while(v[i].verify==0 && i>=0)
	{
		if(v[i].type=="scope")
		{}
		else
		{
			string temp=v[i].name;
			for(int j=i-1;j>=0 && v[j].type!="scope";j--)
				if(v[j].name==v[i].name)
				{
					semantic_error=1;
					cout << "error: semantic error, Multiple definitions of variable '" << v[i].name << "' line : " << lines << endl;
					break;
				}
			v[i].verify=1;
		}
		--i;
	}

}

void clear_scope()
{
	--scope;
	int i=v.size()-1;
	while(v[i].type!="scope")
	{
		v.erase(v.end());
		--i;
	}
}

string get_type(string name)
{
	int i=v.size()-1;
	while(i>=0 && v[i].name!=name)
		--i;
	if(i==-1)
		return "undefined";
	else
		return v[i].type;
}
typedef struct node node;

node* mkleaf(string det)
{
	node *a=new node[1];
	a->nt=det;
	a->np=0;
	a->nptr=NULL;
	return a;
}

node* mknode(string det,int n, ...)
{
	node *a=new node[1];
	a->nt=det;
	a->np=n;
	va_list vl;
	va_start(vl,n);
	a->nptr=(node**)malloc(n*sizeof(node*));
	int i;
	for(i=0;i<n;i++)
		a->nptr[i]=va_arg(vl,node*);
	return a;
}
node *root;
int ret_present=0;

/* Line 371 of yacc.c  */
#line 223 "a.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "a.tab.h".  */
#ifndef YY_YY_A_TAB_H_INCLUDED
# define YY_YY_A_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     RETURN = 261,
     INT = 262,
     BOOL = 263,
     FALSE = 264,
     TRUE = 265,
     EQ = 266,
     NEQ = 267,
     LT = 268,
     LTE = 269,
     GT = 270,
     GTE = 271,
     LEFTPAR = 272,
     RIGHTPAR = 273,
     LEFTBRACE = 274,
     RIGHTBRACE = 275,
     DELIMITER = 276,
     UNKNOWN = 277,
     VOID = 278,
     COMMA = 279,
     integer = 280,
     id = 281,
     PRINT = 282,
     READ = 283,
     PLUS = 284,
     MINUS = 285,
     SUB_ASSIGN = 286,
     SUM_ASSIGN = 287,
     ASSIGN = 288,
     DIVISION = 289,
     MULTIPLY = 290
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_A_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 324 "a.tab.c"

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   136

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    17,    21,
      24,    28,    30,    32,    36,    38,    40,    41,    42,    53,
      55,    56,    58,    59,    63,    65,    68,    72,    74,    76,
      78,    80,    82,    84,    86,    88,    91,    92,    98,   100,
     103,   106,   109,   112,   114,   122,   123,   136,   144,   147,
     151,   155,   159,   163,   165,   169,   171,   173,   175,   177,
     179,   181,   183,   187,   189,   191,   193,   197,   199,   201,
     203,   206,   208,   210,   212,   214,   218,   220,   222,   223,
     229,   231,   232,   236,   238,   240,   242,   244,   246,   248
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    38,    -1,    38,    39,    -1,    39,    -1,
      40,    -1,    44,    -1,     1,    21,    -1,    43,    41,    21,
      -1,    43,     1,    -1,    41,    24,    42,    -1,    42,    -1,
      78,    -1,    78,    33,    63,    -1,     7,    -1,     8,    -1,
      -1,    -1,    43,    78,    17,    45,    48,    18,    19,    47,
      20,    46,    -1,    53,    -1,    -1,    49,    -1,    -1,    49,
      21,    50,    -1,    50,    -1,    43,    51,    -1,    51,    24,
      78,    -1,    78,    -1,    40,    -1,    57,    -1,    58,    -1,
      60,    -1,    55,    -1,    56,    -1,    61,    -1,    52,    53,
      -1,    -1,    80,    47,    20,    54,    53,    -1,    52,    -1,
      27,    78,    -1,    27,    77,    -1,    28,    78,    -1,    62,
      21,    -1,    21,    -1,     3,    17,    63,    18,    80,    47,
      20,    -1,    -1,     3,    17,    63,    18,    80,    47,    20,
      59,     4,    80,    47,    20,    -1,     5,    17,    63,    18,
      80,    47,    20,    -1,     6,    21,    -1,     6,    62,    21,
      -1,    78,    33,    62,    -1,    78,    32,    62,    -1,    78,
      31,    62,    -1,    63,    -1,    65,    64,    65,    -1,    65,
      -1,    14,    -1,    13,    -1,    15,    -1,    16,    -1,    11,
      -1,    12,    -1,    65,    66,    67,    -1,    67,    -1,    29,
      -1,    30,    -1,    67,    68,    69,    -1,    69,    -1,    35,
      -1,    34,    -1,    70,    69,    -1,    71,    -1,    30,    -1,
      72,    -1,    78,    -1,    17,    62,    18,    -1,    73,    -1,
      77,    -1,    -1,    78,    17,    74,    75,    18,    -1,    76,
      -1,    -1,    76,    24,    62,    -1,    62,    -1,    79,    -1,
      10,    -1,     9,    -1,    26,    -1,    25,    -1,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   161,   161,   163,   164,   167,   168,   169,   172,   179,
     182,   193,   198,   208,   221,   222,   225,   236,   225,   240,
     240,   242,   243,   246,   247,   250,   265,   266,   269,   270,
     271,   272,   273,   274,   275,   278,   279,   279,   280,   283,
     284,   286,   288,   289,   292,   293,   293,   296,   298,   299,
     305,   318,   330,   336,   339,   347,   350,   351,   352,   353,
     354,   355,   358,   364,   367,   368,   371,   375,   378,   379,
     382,   386,   389,   392,   393,   401,   402,   403,   406,   406,
     435,   436,   439,   449,   462,   463,   464,   466,   482,   488
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "RETURN", "INT",
  "BOOL", "FALSE", "TRUE", "EQ", "NEQ", "LT", "LTE", "GT", "GTE",
  "LEFTPAR", "RIGHTPAR", "LEFTBRACE", "RIGHTBRACE", "DELIMITER", "UNKNOWN",
  "VOID", "COMMA", "integer", "id", "PRINT", "READ", "PLUS", "MINUS",
  "SUB_ASSIGN", "SUM_ASSIGN", "ASSIGN", "DIVISION", "MULTIPLY", "$accept",
  "CODE", "DECLARATIONS", "DECLARATION", "VARIABLE_DEFINITION",
  "VARIABLES", "VARIABLE_INITIALIZE", "TYPE", "FUNCTION_DEFINITION", "$@1",
  "$@2", "STATEMENT_LIST", "PARAMS", "PARAMETERS", "PARAMETER",
  "PARAMETER_IDS", "STATEMENT", "STATEMENTS", "$@3", "PRINT_STATEMENT",
  "READ_STATEMENT", "EXP", "CONDITIONAL", "$@4", "LOOP",
  "RETURN_STATEMENT", "EXPRESSION", "SIMPLE_EXPRESSION",
  "RELATIONAL_OPERATORS", "SUM", "ARITHMETIC_OPERATORS", "TERM",
  "MUL_DIV_OPERATORS", "UNARY_EXPRESSION", "UNARY_OPERATOR", "FACTOR",
  "L_VALUE", "FUNCTION_CALL", "$@5", "ARGUMENT", "ARGUMENTS", "LITERALS",
  "IDENTIFIER", "INTEGERS", "leftbrace", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    39,    40,    40,
      41,    41,    42,    42,    43,    43,    45,    46,    44,    47,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    53,    54,    53,    53,    55,
      55,    56,    57,    57,    58,    59,    58,    60,    61,    61,
      62,    62,    62,    62,    63,    63,    64,    64,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    72,    74,    73,
      75,    75,    76,    76,    77,    77,    77,    78,    79,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     2,     3,     2,
       3,     1,     1,     3,     1,     1,     0,     0,    10,     1,
       0,     1,     0,     3,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     5,     1,     2,
       2,     2,     2,     1,     7,     0,    12,     7,     2,     3,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     3,     1,     1,     0,     5,
       1,     0,     3,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    14,    15,     0,     0,     4,     5,     0,     6,
       7,     1,     3,     9,    87,     0,    11,    12,     8,     0,
      16,     0,    10,    12,    22,    86,    85,     0,    88,    72,
      13,    55,    63,    67,     0,    71,    73,    76,    77,    74,
      84,     0,     0,    21,    24,     0,    53,    74,    60,    61,
      57,    56,    58,    59,    64,    65,     0,     0,    69,    68,
       0,    70,    78,    25,    27,     0,     0,    75,     0,     0,
       0,    54,    62,    66,    81,     0,    20,    23,    52,    51,
      50,    83,     0,    80,    26,     0,     0,     0,    89,    43,
       0,     0,    28,     0,     0,    38,    19,    32,    33,    29,
      30,    31,    34,     0,    20,    79,     0,     0,     0,    48,
       0,    40,    39,    41,    17,    35,    42,     0,    82,     0,
       0,    49,    18,    36,     0,     0,     0,    20,    20,    37,
       0,     0,    44,    47,     0,     0,    20,     0,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,    92,    15,    16,    93,     9,    24,
     122,    94,    42,    43,    44,    63,    95,    96,   126,    97,
      98,    99,   100,   134,   101,   102,   103,    46,    56,    31,
      57,    32,    60,    33,    34,    35,    36,    37,    74,    82,
      83,    38,    47,    40,   104
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int8 yypact[] =
{
      69,   -12,  -111,  -111,    17,   101,  -111,  -111,     5,  -111,
    -111,  -111,  -111,  -111,  -111,    26,  -111,    29,  -111,    -2,
    -111,    48,  -111,     9,    99,  -111,  -111,    48,  -111,  -111,
    -111,    81,    78,  -111,    48,  -111,  -111,  -111,  -111,    34,
    -111,    -2,    38,    45,  -111,    50,  -111,    72,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,    48,    48,  -111,  -111,
      48,  -111,  -111,    57,  -111,    67,    99,  -111,    48,    48,
      48,    85,    78,  -111,    48,    -2,    13,  -111,  -111,  -111,
    -111,  -111,    80,    66,  -111,   100,   102,    54,  -111,  -111,
      35,    -2,  -111,     5,    96,    13,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,    97,    13,  -111,    48,    48,    48,  -111,
     103,  -111,  -111,  -111,  -111,  -111,  -111,   105,  -111,   104,
     108,  -111,  -111,  -111,   109,   109,    13,    13,    13,  -111,
     107,   110,   116,  -111,   117,   109,    13,   111,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,  -111,   118,     2,  -111,   113,     3,  -111,  -111,
    -111,   -99,  -111,  -111,    63,  -111,  -111,   -91,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,   -15,   -20,  -111,    77,
    -111,    79,  -111,   -24,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,    44,    -8,  -111,  -110
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -46
static const yytype_int16 yytable[] =
{
      17,    30,     7,     8,   115,   117,    13,     7,     8,    10,
      61,    23,    45,    39,   127,   128,    85,    11,    86,    87,
       2,     3,    25,    26,    14,   136,    39,    41,   130,   131,
      27,    14,    88,    64,    89,   129,    73,   137,    28,    14,
      90,    91,    21,    29,    25,    26,    20,    18,    39,    39,
      19,    62,    39,    78,    79,    80,    65,    25,    26,    81,
      28,    14,    21,    25,    26,    27,    66,    84,    67,    41,
       1,    27,   110,    28,    14,   109,     2,     3,    29,    28,
      14,    75,   112,   113,    29,    23,    76,   119,   120,    62,
     106,   118,    48,    49,    50,    51,    52,    53,   105,    39,
      39,    -2,     1,    68,    69,    70,     2,     3,     2,     3,
      54,    55,    58,    59,    54,    55,   114,   107,   116,   108,
     -45,   135,   124,    12,   121,   123,   125,   132,    88,    77,
     133,   138,    22,    71,   111,     0,    72
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       8,    21,     0,     0,    95,   104,     1,     5,     5,    21,
      34,    19,    27,    21,   124,   125,     3,     0,     5,     6,
       7,     8,     9,    10,    26,   135,    34,    24,   127,   128,
      17,    26,    19,    41,    21,   126,    60,   136,    25,    26,
      27,    28,    33,    30,     9,    10,    17,    21,    56,    57,
      24,    17,    60,    68,    69,    70,    18,     9,    10,    74,
      25,    26,    33,     9,    10,    17,    21,    75,    18,    66,
       1,    17,    87,    25,    26,    21,     7,     8,    30,    25,
      26,    24,    90,    91,    30,    93,    19,   107,   108,    17,
      24,   106,    11,    12,    13,    14,    15,    16,    18,   107,
     108,     0,     1,    31,    32,    33,     7,     8,     7,     8,
      29,    30,    34,    35,    29,    30,    20,    17,    21,    17,
       4,     4,    18,     5,    21,    20,    18,    20,    19,    66,
      20,    20,    19,    56,    90,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,     8,    37,    38,    39,    40,    43,    44,
      21,     0,    39,     1,    26,    41,    42,    78,    21,    24,
      17,    33,    42,    78,    45,     9,    10,    17,    25,    30,
      63,    65,    67,    69,    70,    71,    72,    73,    77,    78,
      79,    43,    48,    49,    50,    62,    63,    78,    11,    12,
      13,    14,    15,    16,    29,    30,    64,    66,    34,    35,
      68,    69,    17,    51,    78,    18,    21,    18,    31,    32,
      33,    65,    67,    69,    74,    24,    19,    50,    62,    62,
      62,    62,    75,    76,    78,     3,     5,     6,    19,    21,
      27,    28,    40,    43,    47,    52,    53,    55,    56,    57,
      58,    60,    61,    62,    80,    18,    24,    17,    17,    21,
      62,    77,    78,    78,    20,    53,    21,    47,    62,    63,
      63,    21,    46,    20,    18,    18,    54,    80,    80,    53,
      47,    47,    20,    20,    59,     4,    80,    47,    20
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

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
/* Line 1792 of yacc.c  */
#line 161 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);root=(yyval);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 163 "a.y"
    {(yyval)=mknode("DEC",2,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 164 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 167 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 168 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 169 "a.y"
    { val=1; yyclearin; }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 172 "a.y"
    {
							(yyval)=mknode("VAR_DEF",3,(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),mkleaf(";"));
							/*bool chec=chec_dec($1,$2);
							if(chec==false)
								cout << "Line no. " << lines << ": Invalid variable initialization\n";*/
						        check_symbol((yyvsp[(1) - (3)])->typ);
						}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 179 "a.y"
    {val=1;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 182 "a.y"
    {
							(yyval)=mknode("VARS",3,(yyvsp[(1) - (3)]),mkleaf(","),(yyvsp[(3) - (3)]));
						/*	if($1->typ=="")
								$$->typ=$3->typ;
							else if($3->typ=="")
								$$->typ=$1->typ;
							else if($1->typ==$3->typ)
								$$->typ=$1->typ;
							else
								cout << "Line no. " << lines << ": Invalid varibale initialization\n";*/
						}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 193 "a.y"
    {
		  			(yyval)=(yyvsp[(1) - (1)]);
				}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 198 "a.y"
    {
					(yyval)=(yyvsp[(1) - (1)]);
					(yyval)->scope=scope;
					symbol s;
					s.name=(yyvsp[(1) - (1)])->val;
					s.type="";
					s.verify=0;
					s.scope=scope;
					v.push_back(s);v2.push_back(s);
				 }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 208 "a.y"
    {
			    					(yyval)=mknode("VAR_INIT",3,(yyvsp[(1) - (3)]),mkleaf("="),(yyvsp[(3) - (3)]));
								(yyval)->typ=(yyvsp[(3) - (3)])->typ;
								(yyvsp[(1) - (3)])->scope=scope;
								symbol s;
								s.name=(yyvsp[(1) - (3)])->val;
								s.type=(yyvsp[(3) - (3)])->typ;
								s.verify=0;
								s.scope=scope;
								v.push_back(s);v2.push_back(s);
							   }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 221 "a.y"
    {(yyval)=mkleaf("int");(yyval)->typ="int";}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 222 "a.y"
    {(yyval)=mkleaf("bool");(yyval)->typ="bool";}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 225 "a.y"
    {func_defn fun;
						fun.name=(yyvsp[(2) - (3)])->val;
						fun.type=(yyvsp[(1) - (3)])->nt;
						f.push_back(fun);
						++scope;symbol s; 
						s.name="{";
						s.type="scope";
						s.scope=scope;
						v.push_back(s);
						v2.push_back(s);
						}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 236 "a.y"
    {clear_scope();}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 236 "a.y"
    {
			(yyval)=mknode("FUNC_DEF",4,(yyvsp[(1) - (10)]),(yyvsp[(2) - (10)]),(yyvsp[(5) - (10)]),(yyvsp[(8) - (10)]));}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 240 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 242 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 243 "a.y"
    {(yyval)=mkleaf("");}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 246 "a.y"
    {(yyval)=mknode("PARAMS",3,(yyvsp[(1) - (3)]),mkleaf(";"),(yyvsp[(3) - (3)]));}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 247 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 250 "a.y"
    {
	(yyval)=mknode("PARAM",2,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));
	(yyval)->typ=(yyvsp[(1) - (2)])->typ;
	int i=v.size()-1;
	while(i>=0 && v[i].verify==0)
	{
		symbol temp=v[i];
		temp.type=(yyvsp[(1) - (2)])->typ;
		f[f.size()-1].params.push_back(temp);
		--i;
	}
	check_symbol((yyvsp[(1) - (2)])->typ);
	}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 265 "a.y"
    {(yyval)=mknode("PARAM_IDS",3,(yyvsp[(1) - (3)]),mkleaf(","),(yyvsp[(3) - (3)]));(yyvsp[(3) - (3)])->scope=scope;symbol s;s.name=(yyvsp[(3) - (3)])->val;s.type="";s.verify=0;s.scope=scope;v.push_back(s);v2.push_back(s);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 266 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);(yyval)->scope=scope;symbol s;s.name=(yyvsp[(1) - (1)])->val;s.type="";s.verify=0;s.scope=scope;v.push_back(s);v2.push_back(s);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 269 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 270 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 271 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 273 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 274 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 275 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 278 "a.y"
    {(yyval)=mknode("STMNTS",2,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 279 "a.y"
    {clear_scope();}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 279 "a.y"
    {(yyval)=mknode("STMNTS",2,(yyvsp[(2) - (5)]),(yyvsp[(5) - (5)]));}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 280 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 283 "a.y"
    {(yyval)=mknode("PRINT_STMNT",2,mkleaf("print"),(yyvsp[(2) - (2)]));}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 284 "a.y"
    {(yyval)=mknode("PRINT_STMNT",2,mkleaf("print"),(yyvsp[(2) - (2)]));}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 286 "a.y"
    {(yyval)=mknode("READ_STMNT",2,mkleaf("read"),(yyvsp[(2) - (2)]));}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 288 "a.y"
    {(yyval)=mknode("EXP",2,(yyvsp[(1) - (2)]),mkleaf(";"));}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 289 "a.y"
    {(yyval)=mkleaf(";");}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 292 "a.y"
    {clear_scope();(yyval)=mknode("COND",3,mkleaf("if"),(yyvsp[(3) - (7)]),(yyvsp[(6) - (7)]));}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 293 "a.y"
    {clear_scope();}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 293 "a.y"
    {clear_scope();(yyval)=mknode("COND",5,mkleaf("if"),(yyvsp[(3) - (12)]),(yyvsp[(6) - (12)]),mkleaf("else"),(yyvsp[(11) - (12)]));}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 296 "a.y"
    {clear_scope();(yyval)=mknode("LOOP",3,mkleaf("while"),(yyvsp[(3) - (7)]),(yyvsp[(6) - (7)]));}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 298 "a.y"
    {(yyval)=mknode("RET",2,mkleaf("return"),mkleaf(";"));}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 299 "a.y"
    {(yyval)=mknode("RET",3,mkleaf("return"),(yyvsp[(2) - (3)]),mkleaf(";"));
		 if((yyvsp[(2) - (3)])->typ!=f[f.size()-1].type)
			 cout << "error: semantic error, return type does not match with function definition line: " << lines << endl;
		 }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 305 "a.y"
    {
	(yyval)=mknode("EXPR",3,(yyvsp[(1) - (3)]),mkleaf("="),(yyvsp[(3) - (3)]));
	if(get_type((yyvsp[(1) - (3)])->val)=="undefined")
	{
		semantic_error=1;
		cout << "error: semantic error, variable '" << (yyvsp[(1) - (3)])->val << "' undefined line: " << lines << endl;
	}
	else if(get_type((yyvsp[(1) - (3)])->val)!=(yyvsp[(3) - (3)])->typ)
	{
		semantic_error=1;
		cout << "error: semantic error, Invalid assignment of '" << (yyvsp[(3) - (3)])->typ << "' value to '" << get_type((yyvsp[(1) - (3)])->val) << "' variable line: " << lines <<  endl;
	}
	}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 318 "a.y"
    {(yyval)=mknode("EXPR",3,(yyvsp[(1) - (3)]),mkleaf("+="),(yyvsp[(3) - (3)]));
	if(get_type((yyvsp[(1) - (3)])->val)=="undefined")
	{
		semantic_error=1;
		cout << "error: semantic error, variable '" << (yyvsp[(1) - (3)])->val << "' undefined line: " << lines << endl;
	}
	else if(get_type((yyvsp[(1) - (3)])->val)!=(yyvsp[(3) - (3)])->typ)
	{
		semantic_error=1;
		cout << "error: semantic error, Invalid assignment of '" << (yyvsp[(3) - (3)])->typ << "' value to '" << get_type((yyvsp[(1) - (3)])->val) << "' variable line: " << lines <<  endl;
	}
}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 330 "a.y"
    {(yyval)=mknode("EXPR",3,(yyvsp[(1) - (3)]),mkleaf("-="),(yyvsp[(3) - (3)]));
	if(get_type((yyvsp[(1) - (3)])->val)=="undefined")
		cout << "error: semantic error, variable '" << (yyvsp[(1) - (3)])->val << "' undefined line: " << lines << endl;
	else if(get_type((yyvsp[(1) - (3)])->val)!=(yyvsp[(3) - (3)])->typ)
		cout << "error: semantic error, Invalid assignment of '" << (yyvsp[(3) - (3)])->typ << "' value to '" << get_type((yyvsp[(1) - (3)])->val) << "' variable line: " << lines <<  endl;
}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 336 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 339 "a.y"
    {
	(yyval)=mknode("SIMPL_EXPR",3,(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
	if((yyvsp[(1) - (3)])->typ==(yyvsp[(3) - (3)])->typ)
		(yyval)->typ="bool";
	else
		cout << "error: semantic error, Comparison of '" << (yyvsp[(1) - (3)])->typ << "' with '" << (yyvsp[(3) - (3)])->typ << " line :" << lines << endl;

	}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 347 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 350 "a.y"
    {(yyval)=mkleaf("<=");(yyval)->typ="bool";}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 351 "a.y"
    {(yyval)=mkleaf("<");(yyval)->typ="bool";}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 352 "a.y"
    {(yyval)=mkleaf(">");(yyval)->typ="bool";}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 353 "a.y"
    {(yyval)=mkleaf(">=");(yyval)->typ="bool";}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 354 "a.y"
    {(yyval)=mkleaf("==");(yyval)->typ="bool";}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 355 "a.y"
    {(yyval)=mkleaf("!=");(yyval)->typ="bool";}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 358 "a.y"
    {
	(yyval)=mknode("SUM",3,(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));
	(yyval)->typ="int";
	if((yyvsp[(1) - (3)])->typ=="bool" || (yyvsp[(3) - (3)])->typ=="bool")
		cout << "error: semantic error, boolean value given as operand to arithmetic opertor '" << (yyvsp[(2) - (3)])->val << "' line: " << lines << endl;
	}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 364 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 367 "a.y"
    {(yyval)=mkleaf("+");(yyval)->val="+";}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 368 "a.y"
    {(yyval)=mkleaf("-");(yyval)->val="-";}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 371 "a.y"
    {(yyval)=mknode("TERM",3,(yyvsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yyvsp[(3) - (3)]));(yyval)->typ="int";
	if((yyvsp[(1) - (3)])->typ=="bool" || (yyvsp[(3) - (3)])->typ=="bool")
		cout << "error: semantic error, boolean value given as operand to arithmetic opertor '" << (yyvsp[(2) - (3)])->val << "' line: " << lines << endl;
}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 375 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 378 "a.y"
    {(yyval)=mkleaf("*");(yyval)->val="*";}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 379 "a.y"
    {(yyval)=mkleaf("/");(yyval)->val="/";}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 382 "a.y"
    {(yyval)=mknode("UN_EXP",2,(yyvsp[(1) - (2)]),(yyvsp[(2) - (2)]));(yyval)->typ="int";
	if((yyvsp[(2) - (2)])->typ=="bool")
		cout << "error: semantic error, boolean value given as operand to unary operator '" << (yyvsp[(2) - (2)])->val << "' line: " << lines << endl;
}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 386 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 389 "a.y"
    {(yyval)=mkleaf("-");(yyval)->val="-";}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 392 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 393 "a.y"
    {
	       (yyval)=(yyvsp[(1) - (1)]);
	       (yyval)->typ=get_type((yyval)->val);
	       if((yyval)->typ=="undefined")
		       cout << "error: semantic error, variable '" << (yyval)->val << "' undefined line: " << lines << endl;
       		}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 401 "a.y"
    {(yyval)=(yyvsp[(2) - (3)]);}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 402 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 403 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 406 "a.y"
    {
	int i=f.size()-1;
	 while(i>=0 && f[i].name!=(yyvsp[(1) - (2)])->val)
		 --i;
	 if(i<0)
	 {
		cout << "error: semantic error, function '" << (yyvsp[(1) - (2)])->val << "' is not defined line: " << lines << endl;
		iterat=-1;
	 }
         else
	 { 
		arg_no=f[i].params.size();
		 iterat=0;
		 func_index=i;
	 }
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 421 "a.y"
    {
	(yyval)=mknode("FUNC_CALL",2,(yyvsp[(1) - (5)]),(yyvsp[(4) - (5)]));
	int i=0;
	while(f[i].name!=(yyvsp[(1) - (5)])->val)
		++i;
	(yyval)->typ=f[i].type;
	stringstream ss;
	ss << arg_no;
	(yyval)->val=ss.str();
	if(iterat>=0 && iterat!=arg_no)
		cout << "error: semantic error, insufficient number of arguments line: " << lines << endl;
}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 435 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 436 "a.y"
    {(yyval)=mkleaf("");}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 439 "a.y"
    {(yyval)=mknode("ARGS",3,(yyvsp[(1) - (3)]),mkleaf(","),(yyvsp[(3) - (3)]));
		  if(iterat>=0 && iterat<arg_no)
		  {
			  if(f[func_index].params[iterat].type!=(yyvsp[(3) - (3)])->typ)
				  cout << "error: semantic error, passed '" << (yyvsp[(3) - (3)])->typ << "' argument to '" << f[func_index].params[iterat].type << "' parameter while calling function '" << f[func_index].name << "' line: " << lines << endl;
			  ++iterat;
		  }
		  else if(iterat>=0)
			  cout << "error: semantic error, extra arguments are passed to function '" << f[func_index].name << "' line: " << lines << endl;
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 449 "a.y"
    {
		  (yyval)=(yyvsp[(1) - (1)]);
		  if(iterat>=0 && iterat<arg_no)
		  {
			  if(f[func_index].params[iterat].type!=(yyvsp[(1) - (1)])->typ)
				  cout << "error: semantic error, passed '" << (yyvsp[(1) - (1)])->typ << "' argument to '" << f[func_index].params[iterat].type << "' parameter while calling function '" << f[func_index].name << "' line: " << lines << endl;
			  ++iterat;
		  }
		  else if(iterat>=0)
			  cout << "error: semantic error, extra arguments are passed to function '" << f[func_index].name << "' line: " << lines << endl;
		  }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 462 "a.y"
    {(yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 463 "a.y"
    {(yyval)=mkleaf("BOOLEAN");(yyval)->typ="bool";(yyval)->val="true";}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 464 "a.y"
    {(yyval)=mkleaf("BOOLEAN");(yyval)->typ="bool";(yyval)->val="false";}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 467 "a.y"
    {
		    (yyval)=mkleaf("IDENTIFIER");
		    (yyval)->val=token;
		    for(int i=v.size()-1;i>=0;i--)
			    if(v[i].name==token)
			    {
				    (yyval)->scope=v[i].scope;
				    break;
			    }
			    else
				    (yyval)->scope=scope;
		    (yyval)->typ="";
	    }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 483 "a.y"
    {
		  (yyval)=mkleaf("INTEGERS");
		  (yyval)->val=token;
		  (yyval)->typ="int";
	  }
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 488 "a.y"
    {++scope;symbol s; s.name="{";s.type="scope";v.push_back(s);v2.push_back(s);}
    break;


/* Line 1792 of yacc.c  */
#line 2339 "a.tab.c"
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


/* Line 2055 of yacc.c  */
#line 490 "a.y"

void yyerror(const char *s)
{
	fprintf(stderr,"error: %s line: %d column : %d\n",s,lines,chars);
}
void dfs(node *p)
{
	if(p->np==0)
	{
		cout << "'" << p->nt << "' ";
	}
	else
	{
		int i;
		for(i=0;i<p->np;i++)
			dfs(p->nptr[i]);
		cout << p->nt << " ";
	}
}
string get_new_reg(){
	static int coun=0;
	stringstream ss;
	ss << "r" << coun ;
	coun++;
	return ss.str();
}
string get_new_var(node *p){
	stringstream ss;
	ss << p->val << p->scope;
	return ss.str();
}
int check_label(string temp)
{
	for(int i=0;i<f.size();i++)
		if(f[i].name==temp)
			return -1;
	return 0;
}
string get_new_label(){
	static int num=0;
	stringstream ss;
	do{
	ss.str("");
	ss << "label" << num;
	num++;
	}
	while(check_label(ss.str())!=0);
	return ss.str();
}
int get_max_para(node *root)
{
	string c=root->nt;
	node** p=root->nptr;
	int count=0;
	if(c=="FUNC_CALL")
	{
		int i=0;
		while(f[i].name!=p[0]->val)
			++i;
		count=(f[i].params.size());
	}
	else
	{
		for(int i=0;i<root->np;i++)
			count = max(count,get_max_para(p[i]));
	}
	return count;
}
int get_var_count(node *root)
{
	string c=root->nt;
	node** p=root->nptr;
	int count=0;
	if(c=="VAR_INIT")
	{
		count += get_var_count(p[0]);
		count += get_var_count(p[2]);
	}
	else if(c=="SUM")
	{
		if(set_arg==1)
			set_arg=0;
		count =1;
		count += get_var_count(p[0]);
		count += get_var_count(p[2]);
	}
	else if(c=="TERM")
	{
		count = 1;
		count +=  get_var_count(p[0]);
		count += get_var_count(p[2]);
	}
	else if(c=="IDENTIFIER")
	{
		string temp=get_new_var(root);
		if(mah.find(temp)==mah.end())
		{
			count=1;
			mah.insert(temp);
		}
		if(set_arg==1)
			++count;
	}
	else if(c=="INTEGERS")
	{
		if(set_arg==1)
			count=1;
	}
	else if(c=="BOOLEAN")
	{
		count=1;
	}
	else if(c=="EXPR")
	{
			count += get_var_count(p[0]);
			count += get_var_count(p[2]);
	}
	else if(c=="SIMPL_EXPR")
	{
		if(set_arg==1)
			set_arg=0;
		count=1;
		count += get_var_count(p[0]);
		count += get_var_count(p[2]);
	}
	else if(c=="COND")
	{
		if(root->np==3)	
		{
			count += get_var_count(p[1]); 
			count += get_var_count(p[2]);
		}
		else
		{
			count += get_var_count(p[1]);
			count += get_var_count(p[2]);
			count += get_var_count(p[4]);
		}
	}
	else if(c=="LOOP")
	{
		count +=  get_var_count(p[1]);
		count += get_var_count(p[2]);
	}
	else if(c=="FUNC_DEF")
	{
		count += get_var_count(p[2]);
		count += get_var_count(p[3]);
	}
	else if(c=="RET")
	{
		if(root->np==3)
			count += get_var_count(p[1]);
	}
	else if(c=="FUNC_CALL")
	{
		set_arg=1;
		count=1;
		count += get_var_count(p[1]);
		set_arg=0;
	}
	else if(c=="PRINT_STMNT")
	{
		count += get_var_count(p[1]);
	}
	else if(c=="UN_EXP")
	{
		count=1;
		count +=get_var_count(p[1]);
	}
	else
	{
		for(int i=0;i<root->np;i++)
			count += get_var_count(p[i]);
	}
	return count;
}
string three_addr_code(node *root)
{
	string c=root->nt;
	//cout << c << endl;
	node** p=root->nptr;
	if(c=="VAR_INIT")
	{
		cout << three_addr_code(p[0]) << "=" << three_addr_code(p[2]) << endl;
		return "";
	}
	else if(c=="SUM")
	{
		int temp=set_arg;
		set_arg=0;
		string reg=get_new_reg();
		cout << reg << "=" << three_addr_code(p[0]) << p[1]->val << three_addr_code(p[2]) << endl;
		if(temp==1)
		{
			cout << "param " << reg << endl;
			set_arg=1;
		}
		return reg;
	}
	else if(c=="TERM")
	{
		int temp=set_arg;
		set_arg=0;
		string reg=get_new_reg();
		cout << reg << "=" << three_addr_code(p[0])<< p[1]->val << three_addr_code(p[2]) << endl;
		if(temp==1)
		{
			cout << "param " << reg << endl;
			set_arg=1;
		}
		return reg;
	}
	else if(c=="IDENTIFIER")
	{
		int temp=set_arg;
		if(set_param==1)
			cout << get_new_var(root) << " " ;
		string r1=get_new_var(root);
		if(temp==1)
		{
			string r2=get_new_reg();
			cout << r2 << "=" << r1 << endl;
			cout << "param " << r2 << endl;
			return r2 ;
		}
		return r1;
	}
	
	else if(c=="PRINT_STMNT")
	{
		cout << "print " << three_addr_code(p[1]) << endl;
	}
	else if(c=="READ_STMNT")
	{
		cout << "read " << three_addr_code(p[1]) << endl;
	}
	else if(c=="INTEGERS")
	{
		int temp=set_arg;
		if(temp==1)
		{
			string r1=get_new_reg();
			cout << r1 << "=" << root->val << endl;
			cout << "param " << r1 << endl;
			return r1;
		}
		return root->val;
	}
	else if(c=="BOOLEAN")
	{
		int temp=set_arg;
		string r1=get_new_reg();
		cout << r1 << "=" ;
		if(root->val=="true")
			cout << "1" << endl;
		else
			cout << "0" << endl;
		if(temp==1)
			cout << "param " << r1 << endl;
		return r1;
	}
	else if(c=="EXPR")
	{
		int temp=set_arg;
		set_arg=0;
		if(p[1]->nt=="=")
			cout << three_addr_code(p[0]) << "=" << three_addr_code(p[2]) << endl;
		else if(p[1]->nt=="+=")
			cout << three_addr_code(p[0]) << "="<< three_addr_code(p[0]) << "+" << three_addr_code(p[2]) << endl;
		else 
			cout << three_addr_code(p[0]) << "="<< three_addr_code(p[0]) << "-" << three_addr_code(p[2]) << endl;
		if(temp==1)
		{
			cout << "param " << three_addr_code(p[0]) << endl;
			set_arg=1;
		}
		return "";
	}
	else if(c=="SIMPL_EXPR")
	{
		int temp=set_arg;
		set_arg=0;
		string reg=get_new_reg();
		cout << reg << "=" << three_addr_code(p[0])<< p[1]->nt << three_addr_code(p[2]) << endl;
		if(temp==1)
		{
			cout << "param " << reg << endl;
			set_arg=1;
		}
		return reg;
	}
	else if(c=="COND")
	{
		string continue_label=get_new_label();
		string false_label=get_new_label();
		if(root->np==3)
		{
			cout << "if FALSE " << three_addr_code(p[1]) << " goto " << continue_label <<  endl;
			three_addr_code(p[2]);
			cout << continue_label << ":" << endl;
			return "";
		}
		else
		{
			cout << "if FALSE " << three_addr_code(p[1]) << " goto " << false_label << endl;
			three_addr_code(p[2]);
			cout << "goto " << continue_label << endl;
			cout << false_label << ":" << endl;
			three_addr_code(p[4]);
			cout << continue_label << ":" << endl;
			return "";
		}
	}
	else if(c=="LOOP")
	{
		string loop_label=get_new_label();
		string continue_label=get_new_label();
		cout << loop_label << ":" << endl;
		cout << "if FALSE " << three_addr_code(p[1]) << " goto " << continue_label << endl;
		three_addr_code(p[2]);
		cout << "goto " << loop_label << endl;
		cout << continue_label << ":" << endl;
	}
	else if(c=="FUNC_DEF")
	{
		set_param=1;
		cout << p[1]->val << ":" << endl;
		mah.clear();
		set_arg=0;
		int temp1=get_var_count(root);
		int temp3=get_max_para(p[3]);
		int frame_size=4*(2+temp1+temp3);
		if(frame_size%8!=0)
		frame_size += 8-(frame_size%8);
		cout << "func begin " << frame_size << "," <<  temp3 <<endl;
		cout << "paramx " ;
		three_addr_code(p[2]);
		cout << "," << endl;
		set_param=0;
		ret_present=0;
		three_addr_code(p[3]);
		if(ret_present==0)
			cout << "return null" << endl;
		cout << "func end" << endl; 
		return "";
	}
	else if(c=="RET")
	{
		ret_present=1;
		if(root->np==3)
			cout << "return " <<  three_addr_code(p[1]);
		else
			cout << "return null";
		cout << endl;
		return "";
	}
	else if(c=="FUNC_CALL")
	{
		set_arg=1;
		string r1=get_new_reg();
		three_addr_code(p[1]);
		set_arg=0;
		cout << r1 << " = call " << p[0]->val << "," << root->val << endl;
		return r1;
	}
	else if(c=="UN_EXP")
	{
		int temp=set_arg;
		set_arg=0;
		string reg=get_new_reg();
		cout << reg << "= -" << three_addr_code(p[1]) << endl;
		if(temp==1)
		{
			cout << "param " << reg << endl;
			set_arg=1;
		}
		return reg;
	}
	else
	{
		for(int i=0;i<root->np;i++)
			three_addr_code(p[i]);
		return "";
	}
}

int main()
{
	val=(val+yyparse());
/*	if(val==0)
	{
		dfs(root);
		printf("\n");
	}*/
//	for(int i=0;i<v2.size();i++)
//		cout << v2[i].name << " " << v2[i].scope << " " << endl;
	if(val==0 && semantic_error==0)
		three_addr_code(root);
	return 1;
}
