/*
 * $RCSfile: InterfaceDConfiguracao.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_INTERFACE_DCONFIGURACAO_H
#define SBS_INTERFACE_DCONFIGURACAO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace special{

			namespace dados{

				namespace util{

					class InterfaceDConfiguracao: public InterfaceRede{

						public:

							InterfaceDConfiguracao::InterfaceDConfiguracao();
							virtual InterfaceDConfiguracao::~InterfaceDConfiguracao();

							enum Protocolo{
								REDE_ENVIAR_DADO   = 0x01,
								REDE_RECEBER_DADO  = 0x02,
								REDE_ABRIR_ARQUIVO = 0x03
							};
					};
				}
			}
		}
	}
}

#endif