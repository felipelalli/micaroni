/*
 * $RCSfile: ProbabilidadesDoJogo.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef PROBABILIDADES_JOGO_H_SW
#define PROBABILIDADES_JOGO_H_SW

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/jogos/superbonus/logica/FormulaMatematica.h"
#include "biblia/jogos/superbonus/logica/LogicaCredito.h"
#include "biblia/fluxo/Semaforo.h"

using namespace biblia::basico;
using namespace biblia::jogos::superbonus::dados;
using namespace biblia::fluxo;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {

		  class ProbabilidadesDoJogo: public Objeto {
			private:

				Semaforo* pSemaforo;

				FormulaMatematica* pFormula;

				DConfiguracao& pConfiguracao;


				double ProbabilidadesDoJogo::leProbalidadeDeUmPremio(const char* qualPremio, bool dobro);

				double pProbabilidadeDeIdaParaABolaExtraComUmaLinha;
				double pProbabilidadeDeIdaParaABolaExtraComDuasLinhas;
				double pProbabilidadeDeIdaParaABolaExtraNaLinhaDupla;
				double pProbabilidadeDeFaltaUmParaLinha;

			public:
				ProbabilidadesDoJogo(DConfiguracao&);
				~ProbabilidadesDoJogo();

				//retorna as probablidades de premiação
				double probabilidadeBingo     (bool dobro);
				double probabilidadeLinhaDupla(bool dobro);
				double probabilidadeLinha     (bool dobro);
				double probabilidadeCantos    (bool dobro);
				double probabiliadeDeAcumulado();

				//retorna as probablidades relacionadas com as bolas extras
				double probabilidadeDeBolaExtraParaBingo();
				double probabilidadeDeBolaExtraParaLinhaDupla();
				double probabilidadeDeBolaExtraParaLinhaDuplaComDuasLinhas();
				double probabilidadeDeFaltaUmParaLinha();

				double ProbabilidadesDoJogo::valorInicialAcumuladoAtual();
				void ProbabilidadesDoJogo::premiouAcumulado();

				void ProbabilidadesDoJogo::calcular(bool concorreAcumulado);
		};
	  }
	}
  }
}

#endif
