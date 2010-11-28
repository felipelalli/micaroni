/*
 * $RCSfile: InterfaceDadosRede.h,v $
 * $Date: 2005/01/19 17:22:00 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_INTERFACE_DADOS_REDE_H
#define AGES_SPECIAL_UPGRADE_SBS_INTERFACE_DADOS_REDE_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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