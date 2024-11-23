/* Definition section */
%{
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
%}

/* Variable or self-defined structure */
%union {
    ObjectType var_type;

    bool b_var;
    int i_var;
    float f_var;
    char *s_var;

    Object object_val;
    SymbolData symbol_val;
}

/* Token without return */
%token COUT
%token SHR SHL BAN BOR BNT BXO ADD SUB MUL DIV REM NOT GTR LES GEQ LEQ EQL NEQ LAN LOR
%token VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN REM_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN SHR_ASSIGN SHL_ASSIGN INC_ASSIGN DEC_ASSIGN
%token IF ELSE FOR WHILE RETURN BREAK CONTINUE

/* Token with return, which need to sepcify type */
%token <var_type> VARIABLE_T
%token <s_var> IDENT
%token <s_val > STR_LIT 
%token <f_var> FLOAT_LIT
%token <i_var> INT_LIT
%token <b_var> BOOL_LIT


/* Nonterminal with return, which need to sepcify type */
%type <object_val> Expression
%type <object_val> sign
%type <object_val> factor
%type <object_val> factor2
%type <object_val> factor3
%type <object_val> factor4
%type <object_val> factor5
%type <object_val> factor6
%type <object_val> term
%type <object_val>FunctionParameterStmt
%type <i_var> ArrayParameterStmt
%type <object_val> CalculateFun

%left ADD SUB
%left MUL DIV REM LOR

%right NEG NOT BNT BAN
%right VAL_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN 
%right SHR_ASSIGN SHL_ASSIGN BAN_ASSIGN BOR_ASSIGN BXO_ASSIGN
%right INC_ASSIGN DEC_ASSIGN

/* Yacc will start at this nonterminal */
%start Program
%%
/* Grammar section */
Program
    : { pushScope(); } GlobalStmtList { dumpScope(); }
    | /* Empty file */
;

GlobalStmtList 
    : GlobalStmtList GlobalStmt
    | GlobalStmt
;

GlobalStmt
    : DefineVariableStmt
    | FunctionDefStmt
;

DefineVariableStmt
    : VARIABLE_T{ DefinedType = $<var_type>1;} DefineVariableStmtList
    |
;

DefineVariableStmtList
    : DefineVariableStmtList ',' IDENT
    {
        createassign(DefinedType, $<s_var>3);
        addnew(DefinedType, $<s_var>3, yylineno);
    }
    | DefineVariableStmtList ',' IDENT VAL_ASSIGN Expression
    {
        if(DefinedType==1){
            DefinedType = $<object_val>2.type;
        }
        createassign(DefinedType, $<s_var>3);
        addnew(DefinedType, $<s_var>3, yylineno);
    }
    | IDENT
    {   
        strcpy(autoVarName, $<s_var>1);
        createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>1, yylineno);
    }
    | IDENT VAL_ASSIGN Expression 
    {
        if(DefinedType==1){
            DefinedType = $<object_val>2.type;
        }
        createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>1, yylineno);
    }
    | IDENT ArrayParameterStmt VAL_ASSIGN '{' {arrayCount = 0;}Callist '}'
    {
        if(DefinedType==1){
            DefinedType = $<object_val>2.type;
        }
        printf("create array: %d\n",arrayCount);
        createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>2, yylineno);
    }
    | IDENT ArrayParameterStmt
    {
        createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>2, yylineno);
    }
    | IDENT ArrayParameterStmt ArrayParameterStmt
    {
        createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>2, yylineno);
    }

;
/* Function */
FunctionDefStmt
    : VARIABLE_T IDENT 
    { 
        funcTypeIndex = 0;
        funcType[funcTypeIndex++] = $<var_type>1;
        indextozero();
        addnew(10, $<s_var>2, yylineno);
        createFunction($<var_type>1, $<s_var>2);
    }
    '(' {indextozero();pushScope();}FunctionParameterStmtList 
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
        Object* temp = searchVar($<s_var>2, 1);
        if(temp!=NULL){
            strcpy(temp->symbol->func_sig, sig);
        }else{
            printf("invalid\n");
        }
    } 
    ')' '{' StmtList '}' { dumpScope(); }
;
/*參數*/
FunctionParameterStmtList 
    : FunctionParameterStmtList ',' FunctionParameterStmt 
    | FunctionParameterStmt 
    | /* Empty function parameter */
;
FunctionParameterStmt
    : VARIABLE_T IDENT 
    { 
        funcType[funcTypeIndex++] = $<var_type>1;
        pushFunParm($<var_type>1, $<s_var>2, 1);
        addnew($<var_type>1, $<s_var>2, yylineno);
    }
    | VARIABLE_T IDENT ArrayParameterStmt 
    {
        funcType[funcTypeIndex++] = $<var_type>1; 
        pushFunParm($<var_type>1, $<s_var>2, VAR_FLAG_DEFAULT);
        addnew($<var_type>1, $<s_var>2, yylineno);
    }
