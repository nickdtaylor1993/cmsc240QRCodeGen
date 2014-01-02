/****************************Group README **************************************\
Project: QR code generator
Description:
In our product we created a QR code generator, 

The work was divided up as the following

Amanda: developed an Encoder class, and the child classes AlphaNumEncoder, and NumEncoder class that takes in a message and gives the resulted encoding of the message for the error correction codewords. 

Georgi: The Error correction class functionalty which takes in the encoding from the encoder class and produces the error correction codewords.

Sarah: Developed a Interleaver class that takes the encoding from Amanda's encoding class and Georgi's Error Correction class and interleaves them into a single vector. Sarah also created the Viewer class which handles the graphical user interface that takes a ModuleMatrix object and displays the Matrix content in a GUI. 

Nicholas and Alex: Developed a ModuleMatrix class that handles the population of modules in the Matrix using a 2D array simulated with a bool** array (or pointer that points to a array of booleans). The ModuleMatrix also handles the Masking and adding of formation infomation as well. 

Features: 
The feautres of our product include the multiple classes used to implement the class which include: APLT.cpp /.h , AlphaNumEncoder.cpp/.h CC_Table.cpp / .h , ECC_Table.cpp / .h , ECCgenerator.cpp / .h , Encoder.cpp / .h , Interleaver.cpp / .h , ModuleMatrix.cpp / .h , NumEncoder.cpp / .h , Parser.cpp / .h , QRCode.h , QRCodeGenerator.cpp / .h , Rem_Table.cpp / .h,  Viewer.cpp /.h, qrgen.cpp.

Limitations:
Our QR code generator project generates the correct qr code for "HELLO WORLD" M (with a error correction level of M). This test also works with only using capital letters which was specified in the tutorial on thonky.com. Correct Qr codes are limited past this; through testing we found that numbers and spaces had a tendancy of throwing off the correct encoding. Also the "L" error correction level works for "HELLOWORLD"  and other none spaced all capital words. Alphanumeric hasnt supported number and letters in our testing. Also the numeric case doesnt work with the L error correction level stated. However what it does do is generate new qr codes which demonstrates a product that unfortuantely does not work 100%  in terms of generating the exactly correct qr code that can be scanned. The good news is that it does demosntrate an actual qr code and shows that all of classes work together however with a few bugs that still need to be fixed which is more than likely very minimal. 


Instructions to how to use the QR code generator:

Do make in the current directory. If that doesnt work delete the makefile and
do:
    qmake -project
    qmake directory_name.proj
    								//and call make again to compile

Then on the qmake object that was created run by command line arguments such as the following the [message][error correction level].  The message that needs to be run must be capitalized and the error correction level is specified as either M or L. 


Example of how it looks to run it:

./FINAL_240_ECHO "HELLO WORLD" M

Integration testing:

In order to test the overrall product we use the file qrgen.cpp which acts as our driver which checks the number of command line arguments passed in which should be a message and error correction level and then calls our parser method which determines the input message mode and also the error correction level specified from the user via command line.  Then using a QRCodeGenerator takes the mode, error correction level, and the message and determines the correct qr code data bit string that is passed into the Module matrix which then populates the Matrix and masks it. The Matrix then displays its content using the Viewer class. From this stage we used scanning application to test the printed out matrix's correctness. Testing of a group became bug fixes as team after all the classes were brought to a modestly working order. 
Successfull test case included:
./FINAL_240_ECHO "8675309" "M"
./FINAL_240_ECHO "HELLO WORLD" "M"
./FINAL_240_ECHO "HELLOWORLD" "L"
./FINAL_240_ECHO "ALEX" "M"
./FINAL_240_ECHO "ALEX" "L"
./FINAL_240_ECHO "NICK" "M"
./FINAL_240_ECHO "NICK" "L"
./FINAL_240_ECHO "COOLKIDSDONTUSESPACES" "M"
along with other in this format. 
In regards to actual testing each one of us created our own unique testing sub directories in which we tested our individual classes that we implemented for the project such as with Amanda her encoding classes, sarah her interleaving and viewer, Georgi his error correction class, and Nicholas and Alex with the Module Matrix.  These tests will be described in depth in each of our individual README files.  
