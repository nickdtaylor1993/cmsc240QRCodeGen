#ifndef __QRCODE_GENERATOR_H
#define __QRCODE_GENERATOR_H

#include <cstdlib>
#include "ECC_Table.h"
#include "Encoder.h"
#include "AlphaNumEncoder.h"
#include "NumEncoder.h"
#include "ECCgenerator.h"
#include "Interleaver.h"
#include "QRCode.h"
#include "Rem_Table.h"
#include <vector>
#include <bitset>

class QRCodeGenerator
{
    private:

        Encoder* encoder;
        ECCgenerator* ecc_gen;
        Interleaver interleaver;
        ECC_Table table;
        Rem_Table remTable;

    public:
        QRCodeGenerator(QR::MODE enc_mode, QR::ECC_LEVEL ecc_level);
        ~QRCodeGenerator();

        QRCode* getQRCode(std::string input_message);

std::vector<unsigned char> processMessage(vector<unsigned char>& charMessage, QR::VERSION ver);
 
	//std::vector<unsigned char> processMessage(vector<unsigned char>& charMessage);

};
#endif
