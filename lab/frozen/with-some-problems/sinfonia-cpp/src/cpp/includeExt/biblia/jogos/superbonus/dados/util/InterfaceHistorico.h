/*
 * $RCSfile: InterfaceHistorico.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTERFACE_HISTORICO_H
#define INTERFACE_HISTORICO_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace superbonus{

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