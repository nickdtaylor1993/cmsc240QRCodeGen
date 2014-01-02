//ECHO ECHO ECHO 
// author: Georgi Nick Amanda Alex

#include "Encoder.h"
#include <iostream>
using namespace std;
//This the encode constructor which has a table which sets a value associated with each alpha numeric character
Encoder::Encoder()
{
    alpha_num_values['0'] = 0;
    alpha_num_values['1'] = 1;
    alpha_num_values['2'] = 2;
    alpha_num_values['3'] = 3;
    alpha_num_values['4'] = 4;
    alpha_num_values['5'] = 5;
    alpha_num_values['6'] = 6;
    alpha_num_values['7'] = 7;
    alpha_num_values['8'] = 8;
    alpha_num_values['9'] = 9;
    alpha_num_values['A'] = 10;
    alpha_num_values['B'] = 11;
    alpha_num_values['C'] = 12;
    alpha_num_values['D'] = 13;
    alpha_num_values['E'] = 14;
    alpha_num_values['F'] = 15;
    alpha_num_values['G'] = 16;
    alpha_num_values['H'] = 17;
    alpha_num_values['I'] = 18;
    alpha_num_values['J'] = 19;
    alpha_num_values['K'] = 20;
    alpha_num_values['L'] = 21;
    alpha_num_values['M'] = 22;
    alpha_num_values['N'] = 23;
    alpha_num_values['O'] = 24;
    alpha_num_values['P'] = 25;
    alpha_num_values['Q'] = 26;
    alpha_num_values['R'] = 27;
    alpha_num_values['S'] = 28;
    alpha_num_values['T'] = 29;
    alpha_num_values['U'] = 30;
    alpha_num_values['V'] = 31;
    alpha_num_values['W'] = 32;
    alpha_num_values['X'] = 33;
    alpha_num_values['Y'] = 34;
    alpha_num_values['Z'] = 35;
    alpha_num_values[' '] = 36;
    alpha_num_values['$'] = 37;
    alpha_num_values['%'] = 38;
    alpha_num_values['*'] = 39;
    alpha_num_values['+'] = 40;
    alpha_num_values['-'] = 41;
    alpha_num_values['.'] = 42;
    alpha_num_values['/'] = 43;
    alpha_num_values[':'] = 44;
}
//This method takes in the string input from the user and the wanted error correction level and returns of a vector of chars that is the encoded version of the inputed code
std::vector<unsigned char> Encoder::getEncoding(std::string input, QR::ECC_LEVEL lev)
{
    QR::VERSION ver = getSmallestVersion(lev, input.size());
    //if the version is undefined prints an error to the user.
    if(ver == QR::UNDEFINED_VERSION){
        std::cerr<< "Input too large, or arguments for data encoding incorrect" << std::endl;
        return std::vector<unsigned char>();
    }
    //This section builds the encoding string using other helper methods
    std::string mode_indicator = getModeIndicator();
    std::string char_count_bin = getCharCountBinString(ver, input.size());
    std::string encoding = getEncoding(input);
    int total_num_bits = ecc_table.getNumDataWords(ver, lev) * 8;

    std::string final_binary = mode_indicator + char_count_bin + encoding;
    //concatonates the needed number of terminator bits
    int num_terminator_bits = total_num_bits - final_binary.size();
    if(num_terminator_bits > 4){
        num_terminator_bits = 4;
    }
    for(int i = 0; i < num_terminator_bits; i++){
        string tmp = "0";
        final_binary += tmp;
    }
    // padding additionally with zeros
    while(final_binary.length() % 8){
        string tmp = "0";
        final_binary += tmp;
    }
    int counter = 0;
    string tmp1 = "11101100";
    string tmp2 = "00010001";
    while(final_binary.length() < (unsigned)total_num_bits)
    {
        if(counter%2 == 0)
        {
        final_binary += tmp1;
        }
        else
        {
        final_binary += tmp2;
        }
        counter++;
    }
    std::vector<unsigned char> dec_codewords = convertToDecimal(final_binary);
	//returns of vectors of chars which are (0s or 1s)
    return dec_codewords;
}
//Thos method converts an integer to a its binary equivlent
std::string Encoder::convertNumToBin(const int num_bits, int num)
{
    std::string tmp = toBinary(num);
    return std::string(num_bits-tmp.length(), '0').append(tmp);
}
//this method takes a decimal value and converts it to binary
std::string Encoder::toBinary(int dec_val) 
{
    // observing dec_val as unsigned, so that shift operations are logical
    // instead of arithmetic.
    unsigned int number = (unsigned)dec_val;

    std::ostringstream oss;

    if(number != 0){
        // populate the buffer char array from right to left with the bits
        // corresponding to the decimal number given as an argument
        while(number){
            // check if least significant bit is set
            if (number & 1)
                oss << "1";
            else
                oss << "0";

            // hide the last bit by shifting 1 bit to the right
            // the conversion to unsigned is to force an arithmetic instead of
            // logical shift !
            number >>= 1;
        }
    }
    else{
        oss << "0";
    }
    
    std::string result = oss.str();

    return string(result.rbegin(), result.rend());
}
//This method takes a string and converts its contents to a vector of binary chars
std::vector<unsigned char> Encoder::convertToDecimal(std::string binary)
{
    const int CODEWORD_SIZE = 8;
    std::vector<unsigned char> decimal;
    if(binary.length() % CODEWORD_SIZE != 0){
        std::cerr << "binary not multiple of 8" << std::endl;
    }

    for(unsigned int i = 0; i < binary.length(); i+=CODEWORD_SIZE){
        std::bitset<CODEWORD_SIZE> bits(binary.substr(i, i+CODEWORD_SIZE));
        decimal.push_back(bits.to_ulong());
    }

    //return the populated vector of chars.
    return decimal;
}
