// author: Amanda and Georgi
#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include "ECC_Table.h"
#include <iostream>
using namespace QR;

// Takes in arguments and parses them to determine characteristics about them
class Parser
{
    public:
        // Returns the MODE in which the given string should be encoded
        // (numeric, alpha numeric, etc)
        QR::MODE getMode(std::string input);

        // Returns the ECC Level enum type, corresponding to the given string
        // containing a character determinining the level. e.g. "L" is QR::ECC_L 
        QR::ECC_LEVEL getECC_level(std::string level); 
};

#endif
