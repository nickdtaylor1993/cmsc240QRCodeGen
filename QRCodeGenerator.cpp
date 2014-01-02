#include "QRCodeGenerator.h"

QRCodeGenerator::QRCodeGenerator(QR::MODE enc_mode, QR::ECC_LEVEL ecc_level)
{
    // creating the encoder depending on the mode of encoding
    switch(enc_mode){
        case QR::ALPHA_NUM:
            encoder = new AlphaNumEncoder();
            break;
        case QR::NUM:
            encoder = new NumEncoder();
            break;
        case QR::UNDEFINED_MODE:
            std::cerr << "UNDEFINED MODE" << std::endl;
            break;
    }


    // creating the encoder depending on the mode of encoding
    ecc_gen = new ECCgenerator(ecc_level);
}

QRCodeGenerator::~QRCodeGenerator()
{
    delete encoder;
    delete ecc_gen;
}

QRCode* QRCodeGenerator::getQRCode(std::string input_message)
{
    std::vector<unsigned char> data_codewords = encoder->getEncoding(input_message, ecc_gen->getLevel());
    std::cout << data_codewords.size() << endl;
    if(data_codewords.size() == 0){
        std::cerr << "COULD NOT PASS THROUGH DATA ENCODING STEP" << std::endl;
        exit(1);
    }
    
    // // Hello worlds
    // char codewords[16] = {32, 91, 11, 120, 209, 114, 220, 77, 67, 64, 236, 17, 236, 17, 236, 17};
    // std::vector<unsigned char> data_codewords;
    // data_codewords.assign(codewords, codewords + sizeof(codewords));

    std::vector<unsigned char> ecc_codewords  = ecc_gen->getECC(data_codewords);

    QR::VERSION ver = table.getVersion(data_codewords.size(), ecc_codewords.size());

    std::vector<unsigned char> final_message = interleaver.interleave(data_codewords, ecc_codewords, ecc_gen->getLevel(), ver);

    std::vector<unsigned char> binary_message = processMessage(final_message, ver);

    QRCode* qr_code = new QRCode(binary_message, ver, ecc_gen->getLevel());
	
    return qr_code;
}

std::vector<unsigned char> QRCodeGenerator::processMessage(vector<unsigned char>& charMessage, QR::VERSION ver)
{

        const int CODEWORD_SIZE = 8;
        std::vector<unsigned char> binary;
        for(unsigned int i = 0; i < charMessage.size(); i++)
        {
                std::bitset<CODEWORD_SIZE> bits(charMessage[i]);

                //cout << "bits: " << bits << endl;

                for(int j = CODEWORD_SIZE-1; j >= 0; j--)
                {
                        //cout << bits[j];
                        binary.push_back(bits[j]);
                }
                //cout << " " << endl;
        }

        int rem = remTable.getRemainderBits(ver); // this parameter si just for testing!!! when you move the method to QRCodeGenerator.cpp, you must pass in the actual VERSION from there

        for(int i=0; i < rem; i++)
        {
                binary.push_back(0);
        }

        return binary;
}
