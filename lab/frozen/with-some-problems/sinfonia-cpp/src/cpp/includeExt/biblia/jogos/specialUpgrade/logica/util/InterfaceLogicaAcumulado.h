/*
 * $RCSfile: InterfaceLogicaAcumulado.h,v $
 * $Date: 2005/01/19 17:22:23 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTERFACE_LOGICA_ACUMULADO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTERFACE_LOGICA_ACUMULADO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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