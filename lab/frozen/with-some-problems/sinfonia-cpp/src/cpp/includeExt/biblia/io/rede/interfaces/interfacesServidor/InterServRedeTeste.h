/*
 * $RCSfile: InterServRedeTeste.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_REDE_TESTE_H
#define INTER_SERV_REDE_TESTE_H


#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/InterfaceRedeTeste.h"
using namespace biblia::io::rede::interfaces;




namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				namespace interfacesServidor{

					class InterServRedeTeste: public InterfaceServidor,
											  public InterfaceRedeTeste{

						private:

							char pBuffer [2000];


						public:

							InterServRedeTeste::InterServRedeTeste();
							virtual InterServRedeTeste::~InterServRedeTeste();

							bool InterServRedeTeste::processarRequisicao(char* buffer);

					};
				}
			}
		}
	}
}

#endif