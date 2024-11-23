#ifndef COMPILER_COMMON_H
#define COMPILER_COMMON_H

#include <stdbool.h>
#include <stdint.h>

#define getBool(val) (*(int8_t*)&((val)->value))
#define getByte(val) (*(int8_t*)&((val)->value))
#define getChar(val) (*(int8_t*)&((val)->value))
#define getShort(val) (*(int16_t*)&((val)->value))
#define getInt(val) (*(int32_t*)&((val)->value))
#define getLong(val) (*(int64_t*)&((val)->value))
#define getFloat(val) (*(float*)&((val)->value))
#define getDouble(val) (*(double*)&((val)->value))
#define getString(val) (*(char**)&((val)->value))

#define asVal(val) (*(int64_t*)&(val))

typedef enum _objectType {
    OBJECT_TYPE_UNDEFINED,
    OBJECT_TYPE_AUTO,
    OBJECT_TYPE_VOID,
    OBJECT_TYPE_CHAR,
    OBJECT_TYPE_INT,
    OBJECT_TYPE_LONG,
    OBJECT_TYPE_FLOAT,
    OBJECT_TYPE_DOUBLE,
    OBJECT_TYPE_BOOL,
    OBJECT_TYPE_STR,
    OBJECT_TYPE_FUNCTION,
    OBJECT_TYPE_BYTE,
    OBJECT_TYPE_SHORT,
} ObjectType;

typedef struct _symbolData {
    char* name;
    int32_t index;
    int64_t addr;
    int64_t local_addr;
    int32_t lineno;
    char func_sig[100];
    uint8_t func_var;
    int32_t level;
} SymbolData;

typedef struct _object {
    ObjectType type;
    ObjectType func_retype;
    uint64_t value;
    SymbolData* symbol;
} Object;

extern int yylineno;
extern int funcLineNo;

#endif /* COMPILER_COMMON_H */