;

/* Scope */
StmtList 
    : StmtList Stmt 
    | Stmt 
;
Stmt
    : ';' 
    | COUT CoutParmListStmt ';' {stdoutPrint(); printf("\n");}
    | RETURN Expression ';' {printf("RETURN\n"); }
    | assignvar ';' 
    | DefineVariableStmt ';' //?
    | IF '(' Expression {printf("IF\n");} ')' ifStmt
    | ELSE {printf("ELSE\n");pushScope();} '{' StmtList '}' {dumpScope();} 
    | WHILE '(' {printf("WHILE\n");} CalculateFun ')' '{' {pushScope();} StmtList '}' {dumpScope();}
    | FOR '('{ indextozero(); printf("FOR\n");pushScope();}  forParm ')' '{' StmtList '}' {dumpScope();}
    | BREAK {printf("BREAK\n");}
    | RETURN { printf("RETURN\n"); }
    | Expression
    

;

forParm
    : DefineVariableStmt ';' CalculateFun ';' AddAdd
    | DefineVariableStmt ':' CalculateFun 
    {
        Object* temp = searchVar(autoVarName, 0); //find inserted variable in the symbollist
        if(temp!=NULL){
            temp->type = $<object_val>2.type;
        }else{
            printf("invalid\n");
        }
    } 
;

ifStmt
    : '{' {pushScope();} StmtList '}' {dumpScope();}
    | StmtList

CoutParmListStmt
    : CoutParmListStmt SHL Expression { pushFunInParm(&$<object_val>2);}
    | SHL Expression { pushFunInParm(&$<object_val>1);}
;

ArrayParameterStmt
    : '[' term ']' 
    | '[' ']' {funcType[funcTypeIndex++] = 0;}
;

;

Expression
    : '(' Expression ')' { $<object_val>0.type=$<object_val>1.type; }
    | ArrayParameterStmt
    | CalculateFun {$<object_val>0.type = $<object_val>1.type;}
    | IDENT '(' Callist ')' 
    {
        Object* temp = searchVar($<s_var>1, 1); //find inserted variable in the symbollist
        if(temp!=NULL){
            printf("IDENT (name=%s, address=%ld)\n",$<s_var>1,temp->symbol->addr);
            printf("call: %s%s\n", temp->symbol->name, temp->symbol->func_sig);
            $<object_val>0.type=temp->func_retype;
        }else{
            printf("invalid\n");
        }
    } 
    | IDENT dimension 
    {
        Object* temp = searchVar($<s_var>1, 0); //find inserted variable in the symbollist
        if(temp!=NULL){
            printf("IDENT (name=%s, address=%ld)\n",$<s_var>1,temp->symbol->addr);
            $<object_val>0.type = temp->type;
        }else{
            printf("invalid\n");
        }
    } 
;

dimension
    : dimension '[' term ']'
    | '[' term ']'

Callist
    : CalculateFun ',' Callist {arrayCount++;}
    | CalculateFun {arrayCount++;}
    | //empty

/*substack3*/
CalculateFun
    : factor6 {$<object_val>0.type = $<object_val>1.type;}
    | CalculateFun LOR factor6  {printf("LOR\n");$$.type=OBJECT_TYPE_BOOL;} //||
;

factor6
    : factor5 {$<object_val>0.type = $<object_val>1.type;}
    | factor6 LAN factor5 {printf("LAN\n");$$.type=OBJECT_TYPE_BOOL;} //&&
;

factor5
    : factor4 {$<object_val>0.type = $<object_val>1.type;}
    | factor5 BAN factor4 {printf("BAN\n");$$.type=OBJECT_TYPE_INT;}
    | factor5 BOR factor4 {printf("BOR\n");$$.type=OBJECT_TYPE_INT;}
    | factor5 BXO factor4 {printf("BXO\n");$$.type=OBJECT_TYPE_INT;}
;

factor4
    : factor3 {$<object_val>0.type = $<object_val>1.type;}
    | factor4 GTR factor3 {printf("GTR\n");$$.type=OBJECT_TYPE_BOOL;} //>
    | factor4 LES factor3 {printf("LES\n");$$.type=OBJECT_TYPE_BOOL;} //>
    | factor4 NEQ factor3 {printf("NEQ\n");$$.type=OBJECT_TYPE_BOOL;} //!=
    | factor4 EQL factor3 {printf("EQL\n");$$.type=OBJECT_TYPE_BOOL;} //==
    | factor4 GEQ factor3 {printf("GEQ\n");$$.type=OBJECT_TYPE_BOOL;} //==
;

