// author : Georgi Lekov
// WARNING : SLOPPY CODE 
    

#include "ECCgenerator.h"

ECCgenerator::ECCgenerator(QR::ECC_LEVEL lev)
:level(lev)
{
    // initializing the generator polynomials
    int gen_poly1[8]   = {0, 87, 229, 146, 149, 238, 102, 21};
    int gen_poly2[11]  = {0, 251, 67, 46, 61, 118, 70, 64, 94, 32, 45};
    int gen_poly3[16]  = {0, 8, 183, 61, 91, 202, 37, 51, 58, 58, 237, 140, 124, 5, 99, 105};
    int gen_poly4[17]  = {0, 120, 104, 107, 109, 102, 161, 76, 3, 91, 191, 147, 169, 182, 194, 225, 120};
    int gen_poly5[19]  = {0, 215, 234, 158, 94, 184, 97, 118, 170, 79, 187, 152, 148, 252, 179, 5, 98, 96, 153};
    int gen_poly6[21]  = {0, 17, 60, 79, 50, 61, 163, 26, 187, 202, 180, 221, 225, 83, 239, 156, 164, 212, 212, 188, 190};
    int gen_poly7[23]  = {0, 210, 171, 247, 242, 93, 230, 14, 109, 221, 53, 200, 74, 8, 172, 98, 80, 219, 134, 160, 105, 165, 231};
    int gen_poly8[25]  = {0, 229, 121, 135, 48, 211, 117, 251, 126, 159, 180, 169, 152, 192, 226, 228, 218, 111, 0, 117, 232, 87, 96, 227, 21};
    int gen_poly9[27]  = {0, 173, 125, 158, 2, 103, 182, 118, 17, 145, 201, 111, 28, 165, 53, 161, 21, 245, 142, 13, 102, 48, 227, 153, 145, 218, 70};
    int gen_poly10[29] = {0,168, 223, 200, 104, 224, 234, 108, 180, 110, 190, 195, 147, 205, 27, 232, 201, 21, 43, 245, 87, 42, 195, 212, 119, 242, 37, 9, 123};
    int gen_poly11[31] = {0, 41, 173, 145, 152, 216, 31, 179, 182, 50, 48, 110, 86, 239, 96, 222, 125, 42, 173, 226, 193, 224, 130, 156, 37, 251, 216, 238, 40, 192, 180};

    // populating the map with generator polynomials
    gen_poly_table[7]. assign(gen_poly1,  gen_poly1  + sizeof(gen_poly1) / sizeof(int) ); 
    gen_poly_table[10].assign(gen_poly2,  gen_poly2  + sizeof(gen_poly2) / sizeof(int) );
    gen_poly_table[15].assign(gen_poly3,  gen_poly3  + sizeof(gen_poly3) / sizeof(int) );
    gen_poly_table[16].assign(gen_poly4,  gen_poly4  + sizeof(gen_poly4) / sizeof(int) );
    gen_poly_table[18].assign(gen_poly5,  gen_poly5  + sizeof(gen_poly5) / sizeof(int) );
    gen_poly_table[20].assign(gen_poly6,  gen_poly6  + sizeof(gen_poly6) / sizeof(int) );
    gen_poly_table[22].assign(gen_poly7,  gen_poly7  + sizeof(gen_poly7) / sizeof(int) );
    gen_poly_table[24].assign(gen_poly8,  gen_poly8  + sizeof(gen_poly8) / sizeof(int) );
    gen_poly_table[26].assign(gen_poly9,  gen_poly9  + sizeof(gen_poly9) / sizeof(int) );
    gen_poly_table[28].assign(gen_poly10, gen_poly10 + sizeof(gen_poly10)/ sizeof(int) );
    gen_poly_table[30].assign(gen_poly11, gen_poly11 + sizeof(gen_poly11)/ sizeof(int) );
}

ECCgenerator::~ECCgenerator() {}

std::vector<unsigned char> ECCgenerator::getECC(std::vector<unsigned char> orig_data)
{
    std::vector<int> data_words;
    for(unsigned int i = 0; i < orig_data.size(); i++){
        data_words.push_back(orig_data[i]);
    }

    QR::VERSION ver = ecc_table.getVersion(data_words.size(), level);
    int num_ecc_words = ecc_table.getNumEccWords(data_words.size(), level);

    if(ver == QR::UNDEFINED_VERSION || num_ecc_words == 0){
        return std::vector<unsigned char>();
    }


    // split input into 2 groups and each group into blocks. The division
    // operations will be executed on each block
    // a block is a vector of codewords
    std::vector< std::vector<int> > blocks = splitIntoBlocks(ver, data_words);

    std::vector<int> results;
    for(unsigned int i = 0; i < blocks.size(); i++){
        std::vector<int> ecc_words = getECCForBlock(num_ecc_words, blocks[i]);

        // appending the ecc_words to the ecc_words from previous blocks
        results.insert(results.end(), ecc_words.begin(), ecc_words.end());
    }

    std::vector<unsigned char> to_return;
    to_return.insert(to_return.end(), results.begin(), results.end());

    return to_return;
}

