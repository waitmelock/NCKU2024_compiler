#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "compiler_common.h"

#include "main.h"

#define debug printf("%s:%d: ############### debug\n", __FILE__, __LINE__)

#define toupper(_char) (_char - (char)32)

const char* objectTypeName[] = {
    [OBJECT_TYPE_UNDEFINED] = "undefined",
    [OBJECT_TYPE_AUTO] = "auto",
    [OBJECT_TYPE_VOID] = "void",
    [OBJECT_TYPE_CHAR] = "char",
    [OBJECT_TYPE_INT] = "int",
    [OBJECT_TYPE_FLOAT] = "float",
    [OBJECT_TYPE_BOOL] = "bool",
    [OBJECT_TYPE_STR] = "string",
    [OBJECT_TYPE_FUNCTION] = "function",
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
void createassign(ObjectType variableType, char* funcName) {
        printf("> Insert `%s` (addr: %d) to scope level %d\n",funcName,variableAddress,scopeLevel);
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

int main(int argc, char* argv[]) {
    if (argc == 2) {
        yyin = fopen(yyInputFileName = argv[1], "r");
    } else {
        yyin = stdin;
    }
    if (!yyin) {
        printf("file `%s` doesn't exists or cannot be opened\n", yyInputFileName);
        exit(1);
    }

    // Start parsing
    yyparse();
    printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    yylex_destroy();
    return 0;
}