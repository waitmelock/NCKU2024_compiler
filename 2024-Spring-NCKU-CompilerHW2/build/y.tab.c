/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "./compiler.y"

    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    int currentaddr=-1;
    ObjectType DefinedType = -1;
    Object endl = {.type = 9, .value = (uint64_t)-1, .symbol = NULL};
    int arrayCount = 0;
    char* autoVarName[20];
    int funcType[10];
    int funcTypeIndex=0;

#line 86 "./build/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COUT = 3,                       /* COUT  */
  YYSYMBOL_SHR = 4,                        /* SHR  */
  YYSYMBOL_SHL = 5,                        /* SHL  */
  YYSYMBOL_BAN = 6,                        /* BAN  */
  YYSYMBOL_BOR = 7,                        /* BOR  */
  YYSYMBOL_BNT = 8,                        /* BNT  */
  YYSYMBOL_BXO = 9,                        /* BXO  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_SUB = 11,                       /* SUB  */
  YYSYMBOL_MUL = 12,                       /* MUL  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_REM = 14,                       /* REM  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_GTR = 16,                       /* GTR  */
  YYSYMBOL_LES = 17,                       /* LES  */
  YYSYMBOL_GEQ = 18,                       /* GEQ  */
  YYSYMBOL_LEQ = 19,                       /* LEQ  */
  YYSYMBOL_EQL = 20,                       /* EQL  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LAN = 22,                       /* LAN  */
  YYSYMBOL_LOR = 23,                       /* LOR  */
  YYSYMBOL_VAL_ASSIGN = 24,                /* VAL_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 25,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 26,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 27,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 28,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 29,                /* REM_ASSIGN  */
  YYSYMBOL_BAN_ASSIGN = 30,                /* BAN_ASSIGN  */
  YYSYMBOL_BOR_ASSIGN = 31,                /* BOR_ASSIGN  */
  YYSYMBOL_BXO_ASSIGN = 32,                /* BXO_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 33,                /* SHR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 34,                /* SHL_ASSIGN  */
  YYSYMBOL_INC_ASSIGN = 35,                /* INC_ASSIGN  */
  YYSYMBOL_DEC_ASSIGN = 36,                /* DEC_ASSIGN  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 43,                  /* CONTINUE  */
  YYSYMBOL_VARIABLE_T = 44,                /* VARIABLE_T  */
  YYSYMBOL_IDENT = 45,                     /* IDENT  */
  YYSYMBOL_STR_LIT = 46,                   /* STR_LIT  */
  YYSYMBOL_FLOAT_LIT = 47,                 /* FLOAT_LIT  */
  YYSYMBOL_INT_LIT = 48,                   /* INT_LIT  */
  YYSYMBOL_BOOL_LIT = 49,                  /* BOOL_LIT  */
  YYSYMBOL_NEG = 50,                       /* NEG  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* ';'  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Program = 61,                   /* Program  */
  YYSYMBOL_62_1 = 62,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 63,            /* GlobalStmtList  */
  YYSYMBOL_GlobalStmt = 64,                /* GlobalStmt  */
  YYSYMBOL_DefineVariableStmt = 65,        /* DefineVariableStmt  */
  YYSYMBOL_66_2 = 66,                      /* $@2  */
  YYSYMBOL_DefineVariableStmtList = 67,    /* DefineVariableStmtList  */
  YYSYMBOL_68_3 = 68,                      /* $@3  */
  YYSYMBOL_FunctionDefStmt = 69,           /* FunctionDefStmt  */
  YYSYMBOL_70_4 = 70,                      /* $@4  */
  YYSYMBOL_71_5 = 71,                      /* $@5  */
  YYSYMBOL_72_6 = 72,                      /* $@6  */
  YYSYMBOL_FunctionParameterStmtList = 73, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 74,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 75,                  /* StmtList  */
  YYSYMBOL_Stmt = 76,                      /* Stmt  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_78_8 = 78,                      /* $@8  */
  YYSYMBOL_79_9 = 79,                      /* $@9  */
  YYSYMBOL_80_10 = 80,                     /* $@10  */
  YYSYMBOL_81_11 = 81,                     /* $@11  */
  YYSYMBOL_forParm = 82,                   /* forParm  */
  YYSYMBOL_ifStmt = 83,                    /* ifStmt  */
  YYSYMBOL_84_12 = 84,                     /* $@12  */
  YYSYMBOL_CoutParmListStmt = 85,          /* CoutParmListStmt  */
  YYSYMBOL_ArrayParameterStmt = 86,        /* ArrayParameterStmt  */
  YYSYMBOL_Expression = 87,                /* Expression  */
  YYSYMBOL_dimension = 88,                 /* dimension  */
  YYSYMBOL_Callist = 89,                   /* Callist  */
  YYSYMBOL_CalculateFun = 90,              /* CalculateFun  */
  YYSYMBOL_factor6 = 91,                   /* factor6  */
  YYSYMBOL_factor5 = 92,                   /* factor5  */
  YYSYMBOL_factor4 = 93,                   /* factor4  */
  YYSYMBOL_factor3 = 94,                   /* factor3  */
  YYSYMBOL_factor2 = 95,                   /* factor2  */
  YYSYMBOL_factor = 96,                    /* factor  */
  YYSYMBOL_sign = 97,                      /* sign  */
  YYSYMBOL_term = 98,                      /* term  */
  YYSYMBOL_assignvar = 99,                 /* assignvar  */
  YYSYMBOL_AddAdd = 100                    /* AddAdd  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    56,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    72,    72,    72,    73,    77,    78,    82,    83,    87,
      87,    88,    92,    97,   105,   111,   119,   119,   128,   133,
     143,   150,   151,   142,   214,   215,   216,   219,   225,   235,
     236,   239,   240,   241,   242,   243,   244,   244,   245,   245,
     246,   246,   246,   247,   247,   248,   249,   250,   256,   257,
     269,   269,   270,   273,   274,   278,   279,   285,   286,   287,
     288,   299,   312,   313,   316,   317,   318,   322,   323,   327,
     328,   332,   333,   334,   335,   339,   340,   341,   342,   343,
     344,   348,   349,   353,   354,   359,   366,   367,   372,   377,
     386,   387,   388,   389,   390,   394,   395,   396,   398,   400,
     406,   418,   421,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   450,   451,   452
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "COUT", "SHR", "SHL",
  "BAN", "BOR", "BNT", "BXO", "ADD", "SUB", "MUL", "DIV", "REM", "NOT",
  "GTR", "LES", "GEQ", "LEQ", "EQL", "NEQ", "LAN", "LOR", "VAL_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN",
  "BAN_ASSIGN", "BOR_ASSIGN", "BXO_ASSIGN", "SHR_ASSIGN", "SHL_ASSIGN",
  "INC_ASSIGN", "DEC_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "RETURN",
  "BREAK", "CONTINUE", "VARIABLE_T", "IDENT", "STR_LIT", "FLOAT_LIT",
  "INT_LIT", "BOOL_LIT", "NEG", "','", "'{'", "'}'", "'('", "')'", "';'",
  "':'", "'['", "']'", "$accept", "Program", "$@1", "GlobalStmtList",
  "GlobalStmt", "DefineVariableStmt", "$@2", "DefineVariableStmtList",
  "$@3", "FunctionDefStmt", "$@4", "$@5", "$@6",
  "FunctionParameterStmtList", "FunctionParameterStmt", "StmtList", "Stmt",
  "$@7", "$@8", "$@9", "$@10", "$@11", "forParm", "ifStmt", "$@12",
  "CoutParmListStmt", "ArrayParameterStmt", "Expression", "dimension",
  "Callist", "CalculateFun", "factor6", "factor5", "factor4", "factor3",
  "factor2", "factor", "sign", "term", "assignvar", "AddAdd", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-135)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-103)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -135,    17,   -23,  -135,   -13,   -23,  -135,  -135,  -135,  -135,
      -5,  -135,   -25,    -6,    16,  -135,   162,    73,    -2,    -3,
      10,   404,   404,   115,   -39,  -135,  -135,  -135,  -135,    35,
    -135,  -135,    48,    54,    21,   138,    74,    81,    50,  -135,
    -135,    32,   264,  -135,    42,    61,  -135,    93,    78,    80,
    -135,  -135,  -135,   404,  -135,   312,   404,    67,    96,    97,
      -7,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,    -7,  -135,
    -135,   162,    75,    10,   110,  -135,   116,     8,   113,   404,
     312,  -135,  -135,    54,    21,   138,   138,   138,    74,    74,
      74,    74,    74,    81,    50,    50,  -135,  -135,  -135,   119,
     312,  -135,  -135,  -135,   123,   400,   312,  -135,   117,  -135,
    -135,   125,   390,  -135,  -135,  -135,   187,   139,  -135,   143,
     147,   162,  -135,  -135,  -135,   148,    58,  -135,   343,   149,
     162,     1,   162,   151,  -135,  -135,   156,  -135,  -135,  -135,
     162,   162,   162,   162,   162,   162,   162,   162,   162,   162,
     162,  -135,  -135,   162,  -135,  -135,   390,   169,   312,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
    -135,  -135,   159,   142,    72,   160,     3,   191,  -135,   312,
     312,   165,   166,  -135,   390,  -135,    -9,    48,   390,  -135,
     390,   162,   243,   390,   292,   235,  -135,  -135,  -135,   341,
    -135,  -135,  -135,  -135
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    11,     1,     0,     3,     6,     7,     8,    20,
       0,     5,     0,    14,    10,    21,     0,     0,    18,     0,
      26,     0,     0,     0,   100,   101,    98,    97,    99,     0,
      58,    15,    59,    67,    69,    71,    75,    81,    83,    86,
      90,   100,     0,    56,     0,     0,    19,    12,     0,    22,
      25,    94,    91,     0,    92,    66,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    66,     0,    55,
      16,     0,    27,     0,     0,    93,     0,    65,     0,     0,
       0,    57,    95,    68,    70,    72,    73,    74,    76,    77,
      80,    79,    78,    82,    84,    85,    88,    87,    89,     0,
      66,    13,    28,    24,     0,    60,    66,    63,     0,    96,
     102,     0,     0,    64,    62,    17,     0,     0,    38,     0,
       0,    46,    45,     9,    31,     0,     0,    30,    47,     0,
       0,     0,     0,     0,    43,    40,     0,    35,    23,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    54,     0,    32,    36,     0,    11,     0,    33,
     103,   104,   105,   106,   107,   108,   111,   112,   113,   109,
     110,    53,     0,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,    50,    52,    37,     0,    49,     0,    41,
       0,     0,     0,     0,     0,     0,   116,    48,    44,     0,
      51,   114,   115,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,   214,    -1,  -135,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,   140,  -113,  -134,  -135,  -135,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   -10,   -16,  -135,   -65,
     -22,   161,   163,    45,   -32,   150,    76,   -51,   -12,    23,
    -135
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,   135,    10,    14,   110,     8,
      12,    20,    84,    49,    50,   136,   137,   182,   143,   168,
     203,   167,   185,   195,   200,   141,    30,   138,    57,    86,
      32,    33,    34,    35,    36,    37,    38,    39,    40,   139,
     207
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,     7,   149,    18,     7,    44,   163,    60,    46,    51,
      52,    54,   109,    59,    61,    55,    61,     3,    16,    56,
      78,     4,    45,   106,   107,   108,    61,    63,    64,    15,
      65,    61,     9,    87,    98,    99,   100,   101,   102,   119,
      13,    85,    47,    21,    88,   121,    22,   201,    92,   149,
      23,   123,    17,   183,    48,    87,    17,   164,   192,   116,
     149,   126,    74,    75,    76,   111,    21,    19,   149,    22,
     149,    61,   112,    23,   194,   149,    62,   118,    71,    58,
      24,    25,    26,    27,    28,   202,    77,   204,    87,    29,
     209,    72,    73,    17,    87,   127,   128,   129,   130,   131,
     132,    79,   133,    24,    25,    26,    27,    28,    95,    96,
      97,   148,    29,    80,   134,   146,    17,    81,    41,    25,
      26,    27,    28,    82,   162,    89,   165,    42,   189,   190,
      53,    83,    43,    17,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   126,   186,   181,   104,   105,
      21,    90,    91,    22,    66,    67,    68,    23,    69,    70,
      41,    25,    26,    27,    28,   114,   184,   196,   197,    42,
      21,   115,   117,    22,   120,   122,   124,    23,   125,   127,
     128,   129,   130,   131,   132,   205,   133,    24,    25,    26,
      27,    28,   140,   142,   126,   188,    29,   144,   134,    21,
      17,   145,    22,   166,   147,   161,    23,    24,    25,    26,
      27,    28,   169,   133,   187,   191,    29,   198,   199,    11,
      17,   103,    93,   113,   206,    94,     0,     0,   127,   128,
     129,   130,   131,   132,     0,   133,    24,    25,    26,    27,
      28,     0,     0,   193,     0,    29,   126,   134,     0,    17,
       0,    21,     0,     0,    22,     0,     0,     0,    23,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     211,   212,    21,     0,     0,    22,     0,     0,     0,    23,
     127,   128,   129,   130,   131,   132,     0,   133,    24,    25,
      26,    27,    28,     0,     0,   126,   208,    29,     0,   134,
      21,    17,     0,    22,     0,     0,     0,    23,    58,    41,
      25,    26,    27,    28,     0,     0,     0,     0,    42,     0,
      21,     0,     0,    22,     0,     0,     0,    23,     0,   127,
     128,   129,   130,   131,   132,     0,   133,    24,    25,    26,
      27,    28,     0,     0,   126,   210,    29,     0,   134,    21,
      17,     0,    22,     0,     0,     0,    23,    41,    25,    26,
      27,    28,     0,     0,     0,     0,    42,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   127,   128,
     129,   130,   131,   132,     0,   133,    24,    25,    26,    27,
      28,     0,     0,   126,   213,    29,     0,   134,    21,    17,
       0,    22,     0,     0,  -102,    23,  -102,  -102,     0,  -102,
    -102,     0,  -102,  -102,  -102,     0,  -102,  -102,  -102,     0,
    -102,  -102,  -102,  -102,     0,     0,     0,   127,   128,   129,
     130,   131,   132,     0,   133,    24,    25,    26,    27,    28,
       0,     0,     0,     0,    29,     0,   134,     0,    17,    41,
      25,    26,    27,    28,     0,     0,     0,     0,    42
};

static const yytype_int16 yycheck[] =
{
      16,     2,   136,    13,     5,    17,     5,    29,    18,    21,
      22,    23,    77,    29,    23,    54,    23,     0,    24,    58,
      42,    44,    24,    74,    75,    76,    23,     6,     7,    54,
       9,    23,    45,    55,    66,    67,    68,    69,    70,    90,
      45,    53,    45,     8,    56,   110,    11,    56,    55,   183,
      15,   116,    58,   166,    44,    77,    58,    56,    55,    51,
     194,     3,    12,    13,    14,    81,     8,    51,   202,    11,
     204,    23,    82,    15,   187,   209,    22,    89,     4,    44,
      45,    46,    47,    48,    49,   198,    54,   200,   110,    54,
     203,    10,    11,    58,   116,    37,    38,    39,    40,    41,
      42,    59,    44,    45,    46,    47,    48,    49,    63,    64,
      65,    53,    54,    52,    56,   131,    58,    24,    45,    46,
      47,    48,    49,    45,   140,    58,   142,    54,    56,    57,
      15,    51,    59,    58,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     3,   168,   163,    72,    73,
       8,    55,    55,    11,    16,    17,    18,    15,    20,    21,
      45,    46,    47,    48,    49,    55,   167,   189,   190,    54,
       8,    55,    59,    11,    55,    52,    59,    15,    53,    37,
      38,    39,    40,    41,    42,   201,    44,    45,    46,    47,
      48,    49,     5,    54,     3,    53,    54,    54,    56,     8,
      58,    54,    11,    52,    56,    56,    15,    45,    46,    47,
      48,    49,    56,    44,    55,    55,    54,    52,    52,     5,
      58,    71,    61,    83,   201,    62,    -1,    -1,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,    52,    -1,    54,     3,    56,    -1,    58,
      -1,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,     3,    53,    54,    -1,    56,
       8,    58,    -1,    11,    -1,    -1,    -1,    15,    44,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54,    -1,
       8,    -1,    -1,    11,    -1,    -1,    -1,    15,    -1,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    -1,    -1,     3,    53,    54,    -1,    56,     8,
      58,    -1,    11,    -1,    -1,    -1,    15,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    37,    38,
      39,    40,    41,    42,    -1,    44,    45,    46,    47,    48,
      49,    -1,    -1,     3,    53,    54,    -1,    56,     8,    58,
      -1,    11,    -1,    -1,     4,    15,     6,     7,    -1,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    -1,
      20,    21,    22,    23,    -1,    -1,    -1,    37,    38,    39,
      40,    41,    42,    -1,    44,    45,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    54,    -1,    56,    -1,    58,    45,
      46,    47,    48,    49,    -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,    62,     0,    44,    63,    64,    65,    69,    45,
      66,    64,    70,    45,    67,    54,    24,    58,    86,    51,
      71,     8,    11,    15,    45,    46,    47,    48,    49,    54,
      86,    87,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    45,    54,    59,    98,    24,    86,    45,    44,    73,
      74,    98,    98,    15,    98,    54,    58,    88,    44,    87,
      90,    23,    22,     6,     7,     9,    16,    17,    18,    20,
      21,     4,    10,    11,    12,    13,    14,    54,    90,    59,
      52,    24,    45,    51,    72,    98,    89,    90,    98,    58,
      55,    55,    55,    91,    92,    93,    93,    93,    94,    94,
      94,    94,    94,    95,    96,    96,    97,    97,    97,    89,
      68,    87,    86,    74,    55,    55,    51,    59,    98,    97,
      55,    89,    52,    89,    59,    53,     3,    37,    38,    39,
      40,    41,    42,    44,    56,    65,    75,    76,    87,    99,
       5,    85,    54,    78,    54,    54,    87,    56,    53,    76,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    56,    87,     5,    56,    87,    52,    81,    79,    56,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    77,    75,    65,    82,    90,    55,    53,    56,
      57,    55,    55,    52,    75,    83,    90,    90,    52,    52,
      84,    56,    75,    80,    75,    87,    99,   100,    53,    75,
      53,    35,    36,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    62,    61,    61,    63,    63,    64,    64,    66,
      65,    65,    67,    67,    67,    67,    68,    67,    67,    67,
      70,    71,    72,    69,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    77,    76,    78,    76,
      79,    80,    76,    81,    76,    76,    76,    76,    82,    82,
      84,    83,    83,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    88,    88,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    92,    92,    93,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    95,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   100,   100
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     0,
       3,     0,     3,     5,     1,     3,     0,     7,     2,     3,
       0,     0,     0,    11,     3,     1,     0,     2,     3,     2,
       1,     1,     3,     3,     2,     2,     0,     6,     0,     5,
       0,     0,     9,     0,     8,     1,     1,     1,     5,     3,
       0,     4,     1,     3,     2,     3,     2,     3,     1,     1,
       4,     2,     4,     3,     3,     1,     0,     1,     3,     1,
       3,     1,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     2,     2,     3,     2,     3,     4,     1,     1,     1,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* $@1: %empty  */
