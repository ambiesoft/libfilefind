#ifndef LIBFILEFIND_H
#define LIBFILEFIND_H

#include "libfilefind_global.h"


// This struct is a placeholder for the type of pointer making unique.
typedef struct EFCommandHandle_t {} *EFCommandHandle;

// String representing logical expression.
// ex) "A and (B or (D and E))"
LIBFILEFINDSHARED_EXPORT EFCommandHandle CreateCommand(const char* command);
LIBFILEFINDSHARED_EXPORT int efind(const char* dir,
                                   EFCommandHandle handle);



#endif // LIBFILEFIND_H
