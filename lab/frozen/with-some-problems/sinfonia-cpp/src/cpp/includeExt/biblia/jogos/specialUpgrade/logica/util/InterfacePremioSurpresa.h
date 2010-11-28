/*
 * $RCSfile: InterfacePremioSurpresa.h,v $
 * $Date: 2005/01/20 17:48:04 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTERFACE_PREMIO_SURPRESA_H
#define AGES_SPECIAL_UPGRADE_SBS_INTERFACE_PREMIO_SURPRESA_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class InterfacePremioSurpresa: public InterfaceRede{

						public:

							InterfacePremioSurpresa::InterfacePremioSurpresa();
							virtual InterfacePremioSurpresa::~InterfacePremioSurpresa();

							enum Protocolo{								
								REDE_ATUALIZA_INFORMACOES    = 0x01,
								REDE_GANHOU_PREMIO           = 0x02								
							};
					};
				}
			}
		}
	}
}

#endif