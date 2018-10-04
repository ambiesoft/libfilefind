#include <vector>
#include <string>

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
    vector<string> commandoptions;
    for(int i=1; i < argc; ++i)
    {
        string s = argv[i];
        commandoptions.emplace_back(s);
    }
    // TODO:parse commandoptions

    vector<LFOP_ENTITY> entities;


    LFOP_ENTITY entity1;
    entity1.cbsize = sizeof(entity1);
    entity1.kind = LFOP_KIND::LFOP_PRED;

    LFPRED_ENTITY pred1;
    pred1.cbsize = sizeof(pred1);
    pred1.predkind = LFPRED_KIND::LFPRED_MINSIZE;
    int minsize=5 * 1024 * 1024;
    pred1.preddata.minsize = &minsize;

    entity1.pPred = &pred1;


    entities.emplace_back(entity1);




    LFOP_ENTITY entity2;
    entity2.cbsize = sizeof(entity2);
    entity2.kind = LFOP_KIND::LFOP_AND;

    entities.emplace_back(entity2);






    LFOP_ENTITY entity3;
    entity3.cbsize = sizeof(entity3);
    entity3.kind = LFOP_KIND::LFOP_PRED;

    LFPRED_ENTITY pred3;
    pred3.cbsize = sizeof(pred3);
    pred3.predkind = LFPRED_KIND::LFPRED_MAXSIZE;
    int maxsize=30 * 1024 * 1024;
    pred3.preddata.maxsize = &maxsize;

    entity3.pPred = &pred3;


    entities.emplace_back(entity3);








    const char* dirs[1];
    dirs[0] = R"(C:\Linkout\Dicregate64\)";

    int ret = efind(
                nullptr,
                1,
                dirs,
                static_cast<int>(entities.size()),
                entities.data(),
                OnHit
                );

    return ret;
}
