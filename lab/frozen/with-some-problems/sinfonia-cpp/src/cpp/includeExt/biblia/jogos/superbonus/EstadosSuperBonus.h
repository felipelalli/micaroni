/*
 * $RCSfile: EstadosSuperBonus.h,v $
 * $Date: 2005/01/20 21:28:57 $
 * $Revision: 1.52 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_ESTADOSSUPERBONUS_H__054EE251_7B30_4FEF_A976_CB77144794AC__INCLUDED_)
#define AFX_ESTADOSSUPERBONUS_H__054EE251_7B30_4FEF_A976_CB77144794AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/superbonus/util/NumeroUtil.h"
#include "biblia/basico/Objeto.h"
#include "biblia/sorte/Sorteio.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/jogos/superbonus/estados/Estados.h"
#include "biblia/jogos/superbonus/logica/Logicas.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/jogos/superbonus/io/botoes/BotoesAllegro.h"
#include "biblia/jogos/superbonus/io/botoes/BotoesPlacaIO.h"
#include "biblia/jogos/superbonus/io/botoes/BotoesPlacaDelta.h"
#include "biblia/jogos/superbonus/io/botoes/BotoesPlacaLoddy.h"
#include "biblia/jogos/superbonus/io/botoes/LuzBotoes.h"
#include "biblia/jogos/superbonus/io/botoes/Piscador.h"
#include "biblia/jogos/superbonus/io/botoes/PiscadorPlacaIO.h"
#include "biblia/jogos/superbonus/io/botoes/PiscadorPlacaDelta.h"
#include "biblia/jogos/superbonus/io/botoes/PiscadorPlacaLoddy.h"
#include "biblia/jogos/superbonus/io/botoes/PiscadorVazio.h"
#include "biblia/jogos/superbonus/io/noteiro/Noteiro.h"
#include "biblia/armazenamento/eterno/Contador.h"
#include "biblia/io/contador/ContadorPlacaIO.h"
#include "biblia/io/contador/ContadorPlacaLoddy.h"
#include "biblia/io/contador/ContadorPlacaDelta.h"
#include "biblia/jogos/superbonus/estados/Configuracao.h"
#include "biblia/seguranca/ControleLicenca.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/jogos/superbonus/estados/Portas.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::jogos::superbonus::estados;
using namespace biblia::jogos::superbonus::logica;
using namespace biblia::jogos::superbonus::io::botoes;
using namespace biblia::jogos::superbonus::io::noteiro;
using namespace biblia::io::contador;
using namespace biblia::io::placaio;
using namespace biblia::tempo;
using namespace biblia::jogos::superbonus::util;
using namespace biblia::seguranca;
using namespace biblia::visual::imagem2d;
using namespace biblia::io::disco;
using namespace biblia::armazenamento::eterno;



namespace biblia {
  namespace jogos {
    namespace superbonus {

		class EstadosSuperBonus
				: public Executavel,
				  public Objeto
		{
			private:
				static double EstadosSuperBonus
						::FATOR_VELOCIDADE_TURBO;

				static double EstadosSuperBonus
						::VELOCIDADE_BOLA_ARMADA;

				Portas* pPortas;
				Sorteio sorte;

				bool EstadosSuperBonus::pBotaoSuperTurboPressionado;
				Estados EstadosSuperBonus::pEstados;
				Logicas EstadosSuperBonus::pLogicas;
				Cronometro* EstadosSuperBonus::pCronometroBolas;
				Cronometro* EstadosSuperBonus::pCronometroMensagens;
				Cronometro* EstadosSuperBonus::pCronometroDemonstracao;
				Cronometro* EstadosSuperBonus::pCronometroTempoBolaMaximo;

				LuzBotoes* EstadosSuperBonus::pLuzBotoes;
				Piscador* EstadosSuperBonus::pPiscador;
				biblia::jogos::superbonus::io::botoes::Botoes*
						EstadosSuperBonus::pBotoes;

				biblia::jogos::superbonus::io::botoes::Botao*
						EstadosSuperBonus::pBotaoPressionado;

				Contador* EstadosSuperBonus::pContador;
				Noteiro* EstadosSuperBonus::pNoteiro;


                PlacaIO* pPlacaIO;
				PlacaLoddy* pPlacaLoddy;
				PlacaDelta* pPlacaDelta;

				static unsigned long pKey[4];
				//Configuracao* pConfiguracao;

				ChaveSeguranca* pChave;
				ControleLicenca* pControleLicenca;

                //créditos antes da contabilizacao
                int EstadosSuperBonus::pValorCreditosIniciais;

                // Felipe, fixme:
				int EstadosSuperBonus::pUltimaBola1, pUltimaBola2;

				void EstadosSuperBonus::inicializaEstados();
				void EstadosSuperBonus::verificaEntradaBotoes();
				void EstadosSuperBonus::verificaEntradaNoteiro();
				void EstadosSuperBonus::verificaCancelamentoDoTurbo();
				void EstadosSuperBonus::verificaFilada();
				void EstadosSuperBonus::verificaLancamentoDeNovaBola();
				void EstadosSuperBonus::verificaCompraDeBolaExtra();
				void EstadosSuperBonus::contabilizaPremios();
				void EstadosSuperBonus::atualizaMensagem();
				void EstadosSuperBonus::iniciaJogada();
				void EstadosSuperBonus::verificaComandos();
				void EstadosSuperBonus::telaDeCobranca();

				// por Felipe:
				EstadosSuperBonus& EstadosSuperBonus
						::geraAcoesParaTelaDeConfiguracao();

				void EstadosSuperBonus::determinaEstadoDemonstracao();
				void EstadosSuperBonus::finalizaDemonstracao();
				void EstadosSuperBonus::finalizaDemonstracaoDeFato();
				Intervalo EstadosSuperBonus::intervaloDemonstracao();

				void EstadosSuperBonus::mensagemTemporaria(std::string);
				bool EstadosSuperBonus::deveJogar();

			public:
				EstadosSuperBonus::EstadosSuperBonus(UniversoDeTempo& universoDeTempo,PlacaLoddy* placaLoddy, PlacaDelta* placaDelta);
				virtual EstadosSuperBonus::~EstadosSuperBonus();

				virtual Estados& EstadosSuperBonus::estados();
				virtual Logicas& EstadosSuperBonus::logicas();
                virtual Noteiro& EstadosSuperBonus::noteiro();
				virtual Contador& EstadosSuperBonus::contador();
				virtual ControleLicenca& EstadosSuperBonus::controleLicenca();
				virtual Piscador& EstadosSuperBonus::piscador();

				virtual const Estados& EstadosSuperBonus::estados() const;
				virtual const Logicas& EstadosSuperBonus::logicas() const;
                virtual const Noteiro& EstadosSuperBonus::noteiro() const;
				virtual const Contador& EstadosSuperBonus::contador() const;

				virtual Botoes& EstadosSuperBonus::botoes() const;
				virtual ChaveSeguranca* EstadosSuperBonus::chave() const;

				virtual EstadosSuperBonus& EstadosSuperBonus::defineCronometro(const UniversoDeTempo&);

				virtual bool EstadosSuperBonus::ligouConfiguracao() const;

				// Executavel:
				virtual Executavel& EstadosSuperBonus::executa();
		};
	}
  }
}

#endif // !defined(AFX_ESTADOSSUPERBONUS_H__054EE251_7B30_4FEF_A976_CB77144794AC__INCLUDED_)

