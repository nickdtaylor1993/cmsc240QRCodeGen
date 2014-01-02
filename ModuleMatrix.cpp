//Alexander Beman Nick Taylor
#include "ModuleMatrix.h"
#include <climits>
#include <string> 
#include <vector>
using namespace std; 

ModuleMatrix::ModuleMatrix(const QRCode& qr_code){
    //Gets version number for the QR CODE.  
    versionNumber = qr_code.getVersion();

    //Gets the data bits for the QR Code. 
    dataBits = qr_code.getFinalMessage();

    //Using the version number calculates the size of the module matrix. 	
    SIZE = (((versionNumber)*4)+21);
    //need EccLevel from QR class
    eccLevel = qr_code.getEccLevel();
    //inits a bool* array for the Matrix module.   
    Matrix = new bool*[SIZE]; 

    //Inits a matrixInfo* array for the Matrix module. 
    matrixInfo = new positionContent*[SIZE]; 

    //Within each pointer of bool or matrixInfo inits an array of bool and matrixInfo. 
    for(int i = 0; i < SIZE; i++){
        Matrix[i] = new bool[SIZE];
        matrixInfo[i] = new positionContent[SIZE];	
    }

    //Sets that each position is available initialially. 
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            matrixInfo[i][j].isSpaceAvailable = true; 
            matrixInfo[i][j].isFinder = false; 
            matrixInfo[i][j].isSeperator = false; 	
            matrixInfo[i][j].isSpaceFormatReserved = false; 	
            matrixInfo[i][j].isSpaceVersionReserved = false; 	
            matrixInfo[i][j].isFunctionPattern = false; 
            Matrix[i][j] = false;
        }
    }
    //This method call adds the function patterns to the module matrix and populates the data bits after the matrix has been intialized
    addFunctionPatterns();

}
//This method returns the width of the modular matrix
int ModuleMatrix::getWidth(){

    return SIZE; 
}
//This method returns the hieght of the modular matrix
int ModuleMatrix::getHeight(){

    return SIZE; 
}
//Thie method returns the content of the modular matrix at a given coordinate
bool ModuleMatrix::getElement(int row, int col){
    return Matrix[row][col]; 
}
//This is the deconstructor for the modular matrix
ModuleMatrix::~ModuleMatrix(){
    //Deletes each of the array of pointers
    for(int i = 0; i < SIZE; i++){
        delete[] Matrix[i]; 
        delete[] matrixInfo[i]; 
    }

    //Deletes the dynamically allocated 
    delete[] Matrix; 
    delete[] matrixInfo; 
}
//This method takes the coordinates of the bottom left corner/top right corner/bottom left corner of each fo the three finder patterns and populates the modular matrix with each finder pattern. It then sets those spaces as unavailable for overwriting.
void ModuleMatrix::createFinderPatterns(int col, int row){	
    for(int i = col; i < col + 7; i++){
        for(int j = row; j <  row +7; j++){
            //set all spaces in the finder pattern to be un-overwritable
            matrixInfo[i][j].isSpaceAvailable = false;
            matrixInfo[i][j].isSpaceFormatReserved = false;
            matrixInfo[i][j].isSpaceVersionReserved = false;
            matrixInfo[i][j].isFunctionPattern = true;
            //based on correct column/row areas populate the module matrix to true.
            if(i == col || i == col+6){
                Matrix[i][j] = true; 
                matrixInfo[i][j].isFinder = true; 
            }
            else{
                if(i == col+1 || i == col+5){
                    if(j == row+2 || j == row+3 || j == row+4){
                        Matrix[i][j] = false; 
                        matrixInfo[i][j].isFinder = true; 
                    }

                    if(j == row || j == row+6){
                        Matrix[i][j] = true; 
                        matrixInfo[i][j].isFinder = true; 
                    }
                }
                else{
                    if(j == row+2|| j==row+3 || j == row+4){
                        Matrix[i][j] = true; 
                        matrixInfo[i][j].isFinder = true; 
                    }

                    if( j == row || j == row+6){
                        Matrix[i][j] = true; 
                        matrixInfo[i][j].isFinder = true; 
                    }
                }	
            }
        }	
    }
}
//This method takes the coordinates of the bottom left corner/top right corner/bottom left corner of each fo the three finder patterns and populates the modular matrix with each seperator pattern based on those coordinates. It then sets those spaces as unavailable for overwriting.
void ModuleMatrix::addSeperator(int col, int row){
    //Add  top-left seperator. 
    if(row == 0 && col == 0){
        for(int i = col; i < col+8; i++){
            for(int j = row; j < row+8; j++){
                if((j == row+7) || (i == col+7)){
                    //sets sperator areas to be un-overwritable and sets their positions in the module matrix to false
                    Matrix[i][j] = false; 
                    matrixInfo[i][j].isSeperator = true; 
                    matrixInfo[i][j].isSpaceAvailable = false; 
                    matrixInfo[i][j].isSpaceFormatReserved = false; 
                    matrixInfo[i][j].isSpaceVersionReserved = false; 
                    matrixInfo[i][j].isFunctionPattern = true; 
                }	
            }
        }
    }

    //Add the top-right seperator. 
    if(row != 0 && col == 0){
        for(int i = col; i < col + 8; i++){
            for(int j = row-1; j < row + 7; j++){
                if((j == row-1) || (i == col+7)){
                    //sets sperator areas to be un-overwritable and sets their positions in the module matrix to false
                    Matrix[i][j] = false; 
                    matrixInfo[i][j].isSeperator = true; 
                    matrixInfo[i][j].isSpaceAvailable = false; 
                    matrixInfo[i][j].isSpaceFormatReserved = false; 
                    matrixInfo[i][j].isSpaceVersionReserved = false; 
                    matrixInfo[i][j].isFunctionPattern = true; 
                }	
            }
        }
    }
    //Add the lower-left seperator. 
    if(col != 0 && row == 0){
        for(int i = col-1; i < col + 7; i++){
            for(int j = row; j < row + 8; j++){
                if(i == col-1|| j == row+7){
                    //sets sperator areas to be un-overwritable and sets their positions in the module matrix to false
                    Matrix[i][j] = false; 
                    matrixInfo[i][j].isSeperator = true; 
                    matrixInfo[i][j].isSpaceAvailable = false; 
                    matrixInfo[i][j].isSpaceFormatReserved = false; 
                    matrixInfo[i][j].isSpaceVersionReserved = false; 
                    matrixInfo[i][j].isFunctionPattern = true; 	
                }
            }
        }
    }
}
//This method adds the timing patterns to the modular matrix and sets the positions populated as timing patterns to be non-overwritable.
void ModuleMatrix::createTimePatterns(){
    //This adds the time patterns going down from the top to bottom. 
    for(int row = 8; row < SIZE-7; row++){
        //Sets all the spaces in the timing patter to be un-overwritable and sets the timiing pattern spaces as timing patterns
        matrixInfo[6][row].isSpaceAvailable = false;  
        matrixInfo[6][row].isSpaceFormatReserved = false; 
        matrixInfo[6][row].isSpaceVersionReserved = false;
        matrixInfo[6][row].isFunctionPattern = false;
        matrixInfo[6][row].isTimingPattern = true; 
        //populates the timing patterns spaces as true false true false ect.
        if(row % 2 == 0){
            Matrix[6][row] = true;
        }
        else{
            Matrix[6][row]	= false; 
        }
    }	

    //This adds the time patterns going right from left to right. 
    for(int col = 8; col < SIZE -7; col++){
        matrixInfo[col][6].isSpaceAvailable = false; 
        matrixInfo[col][6].isSpaceFormatReserved = false; 			
        matrixInfo[col][6].isSpaceVersionReserved = false;
        matrixInfo[col][6].isFunctionPattern = false;
        matrixInfo[col][6].isTimingPattern = true; 
        if(col % 2 == 0){
            Matrix[col][6] = true; 
        }
        else{
            Matrix[col][6] = false; 
        }
    }

}
//This method uses the APLT class to get a all of the possible coordinates for alignment patterns in this version of QRCODE and stores all of the possible combination of the coordinates as pairs into a vector of pairs, and then returns that vector of pairs.
std::vector<pair<int, int> > ModuleMatrix::getAligmentCenterCoordinates()
{
    //uses the APLT classes get coordinates methods and sets those coordinates into an integer
    int c0 = aplt.getC0(versionNumber); 
    int c1 = aplt.getC1(versionNumber); 
    int c2 = aplt.getC2(versionNumber); 
    int c3 = aplt.getC3(versionNumber); 
    int c4 = aplt.getC4(versionNumber); 
    int c5 = aplt.getC5(versionNumber); 
    int c6 = aplt.getC6(versionNumber); 
    //creates an array of coordinates
    int coord[7] = {c0,c1,c2,c3,c4,c5,c6}; 
    std::vector<pair<int, int> > centers;

    //puts every combination of coordinates into a vector of pairs
    for(int i = 0; i < 7 && coord[i] != 0; i++){
        for(int j = 0; j < 7 && coord[j] != 0; j++){
            centers.push_back(make_pair(coord[i], coord[j]));
        }
    }
    //returns a vector containing all of the vectors
    return centers;
}
//This method uses the getAligmentCenterCoordinates method to get all of the possible alignment pattern center coordinates, it then determines which are usable by checking to see if they would be overwriting any populated areas. It then populates each favorable alignment pattern position with an allignment patter and sets the space as un-overwritable.
void ModuleMatrix::createAlignmentPatterns(){

    std::vector<pair<int, int> > centers = getAligmentCenterCoordinates();

    // precondition: a combination of 2 coordinates from the APLT table
    for(unsigned int i = 0; i < centers.size(); i++){
        int col = centers[i].first;
        int row = centers[i].second;

        bool overlap = false;

        // checks whether the aligment pattern overlaps with something before  if it does set overlap to true
        for(int i = col-2; i < col+3; i++){
            for(int j = row-2; j < row+3; j++){

                if( matrixInfo[i][j].isFunctionPattern || 
                        matrixInfo[i][j].isSeperator)
                {
                    overlap = true;
                }
            }
        }

        //if the alignment pattern wont overlap anything populate the allignment pattern postions and set them to be un-overwritable
        if(!overlap){
            for(int i = col-2; i < col+3; i++){
                for(int j = row-2; j < row+3; j++){
                    matrixInfo[i][j].isSpaceAvailable = false; 
                    matrixInfo[i][j].isSpaceFormatReserved = false; 
                    matrixInfo[i][j].isSpaceVersionReserved = false; 
                    matrixInfo[i][j].isFunctionPattern = true; 
                    if(i == (col + 2) || i == (col - 2) || j == (row + 2) || j == (row - 2)){
                        Matrix[i][j] = true; 
                    }
                }
            }

            // setting center to true
            Matrix[col][row] = true;
            matrixInfo[col][row].isSpaceAvailable = false; 
            matrixInfo[col][row].isSpaceFormatReserved = false; 
            matrixInfo[col][row].isSpaceVersionReserved = false; 
            matrixInfo[col][row].isFunctionPattern = true; 
        }
    }
}
//This method takes the coordinates of the Dark Module and populates that spot as true and makes it un-overwritable.
void ModuleMatrix::addDarkModule(int col, int row){
    //Add the dark module into the one position specified. 
    Matrix[col][row] = true; 
    matrixInfo[col][row].isSpaceAvailable = false; 
    matrixInfo[col][row].isSpaceFormatReserved = false; 
    matrixInfo[col][row].isSpaceVersionReserved = false;
    matrixInfo[col][row].isFunctionPattern = true; 
}	
//This method adds the DataBits to the modular matrix with the algorithm specified in the tutorial. It takes in a vector of char(only 0s and 1s) and iterates through it populating the modular matrix in the correct fashion.
void ModuleMatrix::addDataBits(vector<unsigned char> data)
{
    bool up = true;
    bool down = false; 
    int index = 0; 
    int row = SIZE-1; 
    //while there are still rows to populate
    while(row >= 0)
    {
        if(row == 6){
            row--;
        }
        //if we are populating upwards populated from Size-1 to 0
        if(up)
        {
            //iterates so it populates two rows at a time before moving to the next column and checks if the space is avaiable for a bit before adding it.
            for(int col = SIZE-1; col >= 0; col--){
                if(index >= (int)(data.size())){ break;}
                if(matrixInfo[col][row].isSpaceAvailable){
                    if((int)(data[index]) == 0){
                        Matrix[col][row] = false;
                        index++; 
                    }
                    else{
                        Matrix[col][row] = true;
                        index++;  
                    }

                    matrixInfo[col][row].isSpaceFormatReserved = false; 
                    matrixInfo[col][row].isSpaceVersionReserved = false; 
                }
                //if we run out of data bits break
                if(index >= (int)(data.size())){ break;}	
                if(matrixInfo[col][row-1].isSpaceAvailable){
                    if((int)(data[index]) == 0){
                        Matrix[col][row-1] = false;
                        index++; 
                    }
                    else{
                        Matrix[col][row-1] = true;
                        index++;  
                    }

                    matrixInfo[col][row-1].isSpaceFormatReserved = false; 
                    matrixInfo[col][row-1].isSpaceVersionReserved = false; 
                }

            }
            up = false; 
            down = true; 
            row-=2; 	
        }
        if(row == 6){
            row--;
        }
        //if we run out of data bits to populate break
        if(index >= (int)(data.size())){ break;}
        //if we are populating downwards populate from 0 to size
        if(down)
        {
            for(int col = 0; col < SIZE; col++){
                if(index >= (int)(data.size())){ break;}
                if(matrixInfo[col][row].isSpaceAvailable){
                    if((int)(data[index]) == 0){
                        Matrix[col][row] = false;
                        index++; 
                    }
                    else{
                        Matrix[col][row] = true; 
                        index++; 
                    }

                    matrixInfo[col][row].isSpaceFormatReserved = false; 
                    matrixInfo[col][row].isSpaceVersionReserved = false; 
                }
                if(index >= (int)(data.size())){ break;}
                if(matrixInfo[col][row-1].isSpaceAvailable){
                    if((int)(data[index]) == 0){
                        Matrix[col][row-1] = false;
                        index++; 
                    }
                    else{
                        Matrix[col][row-1] = true; 
                        index++; 
                    }


                    matrixInfo[col][row-1].isSpaceFormatReserved = false; 
                    matrixInfo[col][row-1].isSpaceVersionReserved = false; 

                }
            }	
            //if we run out of data bits to populate break
            if(index >= (int)(data.size())){ break;}
            down = false; 
            up = true; 
            row-=2; 
        }
    }	
}
//This method reserves the Fromat Reserved space 
void ModuleMatrix::addFormatReservedInfo(int col, int row){
    //Add format around the top-left finder pattern. 
    if(row == 0 && col == 0){
        for(int i = col; i < col +9; i++){
            for(int j = row; j < row + 9; j++){
                if((i == col+8) || (j == row +8)){
                    if(matrixInfo[i][j].isSpaceAvailable)
                    {
                        //set the format reserved info spaces to un-overwritable
                        matrixInfo[i][j].isSpaceAvailable = false;
                        matrixInfo[i][j].isSpaceFormatReserved = true;
                        Matrix[i][j] = false; 	 	
                    }
                }
            }
        }
    }
    //Adds format info around the bottom-left finder pattern. 
    if(row == 0 && col != 0){
        for(int i = col; i < SIZE; i++){
            if(matrixInfo[i][row+8].isSpaceAvailable)
            {
                matrixInfo[i][row+8].isSpaceFormatReserved = true;
                matrixInfo[i][row+8].isSpaceAvailable = false;		
                Matrix[i][row+8] = false; 
            }
        }
    }
    //Adds format info around the top-right finder pattern. 
    if(col == 0 && row != 0){
        for(int i = row-1; i < SIZE; i++){
            if(matrixInfo[col+8][i].isSpaceAvailable){
                matrixInfo[col+8][i].isSpaceFormatReserved = true; 
                matrixInfo[col+8][i].isSpaceAvailable = false;
                Matrix[col+8][i] = false; 	
            }
        }
    }
}
//This method reserves the version info areas in the modular matrix so that they can not be over written by adding data bits
void ModuleMatrix::addVersionReservedInfo(int col, int row){
    //Adds version reserve info around the bottom-left finder pattern. 
    if(row != 0 && col == 0){
        for(int i = col; i < col+6; i++){
            for(int j = row-4; j < row-1; j++){
                matrixInfo[i][j].isSpaceVersionReserved = true; 
                matrixInfo[i][j].isSpaceAvailable = false; 
                Matrix[i][j] = false; 
            }
        }
    }

    //Adds version reserve info around the top-right finder pattern. 
    else if(row == 0 && col != 0){
        for(int i = col -4; i < col -1; i++){
            for(int j = row; j < row+6; j++){
                matrixInfo[i][j].isSpaceVersionReserved = true; 
                matrixInfo[i][j].isSpaceAvailable = false;
                Matrix[i][j] = false; 	
            }
        }
    }
}

