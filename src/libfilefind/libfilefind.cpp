#include "libfilefind.h"

#include "../../../lsMisc/OpParser.h"

using namespace std;
using namespace Ambiesoft::Logic;


Libfilefind::Libfilefind()
{
}

enum EFIND_ERROR {
    EFIND_NOERROR = 0,
    NULL_COMMAND = -1,
    EMPTY_COMMAND = -2,
};

int efind(const char* command,
          EFfGetNext ufGetNext)
{
    if(command==nullptr)
        return NULL_DIR;

    if(command[0] == '\0')
        return EMPTY_DIR;


    return EFIND_NOERROR;
}
