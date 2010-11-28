/*
 * $RCSfile: TestadorFormulaMatematica.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_FORMULA_MATEMATICA_H
#define TESTADOR_FORMULA_MATEMATICA_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;


#include "biblia/jogos/superbonus/logica/FormulaMatematica.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;


namespace biblia {
  namespace testador {

	class TestadorFormulaMatematica: public TestadorComSaidaEmTexto {

		private:

			FormulaMatematica* pFormula;

		public:
			TestadorFormulaMatematica::TestadorFormulaMatematica(FluxoDeTexto&);

			virtual TestadorFormulaMatematica::~TestadorFormulaMatematica();

			// Executavel
			virtual Executavel& TestadorFormulaMatematica::executa();
	};
  }
}

#endif
