// echo, echo, echo...
#ifndef __REM_TABLE_H__
#define __REM_TABLE_H__

#include "ECC_Table.h"

using namespace std;
using namespace QR;

class Rem_Table
{
	public:
		Rem_Table();
		~Rem_Table();

		int getRemainderBits(QR::VERSION ver) { return remainder[ver]; }

	private:
		int remainder[QR::UNDEFINED_VERSION];

};
#endif
