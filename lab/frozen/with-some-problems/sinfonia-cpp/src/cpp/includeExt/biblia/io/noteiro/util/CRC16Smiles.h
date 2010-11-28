/*
 * $RCSfile: CRC16Smiles.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef CRC16Smiles_H
#define CRC16Smiles_H

#define BYTE unsigned char

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace util{

				class CRC16Smiles:public Objeto {

					private:
						static int crctab[];

						BYTE pHigh;
						BYTE pLow;
						void CRC16Smiles::pUpdateCRC16(BYTE num);

					public:
						void CRC16Smiles::getCRC16(int len, BYTE* buf);
						BYTE CRC16Smiles::getHigh();
						BYTE CRC16Smiles::getLow();
				};
			}
		}
	}
}

#endif
