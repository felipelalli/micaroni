/*
 * $RCSfile: CRC16Smiley.h,v $
 * $Date: 2003/10/22 13:55:05 $
 * $Revision: 1.1 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef CRC16Smiley_H
#define CRC16Smiley_H

#ifndef BYTE
#define BYTE unsigned char
#endif

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace smiley{

				class CRC16Smiley:public Objeto {

					private:
						static int crctab[];

						BYTE pHigh;
						BYTE pLow;
						void CRC16Smiley::pUpdateCRC16(BYTE num);

					public:
						void CRC16Smiley::getCRC16(int len, BYTE* buf);
						BYTE CRC16Smiley::getHigh();
						BYTE CRC16Smiley::getLow();
				};
			}
		}
	}
}

#endif
