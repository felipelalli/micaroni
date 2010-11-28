/*
 * $RCSfile: InterfaceDadosRede.h,v $
 * $Date: 2004/05/17 21:56:41 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef SBS_INTERFACE_DADOS_REDE_H
#define SBS_INTERFACE_DADOS_REDE_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace special{

			namespace dados{

				namespace util{

					class InterfaceDadosRede: public InterfaceRede{

						public:

							InterfaceDadosRede::InterfaceDadosRede();
							virtual InterfaceDadosRede::~InterfaceDadosRede();

							enum Protocolo{
								REDE_LIMPAR              = 0x01,
								REDE_ADD_MAQUINA         = 0x02,
								REDE_REM_MAQUINA         = 0x03,
								REDE_CONCLUIR            = 0x04,
								REDE_QTS_MAQUINA_NA_REDE = 0x05,
								REDE_TRAZER_MAQUINA      = 0x06
							};
					};
				}
			}
		}
	}
}

#endif