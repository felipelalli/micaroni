/*
 * $RCSfile: GerenciadorDeFluxoDeJogo.h,v $
 * $Date: 2005/01/19 17:22:10 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_GERENCIADOR_DE_FLUXO_DE_JOGO_H
#define AGES_SPECIAL_UPGRADE_GERENCIADOR_DE_FLUXO_DE_JOGO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/specialUpgrade/logica/GerenciadorDeProbabilidades.h"
using namespace biblia::jogos::specialUpgrade::logica;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				class GerenciadorDeFluxoDeJogo: public Objeto{

					private:

						Sorteio pSorteio;

						GerenciadorDeProbabilidades& pGerenciador;

						int premioATranformarConcorre    [4];
						int creditosDevidosConcorre      [4];

						int premioATranformarNaoConcorre [4];
						int creditosDevidosNaoConcorre   [4];

						int premioATranformarDobro       [4];
						int creditosDevidosDobro         [4];

						biblia::armazenamento::volatil::Lista pLstPremiosConcorre;
						biblia::armazenamento::volatil::Lista pLstPremiosNaoConcorre;
						biblia::armazenamento::volatil::Lista pLstPremiosDobro;

						void GerenciadorDeFluxoDeJogo::pGerarPremiacao(bool concorreAcumulado,bool dobro,int cartelas);
						void GerenciadorDeFluxoDeJogo::pArranjarPremiacao(int* vetPremios, int qtsPremios);

						ListaInt& GerenciadorDeFluxoDeJogo::pGetLstPremios (bool concorreAcumulado, bool dobro, int cartelas);

						enum Constantes{
							QTS_JOGADAS=1000
						};


						int* GerenciadorDeFluxoDeJogo::getPremioATransformar (bool concorreAcumulado, bool dobro, int cartelas);
						int* GerenciadorDeFluxoDeJogo::getCreditosDevidos (bool concorreAcumulado, bool dobro, int cartelas);

						void GerenciadorDeFluxoDeJogo::sorteiaPremioATransformar (bool concorreAcumulado, bool dobro, int cartelas);						
	


					public:
						GerenciadorDeFluxoDeJogo::GerenciadorDeFluxoDeJogo(GerenciadorDeProbabilidades& gerenciador);
						GerenciadorDeFluxoDeJogo::~GerenciadorDeFluxoDeJogo();

						int GerenciadorDeFluxoDeJogo::getPremio(bool concorreAcumulado,bool dobro,int cartelas);

						void GerenciadorDeFluxoDeJogo::reposicionaPremio (int premio, bool concorreAcumulado, bool dobro, int cartelas);
				};
			}
		}
	}
}
#endif
