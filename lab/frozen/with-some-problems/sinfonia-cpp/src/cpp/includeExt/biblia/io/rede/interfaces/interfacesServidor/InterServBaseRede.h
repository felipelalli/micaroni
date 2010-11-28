/*
 * $RCSfile: InterServBaseRede.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_BASE_REDE_H
#define INTER_SERV_BASE_REDE_H


#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/InterfaceBaseRede.h"
using namespace biblia::io::rede::interfaces;




namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				namespace interfacesServidor{

					class InterServBaseRede:  public InterfaceServidor,
											  public InterfaceBaseRede{

						public:

							InterServBaseRede::InterServBaseRede();
							virtual InterServBaseRede::~InterServBaseRede();

							bool InterServBaseRede::processarRequisicao (char* buffer);
					};
				}
			}
		}
	}
}

#endif