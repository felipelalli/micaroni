/*
 * $RCSfile: InterfaceRedeTeste.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTERFACE_REDE_TESTE_SW_H
#define INTERFACE_REDE_TESTE_SW_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				class InterfaceRedeTeste: public InterfaceRede{

					public:

						InterfaceRedeTeste::InterfaceRedeTeste();
						virtual InterfaceRedeTeste::~InterfaceRedeTeste();

						enum Protocolo{
							REDE_ENVIAR_BUFFER=0x01,
							REDE_RECEBER_BUFFER=0x02
						};
				};
			}
		}
	}
}

#endif