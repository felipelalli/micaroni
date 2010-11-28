/*
 * $RCSfile: EstadosSpecial.h,v $
 * $Date: 2005/01/19 17:21:51 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_AFX_EstadosSpecial_H__054EE251_7B30_4FEF_A976_CB77144794AC__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_AFX_EstadosSpecial_H__054EE251_7B30_4FEF_A976_CB77144794AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/sorte/Sorteio.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/armazenamento/eterno/Contador.h"
#include "biblia/io/contador/ContadorPlacaIO.h"
#include "biblia/io/contador/ContadorPlacaLoddy.h"
#include "biblia/io/contador/ContadorPlacaDelta.h"
#include "biblia/seguranca/ControleLicenca.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/dinamica/BasicoVisual.h"

#include "biblia/jogos/specialUpgrade/logica/ForcadorDePremios.h"
#include "biblia/jogos/specialUpgrade/logica/Logicas.h"
#include "biblia/jogos/specialUpgrade/estados/Estados.h"
#include "biblia/jogos/specialUpgrade/estados/Configuracao.h"
#include "biblia/jogos/specialUpgrade/estados/Portas.h"
#include "biblia/jogos/specialUpgrade/util/NumeroUtil.h"
#include "biblia/jogos/specialUpgrade/io/botoes/BotoesAllegro.h"
#include "biblia/jogos/specialUpgrade/io/botoes/BotoesPlacaIO.h"
#include "biblia/jogos/specialUpgrade/io/botoes/BotoesPlacaLoddy.h"
#include "biblia/jogos/specialUpgrade/io/botoes/BotoesPlacaDelta.h"
#include "biblia/jogos/specialUpgrade/io/botoes/LuzBotoes.h"
#include "biblia/jogos/specialUpgrade/io/botoes/Piscador.h"
#include "biblia/jogos/specialUpgrade/io/botoes/PiscadorPlacaIO.h"
#include "biblia/jogos/specialUpgrade/io/botoes/PiscadorPlacaLoddy.h"
#include "biblia/jogos/specialUpgrade/io/botoes/PiscadorPlacaDelta.h"
#include "biblia/jogos/specialUpgrade/io/botoes/PiscadorVazio.h"
#include "biblia/jogos/specialUpgrade/io/noteiro/Noteiro.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::jogos::specialUpgrade::estados;
using namespace biblia::jogos::specialUpgrade::logica;
using namespace biblia::jogos::specialUpgrade::io::botoes;
using namespace biblia::jogos::specialUpgrade::io::noteiro;
using namespace biblia::jogos::specialUpgrade::util;
using namespace biblia::io::contador;
using namespace biblia::io::placaio;
using namespace biblia::io::disco;
using namespace biblia::tempo;
using namespace biblia::seguranca;
using namespace biblia::visual::imagem2d;
using namespace biblia::armazenamento::eterno;

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;

#include "biblia/jogos/specialUpgrade/logica/util/EventosCartela.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {

		enum Skin {
			SPECIAL_UPGRADE,
			DOUBLE_UPGRADE
		};

		class EstadosSpecial
				:public Executavel,
				 public Objeto
		{
			private:
				Skin pSkin;
				BasicoVisual* pVisual;

				static double EstadosSpecial
						::FATOR_VELOCIDADE_TURBO;

				static double EstadosSpecial
						::VELOCIDADE_BOLA_ARMADA;

				Portas* pPortas;
				Sorteio sorte;

				bool EstadosSpecial::pBotaoSuperTurboPressionado;
				Estados EstadosSpecial::pEstados;
				Logicas EstadosSpecial::pLogicas;
				Cronometro* EstadosSpecial::pCronometroBolas;
				Cronometro* EstadosSpecial::pCronometroMensagens;
				Cronometro* EstadosSpecial::pCronometroDemonstracao;
				Cronometro* EstadosSpecial::pCronometroTempoBolaMaximo;
				Cronometro* EstadosSpecial::pCronometroInsiraCreditosAntesDoBoaSorte;

				LuzBotoes* EstadosSpecial::pLuzBotoes;
				Piscador* EstadosSpecial::pPiscador;
				biblia::jogos::specialUpgrade::io::botoes::Botoes*
						EstadosSpecial::pBotoes;

				biblia::jogos::specialUpgrade::io::botoes::Botao*
						EstadosSpecial::pBotaoPressionado;

				Contador* EstadosSpecial::pContador;
				Noteiro* EstadosSpecial::pNoteiro;

                PlacaIO* pPlacaIO;
				PlacaLoddy* pPlacaLoddy;
				PlacaDelta* pPlacaDelta;

				static unsigned long pKey[4];
				//Configuracao* pConfiguracao;

				ChaveSeguranca* pChave;
				ChaveSeguranca* pChaveUsuario;
				ControleLicenca* pControleLicenca;

                //créditos antes da contabilizacao
                int EstadosSpecial::pValorCreditosIniciais;

                // Felipe, fixme:
				int EstadosSpecial::pUltimaBola1, pUltimaBola2;

				void EstadosSpecial::inicializaEstados();
				void EstadosSpecial::verificaEntradaBotoes();
				void EstadosSpecial::verificaEntradaNoteiro();
				void EstadosSpecial::verificaCancelamentoDoTurbo();
				void EstadosSpecial::verificaFilada();
				void EstadosSpecial::verificaLancamentoDeNovaBola();
				void EstadosSpecial::verificaCompraDeBolaExtra();
				void EstadosSpecial::contabilizaPremios();
				void EstadosSpecial::atualizaMensagem();
				void EstadosSpecial::iniciaJogada();
				void EstadosSpecial::verificaComandos();
				void EstadosSpecial::telaDeCobranca();				

				// por Felipe:
				EstadosSpecial& EstadosSpecial
						::geraAcoesParaTelaDeConfiguracao();

				void EstadosSpecial::determinaEstadoDemonstracao();
				void EstadosSpecial::finalizaDemonstracao();
				void EstadosSpecial::finalizaDemonstracaoDeFato();
				Intervalo EstadosSpecial::intervaloDemonstracao();

				void EstadosSpecial::mensagemTemporaria(string);
				bool EstadosSpecial::deveJogar();
				EstadosSpecial& atualizaEstadosSimulador();

				ForcadorDePremios* pForcadorDePremios;

			public:
				EstadosSpecial::EstadosSpecial(
						UniversoDeTempo& universoDeTempo,
						PlacaLoddy* placaLoddy, PlacaDelta* placaDelta,
						BasicoVisual&, const Skin&);

				virtual EstadosSpecial::~EstadosSpecial();

				virtual Estados& EstadosSpecial::estados();
				virtual Portas&  EstadosSpecial::portas();
				virtual Logicas& EstadosSpecial::logicas();
                virtual Noteiro& EstadosSpecial::noteiro();
				virtual Contador& EstadosSpecial::contador();
				virtual ControleLicenca& EstadosSpecial::controleLicenca();
				virtual Piscador& EstadosSpecial::piscador();

				virtual const Estados& EstadosSpecial::estados() const;
				virtual const Logicas& EstadosSpecial::logicas() const;
                virtual const Noteiro& EstadosSpecial::noteiro() const;
				virtual const Contador& EstadosSpecial::contador() const;

				virtual Botoes& EstadosSpecial::botoes() const;
				virtual ChaveSeguranca* EstadosSpecial::chave() const;
				virtual ChaveSeguranca* EstadosSpecial::chaveUsuario() const;

				virtual EstadosSpecial& EstadosSpecial::defineCronometro(const UniversoDeTempo&);

				virtual bool EstadosSpecial::ligouConfiguracao() const;

				// Executavel:
				virtual Executavel& EstadosSpecial::executa();
		};
	}
  }
}

#endif // !defined(AFX_EstadosSpecial_H__054EE251_7B30_4FEF_A976_CB77144794AC__INCLUDED_)

