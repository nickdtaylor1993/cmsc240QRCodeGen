#ifndef _MODULEMATRIX_H_
#define _MODULEMATRIX_H_
//Alexander Beman Nick Taylor
#include <vector> 
#include <utility>
#include "APLT.h"
#include "QRCode.h"
#include "ECC_Table.h" 
#include "math.h"
#include <cstdlib>
#include <iostream>
using namespace std; 
using namespace QR; 
class ModuleMatrix
{
  public:
    // populates the modules of the matrix using the qr_code
    ModuleMatrix(const QRCode& qr_code);

    ~ModuleMatrix();
    //This method masks the modular matrix
    void mask();

    // void addFormatInfo();
    int getWidth(); 
    int getHeight(); 
    //returns a pointer to the element at the specified row and column
    //If there is no element at the given row/column the function returns null
     bool getElement(int row, int column); // stub for now
     //This method prints out the contents of the modular matrix
     void print();

  private:
     //The height and width of the matrix. 
     int width;
     int height;
     //sets the eccLevel from qr_code
     QR::ECC_LEVEL eccLevel;
     // Used for the size of the matrix. 
     int SIZE; 


     //Struct used to check the content of each module in the QR matrix module
     //With knowledge about whether the space is avaialbe, is a format reserved space, or a version reserved space position. 
     struct positionContent
     {
         bool isSpaceAvailable; 
         bool isSpaceFormatReserved;
         bool isSeperator; 
         bool isFinder;
         bool isFunctionPattern;   
         bool isSpaceVersionReserved; 
         bool isTimingPattern;
     };
     //This struct has a field for each masking pattern and when the correct masking pattern is determined it sets that field to true
     struct maskingPatterns
     {
         bool pattern1;
         bool pattern2; 
         bool pattern3;
         bool pattern4;
         bool pattern5;
         bool pattern6;
         bool pattern7;
         bool pattern8; 
     }; 
     //This method determines which masking pattern shold be used for the current modular matrix
     void determineMaskPattern(); 

     //Creates an array of positionContent structs. 
     positionContent** matrixInfo;
     //this is an instance of the maskingPattern struct
     maskingPatterns maskType;   
     //this data field determine the lowest masking pattern
     int lowMask; 
     //Used for the alignment pattern.     
     APLT aplt;  

     //Used for the matrix module. 
     bool** Matrix;

     //Used to get the version format string pattern. 
     bool* getVersionFormatStrings(QR::VERSION version);	

     //Is the version number of the module Matrix.
     QR::VERSION versionNumber; 

     //Is the string data bits for the module Matrix. 
     vector<unsigned char>  dataBits; 

     //Add the Format/Version String into the QRCODE
     void addFormatVersion(int maskLevel);
     void populateVersionSpace(bool* array);
     void populateFormatSpace(bool array[]);

     //Adds the seperator patterns into the Module matrix. 
     void addSeperator(int col, int row); 

     //Adds the finder patterns into the Module matrix. 
     void createFinderPatterns(int col, int row); 
     //This method use the APLT table to determine all possible alignment patter coordinates and stores them as pairs into a vector of pairs. It then returns that vector.
     std::vector<pair<int, int> > getAligmentCenterCoordinates();
     //Adds the alignment patterns into the Module matrix. 
     void createAlignmentPatterns(); 

     //Adds the timing patterns for the Module matrix. 
     void createTimePatterns (); 

     //Adds the dark module for the Module matrix. 
     void addDarkModule(int col, int row); 

     //Adds the data bits into the Module matrix. 
     void addDataBits(vector<unsigned char> data); 

     //Add the format reserved information. 
     void addFormatReservedInfo(int col, int row); 

     //Add the version reserved information.
     void addVersionReservedInfo(int col, int row); 

     //Adds the function patterns into the module matrix. 
     void addFunctionPatterns(); 

     //Adds the reserved areas into the module matrix. 
     void AddReservedAreas();
     //These methods take a masked modular matrix determine the penalties associated with that masking pattern scheme.
     int getPenaltyRuleOne(bool** array); 
     int getPenaltyRuleTwo(bool** array); 
     int getPenaltyRuleThree(bool** array); 
     int getPenaltyRuleFour(bool** array); 
     //These methods mask a modular matrix with a particualr masking algorithm
     void checkMask1(bool** cpy);
     void checkMask2(bool** cpy);
     void checkMask3(bool** cpy);
     void checkMask4(bool** cpy);
     void checkMask5(bool** cpy);
     void checkMask6(bool** cpy);
     void checkMask7(bool** cpy);
     void checkMask8(bool** cpy);
     //This methods calculates the number of penalties by summing values returned by running each fo the penalty counter methods
     int getNumPenalties(bool** array);
    //This is a testing method for printing out the modular matrix 
    void printBoolArray(bool** array);
};
#endif
