

#include "../../../lsMisc/stdosd/OpParser.h"

#include "libfilefind.h"
#include "parser.h"
#include "dirwalk.h"


using namespace std;
using namespace Ambiesoft::Logic;
using namespace Ambiesoft::stdosd;





bool lfEvaluator(const LFPRED_ENTITY& entity, const FileInfo& fi)
{
    switch(entity.predkind)
    {
    case LFPRED_UNDEF:
        return false;
    case LFPRED_MINSIZE:
        // qDebug() << QString("Entity=%1,FI=%2,'%3'").arg(*entity.preddata_.size_).arg(fi.size()).arg(fi.filePath());
        if( *entity.preddata.minsize < fi.size() )
            return true;
        break;
    case LFPRED_MAXSIZE:
        // qDebug() << QString("Entity=%1,FI=%2,'%3'").arg(*entity.preddata_.size_).arg(fi.size()).arg(fi.filePath());
        if( *entity.preddata.maxsize >= fi.size() )
            return true;
        break;

    case LPFRED_NAME:
        if(fi.name().find(entity.preddata.name) != string::npos)
            return true;
        break;

    case LFPRED_MINMTIME:
        break;
    case LFPRED_MAXMTIME:
        break;
    }
    return false;
}
LIBFILEFINDSHARED_EXPORT int efind(
        LF_GLOBAL_OPTION* /* pOption */,
        int nDirCount,
        const char** dirs,
        int nOpCount,
        LFOP_ENTITY* pEntity,
        fnOnHit onHit)
{
    LF_OPPARSER opParser(lfEvaluator);

    for(int i=0 ; i < nOpCount; ++i,++pEntity)
    {
        switch(pEntity->kind)
        {
        case LFOP_BEGINPAREN:
            opParser.AddBeginningParenthesis();
            break;
        case LFOP_ENDPAREN:
            opParser.AddEndingParenthesis();
            break;
        case LFOP_AND:
            opParser.AddAnd();
            break;
        case LFOP_OR:
            opParser.AddOr();
            break;
        case LFOP_PRED:
            opParser.AddPredicator(*pEntity->pPred);
            break;
        default:
            return LFERROR_NOOPENTITYKIND;
        }
    }
    for(int i=0 ; i < nDirCount; ++i)
    {
        const char* dir = dirs[i];
        if(dir==nullptr)
            return LFERROR_NULL_DIR;

        if(dir[0] == '\0')
            return LFERROR_EMPTY_DIR;

        // TODO: to function
        walkDir(opParser, dir, onHit);
    }


    return LFERROR_NOERROR;
}
