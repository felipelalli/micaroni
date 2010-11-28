/*
 * $RCSfile: LogicaBolas.h,v $
 * $Date: 2005/01/20 21:29:00 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef LOGICA_BOLAS_NOVO_H
#define	LOGICA_BOLAS_NOVO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/superbonus/logica/LogicaBolaExtra.h"
#include "biblia/jogos/superbonus/logica/SorteioBolas.h"
#include "biblia/jogos/superbonus/logica/Premio.h"
#include "biblia/jogos/superbonus/logica/LogicaCartela.h"
#include "biblia/jogos/superbonus/logica/ProbabilidadesDoJogo.h"
#include "biblia/jogos/superbonus/logica/ProbabilidadesDaBolaExtra.h"
#include "biblia/jogos/superbonus/logica/GerenciadorDeFluxoDeJogo.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/jogos/superbonus/logica/util/ArqPremiosDevidos.h"
#include "biblia/jogos/superbonus/logica/util/InterCliPremiacaoAcumulado.h"
using namespace biblia::jogos::superbonus::logica::util;


#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace logica{

				class LogicaBolas: public Objeto{

					private:
						LogicaCartela* pCartelas;
						ProbabilidadesDoJogo* pProbabilidades;
						ProbabilidadesDaBolaExtra* pProbabilidadesBolaExtra;
						GerenciadorDeFluxoDeJogo* pFluxoDeJogo;

						int pVetBolas [36];

						int pQtsBolas;

						bool pConcorreAcumulado;
						bool pEstaNoDobro;
						int  pAposta;


						SorteioBolas pSorteIntervalo;
						Sorteio pSorte;
						SorteioBolas pSorteioBolas;


						Premio pPremios[4];

						InterCliPremiacaoAcumulado* pAcumulado;

						bool LogicaBolas::pEhPossivelColocarPremio (int cartela);

						void LogicaBolas::pGerarBolas (int cartela);
						void LogicaBolas::pGerarBolasRestantes ();
						void LogicaBolas::pMisturarBolas (int vezes);
						void LogicaBolas::pTrocarBolas (int indice1, int indice2);
						void LogicaBolas::pCorrigirBolasBingo();
						void LogicaBolas::pSortearBolasExtras();
						void LogicaBolas::pDefineProbPremiosBolaExtra (int* vetPremiosConcorridos, double valorBolaExtra, double* vetProb, int qtsPremios);


						//Bolas que podem ser sorteadas sem alterar a premiacao
						int pPossiblidadesDePreenchimento [4][12];
						int pQtdNumeros [4];
						int pQtdNumerosSorteados [4];
						SorteioBolas* pSorteCartelas [4];
						int LogicaBolas::pSortearNumeroDisponivel();

						ArqPremiosDevidos pArqPremiosDevidos;

						void LogicaBolas::pVerificarSorteio();

					public:
						LogicaBolas::LogicaBolas (DConfiguracao& conf,LogicaCartela* cartelas, InterCliPremiacaoAcumulado* acumulado = NULL);
						LogicaBolas::~LogicaBolas();

						void LogicaBolas::sortearBolas (bool concorreAcumulado, bool estaNoDobro, int aposta);

						int LogicaBolas::getBola(int qualBola);

						void LogicaBolas::zerar ();

						static int LogicaBolas::QTS_BOLAS_JOGADA;
						static int LogicaBolas::QTS_BOLAS_EXTRAS;

						//fixme nao deve ter essa funcao
						Premio& LogicaBolas::getPremio (int cartela);
						void LogicaBolas::pSortearPremio (int cartela);

						virtual const std::deque<int> LogicaBolas::geraListaDeBolas() const;

						virtual LogicaBolas& LogicaBolas::forcaBolas(const std::deque<int>& bolas);
				};

			}
		}
	}
}

#endif