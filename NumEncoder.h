#ifndef __NUM_ENCODER_H__
#define __NUM_ENCODER_H__

#include "Encoder.h"

class NumEncoder: public Encoder
{
	public:
        QR::VERSION getSmallestVersion(QR::ECC_LEVEL lev, int num_characters)
        {
            return cc_table.getSmallestVersion(lev, QR::NUM, num_characters); 
        }

        std::string getModeIndicator() { return "0001"; }

        std::string getCharCountBinString(QR::VERSION ver, int char_count);

        std::string getEncoding(std::string input);
};
#endif
