#include "Interleaver.h"
#include <iostream>
#include <cstdlib>

Interleaver::Interleaver()
{}

Interleaver::~Interleaver()
{}

vector<unsigned char> Interleaver::interleave(vector<unsigned char>& data_words, vector<unsigned char>& code_words, QR::ECC_LEVEL lev, QR::VERSION ver)
{
	// set private data fields based on version and level entered as parameters
	numBlocksDataWords_grpONE = eccTable.getNumBlocksGrpONE(ver,lev);
	numBlocksDataWords_grpTWO = eccTable.getNumBlocksGrpTWO(ver,lev);

	dataWordsPerBlock_grpONE = eccTable.getNumWordsInBlockGrpONE(ver,lev);
	dataWordsPerBlock_grpTWO = eccTable.getNumWordsInBlockGrpTWO(ver,lev);

	numBlocksECCWords_grpONE = numBlocksDataWords_grpONE;
	numBlocksECCWords_grpTWO = numBlocksDataWords_grpTWO;

	eccWordsPerBlock_grpONE = eccTable.getNumEccWords(data_words.size(),lev);
	eccWordsPerBlock_grpTWO = eccTable.getNumEccWords(data_words.size(),lev);

/*	numBlocksDataWords_grpONE = 2;
	numBlocksDataWords_grpTWO = 2;
	dataWordsPerBlock_grpONE = 2;
	dataWordsPerBlock_grpTWO = 2;

	numBlocksECCWords_grpONE = numBlocksDataWords_grpONE;
        numBlocksECCWords_grpTWO = numBlocksDataWords_grpTWO;
	
	eccWordsPerBlock_grpONE = 3;
	eccWordsPerBlock_grpTWO = 3;
*/

	// PRINTS
/*	cout << "data words: " << data_words.size() << endl;
	cout << "group 1: " << numBlocksDataWords_grpONE << endl;
	cout << "    words per block: " << dataWordsPerBlock_grpONE << endl;
	cout << "group 2: " << numBlocksDataWords_grpTWO << endl;
	cout << "    words per block: " << dataWordsPerBlock_grpTWO << endl;

	cout << "ecc words: " << code_words.size() << endl;
        cout << "group 1: " << numBlocksECCWords_grpONE << endl;
        cout << "    words per block: " << eccWordsPerBlock_grpONE << endl;
        cout << "group 2: " << numBlocksECCWords_grpTWO << endl;
        cout << "    words per block: " << eccWordsPerBlock_grpTWO << endl;
*/

	// interleave final message
	vector<unsigned char> message;

	vector<unsigned char> dataWords = interleaveDataWords(data_words);
	vector<unsigned char> eccWords = interleaveECCWords(code_words);

	// add interleaved data words to final message
	for(unsigned int i=0; i<dataWords.size(); i++)
	{
		message.push_back(dataWords.at(i));
	}

	// add interleaved ecc words to final message
	for(unsigned int j=0; j<eccWords.size(); j++)
	{
		message.push_back(eccWords.at(j));
	}

	return message;
}

