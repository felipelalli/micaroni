/*
 * $RCSfile: InterfaceDEstatistica.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTERFACE_DESTATISTICA_H
#define INTERFACE_DESTATISTICA_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace dados{

				namespace util{

					class InterfaceDEstatistica: public InterfaceRede{

						public:

							InterfaceDEstatistica::InterfaceDEstatistica();
							virtual InterfaceDEstatistica::~InterfaceDEstatistica();

							enum Protocolo{
								REDE_ENVIAR_DADO   = 0x01,
								REDE_RECEBER_DADO  = 0x02,
								REDE_ABRE_ARQUIVO  = 0x03,
								REDE_APAGA_GERAL   = 0x04,
								REDE_APAGA_PARCIAL = 0x05,
								REDE_ZERAR_TUDO    = 0x06
							};
					};
				}
			}
		}
	}
}

#endif