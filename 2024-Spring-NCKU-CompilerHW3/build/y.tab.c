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
    int flagendl=0;
    int isif=0;
    int currentlebal=0;
    Object* current;
    Object* addrsave;
    int ifarray[20];
    int currentif=0;
    int iflabel=0;
    int tempForIF=100;
    int whileforarray[20];
    int currentwhilefor=0;
    int whileforlabel=0;
    int arrayinit=0;
    int isarray=0;
    int arrayassign=0;
    int arraycurrent=0;
    int breaktype=0;
    int mainflag=0;

#line 104 "./build/y.tab.c"

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
  YYSYMBOL_69_4 = 69,                      /* $@4  */
  YYSYMBOL_FunctionDefStmt = 70,           /* FunctionDefStmt  */
  YYSYMBOL_71_5 = 71,                      /* $@5  */
  YYSYMBOL_72_6 = 72,                      /* $@6  */
  YYSYMBOL_73_7 = 73,                      /* $@7  */
  YYSYMBOL_FunctionParameterStmtList = 74, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 75,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 76,                  /* StmtList  */
  YYSYMBOL_Stmt = 77,                      /* Stmt  */
  YYSYMBOL_78_8 = 78,                      /* $@8  */
  YYSYMBOL_79_9 = 79,                      /* $@9  */
  YYSYMBOL_80_10 = 80,                     /* $@10  */
  YYSYMBOL_81_11 = 81,                     /* $@11  */
  YYSYMBOL_82_12 = 82,                     /* $@12  */
  YYSYMBOL_83_13 = 83,                     /* $@13  */
  YYSYMBOL_84_14 = 84,                     /* $@14  */
  YYSYMBOL_85_15 = 85,                     /* $@15  */
  YYSYMBOL_86_16 = 86,                     /* $@16  */
  YYSYMBOL_forParm = 87,                   /* forParm  */
  YYSYMBOL_88_17 = 88,                     /* $@17  */
  YYSYMBOL_89_18 = 89,                     /* $@18  */
  YYSYMBOL_ifStmt = 90,                    /* ifStmt  */
  YYSYMBOL_91_19 = 91,                     /* $@19  */
  YYSYMBOL_CoutParmListStmt = 92,          /* CoutParmListStmt  */
  YYSYMBOL_93_20 = 93,                     /* $@20  */
  YYSYMBOL_94_21 = 94,                     /* $@21  */
  YYSYMBOL_ArrayParameterStmt = 95,        /* ArrayParameterStmt  */
  YYSYMBOL_Expression = 96,                /* Expression  */
  YYSYMBOL_97_22 = 97,                     /* $@22  */
  YYSYMBOL_dimension = 98,                 /* dimension  */
  YYSYMBOL_99_23 = 99,                     /* $@23  */
  YYSYMBOL_Callist = 100,                  /* Callist  */
  YYSYMBOL_CalculateFun = 101,             /* CalculateFun  */
  YYSYMBOL_factor6 = 102,                  /* factor6  */
  YYSYMBOL_factor5 = 103,                  /* factor5  */
  YYSYMBOL_factor4 = 104,                  /* factor4  */
  YYSYMBOL_factor3 = 105,                  /* factor3  */
  YYSYMBOL_factor2 = 106,                  /* factor2  */
  YYSYMBOL_factor = 107,                   /* factor  */
  YYSYMBOL_sign = 108,                     /* sign  */
  YYSYMBOL_term = 109,                     /* term  */
  YYSYMBOL_assignvar = 110,                /* assignvar  */
  YYSYMBOL_111_24 = 111,                   /* $@24  */
  YYSYMBOL_112_25 = 112,                   /* $@25  */
  YYSYMBOL_113_26 = 113,                   /* $@26  */
  YYSYMBOL_114_27 = 114,                   /* $@27  */
  YYSYMBOL_115_28 = 115,                   /* $@28  */
  YYSYMBOL_116_29 = 116,                   /* $@29  */
  YYSYMBOL_117_30 = 117,                   /* $@30  */
  YYSYMBOL_118_31 = 118,                   /* $@31  */
  YYSYMBOL_119_32 = 119,                   /* $@32  */
  YYSYMBOL_120_33 = 120,                   /* $@33  */
  YYSYMBOL_121_34 = 121,                   /* $@34  */
  YYSYMBOL_AddAdd = 122                    /* AddAdd  */
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
#define YYLAST   451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  138
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

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
       0,    90,    90,    90,    91,    95,    96,   100,   101,   105,
     105,   107,   111,   130,   153,   161,   175,   175,   175,   186,
     194,   207,   223,   224,   206,   302,   303,   304,   307,   313,
     323,   324,   327,   328,   329,   339,   340,   341,   341,   341,
     352,   352,   365,   369,   369,   373,   365,   379,   379,   379,
     387,   397,   402,   413,   417,   413,   426,   439,   439,   444,
     450,   450,   465,   465,   483,   484,   490,   491,   492,   493,
     508,   508,   531,   531,   532,   535,   536,   537,   541,   542,
     546,   547,   553,   554,   557,   560,   566,   567,   587,   596,
     617,   638,   662,   663,   669,   670,   675,   682,   683,   688,
     693,   702,   703,   707,   708,   709,   716,   717,   726,   735,
     739,   749,   796,   802,   819,   819,   847,   847,   858,   858,
     869,   869,   880,   880,   891,   891,   902,   902,   914,   914,
     926,   926,   938,   938,   947,   947,   959,   965,   971
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
  "$@3", "$@4", "FunctionDefStmt", "$@5", "$@6", "$@7",
  "FunctionParameterStmtList", "FunctionParameterStmt", "StmtList", "Stmt",
  "$@8", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16",
  "forParm", "$@17", "$@18", "ifStmt", "$@19", "CoutParmListStmt", "$@20",
  "$@21", "ArrayParameterStmt", "Expression", "$@22", "dimension", "$@23",
  "Callist", "CalculateFun", "factor6", "factor5", "factor4", "factor3",
  "factor2", "factor", "sign", "term", "assignvar", "$@24", "$@25", "$@26",
  "$@27", "$@28", "$@29", "$@30", "$@31", "$@32", "$@33", "$@34", "AddAdd", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-163)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-135)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -163,    20,   -14,  -163,    -4,   -14,  -163,  -163,  -163,  -163,
       6,  -163,   -18,   -10,     3,  -163,    32,   154,    -8,    12,
      23,   266,   266,   211,   -39,  -163,  -163,  -163,  -163,    58,
    -163,  -163,    48,    60,    17,   123,    81,    22,    96,  -163,
    -163,    30,   256,  -163,    33,    69,  -163,    72,    53,    49,
    -163,  -163,  -163,   266,  -163,    14,    43,    56,    59,   -20,
      14,    14,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,    14,    14,    14,   -20,  -163,    71,
      32,    77,    23,    91,  -163,    92,    -5,   266,    90,    14,
    -163,  -163,    60,    17,   123,   123,   123,    81,    81,    81,
      81,    81,    22,    96,    96,  -163,  -163,  -163,    95,  -163,
    -163,  -163,  -163,   101,   343,    14,    97,  -163,  -163,  -163,
      14,   382,  -163,  -163,   266,   102,  -163,  -163,  -163,   100,
    -163,    32,  -163,  -163,  -163,   121,    80,  -163,   417,   128,
     136,  -163,   137,   191,   143,   152,  -163,   151,   150,  -163,
    -163,  -163,   186,   182,   185,   192,   184,   204,   201,   202,
     210,   213,   215,  -163,  -163,  -163,   237,    32,    32,   382,
     205,  -163,  -163,    32,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,  -163,  -163,   134,   -29,   190,
      14,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,   193,  -163,  -163,    14,  -163,    -6,   183,
      14,    48,   199,  -163,  -163,  -163,  -163,    48,   382,   200,
     382,   197,   235,  -163,   284,    32,  -163,   382,  -163,   373,
    -163,  -163,   333,  -163,  -163,  -163
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,    11,     1,     0,     3,     6,     7,     8,    21,
       0,     5,     0,    14,    10,    22,     0,     0,    19,     0,
      27,     0,     0,     0,   111,   112,   109,   108,   110,     0,
      67,    15,    68,    78,    80,    82,    86,    92,    94,    97,
     101,   111,     0,    65,     0,     0,    20,    12,     0,    23,
      26,   105,   102,     0,   103,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,    64,     0,
       0,    28,     0,     0,   104,     0,    76,     0,    71,     0,
      66,   106,    79,    81,    83,    84,    85,    87,    88,    91,
      90,    89,    93,    95,    96,    99,    98,   100,     0,    17,
      13,    29,    25,     0,    69,    77,     0,    72,   107,   113,
      77,     0,    75,    74,     0,     0,    62,    37,    40,     0,
      42,    51,    50,     9,    32,     0,     0,    31,    52,     0,
       0,    18,    60,     0,     0,     0,    47,     0,     0,    36,
      24,    30,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    73,    33,     0,     0,     0,     0,
      11,    43,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    38,     0,     0,     0,
       0,   115,   117,   119,   121,   123,   125,   127,   129,   131,
     133,   135,    61,     0,    41,    53,     0,    48,     0,     0,
       0,    56,     0,    44,    57,    59,    39,    54,     0,     0,
       0,     0,     0,    45,     0,     0,    49,     0,    58,   114,
     138,    55,     0,   136,   137,    46
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -163,  -163,  -163,  -163,   249,     0,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,   173,  -162,  -135,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163,  -163,  -163,    -9,   -16,  -163,  -163,  -163,
     -45,   -21,   203,   207,    68,   149,   196,   -27,   -36,   -11,
      36,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,  -163,
    -163,  -163,  -163
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,   135,    10,    14,    45,   120,
       8,    12,    20,    83,    49,    50,   136,   137,   144,   203,
     145,   147,   190,   219,   227,   170,   212,   189,   210,   221,
     216,   220,   142,   166,   143,    30,   138,    56,    88,   124,
      85,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     139,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   231
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,   151,     7,    60,    18,     7,    44,   187,    59,    46,
      51,    52,    54,    58,    16,    55,   -16,    60,    60,   -70,
       3,    77,    21,    62,    63,    22,    64,   205,   206,    23,
       4,   108,    71,    72,    86,    91,    15,   105,   106,   107,
      21,     9,    84,    22,   103,   104,   115,    23,    17,   213,
      17,    13,   151,   118,    19,    86,   222,    47,   224,    41,
      25,    26,    27,    28,   110,   232,    21,    48,    42,    22,
     122,    60,   111,    23,   215,   125,   116,    24,    25,    26,
      27,    28,    61,   126,    76,    70,    29,   151,    21,   151,
      17,    22,    78,    79,    86,    23,    80,   151,    81,    86,
      82,    87,    57,    24,    25,    26,    27,    28,    73,    74,
      75,    89,    29,   140,    90,   148,    17,   127,   128,   129,
     130,   131,   132,   109,   133,    24,    25,    26,    27,    28,
      94,    95,    96,   150,    29,    17,   134,   126,    17,    65,
      66,    67,    21,    68,    69,    22,   113,   114,   117,    23,
     119,   185,   186,   121,   146,   141,   123,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   208,
     188,   127,   128,   129,   130,   131,   132,   149,   133,    24,
      25,    26,    27,    28,   163,   211,   126,   204,    29,   217,
     134,    21,    17,   165,    22,   164,   167,   168,    23,    41,
      25,    26,    27,    28,   169,   171,   172,   174,    42,   229,
     173,   175,   177,    43,    97,    98,    99,   100,   101,   176,
     127,   128,   129,   130,   131,   132,    53,   133,    24,    25,
      26,    27,    28,   178,   179,   214,   180,    29,   126,   134,
     181,    17,   184,    21,   182,   207,    22,   183,   209,   133,
      23,   218,   223,   225,    11,   112,    41,    25,    26,    27,
      28,   230,     0,    92,    21,    42,   102,    22,    93,     0,
       0,    23,   127,   128,   129,   130,   131,   132,     0,   133,
      24,    25,    26,    27,    28,     0,     0,   126,   226,    29,
       0,   134,    21,    17,     0,    22,     0,     0,     0,    23,
      57,    41,    25,    26,    27,    28,     0,     0,     0,     0,
      42,    41,    25,    26,    27,    28,     0,     0,     0,     0,
      42,   127,   128,   129,   130,   131,   132,     0,   133,    24,
      25,    26,    27,    28,     0,     0,   126,   228,    29,     0,
     134,    21,    17,     0,    22,     0,     0,  -113,    23,  -113,
    -113,     0,  -113,  -113,     0,  -113,  -113,  -113,     0,  -113,
    -113,  -113,     0,  -113,  -113,  -113,  -113,     0,     0,     0,
     127,   128,   129,   130,   131,   132,     0,   133,    24,    25,
      26,    27,    28,     0,     0,   126,   235,    29,     0,   134,
      21,    17,     0,    22,     0,     0,     0,    23,  -116,  -118,
    -120,  -122,  -124,  -130,  -132,  -134,  -126,  -128,   233,   234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   127,
     128,   129,   130,   131,   132,     0,   133,    24,    25,    26,
      27,    28,     0,     0,     0,     0,    29,     0,   134,     0,
      17,  -114,  -116,  -118,  -120,  -122,  -124,  -130,  -132,  -134,
    -126,  -128
};

