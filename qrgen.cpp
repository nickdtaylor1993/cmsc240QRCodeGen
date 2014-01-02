#include <cstdlib>
#include <iostream>
#include <QApplication>
#include "ECC_Table.h"
#include "Parser.h"
#include "QRCodeGenerator.h"
#include "QRCode.h"
#include "Viewer.h"
#include "ModuleMatrix.h"
//This is the driver class which builds each of the class objects and actually builds the viewer and module matrix to be placed ontop of it
int main(int argc, char** argv)
{
	if(argc < 3){
		std::cerr << "Usage: " << argv[0] << " [message] [error code correction level]" << std::endl;
		exit(1);
	}

	QApplication app(0,0);

	std::string input_message(argv[1]);
	std::string ecc_level(argv[2]);

	Parser parser;
	Viewer viewer;

    QR::MODE mode = parser.getMode(input_message);
    QR::ECC_LEVEL lev = parser.getECC_level(ecc_level);

    if(mode == UNDEFINED_MODE){
        std::cerr << "Cannot determine mode for encoding. Message"
            << "must contain only alphanumeric characters." << std::endl;
        exit(1);
    }
    if(lev == UNDEFINED_LEVEL){
        std::cerr << "Cannot determine error correction level. Error code correction level"
            << "must be a single letter. Currently only L and M levels are supported" << std::endl;
        exit(1);
    }

    QRCodeGenerator qr_code_gen(mode, lev);

	QRCode* qr_code = qr_code_gen.getQRCode(input_message);
	ModuleMatrix matrix(*qr_code);

    matrix.mask();


	viewer.displayMatrix(matrix);
	viewer.show();

	delete qr_code;
	return app.exec();
}
