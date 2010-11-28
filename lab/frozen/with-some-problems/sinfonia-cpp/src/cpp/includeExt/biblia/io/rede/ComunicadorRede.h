/*
 * $RCSfile: ComunicadorRede.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef COMUNICADOR_REDE_H_SW
#define COMUNICADOR_REDE_H_SW


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{
	namespace io{
		namespace rede{

			class ComunicadorRede {
				public:
					virtual ComunicadorRede::~ComunicadorRede(){};
					virtual bool ComunicadorRede::conectado()=0;
					virtual int  ComunicadorRede::makeComm(char* buffer,int tamanho)=0;
			};
		}
	}
}

#endif