//Adds the function patterns into the module matrix. 
void ModuleMatrix::addFunctionPatterns(){
    //Adds top-Left finder pattern
    createFinderPatterns(0,0); 

    //Adds bottom-Left finder pattern. 
    int colCoord = (((versionNumber)*4)+21-7); 
    createFinderPatterns(colCoord,0);   

    //Adds top-Right finder pattern. 
    int rowCoord = colCoord; 
    createFinderPatterns(0,rowCoord);

    //Adds seperator on the top-Left finder pattern. 
    addSeperator(0,0); 	

    //Adds seperator on the bottom-Left finder pattern. 
    addSeperator(colCoord,0); 
    //Adds seperator on the top-Right finder pattern. 
    addSeperator(0,rowCoord); 
    //Adds the timing patterns into the Module matrix. 
    createTimePatterns(); 
    //Adds VersionReservedSpace
    //This adds in the reserved info based on the version.
    if(versionNumber+1 >= QR::V_SEVEN){
        addVersionReservedInfo(colCoord,0);
        addVersionReservedInfo(0,rowCoord);
    }

    ///Adds FormatReservedSpace
    addFormatReservedInfo(0,0);
    addFormatReservedInfo(colCoord,0);
    addFormatReservedInfo(0,rowCoord);


    if(versionNumber + 1 >= QR::V_TWO){	
        //Adds the alignment patterns into the module matrix. 
        createAlignmentPatterns(); 
    }
    //col and row for the dark module. 
    int col = (4 * (versionNumber+1))+9; 
    int row = 8; 	
    //Adds the dark module into the matrix. 

    addDarkModule(col, row);

    //Adds the data bits into the matrix. 

    addDataBits(dataBits);	


}	
//This method takes a copy of the populated modular matrix that has been masked using a particular masking scheme and calculates the number of penalties that masking scheme would cause using the first penalty checker algorithm.
int ModuleMatrix::getPenaltyRuleOne(bool** array){
    int penalty = 0;  
    //Evaluation Condition #1
    //Checking each row one by one.
    int darkCount = 0;  
    int lightCount = 0; 
    for(int i = 0; i < SIZE; i++){
        for(int j = 1; j < SIZE; j++){
            if(array[i][j-1] == false && array[i][j] == false)
                lightCount++; 
            else 
                lightCount = 0; 

            if(array[i][j-1] == true && array[i][j] == true)
                darkCount++; 
            else
                darkCount = 0; 

            if(darkCount == 5 || lightCount == 5){
                penalty +=3; 
            }

            if(darkCount >5 || lightCount >5)
                penalty++; 
        }
        darkCount = 0;
        lightCount=0; 
    }
    darkCount = 0; 
    lightCount = 0; 
    //Checking each col one by one. 
    for(int i = 0; i < SIZE; i++){
        for(int j = 1; j < SIZE; j++){

            if(array[j-1][i] == false && array[j][i] == false)
                lightCount++; 
            else 
                lightCount = 0;

            if(array[j-1][i] == true && array[j][i] == true)
                darkCount++; 
            else
                darkCount = 0; 

            if(darkCount == 3 || lightCount == 3){
                penalty +=3; 
            }

            if(darkCount > 5 || lightCount > 5)
                penalty++; 
        }
        darkCount = 0; 
        lightCount = 0;  
    }
    return penalty;
}
//This method takes a copy of the populated modular matrix that has been masked using a particular masking scheme and calculates the number of penalties that masking scheme would cause using the sceond penalty checker algorithm.
int ModuleMatrix::getPenaltyRuleTwo(bool** array){
    int penalty =0;    
    for(int i = 0; i < SIZE-2; i+=2){
        for(int j = 0; j < SIZE-2; j+=2){
            if(array[i][j] && array[i][j+1] && array[i+1][j] && array[i+1][j+1]){
                penalty+=3;
            }
            else if(!array[i][j] && !array[i][j+1] && !array[i+1][j] && !array[i+1][j+1]){
                penalty+=3;
            }
        }
    }
    return penalty;
}
//This method takes a copy of the populated modular matrix that has been masked using a particular masking scheme and calculates the number of penalties that masking scheme would cause using the third penalty checker algorithm.
int ModuleMatrix::getPenaltyRuleThree(bool** array){
    bool form1[] = {1,0,1,1,1,0,1,0,0,0,0};
    bool form2[] = {0,0,0,0,1,0,1,1,1,0,1};
    //this method checks chunks of 11 modules first by rows then by columns looking for each of the bit patterns set above.
    int penalty = 0;
    for(int i = 0; i <SIZE; i++){
        for(int j = 11; j < SIZE; j+=11){
            bool flag1 = true;
            bool flag2 = true;
            for(int x = j - 11; x < j; x++){
                if(array[i][(j-11) + x] != form1[x%11]){
                    flag1 = false;
                }
                if(array[i][(j-11) + x] != form2[x%11]){
                    flag2 = false;
                }
            }
            if(flag1){
                penalty+=40;
            }
            if(flag2){
                penalty+=40;
            }
        }
    }

    for(int i = 11; i <SIZE; i+=11){
        for(int j = 0; j < SIZE; j++){
            bool flag1 = true;
            bool flag2 = true;
            for(int x = i - 11; x < i; x++){
                if(array[i-11 + x][j] != form1[x%11]){
                    flag1 = false;
                }
                if(array[i-11 + x][j] != form2[x%11]){
                    flag2 = false;
                }
            }
            if(flag1){
                penalty+=40;
            }
            if(flag2){
                penalty+=40;
            }
        }
    }
    return penalty;
}
//This method takes a copy of the populated modular matrix that has been masked using a particular masking scheme and calculates the number of penalties that masking scheme would cause using the fourth penalty checker algorithm.
int ModuleMatrix::getPenaltyRuleFour(bool** array)
{
    int numDark = 0;
    int numMod = SIZE*SIZE;
    int ratio = 0;
    //counts all of the dark bits to find the ratio of dark bits
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(array[i][j] == true)
            {
                numDark++;
            }
        }
    }
    ratio = (double(numDark)/(numMod))*100;
    int prevMultFive = (ratio/5)*5;
    int nextMultFive = ((ratio/5)+1)*5; //import math class
    prevMultFive = abs(prevMultFive - 50);
    nextMultFive = abs(nextMultFive -50);
    prevMultFive /= 5;
    nextMultFive /= 5;

    return 10*min(prevMultFive, nextMultFive);
}
//This method determines which masking should be used on the module matrix by copying the matrix for each possible masking scheme. Run each masking scheme on each copy of the modular matrix and then uses the penalty checker algorithms to determine which mask would have the least number of penalties.
void ModuleMatrix::determineMaskPattern(){
    bool** maskCopy1;
    bool** maskCopy2; 
    bool** maskCopy3; 
    bool** maskCopy4; 
    bool** maskCopy5; 
    bool** maskCopy6; 
    bool** maskCopy7;
    bool** maskCopy8;
    //inits a bool* array for the Matrix module.   
    maskCopy1 = new bool*[SIZE];
    maskCopy2 = new bool*[SIZE];
    maskCopy3 = new bool*[SIZE];
    maskCopy4 = new bool*[SIZE];
    maskCopy5 = new bool*[SIZE];  
    maskCopy6 = new bool*[SIZE];
    maskCopy7 = new bool*[SIZE];
    maskCopy8 = new bool*[SIZE];
    //Within each pointer of bool or matrixInfo inits an array of bool and matrixInfo. 
    for(int i = 0; i < SIZE; i++){
        maskCopy1[i] = new bool[SIZE];
        maskCopy2[i] = new bool[SIZE];
        maskCopy3[i] = new bool[SIZE];
        maskCopy4[i] = new bool[SIZE];
        maskCopy5[i] = new bool[SIZE];  
        maskCopy6[i] = new bool[SIZE];
        maskCopy7[i] = new bool[SIZE];
        maskCopy8[i] = new bool[SIZE];
    }
    //copies the modular matrix into each of the maskCopies
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j< SIZE; j++){
            maskCopy1[i][j] = Matrix[i][j];
            maskCopy2[i][j] = Matrix[i][j]; 
            maskCopy3[i][j] = Matrix[i][j]; 
            maskCopy4[i][j] = Matrix[i][j]; 
            maskCopy5[i][j] = Matrix[i][j]; 
            maskCopy6[i][j] = Matrix[i][j]; 
            maskCopy7[i][j] = Matrix[i][j];
            maskCopy8[i][j] = Matrix[i][j];

        }
    }
    //masks each copy
    checkMask1(maskCopy1);
    checkMask2(maskCopy2);
    checkMask3(maskCopy3);
    checkMask4(maskCopy4);
    checkMask5(maskCopy5);
    checkMask6(maskCopy6);
    checkMask7(maskCopy7);
    checkMask8(maskCopy8);
    /*
    //testing print method  
    printBoolArray(maskCopy1);
    printBoolArray(maskCopy2);
    printBoolArray(maskCopy3);
    printBoolArray(maskCopy4);
    printBoolArray(maskCopy5);
    printBoolArray(maskCopy6);
    printBoolArray(maskCopy7);
    printBoolArray(maskCopy8);
    */
    //Array that holds the the result of calculating the total number of penalties for each mask
    int penaltyHolder[8];
    penaltyHolder[0] = getNumPenalties(maskCopy1);
    penaltyHolder[1] = getNumPenalties(maskCopy2);
    penaltyHolder[2] = getNumPenalties(maskCopy3);
    penaltyHolder[3] = getNumPenalties(maskCopy4);
    penaltyHolder[4] = getNumPenalties(maskCopy5);
    penaltyHolder[5] = getNumPenalties(maskCopy6);
    penaltyHolder[6] = getNumPenalties(maskCopy7);
    penaltyHolder[7] = getNumPenalties(maskCopy8);
    //This determines which masking method has the lowest penalty count
    int leastPenalties = INT_MAX;
    int lowMask = 0;
    for( int i = 0; i < 8; i++)
    {
        if(penaltyHolder[i] < leastPenalties)
        {
            leastPenalties = penaltyHolder[i];
            lowMask = i;
        }
    }
    //sets the correct masking pattern boolean in the struct determining which the matrix should use
    bool patternCheck[8];
    for(int i =0; i <8; i++)
    {
        if(i == lowMask)
        {
            patternCheck[i] = true;
        }
        else
        {
            patternCheck[i] = false;
        }
    }
    //sets the pattern struct for the lowest penalty masking scheme to true.
    maskType.pattern1 = patternCheck[0];
    maskType.pattern2 = patternCheck[1];
    maskType.pattern3 = patternCheck[2];
    maskType.pattern4 = patternCheck[3];
    maskType.pattern5 = patternCheck[4];
    maskType.pattern6 = patternCheck[5];
    maskType.pattern7 = patternCheck[6];
    maskType.pattern8 = patternCheck[7];
    //Dealocates all copies after they are used.
    for(int i = 0; i < SIZE; i++){
        delete[] maskCopy1[i];
        delete[] maskCopy2[i];
        delete[] maskCopy3[i];
        delete[] maskCopy4[i];
        delete[] maskCopy5[i];  
        delete[] maskCopy6[i];
        delete[] maskCopy7[i];
        delete[] maskCopy8[i];
    }
    delete[] maskCopy1;
    delete[] maskCopy2;
    delete[] maskCopy3;
    delete[] maskCopy4;
    delete[] maskCopy5;  
    delete[] maskCopy6;
    delete[] maskCopy7;
    delete[] maskCopy8; 
} 
//This method takes a masked modular matrix and returns the sum of running all the penalty checker algorithms
int ModuleMatrix::getNumPenalties(bool** array)
{
    int result = 0; 
    result += getPenaltyRuleOne(array) + getPenaltyRuleTwo(array) + getPenaltyRuleThree(array) + getPenaltyRuleFour(array);
    return result;
}
//This method takes a modular matrix and runs the mask scheme 1 algorith on the modular matrix.
void ModuleMatrix::checkMask1(bool** array)
{
    //iterates through whole modular matrix and checks if avaiable spaces match the mask schemes algorithm. If the particular module does it flips the bit value.
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <SIZE; j++){
            if(matrixInfo[i][j].isSpaceAvailable){
                if(((i+j)%2) == 0)
                {
                    if(array[i][j] == false)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = false;
                    }
                }
            }
        }}
}
//This method takes a modular matrix and runs the mask scheme 2 algorith on the modular matrix.
void ModuleMatrix::checkMask2(bool** array)
{
    //iterates through whole modular matrix and checks if avaiable spaces match the mask schemes algorithm. If the particular module does it flips the bit value.
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <SIZE; j++){
            if(matrixInfo[i][j].isSpaceAvailable){
                if( j%2 == 0)
                {
                    if(array[i][j] == false)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = false;
                    }
                }
            }}
    }

}
//This method takes a modular matrix and runs the mask scheme 3 algorith on the modular matrix.
void ModuleMatrix::checkMask3(bool** array)
{
    //iterates through whole modular matrix and checks if avaiable spaces match the mask schemes algorithm. If the particular module does it flips the bit value.
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <SIZE; j++){
            if(matrixInfo[i][j].isSpaceAvailable){
                if(i%3 == 0)
                {
                    if(array[i][j] == false)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = false;
                    }
                }
            }}
    }
}
//This method takes a modular matrix and runs the mask scheme 4 algorith on the modular matrix.
void ModuleMatrix::checkMask4(bool** array)
{
    //iterates through whole modular matrix and checks if avaiable spaces match the mask schemes algorithm. If the particular module does it flips the bit value.
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <SIZE; j++){
            if(matrixInfo[i][j].isSpaceAvailable){
                if(((i+j)%3) == 0)
                {
                    if(array[i][j] == false)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = false;
                    }
                }
            }}
    }
}
//This method takes a modular matrix and runs the mask scheme 5 algorith on the modular matrix.
void ModuleMatrix::checkMask5(bool** array)
{
    //iterates through whole modular matrix and checks if avaiable spaces match the mask schemes algorithm. If the particular module does it flips the bit value.
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <SIZE; j++){ 	
            if(matrixInfo[i][j].isSpaceAvailable){
                if((j/2 + i/3)%2 == 0)
                {
                    if(array[i][j] == false)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = false;
                    }
                }
            }}
    }
}
//This method takes a modular matrix and runs the mask scheme 6 algorith on the modular matrix.
void ModuleMatrix::checkMask6(bool** array)
{
    //iterates through whole modular matrix and checks if avaiable spaces match the mask schemes algorithm. If the particular module does it flips the bit value.
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <SIZE; j++){
            if(((j*i)%2)+((j*i)%3) == 0){
                if(matrixInfo[i][j].isSpaceAvailable){
                    if(array[i][j] == false)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = false;
                    }

                }
            }
        }
    }
}
//This method takes a modular matrix and runs the mask scheme 7 algorith on the modular matrix.
void ModuleMatrix::checkMask7(bool** array)
{
    //iterates through whole modular matrix and checks if avaiable spaces match the mask schemes algorithm. If the particular module does it flips the bit value.
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <SIZE; j++){
            if(matrixInfo[i][j].isSpaceAvailable){
                if((((j*i)%2)+((j*i)%3))%2 == 0)
                {
                    if(array[i][j] == false)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = false;
                    }
                }
            }
        }
    }
}
//This method takes a modular matrix and runs the mask scheme 8 algorith on the modular matrix.
void ModuleMatrix::checkMask8(bool** array)
{
    //iterates through whole modular matrix and checks if avaiable spaces match the mask schemes algorithm. If the particular module does it flips the bit value.
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j <SIZE; j++){
            if(matrixInfo[i][j].isSpaceAvailable){
                if((((j+i)%2)+((j*i)%3))%2 == 0)
                {
                    if(array[i][j] == false)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = false;
                    }
                }
            }
        }
    }
}
//This method adds the format area strings that was set ascide and the version area string that was set ascide. The method takes a masking level and from that masking level determines which format/version string is needed to be placed into the modular matrix
void ModuleMatrix::addFormatVersion(int maskLevel)
{
    //These are all the possible format strings that could be used to populate the format space
    bool infoBits1[15] = {1,1,1,0,1,1,1,1,1,0,0,0,1,0,0};
    bool infoBits2[15] = {1,1,1,0,0,1,0,1,1,1,1,0,0,1,1};
    bool infoBits3[15] = {1,1,1,1,1,0,1,1,0,1,0,1,0,1,0};
    bool infoBits4[15] = {1,1,1,1,0,0,0,1,0,0,1,1,1,0,1};
    bool infoBits5[15] = {1,1,0,0,1,1,0,0,0,1,0,1,1,1,1};
    bool infoBits6[15] = {1,1,0,0,0,1,1,0,0,0,1,1,0,0,0};
    bool infoBits7[15] = {1,1,0,1,1,0,0,0,1,0,0,0,0,0,1};
    bool infoBits8[15] = {1,1,0,1,0,0,1,0,1,1,1,0,1,1,0};
    bool infoBits9[15] = {1,0,1,0,1,0,0,0,0,0,1,0,0,1,0};  
    bool infoBits10[15] = {1,0,1,0,0,0,1,0,0,1,0,0,1,0,1};
    bool infoBits11[15] = {1,0,1,1,1,1,0,0,1,1,1,1,1,0,0}; 
    bool infoBits12[15] = {1,0,1,1,0,1,1,0,1,0,0,1,0,1,1};
    bool infoBits13[15] = {1,0,0,0,1,0,1,1,1,1,1,1,0,0,1};
    bool infoBits14[15] = {1,0,0,0,0,0,0,1,1,0,0,1,1,1,0};  
    bool infoBits15[15] = {1,0,0,1,1,1,1,1,0,0,1,0,1,1,1};
    bool infoBits16[15] = {1,0,0,1,0,1,0,1,0,1,0,0,0,0,0};
    //These if statements ensure that the correct boolean array of version strings/fomrat strings is passed to the populate version space and populate format space methods
    if(maskLevel == 0 && eccLevel == QR::ECC_L)
    {	if(versionNumber >= V_SEVEN){
                                        bool* versionSpaceInfo;  
                                        versionSpaceInfo = getVersionFormatStrings(versionNumber); 

                                        populateVersionSpace(versionSpaceInfo);
                                    }
    populateFormatSpace(infoBits1);
    }
    if(maskLevel == 1 && eccLevel == QR::ECC_L)
    {	bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 

        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits2); 
    }
    if(maskLevel == 2 && eccLevel ==QR::ECC_L)
    {
        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 

        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits3);
    }
    if(maskLevel == 3 && eccLevel ==QR::ECC_L)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits4);
    }
    if(maskLevel == 4 && eccLevel ==QR::ECC_L)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits5);
    }
    if(maskLevel == 5 && eccLevel ==QR::ECC_L)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits6);
    }
    if(maskLevel == 6 && eccLevel ==QR::ECC_L)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits7);
    }
    if(maskLevel == 7 && eccLevel ==QR::ECC_L)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits8);
    }
    if(maskLevel == 0 && eccLevel ==QR::ECC_M)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits9);
    }
    if(maskLevel == 1 && eccLevel ==QR::ECC_M)
    {
        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits10);
    }
    if(maskLevel == 2 && eccLevel ==QR::ECC_M)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits11);
    }
    if(maskLevel == 3 && eccLevel ==QR::ECC_M)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits12);
    }
    if(maskLevel == 4 && eccLevel ==QR::ECC_M)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits13);
    }
    if(maskLevel == 5 && eccLevel ==QR::ECC_M)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits14);
    }
    if(maskLevel == 6 && eccLevel ==QR::ECC_M)
    {

        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 
        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits15);
    }
    if(maskLevel == 7 && eccLevel ==QR::ECC_M)
    {
        bool* versionSpaceInfo;  
        versionSpaceInfo = getVersionFormatStrings(versionNumber); 

        if(versionNumber >= QR::V_SEVEN){
            populateVersionSpace(versionSpaceInfo);
        }
        populateFormatSpace(infoBits16);
    }

}
//This method takes a pre determined correct version space array that contains the correct version space string and then populates the version space of the modular matrix
void ModuleMatrix::populateVersionSpace(bool* array)
{
    int botLeftCol = ((((versionNumber)*4)+21)-7);
    int topRightRow = ((((versionNumber)*4)+21)-7);
    int counter = 0;
    //itterates through the blocks of 6x3 and populates with correct version bits
    for(int j = 0; j <6; j++){
        for(int i = botLeftCol-4; i <botLeftCol-1; i++)
        {
            Matrix[i][j] = array[counter];
            counter++;
        }
    }

    counter = 0;
    for(int i = 0; i <6 ; i++ )
    {
        for(int j = topRightRow -4; j < topRightRow-1; j++)
        {

            Matrix[i][j] = array[counter];
            counter++;
        }
    }
}
//This method takes a pre determined correct format space array that contains the correct format space string and then populates the format space of the modular matrix
void ModuleMatrix::populateFormatSpace(bool array[])
{
    int col = 0;
    int row = 0;
    int topRightRow = ((((versionNumber)*4)+21)-7);

    int botLeftRow = 0;
    int botLeftCol = ((((versionNumber)*4)+21)-7);

    //Adds all the format to the top left 	
    Matrix[0][row+8] = array[14];
    Matrix[1][row+8] = array[13];
    Matrix[2][row+8] = array[12];
    Matrix[3][row+8] = array[11];
    Matrix[4][row+8] = array[10];
    Matrix[5][row+8] = array[9];
    Matrix[7][row+8] = array[8];
    Matrix[8][row+8] = array[7];

    //Adds to left
    Matrix[col+8][row+7] = array[6];

    //Adds to the top left bottom part. 
    Matrix[col+8][0] = array[0];
    Matrix[col+8][1] = array[1];
    Matrix[col+8][2] = array[2];
    Matrix[col+8][3] = array[3];
    Matrix[col+8][4] = array[4];
    Matrix[col+8][5] = array[5];


    //Adds to the top right part. 	
    Matrix[col+8][topRightRow-1] = array[7];
    Matrix[col+8][topRightRow] = array[8];
    Matrix[col+8][topRightRow+1] = array[9];
    Matrix[col+8][topRightRow+2] = array[10];
    Matrix[col+8][topRightRow+3] = array[11];
    Matrix[col+8][topRightRow+4] = array[12];
    Matrix[col+8][topRightRow+5] = array[13];
    Matrix[col+8][topRightRow+6] = array[14];


    //Adds to the bottom part 
    Matrix[botLeftCol+0][botLeftRow+8] = array[6];		
    Matrix[botLeftCol+1][botLeftRow+8] = array[5];
    Matrix[botLeftCol+2][botLeftRow+8] = array[4];
    Matrix[botLeftCol+3][botLeftRow+8] = array[3];
    Matrix[botLeftCol+4][botLeftRow+8] = array[2];
    Matrix[botLeftCol+5][botLeftRow+8] = array[1];
    Matrix[botLeftCol+6][botLeftRow+8] = array[0];

}
//This is the method that controls all of the masking functions. This method uses the determineMaskPattern() method to set which masking pattern should be used. It then masks the modular matrix and then adds the format/version area strings.
void ModuleMatrix::mask(){
    determineMaskPattern();
    //This group of if statements determines which masking method to use and which format/version string to use for populating the version/format info spaces
    if(maskType.pattern1 == true)
    {
        checkMask1(Matrix);

        addFormatVersion(0);
    }
    else if(maskType.pattern2 == true)
    {
        checkMask2(Matrix);

        addFormatVersion(1);
    }
    else if(maskType.pattern3 == true)
    {
        checkMask3(Matrix);
        addFormatVersion(2);
    }
    else if(maskType.pattern4 == true)
    {
        checkMask4(Matrix);
        addFormatVersion(3);
    }
    else if(maskType.pattern5 == true)
    {
        checkMask5(Matrix);
        addFormatVersion(4);
    }
    else if(maskType.pattern6 == true)
    {
        checkMask6(Matrix);
        addFormatVersion(5);
    }
    else if(maskType.pattern7 == true)
    {
        checkMask7(Matrix);
        addFormatVersion(6);
    }
    else if(maskType.pattern8 == true)
    {
        checkMask8(Matrix);
        addFormatVersion(7);
    }
    else
    {
        cerr <<"No Masking pattern was set to true" <<endl;
    }
}
//This method takes the current version of the Modular matrix and determines which version string should be used for the modular matrix
bool* ModuleMatrix::getVersionFormatStrings(QR::VERSION version){

    bool* default_array  = new bool[18]();
    bool* pversionString7  = new bool[18];
    bool* pversionString8  = new bool[18]; 
    bool* pversionString9  = new bool[18]; 
    bool* pversionString10 = new bool[18]; 
    bool* pversionString11 = new bool[18]; 
    bool* pversionString12 = new bool[18]; 
    bool* pversionString13 = new bool[18]; 
    bool* pversionString14 = new bool[18]; 
    bool* pversionString15 = new bool[18]; 
    bool* pversionString16 = new bool[18]; 
    bool* pversionString17 = new bool[18]; 
    bool* pversionString18 = new bool[18]; 
    bool* pversionString19 = new bool[18]; 
    bool* pversionString20 = new bool[18]; 
    bool* pversionString21 = new bool[18]; 
    bool* pversionString22 = new bool[18]; 
    bool* pversionString23 = new bool[18]; 
    bool* pversionString24 = new bool[18]; 
    bool* pversionString25 = new bool[18]; 
    bool* pversionString26 = new bool[18]; 
    bool* pversionString27 = new bool[18]; 
    bool* pversionString28 = new bool[18]; 
    bool* pversionString29 = new bool[18]; 
    bool* pversionString30 = new bool[18]; 
    bool* pversionString31 = new bool[18]; 
    bool* pversionString32 = new bool[18]; 
    bool* pversionString33 = new bool[18]; 
    bool* pversionString34 = new bool[18]; 
    bool* pversionString35 = new bool[18]; 
    bool* pversionString36 = new bool[18]; 
    bool* pversionString37 = new bool[18]; 
    bool* pversionString38 = new bool[18]; 
    bool* pversionString39 = new bool[18]; 
    bool* pversionString40 = new bool[18]; 
    //All possible version strings that could be used to populate version space
    bool versionString7 [18] = {0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0};
    bool versionString8 [18] = {0,0,1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0};
    bool versionString9 [18] = {0,0,1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1};
    bool versionString10[18] = {0,0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1};
    bool versionString11[18] = {0,0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0};
    bool versionString12[18] = {0,0,1,1,0,0,0,1,1,1,0,1,1,0,0,0,1,0};
    bool versionString13[18] = {0,0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1};
    bool versionString14[18] = {0,0,1,1,1,0,0,1,1,0,0,0,0,0,1,1,0,1};
    bool versionString15[18] = {0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0};
    bool versionString16[18] = {0,1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0};
    bool versionString17[18] = {0,1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1};
    bool versionString18[18] = {0,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1};
    bool versionString19[18] = {0,1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1,0};
    bool versionString20[18] = {0,1,0,1,0,0,1,0,0,1,1,0,1,0,0,1,1,0};
    bool versionString21[18] = {0,1,0,1,0,1,0,1,1,0,1,0,0,0,0,0,1,1};
    bool versionString22[18] = {0,1,0,1,1,0,1,0,0,0,1,1,0,0,1,0,0,1};
    bool versionString23[18] = {0,1,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,0};
    bool versionString24[18] = {0,1,1,0,0,0,1,1,1,0,1,1,0,0,0,1,0,0};
    bool versionString25[18] = {0,1,1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,1};
    bool versionString26[18] = {0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1};
    bool versionString27[18] = {0,1,1,0,1,1,0,0,0,0,1,0,0,0,1,1,1,0};
    bool versionString28[18] = {0,1,1,1,0,0,1,1,0,0,0,0,0,1,1,0,1,0};
    bool versionString29[18] = {0,1,1,1,0,1,0,0,1,1,0,0,1,1,1,1,1,1};
    bool versionString30[18] = {0,1,1,1,1,0,1,1,0,1,0,1,1,1,0,1,0,1};
    bool versionString31[18] = {0,1,1,1,1,1,0,0,1,0,0,1,0,1,0,0,0,0};
    bool versionString32[18] = {1,0,0,0,0,0,1,0,0,1,1,1,0,1,0,1,0,1};
    bool versionString33[18] = {1,0,0,0,0,1,0,1,1,0,1,1,1,1,0,0,0,0};
    bool versionString34[18] = {1,0,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0};
    bool versionString35[18] = {1,0,0,0,1,1,0,1,1,1,1,0,0,1,1,1,1,1};
    bool versionString36[18] = {1,0,0,1,0,0,1,0,1,1,0,0,0,0,1,0,1,1};
    bool versionString37[18] = {1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,1,1,0};
    bool versionString38[18] = {1,0,0,1,1,0,1,0,1,0,0,1,1,0,0,1,0,0};
    bool versionString39[18] = {1,0,0,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1};
    bool versionString40[18] = {1,0,1,0,0,0,1,1,0,0,0,1,1,0,1,0,0,1};

    //iterates through all version spaces and stores their value in a version string pointer which is returned
    for(int i = 0; i < 18; i++){
        pversionString7 [i] = versionString7 [i];
        pversionString8 [i] = versionString8 [i];
        pversionString9 [i] = versionString9 [i];
        pversionString10[i] = versionString10[i];
        pversionString11[i] = versionString11[i];
        pversionString12[i] = versionString12[i];
        pversionString13[i] = versionString13[i];
        pversionString14[i] = versionString14[i];
        pversionString15[i] = versionString15[i];
        pversionString16[i] = versionString16[i];
        pversionString17[i] = versionString17[i];
        pversionString18[i] = versionString18[i];
        pversionString19[i] = versionString19[i];
        pversionString20[i] = versionString20[i];
        pversionString21[i] = versionString21[i];
        pversionString22[i] = versionString22[i];
        pversionString23[i] = versionString23[i];
        pversionString24[i] = versionString24[i];
        pversionString25[i] = versionString25[i];
        pversionString26[i] = versionString26[i];
        pversionString27[i] = versionString27[i];
        pversionString28[i] = versionString28[i];
        pversionString29[i] = versionString29[i];
        pversionString30[i] = versionString30[i];
        pversionString31[i] = versionString31[i];
        pversionString32[i] = versionString32[i];
        pversionString33[i] = versionString33[i];
        pversionString34[i] = versionString34[i];
        pversionString35[i] = versionString35[i];
        pversionString36[i] = versionString36[i];
        pversionString37[i] = versionString37[i];
        pversionString38[i] = versionString38[i];
        pversionString39[i] = versionString39[i];
        pversionString40[i] = versionString40[i];
    }
    //sets which version string to use based on version
    if(version == V_SEVEN)
        return pversionString7;

    if(version == V_EIGHT)
        return pversionString8;

    if(version == V_NINE)
        return  pversionString9;

    if(version == V_TEN)
        return pversionString10;

    if(version == V_ELEVEN)
        return  pversionString11;

    if(version == V_TWELVE)
        return  pversionString12;

    if(version == V_THIRTEEN)
        return  pversionString13;

    if(version == V_FOURTEEN)
        return  pversionString14;

    if(version == V_FIFTEEN)
        return  pversionString15;

    if(version == V_SIXTEEN)
        return  pversionString16;

    if(version == V_SEVENTEEN)
        return pversionString17;

    if(version == V_EIGHTEEN)
        return pversionString18;

    if(version == V_NINETEEN)
        return pversionString19;

    if(version == V_TWENTY)
        return pversionString20;

    if(version == V_TWENTY_ONE)
        return pversionString21;

    if(version == V_TWENTY_TWO)
        return pversionString22;

    if(version == V_TWENTY_THREE)
        return pversionString23;

    if(version == V_TWENTY_FOUR)
        return pversionString24;

    if(version == V_TWENTY_FIVE)
        return pversionString25;

    if(version == V_TWENTY_SIX)
        return pversionString26;

    if(version == V_TWENTY_SEVEN)
        return pversionString27;

    if(version == V_TWENTY_EIGHT)
        return pversionString28;

    if(version == V_TWENTY_NINE)
        return pversionString29;

    if(version == V_THIRTY)
        return pversionString30;

    if(version == V_THIRTY_ONE)
        return pversionString31;

    if(version == V_THIRTY_TWO)
        return pversionString32;

    if(version == V_THIRTY_THREE)
        return pversionString33;

    if(version == V_THIRTY_FOUR)
        return pversionString34;

    if(version == V_THIRTY_FIVE)
        return pversionString35;

    if(version == V_THIRTY_SIX)
        return pversionString36;

    if(version == V_THIRTY_SEVEN)
        return pversionString37;

    if(version == V_THIRTY_EIGHT)
        return pversionString38;

    if(version == V_THIRTY_NINE)
        return pversionString39;

    if(version == V_FORTY)
        return pversionString40;


    return default_array;
}
//This method prints out the modular matrix: it was used for testing the matrix
void ModuleMatrix::print()
{
    std::cout << std::endl;

    for(int i = 0; i <  this->getWidth(); i++){
        std::cout << "|";
        for(int j =0; j <this->getHeight(); j++){
            if(this->getElement(i,j)){
                std::cout << "@";
            }
            else{
                std::cout<< " ";
            }
            std::cout<<"|";
        }
        cout << std::endl;
    }
    cout << std::endl;
}
//Testing print method
void ModuleMatrix::printBoolArray(bool** array)
{
    std::cout << std::endl;

    for(int i = 0; i <  this->getWidth(); i++){
        std::cout << "|";
        for(int j =0; j <this->getHeight(); j++){
            if(array[i][j]){
                std::cout << "@";
            }
            else{
                std::cout<< " ";
            }
            std::cout<<"|";
        }
        cout << std::endl;
    }
    cout << std::endl;
}
