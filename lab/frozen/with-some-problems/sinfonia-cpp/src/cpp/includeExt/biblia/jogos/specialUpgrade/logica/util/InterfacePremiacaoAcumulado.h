/*
 * $RCSfile: InterfacePremiacaoAcumulado.h,v $
 * $Date: 2005/01/19 17:22:23 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTERFACE_PREMIACAO_ACUMULADO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTERFACE_PREMIACAO_ACUMULADO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class InterfacePremiacaoAcumulado: public InterfaceRede{

						public:

							InterfacePremiacaoAcumulado::InterfacePremiacaoAcumulado();
							virtual InterfacePremiacaoAcumulado::~InterfacePremiacaoAcumulado();

							enum Protocolo{
								REDE_PREMIOU_ACUMULADO = 0x01,
							};
					};
				}
			}
		}
	}
}

#endif