/*
 * $RCSfile: InterfaceDConfiguracao.h,v $
 * $Date: 2005/01/19 17:22:00 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTERFACE_DCONFIGURACAO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTERFACE_DCONFIGURACAO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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