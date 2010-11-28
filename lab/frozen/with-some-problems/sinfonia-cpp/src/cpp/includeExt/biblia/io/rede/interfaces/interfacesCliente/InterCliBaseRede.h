/*
 * $RCSfile: InterCliBaseRede.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_CLI_BASE_REDE_H
#define INTER_CLI_BASE_REDE_H



#include "biblia/io/rede/interfaces/InterfaceBaseRede.h"
using namespace biblia::io::rede::interfaces;

#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				namespace interfacesCliente{

					class InterCliBaseRede:  public InterfaceCliente,
											 public InterfaceBaseRede{


						public:

							InterCliBaseRede::InterCliBaseRede(ComunicadorRede* redeCliente);
							virtual InterCliBaseRede::~InterCliBaseRede();

							bool InterCliBaseRede::fazerPooling();
							bool InterCliBaseRede::encerrar();
					};
				}
			}
		}
	}
}

#endif