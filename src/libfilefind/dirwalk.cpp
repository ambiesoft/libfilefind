
#include <QDir>
#include <QDirIterator>
#include <QDebug>

#include "libfilefind.h"
#include "parser.h"

bool walkDir(LF_OPPARSER opParser, const QString& dir, fnOnHit onHit)
{
    QDir qdir(dir);
    QDirIterator it(dir,
                    QStringList(),
                    QDir::AllEntries | QDir::NoDotAndDotDot);
                    // QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();
        // qDebug() << it.fileInfo();
        if(opParser.Evaluate(it.fileInfo()))
        {
            onHit(it.filePath().toStdString().c_str());
        }

        if(it.fileInfo().isDir())
        {
            if(!walkDir(opParser, it.filePath(), onHit))
                return false;
        }
    }
    return true;
}
