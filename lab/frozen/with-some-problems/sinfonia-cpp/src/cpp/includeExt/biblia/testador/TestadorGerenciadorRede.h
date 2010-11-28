/*
 * $RCSfile: TestadorGerenciadorRede.h,v $
 * $Date: 2004/05/17 22:18:08 $
 * $Revision: 1.9 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef TESTADOR_GERENCIADOR_REDE_H
#define TESTADOR_GERENCIADOR_REDE_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/io/rede/RedeServidor.h"
#include "biblia/io/rede/MaquinaNaRede.h"
#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServGerenciadorRede.h"
#include "biblia/io/rede/interfaces/interfacesServidor/InterServRedeTeste.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

#include "biblia/io/rede/interfaces/interfacesCliente/InterCliRedeTeste.h"
using namespace biblia::io::rede::interfaces::interfacesCliente;

#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia {
  namespace testador {

	class TestadorGerenciadorRede: public TestadorComSaidaEmTexto {

		private:

			ChaveSeguranca* pChaveSeguranca;

			InterServGerenciadorRede* pInterServGerenciadorRede;
			InterServRedeTeste* pInterServRedeTeste;

			InterCliRedeTeste* pInterCliRedeTeste;

			ArqGerenciadorRedeWizard* pArqGerenciadorRedeWizard;
			GerenciadorRedeWizard* pGerenciadorRedeWizard;
			RedeServidor* pRedeServidor;
			GerenciadorRede* pGerenciadorRede;


		public:
			TestadorGerenciadorRede::TestadorGerenciadorRede(FluxoDeTexto&);

			virtual TestadorGerenciadorRede::~TestadorGerenciadorRede();

			// Executavel
			virtual Executavel& TestadorGerenciadorRede::executa();
	};
  }
}

#endif