// Splits the given data words into a vector of blocks of appropriate
// size corresponding to the version given.
std::vector<std::vector<int> > ECCgenerator::splitIntoBlocks(QR::VERSION ver, std::vector<int>& data)
{
    // determining the number of blocks, words and groups
    int num_block_grpONE = ecc_table.getNumBlocksGrpONE(ver, level);
    int num_word_in_block_grpONE = ecc_table.getNumWordsInBlockGrpONE(ver, level);
    int num_block_grpTWO = ecc_table.getNumBlocksGrpTWO(ver, level);
    int num_word_in_block_grpTWO = ecc_table.getNumWordsInBlockGrpTWO(ver, level);

    int local_data_index = 0; // determines the point to which we have traversed data

    // copying the appropriate codewords from the input data the blocks and
    // words in group ONE
    int grpONE_blocks[num_block_grpONE][num_word_in_block_grpONE];
    for(int i = 0; i < num_block_grpONE; i++){
        for(int j =0; j < num_word_in_block_grpONE; j++){
            grpONE_blocks[i][j] = data[local_data_index];
            local_data_index++;
        }
    }

    // copying the appropriate codewords from the input data the blocks and
    // words in group TWO
    int grpTWO_blocks[num_block_grpTWO][num_word_in_block_grpTWO];
    for(int i = 0; i < num_block_grpTWO; i++){
        for(int j =0; j < num_word_in_block_grpTWO; j++){
            grpTWO_blocks[i][j] = data[local_data_index];
            local_data_index++;
        }
    }

    std::vector<std::vector<int> > blocks;

    // transfer the blocks to a vector
    for(int i = 0; i < num_block_grpONE; i++){
        blocks.push_back(std::vector<int>()); // creating an empty vector
        blocks[i].assign(grpONE_blocks[i], grpONE_blocks[i] + num_word_in_block_grpONE);
    }

    // transfer the blocks to a vector
    int m = 0;
    for(int i = num_block_grpONE; i < num_block_grpONE + num_block_grpTWO; i++){
        blocks.push_back(std::vector<int>()); // creating an empty vector
        blocks[i].assign(grpTWO_blocks[m], grpTWO_blocks[m] + num_word_in_block_grpTWO);
        m++;
    }

    return blocks;
}

// Returns a vector of ecc words containing the given number of ecc
// words specified
std::vector<int> ECCgenerator::getECCForBlock(int num_ecc_words, std::vector<int>& data_words)
{
    // error check
    if(num_ecc_words == 0) return std::vector<int>();

    // finding the generator polynomial
    std::vector<int> gen_poly = gen_poly_table[num_ecc_words];

    int num_steps = data_words.size();
    for(int i = 0; i < num_steps; i++){
        data_words = dividePoly(data_words, gen_poly);
    }

    return data_words;
}

// Divides the message polynomial by the generator polynomial and
// returns the resulting vector of codewords
std::vector<int> ECCgenerator::dividePoly(std::vector<int>& mess_poly, 
        std::vector<int>& gen_poly)
{
    // step 1a from tutorial
    std::vector<int> tmp_poly;
    // multiply the generator polynomial by the alpha notation version of the
    // leading term of the message polynomial, and store the result in tmp poly
    mult_poly(exponents[(mess_poly[0])], gen_poly, tmp_poly);
    conv_poly_to_int_notation(tmp_poly);

    // step 1b
    // xor the result from the multiplication above with the original
    // polynomial and store the results in mess_poly
    std::vector<int> result = xor_poly(tmp_poly, mess_poly);

    //discard leading 0
    for(unsigned int i = 1; i < result.size(); i++){
        result[i-1] = result[i];
    }
    result.pop_back();

    return result;
}


/* performs a bitwise XOR between the elements of polyONE and polyTWO and
 * stores the result is returned as a vector. If the 2 vectors differ in
 * length, 0 is used as one of the operands to XOR.
 */
std::vector<int> ECCgenerator::xor_poly(std::vector<int>& polyONE, 
                                                  std::vector<int>& polyTWO)
{
    // used to determine how many elements we should have in the destination
    // vector
    unsigned int max_size = std::max(polyONE.size(), polyTWO.size());
    std::vector<int> dest(max_size); // the vector to store the results
    // XOR the two polynomials
    for(unsigned int i = 0; i < max_size; i++){
        int opONE = 0;
        int opTWO = 0;
        // if we are past the end for one of the vectors, use only a 0
        if(i < polyONE.size()){
            opONE = polyONE[i];
        }
        if(i < polyTWO.size()){
            opTWO = polyTWO[i];
        }
        dest[i] = opONE ^ opTWO;
    }
    return dest;
}


