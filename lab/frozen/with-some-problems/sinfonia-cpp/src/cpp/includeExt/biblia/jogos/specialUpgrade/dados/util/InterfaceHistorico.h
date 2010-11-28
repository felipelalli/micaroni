/*
 * $RCSfile: InterfaceHistorico.h,v $
 * $Date: 2005/01/19 17:22:01 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTERFACE_HISTORICO_H
#define AGES_SPECIAL_UPGRADE_SBS_INTERFACE_HISTORICO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{

				namespace util{

					class InterfaceHistorico: public InterfaceRede{

						public:

							InterfaceHistorico::InterfaceHistorico();
							virtual InterfaceHistorico::~InterfaceHistorico();

							enum Protocolo{
								REDE_QTS_DADOS_HISTORICO = 0x01,
								REDE_TRAZER_DADO         = 0x02,
								REDE_ADICIONAR_EVENTO    = 0x03
							};

							enum Historicos{
								HISTORICO_EVENTOS    = 0x01,
								HISTORICO_PAGAMENTOS = 0x02,
								HISTORICO_NOTAS      = 0x03,
								HISTORICO_ACUMULADOS = 0x04,
								HISTORICO_JOGADAS    = 0x05
							};
					};
				}
			}
		}
	}
}

#endif