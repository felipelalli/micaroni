/*
 * $RCSfile: InterfacePremiacaoAcumulado.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_INTERFACE_PREMIACAO_ACUMULADO_H
#define SBS_INTERFACE_PREMIACAO_ACUMULADO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace special{

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