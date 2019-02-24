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

class CEntity
{
    LFOP_ENTITY entity_;
    LFPRED_ENTITY pred_;
    unsigned long long data_ = 0;
    std::string nameData_;

public:
    CEntity(LFOP_KIND kind)
    {
        memset(&entity_, 0, sizeof(entity_));
        entity_.cbsize = sizeof(entity_);
        entity_.kind = kind;

        memset(&pred_, 0, sizeof(pred_));
        pred_.cbsize = sizeof(pred_);

    }
    void setMinsize(unsigned long long size)
    {
        data_ = size;
        pred_.predkind = LFPRED_KIND::LFPRED_MINSIZE;
        pred_.preddata.minsize = &data_;

        entity_.pPred = &pred_;
    }
    void setName(const string& name)
    {
        nameData_ = name;
        pred_.predkind = LFPRED_KIND::LPFRED_NAME;
        pred_.preddata.name = (char*)nameData_.c_str();

        entity_.pPred = &pred_;
    }
    const LFOP_ENTITY& entity() const {
        return entity_;
    }
};

int test2()
{
    vector<LFOP_ENTITY> entities;

    CEntity entMinsize(LFOP_KIND::LFOP_PRED);
    entMinsize.setMinsize(5 * 1024 * 1024);
    entities.push_back(entMinsize.entity());

    CEntity entOr(LFOP_KIND::LFOP_OR);
    entities.push_back(entOr.entity());

    CEntity entNameCef(LFOP_KIND::LFOP_PRED);
    entNameCef.setName("cef");
    entities.push_back(entNameCef.entity());

    const char* dirs[1];
    dirs[0] = R"(C:\Linkout\Dicregate64\)";

    int ret = efind(
                nullptr,
                _countof(dirs),
                dirs,
                static_cast<int>(entities.size()),
                entities.data(),
                OnHit
                );

    return ret;
}

int test1()
{


    vector<LFOP_ENTITY> entities;


    LFOP_ENTITY entity1;
    entity1.cbsize = sizeof(entity1);
    entity1.kind = LFOP_KIND::LFOP_PRED;

    LFPRED_ENTITY pred1;
    pred1.cbsize = sizeof(pred1);
    pred1.predkind = LFPRED_KIND::LFPRED_MINSIZE;
    unsigned long long minsize=5 * 1024 * 1024;
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
    unsigned long long maxsize=30 * 1024 * 1024;
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

int main(int argc, char* argv[])
{
    vector<string> commandoptions;
    for(int i=1; i < argc; ++i)
    {
        string s = argv[i];
        commandoptions.emplace_back(s);
    }
    // TODO:parse commandoptions

    test2();

    cout << "==============================" << endl;

    test1();
    return 0;
}