vector<unsigned char> Interleaver::interleaveDataWords(vector<unsigned char>& dataWordList)
{

	// parameter check
	int size = (numBlocksDataWords_grpONE*dataWordsPerBlock_grpONE) + (numBlocksDataWords_grpTWO*dataWordsPerBlock_grpTWO);

	//cout << "size: " << size << endl;
	//cout << "vector size: " << dataWordList.size() << endl;
	if(size != (int)dataWordList.size())
	{
		cerr << "Error: Incorrect number of data codewords." << endl;
		exit(1);
	}

	vector<vector<unsigned char> > dataWords;

	int position = 0;

	// trasfer data words into 2d vector in blocks for group 1
	for(int i=0; i < numBlocksDataWords_grpONE; i++)
	{
		vector<unsigned char> block;
		dataWords.push_back(block);

		// goes through the blocks for group 1
		while(position < (i+1)*dataWordsPerBlock_grpONE )
		{
			// copies over the values in blocks
			dataWords.at(i).push_back(dataWordList.at(position)); // copies front element of data_words to the end of current block
			position++;
		}
	}

	// trasfer data words into 2d vector in blocks for group 2
	for(int j=0; j < numBlocksDataWords_grpTWO; j++)
	{
		vector<unsigned char> block;
		dataWords.push_back(block);
		// goes through the blocks for group 1
		while(position < (j+1)*dataWordsPerBlock_grpTWO + numBlocksDataWords_grpONE*dataWordsPerBlock_grpONE )
		{
			// copies over the values in blocks
			dataWords.at(j+numBlocksDataWords_grpONE).push_back(dataWordList.at(position)); // copies front element of data_words to the end of current block
			position++;
		}
	}

	// create vector for interleaving
	vector<unsigned char> interleavedDataWords;

	// determine the longest block
	int blockLength = 0;
	if(dataWordsPerBlock_grpTWO > dataWordsPerBlock_grpONE)
	{
		blockLength = dataWordsPerBlock_grpTWO;
	}
	else
	{
		blockLength = dataWordsPerBlock_grpONE;
	}

	// interleave the blocks of data words
	for(int k=0; k<blockLength; k++) // iterates through the position within the blocks (columns)
	{
		for(unsigned int l=0; l<dataWords.size(); l++) // iterates through the different blocks (rows)
		{
			if(k < (int)dataWords.at(l).size()) // checks that the position does not exceed the number of words for that block (prevents out of bounds due to different length blocks for different groups
			{
				interleavedDataWords.push_back(dataWords.at(l).at(k)); 
			}
			else
			{
				continue;
			}
		}
	}

	return interleavedDataWords;
}

vector<unsigned char> Interleaver::interleaveECCWords(vector<unsigned char>& eccWordList)
{

	// parameter check
	int size = (numBlocksECCWords_grpONE*eccWordsPerBlock_grpONE) + (numBlocksECCWords_grpTWO*eccWordsPerBlock_grpTWO);

	if(size != (int)eccWordList.size())
	{
		cerr << "Error: Incorrect number of data codewords." << endl;
		exit(1);
	}

	vector<vector<unsigned char> > eccWords;

	int position = 0;

	// trasfer data words into 2d vector in blocks for group 1
	for(int i=0; i < numBlocksECCWords_grpONE; i++)
	{
		vector<unsigned char> block;
		eccWords.push_back(block);

		// goes through the blocks for group 1
		while(position < (i+1)*eccWordsPerBlock_grpONE )
		{
			// copies over the values in blocks
			eccWords.at(i).push_back(eccWordList.at(position)); // copies front element of data_words to the end of current block
			position++;
		}
	}

	// trasfer data words into 2d vector in blocks for group 2
	for(int j=0; j < numBlocksECCWords_grpTWO; j++)
	{
		vector<unsigned char> block;
		eccWords.push_back(block);
		// goes through the blocks for group 1
		while(position < (j+1)*eccWordsPerBlock_grpTWO + numBlocksECCWords_grpONE*eccWordsPerBlock_grpONE )
		{
			// copies over the values in blocks
			eccWords.at(j+numBlocksECCWords_grpONE).push_back(eccWordList.at(position)); // copies front element of data_words to the end of current block
			position++;
		}
	}

	vector<unsigned char> interleavedECCWords;

	int blockLength = 0;

	if(eccWordsPerBlock_grpTWO > eccWordsPerBlock_grpONE)
	{
		blockLength = eccWordsPerBlock_grpTWO;
	}
	else
	{
		blockLength = eccWordsPerBlock_grpONE;
	}

	for(int k=0; k<blockLength; k++)
	{
		for(unsigned int l=0; l<eccWords.size(); l++)
		{
			if(k < (int)eccWords.at(l).size())
			{
				interleavedECCWords.push_back(eccWords.at(l).at(k));
			}
			else
			{
				continue;
			}
		}
	}

	return interleavedECCWords;
}



