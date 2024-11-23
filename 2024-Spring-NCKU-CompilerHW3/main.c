#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "compiler_common.h"


#define WJCL_LINKED_LIST_IMPLEMENTATION
#include "main.h"
#define WJCL_HASH_MAP_IMPLEMENTATION

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)

#define iload(var) code("iload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lload(var) code("lload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fload(var) code("fload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dload(var) code("dload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define aload(var) code("aload %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)

#define istore(var) code("istore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define lstore(var) code("lstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define fstore(var) code("fstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define dstore(var) code("dstore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)
#define astore(var) code("astore %" PRId64 " ; %s", (var)->symbol->addr, (var)->symbol->name)

#define ldz(val) code("ldc %d", getBool(val))
#define ldb(val) code("ldc %d", getByte(val))
#define ldc(val) code("ldc %d", getChar(val))
#define lds(val) code("ldc %d", getShort(val))
#define ldi(val) code("ldc %d", getInt(val))
#define ldl(val) code("ldc_w %" PRId64, getLong(val))
#define ldf(val) code("ldc %.6f", getFloat(val))
#define ldd(val) code("ldc_w %lf", getDouble(val))
#define ldt(val) code("ldc \"%s\"", getString(val))

const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_BYTE] = "byte",
    [OBJECT_TYPE_CHAR] = "char",
    [OBJECT_TYPE_SHORT] = "short",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_LONG] = "long",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_DOUBLE] = "double",
    [OBJECT_TYPE_STR] = "string",
    [OBJECT_TYPE_FUNCTION] = "function",
};
const char* objectJavaTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "V",
    [OBJECT_TYPE_VOID] = "V",
    [OBJECT_TYPE_BOOL] = "Z",
    [OBJECT_TYPE_BYTE] = "B",
    [OBJECT_TYPE_CHAR] = "C",
    [OBJECT_TYPE_SHORT] = "S",
    [OBJECT_TYPE_INT] = "I",
    [OBJECT_TYPE_LONG] = "J",
    [OBJECT_TYPE_FLOAT] = "F",
    [OBJECT_TYPE_DOUBLE] = "D",
    [OBJECT_TYPE_STR] = "Ljava/lang/String;",
};

char* stdoutlist[20];
int stdindex=0;

Object symbollist[20];
int symbolindex=0;

char* yyInputFileName;
bool compileError;

int temp = 0;
int indent = 0; //index
int scopeLevel = -1;
int funcLineNo = 0;
int variableAddress = 0;
ObjectType variableIdentType;
int localvariable = 0;
int localvariableAddress = 0;

void setlocalvariable(int set){
    if(set==-1){
        localvariableAddress = 0;
    }else{
        localvariable = set;
    }
}

void addnew(ObjectType vartype,char* varname,int32_t linenum){
    Object* symbolnew = (Object*)malloc(sizeof(Object) );
    SymbolData* symboldata = (SymbolData*)malloc(sizeof(SymbolData) );
    symboldata->name=varname;
    symboldata->lineno=linenum;
    symboldata->index=indent;
    symboldata->level=scopeLevel;
    if(vartype==10){
        symboldata->addr=-1;
        symbolnew->type=10;
    }
    else{
        symboldata->addr=variableAddress;
        variableAddress++;
        strcpy(symboldata->func_sig, "-");
        symbolnew->type=vartype;
    }
    if(localvariable==1){
        symboldata->local_addr=localvariableAddress;
        localvariableAddress++;
    }else{
        symboldata->local_addr=-1;
    }
    symbolnew->symbol = symboldata;
    symbollist[symbolindex]=*symbolnew;
    // printf("insert symbol: %s insert level:%d\n",symbollist[symbolindex].symbol->name, symbollist[symbolindex].symbol->level);
    symbolindex++;
    indent++;
}

