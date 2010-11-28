/*
 * $RCSfile: InterCliRedeTeste.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_CLI_REDE_TESTE_H
#define INTER_CLI_REDE_TESTE_H


#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/InterfaceRedeTeste.h"
using namespace biblia::io::rede::interfaces;




namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				namespace interfacesCliente{

					class InterCliRedeTeste: public InterfaceCliente,
											 public InterfaceRedeTeste{

						private:

							char pBuffer [2000];


						public:

							InterCliRedeTeste::InterCliRedeTeste(ComunicadorRede* redeCliente);
							virtual InterCliRedeTeste::~InterCliRedeTeste();

							bool InterCliRedeTeste::setBufferRede (char* novoBuffer);
							char* InterCliRedeTeste::getBufferRede ();
					};
				}
			}
		}
	}
}

#endif