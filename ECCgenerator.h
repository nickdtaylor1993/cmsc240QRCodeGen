// author : Georgi Lekov

#ifndef __ECCGENERATOR_H__
#define __ECCGENERATOR_H__

#include <map>
#include <vector>
#include "ECC_Table.h"

// This class generates reed solomon error correction codewords for a specific
// level of encoding. The user must provide a vecor of data codewords, whose
// length corresponds the standartized amount of data codewords for the
// specific level and encoding (see ecc_table on thonky.com)
class ECCgenerator
{
    public:
        // possible values of galois field range
        static const int GF_RANGE = 256; 

        ECCgenerator(QR::ECC_LEVEL lev);

        ~ECCgenerator();

        // Returns the ecc level that this ECCgenerator encodes data codewords in
        QR::ECC_LEVEL getLevel() { return level; }

        // Returns a vector conaining the error correction codewords for the
        // given data codewords.
        // Note: if the given data codewords don't correspond to the amount
        // required for the supported versions and ECC levels, the method
        // returns an empty vector. Check ECC_Table to see supported versions
        // and ecc_levels
        std::vector<unsigned char> getECC(std::vector<unsigned char> data_words); 

    private:
        ECC_Table ecc_table;
        QR::ECC_LEVEL level; // level of encoding of this ecc generator

        // key: number of ecc words
        // value: corresponding generator polynomial
        std::map<int, std::vector<int> > gen_poly_table;


        // log antilog tables 
        static const int integers[GF_RANGE];
        static const int exponents[GF_RANGE];


        // Splits the given data words into a vector of blocks of appropriate
        // size corresponding to the version given.
        std::vector<std::vector<int> > splitIntoBlocks(QR::VERSION ver, 
                                                       std::vector<int>& data);

        // Returns a vector of ecc words containing the given number of ecc
        // words specified
        std::vector<int> getECCForBlock(int num_ecc_words, std::vector<int>& data_words);

        // Divides the message polynomial by the generator polynomial and
        // returns the resulting vector of codewords
        std::vector<int> dividePoly(std::vector<int>& mess_poly, 
                                    std::vector<int>& gen_poly);

        // XOR operation between polynomial ONE and polynomial TWO, and returns
        // the result as a vector
        std::vector<int> xor_poly(std::vector<int>& polyONE, 
                                  std::vector<int>& polyTWO);

        /*
         * Since the given polynomial is a vector of the powers of ALPHA, this
         * algorithm adds the given power to every entry of the vector. This is
         * essentially a multiplication of the polynomial by an entry ALPHA to
         * the given power. The algorithm doesnt allow for powers to get larger
         * than the galois range.
         */
        void mult_poly(int power, std::vector<int>& poly, 
                std::vector<int>& dest);

        /*
         * Converts the polynomial to integer notation using the log antilog
         * table
         */
        void conv_poly_to_int_notation(std::vector<int>& poly);

};
#endif
