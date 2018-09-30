
#include <QVariant>
#include <QDir>
#include <QDirIterator>
#include <QDebug>
#include <QFileInfo>

#include "../../../lsMisc/stdosd/OpParser.h"

#include "libfilefind.h"
#include "parser.h"
#include "dirwalk.h"


using namespace std;
using namespace Ambiesoft::Logic;





bool lfEvaluator(const LFPRED_ENTITY& entity, const QFileInfo& fi)
{
    switch(entity.predkind_)
    {
    case LFPRED_UNDEF:
        return false;
    case LFPRED_SIZE:
        // qDebug() << QString("Entity=%1,FI=%2,'%3'").arg(*entity.preddata_.size_).arg(fi.size()).arg(fi.filePath());
        if( *entity.preddata_.size_ < fi.size() )
            return true;
    }
    return false;
}
LIBFILEFINDSHARED_EXPORT int efind(
        LF_GLOBAL_OPTION* pOption,
        int nDirCount,
        const char** dirs,
        int nOpCount,
        LFOP_ENTITY* pEntity,
        fnOnHit onHit)
{
    Q_UNUSED(pOption);
    LF_OPPARSER opParser(lfEvaluator);

    for(int i=0 ; i < nOpCount; ++i,++pEntity)
    {
        switch(pEntity->kind_)
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
            opParser.AddPredicator(*pEntity->pPred_);
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
