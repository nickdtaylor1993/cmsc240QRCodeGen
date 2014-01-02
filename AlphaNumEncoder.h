#ifndef __ALPHA_NUM_ENCODER_H__
#define __ALPHA_NUM_ENCODER_H__

#include "Encoder.h"

class AlphaNumEncoder: public Encoder
{
    public:
        QR::VERSION getSmallestVersion(QR::ECC_LEVEL lev, int num_characters)
        {
            return cc_table.getSmallestVersion(lev, QR::ALPHA_NUM, num_characters); 
        }

        std::string getModeIndicator() { return "0010"; }

        std::string getCharCountBinString(QR::VERSION ver, int char_count);

        std::string getEncoding(std::string input);
};
#endif
