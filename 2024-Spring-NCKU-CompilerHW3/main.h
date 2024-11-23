#ifndef MAIN_H
#define MAIN_H
#include "compiler_common.h"

#define code(format, ...) \
    fprintf(yyout, "%*s" format "\n", scopeLevel << 2, "", ##__VA_ARGS__)
#define codeRaw(code) \
    fprintf(yyout, "%*s" code "\n", scopeLevel << 2, "")

extern FILE* yyout;
extern FILE* yyin;
extern bool compileError;
extern int scopeLevel;
int yyparse();
int yylex();
int yylex_destroy();

#define VAR_FLAG_DEFAULT 0
#define VAR_FLAG_ARRAY 0b00000001
#define VAR_FLAG_POINTER 0b00000010

void pushScope();
void dumpScope();

void pushFunParm(ObjectType variableType, char* variableName, int parmFlag);
void createFunction(ObjectType variableType, char* funcName);
void pushFunInParm(Object* b);
int createassign(ObjectType variableType, char* funcName);

Object* findVariable(char* variableName);
Object* createVariable(ObjectType variableType, char* variableName, int variableFlag);
bool objectExpression(char op, Object* a, Object* b, Object* out);
bool objectExpBinary(char op, Object* a, Object* b, Object* out);
bool objectExpBoolean(char op, Object* a, Object* b, Object* out);
bool objectExpAssign(char op, Object* dest, Object* val, Object* out);
bool objectValueAssign(Object* dest, Object* val, Object* out);
bool objectNotBinaryExpression(Object* dest, Object* out);
bool objectNotExpression(Object* dest, Object* out);
bool objectNegExpression(Object* dest, Object* out);
bool objectIncAssign(Object* a, Object* out);
bool objectDecAssign(Object* a, Object* out);
bool objectCast(ObjectType variableType, Object* dest, Object* out);

void stdoutPrint();
void addnew(ObjectType vartype,char* varname,int linenum);
void indextozero();
Object* searchVar(char* varname, int isFunc);
char* getfunsig(int num);
void precedenc(int num,Object* temp);
void precedenc_s(int num,Object* temp);
void precedenc_assign(int num,int addr);
void array1(ObjectType vartype);
// Object* findVariable(char* variableName);
// bool initVariable(ObjectType variableType, LinkedList* arraySubscripts, char* variableName);
// Object* createVariable(ObjectType variableType, LinkedList* arraySubscripts, char* variableName, Object* value);

// void functionLocalsBegin();
// void functionParmPush(ObjectType variableType, LinkedList* arraySubscripts, char* variableName);
// void functionBegin(ObjectType returnType, LinkedList* arraySubscripts, char* funcName);
// bool functionEnd(ObjectType returnType);

// bool returnObject(Object* obj);
// bool breakLoop();

// void functionArgsBegin();
// void functionArgPush(Object* obj);
// void functionCall(char* funcName, Object* out);

// bool stdoutPrint(Object* obj);

// // Expressions
// bool objectExpression(char op, Object* a, Object* b, Object* out);
// bool objectExpBinary(char op, Object* a, Object* b, Object* out);
// bool objectExpBoolean(char op, Object* a, Object* b, Object* out);
// bool objectNotBinaryExpression(Object* a, Object* out);
// bool objectNotBooleanExpression(Object* a, Object* out);
// bool objectNegExpression(Object* a, Object* out);
// bool objectIncAssign(Object* a, Object* out);
// bool objectDecAssign(Object* a, Object* out);
// bool objectCast(ObjectType variableType, Object* a, Object* out);
// bool objectExpAssign(char op, Object* dest, Object* val, Object* out);
// bool objectValueAssign(Object* dest, Object* val, Object* out);

// bool ifBegin(Object* a);
// bool ifEnd();
// bool ifOnlyEnd();
// bool elseBegin();
// bool elseEnd();

// bool whileBegin();
// bool whileBodyBegin();
// bool whileEnd();

// bool forBegin();
// bool forInitEnd();
// bool forConditionEnd(Object* result);
// bool forHeaderEnd();
// bool foreachHeaderEnd(Object* obj);
// bool forEnd();

// bool arrayCreate(Object* out);
// bool objectArrayGet(Object* arr, LinkedList* arraySubscripts, Object* out);
// LinkedList* arraySubscriptBegin(Object* index);
// bool arraySubscriptPush(LinkedList* arraySubscripts, Object* index);
// bool arraySubscriptEnd(LinkedList* arraySubscripts);

// void stdoutPrint();
// void addnew(ObjectType vartype,char* varname,int linenum);
// void indextozero();
// Object* searchVar(char* varname, int isFunc);

#endif