static const yytype_int16 yycheck[] =
{
      16,   136,     2,    23,    13,     5,    17,   169,    29,    18,
      21,    22,    23,    29,    24,    54,    24,    23,    23,    58,
       0,    42,     8,     6,     7,    11,     9,    56,    57,    15,
      44,    76,    10,    11,    55,    55,    54,    73,    74,    75,
       8,    45,    53,    11,    71,    72,    51,    15,    58,    55,
      58,    45,   187,    89,    51,    76,   218,    45,   220,    45,
      46,    47,    48,    49,    80,   227,     8,    44,    54,    11,
     115,    23,    81,    15,   209,   120,    87,    45,    46,    47,
      48,    49,    22,     3,    54,     4,    54,   222,     8,   224,
      58,    11,    59,    24,   115,    15,    24,   232,    45,   120,
      51,    58,    44,    45,    46,    47,    48,    49,    12,    13,
      14,    55,    54,   124,    55,   131,    58,    37,    38,    39,
      40,    41,    42,    52,    44,    45,    46,    47,    48,    49,
      62,    63,    64,    53,    54,    58,    56,     3,    58,    16,
      17,    18,     8,    20,    21,    11,    55,    55,    58,    15,
      55,   167,   168,    52,    54,    53,    59,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   190,
     170,    37,    38,    39,    40,    41,    42,    56,    44,    45,
      46,    47,    48,    49,    56,   206,     3,    53,    54,   210,
      56,     8,    58,    56,    11,    59,     5,    54,    15,    45,
      46,    47,    48,    49,    52,    54,    56,    25,    54,   225,
      24,    26,    28,    59,    65,    66,    67,    68,    69,    27,
      37,    38,    39,    40,    41,    42,    15,    44,    45,    46,
      47,    48,    49,    29,    33,    52,    34,    54,     3,    56,
      30,    58,     5,     8,    31,    55,    11,    32,    55,    44,
      15,    52,    52,    56,     5,    82,    45,    46,    47,    48,
      49,   225,    -1,    60,     8,    54,    70,    11,    61,    -1,
      -1,    15,    37,    38,    39,    40,    41,    42,    -1,    44,
      45,    46,    47,    48,    49,    -1,    -1,     3,    53,    54,
      -1,    56,     8,    58,    -1,    11,    -1,    -1,    -1,    15,
      44,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    45,    46,    47,    48,    49,    -1,    -1,    -1,    -1,
      54,    37,    38,    39,    40,    41,    42,    -1,    44,    45,
      46,    47,    48,    49,    -1,    -1,     3,    53,    54,    -1,
      56,     8,    58,    -1,    11,    -1,    -1,     4,    15,     6,
       7,    -1,     9,    10,    -1,    12,    13,    14,    -1,    16,
      17,    18,    -1,    20,    21,    22,    23,    -1,    -1,    -1,
      37,    38,    39,    40,    41,    42,    -1,    44,    45,    46,
      47,    48,    49,    -1,    -1,     3,    53,    54,    -1,    56,
       8,    58,    -1,    11,    -1,    -1,    -1,    15,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    41,    42,    -1,    44,    45,    46,    47,
      48,    49,    -1,    -1,    -1,    -1,    54,    -1,    56,    -1,
      58,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    61,    62,     0,    44,    63,    64,    65,    70,    45,
      66,    64,    71,    45,    67,    54,    24,    58,    95,    51,
      72,     8,    11,    15,    45,    46,    47,    48,    49,    54,
      95,    96,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    45,    54,    59,   109,    68,    95,    45,    44,    74,
      75,   109,   109,    15,   109,    54,    97,    44,    96,   101,
      23,    22,     6,     7,     9,    16,    17,    18,    20,    21,
       4,    10,    11,    12,    13,    14,    54,   101,    59,    24,
      24,    45,    51,    73,   109,   100,   101,    58,    98,    55,
      55,    55,   102,   103,   104,   104,   104,   105,   105,   105,
     105,   105,   106,   107,   107,   108,   108,   108,   100,    52,
      96,    95,    75,    55,    55,    51,   109,    58,   108,    55,
      69,    52,   100,    59,    99,   100,     3,    37,    38,    39,
      40,    41,    42,    44,    56,    65,    76,    77,    96,   110,
     109,    53,    92,    94,    78,    80,    54,    81,    96,    56,
      53,    77,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,    56,    59,    56,    93,     5,    54,    52,
      85,    54,    56,    24,    25,    26,    27,    28,    29,    33,
      34,    30,    31,    32,     5,    96,    96,    76,    65,    87,
      82,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    79,    53,    56,    57,    55,   101,    55,
      88,   101,    86,    55,    52,    77,    90,   101,    52,    83,
      91,    89,    76,    52,    76,    56,    53,    84,    53,    96,
     110,   122,    76,    35,    36,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    62,    61,    61,    63,    63,    64,    64,    66,
      65,    65,    67,    67,    67,    67,    68,    69,    67,    67,
      67,    71,    72,    73,    70,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    77,    78,    79,    77,
      80,    77,    81,    82,    83,    84,    77,    85,    86,    77,
      77,    77,    77,    88,    89,    87,    87,    91,    90,    90,
      93,    92,    94,    92,    95,    95,    96,    96,    96,    96,
      97,    96,    99,    98,    98,   100,   100,   100,   101,   101,
     102,   102,   103,   103,   103,   103,   104,   104,   104,   104,
     104,   104,   105,   105,   106,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   111,   110,   112,   110,   113,   110,
     114,   110,   115,   110,   116,   110,   117,   110,   118,   110,
     119,   110,   120,   110,   121,   110,   122,   122,   122
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     0,
       3,     0,     3,     5,     1,     3,     0,     0,     8,     2,
       3,     0,     0,     0,    11,     3,     1,     0,     2,     3,
       2,     1,     1,     3,     3,     2,     2,     0,     0,     7,
       0,     5,     0,     0,     0,     0,    11,     0,     0,     9,
       1,     1,     1,     0,     0,     7,     3,     0,     4,     1,
       0,     4,     0,     3,     3,     2,     3,     1,     1,     4,
       0,     3,     0,     5,     3,     3,     1,     0,     1,     3,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     1,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     3,     2,     3,     4,     1,     1,
       1,     1,     1,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     2,     2,     1
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
#line 90 "./compiler.y"
      { pushScope(); }
#line 1430 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 90 "./compiler.y"
                                      { dumpScope(); }
#line 1436 "./build/y.tab.c"
    break;

  case 9: /* $@2: %empty  */
#line 105 "./compiler.y"
                { DefinedType = (yyvsp[0].var_type);
    }
#line 1443 "./build/y.tab.c"
    break;

  case 12: /* DefineVariableStmtList: DefineVariableStmtList ',' IDENT  */
#line 112 "./compiler.y"
    {
        currentaddr=createassign(DefinedType, (yyvsp[0].s_var));
        addnew(DefinedType, (yyvsp[0].s_var), yylineno);
        switch(DefinedType){
            case OBJECT_TYPE_FLOAT:
                codeRaw("ldc 0.0");
                code("fstore %d",currentaddr);
                break;
            case OBJECT_TYPE_INT:
                codeRaw("ldc 0");
                code("istore %d",currentaddr);
                break;
            case OBJECT_TYPE_BOOL:
                codeRaw("ldc 0");
                code("astore %d",currentaddr);
                break;
        }
    }
#line 1466 "./build/y.tab.c"
    break;

  case 13: /* DefineVariableStmtList: DefineVariableStmtList ',' IDENT VAL_ASSIGN Expression  */
#line 131 "./compiler.y"
    {
        if(isarray==1){
            codeRaw("iaload");
            isarray=0;
        }
        if(DefinedType==1){
            DefinedType = (yyvsp[-3].object_val).type;
        }
        currentaddr=createassign(DefinedType, (yyvsp[-2].s_var));
        addnew(DefinedType, (yyvsp[-2].s_var), yylineno);
        switch(DefinedType){
            case OBJECT_TYPE_FLOAT:
                code("fstore %d",currentaddr);
                break;
            case OBJECT_TYPE_INT:
                code("istore %d",currentaddr);
                break;
            case OBJECT_TYPE_BOOL:
                code("astore %d",currentaddr);
                break;
        }
    }
#line 1493 "./build/y.tab.c"
    break;

  case 14: /* DefineVariableStmtList: IDENT  */
#line 154 "./compiler.y"
    {   
        strcpy(autoVarName, (yyvsp[0].s_var));
        currentaddr=createassign(DefinedType, (yyvsp[0].s_var));
        addnew(DefinedType, (yyvsp[0].s_var), yylineno);
        codeRaw("ldc 0");
        precedenc_assign(DefinedType,currentaddr);
    }
#line 1505 "./build/y.tab.c"
    break;

  case 15: /* DefineVariableStmtList: IDENT VAL_ASSIGN Expression  */
#line 162 "./compiler.y"
    {
        if(isarray==1){
            codeRaw("iaload");
            isarray=0;
        }
        if(DefinedType==1){
            DefinedType = (yyvsp[-1].object_val).type;
        }
        currentaddr=createassign(DefinedType, (yyvsp[-2].s_var));
        //printf("testtesttest:%d",currentaddr);
        precedenc_assign(DefinedType,currentaddr);
        addnew(DefinedType, (yyvsp[-2].s_var), yylineno);
    }
#line 1523 "./build/y.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 175 "./compiler.y"
                               {array1(DefinedType);arrayinit=1;}
#line 1529 "./build/y.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 175 "./compiler.y"
                                                                                 {arraycurrent=0;arrayCount = 0;}
#line 1535 "./build/y.tab.c"
    break;

  case 18: /* DefineVariableStmtList: IDENT ArrayParameterStmt $@3 VAL_ASSIGN '{' $@4 Callist '}'  */
#line 176 "./compiler.y"
    {
        if(DefinedType==1){
            DefinedType = (yyvsp[-6].object_val).type;
        }
        printf("create array: %d\n",arrayCount);
        arrayassign=createassign(DefinedType, (yyvsp[-7].s_var));
        addnew(DefinedType, (yyvsp[-7].s_var), yylineno);
        arrayinit=0;
        code("astore %d",arrayassign);
    }
#line 1550 "./build/y.tab.c"
    break;

  case 19: /* DefineVariableStmtList: IDENT ArrayParameterStmt  */
#line 187 "./compiler.y"
    {
        array1(DefinedType);
        arrayassign=createassign(DefinedType, (yyvsp[-1].s_var));
        addnew(DefinedType, (yyvsp[-1].s_var), yylineno);
        arrayinit=0;
        code("astore %d",arrayassign);
    }
#line 1562 "./build/y.tab.c"
    break;

  case 20: /* DefineVariableStmtList: IDENT ArrayParameterStmt ArrayParameterStmt  */
#line 195 "./compiler.y"
    {
        arrayinit=0;
        arrayassign = createassign(DefinedType, (yyvsp[-2].s_var));
        addnew(DefinedType, (yyvsp[-2].s_var), yylineno);
        codeRaw("multianewarray [[I 2");
        code("astore %d", arrayassign);
    }
#line 1574 "./build/y.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 207 "./compiler.y"
    { 
        funcTypeIndex = 0;
        funcType[funcTypeIndex++] = (yyvsp[-1].var_type);
        indextozero();
        addnew(10, (yyvsp[0].s_var), yylineno);
        createFunction((yyvsp[-1].var_type), (yyvsp[0].s_var));
        if(strcmp((yyvsp[0].s_var), "main")!=0){
            setlocalvariable(-1);//reset localvariableAddress in main.c
            setlocalvariable(1);//set local_addr in add_new
        }
        if(strcmp((yyvsp[0].s_var),"main")==0){
            mainflag = 1;
        }else{
            mainflag = 0;
        }
    }
#line 1595 "./build/y.tab.c"
    break;

  case 22: /* $@6: %empty  */
#line 223 "./compiler.y"
        {indextozero();pushScope();}
#line 1601 "./build/y.tab.c"
    break;

  case 23: /* $@7: %empty  */
#line 224 "./compiler.y"
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
                    strcat(sig, "Z");
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
                strcat(sig, "Z");
                break;
            case 9:
                strcat(sig, "Ljava/lang/String;");
                break;
            default:
                printf("invalid\n");
                break;
        }
        Object* temp = searchVar((yyvsp[-4].s_var), 1);
        current=temp;
        if(temp!=NULL){
            strcpy(temp->symbol->func_sig, sig);
            if(strcmp(temp->symbol->name,"main")==0){
                code(".method public static %s([Ljava/lang/String;)V",temp->symbol->name);
            }
            else{
                code(".method public static %s%s",temp->symbol->name,temp->symbol->func_sig);
            }
            codeRaw(".limit stack 500");
            codeRaw(".limit locals 500");
        }else{
            printf("invalid\n");
        }
    }
