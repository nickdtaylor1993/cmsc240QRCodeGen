//author:Georgi Lekov

#ifndef CC_TABLE_H
#define CC_TABLE_H

#include "ECC_Table.h"
#include <map>
using namespace std;
using namespace QR;

class CC_Table
{
    public:
        CC_Table();
        ~CC_Table();
        QR::VERSION getSmallestVersion(QR::ECC_LEVEL lev, QR::MODE mode, int length);

    private:
        map<ECC_LEVEL, map<MODE, map<int , VERSION> > > char_capacity;

};
#endif