#line 72 "./compiler.y"
      { pushScope(); }
#line 1372 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 72 "./compiler.y"
                                      { dumpScope(); }
#line 1378 "./build/y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 87 "./compiler.y"
                { DefinedType = (yyvsp[0].var_type);}
#line 1384 "./build/y.tab.c"
    break;

  case 12: /* DefineVariableStmtList: DefineVariableStmtList ',' IDENT  */
#line 93 "./compiler.y"
    {
        createassign(DefinedType, (yyvsp[0].s_var));
        addnew(DefinedType, (yyvsp[0].s_var), yylineno);
    }
#line 1393 "./build/y.tab.c"
    break;

  case 13: /* DefineVariableStmtList: DefineVariableStmtList ',' IDENT VAL_ASSIGN Expression  */
#line 98 "./compiler.y"
    {
        if(DefinedType==1){
            DefinedType = (yyvsp[-3].object_val).type;
        }
        createassign(DefinedType, (yyvsp[-2].s_var));
        addnew(DefinedType, (yyvsp[-2].s_var), yylineno);
    }
#line 1405 "./build/y.tab.c"
    break;

  case 14: /* DefineVariableStmtList: IDENT  */
#line 106 "./compiler.y"
    {   
        strcpy(autoVarName, (yyvsp[0].s_var));
        createassign(DefinedType, (yyvsp[0].s_var));
        addnew(DefinedType, (yyvsp[0].s_var), yylineno);
    }