#line 1674 "./build/y.tab.c"
    break;

  case 24: /* FunctionDefStmt: VARIABLE_T IDENT $@5 '(' $@6 FunctionParameterStmtList $@7 ')' '{' StmtList '}'  */
#line 292 "./compiler.y"
                         {
        setlocalvariable(0);
        if(mainflag==1){
            codeRaw("return");
        }
        codeRaw(".end method");dumpScope(); 
    }
#line 1686 "./build/y.tab.c"
    break;

  case 28: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 308 "./compiler.y"
    { 
        funcType[funcTypeIndex++] = (yyvsp[-1].var_type);
        pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), 1);
        addnew((yyvsp[-1].var_type), (yyvsp[0].s_var), yylineno);
    }
#line 1696 "./build/y.tab.c"
    break;

  case 29: /* FunctionParameterStmt: VARIABLE_T IDENT ArrayParameterStmt  */
#line 314 "./compiler.y"
    {
        funcType[funcTypeIndex++] = (yyvsp[-2].var_type); 
        pushFunParm((yyvsp[-2].var_type), (yyvsp[-1].s_var), VAR_FLAG_DEFAULT);
        addnew((yyvsp[-2].var_type), (yyvsp[-1].s_var), yylineno);
    }
#line 1706 "./build/y.tab.c"
    break;

  case 33: /* Stmt: COUT CoutParmListStmt ';'  */
