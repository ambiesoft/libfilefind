#include "libfilefind.h"

#include "../../../lsMisc/OpParser.h"

using namespace std;
using namespace Ambiesoft::Logic;



enum EFIND_ERROR {
    EFIND_NOERROR = 0,
    NULL_DIR = -1,
    EMPTY_DIR = -2,
};

LIBFILEFINDSHARED_EXPORT int efind(const char* dir,
                                   EFCommandHandle handle)
{
    if(dir==nullptr)
        return NULL_DIR;

    if(dir[0] == '\0')
        return EMPTY_DIR;


    return EFIND_NOERROR;
}
