/*
 * $RCSfile: ProbabilidadesDaBolaExtra.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef PROBABILIDADES_BOLA_EXTRA_H_SW
#define PROBABILIDADES_BOLA_EXTRA_H_SW

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
using namespace biblia::jogos::superbonus::dados;

#include "biblia/jogos/superbonus/logica/FormulaMatematica.h"
#include "biblia/jogos/superbonus/logica/LogicaCredito.h"
using namespace biblia::jogos::superbonus::logica;

namespace biblia {

  namespace jogos {

    namespace superbonus {

	  namespace logica {

		  class ProbabilidadesDaBolaExtra: public Objeto {
			private:

				FormulaMatematica* pFormula;

				DConfiguracao& pConfiguracao;

				void pRecalcula(int premio);

				double pProbabilidadeDeCantos;
				double pProbabilidadeDeLinha;
				double pProbabilidadeDeLinhaDupla;
				double pProbabilidadeDeBingo;

			public:
				ProbabilidadesDaBolaExtra(DConfiguracao&);
				~ProbabilidadesDaBolaExtra();

				//retorna as probablidades de premiação
				double ProbabilidadesDaBolaExtra::probabilidade (int premio);
		};
	  }
	}
  }
}

#endif