Object* searchVar(char* varname, int isFunc){
    for(int i=0;i<symbolindex;i++){
        if(strcmp(symbollist[i].symbol->name, varname)==0
        &&!isFunc
        &&symbollist[i].type!=10){
            return &symbollist[i];
        }
        if(strcmp(symbollist[i].symbol->name, varname)==0
        &&isFunc
        &&symbollist[i].type==10){
            return&symbollist[i];
        }
    }
    return NULL;
} 

void casting(ObjectType vartype){
    printf("Cast to %s\n",objectTypeName[vartype]);
}

void getscopeLevel(){
    scopeLevel++;
}
void indextozero(){
    indent=0;
}
void pushScope() {
    getscopeLevel();
    printf("> Create symbol table (scope level %d)\n",scopeLevel);
}
void dumphalf(){
    printf("\n> Dump symbol table (scope level: %d)\n",scopeLevel);
    printf("Index     Name                Type      Addr      Lineno    Func_sig  \n");
    scopeLevel--;
}
void dumpScope() {
    printf("\n> Dump symbol table (scope level: %d)\n",scopeLevel);
    printf("Index     Name                Type      Addr      Lineno    Func_sig  \n");
    int temp=symbolindex;
    int count=0;
    for (int i=0;i<symbolindex;i++){
        if (symbollist[i].symbol->level==scopeLevel){
            if(i<=temp){
                temp = i;
            }
            printf("%-10"PRId32"%-20s%-10s%-10"PRId64"%-10"PRId32"%-10s\n",
            count++,
            symbollist[i].symbol->name,
            objectTypeName[symbollist[i].type],
            symbollist[i].symbol->addr,
            symbollist[i].symbol->lineno,
            symbollist[i].symbol->func_sig);
        }
    }
    symbolindex=temp;
    scopeLevel--;
}

Object* createVariable(ObjectType variableType, char* variableName, int variableFlag) {
    return NULL;
}

void pushFunParm(ObjectType variableType, char* variableName, int variableFlag) {
    //getscopeLevel();
    // printf("> Create symbol table (scope level %d)\n",scopeLevel);
    printf("> Insert `%s` (addr: %d) to scope level %d\n",variableName,variableAddress,scopeLevel);
}

void createFunction(ObjectType variableType, char* funcName) {
    printf("func: %s\n",funcName);
    printf("> Insert `%s` (addr: -1) to scope level %d\n",funcName,scopeLevel);
    Object* temp = searchVar(funcName, 1);
    if(temp!=NULL)
        temp->func_retype = variableType;
    else
        printf("invalid\n");
    
}
int createassign(ObjectType variableType, char* funcName) {
        printf("> Insert `%s` (addr: %d) to scope level %d\n",funcName,variableAddress,scopeLevel);
        return variableAddress;
}

void debugPrintInst(char instc, Object* a, Object* b, Object* out) {
}

bool objectExpression(char op, Object* dest, Object* val, Object* out) {
    return false;
}

bool objectExpBinary(char op, Object* a, Object* b, Object* out) {
    return false;
}

bool objectExpBoolean(char op, Object* a, Object* b, Object* out) {
    return false;
}

bool objectExpAssign(char op, Object* dest, Object* val, Object* out) {
    return false;
}

bool objectValueAssign(Object* dest, Object* val, Object* out) {
    return false;
}

bool objectNotBinaryExpression(Object* dest, Object* out) {
    return false;
}

bool objectNegExpression(Object* dest, Object* out) {
    return false;
}
bool objectNotExpression(Object* dest, Object* out) {
    return false;
}

bool objectIncAssign(Object* a, Object* out) {
    return false;
}

bool objectDecAssign(Object* a, Object* out) {
    return false;
}

bool objectCast(ObjectType variableType, Object* dest, Object* out) {
    return false;
}

Object* findVariable(char* variableName) {
    Object* variable = NULL;
    return variable;
}



