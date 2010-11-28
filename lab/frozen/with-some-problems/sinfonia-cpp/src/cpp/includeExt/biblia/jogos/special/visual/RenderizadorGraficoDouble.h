/*
 * $RCSfile: RenderizadorGraficoDouble.h,v $
 * $Date: 2005/01/20 21:28:56 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(SBS_AFX_RENDERIZADORGRAFICODOUBLE_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_)
#define SBS_AFX_RENDERIZADORGRAFICODOUBLE_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_

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
#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
#include "biblia/visual/animacao/Video.h"
#include "biblia/visual/dinamica/ResultadoGrafico.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/dinamica/ComponenteGrafico.h"
#include "biblia/visual/dinamica/DesenhistaDeResultadoGraficoNaTela.h"
#include "biblia/visual/dinamica/Camada.h"
#include "biblia/visual/fonte/RenderizadorDeFonteImagem.h"
#include "biblia/visual/cores/Transparente.h"
#include "biblia/visual/geometricos/Retangulo.h"
#include "biblia/jogos/special/EstadosSpecial.h"
#include "biblia/jogos/special/estados/VisorCreditos.h"
#include "biblia/jogos/special/estados/Bonus.h"
#include "biblia/jogos/special/visual/BolasAndando.h"
#include "biblia/jogos/special/visual/FogosDeArtificio.h"
#include "biblia/jogos/special/util/NumeroUtil.h"

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
using namespace biblia::jogos::special;
using namespace biblia::jogos::special::estados;
using namespace biblia::jogos::special::logica;
using namespace biblia::jogos::special::util;

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace visual {

		/**
		 * Para que os créditos subam aos poucos.
		 */
		class IncrementadorDeVisualCreditoDouble
				:public ExecutavelOtimizado
		{
			private:
				VisorCreditos*
						IncrementadorDeVisualCreditoDouble::vc;

			public:
				IncrementadorDeVisualCreditoDouble
						::IncrementadorDeVisualCreditoDouble();

				virtual IncrementadorDeVisualCreditoDouble&
						IncrementadorDeVisualCreditoDouble
							::defineVisorCreditos(VisorCreditos&);

				virtual ExecutavelOtimizado&
						IncrementadorDeVisualCreditoDouble
							::executa(int quantasVezes);
		};

		/**
		 * Para que o fundo fique piscando.
		 */
		class PiscadorDeBonusDouble: public ExecutavelOtimizado	{
			private:
				Bonus* PiscadorDeBonusDouble::b;

			public:
				PiscadorDeBonusDouble
						::PiscadorDeBonusDouble();

				virtual PiscadorDeBonusDouble&
						PiscadorDeBonusDouble
							::defineBonus(Bonus&);

				virtual ExecutavelOtimizado&
						PiscadorDeBonusDouble
							::executa(int quantasVezes);
		};

		/**
		 * A partir das informações do jogo ele
		 * gera um resultado gráfico.
		 */
		class RenderizadorGraficoDouble: public Renderizador {
			private:
      			BasicoVisual*
						RenderizadorGraficoDouble::
							pVisual;

				EstadosSpecial*
						RenderizadorGraficoDouble::
							pEstados;

				// Cartelas:
				Camada* RenderizadorGraficoDouble
						::pCamadaMaisAltaDaCartela;

				int RenderizadorGraficoDouble
						::pUltimaApostaCartela;

				// FaltaUm:
				int RenderizadorGraficoDouble
						::pPosicaoXInicialDoFaltaUmEsquerda;

				int RenderizadorGraficoDouble
						::pPosicaoXInicialDoFaltaUmDireita;

				std::deque<PontoNaCartela>
						RenderizadorGraficoDouble
							::pFaltaUns;

				// Placa Prêmios:
				int RenderizadorGraficoDouble
						::pUltimaAposta;

				int RenderizadorGraficoDouble
						::pPosicaoXInicialDaPlaca;

				// Aposta:
				int RenderizadorGraficoDouble
						::pPosicaoXInicialDaAposta;

				// Creditos:
				int RenderizadorGraficoDouble
						::pUltimoCreditos;

				Temporizador* RenderizadorGraficoDouble
						::pPassoDosCreditos;

				IncrementadorDeVisualCreditoDouble
						RenderizadorGraficoDouble
							::pAumentaCreditos;

				// Barra Titulo:
				Cronometro* RenderizadorGraficoDouble
						::pEsperaParaOnda;

				int RenderizadorGraficoDouble
						::pQuantasJogadasGratisAnteriormente;

				// Barra Mensagem:
				int RenderizadorGraficoDouble
						::pPosicaoXInicialDaBarraMensagem;

				Cronometro* RenderizadorGraficoDouble
						::pPiscagem;

				// Bolona:
				ComponenteGrafico<Video>*
						RenderizadorGraficoDouble
						::pUltimaBolona;

				int RenderizadorGraficoDouble
						::pUltimaBola;

				int RenderizadorGraficoDouble
						::pPosicao;

				// Elementos da cartela:
				bool RenderizadorGraficoDouble
						::pCartelaEstaChegandoNoFim;

				// Dobro:
				Temporizador* RenderizadorGraficoDouble
						::pPiscagemDoDobro;

				PiscadorDeBonusDouble
						RenderizadorGraficoDouble
							::pPiscaDobro;

				int RenderizadorGraficoDouble
						::p2xAtual;

				// Acumulado:
				double RenderizadorGraficoDouble
						::pUltimoValor;

				int RenderizadorGraficoDouble
						::pPosicaoXAcumulado;

				int RenderizadorGraficoDouble
						::pPosicaoXAnimacaoAcumulado;

				int RenderizadorGraficoDouble
						::pPosicaoXAnimacaoAcumulado2;

				// Bolas:
				BolasAndando* RenderizadorGraficoDouble
						::pBolasAndando;

				Temporizador* RenderizadorGraficoDouble
						::pTemporizadorBolas;

				int RenderizadorGraficoDouble::pPosicao2;

				// Cobrança:
				int RenderizadorGraficoDouble
						::pPosicaoXTextosCobranca;

				// Sorte:
				Sorteio sorte;

				// Mesclagem:
				bool RenderizadorGraficoDouble
						::pLancouAntes;

				bool RenderizadorGraficoDouble
						::pDeveMesclar;

				bool RenderizadorGraficoDouble
						::pDeveRestaurar;

				DesenhistaDeResultadoGraficoNaTela*
						RenderizadorGraficoDouble
								::pDesenhista;

				// Carregamento:
				const Conclusivo* RenderizadorGraficoDouble
						::pCarregamento;

				// 2x:
				int RenderizadorGraficoDouble::pVoltaDoGira;

				// Tela de Demonstração:
				// (acumulado)
				Temporizador* RenderizadorGraficoDouble
						::pTemporizadorAcumulado;

				// Restauração de fundo:
				bool RenderizadorGraficoDouble
						::pTelaDemonstracao;

				// Fogos:
				FogosDeArtificio RenderizadorGraficoDouble
						::pFogosDeArtificio;

				Temporizador* RenderizadorGraficoDouble
						::pTemporizadorFogos;

				// BolaExtra:
				int RenderizadorGraficoDouble
						::pUltimoQuadroBolaExtra;

				// primeira vez:
				bool RenderizadorGraficoDouble::pPrimeiraVez;

                //Se deu prêmio para não lancar a animacao 2X
                bool RenderizadorGraficoDouble::pDeuPremio;

                //Se não deu prêmio na passada anterior para lancar a animacao 2X
                bool RenderizadorGraficoDouble::pDeuPremioJogAnt;

                //Para verificar quantas bolas extra foram lancadas na jogada anterior
                int RenderizadorGraficoDouble::pQuantasBolasExtra;

                //Para indicar que deve fechar os vidrinhos
                bool RenderizadorGraficoDouble::pFinalizouBolasExtra;

                // animações do "fluah" (marcação de prêmio)
				std::deque<string> RenderizadorGraficoDouble::fluah;

				// animações do "consome" (marcação de prêmio)
				std::deque<string> RenderizadorGraficoDouble::consome;

				// falta-uns da cartelinha
				std::deque<string> RenderizadorGraficoDouble::faltaUnsDaCartelinha;

				// carregamento
				double RenderizadorGraficoDouble::pProjecao;
				int RenderizadorGraficoDouble::pVezes;

			protected:
				virtual CarregadorDeComponentes&
						RenderizadorGraficoDouble::
							carregador();

				virtual const CarregadorDeComponentes&
						RenderizadorGraficoDouble::
							carregador() const;

				// Operações:
				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::primeiraVez();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaCartelas();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaPremios();

                virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::lancaCobranca();

			    virtual bool RenderizadorGraficoDouble
						::finalizaCobranca();

			    virtual bool RenderizadorGraficoDouble
						::verificaVidro3();

			    virtual bool RenderizadorGraficoDouble
						::verificaVidro3_i();

                virtual RenderizadorGraficoDouble&
	                    RenderizadorGraficoDouble::abreVidro(int qual);

                virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::lancaAjuda();

			    virtual bool RenderizadorGraficoDouble
						::finalizaAjuda();

                virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaAposta();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaCreditos();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaBarraTitulo();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaBarraMensagem();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaAcumulado();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaBolona();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaComponentesDaCartela();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaDobro();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaBolaExtra();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaBolas();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaTelaDeCobranca();

                virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::lanca2x();

                virtual bool RenderizadorGraficoDouble
							::finaliza2x();

                virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::fechaVidros(int qts=3);

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaTelaDeAjuda();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaAnimacaoAcumulado();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::verificaFimDaQuedaAcumulado();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::deslocaAcumuladoParaDireita();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::iniciaQuedaAcumulado(bool aoContrario = false);

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaTelaDeDemonstracao();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::mesclaOQueDeve();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaCarregamento();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::soltaFogos();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::lancaFlash();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::lancaFlashizinho();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::finalizaFlash();

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::atualizaHistorico();

			public:
				RenderizadorGraficoDouble
						::RenderizadorGraficoDouble();

				virtual RenderizadorGraficoDouble
						::~RenderizadorGraficoDouble();

				virtual ResultadoGrafico&
						RenderizadorGraficoDouble
							::resultadoGrafico();

				virtual const ResultadoGrafico&
						RenderizadorGraficoDouble
							::resultadoGrafico() const;

				virtual EstadosSpecial&
						RenderizadorGraficoDouble
							::jogo();

				virtual const EstadosSpecial&
						RenderizadorGraficoDouble
							::jogo() const;

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::defineBasicoVisual(
								BasicoVisual&);

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
							::defineEstados(
								EstadosSpecial&);

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
								::defineDesenhista(
									DesenhistaDeResultadoGraficoNaTela&);

				virtual RenderizadorGraficoDouble&
						RenderizadorGraficoDouble
								::defineCarregamento(
									const Conclusivo&);

				// Executavel:

				/**
				 * Renderiza de fato.
				 */
				virtual Executavel&
						RenderizadorGraficoDouble
							::executa();
		};
	  }
	}
  }
}

#endif // !defined(SBS_AFX_RENDERIZADORGRAFICODOUBLE_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_)
