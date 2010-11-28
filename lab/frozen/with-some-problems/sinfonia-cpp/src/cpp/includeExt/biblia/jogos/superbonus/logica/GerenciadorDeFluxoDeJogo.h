/*
 * $RCSfile: GerenciadorDeFluxoDeJogo.h,v $
 * $Date: 2004/05/18 18:47:14 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef GERENCIADOR_DE_FLUXO_DE_JOGO_H_SB
#define GERENCIADOR_DE_FLUXO_DE_JOGO_H_SB

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/superbonus/logica/ProbabilidadesDoJogo.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

namespace biblia{
	
	namespace jogos{

		namespace superbonus{
		
			namespace logica{	

				class GerenciadorDeFluxoDeJogo: public Objeto{
					
					private:

						Sorteio pSorteio;

						ProbabilidadesDoJogo* pProbJogo;
						
						biblia::armazenamento::volatil::Lista pLstPremiosConcorre;
						biblia::armazenamento::volatil::Lista pLstPremiosNaoConcorre;
						biblia::armazenamento::volatil::Lista pLstPremiosDobro;

						void GerenciadorDeFluxoDeJogo::pGerarPremiacao(bool concorreAcumulado,bool dobro,int cartelas);
						void GerenciadorDeFluxoDeJogo::pArranjarPremiacao(int* vetPremios, int qtsPremios);
						
						biblia::armazenamento::volatil::ListaInt& GerenciadorDeFluxoDeJogo::pGetLstPremios (bool concorreAcumulado, bool dobro, int cartelas);

						enum Constantes{
							QTS_JOGADAS=1000							
						};



						int maxJogadasComPremio;
						int jogadasSeguidasComPremio;
						int maxJogadasSemPremio;
						int jogadasSeguidasSemPremio;



					public:
						GerenciadorDeFluxoDeJogo::GerenciadorDeFluxoDeJogo(ProbabilidadesDoJogo* probJogo);
						GerenciadorDeFluxoDeJogo::~GerenciadorDeFluxoDeJogo();

						int GerenciadorDeFluxoDeJogo::getPremio(bool concorreAcumulado,bool dobro,int cartelas);
				};
			}
		}
	}
}
#endif