#line 328 "./compiler.y"
                                { stdoutPrint(); printf("\n"); }
#line 1712 "./build/y.tab.c"
    break;

  case 34: /* Stmt: RETURN Expression ';'  */
#line 330 "./compiler.y"
    {   printf("RETURN\n"); //別刪
        if(mainflag!=1){
            if((yyvsp[-1].object_val).type==6){
                codeRaw("freturn");
            }else{
                codeRaw("ireturn");
            }
        }
    }
#line 1726 "./build/y.tab.c"
    break;

  case 37: /* $@8: %empty  */
#line 341 "./compiler.y"
         {isif=1;}
#line 1732 "./build/y.tab.c"
    break;

  case 38: /* $@9: %empty  */
#line 341 "./compiler.y"
                                  {
        codeRaw("dup");
        code("istore %d", tempForIF);
        tempForIF--;
        code("ifeq ifEnd%d",iflabel);
        code("if%d:", iflabel);
        ifarray[currentif] = iflabel;
        currentif++;
        iflabel++;
        printf("IF\n");
    }
#line 1748 "./build/y.tab.c"
    break;

  case 40: /* $@10: %empty  */
#line 352 "./compiler.y"
           {isif=1;
        printf("ELSE\n");
        tempForIF++;
        code("iload %d", tempForIF);
        code("ifne elseEnd%d", iflabel);
        ifarray[currentif] = iflabel;
        currentif++;
        iflabel++;
    pushScope();}
#line 1762 "./build/y.tab.c"
    break;

  case 41: /* Stmt: ELSE $@10 '{' StmtList '}'  */
#line 360 "./compiler.y"
                                   {
        currentif--;
        code("elseEnd%d:", ifarray[currentif]);
        dumpScope();
    }
#line 1772 "./build/y.tab.c"
    break;

  case 42: /* $@11: %empty  */
#line 365 "./compiler.y"
            {
        breaktype = 1;
        code("while%d:", whileforlabel);
        whileforarray[currentwhilefor] = whileforlabel;
    }
