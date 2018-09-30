#ifndef DIRWALK_H
#define DIRWALK_H

#include "parser.h"

bool walkDir(LF_OPPARSER opParser, const QString& dir, fnOnHit onHit);

#endif // DIRWALK_H
