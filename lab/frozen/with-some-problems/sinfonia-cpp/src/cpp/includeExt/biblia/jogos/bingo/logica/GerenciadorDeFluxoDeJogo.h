/*
 * $RCSfile: GerenciadorDeFluxoDeJogo.h,v $
 * $Date: 2004/06/16 00:31:25 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef GERENCIADOR_DE_FLUXO_DE_JOGO_H
#define GERENCIADOR_DE_FLUXO_DE_JOGO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/bingo/logica/GerenciadorDeProbabilidades.h"
using namespace biblia::jogos::bingo::logica;

namespace biblia{
	
	namespace jogos{

		namespace bingo{
		
			namespace logica{	

				class GerenciadorDeFluxoDeJogo: public Objeto{
					
					private:

						Sorteio pSorteio;

						GerenciadorDeProbabilidades& pGerenciador;
						
						biblia::armazenamento::volatil::Lista pLstPremiosConcorre;
						biblia::armazenamento::volatil::Lista pLstPremiosNaoConcorre;
						biblia::armazenamento::volatil::Lista pLstPremiosDobro;

						void GerenciadorDeFluxoDeJogo::pGerarPremiacao(bool concorreAcumulado,bool dobro,int cartelas);
						void GerenciadorDeFluxoDeJogo::pArranjarPremiacao(int* vetPremios, int qtsPremios);
						
						ListaInt& GerenciadorDeFluxoDeJogo::pGetLstPremios (bool concorreAcumulado, bool dobro, int cartelas);

						enum Constantes{
							QTS_JOGADAS=1000							
						};



						int maxJogadasComPremio;
						int jogadasSeguidasComPremio;
						int maxJogadasSemPremio;
						int jogadasSeguidasSemPremio;



					public:
						GerenciadorDeFluxoDeJogo::GerenciadorDeFluxoDeJogo(GerenciadorDeProbabilidades& gerenciador);
						GerenciadorDeFluxoDeJogo::~GerenciadorDeFluxoDeJogo();

						int GerenciadorDeFluxoDeJogo::getPremio(bool concorreAcumulado,bool dobro,int cartelas);
				};
			}
		}
	}
}
#endif