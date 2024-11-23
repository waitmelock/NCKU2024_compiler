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
    : VARIABLE_T{ DefinedType = $<var_type>1;
    } DefineVariableStmtList
    |
;

DefineVariableStmtList
    : DefineVariableStmtList ',' IDENT
    {
        currentaddr=createassign(DefinedType, $<s_var>3);
        addnew(DefinedType, $<s_var>3, yylineno);
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
    | DefineVariableStmtList ',' IDENT VAL_ASSIGN Expression
    {
        if(isarray==1){
            codeRaw("iaload");
            isarray=0;
        }
        if(DefinedType==1){
            DefinedType = $<object_val>2.type;
        }
        currentaddr=createassign(DefinedType, $<s_var>3);
        addnew(DefinedType, $<s_var>3, yylineno);
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
    | IDENT
    {   
        strcpy(autoVarName, $<s_var>1);
        currentaddr=createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>1, yylineno);
        codeRaw("ldc 0");
        precedenc_assign(DefinedType,currentaddr);
    }
    | IDENT VAL_ASSIGN Expression 
    {
        if(isarray==1){
            codeRaw("iaload");
            isarray=0;
        }
        if(DefinedType==1){
            DefinedType = $<object_val>2.type;
        }
        currentaddr=createassign(DefinedType, $<s_var>1);
        //printf("testtesttest:%d",currentaddr);
        precedenc_assign(DefinedType,currentaddr);
        addnew(DefinedType, $<s_var>1, yylineno);
    }
    | IDENT ArrayParameterStmt {array1(DefinedType);arrayinit=1;} VAL_ASSIGN '{' {arraycurrent=0;arrayCount = 0;} Callist '}'
    {
        if(DefinedType==1){
            DefinedType = $<object_val>2.type;
        }
        printf("create array: %d\n",arrayCount);
        arrayassign=createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>1, yylineno);
        arrayinit=0;
        code("astore %d",arrayassign);
    }
    | IDENT ArrayParameterStmt
    {
        array1(DefinedType);
        arrayassign=createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>1, yylineno);
        arrayinit=0;
        code("astore %d",arrayassign);
    }
    | IDENT ArrayParameterStmt ArrayParameterStmt
    {
        arrayinit=0;
        arrayassign = createassign(DefinedType, $<s_var>1);
        addnew(DefinedType, $<s_var>1, yylineno);
        codeRaw("multianewarray [[I 2");
        code("astore %d", arrayassign);
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
        if(strcmp($<s_var>2, "main")!=0){
            setlocalvariable(-1);//reset localvariableAddress in main.c
            setlocalvariable(1);//set local_addr in add_new
        }
        if(strcmp($<s_var>2,"main")==0){
            mainflag = 1;
        }else{
            mainflag = 0;
        }
    }
    '(' {indextozero();pushScope();} FunctionParameterStmtList 
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
        Object* temp = searchVar($<s_var>2, 1);
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
    ')' '{' StmtList '}' {
        setlocalvariable(0);
        if(mainflag==1){
            codeRaw("return");
        }
        codeRaw(".end method");dumpScope(); 
    }
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
    | COUT CoutParmListStmt ';' { stdoutPrint(); printf("\n"); }
    | RETURN Expression ';' 
    {   printf("RETURN\n"); //別刪
        if(mainflag!=1){
            if($<object_val>2.type==6){
                codeRaw("freturn");
            }else{
                codeRaw("ireturn");
            }
        }
    }
    | assignvar ';' 
    | DefineVariableStmt ';' //?
    | IF {isif=1;} '(' Expression {
        codeRaw("dup");
        code("istore %d", tempForIF);
        tempForIF--;
        code("ifeq ifEnd%d",iflabel);
        code("if%d:", iflabel);
        ifarray[currentif] = iflabel;
        currentif++;
        iflabel++;
        printf("IF\n");
    } ')' ifStmt
    | ELSE {isif=1;
        printf("ELSE\n");
        tempForIF++;
        code("iload %d", tempForIF);
        code("ifne elseEnd%d", iflabel);
        ifarray[currentif] = iflabel;
        currentif++;
        iflabel++;
    pushScope();} '{' StmtList '}' {
        currentif--;
        code("elseEnd%d:", ifarray[currentif]);
        dumpScope();
    } 
    | WHILE {
        breaktype = 1;
        code("while%d:", whileforlabel);
        whileforarray[currentwhilefor] = whileforlabel;
    }'(' {printf("WHILE\n");} CalculateFun ')'{
        code("ifeq whileEnd%d", whileforarray[currentwhilefor]);
        currentwhilefor++;
        whileforlabel++;
    } '{' {pushScope();} StmtList '}' {
        dumpScope();
        currentwhilefor--;
        code("goto while%d", whileforarray[currentwhilefor]);
        code("whileEnd%d:", whileforarray[currentwhilefor]);    
    }
    | FOR '('{ indextozero(); printf("FOR\n");pushScope();}  forParm ')' {
        code("forstmt%d:", whileforarray[currentwhilefor-1]);
    } '{' StmtList '}' {
        dumpScope();
        currentwhilefor--;
        code("goto forAddAdd%d", whileforarray[currentwhilefor]);
        code("forEnd%d:", whileforarray[currentwhilefor]);
    }
    | BREAK {
        printf("BREAK\n");
        if(breaktype==1){
            code("goto whileEnd%d", whileforarray[currentwhilefor-1]);
        }
        if(breaktype==2){
            code("goto forEnd%d", whileforarray[currentwhilefor-1]);
        }
        breaktype = 0;
    }
    | RETURN { 
        printf("RETURN\n");
        if(mainflag!=1){
            codeRaw("return");}
        }
    | Expression {
        if(isarray==1){
            codeRaw("iaload");
            isarray=0;
        }
    }
    

