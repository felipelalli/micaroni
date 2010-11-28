/*
 * $RCSfile: MaquinaNaRede.h,v $
 * $Date: 2005/01/20 21:28:43 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef MAQUINA_NA_REDE_SW
#define MAQUINA_NA_REDE_SW

#include <string>

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/rede/RedeCliente.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesCliente/InterCliGerenciadorRede.h"
using namespace biblia::io::rede::interfaces::interfacesCliente;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

namespace biblia{

	namespace io{

		namespace rede{

			class MaquinaNaRede: public Objeto{

				private:
					InterCliGerenciadorRede* pInfoRede;
					RedeCliente* pRedeCliente;
					int pHub;
					char pIp [100];

				public:
					MaquinaNaRede::MaquinaNaRede (
											UniversoDeTempo& universo,
											char* ip,
											int porta,
											int hub,
											ChaveSeguranca* chave);

					virtual MaquinaNaRede::~MaquinaNaRede();

					int MaquinaNaRede::getHub();
					char* MaquinaNaRede::getIP();
					RedeCliente* MaquinaNaRede::getRede();
					InterCliGerenciadorRede* MaquinaNaRede::getInfoRede();

					bool MaquinaNaRede::terminou();
					void MaquinaNaRede::terminar();
			};
		}
	}
}

#endif