#ifndef __INTERLEAVER_H__
#define __INTERLEAVER_H__
#include <vector>
#include "ECC_Table.h"


using namespace std;
using namespace QR;

class Interleaver
{
	public:
		vector<unsigned char> interleave(vector<unsigned char>& data_words, vector<unsigned char>& code_words, QR::ECC_LEVEL lev, QR::VERSION ver);

		vector<unsigned char> interleaveDataWords(vector<unsigned char>& data_words);

		vector<unsigned char> interleaveECCWords(vector<unsigned char>& ecc_words);

		Interleaver();
		~Interleaver();

	private:
		ECC_Table eccTable;

		int numBlocksDataWords_grpONE;
		int numBlocksDataWords_grpTWO;

		int dataWordsPerBlock_grpONE;
		int dataWordsPerBlock_grpTWO;

		int numBlocksECCWords_grpONE;
		int numBlocksECCWords_grpTWO;

		int eccWordsPerBlock_grpONE;
		int eccWordsPerBlock_grpTWO;

};
#endif
