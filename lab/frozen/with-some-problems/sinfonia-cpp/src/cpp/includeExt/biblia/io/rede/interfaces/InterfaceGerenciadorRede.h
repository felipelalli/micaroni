/*
 * $RCSfile: InterfaceGerenciadorRede.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTERFACE_GERENCIADOR_REDE_SW_H
#define INTERFACE_GERENCIADOR_REDE_SW_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				class InterfaceGerenciadorRede: public InterfaceRede{

					public:

						InterfaceGerenciadorRede::InterfaceGerenciadorRede();
						virtual InterfaceGerenciadorRede::~InterfaceGerenciadorRede();

						enum Constantes{
							ATIVADO    = 0x01,
							DESATIVADO = 0x02
						};

						enum Protocolo{
							REDE_GET_CODIGO    = 0x01,
							REDE_SET_CODIGO    = 0x02,
							REDE_GET_SEQUENCIA = 0x03,
							REDE_SET_SEQUENCIA = 0x04,
							REDE_ADD_SEQUENCIA = 0x05,
							REDE_GET_ATIVADO   = 0X06,
							REDE_SET_ATIVADO   = 0x07
						};
				};
			}
		}
	}
}

#endif