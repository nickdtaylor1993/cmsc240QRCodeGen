// author: Georgi Lekov
#ifndef ALLIGNMENT_H
#define ALLIGNMENT_H
#include "ECC_Table.h"
// Alignmen Pattern Location Table (check on thonky)
class APLT
{
    public:
        APLT();
        ~APLT();

        int getC0(QR::VERSION ver) { return algn_coords[ver].c0; }
        int getC1(QR::VERSION ver) { return algn_coords[ver].c1; }
        int getC2(QR::VERSION ver) { return algn_coords[ver].c2; }
        int getC3(QR::VERSION ver) { return algn_coords[ver].c3; }
        int getC4(QR::VERSION ver) { return algn_coords[ver].c4; }
        int getC5(QR::VERSION ver) { return algn_coords[ver].c5; }
        int getC6(QR::VERSION ver) { return algn_coords[ver].c6; }

        struct coord {
            int c0, c1, c2, c3, c4, c5, c6;

            coord(): c0(0), c1(0), c2(0), c3(0), c4(0), c5(0), c6(0)
            {}
        };

        coord algn_coords[QR::UNDEFINED_VERSION];

};
#endif