#line 1415 "./build/y.tab.c"
    break;

  case 15: /* DefineVariableStmtList: IDENT VAL_ASSIGN Expression  */
#line 112 "./compiler.y"
    {
        if(DefinedType==1){
            DefinedType = (yyvsp[-1].object_val).type;
        }
        createassign(DefinedType, (yyvsp[-2].s_var));
        addnew(DefinedType, (yyvsp[-2].s_var), yylineno);
    }
#line 1427 "./build/y.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 119 "./compiler.y"
                                              {arrayCount = 0;}
#line 1433 "./build/y.tab.c"
    break;

  case 17: /* DefineVariableStmtList: IDENT ArrayParameterStmt VAL_ASSIGN '{' $@3 Callist '}'  */
#line 120 "./compiler.y"
    {
        if(DefinedType==1){
            DefinedType = (yyvsp[-5].object_val).type;
        }
        printf("create array: %d\n",arrayCount);
        createassign(DefinedType, (yyvsp[-6].s_var));
        addnew(DefinedType, (yyvsp[-5].s_var), yylineno);
    }
#line 1446 "./build/y.tab.c"
    break;

  case 18: /* DefineVariableStmtList: IDENT ArrayParameterStmt  */
#line 129 "./compiler.y"
    {
        createassign(DefinedType, (yyvsp[-1].s_var));
        addnew(DefinedType, (yyvsp[0].s_var), yylineno);
    }
