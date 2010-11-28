/*
 * $RCSfile: TestadorPlacaLoddy.h,v $
 * $Date: 2003/06/02 18:27:50 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef TESTADOR_PLACALODDY_H
#define TESTADOR_PLACALODDY_H


#include "biblia/io/placaloddy/PlacaLoddy.h"
using namespace biblia::io::placaloddy;

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace testador {

	class TestadorPlacaLoddy: public TestadorComSaidaEmTexto {

		private:
			PlacaLoddy* pPlacaLoddy;			

		public:
			TestadorPlacaLoddy::TestadorPlacaLoddy(FluxoDeTexto&);

			virtual TestadorPlacaLoddy::~TestadorPlacaLoddy();

			// Executavel
			virtual Executavel& TestadorPlacaLoddy::executa();
	};
  }
}

#endif
