#include <iostream>
#include <QtCore>

#include "../libfilefind/libfilefind.h"
using namespace std;

void OnHit(const char* file)
{
    cout << file << endl;
}
int main(int argc, char* argv[])
{
    LFOP_ENTITY entities[1];

    LFOP_ENTITY entity;
    entity.kind_ = LP_OP_KIND::LFOP_PRED;

    LFPRED_ENTITY pred;
    pred.predkind_ = LFPRED_KIND::LFPRED_SIZE;
    int size=10 * 1024 * 1024;
    pred.preddata_.size_ = &size;

    entity.pPred_ = &pred;
    entities[0] = entity;

    const char* dirs[1];
    dirs[0] = "c:\\linkout\\";
    int ret = efind(
                nullptr,
                1,
                dirs,
                1,
                entities,
                OnHit
                );

    return ret;
}
