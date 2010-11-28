/*
 * $RCSfile: CRC16JCM.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef CRC16JCM_H_SW
#define CRC16JCM_H_SW

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace util{

				class CRC16JCM: public Objeto {

					private:
						static unsigned short crctab[];

					public:
						static unsigned short CRC16JCM::getCRC16 (unsigned short crc, char *buffer, int length);
				};
			}
		}
	}
}

#endif
