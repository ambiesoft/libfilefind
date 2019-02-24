
#include <string>

#include "../../../lsMisc/stdosd/stdosd.h"
#include "libfilefind.h"
#include "parser.h"

using namespace std;
using namespace Ambiesoft::stdosd;

bool walkDir(LF_OPPARSER opParser, const string& dir, fnOnHit onHit)
{
    // QDir qdir(dir);
    HFILEITERATOR hIterator = stdCreateFileIterator(dir);
    FileInfo fi;
    while(stdFileNext(hIterator, &fi))
    {
        if(opParser.Evaluate(fi))
        {
            onHit(stdCombinePath(dir,fi.name()).c_str());
        }

        if(fi.isDirectory())
        {
            if(!walkDir(opParser, stdCombinePath(dir, fi.name()), onHit))
                return false;
        }
    }
    stdCloseFileIterator(hIterator);

//    QDirIterator it(dir,
//                    QStringList(),
//                    QDir::AllEntries | QDir::NoDotAndDotDot);
//                    // QDirIterator::Subdirectories);
//    while (it.hasNext())
//    {
//        it.next();
//        // qDebug() << it.fileInfo();
//        if(opParser.Evaluate(it.fileInfo()))
//        {
//            onHit(it.filePath().toStdString().c_str());
//        }

//        if(it.fileInfo().isDir())
//        {
//            if(!walkDir(opParser, it.filePath(), onHit))
//                return false;
//        }
//    }
    return true;
}
