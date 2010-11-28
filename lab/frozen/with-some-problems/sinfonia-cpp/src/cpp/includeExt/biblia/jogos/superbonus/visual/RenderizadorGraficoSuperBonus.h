/*
 * $RCSfile: RenderizadorGraficoSuperBonus.h,v $
 * $Date: 2005/01/20 21:29:01 $
 * $Revision: 1.48 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_RENDERIZADORGRAFICOSUPERBONUS_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_)
#define AFX_RENDERIZADORGRAFICOSUPERBONUS_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <deque>
#include "biblia/logica/Renderizador.h"
#include "biblia/sorte/Sorteio.h"
#include "biblia/tempo/UltraLong.h"
#include "biblia/tempo/Temporizador.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/fluxo/ExecutavelOtimizado.h"
#include "biblia/visual/animacao/Video.h"
#include "biblia/visual/dinamica/ResultadoGrafico.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/dinamica/ComponenteGrafico.h"
#include "biblia/visual/dinamica/DesenhistaDeResultadoGraficoNaTela.h"
#include "biblia/visual/dinamica/Camada.h"
#include "biblia/visual/fonte/RenderizadorDeFonteImagem.h"
#include "biblia/visual/cores/Transparente.h"
#include "biblia/visual/geometricos/Retangulo.h"
#include "biblia/jogos/superbonus/EstadosSuperBonus.h"
#include "biblia/jogos/superbonus/estados/VisorCreditos.h"
#include "biblia/jogos/superbonus/estados/Bonus.h"
#include "biblia/jogos/superbonus/logica/PosicaoNasCartelas.h"
#include "biblia/jogos/superbonus/visual/BolasAndando.h"
#include "biblia/jogos/superbonus/visual/FogosDeArtificio.h"
#include "biblia/jogos/superbonus/util/NumeroUtil.h"

using namespace std;
using namespace biblia::sorte;
using namespace biblia::logica;
using namespace biblia::tempo;
using namespace biblia::fluxo;
using namespace biblia::visual::dinamica;
using namespace biblia::visual::fonte;
using namespace biblia::visual::animacao;
using namespace biblia::visual::cores;
using namespace biblia::visual::geometricos;
using namespace biblia::jogos::superbonus;
using namespace biblia::jogos::superbonus::estados;
using namespace biblia::jogos::superbonus::logica;
using namespace biblia::jogos::superbonus::util;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace visual {

		/**
		 * Para que os créditos subam aos poucos.
		 */
		class IncrementadorDeVisualCredito
				:public ExecutavelOtimizado
		{
			private:
				VisorCreditos*
						IncrementadorDeVisualCredito::vc;

			public:
				IncrementadorDeVisualCredito
						::IncrementadorDeVisualCredito();

				virtual IncrementadorDeVisualCredito&
						IncrementadorDeVisualCredito
							::defineVisorCreditos(VisorCreditos&);

				virtual ExecutavelOtimizado&
						IncrementadorDeVisualCredito
							::executa(int quantasVezes);
		};

		/**
		 * Para que o fundo fique piscando.
		 */
		class PiscadorDeBonus
				:public ExecutavelOtimizado
		{
			private:
				Bonus* PiscadorDeBonus::b;

			public:
				PiscadorDeBonus
						::PiscadorDeBonus();

				virtual PiscadorDeBonus&
						PiscadorDeBonus
							::defineBonus(Bonus&);

				virtual ExecutavelOtimizado&
						PiscadorDeBonus
							::executa(int quantasVezes);
		};

		/**
		 * Para que o fogo do acumulado ande.
		 */
		class AcumuladoAndando
				:public ExecutavelOtimizado
		{
			private:
				int AcumuladoAndando::pX;

			public:
				AcumuladoAndando
						::AcumuladoAndando();

				virtual AcumuladoAndando&
						AcumuladoAndando::zera();

				virtual const int&
						AcumuladoAndando::x() const;

				virtual ExecutavelOtimizado&
						AcumuladoAndando
							::executa(int quantasVezes);
		};

		/**
		 * A partir das informações do jogo ele
		 * gera um resultado gráfico.
		 */
		class RenderizadorGraficoSuperBonus: public Renderizador {
			private:
      			BasicoVisual*
						RenderizadorGraficoSuperBonus::
							pVisual;

				EstadosSuperBonus*
						RenderizadorGraficoSuperBonus::
							pEstados;

				// Cartelas:
				Camada* RenderizadorGraficoSuperBonus
						::pCamadaMaisAltaDaCartela;

				int RenderizadorGraficoSuperBonus
						::pUltimaApostaCartela;

				// FaltaUm:
				int RenderizadorGraficoSuperBonus
						::pPosicaoXInicialDoFaltaUmEsquerda;

				int RenderizadorGraficoSuperBonus
						::pPosicaoXInicialDoFaltaUmDireita;

				std::deque<PosicaoNasCartelas>
						RenderizadorGraficoSuperBonus
							::pFaltaUns;

				// Placa Prêmios:
				int RenderizadorGraficoSuperBonus
						::pUltimaAposta;

				int RenderizadorGraficoSuperBonus
						::pPosicaoXInicialDaPlaca;

				// Aposta:
				int RenderizadorGraficoSuperBonus
						::pPosicaoXInicialDaAposta;

				// Creditos:
				int RenderizadorGraficoSuperBonus
						::pUltimoCreditos;

				Temporizador* RenderizadorGraficoSuperBonus
						::pPassoDosCreditos;

				IncrementadorDeVisualCredito
						RenderizadorGraficoSuperBonus
							::pAumentaCreditos;

				// Barra Titulo:
				Cronometro* RenderizadorGraficoSuperBonus
						::pEsperaParaOnda;

				int RenderizadorGraficoSuperBonus
						::pQuantasJogadasGratisAnteriormente;

				// Barra Mensagem:
				int RenderizadorGraficoSuperBonus
						::pPosicaoXInicialDaBarraMensagem;

				Cronometro* RenderizadorGraficoSuperBonus
						::pPiscagem;

				// Bolona:
				ComponenteGrafico<Video>*
						RenderizadorGraficoSuperBonus
						::pUltimaBolona;

				int RenderizadorGraficoSuperBonus
						::pUltimaBola;

				int RenderizadorGraficoSuperBonus
						::pPosicao;

				// Elementos da cartela:
				bool RenderizadorGraficoSuperBonus
						::pCartelaEstaChegandoNoFim;

				// Dobro:
				Temporizador* RenderizadorGraficoSuperBonus
						::pPiscagemDoDobro;

				PiscadorDeBonus
						RenderizadorGraficoSuperBonus
							::pPiscaDobro;

				int RenderizadorGraficoSuperBonus
						::p2xAtual;

				// Acumulado:
				double RenderizadorGraficoSuperBonus
						::pUltimoValor;

				int RenderizadorGraficoSuperBonus
						::pPosicaoXAcumulado;

				int RenderizadorGraficoSuperBonus
						::pPosicaoXAnimacaoAcumulado;

				int RenderizadorGraficoSuperBonus
						::pPosicaoXAnimacaoAcumulado2;

				// Bolas:
				BolasAndando* RenderizadorGraficoSuperBonus
						::pBolasAndando;

				Temporizador* RenderizadorGraficoSuperBonus
						::pTemporizadorBolas;

				int RenderizadorGraficoSuperBonus::pPosicao2;

				// Cobrança:
				int RenderizadorGraficoSuperBonus
						::pPosicaoXTextosCobranca;

				// Sorte:
				Sorteio sorte;

				// Mesclagem:
				bool RenderizadorGraficoSuperBonus
						::pLancouAntes;

				bool RenderizadorGraficoSuperBonus
						::pDeveMesclar;

				bool RenderizadorGraficoSuperBonus
						::pDeveRestaurar;

				DesenhistaDeResultadoGraficoNaTela*
						RenderizadorGraficoSuperBonus
								::pDesenhista;

				// Carregamento:
				const Conclusivo* RenderizadorGraficoSuperBonus
						::pCarregamento;

				// 2x:
				int RenderizadorGraficoSuperBonus::pVoltaDoGira;

				bool RenderizadorGraficoSuperBonus
						::pligado;

				// Tela de Demonstração:
				// (acumulado)
				Temporizador* RenderizadorGraficoSuperBonus
						::pTemporizadorAcumulado;

				AcumuladoAndando RenderizadorGraficoSuperBonus
						::pAcumuladoAndando;

				// Restauração de fundo:
				bool RenderizadorGraficoSuperBonus
						::pTelaDemonstracao;

				// Fogos:
				FogosDeArtificio RenderizadorGraficoSuperBonus
						::pFogosDeArtificio;

				Temporizador* RenderizadorGraficoSuperBonus
						::pTemporizadorFogos;

				// BolaExtra:
				int RenderizadorGraficoSuperBonus
						::pUltimoQuadroBolaExtra;

			protected:
				virtual CarregadorDeComponentes&
						RenderizadorGraficoSuperBonus::
							carregador();

				virtual const CarregadorDeComponentes&
						RenderizadorGraficoSuperBonus::
							carregador() const;

				// Operações:
				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaCartelas();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaPremios();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaAposta();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaCreditos();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaBarraTitulo();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaBarraMensagem();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaAcumulado();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaBolona();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaComponentesDaCartela();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaDobro();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaBolaExtra();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaBolas();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaTelaDeCobranca();

                virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::lanca2x();

                virtual bool RenderizadorGraficoSuperBonus
							::finaliza2x();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaTelaDeAjuda();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaAnimacaoAcumulado();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::verificaFimDaQuedaAcumulado();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::deslocaAcumuladoParaDireita();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::iniciaQuedaAcumulado(bool aoContrario = false);

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaTelaDeDemonstracao();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::mesclaOQueDeve();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::atualizaCarregamento();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::soltaFogos();

			public:
				RenderizadorGraficoSuperBonus
						::RenderizadorGraficoSuperBonus();

				virtual RenderizadorGraficoSuperBonus
						::~RenderizadorGraficoSuperBonus();

				virtual ResultadoGrafico&
						RenderizadorGraficoSuperBonus
							::resultadoGrafico();

				virtual const ResultadoGrafico&
						RenderizadorGraficoSuperBonus
							::resultadoGrafico() const;

				virtual EstadosSuperBonus&
						RenderizadorGraficoSuperBonus
							::jogo();

				virtual const EstadosSuperBonus&
						RenderizadorGraficoSuperBonus
							::jogo() const;

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::defineBasicoVisual(
								BasicoVisual&);

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
							::defineEstados(
								EstadosSuperBonus&);

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
								::defineDesenhista(
									DesenhistaDeResultadoGraficoNaTela&);

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
								::defineCarregamento(
									const Conclusivo&);

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
								::liga();

				virtual RenderizadorGraficoSuperBonus&
						RenderizadorGraficoSuperBonus
								::desliga();


				// Executavel:

				/**
				 * Renderiza de fato.
				 */
				virtual Executavel&
						RenderizadorGraficoSuperBonus
							::executa();
		};
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORGRAFICOSUPERBONUS_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_)
