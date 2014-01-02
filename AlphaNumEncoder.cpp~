//Nick Georgi Amanda Alex
#include "AlphaNumEncoder.h"
#include <iostream>
//This method returns a binary string that represents the number of the bits needed to represent the user input and the version being used.
std::string AlphaNumEncoder::getCharCountBinString(QR::VERSION ver, int char_count)
{
    int num_bits = 0;
    //These control statements set the number of bits the binary string needs to represent the input based on the version.
    if(ver <= QR::V_NINE){
        num_bits = 9;
    }
    else if(ver <= QR::V_TWENTY_SIX){
        num_bits = 11;
    }
    else if(ver < QR::UNDEFINED_VERSION){
        num_bits = 13;
    }
    return convertNumToBin(num_bits, char_count);
}
//This method takes an input string from the user and encodes it using the alphanumeric encoding method
std::string AlphaNumEncoder::getEncoding(std::string input)
{
    std::ostringstream oss;
        //This for loop takes chunks of 3 digits from the input and conversts those values to binary and adds them to the oss string stream.
    int limit = input.size() % 2; // either 1 or 0
    for(unsigned int i = 0; i < input.size() - limit; i+=2){
        oss << convertNumToBin(11, (alpha_num_values[input[i]] * 45) + alpha_num_values[input[i+1]]);
    }
//This method runs when there are extra bits outside of the groups of two and computes their binary values and adds them to the string.
    if(limit){
        oss << convertNumToBin(6, alpha_num_values[input[input.size()-1]]);
    }
    return oss.str();
}