factor3
    : factor2 {$<object_val>0.type = $<object_val>1.type;}
    | factor3 SHR factor2 {printf("SHR\n");$$.type=OBJECT_TYPE_INT;} //>>
    //| factor3 SHL factor2 {printf("SHL\n");$$.type=OBJECT_TYPE_INT;} //<<
;   
factor2
    : factor {$<object_val>0.type = $<object_val>1.type;}
    | factor2 ADD factor {printf("ADD\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;
        }else{$$.type=OBJECT_TYPE_INT;}
    }
    | factor2 SUB factor  {printf("SUB\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;
        }else{$$.type=OBJECT_TYPE_INT;}
    }
;
factor
    : sign {$<object_val>0.type = $<object_val>1.type;}
    | factor DIV sign {printf("DIV\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;
        }else{$$.type=OBJECT_TYPE_INT;}
    }
    | factor MUL sign {printf("MUL\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;
        }else{$$.type=OBJECT_TYPE_INT;}
    }
    | factor REM sign {printf("REM\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;
        }else{$$.type=OBJECT_TYPE_INT;}
    }
;


sign
    : term {$<object_val>0.type = $<object_val>1.type;}
    | SUB term {printf("NEG\n");$<object_val>0.type = $<object_val>2.type;}
    | NOT term {printf("NOT\n");$$.type=OBJECT_TYPE_BOOL;}
    | NOT NOT term {printf("NOT\nNOT\n");$$.type=OBJECT_TYPE_BOOL;}
    | BNT term {printf("BNT\n"); $$.type=OBJECT_TYPE_INT; } 
;

term
    : '(' CalculateFun ')'
    | '(' VARIABLE_T ')' sign {casting($<var_type>2);}
    | INT_LIT { $$ = $<object_val>1; $$.type=OBJECT_TYPE_INT; 
            printf("INT_LIT %d\n",$<i_var>1); }
    | FLOAT_LIT { $$ = $<object_val>1; $$.type=OBJECT_TYPE_FLOAT; 
            printf("FLOAT_LIT %.6f\n",$<f_var>1); }
    | BOOL_LIT { $$ = $<object_val>1; $$.type=OBJECT_TYPE_BOOL; 
            if($<b_var>1)
                printf("BOOL_LIT %s\n","TRUE");
            else
                printf("BOOL_LIT %s\n","FALSE");  
            }
    | IDENT {
                Object* temp = searchVar($<s_var>1, 0); //find inserted variable in the symbollist
                if(temp!=NULL){
                    printf("IDENT (name=%s, address=%ld)\n",$<s_var>1,temp->symbol->addr);
                    $$.type=temp->type; 
                    $$ = *temp;
                }else{
                    printf("IDENT (name=%s, address=-1)\n",$<s_var>1);
                    $$ = endl;
                    $$.type=OBJECT_TYPE_STR; 
                }
            }
    | STR_LIT { 
                $$.type=OBJECT_TYPE_STR;
                printf("STR_LIT \"%s\"\n",$<s_var>1); }
    | IDENT '(' Callist ')' 
    {
        Object* temp = searchVar($<s_var>1, 1); //find inserted variable in the symbollist
        if(temp!=NULL){
            printf("IDENT (name=%s, address=%ld)\n",$<s_var>1,temp->symbol->addr);
            printf("call: %s%s\n", temp->symbol->name, temp->symbol->func_sig);
            $<object_val>0.type=temp->func_retype;
        }else{
            printf("invalid\n");
        }
    } 
;

/*substack4*/
assignvar
    : Expression VAL_ASSIGN Expression {printf("EQL_ASSIGN\n");}
    | Expression ADD_ASSIGN Expression {printf("ADD_ASSIGN\n");}
    | Expression SUB_ASSIGN Expression {printf("SUB_ASSIGN\n");}
    | Expression MUL_ASSIGN Expression {printf("MUL_ASSIGN\n");}
    | Expression DIV_ASSIGN Expression {printf("DIV_ASSIGN\n");}
    | Expression REM_ASSIGN Expression {printf("REM_ASSIGN\n");}
    | Expression SHR_ASSIGN Expression {printf("SHR_ASSIGN\n");}
    | Expression SHL_ASSIGN Expression {printf("SHL_ASSIGN\n");}
    | Expression BAN_ASSIGN Expression {printf("BAN_ASSIGN\n");}
    | Expression BOR_ASSIGN Expression {printf("BOR_ASSIGN\n");}
    | Expression BXO_ASSIGN Expression {printf("BXO_ASSIGN\n");}
;

AddAdd
    : Expression INC_ASSIGN {printf("INC_ASSIGN\n");}
    | Expression DEC_ASSIGN {printf("DEC_ASSIGN\n");}
    | assignvar
;

%%
/* C code section */