#line 1455 "./build/y.tab.c"
    break;

  case 19: /* DefineVariableStmtList: IDENT ArrayParameterStmt ArrayParameterStmt  */
#line 134 "./compiler.y"
    {
        createassign(DefinedType, (yyvsp[-2].s_var));
        addnew(DefinedType, (yyvsp[-1].s_var), yylineno);
    }
#line 1464 "./build/y.tab.c"
    break;

  case 20: /* $@4: %empty  */
#line 143 "./compiler.y"
    { 
        funcTypeIndex = 0;
        funcType[funcTypeIndex++] = (yyvsp[-1].var_type);
        indextozero();
        addnew(10, (yyvsp[0].s_var), yylineno);
        createFunction((yyvsp[-1].var_type), (yyvsp[0].s_var));
    }
#line 1476 "./build/y.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 150 "./compiler.y"
        {indextozero();pushScope();}
#line 1482 "./build/y.tab.c"
    break;

  case 22: /* $@6: %empty  */
#line 151 "./compiler.y"
    {
        char sig[100]= "";
        strcat(sig, "(");
        for(int i=1;i<funcTypeIndex;i++){
            switch (funcType[i]){
                case 0:
                    strcat(sig, "[");
                    break;
                case 2:
                    strcat(sig, "V");
                    break;
                case 4:
                    strcat(sig, "I");
                    break;
                case 6:
                    strcat(sig, "F");
                    break;
                case 8:
                    strcat(sig, "B");
                    break;
                case 9:
                    strcat(sig, "Ljava/lang/String;");
                    break;
                default:
                    printf("invalid\n");
                    break;
            }
        }
        strcat(sig, ")");
        switch (funcType[0]){
            case 0:
                strcat(sig, "[");
                break;
            case 2:
                strcat(sig, "V");
                break;
            case 4:
                strcat(sig, "I");
                break;
            case 6:
                strcat(sig, "F");
                break;
            case 8:
                strcat(sig, "B");
                break;
            case 9:
                strcat(sig, "Ljava/lang/String;");
                break;
            default:
                printf("invalid\n");
                break;
        }
        Object* temp = searchVar((yyvsp[-4].s_var), 1);
        if(temp!=NULL){
            strcpy(temp->symbol->func_sig, sig);
        }else{
            printf("invalid\n");
        }
    }
