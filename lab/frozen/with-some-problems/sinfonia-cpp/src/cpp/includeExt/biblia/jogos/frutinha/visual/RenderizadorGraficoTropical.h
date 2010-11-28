/*
 * $RCSfile: RenderizadorGraficoTropical.h,v $
 * $Date: 2005/01/20 21:28:52 $
 * $Revision: 1.18 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef RENDERIZADOR_GRAFICO_TROPICAL_TROPCIAL_H
#define RENDERIZADOR_GRAFICO_TROPICAL_TROPCIAL_H



#include "biblia/logica/Renderizador.h"
using namespace biblia::logica;

#include "biblia/visual/dinamica/BasicoVisual.h"
using namespace biblia::visual::dinamica;

#include "biblia/visual/geometricos/Retangulo.h"
using namespace biblia::visual::geometricos;

#include "biblia/visual/fonte/RenderizadorDeFonteImagem.h"
using namespace biblia::visual::fonte;

#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
#include "biblia/armazenamento/volatil/primitivos/Flutuante.h"
using namespace biblia::armazenamento::volatil::primitivos;

#include "biblia/jogos/frutinha/estados/EstadosTropical.h"
using namespace biblia::jogos::frutinha::estados;

#include "biblia/jogos/frutinha/util/NumeroUtil.h"
using namespace biblia::jogos::frutinha::util;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#include "biblia/seguranca/ControleLicenca.h"
using namespace biblia::seguranca;



namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace visual{

				/**
				 * Para que os créditos subam aos poucos.
				 */
				class IncrementadorTropicalDeCredito
						:public ExecutavelOtimizado
				{
					private:
						BarraPrincipal*
								IncrementadorTropicalDeCredito::bp;

					public:
						IncrementadorTropicalDeCredito
								::IncrementadorTropicalDeCredito();

						virtual IncrementadorTropicalDeCredito&
								IncrementadorTropicalDeCredito
									::defineBarraPrincipal(BarraPrincipal&);

						virtual ExecutavelOtimizado&
								IncrementadorTropicalDeCredito
									::executa(int quantasVezes);
				};

				class RenderizadorGraficoTropical: public Renderizador{

					private:
						EstadosTropical& pEstados;
						BasicoVisual* pVisual;

						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaBarraDeMensagens();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaAcumulado();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaBarraPrincipal();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaBonus();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaRodilho();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaTelaDeAjuda();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaTelaDeCobranca();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaTelaDeCarregamento();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaDemonstracao();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaFlash();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pRenderizaMaquinaBloqueada();

						// posições iniciais:
						bool pPrimeiraVez;
						int pPosicaoXInicialDaAposta;
						int pPosicaoXInicialDosCreditos;
						int pPosicaoXInicialDoPremio;
						int pPosicaoXInicialDoAcumulado;

						// Créditos:
						Temporizador* RenderizadorGraficoTropical
								::pPassoDosCreditos;

						IncrementadorTropicalDeCredito
								RenderizadorGraficoTropical
									::pAumentaCreditos;

						//Funções auxiliares do Bonus
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pReposicionaTextoBonus(int tamanho);

						//Funções auxiliares do rodilho
						bool pVetParado [3][5];
						Sorteio pSorte;
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pAtualizaRodilho (int linha, int coluna);
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pAtualizaPremio (int linha);
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pDesenhaApostaRodilho();
						RenderizadorGraficoTropical& RenderizadorGraficoTropical::pVerificaParadaDosRodilhos();
						bool RenderizadorGraficoTropical::pAcesso (int linha, int coluna);
						std::string RenderizadorGraficoTropical::pNomeCorLinha (int qualPremio);

						ControleLicenca& pLicenca;

					public:

						RenderizadorGraficoTropical::RenderizadorGraficoTropical (EstadosTropical& estados,ControleLicenca& licenca);
						virtual RenderizadorGraficoTropical::~RenderizadorGraficoTropical();

						virtual BasicoVisual&
								RenderizadorGraficoTropical::visual();

						virtual RenderizadorGraficoTropical&
								RenderizadorGraficoTropical::defineVisual(
										BasicoVisual&);

						Executavel& RenderizadorGraficoTropical::executa();
				};
			}
		}
	}
}

#endif