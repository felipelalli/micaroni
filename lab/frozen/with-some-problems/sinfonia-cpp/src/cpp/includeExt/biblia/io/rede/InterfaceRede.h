/*
 * $RCSfile: InterfaceRede.h,v $
 * $Date: 2005/01/20 21:28:43 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef INTERFACE_REDE_SW
#define INTERFACE_REDE_SW

#include <string>
#include <stdio.h>

namespace biblia{

	namespace io{

		namespace rede{

			class InterfaceRede{

				private:
					char pByteProtocolo;
					char pNomeInterface [200];


				public:

					InterfaceRede::InterfaceRede(char* nomeInterface, char byteProtocolo);
					virtual InterfaceRede::~InterfaceRede();

					char  InterfaceRede::getProtocolo();
					char* InterfaceRede::getNomeInterface();
			};
		}
	}
}

#endif