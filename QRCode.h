//ECHO ECHO ECHO...
#ifndef __QRCode_h__
#define __QRCode_h__

#include <vector>

class QRCode
{
    private:
        std::vector<unsigned char> final_message;
        QR::VERSION version; 
        QR::ECC_LEVEL level;

    public:
        QRCode(std::vector<unsigned char> codewords, QR::VERSION version, QR::ECC_LEVEL lev)
            :final_message(codewords), version(version), level(lev) {}

        ~QRCode() { }
       
        QR::VERSION getVersion() const { return version; }; 

        QR::ECC_LEVEL getEccLevel() const { return level; };

        unsigned char getElement(int i) const { return final_message[i]; };  

        std::vector<unsigned char> getFinalMessage() const { return final_message; }; 



};

#endif
