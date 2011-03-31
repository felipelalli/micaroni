/*
 * $RCSfile: InterfaceLogicaAcumulado.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_INTERFACE_LOGICA_ACUMULADO_H
#define SBS_INTERFACE_LOGICA_ACUMULADO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace special{

			namespace logica{

				namespace util{

					class InterfaceLogicaAcumulado: public InterfaceRede{

						public:

							InterfaceLogicaAcumulado::InterfaceLogicaAcumulado();
							virtual InterfaceLogicaAcumulado::~InterfaceLogicaAcumulado();

							enum Protocolo{
								REDE_GET_VALOR         = 0x01,
								REDE_SET_VALOR         = 0x02,
								REDE_ADD_VALOR         = 0x03,
								REDE_PREMIAR_ACUMULADO = 0x04
							};
					};
				}
			}
		}
	}
}

#endif