;

forParm
    : DefineVariableStmt ';'{
        breaktype=2;
        code("for%d:", whileforlabel);
        whileforarray[currentwhilefor] = whileforlabel;
    } CalculateFun {
        code("ifne forstmt%d", whileforarray[currentwhilefor]);
        code("goto forEnd%d", whileforarray[currentwhilefor]);
        code("forAddAdd%d:", whileforarray[currentwhilefor]);
    }';' AddAdd {
        code("goto for%d", whileforarray[currentwhilefor]);
        currentwhilefor++;
        whileforlabel++;
    }
    | DefineVariableStmt ':' CalculateFun 
    {
        Object* temp = searchVar(autoVarName, 0); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            temp->type = $<object_val>2.type;
        }else{
            printf("invalid\n");
        }
    } 
;

ifStmt
    : '{' {pushScope();} StmtList '}' {
        currentif--;
        code("ifEnd%d:", ifarray[currentif]);
        dumpScope();
    }
    | Stmt{
        currentif--;
        code("ifEnd%d:", ifarray[currentif]);
    }

CoutParmListStmt
    :  CoutParmListStmt {codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");} SHL Expression 
    {
    if(isarray==1){
        codeRaw("iaload");
        isarray=0;
    }
    if(flagendl==0){
        code("invokevirtual java/io/PrintStream/print(%s)V",getfunsig($<object_val>3.type));
    }
    else{
        codeRaw("invokevirtual java/io/PrintStream/println()V");
        flagendl=0;
    }
    pushFunInParm(&$<object_val>3);
    }
    | {codeRaw("getstatic java/lang/System/out Ljava/io/PrintStream;");} SHL Expression 
    {
        if(isarray==1){
            codeRaw("iaload");
            isarray=0;
        }
    if(flagendl==0){
        code("invokevirtual java/io/PrintStream/print(%s)V",getfunsig($<object_val>2.type));
    }
    else{
        codeRaw("invokevirtual java/io/PrintStream/println()V");
        flagendl=0;
    }
    pushFunInParm(&$<object_val>2);
    }
;

ArrayParameterStmt
    : '[' term ']'  
    | '[' ']' {funcType[funcTypeIndex++] = 0;}
;

;

Expression
    : '(' Expression ')' { $<object_val>0.type=$<object_val>1.type;}
    | ArrayParameterStmt
    | CalculateFun {$<object_val>0.type = $<object_val>1.type; }
    | IDENT '(' Callist ')' 
    {
        Object* temp = searchVar($<s_var>1, 1); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            //printf("current1");
            printf("IDENT (name=%s, address=%ld)\n",$<s_var>1,temp->symbol->addr);
            printf("call: %s%s\n", temp->symbol->name, temp->symbol->func_sig);
            $<object_val>0.type=temp->func_retype;
        }else{
            printf("invalid\n");
        }

        code("invokestatic Main/%s%s", temp->symbol->name, temp->symbol->func_sig);
    } 
    | IDENT {
        Object* temp = searchVar($<s_var>1, 0); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            code("aload %d",temp->symbol->addr);//testing
        }
    } dimension 
    {
        Object* temp = searchVar($<s_var>1, 0); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            //printf("current2");
            printf("IDENT (name=%s, address=%ld)\n",$<s_var>1,temp->symbol->addr);
            $<object_val>0.type = temp->type;
            
        }else{
            printf("invalid\n");
        }
        isarray=1;
    } 
