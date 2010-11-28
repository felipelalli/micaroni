/*
 * $RCSfile: InterCliGerenciadorRede.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTER_CLI_GERENCIADOR_REDE_H
#define INTER_CLI_GERENCIADOR_REDE_H

#include <stdio.h>

#include "biblia/io/rede/interfaces/InterfaceGerenciadorRede.h"
using namespace biblia::io::rede::interfaces;

#include "biblia/io/rede/ComunicadorRede.h"
#include "biblia/io/rede/InterfaceCliente.h"
using namespace biblia::io::rede;

namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				namespace interfacesCliente{
					class InterCliGerenciadorRede:  public InterfaceCliente,
													public InterfaceGerenciadorRede{

						public:

							InterCliGerenciadorRede::InterCliGerenciadorRede(ComunicadorRede* redeCliente);
							virtual InterCliGerenciadorRede::~InterCliGerenciadorRede();

							int  InterCliGerenciadorRede::getCodigo();
							bool InterCliGerenciadorRede::setCodigo(int codigo);

							int  InterCliGerenciadorRede::getSequencia();
							bool InterCliGerenciadorRede::setSequencia(int sequencia);
							bool InterCliGerenciadorRede::addSequencia();

							bool InterCliGerenciadorRede::getAtivado();
							bool InterCliGerenciadorRede::setAtivado(bool estado);
					};
				}
			}
		}
	}
}

#endif