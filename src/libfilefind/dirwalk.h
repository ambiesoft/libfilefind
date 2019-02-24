#ifndef DIRWALK_H
#define DIRWALK_H

#include <string>
#include "parser.h"

bool walkDir(LF_OPPARSER opParser, const std::string& dir, fnOnHit onHit);

#endif // DIRWALK_H
