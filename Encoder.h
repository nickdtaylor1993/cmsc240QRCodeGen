// ECHO ECHO ECHO...
// author: Georgi Lekov

#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <bitset>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include "ECC_Table.h"
#include "Parser.h"
#include "CC_Table.h"

using namespace QR;

class Encoder
{


    public:
        Encoder();
        virtual ~Encoder() {}
        virtual std::vector<unsigned char> getEncoding(std::string data, QR::ECC_LEVEL ecc_level);
        std::string getData();

    protected:
        CC_Table cc_table;
        ECC_Table ecc_table;
        map<char, int> alpha_num_values;

        virtual QR::VERSION getSmallestVersion(QR::ECC_LEVEL lev, int length) = 0;
        virtual std::string getModeIndicator() = 0;
        virtual std::string getCharCountBinString(QR::VERSION ver, int char_count) = 0;
        virtual std::string getEncoding(std::string input) = 0;
        std::string convertNumToBin(const int num_bits, int char_count);
        std::string toBinary(int num); 
        std::vector<unsigned char> convertToDecimal(std::string binary);

};
#endif