#line 1546 "./build/y.tab.c"
    break;

  case 23: /* FunctionDefStmt: VARIABLE_T IDENT $@4 '(' $@5 FunctionParameterStmtList $@6 ')' '{' StmtList '}'  */
#line 210 "./compiler.y"
                         { dumpScope(); }
#line 1552 "./build/y.tab.c"
    break;

  case 27: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 220 "./compiler.y"
    { 
        funcType[funcTypeIndex++] = (yyvsp[-1].var_type);
        pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), 1);
        addnew((yyvsp[-1].var_type), (yyvsp[0].s_var), yylineno);
    }
#line 1562 "./build/y.tab.c"
    break;

  case 28: /* FunctionParameterStmt: VARIABLE_T IDENT ArrayParameterStmt  */
#line 226 "./compiler.y"
    {
        funcType[funcTypeIndex++] = (yyvsp[-2].var_type); 
        pushFunParm((yyvsp[-2].var_type), (yyvsp[-1].s_var), VAR_FLAG_DEFAULT);
        addnew((yyvsp[-2].var_type), (yyvsp[-1].s_var), yylineno);
    }
#line 1572 "./build/y.tab.c"
    break;

  case 32: /* Stmt: COUT CoutParmListStmt ';'  */
#line 240 "./compiler.y"
                                {stdoutPrint(); printf("\n");}
#line 1578 "./build/y.tab.c"
    break;

  case 33: /* Stmt: RETURN Expression ';'  */
#line 241 "./compiler.y"
                            {printf("RETURN\n"); }
#line 1584 "./build/y.tab.c"
    break;

  case 36: /* $@7: %empty  */
#line 244 "./compiler.y"
                        {printf("IF\n");}
