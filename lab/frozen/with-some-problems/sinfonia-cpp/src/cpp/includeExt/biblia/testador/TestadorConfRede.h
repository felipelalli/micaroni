/*
 * $RCSfile: TestadorConfRede.h,v $
 * $Date: 2004/05/17 22:18:07 $
 * $Revision: 1.17 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef TESTADOR_CONF_REDE_H
#define TESTADOR_CONF_REDE_H

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

#include "biblia/jogos/superbonus/dados/util/InterServDEstatistica.h"
#include "biblia/jogos/superbonus/dados/util/InterServDConfiguracao.h"
#include "biblia/jogos/superbonus/dados/util/InterServHistorico.h"
#include "biblia/jogos/superbonus/dados/util/InterServDadosRede.h"
#include "biblia/jogos/superbonus/dados/util/DadosJogada.h"
using namespace biblia::jogos::superbonus::dados::util;

#include "biblia/jogos/superbonus/io/noteiro/Noteiro.h"
using namespace biblia::jogos::superbonus::io::noteiro;

#include "biblia/jogos/superbonus/dados/DadosConfiguracao.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/jogos/superbonus/dados/DHistorico.h"
#include "biblia/jogos/superbonus/dados/DadosEmRede.h"
#include "biblia/jogos/superbonus/dados/Dicionario.h"
#include "biblia/jogos/superbonus/dados/UltimasJogadas.h"
using namespace biblia::jogos::superbonus::dados;

#include "biblia/jogos/superbonus/logica/LogicaCredito.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/jogos/superbonus/util/NumeroUtil.h"
using namespace biblia::jogos::superbonus::util;

namespace biblia {
  namespace testador {

	class TestadorConfRede: public TestadorComSaidaEmTexto {

		private:

			Teclado* teclado;

			ChaveSeguranca* pChaveSeguranca;

			DadosConfiguracao* pConfiguracao;

			DConfiguracao* pConfLocal;
			DEstatistica* pEstatisticaLocal;
			DHistorico* pHistoricoLocal;
			UltimasJogadas* pUltimasJogadas;

			Noteiro* pNoteiro;

			Dicionario* pDicionario;

			InterServDEstatistica* pInterServDEstatistica;
			InterServDConfiguracao* pInterServDConfiguracao;
			InterServHistorico* pInterServHistorico;
			InterServDadosRede* pInterServDadosRede;

			ArqGerenciadorRedeWizard* pArqGerenciadorRedeWizard;
			GerenciadorRedeWizard* pGerenciadorRedeWizard;
			RedeServidor* pRedeServidor;
			GerenciadorRede* pGerenciadorRede;

			void TestadorConfRede::pEscolherMaquina();
			void TestadorConfRede::pMenuPrincipal();
			void TestadorConfRede::pFinanceiro(bool geral);
			void TestadorConfRede::pHistoricoEventos ();
			void TestadorConfRede::pHistoricoPagamentos ();
			void TestadorConfRede::pHistoricoAcumulado();
			void TestadorConfRede::pHistoricoJogadas();
			void TestadorConfRede::pEntradaDeNotas ();
			void TestadorConfRede::pConfiguracaoRede();

		public:
			TestadorConfRede::TestadorConfRede(FluxoDeTexto&);

			virtual TestadorConfRede::~TestadorConfRede();

			// Executavel
			virtual Executavel& TestadorConfRede::executa();
	};
  }
}

#endif