;

dimension
    : dimension '['{codeRaw("aaload");} term ']'
    | '[' term ']'

Callist
    : CalculateFun ',' Callist { arrayCount++; }
    | CalculateFun {arrayCount++;}
    | //empty

/*substack3*/
CalculateFun
    : factor6 {$<object_val>0.type = $<object_val>1.type;}
    | CalculateFun LOR factor6  {printf("LOR\n");$$.type=OBJECT_TYPE_BOOL;codeRaw("ior");} //||
;

factor6
    : factor5 {$<object_val>0.type = $<object_val>1.type;}
    | factor6 LAN factor5 {printf("LAN\n");$$.type=OBJECT_TYPE_BOOL;
        codeRaw("iand");
    } //&&
;

factor5
    : factor4 {$<object_val>0.type = $<object_val>1.type;}
    | factor5 BAN factor4 {printf("BAN\n");$$.type=OBJECT_TYPE_INT;
        codeRaw("iand");
    }
    | factor5 BOR factor4 {printf("BOR\n");$$.type=OBJECT_TYPE_INT;
        codeRaw("ior");
    }
    | factor5 BXO factor4 {printf("BXO\n");$$.type=OBJECT_TYPE_INT;
        codeRaw("ixor");    
    }
;

factor4
    : factor3 {$<object_val>0.type = $<object_val>1.type;}
    | factor4 GTR factor3 {printf("GTR\n");$$.type=OBJECT_TYPE_BOOL;
        if($<object_val>1.type==OBJECT_TYPE_FLOAT){
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
    } //>
    | factor4 LES factor3 {printf("LES\n");$$.type=OBJECT_TYPE_BOOL;
        code("if_icmplt LESLabel%d",currentlebal);
        code("iconst_0");
        code("goto LESend%d",currentlebal);
        code("LESLabel%d:",currentlebal);
        code("iconst_1");
        code("LESend%d:",currentlebal);
        currentlebal++;
    } //>
    | factor4 NEQ factor3 {printf("NEQ\n");$$.type=OBJECT_TYPE_BOOL;
        if($<object_val>1.type==OBJECT_TYPE_FLOAT){
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
    } //!=
    | factor4 EQL factor3 {printf("EQL\n");$$.type=OBJECT_TYPE_BOOL;
        if($<object_val>1.type==OBJECT_TYPE_FLOAT){
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
    } //==
    | factor4 GEQ factor3 {
        printf("GEQ\n");$$.type=OBJECT_TYPE_BOOL;
        if($<object_val>1.type==OBJECT_TYPE_FLOAT){
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
    } //==
;

factor3
    : factor2 {$<object_val>0.type = $<object_val>1.type;}
    | factor3 SHR factor2 {printf("SHR\n");$$.type=OBJECT_TYPE_INT;
        codeRaw("ishr");
    } //>>
    //| factor3 SHL factor2 {printf("SHL\n");$$.type=OBJECT_TYPE_INT;} //<<
;   
factor2
    : factor {$<object_val>0.type = $<object_val>1.type;}
    | factor2 ADD factor {printf("ADD\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;codeRaw("fadd");
        }else{$$.type=OBJECT_TYPE_INT;codeRaw("iadd");}
    }
    | factor2 SUB factor  {printf("SUB\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;codeRaw("fsub");
        }else{$$.type=OBJECT_TYPE_INT;codeRaw("isub");}
    }
;
factor
    : sign {$<object_val>0.type = $<object_val>1.type;}
    | factor DIV sign {printf("DIV\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;codeRaw("fdiv");
        }else{$$.type=OBJECT_TYPE_INT;codeRaw("idiv");}
    }
    | factor MUL sign {printf("MUL\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;codeRaw("fmul");
        }else{$$.type=OBJECT_TYPE_INT;codeRaw("imul");}
    }
    | factor REM sign {printf("REM\n");
        if($<object_val>1.type==OBJECT_TYPE_FLOAT||$<object_val>3.type==OBJECT_TYPE_FLOAT){
            $$.type=OBJECT_TYPE_FLOAT;codeRaw("frem");
        }else{$$.type=OBJECT_TYPE_INT;codeRaw("irem");}
    }
;


sign
    : term {$<object_val>0.type = $<object_val>1.type;}
    | SUB term {printf("NEG\n");$<object_val>0.type = $<object_val>2.type;
        if($<object_val>2.type==6){codeRaw("fneg");}
        else{codeRaw("ineg");}
    }
    | NOT term {printf("NOT\n");$$.type=OBJECT_TYPE_BOOL;codeRaw("iconst_1");codeRaw("ixor");}
    | NOT NOT term {printf("NOT\nNOT\n");$$.type=OBJECT_TYPE_BOOL; codeRaw("iconst_1");codeRaw("ixor");codeRaw("iconst_1");codeRaw("ixor");}
    | BNT term {printf("BNT\n"); $$.type=OBJECT_TYPE_INT; 
        codeRaw("iconst_m1");
        codeRaw("ixor");
    } 
;

term
    : '(' CalculateFun ')'
    | '(' VARIABLE_T ')' sign {casting($<var_type>2);
        if($<object_val>4.type!=$<object_val>2.type){
            if($<object_val>2.type==OBJECT_TYPE_FLOAT){
            codeRaw("i2f");
        }
        else{
            codeRaw("f2i");
        }}
    }
    | INT_LIT { $$ = $<object_val>1; $$.type=OBJECT_TYPE_INT; 
            printf("INT_LIT %d\n",$<i_var>1); 
            if(arrayinit==1){
                codeRaw("dup");code("ldc %d",arraycurrent++);code("ldc %d",$<i_var>1);codeRaw("iastore");
            }
            else{
                code("ldc %d",$<i_var>1);   
            }
            }
    | FLOAT_LIT { $$ = $<object_val>1; $$.type=OBJECT_TYPE_FLOAT; 
            printf("FLOAT_LIT %.6f\n",$<f_var>1); 
            code("ldc %6f",$<f_var>1);
            }
    | BOOL_LIT { $$ = $<object_val>1; $$.type=OBJECT_TYPE_BOOL; 
            if($<b_var>1){
                printf("BOOL_LIT %s\n","TRUE");
                codeRaw("iconst_1");
            }
            else{
                printf("BOOL_LIT %s\n","FALSE");  
                codeRaw("iconst_0");
            }
            }
    | IDENT {
                Object* temp = searchVar($<s_var>1, 0); //find inserted variable in the symbollist
                current=temp;
                if(temp!=NULL){
                    printf("IDENT (name=%s, address=%ld)\n",$<s_var>1,temp->symbol->addr);
                    $$.type=temp->type; 
                    $$ = *temp;
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
                    printf("IDENT (name=%s, address=-1)\n",$<s_var>1);
                    $$ = endl;
                    $$.type=OBJECT_TYPE_STR; 
                    flagendl=1;
                    //codeRaw("invokevirtual java/io/PrintStream/println()V");
                }
            }
    | STR_LIT { 
                $$.type=OBJECT_TYPE_STR;
                printf("STR_LIT \"%s\"\n",$<s_var>1); 
                code("ldc \"%s\"",$<s_var>1);
                //codeRaw("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V");
              }
    | IDENT '(' Callist ')' 
    {
        Object* temp = searchVar($<s_var>1, 1); //find inserted variable in the symbollist
        current=temp;
        if(temp!=NULL){
            printf("IDENT (name=%s, address=%ld)\n",$<s_var>1,temp->symbol->addr);
            printf("call: %s%s\n", temp->symbol->name, temp->symbol->func_sig);
            $<object_val>0.type=temp->func_retype;
        }else{
            printf("invalid\n");
        }
        code("invokestatic Main/%s%s", temp->symbol->name, temp->symbol->func_sig);
    } 
;

/*substack4*/
assignvar
    : Expression {
        addrsave=current;
        if(isarray!=0){
            isarray=0;
            arrayassign = 1;
        }
        
    } VAL_ASSIGN  Expression {printf("EQL_ASSIGN\n");
       if($<object_val>1.type!=$<object_val>3.type&&arrayassign==0){
        if($<object_val>1.type==OBJECT_TYPE_FLOAT){
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
            precedenc_s($<object_val>1.type,addrsave);
            codeRaw("pop");
        }
       
    }
    | Expression {addrsave=current;} ADD_ASSIGN Expression {printf("ADD_ASSIGN\n");
        switch($<object_val>1.type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fadd");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("iadd");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;} SUB_ASSIGN Expression {printf("SUB_ASSIGN\n");
        switch($<object_val>1.type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fsub");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("isub");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;precedenc(current->type,current);} MUL_ASSIGN Expression {printf("MUL_ASSIGN\n");
        switch($<object_val>1.type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fmul");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("imul");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;precedenc(current->type,current);} DIV_ASSIGN Expression {printf("DIV_ASSIGN\n");
        switch($<object_val>1.type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fdiv");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("idiv");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;precedenc(current->type,current);} REM_ASSIGN Expression {printf("REM_ASSIGN\n");
        switch($<object_val>1.type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("frem");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("irem");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;precedenc(current->type,current);} SHR_ASSIGN Expression {printf("SHR_ASSIGN\n");
        //precedenc_type($<object_val>1.type);
        switch($<object_val>1.type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fshr");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("ishr");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;precedenc(current->type,current);} SHL_ASSIGN Expression {printf("SHL_ASSIGN\n"); 
        switch($<object_val>1.type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fshl");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("ishl");
                break;
        }
        //precedenc_type($<object_val>1.type);
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;precedenc(current->type,current);} BAN_ASSIGN Expression {printf("BAN_ASSIGN\n");
        //precedenc_type($<object_val>1.type);
        switch($<object_val>1.type){
            case OBJECT_TYPE_FLOAT:
                codeRaw("fand");
                break;
            case OBJECT_TYPE_INT:
                codeRaw("iand");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;precedenc(current->type,current);} BOR_ASSIGN Expression {printf("BOR_ASSIGN\n");
        //precedenc_type($<object_val>1.type);
        switch($<object_val>1.type){
            case OBJECT_TYPE_INT:
                codeRaw("ior");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
    | Expression {addrsave=current;precedenc(current->type,current);} BXO_ASSIGN Expression {printf("BXO_ASSIGN\n");
        //precedenc_type($<object_val>1.type);
        switch($<object_val>1.type){
            case OBJECT_TYPE_INT:
                codeRaw("ixor");
                break;
        }
        precedenc_s($<object_val>1.type,addrsave);
    }
;

AddAdd
    : Expression INC_ASSIGN {
        printf("INC_ASSIGN\n");
        codeRaw("iconst_1");
        codeRaw("iadd");
        precedenc_s(current->type,current);
    }
    | Expression DEC_ASSIGN {
        printf("DEC_ASSIGN\n");
        codeRaw("iconst_1");
        codeRaw("isub");
        precedenc_s(current->type,current);
    }
    | assignvar
;

%%
/* C code section */