#line 1590 "./build/y.tab.c"
    break;

  case 38: /* $@8: %empty  */
#line 245 "./compiler.y"
           {printf("ELSE\n");pushScope();}
#line 1596 "./build/y.tab.c"
    break;

  case 39: /* Stmt: ELSE $@8 '{' StmtList '}'  */
#line 245 "./compiler.y"
                                                            {dumpScope();}
#line 1602 "./build/y.tab.c"
    break;

  case 40: /* $@9: %empty  */
#line 246 "./compiler.y"
                {printf("WHILE\n");}
#line 1608 "./build/y.tab.c"
    break;

  case 41: /* $@10: %empty  */
#line 246 "./compiler.y"
                                                          {pushScope();}
#line 1614 "./build/y.tab.c"
    break;

  case 42: /* Stmt: WHILE '(' $@9 CalculateFun ')' '{' $@10 StmtList '}'  */
#line 246 "./compiler.y"
                                                                                      {dumpScope();}
#line 1620 "./build/y.tab.c"
    break;

  case 43: /* $@11: %empty  */
#line 247 "./compiler.y"
             { indextozero(); printf("FOR\n");pushScope();}
#line 1626 "./build/y.tab.c"
    break;

  case 44: /* Stmt: FOR '(' $@11 forParm ')' '{' StmtList '}'  */
#line 247 "./compiler.y"
                                                                                          {dumpScope();}
#line 1632 "./build/y.tab.c"
    break;

  case 45: /* Stmt: BREAK  */
#line 248 "./compiler.y"
            {printf("BREAK\n");}
#line 1638 "./build/y.tab.c"
    break;

  case 46: /* Stmt: RETURN  */
#line 249 "./compiler.y"
             { printf("RETURN\n"); }
#line 1644 "./build/y.tab.c"
    break;

  case 49: /* forParm: DefineVariableStmt ':' CalculateFun  */
#line 258 "./compiler.y"
    {
        Object* temp = searchVar(autoVarName, 0); //find inserted variable in the symbollist
        if(temp!=NULL){
            temp->type = (yyvsp[-1].object_val).type;
        }else{
            printf("invalid\n");
        }
    }
#line 1657 "./build/y.tab.c"
    break;

  case 50: /* $@12: %empty  */
#line 269 "./compiler.y"
          {pushScope();}
#line 1663 "./build/y.tab.c"
    break;

  case 51: /* ifStmt: '{' $@12 StmtList '}'  */
#line 269 "./compiler.y"
                                      {dumpScope();}
#line 1669 "./build/y.tab.c"
    break;

  case 53: /* CoutParmListStmt: CoutParmListStmt SHL Expression  */
#line 273 "./compiler.y"
                                      { pushFunInParm(&(yyvsp[-1].object_val));}
#line 1675 "./build/y.tab.c"
    break;

  case 54: /* CoutParmListStmt: SHL Expression  */
#line 274 "./compiler.y"
                     { pushFunInParm(&(yyvsp[-1].object_val));}
#line 1681 "./build/y.tab.c"
    break;

  case 56: /* ArrayParameterStmt: '[' ']'  */
#line 279 "./compiler.y"
              {funcType[funcTypeIndex++] = 0;}
#line 1687 "./build/y.tab.c"
    break;

  case 57: /* Expression: '(' Expression ')'  */
#line 285 "./compiler.y"
                         { (yyvsp[-3].object_val).type=(yyvsp[-2].object_val).type; }
#line 1693 "./build/y.tab.c"
    break;

  case 59: /* Expression: CalculateFun  */
