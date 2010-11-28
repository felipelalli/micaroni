/*
 * $RCSfile: LogicaBolas.h,v $
 * $Date: 2005/01/20 21:28:46 $
 * $Revision: 1.19 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef LOGICA_BOLAS_BASE_H
#define	LOGICA_BOLAS_BASE_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/special/logica/SorteioBolas.h"
using namespace biblia::jogos::special::logica;

#include "biblia/jogos/bingo/logica/GerenciadorDePremios.h"
#include "biblia/jogos/bingo/logica/GerenciadorDeProbabilidades.h"
#include "biblia/jogos/bingo/logica/LogicaCartelas.h"
#include "biblia/jogos/bingo/logica/GerenciadorDeFluxoDeJogo.h"
#include "biblia/jogos/bingo/logica/ControladorDePercentual.h"
using namespace biblia::jogos::bingo::logica;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/bingo/logica/util/Premio.h"
#include "biblia/jogos/bingo/logica/util/ArqPremiosDevidos.h"
using namespace biblia::jogos::bingo::logica::util;

//FIXME: AQUI NAO DEVERIA CHAMAR NADA DO SPECIAL
#include "biblia/jogos/special/logica/SorteioBolas.h"
using namespace biblia::jogos::special::logica;

//FIXME: Nao deveria chamar nada do special, usa o configuracao apenas para pegar o valor do acumulado
#include "biblia/jogos/special/dados/DadosConfiguracao.h"
#include "biblia/jogos/special/dados/DConfiguracao.h"
using namespace biblia::jogos::special::dados;

//FIXME: AQUI NAO DEVERIA CHAMAR NADA DO SPECIAL
#include "biblia/jogos/special/logica/util/InterCliPremiacaoAcumulado.h"
using namespace biblia::jogos::special::logica::util;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;



namespace biblia{

	namespace jogos{

		namespace bingo{

			namespace logica{

				class LogicaBolas: public Objeto{

				private:

						biblia::jogos::special::logica::SorteioBolas pSorteioBolas;
						Sorteio pSorteio;

						LogicaCartelas& pCartelas;
						GerenciadorDePremios& pGerenciadorDePremios;
						GerenciadorDeProbabilidades pGerenciadorProbabilidades;
						GerenciadorDeFluxoDeJogo pPreSorteio;
						ControladorDePercentual* pControladorDePercentual;
						biblia::jogos::special::logica::util::InterCliPremiacaoAcumulado* pInterCliPremiacaoAcumulado;

						biblia::jogos::bingo::logica::util::ArqPremiosDevidos pArqPremiosDevidos;

						biblia::armazenamento::volatil::Lista pLstPremios;

						biblia::jogos::special::logica::SorteioBolas pSorteioNumerosDisponiveis;
						ListaInt     pLstNumerosDisponiveis;
						biblia::armazenamento::volatil::Lista        pLstPontosDisponiveis;

						int pVetBolas [36];

						int pQtsBolas;

						bool LogicaBolas::pEhPossivelColocarPremio (int iPremio, bool concorreAcumulado);
						void LogicaBolas::pGerarBolasPremio (int iCartela, int iPremio);
						void LogicaBolas::pGerarBolasRestantes ();
						int  LogicaBolas::pSortearNumeroDisponivel();
						void LogicaBolas::pMisturarBolas (int vezes);
						void LogicaBolas::pTrocarBolas (int indice1, int indice2);
						void LogicaBolas::pCorrigirBolasBingo();

						biblia::jogos::bingo::logica::util::Premio& LogicaBolas::pGetPremio (int iPremio);

					public:
						LogicaBolas::LogicaBolas (GerenciadorDePremios& gerenciador, LogicaCartelas& cartelas, biblia::jogos::special::dados::DConfiguracao& configuracao,biblia::jogos::bingo::logica::LogicaBolaExtra& lBolaExtra);
						LogicaBolas::~LogicaBolas();

						void LogicaBolas::sortearBolas (bool concorreAcumulado, bool estaNoDobro, int forcarPremio = -1);

						int LogicaBolas::getBola(int qualBola);

						void LogicaBolas::zerar ();

						static int LogicaBolas::QTS_BOLAS_JOGADA;
						static int LogicaBolas::QTS_BOLAS_EXTRAS;

						virtual const std::deque<int> LogicaBolas::geraListaDeBolas() const;

						virtual LogicaBolas& LogicaBolas::forcaBolas(const std::deque<int>& bolas);

						GerenciadorDeProbabilidades& LogicaBolas::getGerenciadorProb (){
							return this->pGerenciadorProbabilidades;
						}

						void LogicaBolas::comparaCartelasComBolas();

						void LogicaBolas::defineInterfacePremiacaoAcumulado(biblia::jogos::special::logica::util::InterCliPremiacaoAcumulado* interCliPremiacaoAcumulado);
						void LogicaBolas::defineDadosRede (biblia::jogos::special::dados::DadosConfiguracao& dados);
				};

			}
		}
	}
}

#endif