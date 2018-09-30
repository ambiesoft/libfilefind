#ifndef LIBFILEFIND_H
#define LIBFILEFIND_H

#include "libfilefind_global.h"

enum EFIND_ERROR {
    LFERROR_NOERROR = 0,
    LFERROR_NULL_DIR = -1,
    LFERROR_EMPTY_DIR = -2,
    LFERROR_NOOPENTITYKIND = -3,
};

struct LF_GLOBAL_OPTION {

};

enum LP_OP_KIND {
    LFOP_UNDEF,

    LFOP_BEGINPAREN,
    LFOP_ENDPAREN,

    LFOP_AND,
    LFOP_OR,

    LFOP_PRED,
};

enum LFPRED_KIND {
    LFPRED_UNDEF,
    LFPRED_SIZE,
};

struct LFPRED_ENTITY {
    LFPRED_KIND predkind_;
    union {
        int* size_;
        char* name_;
        char* content_;
        int* mtime_;
    } preddata_;
};

struct LFOP_ENTITY {
    LP_OP_KIND kind_;
    LFPRED_ENTITY* pPred_;
};

typedef void (*fnOnHit)(const char* file);
LIBFILEFINDSHARED_EXPORT int efind(
        LF_GLOBAL_OPTION* pOption,
        int nDirCount,
        const char** dirs,
        int nOpCount,
        LFOP_ENTITY* ppEntity,
        fnOnHit onHit);




#endif // LIBFILEFIND_H