#line 287 "./compiler.y"
                   {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1699 "./build/y.tab.c"
    break;

  case 60: /* Expression: IDENT '(' Callist ')'  */
#line 289 "./compiler.y"
    {
        Object* temp = searchVar((yyvsp[-3].s_var), 1); //find inserted variable in the symbollist
        if(temp!=NULL){
            printf("IDENT (name=%s, address=%ld)\n",(yyvsp[-3].s_var),temp->symbol->addr);
            printf("call: %s%s\n", temp->symbol->name, temp->symbol->func_sig);
            (yyvsp[-4].object_val).type=temp->func_retype;
        }else{
            printf("invalid\n");
        }
    }
#line 1714 "./build/y.tab.c"
    break;

  case 61: /* Expression: IDENT dimension  */
#line 300 "./compiler.y"
    {
        Object* temp = searchVar((yyvsp[-1].s_var), 0); //find inserted variable in the symbollist
        if(temp!=NULL){
            printf("IDENT (name=%s, address=%ld)\n",(yyvsp[-1].s_var),temp->symbol->addr);
            (yyvsp[-2].object_val).type = temp->type;
        }else{
            printf("invalid\n");
        }
    }
#line 1728 "./build/y.tab.c"
    break;

  case 64: /* Callist: CalculateFun ',' Callist  */
#line 316 "./compiler.y"
                               {arrayCount++;}
#line 1734 "./build/y.tab.c"
    break;

  case 65: /* Callist: CalculateFun  */
#line 317 "./compiler.y"
                   {arrayCount++;}
#line 1740 "./build/y.tab.c"
    break;

  case 67: /* CalculateFun: factor6  */
#line 322 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1746 "./build/y.tab.c"
    break;

  case 68: /* CalculateFun: CalculateFun LOR factor6  */
#line 323 "./compiler.y"
                                {printf("LOR\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1752 "./build/y.tab.c"
    break;

  case 69: /* factor6: factor5  */
#line 327 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1758 "./build/y.tab.c"
    break;

  case 70: /* factor6: factor6 LAN factor5  */
#line 328 "./compiler.y"
                          {printf("LAN\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1764 "./build/y.tab.c"
    break;

  case 71: /* factor5: factor4  */
#line 332 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1770 "./build/y.tab.c"
    break;

  case 72: /* factor5: factor5 BAN factor4  */
#line 333 "./compiler.y"
                          {printf("BAN\n");(yyval.object_val).type=OBJECT_TYPE_INT;}
#line 1776 "./build/y.tab.c"
    break;

  case 73: /* factor5: factor5 BOR factor4  */
#line 334 "./compiler.y"
                          {printf("BOR\n");(yyval.object_val).type=OBJECT_TYPE_INT;}
#line 1782 "./build/y.tab.c"
    break;

  case 74: /* factor5: factor5 BXO factor4  */
#line 335 "./compiler.y"
                          {printf("BXO\n");(yyval.object_val).type=OBJECT_TYPE_INT;}
#line 1788 "./build/y.tab.c"
    break;

  case 75: /* factor4: factor3  */
#line 339 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1794 "./build/y.tab.c"
    break;

  case 76: /* factor4: factor4 GTR factor3  */
#line 340 "./compiler.y"
                          {printf("GTR\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1800 "./build/y.tab.c"
    break;

  case 77: /* factor4: factor4 LES factor3  */
#line 341 "./compiler.y"
                          {printf("LES\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1806 "./build/y.tab.c"
    break;

  case 78: /* factor4: factor4 NEQ factor3  */
#line 342 "./compiler.y"
                          {printf("NEQ\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1812 "./build/y.tab.c"
    break;

  case 79: /* factor4: factor4 EQL factor3  */
#line 343 "./compiler.y"
                          {printf("EQL\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1818 "./build/y.tab.c"
    break;

  case 80: /* factor4: factor4 GEQ factor3  */
#line 344 "./compiler.y"
                          {printf("GEQ\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1824 "./build/y.tab.c"
    break;

  case 81: /* factor3: factor2  */
#line 348 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1830 "./build/y.tab.c"
    break;

  case 82: /* factor3: factor3 SHR factor2  */
#line 349 "./compiler.y"
                          {printf("SHR\n");(yyval.object_val).type=OBJECT_TYPE_INT;}
#line 1836 "./build/y.tab.c"
    break;

  case 83: /* factor2: factor  */
#line 353 "./compiler.y"
             {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1842 "./build/y.tab.c"
    break;

  case 84: /* factor2: factor2 ADD factor  */
#line 354 "./compiler.y"
                         {printf("ADD\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;}
    }
#line 1852 "./build/y.tab.c"
    break;

  case 85: /* factor2: factor2 SUB factor  */
#line 359 "./compiler.y"
                          {printf("SUB\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;}
    }
#line 1862 "./build/y.tab.c"
    break;

  case 86: /* factor: sign  */
#line 366 "./compiler.y"
           {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1868 "./build/y.tab.c"
    break;

  case 87: /* factor: factor DIV sign  */
#line 367 "./compiler.y"
                      {printf("DIV\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;}
    }
#line 1878 "./build/y.tab.c"
    break;

  case 88: /* factor: factor MUL sign  */
#line 372 "./compiler.y"
                      {printf("MUL\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;}
    }
#line 1888 "./build/y.tab.c"
    break;

  case 89: /* factor: factor REM sign  */
#line 377 "./compiler.y"
                      {printf("REM\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;}
    }
#line 1898 "./build/y.tab.c"
    break;

  case 90: /* sign: term  */
#line 386 "./compiler.y"
           {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 1904 "./build/y.tab.c"
    break;

  case 91: /* sign: SUB term  */
#line 387 "./compiler.y"
               {printf("NEG\n");(yyvsp[-2].object_val).type = (yyvsp[0].object_val).type;}
#line 1910 "./build/y.tab.c"
    break;

  case 92: /* sign: NOT term  */
#line 388 "./compiler.y"
               {printf("NOT\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1916 "./build/y.tab.c"
    break;

  case 93: /* sign: NOT NOT term  */
#line 389 "./compiler.y"
                   {printf("NOT\nNOT\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;}
#line 1922 "./build/y.tab.c"
    break;

  case 94: /* sign: BNT term  */
#line 390 "./compiler.y"
               {printf("BNT\n"); (yyval.object_val).type=OBJECT_TYPE_INT; }
#line 1928 "./build/y.tab.c"
    break;

  case 96: /* term: '(' VARIABLE_T ')' sign  */
#line 395 "./compiler.y"
                              {casting((yyvsp[-2].var_type));}
#line 1934 "./build/y.tab.c"
    break;

  case 97: /* term: INT_LIT  */
#line 396 "./compiler.y"
              { (yyval.object_val) = (yyvsp[0].object_val); (yyval.object_val).type=OBJECT_TYPE_INT; 
            printf("INT_LIT %d\n",(yyvsp[0].i_var)); }
#line 1941 "./build/y.tab.c"
    break;

  case 98: /* term: FLOAT_LIT  */
#line 398 "./compiler.y"
                { (yyval.object_val) = (yyvsp[0].object_val); (yyval.object_val).type=OBJECT_TYPE_FLOAT; 
            printf("FLOAT_LIT %.6f\n",(yyvsp[0].f_var)); }
#line 1948 "./build/y.tab.c"
    break;

  case 99: /* term: BOOL_LIT  */
#line 400 "./compiler.y"
               { (yyval.object_val) = (yyvsp[0].object_val); (yyval.object_val).type=OBJECT_TYPE_BOOL; 
            if((yyvsp[0].b_var))
                printf("BOOL_LIT %s\n","TRUE");
            else
                printf("BOOL_LIT %s\n","FALSE");  
            }
#line 1959 "./build/y.tab.c"
    break;

  case 100: /* term: IDENT  */
#line 406 "./compiler.y"
            {
                Object* temp = searchVar((yyvsp[0].s_var), 0); //find inserted variable in the symbollist
                if(temp!=NULL){
                    printf("IDENT (name=%s, address=%ld)\n",(yyvsp[0].s_var),temp->symbol->addr);
                    (yyval.object_val).type=temp->type; 
                    (yyval.object_val) = *temp;
                }else{
                    printf("IDENT (name=%s, address=-1)\n",(yyvsp[0].s_var));
                    (yyval.object_val) = endl;
                    (yyval.object_val).type=OBJECT_TYPE_STR; 
                }
            }
#line 1976 "./build/y.tab.c"
    break;

  case 101: /* term: STR_LIT  */
#line 418 "./compiler.y"
              { 
                (yyval.object_val).type=OBJECT_TYPE_STR;
                printf("STR_LIT \"%s\"\n",(yyvsp[0].s_var)); }
#line 1984 "./build/y.tab.c"
    break;

  case 102: /* term: IDENT '(' Callist ')'  */
#line 422 "./compiler.y"
    {
        Object* temp = searchVar((yyvsp[-3].s_var), 1); //find inserted variable in the symbollist
        if(temp!=NULL){
            printf("IDENT (name=%s, address=%ld)\n",(yyvsp[-3].s_var),temp->symbol->addr);
            printf("call: %s%s\n", temp->symbol->name, temp->symbol->func_sig);
            (yyvsp[-4].object_val).type=temp->func_retype;
        }else{
            printf("invalid\n");
        }
    }
#line 1999 "./build/y.tab.c"
    break;

  case 103: /* assignvar: Expression VAL_ASSIGN Expression  */
#line 436 "./compiler.y"
                                       {printf("EQL_ASSIGN\n");}
#line 2005 "./build/y.tab.c"
    break;

  case 104: /* assignvar: Expression ADD_ASSIGN Expression  */
#line 437 "./compiler.y"
                                       {printf("ADD_ASSIGN\n");}
#line 2011 "./build/y.tab.c"
    break;

  case 105: /* assignvar: Expression SUB_ASSIGN Expression  */
#line 438 "./compiler.y"
                                       {printf("SUB_ASSIGN\n");}
#line 2017 "./build/y.tab.c"
    break;

  case 106: /* assignvar: Expression MUL_ASSIGN Expression  */
#line 439 "./compiler.y"
                                       {printf("MUL_ASSIGN\n");}
#line 2023 "./build/y.tab.c"
    break;

  case 107: /* assignvar: Expression DIV_ASSIGN Expression  */
#line 440 "./compiler.y"
                                       {printf("DIV_ASSIGN\n");}
#line 2029 "./build/y.tab.c"
    break;

  case 108: /* assignvar: Expression REM_ASSIGN Expression  */
#line 441 "./compiler.y"
                                       {printf("REM_ASSIGN\n");}
#line 2035 "./build/y.tab.c"
    break;

  case 109: /* assignvar: Expression SHR_ASSIGN Expression  */
#line 442 "./compiler.y"
                                       {printf("SHR_ASSIGN\n");}
#line 2041 "./build/y.tab.c"
    break;

  case 110: /* assignvar: Expression SHL_ASSIGN Expression  */
#line 443 "./compiler.y"
                                       {printf("SHL_ASSIGN\n");}
#line 2047 "./build/y.tab.c"
    break;

  case 111: /* assignvar: Expression BAN_ASSIGN Expression  */
#line 444 "./compiler.y"
                                       {printf("BAN_ASSIGN\n");}
#line 2053 "./build/y.tab.c"
    break;

  case 112: /* assignvar: Expression BOR_ASSIGN Expression  */
#line 445 "./compiler.y"
                                       {printf("BOR_ASSIGN\n");}
#line 2059 "./build/y.tab.c"
    break;

  case 113: /* assignvar: Expression BXO_ASSIGN Expression  */
#line 446 "./compiler.y"
                                       {printf("BXO_ASSIGN\n");}
#line 2065 "./build/y.tab.c"
    break;

  case 114: /* AddAdd: Expression INC_ASSIGN  */
#line 450 "./compiler.y"
                            {printf("INC_ASSIGN\n");}
#line 2071 "./build/y.tab.c"
    break;

  case 115: /* AddAdd: Expression DEC_ASSIGN  */
#line 451 "./compiler.y"
                            {printf("DEC_ASSIGN\n");}
#line 2077 "./build/y.tab.c"
    break;


#line 2081 "./build/y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 455 "./compiler.y"

/* C code section */
