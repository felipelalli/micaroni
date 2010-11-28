/*
 * $RCSfile: TestadorLogicaAcumulado.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_LOGICA_ACUMULADO_H
#define TESTADOR_LOGICA_ACUMULADO_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/io/rede/RedeServidor.h"
#include "biblia/io/rede/MaquinaNaRede.h"
#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServGerenciadorRede.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/specialUpgrade/logica/LogicaAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/jogos/specialUpgrade/logica/util/InterCliPremiacaoAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterServPremiacaoAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterServLogicaAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados;


namespace biblia {
  namespace testador {

	class TestadorLogicaAcumulado: public TestadorComSaidaEmTexto {

		private:

			ChaveSeguranca* pChaveSeguranca;

			DConfiguracao* pDConfiguracao;

			InterCliPremiacaoAcumulado*  pInterCliPremiacaoAcumulado;

			InterServPremiacaoAcumulado* pInterServPremiacaoAcumulado;
			InterServLogicaAcumulado*    pInterServLogicaAcumulado;

			ArqGerenciadorRedeWizard* pArqGerenciadorRedeWizard;
			GerenciadorRedeWizard* pGerenciadorRedeWizard;
			RedeServidor* pRedeServidor;
			GerenciadorRede* pGerenciadorRede;

			LogicaAcumulado* pLogicaAcumulado;

		public:
			TestadorLogicaAcumulado::TestadorLogicaAcumulado(FluxoDeTexto&);

			virtual TestadorLogicaAcumulado::~TestadorLogicaAcumulado();

			// Executavel
			virtual Executavel& TestadorLogicaAcumulado::executa();
	};
  }
}

#endif