/*
 * Since the given polynomial is a vector of the powers of ALPHA, this
 * algorithm adds the given power to every entry of the vector. This is
 * essentially a multiplication of the polynomial by an entry ALPHA to the
 * given power. The algorithm doesnt allow for powers to get larger than the
 * galois range.
 */
void ECCgenerator::mult_poly(int power, std::vector<int>& poly, std::vector<int>& dest)
{
    for(unsigned int i = 0; i < poly.size(); i++){
        // add the power to the one in the polynomial, and restrict so it
        // doesnt't become larger thatn GF_RANGE
        dest.push_back( ((poly[i]) + power) % (GF_RANGE - 1) );
    }
}

/*
 * Converts the polynomial to integer notation using the log antilog table
 */
void ECCgenerator::conv_poly_to_int_notation(std::vector<int>& poly)
{
    for(unsigned int i = 0; i < poly.size(); i++){
        poly[i] = integers[(poly[i])];
    }
}

const int ECCgenerator::integers[GF_RANGE] = 
{1, 2, 4, 8, 16, 32, 64, 128, 29, 58,
    116, 232, 205, 135, 19, 38, 76, 152, 45, 90,
    180, 117, 234, 201, 143, 3, 6, 12, 24, 48,
    96, 192, 157, 39, 78, 156, 37, 74, 148, 53,
    106, 212, 181, 119, 238, 193, 159, 35, 70, 140,
    5, 10, 20, 40, 80, 160, 93, 186, 105, 210,
    185, 111, 222, 161, 95, 190, 97, 194, 153, 47,
    94, 188, 101, 202, 137, 15, 30, 60, 120, 240,
    253, 231, 211, 187, 107, 214, 177, 127, 254, 225,
    223, 163, 91, 182, 113, 226, 217, 175, 67, 134,
    17, 34, 68, 136, 13, 26, 52, 104, 208, 189,
    103, 206, 129, 31, 62, 124, 248, 237, 199, 147,
    59, 118, 236, 197, 151, 51, 102, 204, 133, 23,
    46, 92, 184, 109, 218, 169, 79, 158, 33, 66,
    132, 21, 42, 84, 168, 77, 154, 41, 82, 164,
    85, 170, 73, 146, 57, 114, 228, 213, 183, 115,
    230, 209, 191, 99, 198, 145, 63, 126, 252, 229,
    215, 179, 123, 246, 241, 255, 227, 219, 171, 75,
    150, 49, 98, 196, 149, 55, 110, 220, 165, 87,
    174, 65, 130, 25, 50, 100, 200, 141, 7, 14,
    28, 56, 112, 224, 221, 167, 83, 166, 81, 162,
    89, 178, 121, 242, 249, 239, 195, 155, 43, 86,
    172, 69, 138, 9, 18, 36, 72, 144, 61, 122,
    244, 245, 247, 243, 251, 235, 203, 139, 11, 22,
    44, 88, 176, 125, 250, 233, 207, 131, 27, 54,
    108, 216, 173, 71, 142, 1};

const int ECCgenerator::exponents[GF_RANGE] = 
{0, 0, 1, 25, 2, 50, 26, 198, 3, 223,
    51, 238, 27, 104, 199, 75, 4, 100, 224, 14,
    52, 141, 239, 129, 28, 193, 105, 248, 200, 8,
    76, 113, 5, 138, 101, 47, 225, 36, 15, 33,
    53, 147, 142, 218, 240, 18, 130, 69, 29, 181,
    194, 125, 106, 39, 249, 185, 201, 154, 9, 120,
    77, 228, 114, 166, 6, 191, 139, 98, 102, 221,
    48, 253, 226, 152, 37, 179, 16, 145, 34, 136,
    54, 208, 148, 206, 143, 150, 219, 189, 241, 210,
    19, 92, 131, 56, 70, 64, 30, 66, 182, 163,
    195, 72, 126, 110, 107, 58, 40, 84, 250, 133,
    186, 61, 202, 94, 155, 159, 10, 21, 121, 43,
    78, 212, 229, 172, 115, 243, 167, 87, 7, 112,
    192, 247, 140, 128, 99, 13, 103, 74, 222, 237,
    49, 197, 254, 24, 227, 165, 153, 119, 38, 184,
    180, 124, 17, 68, 146, 217, 35, 32, 137, 46,
    55, 63, 209, 91, 149, 188, 207, 205, 144, 135,
    151, 178, 220, 252, 190, 97, 242, 86, 211, 171,
    20, 42, 93, 158, 132, 60, 57, 83, 71, 109,
    65, 162, 31, 45, 67, 216, 183, 123, 164, 118,
    196, 23, 73, 236, 127, 12, 111, 246, 108, 161,
    59, 82, 41, 157, 85, 170, 251, 96, 134, 177,
    187, 204, 62, 90, 203, 89, 95, 176, 156, 169,
    160, 81, 11, 245, 22, 235, 122, 117, 44, 215,
    79, 174, 213, 233, 230, 231, 173, 232, 116, 214,
    244, 234, 168, 80, 88, 175};