void pushFunInParm(Object* variable) {
    // printf("stdindex: %d\n", stdindex);
    stdoutlist[stdindex] = malloc(sizeof(char)*20);
    // printf("%d\n",variable->type);
   // printf("%sowo\n",objectTypeName[variable->type]); // objectTypeName[9]
    strcpy(stdoutlist[stdindex],objectTypeName[variable->type]);
    //printf("%d\n",variable->type);
   // printf("%s",stdoutlist[stdindex]);
    stdindex++;
    // printf("%s,%s,%s\n", stdoutlist[0],stdoutlist[1],stdoutlist[2]);
}

void stdoutPrint() {
    printf("cout");
    for (int i=0;i<stdindex;i++){
        printf(" %s",stdoutlist[i]);
    }
    stdindex=0;
}

char* getfunsig(int num){
    return objectJavaTypeName[num];
}
void precedenc(int num,Object* temp){
    if(temp->symbol->local_addr<0){
        switch(num){
            case OBJECT_TYPE_FLOAT:
                fload(temp);
                break;
            case OBJECT_TYPE_INT:
                iload(temp);
                break;
            case OBJECT_TYPE_STR:
                aload(temp);
                break;
            case OBJECT_TYPE_BOOL:
                iload(temp);
                break;
        }
    }else{
        switch(num){
            case OBJECT_TYPE_FLOAT:
                code("fload %d", temp->symbol->local_addr);
                break;
            case OBJECT_TYPE_INT:
                code("iload %d", temp->symbol->local_addr);
                break;
            case OBJECT_TYPE_STR:
                code("aload %d", temp->symbol->local_addr);
                break;
            case OBJECT_TYPE_BOOL:
                code("iload %d", temp->symbol->local_addr);
                break;
        }
    }
    
}
void precedenc_s(int num,Object* temp){
    //printf("%d",num);
    if(temp->symbol->local_addr<0){
        switch(num){
            case OBJECT_TYPE_FLOAT:
                fstore(temp);
                break;
            case OBJECT_TYPE_INT:
                istore(temp);
                break;
            case OBJECT_TYPE_STR:
                astore(temp);
                break;
            case OBJECT_TYPE_BOOL:
                istore(temp);
                break;
        }
    }else{
        switch(num){
            case OBJECT_TYPE_FLOAT:
                code("fstore %d", temp->symbol->local_addr);
                break;
            case OBJECT_TYPE_INT:
                code("istore %d", temp->symbol->local_addr);
                break;
            case OBJECT_TYPE_STR:
                code("astore %d", temp->symbol->local_addr);
                break;
            case OBJECT_TYPE_BOOL:
                code("istore %d", temp->symbol->local_addr);
                break;
        }
    }
    
}
void precedenc_assign(int num,int addr){
    // printf("%d\n",num);
    switch(num){
        case OBJECT_TYPE_FLOAT:
            code("fstore %d",addr);
            break;
        case OBJECT_TYPE_INT:
            code("istore %d",addr);
            break;
        case OBJECT_TYPE_STR:
            code("astore %d",addr);
            break;
        case OBJECT_TYPE_BOOL:
            code("istore %d",addr);
            break;
    }
}
void array1(ObjectType vartype){
    switch(vartype){
        case OBJECT_TYPE_FLOAT:
            codeRaw("newarray float");
            break;
        case OBJECT_TYPE_INT:
            codeRaw("newarray int");
            break;
        case OBJECT_TYPE_STR:
            codeRaw("newarray char");
            break;
        case OBJECT_TYPE_BOOL:
            codeRaw("newarray bool");
            break;
    }
}
int main(int argc, char* argv[]) {
    char* outputFileName = NULL;
    if (argc == 3) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = fopen(outputFileName = argv[2], "w");
    } else if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
        yyout = stdout;
    } else {
        printf("require input file");
        exit(1);
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }
    if (!yyout) {
        printf("file `%s` doesn't exists or cannot be opened\n", outputFileName);
        exit(1);
    }
    codeRaw(".source Main.j");
    codeRaw(".class public Main");
    codeRaw(".super java/lang/Object");
    scopeLevel = -1;

    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}