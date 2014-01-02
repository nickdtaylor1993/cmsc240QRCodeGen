// author: Amanda and Georgi
#include "Encoder.h"
#include "Parser.h"
//This method determines the mode wanted from the user input and returns the wanted mode.
QR::MODE Parser::getMode(std::string input)
{	
	int size = input.length();
    QR::MODE enc_mode = UNDEFINED_MODE;

    bool cantbenum = false;

	for(int i= 0; i < size; i++)
	{
		char x = input[i];

		int ascii = static_cast<int>(x);

		if((ascii >= 48 && ascii <= 57) && !cantbenum){
			enc_mode = NUM;
        }
        else if( (ascii >= 65 && ascii <= 90) || (ascii == 32) || (ascii >= 48 && ascii <= 57)){
            cantbenum = true;
            enc_mode = ALPHA_NUM;
        }
        else{
			enc_mode = UNDEFINED_MODE; 
			std::cerr << "Invalid input character. Cannot determine mode" << std::endl; 
		}	
	}

    return enc_mode;
}

//This method returns the Error correction level given by the user
QR::ECC_LEVEL Parser::getECC_level(std::string level)
{
    if(level == "L")
        return QR::ECC_L;
    else if(level == "M")
        return QR::ECC_M;

    return QR::UNDEFINED_LEVEL;
}
