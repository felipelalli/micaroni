/*
 * $RCSfile: GerenciadorInterface.h,v $
 * $Date: 2004/06/16 00:31:25 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef GERENCIADOR_INTERFACE_SW_H
#define GERENCIADOR_INTERFACE_SW_H


#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/io/rede/InterfaceServidor.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServBaseRede.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

namespace biblia{

	namespace io{

		namespace rede{

			class GerenciadorInterface{

				private:
					biblia::armazenamento::volatil::Lista* pLstInterface;

					InterServBaseRede* pInterfaceBaseRede;

				public:
					GerenciadorInterface::GerenciadorInterface();
					virtual GerenciadorInterface::~GerenciadorInterface();

					void GerenciadorInterface::adicionarInterface(InterfaceServidor* interfaceRede);
					int  GerenciadorInterface::qtsInterfaces();
					InterfaceServidor* GerenciadorInterface::getInterface(int indice);
			};
		}
	}
}

#endif