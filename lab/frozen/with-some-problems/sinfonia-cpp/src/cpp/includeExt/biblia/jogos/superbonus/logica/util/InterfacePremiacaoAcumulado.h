/*
 * $RCSfile: InterfacePremiacaoAcumulado.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTERFACE_PREMIACAO_ACUMULADO_H
#define INTERFACE_PREMIACAO_ACUMULADO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace superbonus{

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