#ifndef PARSER_H
#define PARSER_H

#include "../../../lsMisc/stdosd/OpParser.h"
#include "../../../lsMisc/stdosd/stdosd.h"


#include "libfilefind.h"

// #define LF_OPPARSER Ambiesoft::Logic::OpParser<LFPRED_ENTITY, QFileInfo>
typedef Ambiesoft::Logic::OpParser<LFPRED_ENTITY, Ambiesoft::stdosd::FileInfo> LF_OPPARSER;


#endif // PARSER_H
