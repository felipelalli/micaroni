/*
 * $RCSfile: InterfaceDEstatistica.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_INTERFACE_DESTATISTICA_H
#define SBS_INTERFACE_DESTATISTICA_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace special{

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