#line 1782 "./build/y.tab.c"
    break;

  case 43: /* $@12: %empty  */
#line 369 "./compiler.y"
         {printf("WHILE\n");}
#line 1788 "./build/y.tab.c"
    break;

  case 44: /* $@13: %empty  */
#line 369 "./compiler.y"
                                              {
        code("ifeq whileEnd%d", whileforarray[currentwhilefor]);
        currentwhilefor++;
        whileforlabel++;
    }
#line 1798 "./build/y.tab.c"
    break;

  case 45: /* $@14: %empty  */
#line 373 "./compiler.y"
          {pushScope();}
#line 1804 "./build/y.tab.c"
    break;

  case 46: /* Stmt: WHILE $@11 '(' $@12 CalculateFun ')' $@13 '{' $@14 StmtList '}'  */
#line 373 "./compiler.y"
                                      {
        dumpScope();
        currentwhilefor--;
        code("goto while%d", whileforarray[currentwhilefor]);
        code("whileEnd%d:", whileforarray[currentwhilefor]);    
    }
#line 1815 "./build/y.tab.c"
    break;

  case 47: /* $@15: %empty  */
#line 379 "./compiler.y"
             { indextozero(); printf("FOR\n");pushScope();}
#line 1821 "./build/y.tab.c"
    break;

  case 48: /* $@16: %empty  */
#line 379 "./compiler.y"
                                                                         {
        code("forstmt%d:", whileforarray[currentwhilefor-1]);
    }
#line 1829 "./build/y.tab.c"
    break;

  case 49: /* Stmt: FOR '(' $@15 forParm ')' $@16 '{' StmtList '}'  */
#line 381 "./compiler.y"
                       {
        dumpScope();
        currentwhilefor--;
        code("goto forAddAdd%d", whileforarray[currentwhilefor]);
        code("forEnd%d:", whileforarray[currentwhilefor]);
    }
#line 1840 "./build/y.tab.c"
    break;

  case 50: /* Stmt: BREAK  */
#line 387 "./compiler.y"
            {
        printf("BREAK\n");
        if(breaktype==1){
            code("goto whileEnd%d", whileforarray[currentwhilefor-1]);
        }
        if(breaktype==2){
            code("goto forEnd%d", whileforarray[currentwhilefor-1]);
        }
        breaktype = 0;
    }
#line 1855 "./build/y.tab.c"
    break;

  case 51: /* Stmt: RETURN  */
#line 397 "./compiler.y"
             { 
        printf("RETURN\n");
        if(mainflag!=1){
            codeRaw("return");}
        }
#line 1865 "./build/y.tab.c"
    break;

  case 52: /* Stmt: Expression  */
#line 402 "./compiler.y"
                 {
        if(isarray==1){
            codeRaw("iaload");
            isarray=0;
        }
    }
#line 1876 "./build/y.tab.c"
    break;

  case 53: /* $@17: %empty  */
#line 413 "./compiler.y"
                            {
        breaktype=2;
        code("for%d:", whileforlabel);
        whileforarray[currentwhilefor] = whileforlabel;
    }
#line 1886 "./build/y.tab.c"
    break;

  case 54: /* $@18: %empty  */
#line 417 "./compiler.y"
                   {
        code("ifne forstmt%d", whileforarray[currentwhilefor]);
        code("goto forEnd%d", whileforarray[currentwhilefor]);
        code("forAddAdd%d:", whileforarray[currentwhilefor]);
    }
#line 1896 "./build/y.tab.c"
    break;

  case 55: /* forParm: DefineVariableStmt ';' $@17 CalculateFun $@18 ';' AddAdd  */
#line 421 "./compiler.y"
                {
        code("goto for%d", whileforarray[currentwhilefor]);
        currentwhilefor++;
        whileforlabel++;
    }
#line 1906 "./build/y.tab.c"
    break;

  case 56: /* forParm: DefineVariableStmt ':' CalculateFun  */
#line 427 "./compiler.y"
    {
        Object* temp = searchVar(autoVarName, 0); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            temp->type = (yyvsp[-1].object_val).type;
        }else{
            printf("invalid\n");
        }
    }
#line 1920 "./build/y.tab.c"
    break;

  case 57: /* $@19: %empty  */
#line 439 "./compiler.y"
          {pushScope();}
#line 1926 "./build/y.tab.c"
    break;

  case 58: /* ifStmt: '{' $@19 StmtList '}'  */
#line 439 "./compiler.y"
                                      {
        currentif--;
        code("ifEnd%d:", ifarray[currentif]);
        dumpScope();
    }
#line 1936 "./build/y.tab.c"
    break;

  case 59: /* ifStmt: Stmt  */
#line 444 "./compiler.y"
          {
        currentif--;
        code("ifEnd%d:", ifarray[currentif]);
    }
#line 1945 "./build/y.tab.c"
    break;

  case 60: /* $@20: %empty  */
#line 450 "./compiler.y"
                        {codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");}
#line 1951 "./build/y.tab.c"
    break;

  case 61: /* CoutParmListStmt: CoutParmListStmt $@20 SHL Expression  */
#line 451 "./compiler.y"
    {
    if(isarray==1){
        codeRaw("iaload");
        isarray=0;
    }
    if(flagendl==0){
        code("invokevirtual java/io/PrintStream/print(%s)V",getfunsig((yyvsp[-1].object_val).type));
    }
    else{
        codeRaw("invokevirtual java/io/PrintStream/println()V");
        flagendl=0;
    }
    pushFunInParm(&(yyvsp[-1].object_val));
    }
#line 1970 "./build/y.tab.c"
    break;

  case 62: /* $@21: %empty  */
#line 465 "./compiler.y"
      {codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");}
#line 1976 "./build/y.tab.c"
    break;

  case 63: /* CoutParmListStmt: $@21 SHL Expression  */
#line 466 "./compiler.y"
    {
        if(isarray==1){
            codeRaw("iaload");
            isarray=0;
        }
    if(flagendl==0){
        code("invokevirtual java/io/PrintStream/print(%s)V",getfunsig((yyvsp[-1].object_val).type));
    }
    else{
        codeRaw("invokevirtual java/io/PrintStream/println()V");
        flagendl=0;
    }
    pushFunInParm(&(yyvsp[-1].object_val));
    }
#line 1995 "./build/y.tab.c"
    break;

  case 65: /* ArrayParameterStmt: '[' ']'  */
#line 484 "./compiler.y"
              {funcType[funcTypeIndex++] = 0;}
#line 2001 "./build/y.tab.c"
    break;

  case 66: /* Expression: '(' Expression ')'  */
#line 490 "./compiler.y"
                         { (yyvsp[-3].object_val).type=(yyvsp[-2].object_val).type;}
#line 2007 "./build/y.tab.c"
    break;

  case 68: /* Expression: CalculateFun  */
#line 492 "./compiler.y"
                   {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type; }
#line 2013 "./build/y.tab.c"
    break;

  case 69: /* Expression: IDENT '(' Callist ')'  */
#line 494 "./compiler.y"
    {
        Object* temp = searchVar((yyvsp[-3].s_var), 1); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            //printf("current1");
            printf("IDENT (name=%s, address=%ld)\n",(yyvsp[-3].s_var),temp->symbol->addr);
            printf("call: %s%s\n", temp->symbol->name, temp->symbol->func_sig);
            (yyvsp[-4].object_val).type=temp->func_retype;
        }else{
            printf("invalid\n");
        }

        code("invokestatic Main/%s%s", temp->symbol->name, temp->symbol->func_sig);
    }
#line 2032 "./build/y.tab.c"
    break;

  case 70: /* $@22: %empty  */
#line 508 "./compiler.y"
            {
        Object* temp = searchVar((yyvsp[0].s_var), 0); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            code("aload %d",temp->symbol->addr);//testing
        }
    }
