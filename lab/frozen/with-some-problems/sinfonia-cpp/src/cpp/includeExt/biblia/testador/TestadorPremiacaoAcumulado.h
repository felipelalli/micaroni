/*
 * $RCSfile: TestadorPremiacaoAcumulado.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_PREMIACAO_ACUMULADO_H
#define TESTADOR_PREMIACAO_ACUMULADO_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/jogos/superbonus/logica/LogicaAcumulado.h"
#include "biblia/jogos/superbonus/logica/ProbabilidadesDoJogo.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
using namespace biblia::jogos::superbonus::dados;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;


namespace biblia {
  namespace testador {

	class TestadorPremiacaoAcumulado: public TestadorComSaidaEmTexto {

		private:

			DConfiguracao* pDConfiguracao;

			ProbabilidadesDoJogo* pProbabilidadesJogo;

		public:
			TestadorPremiacaoAcumulado::TestadorPremiacaoAcumulado(FluxoDeTexto&);

			virtual TestadorPremiacaoAcumulado::~TestadorPremiacaoAcumulado();

			// Executavel
			virtual Executavel& TestadorPremiacaoAcumulado::executa();
	};
  }
}

#endif
