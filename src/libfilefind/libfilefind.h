#ifndef LIBFILEFIND_H
#define LIBFILEFIND_H

#include "libfilefind_global.h"

extern "C" {


enum EFIND_ERROR {
    LFERROR_NOERROR = 0,
    LFERROR_NULL_DIR = -1,
    LFERROR_EMPTY_DIR = -2,
    LFERROR_NOOPENTITYKIND = -3,
};

struct LF_GLOBAL_OPTION {

};

enum LFOP_KIND {
    LFOP_UNDEF,

    LFOP_BEGINPAREN,
    LFOP_ENDPAREN,

    LFOP_AND,
    LFOP_OR,

    LFOP_PRED,
};

enum LFPRED_KIND {
    LFPRED_UNDEF,

    LFPRED_MINSIZE,
    LFPRED_MAXSIZE,

    LPFRED_NAME,

    LFPRED_MINMTIME,
    LFPRED_MAXMTIME,

};

struct LFPRED_ENTITY {
    int cbsize;
    LFPRED_KIND predkind;
    union {
        unsigned long long* minsize;
        unsigned long long* maxsize;
        char* name;
        char* content;
        unsigned long long* minmtime;
        unsigned long long* maxmtime;
    } preddata;
};

struct LFOP_ENTITY {
    int cbsize;
    LFOP_KIND kind;
    LFPRED_ENTITY* pPred;
};

typedef void (*fnOnHit)(const char* file);
LIBFILEFINDSHARED_EXPORT int efind(
        LF_GLOBAL_OPTION* pOption,
        int nDirCount,
        const char** dirs,
        int nOpCount,
        LFOP_ENTITY* ppEntity,
        fnOnHit onHit);

} // extern "C"


#endif // LIBFILEFIND_H