#line 2044 "./build/y.tab.c"
    break;

  case 71: /* Expression: IDENT $@22 dimension  */
#line 515 "./compiler.y"
    {
        Object* temp = searchVar((yyvsp[-2].s_var), 0); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            //printf("current2");
            printf("IDENT (name=%s, address=%ld)\n",(yyvsp[-2].s_var),temp->symbol->addr);
            (yyvsp[-3].object_val).type = temp->type;
            
        }else{
            printf("invalid\n");
        }
        isarray=1;
    }
#line 2062 "./build/y.tab.c"
    break;

  case 72: /* $@23: %empty  */
#line 531 "./compiler.y"
                   {codeRaw("aaload");}
#line 2068 "./build/y.tab.c"
    break;

  case 75: /* Callist: CalculateFun ',' Callist  */
#line 535 "./compiler.y"
                               { arrayCount++; }
#line 2074 "./build/y.tab.c"
    break;

  case 76: /* Callist: CalculateFun  */
#line 536 "./compiler.y"
                   {arrayCount++;}
#line 2080 "./build/y.tab.c"
    break;

  case 78: /* CalculateFun: factor6  */
#line 541 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 2086 "./build/y.tab.c"
    break;

  case 79: /* CalculateFun: CalculateFun LOR factor6  */
