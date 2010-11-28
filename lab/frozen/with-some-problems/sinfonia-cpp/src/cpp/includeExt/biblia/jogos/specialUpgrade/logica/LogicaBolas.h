/*
 * $RCSfile: LogicaBolas.h,v $
 * $Date: 2005/01/26 22:11:12 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_LOGICA_BOLAS_BASE_H
#define	LOGICA_BOLAS_BASE_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/specialUpgrade/logica/SorteioBolas.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/jogos/specialUpgrade/logica/PremioSurpresa.h"
#include "biblia/jogos/specialUpgrade/logica/GerenciadorDePremios.h"
#include "biblia/jogos/specialUpgrade/logica/GerenciadorDeProbabilidades.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaCartelas.h"
#include "biblia/jogos/specialUpgrade/logica/GerenciadorDeFluxoDeJogo.h"
#include "biblia/jogos/specialUpgrade/logica/ControladorDePercentual.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/specialUpgrade/logica/util/Premio.h"
#include "biblia/jogos/specialUpgrade/logica/util/ArqPremiosDevidos.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/SorteioBolas.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/jogos/specialUpgrade/dados/DadosConfiguracao.h"
#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/jogos/specialUpgrade/logica/util/InterCliPremiacaoAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;



namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				class LogicaBolas: public Objeto{

				private:

						bool pConcorreAcumulado;
						bool pDobro;
						int  pQtsCartelas;


						biblia::jogos::specialUpgrade::logica::SorteioBolas pSorteioBolas;
						Sorteio pSorteio;

						PremioSurpresa* pPremioSurpresa;
						LogicaCartelas& pCartelas;
						GerenciadorDePremios& pGerenciadorDePremios;
						GerenciadorDeProbabilidades pGerenciadorProbabilidades;
						GerenciadorDeFluxoDeJogo pPreSorteio;
						ControladorDePercentual* pControladorDePercentual;
						InterCliPremiacaoAcumulado* pInterCliPremiacaoAcumulado;

						ArqPremiosDevidos pArqPremiosDevidos;

						biblia::armazenamento::volatil::Lista pLstPremios;

						SorteioBolas pSorteioNumerosDisponiveis;
						ListaInt     pLstNumerosDisponiveis;

						biblia::armazenamento::volatil::Lista pLstPontosDisponiveis;

						int pVetBolas [45];

						int pQtsBolas;
						
						void LogicaBolas::sortearPremios (int* premios, bool concorreAcumulado, bool estaNoDobro, int qualPremioForcado);
						bool LogicaBolas::pEhPossivelColocarPremio (int iPremio, bool concorreAcumulado);
						void LogicaBolas::pGerarBolasPremio (int iCartela, int iPremio);
						bool LogicaBolas::pGerarBolasRestantes ();
						int  LogicaBolas::pSortearNumeroDisponivel();
						void LogicaBolas::pMisturarBolas (int vezes);
						void LogicaBolas::pTrocarBolas (int indice1, int indice2);
						void LogicaBolas::pCorrigirBolasBingo();

						biblia::jogos::specialUpgrade::logica::util::Premio& LogicaBolas::pGetPremio (int iPremio);
						PremioSurpresa& LogicaBolas::premioSurpresa();

						bool LogicaBolas::pValidaBolas();

					public:
						LogicaBolas::LogicaBolas (GerenciadorDePremios& gerenciador, LogicaCartelas& cartelas, biblia::jogos::specialUpgrade::dados::DConfiguracao& configuracao,biblia::jogos::specialUpgrade::logica::LogicaBolaExtra& lBolaExtra);
						LogicaBolas::~LogicaBolas();

						void LogicaBolas::sortearBolas (bool concorreAcumulado, bool estaNoDobro, int qualPremioForcado = -1);

						int LogicaBolas::getBola(int qualBola);

						void LogicaBolas::zerar ();

						static int LogicaBolas::QTS_BOLAS_JOGADA;
						static int LogicaBolas::QTS_BOLAS_EXTRAS;

						virtual const deque<int> LogicaBolas::geraListaDeBolas() const;

						virtual LogicaBolas& LogicaBolas::forcaBolas(const deque<int>& bolas);

						GerenciadorDeProbabilidades& LogicaBolas::getGerenciadorProb (){
							return this->pGerenciadorProbabilidades;
						}

						void LogicaBolas::comparaCartelasComBolas();

						void LogicaBolas::defineInterfacePremiacaoAcumulado(biblia::jogos::specialUpgrade::logica::util::InterCliPremiacaoAcumulado* interCliPremiacaoAcumulado);
						void LogicaBolas::defineDadosRede (biblia::jogos::specialUpgrade::dados::DadosConfiguracao& dados);

						void LogicaBolas::definePremioSurpresa (PremioSurpresa* premio);

						GerenciadorDeFluxoDeJogo& LogicaBolas::sorteio (){ return this->pPreSorteio;};

						void LogicaBolas::reposicionarPremiosDescartadosPorBolaExtra();
				};

			}
		}
	}
}

#endif