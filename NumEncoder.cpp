//Nick Georgi Amanda Alex
#include "NumEncoder.h"
//This method calculates the number of characters that a particular encoding should have(and returns a binary string representing that number) based on the number of characters in the user input and the version
std::string NumEncoder::getCharCountBinString(QR::VERSION ver, int char_count)
{
    int num_bits = 0;
    //These control statements set the number of bits the binary string needs to represent the input based on the version.
    if(ver <= QR::V_NINE){
        num_bits = 10;
    }
    else if(ver <= QR::V_TWENTY_SIX){
        num_bits = 12;
    }
    else if(ver < QR::UNDEFINED_VERSION){
        num_bits = 14;
    }

    return convertNumToBin(num_bits, char_count);
}
//This method takes in an input string from the user and encodes it using the numeric type encoding method.
std::string NumEncoder::getEncoding(std::string input)
{
    std::ostringstream oss;
    //This for loop takes chunks of 3 digits from the input and conversts those values to binary and adds them to the oss string stream.
    int limit = input.size() % 3; // either 1 or 0 or 2
    for(unsigned int i = 0; i < input.size() - limit; i+=3){
        std::istringstream iss(input.substr(i, 3));
        int value = 0;
        iss >> value;
        oss << toBinary(value);
    }
    //This method runs when there are extra bits outside of the groups of three and computes their binary values and adds them to the string.
    if(limit){
        std::istringstream iss(input.substr(input.size()-limit, input.size()));
        int value = 0;
        iss >> value;
        oss << toBinary(value);
    }
    return oss.str();
}
