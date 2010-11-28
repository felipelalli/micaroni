/*
 * $RCSfile: InterServGerenciadorRede.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_SERV_GERENCIADOR_REDE_H
#define INTER_SERV_GERENCIADOR_REDE_H

#include <stdlib.h>

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/InterfaceGerenciadorRede.h"
using namespace biblia::io::rede::interfaces;

#include "biblia/io/rede/util/ArqInfoGerenciadorRede.h"
using namespace biblia::io::rede::util;


namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				namespace interfacesServidor{

					class InterServGerenciadorRede: public InterfaceServidor,
													public InterfaceGerenciadorRede{

						private:
							bool pAtivo;
							ArqInfoGerenciadorRede* pArqDados;

						public:

							InterServGerenciadorRede::InterServGerenciadorRede();
							virtual InterServGerenciadorRede::~InterServGerenciadorRede();

							bool InterServGerenciadorRede::processarRequisicao(char* buffer);

							void InterServGerenciadorRede::desativarServidor ();
							bool InterServGerenciadorRede::servidorAtivo();

							void InterServGerenciadorRede::setCodSeq(int codigo, int sequencia);

							int InterServGerenciadorRede::getCodigo ();
							int InterServGerenciadorRede::getSequencia ();
					};
				}
			}
		}
	}
}

#endif