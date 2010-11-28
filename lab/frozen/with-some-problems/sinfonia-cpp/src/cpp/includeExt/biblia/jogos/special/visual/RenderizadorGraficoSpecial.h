/*
 * $RCSfile: RenderizadorGraficoSpecial.h,v $
 * $Date: 2005/01/20 21:28:56 $
 * $Revision: 1.22 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(SBS_AFX_RENDERIZADORGRAFICOspecial_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_)
#define SBS_AFX_RENDERIZADORGRAFICOspecial_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_

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
		 * A partir das informações do jogo ele
		 * gera um resultado gráfico.
		 */
		class RenderizadorGraficoSpecial: public Renderizador {
			private:
      			BasicoVisual*
						RenderizadorGraficoSpecial::
							pVisual;

				EstadosSpecial*
						RenderizadorGraficoSpecial::
							pEstados;

				// Cartelas:
				Camada* RenderizadorGraficoSpecial
						::pCamadaMaisAltaDaCartela;

				int RenderizadorGraficoSpecial
						::pUltimaApostaCartela;

				// FaltaUm:
				int RenderizadorGraficoSpecial
						::pPosicaoXInicialDoFaltaUmEsquerda;

				int RenderizadorGraficoSpecial
						::pPosicaoXInicialDoFaltaUmDireita;

				std::deque<PontoNaCartela>
						RenderizadorGraficoSpecial
							::pFaltaUns;

				// Placa Prêmios:
				int RenderizadorGraficoSpecial
						::pUltimaAposta;

				int RenderizadorGraficoSpecial
						::pPosicaoXInicialDaPlaca;

				// Aposta:
				int RenderizadorGraficoSpecial
						::pPosicaoXInicialDaAposta;

				// Creditos:
				int RenderizadorGraficoSpecial
						::pUltimoCreditos;

				Temporizador* RenderizadorGraficoSpecial
						::pPassoDosCreditos;

				IncrementadorDeVisualCredito
						RenderizadorGraficoSpecial
							::pAumentaCreditos;

				// Barra Titulo:
				Cronometro* RenderizadorGraficoSpecial
						::pEsperaParaOnda;

				int RenderizadorGraficoSpecial
						::pQuantasJogadasGratisAnteriormente;

				// Barra Mensagem:
				int RenderizadorGraficoSpecial
						::pPosicaoXInicialDaBarraMensagem;

				Cronometro* RenderizadorGraficoSpecial
						::pPiscagem;

				// Bolona:
				ComponenteGrafico<Video>*
						RenderizadorGraficoSpecial
						::pUltimaBolona;

				int RenderizadorGraficoSpecial
						::pUltimaBola;

				int RenderizadorGraficoSpecial
						::pPosicao;

				// Elementos da cartela:
				bool RenderizadorGraficoSpecial
						::pCartelaEstaChegandoNoFim;

				// Dobro:
				Temporizador* RenderizadorGraficoSpecial
						::pPiscagemDoDobro;

				PiscadorDeBonus
						RenderizadorGraficoSpecial
							::pPiscaDobro;

				int RenderizadorGraficoSpecial
						::p2xAtual;

				// Acumulado:
				double RenderizadorGraficoSpecial
						::pUltimoValor;

				int RenderizadorGraficoSpecial
						::pPosicaoXAcumulado;

				int RenderizadorGraficoSpecial
						::pPosicaoXAnimacaoAcumulado;

				int RenderizadorGraficoSpecial
						::pPosicaoXAnimacaoAcumulado2;

				// Bolas:
				BolasAndando* RenderizadorGraficoSpecial
						::pBolasAndando;

				Temporizador* RenderizadorGraficoSpecial
						::pTemporizadorBolas;

				int RenderizadorGraficoSpecial::pPosicao2;

				// Cobrança:
				int RenderizadorGraficoSpecial
						::pPosicaoXTextosCobranca;

				// Sorte:
				Sorteio sorte;

				// Mesclagem:
				bool RenderizadorGraficoSpecial
						::pLancouAntes;

				bool RenderizadorGraficoSpecial
						::pDeveMesclar;

				bool RenderizadorGraficoSpecial
						::pDeveRestaurar;

				DesenhistaDeResultadoGraficoNaTela*
						RenderizadorGraficoSpecial
								::pDesenhista;

				// Carregamento:
				const Conclusivo* RenderizadorGraficoSpecial
						::pCarregamento;

				// 2x:
				int RenderizadorGraficoSpecial::pVoltaDoGira;

				// Tela de Demonstração:
				// (acumulado)
				Temporizador* RenderizadorGraficoSpecial
						::pTemporizadorAcumulado;

				// Restauração de fundo:
				bool RenderizadorGraficoSpecial
						::pTelaDemonstracao;

				// Fogos:
				FogosDeArtificio RenderizadorGraficoSpecial
						::pFogosDeArtificio;

				Temporizador* RenderizadorGraficoSpecial
						::pTemporizadorFogos;

				// BolaExtra:
				int RenderizadorGraficoSpecial
						::pUltimoQuadroBolaExtra;

				// primeira vez:
				bool RenderizadorGraficoSpecial::pPrimeiraVez;

                //Se deu prêmio para não lancar a animacao 2X
                bool RenderizadorGraficoSpecial::pDeuPremio;

                //Se não deu prêmio na passada anterior para lancar a animacao 2X
                bool RenderizadorGraficoSpecial::pDeuPremioJogAnt;

                //Para verificar quantas bolas extra foram lancadas na jogada anterior
                int RenderizadorGraficoSpecial::pQuantasBolasExtra;

                //Para indicar que deve fechar os vidrinhos
                bool RenderizadorGraficoSpecial::pFinalizouBolasExtra;

                // animações do "fluah" (marcação de prêmio)
				std::deque<string> RenderizadorGraficoSpecial::fluah;

				// animações do "consome" (marcação de prêmio)
				std::deque<string> RenderizadorGraficoSpecial::consome;

				// falta-uns da cartelinha
				std::deque<string> RenderizadorGraficoSpecial::faltaUnsDaCartelinha;

				// carregamento
				double RenderizadorGraficoSpecial::pProjecao;
				int RenderizadorGraficoSpecial::pVezes;

			protected:
				virtual CarregadorDeComponentes&
						RenderizadorGraficoSpecial::
							carregador();

				virtual const CarregadorDeComponentes&
						RenderizadorGraficoSpecial::
							carregador() const;

				// Operações:
				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::primeiraVez();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaCartelas();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaPremios();

                virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::lancaCobranca();

			    virtual bool RenderizadorGraficoSpecial
						::finalizaCobranca();

			    virtual bool RenderizadorGraficoSpecial
						::verificaVidro3();

			    virtual bool RenderizadorGraficoSpecial
						::verificaVidro3_i();

                virtual RenderizadorGraficoSpecial&
	                    RenderizadorGraficoSpecial::abreVidro(int qual);

                virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::lancaAjuda();

			    virtual bool RenderizadorGraficoSpecial
						::finalizaAjuda();

                virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaAposta();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaCreditos();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaBarraTitulo();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaBarraMensagem();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaAcumulado();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaBolona();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaComponentesDaCartela();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaDobro();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaHistorico();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaBolaExtra();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaBolas();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaTelaDeCobranca();

                virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::lanca2x();

                virtual bool RenderizadorGraficoSpecial
							::finaliza2x();

                virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::fechaVidros(int qts=3);

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaTelaDeAjuda();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaAnimacaoAcumulado();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::verificaFimDaQuedaAcumulado();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::deslocaAcumuladoParaDireita();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::iniciaQuedaAcumulado(bool aoContrario = false);

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaTelaDeDemonstracao();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::mesclaOQueDeve();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::atualizaCarregamento();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::soltaFogos();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::lancaFlash();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::lancaFlashizinho();

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::finalizaFlash();

			public:
				RenderizadorGraficoSpecial
						::RenderizadorGraficoSpecial();

				virtual RenderizadorGraficoSpecial
						::~RenderizadorGraficoSpecial();

				virtual ResultadoGrafico&
						RenderizadorGraficoSpecial
							::resultadoGrafico();

				virtual const ResultadoGrafico&
						RenderizadorGraficoSpecial
							::resultadoGrafico() const;

				virtual EstadosSpecial&
						RenderizadorGraficoSpecial
							::jogo();

				virtual const EstadosSpecial&
						RenderizadorGraficoSpecial
							::jogo() const;

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::defineBasicoVisual(
								BasicoVisual&);

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
							::defineEstados(
								EstadosSpecial&);

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
								::defineDesenhista(
									DesenhistaDeResultadoGraficoNaTela&);

				virtual RenderizadorGraficoSpecial&
						RenderizadorGraficoSpecial
								::defineCarregamento(
									const Conclusivo&);

				// Executavel:

				/**
				 * Renderiza de fato.
				 */
				virtual Executavel&
						RenderizadorGraficoSpecial
							::executa();
		};
	  }
	}
  }
}

#endif // !defined(AFX_RENDERIZADORGRAFICOSUPERBONUS_H__691CF28A_3E2F_40C1_8471_B83061FB6192__INCLUDED_)
