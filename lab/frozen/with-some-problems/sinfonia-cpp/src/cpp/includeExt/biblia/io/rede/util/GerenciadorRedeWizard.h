/*
 * $RCSfile: GerenciadorRedeWizard.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef GERENCIADOR_REDE_WIZARD_H
#define GERENCIADOR_REDE_WIZARD_H


#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServGerenciadorRede.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

#include "biblia/io/rede/RedeServidor.h"
#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/UniversoDeTempo.h"
using namespace biblia::tempo;

namespace biblia {

	namespace io {

		namespace rede {

			namespace util{

				class GerenciadorRedeWizard{

					private:

						ArqGerenciadorRedeWizard* pArqRede;

						InterServGerenciadorRede* pInterServGerenciadorRede;

						RedeServidor* pRedeServidor;
						GerenciadorRede* pGerenciadorRede;

						char pArquivoBasico[100];
						ChaveSeguranca* pChaveSeguranca;

						UniversoDeTempo& pUniverso;

						void GerenciadorRedeWizard::pCarregarGerenciadorRede();
						void GerenciadorRedeWizard::pCarregarServidor();

					public:
						GerenciadorRedeWizard::GerenciadorRedeWizard(UniversoDeTempo& universo, ArqGerenciadorRedeWizard* arqRede,ChaveSeguranca* chave);

						virtual GerenciadorRedeWizard::~GerenciadorRedeWizard();

						void GerenciadorRedeWizard::reiniciarTudo();
						void GerenciadorRedeWizard::reiniciarGerenciadorRede();
						void GerenciadorRedeWizard::reiniciarServidor();

						RedeServidor* GerenciadorRedeWizard::getRedeServidor();
						GerenciadorRede * GerenciadorRedeWizard::getGerenciadorRede();

						InterServGerenciadorRede* GerenciadorRedeWizard::getInterServGerenciadorRede();

				};
			}
		}
	}
}


#endif