#line 542 "./compiler.y"
                                {printf("LOR\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;codeRaw("ior");}
#line 2092 "./build/y.tab.c"
    break;

  case 80: /* factor6: factor5  */
#line 546 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 2098 "./build/y.tab.c"
    break;

  case 81: /* factor6: factor6 LAN factor5  */
#line 547 "./compiler.y"
                          {printf("LAN\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;
        codeRaw("iand");
    }
#line 2106 "./build/y.tab.c"
    break;

  case 82: /* factor5: factor4  */
#line 553 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 2112 "./build/y.tab.c"
    break;

  case 83: /* factor5: factor5 BAN factor4  */
#line 554 "./compiler.y"
                          {printf("BAN\n");(yyval.object_val).type=OBJECT_TYPE_INT;
        codeRaw("iand");
    }
#line 2120 "./build/y.tab.c"
    break;

  case 84: /* factor5: factor5 BOR factor4  */
#line 557 "./compiler.y"
                          {printf("BOR\n");(yyval.object_val).type=OBJECT_TYPE_INT;
        codeRaw("ior");
    }
#line 2128 "./build/y.tab.c"
    break;

  case 85: /* factor5: factor5 BXO factor4  */
#line 560 "./compiler.y"
                          {printf("BXO\n");(yyval.object_val).type=OBJECT_TYPE_INT;
        codeRaw("ixor");    
    }
#line 2136 "./build/y.tab.c"
    break;

  case 86: /* factor4: factor3  */
#line 566 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 2142 "./build/y.tab.c"
    break;

  case 87: /* factor4: factor4 GTR factor3  */
#line 567 "./compiler.y"
                          {printf("GTR\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT){
            code("fcmpg");
            code("ifgt GTRfLabel%d",currentlebal);
            code("iconst_0");
            code("goto GTRfend%d",currentlebal);
            code("GTRfLabel%d:",currentlebal);
            code("iconst_1");
            code("GTRfend%d:",currentlebal);
            currentlebal++;
        }
        else{ code("if_icmpgt GTRLabel%d",currentlebal);
            code("iconst_0");
            code("goto GTRend%d",currentlebal);
            code("GTRLabel%d:",currentlebal);
            code("iconst_1");
            code("GTRend%d:",currentlebal);
            currentlebal++;
        }
    }
#line 2167 "./build/y.tab.c"
    break;

  case 88: /* factor4: factor4 LES factor3  */
#line 587 "./compiler.y"
                          {printf("LES\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;
        code("if_icmplt LESLabel%d",currentlebal);
        code("iconst_0");
        code("goto LESend%d",currentlebal);
        code("LESLabel%d:",currentlebal);
        code("iconst_1");
        code("LESend%d:",currentlebal);
        currentlebal++;
    }
#line 2181 "./build/y.tab.c"
    break;

  case 89: /* factor4: factor4 NEQ factor3  */
#line 596 "./compiler.y"
                          {printf("NEQ\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT){
            code("fcmpg");
            code("ifne NEQfLabel%d",currentlebal);
            code("iconst_0");
            code("goto NEQfend%d",currentlebal);
            code("NEQfLabel%d:",currentlebal);
            code("iconst_1");
            code("NEQfend%d:",currentlebal);
            currentlebal++;
        }
        else{
            code("if_icmpne NEQLabel%d",currentlebal);
            code("iconst_0");
            code("goto NEQend%d",currentlebal);
            code("NEQLabel%d:",currentlebal);
            code("iconst_1");
            code("NEQend%d:",currentlebal);
            currentlebal++;
            }
    }
#line 2207 "./build/y.tab.c"
    break;

  case 90: /* factor4: factor4 EQL factor3  */
#line 617 "./compiler.y"
                          {printf("EQL\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT){
            code("fcmpg");
            code("ifne EQLfLabel%d",currentlebal);
            code("iconst_0");
            code("goto NEQfend%d",currentlebal);
            code("NEQfLabel%d:",currentlebal);
            code("iconst_1");
            code("NEQfend%d:",currentlebal);
            currentlebal++;
        }
        else{
            code("if_icmpeq EQLabel%d",currentlebal);
            code("iconst_0");
            code("goto EQLend%d",currentlebal);
            code("EQLabel%d:",currentlebal);
            code("iconst_1");
            code("EQLend%d:",currentlebal);
            currentlebal++;
            }
    }
#line 2233 "./build/y.tab.c"
    break;

  case 91: /* factor4: factor4 GEQ factor3  */
#line 638 "./compiler.y"
                          {
        printf("GEQ\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT){
            code("fcmpg");
            code("ifge GEQfLabel%d",currentlebal);
            code("iconst_0");
            code("goto GEQfend%d",currentlebal);
            code("GEQfLabel%d:",currentlebal);
            code("iconst_1");
            code("GEQfend%d:",currentlebal);
            currentlebal++;
        }
        else{ code("if_icmpge GEQLabel%d",currentlebal);
            code("iconst_0");
            code("goto GEQend%d",currentlebal);
            code("GEQLabel%d:",currentlebal);
            code("iconst_1");
            code("GEQend%d:",currentlebal);
            currentlebal++;
        }
    }
#line 2259 "./build/y.tab.c"
    break;

  case 92: /* factor3: factor2  */
#line 662 "./compiler.y"
              {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 2265 "./build/y.tab.c"
    break;

  case 93: /* factor3: factor3 SHR factor2  */
#line 663 "./compiler.y"
                          {printf("SHR\n");(yyval.object_val).type=OBJECT_TYPE_INT;
        codeRaw("ishr");
    }
#line 2273 "./build/y.tab.c"
    break;

  case 94: /* factor2: factor  */
#line 669 "./compiler.y"
             {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 2279 "./build/y.tab.c"
    break;

  case 95: /* factor2: factor2 ADD factor  */
#line 670 "./compiler.y"
                         {printf("ADD\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;codeRaw("fadd");
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;codeRaw("iadd");}
    }
#line 2289 "./build/y.tab.c"
    break;

  case 96: /* factor2: factor2 SUB factor  */
#line 675 "./compiler.y"
                          {printf("SUB\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;codeRaw("fsub");
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;codeRaw("isub");}
    }
#line 2299 "./build/y.tab.c"
    break;

  case 97: /* factor: sign  */
#line 682 "./compiler.y"
           {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 2305 "./build/y.tab.c"
    break;

  case 98: /* factor: factor DIV sign  */
#line 683 "./compiler.y"
                      {printf("DIV\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;codeRaw("fdiv");
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;codeRaw("idiv");}
    }
#line 2315 "./build/y.tab.c"
    break;

  case 99: /* factor: factor MUL sign  */
#line 688 "./compiler.y"
                      {printf("MUL\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;codeRaw("fmul");
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;codeRaw("imul");}
    }
#line 2325 "./build/y.tab.c"
    break;

  case 100: /* factor: factor REM sign  */
#line 693 "./compiler.y"
                      {printf("REM\n");
        if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT||(yyvsp[0].object_val).type==OBJECT_TYPE_FLOAT){
            (yyval.object_val).type=OBJECT_TYPE_FLOAT;codeRaw("frem");
        }else{(yyval.object_val).type=OBJECT_TYPE_INT;codeRaw("irem");}
    }
#line 2335 "./build/y.tab.c"
    break;

  case 101: /* sign: term  */
#line 702 "./compiler.y"
           {(yyvsp[-1].object_val).type = (yyvsp[0].object_val).type;}
#line 2341 "./build/y.tab.c"
    break;

  case 102: /* sign: SUB term  */
#line 703 "./compiler.y"
               {printf("NEG\n");(yyvsp[-2].object_val).type = (yyvsp[0].object_val).type;
        if((yyvsp[0].object_val).type==6){codeRaw("fneg");}
        else{codeRaw("ineg");}
    }
#line 2350 "./build/y.tab.c"
    break;

  case 103: /* sign: NOT term  */
#line 707 "./compiler.y"
               {printf("NOT\n");(yyval.object_val).type=OBJECT_TYPE_BOOL;codeRaw("iconst_1");codeRaw("ixor");}
#line 2356 "./build/y.tab.c"
    break;

  case 104: /* sign: NOT NOT term  */
#line 708 "./compiler.y"
                   {printf("NOT\nNOT\n");(yyval.object_val).type=OBJECT_TYPE_BOOL; codeRaw("iconst_1");codeRaw("ixor");codeRaw("iconst_1");codeRaw("ixor");}
#line 2362 "./build/y.tab.c"
    break;

  case 105: /* sign: BNT term  */
#line 709 "./compiler.y"
               {printf("BNT\n"); (yyval.object_val).type=OBJECT_TYPE_INT; 
        codeRaw("iconst_m1");
        codeRaw("ixor");
    }
#line 2371 "./build/y.tab.c"
    break;

  case 107: /* term: '(' VARIABLE_T ')' sign  */
#line 717 "./compiler.y"
                              {casting((yyvsp[-2].var_type));
        if((yyvsp[0].object_val).type!=(yyvsp[-2].object_val).type){
            if((yyvsp[-2].object_val).type==OBJECT_TYPE_FLOAT){
            codeRaw("i2f");
        }
        else{
            codeRaw("f2i");
        }}
    }
#line 2385 "./build/y.tab.c"
    break;

  case 108: /* term: INT_LIT  */
#line 726 "./compiler.y"
              { (yyval.object_val) = (yyvsp[0].object_val); (yyval.object_val).type=OBJECT_TYPE_INT; 
            printf("INT_LIT %d\n",(yyvsp[0].i_var)); 
            if(arrayinit==1){
                codeRaw("dup");code("ldc %d",arraycurrent++);code("ldc %d",(yyvsp[0].i_var));codeRaw("iastore");
            }
            else{
                code("ldc %d",(yyvsp[0].i_var));   
            }
            }
#line 2399 "./build/y.tab.c"
    break;

  case 109: /* term: FLOAT_LIT  */
#line 735 "./compiler.y"
                { (yyval.object_val) = (yyvsp[0].object_val); (yyval.object_val).type=OBJECT_TYPE_FLOAT; 
            printf("FLOAT_LIT %.6f\n",(yyvsp[0].f_var)); 
            code("ldc %6f",(yyvsp[0].f_var));
            }
#line 2408 "./build/y.tab.c"
    break;

  case 110: /* term: BOOL_LIT  */
#line 739 "./compiler.y"
               { (yyval.object_val) = (yyvsp[0].object_val); (yyval.object_val).type=OBJECT_TYPE_BOOL; 
            if((yyvsp[0].b_var)){
                printf("BOOL_LIT %s\n","TRUE");
                codeRaw("iconst_1");
            }
            else{
                printf("BOOL_LIT %s\n","FALSE");  
                codeRaw("iconst_0");
            }
            }
#line 2423 "./build/y.tab.c"
    break;

  case 111: /* term: IDENT  */
#line 749 "./compiler.y"
            {
                Object* temp = searchVar((yyvsp[0].s_var), 0); //find inserted variable in the symbollist
                current=temp;
                if(temp!=NULL){
                    printf("IDENT (name=%s, address=%ld)\n",(yyvsp[0].s_var),temp->symbol->addr);
                    (yyval.object_val).type=temp->type; 
                    (yyval.object_val) = *temp;
                    if(temp->symbol->local_addr<0){
                        switch(temp->type){
                            case OBJECT_TYPE_INT:
                                code("iload %d",temp->symbol->addr);
                                break;
                            case OBJECT_TYPE_FLOAT:
                                code("fload %d",temp->symbol->addr);
                                break;
                            case OBJECT_TYPE_STR:
                                code("aload %d",temp->symbol->addr);
                                break;
                            case OBJECT_TYPE_BOOL:
                                code("iload %d",temp->symbol->addr);
                                break;
                        }
                    }else{
                        switch(temp->type){
                            case OBJECT_TYPE_INT:
                                code("iload %d",temp->symbol->local_addr);
                                break;
                            case OBJECT_TYPE_FLOAT:
                                code("fload %d",temp->symbol->local_addr);
                                break;
                            case OBJECT_TYPE_STR:
                                code("aload %d",temp->symbol->local_addr);
                                break;
                            case OBJECT_TYPE_BOOL:
                                code("iload %d",temp->symbol->local_addr);
                                break;
                        }
                    }
                    //printf("testing:%s,%ld,%d",$<s_var>1,temp->symbol->addr,temp->type);
                }else{
                    printf("IDENT (name=%s, address=-1)\n",(yyvsp[0].s_var));
                    (yyval.object_val) = endl;
                    (yyval.object_val).type=OBJECT_TYPE_STR; 
                    flagendl=1;
                    //codeRaw("invokevirtual java/io/PrintStream/println()V");
                }
            }
#line 2475 "./build/y.tab.c"
    break;

  case 112: /* term: STR_LIT  */
#line 796 "./compiler.y"
              { 
                (yyval.object_val).type=OBJECT_TYPE_STR;
                printf("STR_LIT \"%s\"\n",(yyvsp[0].s_var)); 
                code("ldc \"%s\"",(yyvsp[0].s_var));
                //codeRaw("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
              }
#line 2486 "./build/y.tab.c"
    break;

  case 113: /* term: IDENT '(' Callist ')'  */
#line 803 "./compiler.y"
    {
        Object* temp = searchVar((yyvsp[-3].s_var), 1); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            printf("IDENT (name=%s, address=%ld)\n",(yyvsp[-3].s_var),temp->symbol->addr);
            printf("call: %s%s\n", temp->symbol->name, temp->symbol->func_sig);
            (yyvsp[-4].object_val).type=temp->func_retype;
        }else{
            printf("invalid\n");
        }
        code("invokestatic Main/%s%s", temp->symbol->name, temp->symbol->func_sig);
    }
#line 2503 "./build/y.tab.c"
    break;

  case 114: /* $@24: %empty  */
#line 819 "./compiler.y"
                 {
        addrsave=current;
        if(isarray!=0){
            isarray=0;
            arrayassign = 1;
        }
        
    }
#line 2516 "./build/y.tab.c"
    break;

  case 115: /* assignvar: Expression $@24 VAL_ASSIGN Expression  */
#line 826 "./compiler.y"
                             {printf("EQL_ASSIGN\n");
       if((yyvsp[-3].object_val).type!=(yyvsp[-1].object_val).type&&arrayassign==0){
        if((yyvsp[-3].object_val).type==OBJECT_TYPE_FLOAT){
            codeRaw("i2f");
        }
        else{
            codeRaw("f2i");
        }}
        if(isarray==1){
            codeRaw("iaload");//checkok
            isarray=0;
        }
        if(arrayassign==1){
            codeRaw("iastore");
            arrayassign=0;
        }else{
            precedenc_s((yyvsp[-3].object_val).type,addrsave);
            codeRaw("pop");
        }
       
    }
#line 2542 "./build/y.tab.c"
    break;

  case 116: /* $@25: %empty  */
#line 847 "./compiler.y"
                 {addrsave=current;}
#line 2548 "./build/y.tab.c"
    break;

  case 117: /* assignvar: Expression $@25 ADD_ASSIGN Expression  */
#line 847 "./compiler.y"
                                                           {printf("ADD_ASSIGN\n");
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fadd");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("iadd");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2564 "./build/y.tab.c"
    break;

  case 118: /* $@26: %empty  */
#line 858 "./compiler.y"
                 {addrsave=current;}
#line 2570 "./build/y.tab.c"
    break;

  case 119: /* assignvar: Expression $@26 SUB_ASSIGN Expression  */
#line 858 "./compiler.y"
                                                           {printf("SUB_ASSIGN\n");
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fsub");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("isub");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2586 "./build/y.tab.c"
    break;

  case 120: /* $@27: %empty  */
#line 869 "./compiler.y"
                 {addrsave=current;precedenc(current->type,current);}
#line 2592 "./build/y.tab.c"
    break;

  case 121: /* assignvar: Expression $@27 MUL_ASSIGN Expression  */
#line 869 "./compiler.y"
                                                                                            {printf("MUL_ASSIGN\n");
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fmul");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("imul");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2608 "./build/y.tab.c"
    break;

  case 122: /* $@28: %empty  */
#line 880 "./compiler.y"
                 {addrsave=current;precedenc(current->type,current);}
#line 2614 "./build/y.tab.c"
    break;

  case 123: /* assignvar: Expression $@28 DIV_ASSIGN Expression  */
#line 880 "./compiler.y"
                                                                                            {printf("DIV_ASSIGN\n");
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fdiv");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("idiv");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2630 "./build/y.tab.c"
    break;

  case 124: /* $@29: %empty  */
#line 891 "./compiler.y"
                 {addrsave=current;precedenc(current->type,current);}
#line 2636 "./build/y.tab.c"
    break;

  case 125: /* assignvar: Expression $@29 REM_ASSIGN Expression  */
#line 891 "./compiler.y"
                                                                                            {printf("REM_ASSIGN\n");
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("frem");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("irem");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2652 "./build/y.tab.c"
    break;

  case 126: /* $@30: %empty  */
#line 902 "./compiler.y"
                 {addrsave=current;precedenc(current->type,current);}
#line 2658 "./build/y.tab.c"
    break;

  case 127: /* assignvar: Expression $@30 SHR_ASSIGN Expression  */
#line 902 "./compiler.y"
                                                                                            {printf("SHR_ASSIGN\n");
        //precedenc_type($<object_val>1.type);
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fshr");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("ishr");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2675 "./build/y.tab.c"
    break;

  case 128: /* $@31: %empty  */
#line 914 "./compiler.y"
                 {addrsave=current;precedenc(current->type,current);}
#line 2681 "./build/y.tab.c"
    break;

  case 129: /* assignvar: Expression $@31 SHL_ASSIGN Expression  */
#line 914 "./compiler.y"
                                                                                            {printf("SHL_ASSIGN\n"); 
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fshl");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("ishl");
                break;
        }
        //precedenc_type($<object_val>1.type);
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2698 "./build/y.tab.c"
    break;

  case 130: /* $@32: %empty  */
#line 926 "./compiler.y"
                 {addrsave=current;precedenc(current->type,current);}
#line 2704 "./build/y.tab.c"
    break;

  case 131: /* assignvar: Expression $@32 BAN_ASSIGN Expression  */
#line 926 "./compiler.y"
                                                                                            {printf("BAN_ASSIGN\n");
        //precedenc_type($<object_val>1.type);
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fand");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("iand");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2721 "./build/y.tab.c"
    break;

  case 132: /* $@33: %empty  */
#line 938 "./compiler.y"
                 {addrsave=current;precedenc(current->type,current);}
#line 2727 "./build/y.tab.c"
    break;

  case 133: /* assignvar: Expression $@33 BOR_ASSIGN Expression  */
#line 938 "./compiler.y"
                                                                                            {printf("BOR_ASSIGN\n");
        //precedenc_type($<object_val>1.type);
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_INT:
                codeRaw("ior");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2741 "./build/y.tab.c"
    break;

  case 134: /* $@34: %empty  */
#line 947 "./compiler.y"
                 {addrsave=current;precedenc(current->type,current);}
#line 2747 "./build/y.tab.c"
    break;

  case 135: /* assignvar: Expression $@34 BXO_ASSIGN Expression  */
#line 947 "./compiler.y"
                                                                                            {printf("BXO_ASSIGN\n");
        //precedenc_type($<object_val>1.type);
        switch((yyvsp[-3].object_val).type){
            case OBJECT_TYPE_INT:
                codeRaw("ixor");
                break;
        }
        precedenc_s((yyvsp[-3].object_val).type,addrsave);
    }
#line 2761 "./build/y.tab.c"
    break;

  case 136: /* AddAdd: Expression INC_ASSIGN  */
#line 959 "./compiler.y"
                            {
        printf("INC_ASSIGN\n");
        codeRaw("iconst_1");
        codeRaw("iadd");
        precedenc_s(current->type,current);
    }
#line 2772 "./build/y.tab.c"
    break;

  case 137: /* AddAdd: Expression DEC_ASSIGN  */
#line 965 "./compiler.y"
                            {
        printf("DEC_ASSIGN\n");
        codeRaw("iconst_1");
        codeRaw("isub");
        precedenc_s(current->type,current);
    }
#line 2783 "./build/y.tab.c"
    break;


#line 2787 "./build/y.tab.c"

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

#line 974 "./compiler.y"

/* C code section */
