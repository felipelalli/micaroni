/*
 * $RCSfile: TestadorPlacaIO.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_PLACAIO_H
#define TESTADOR_PLACAIO_H


#include "biblia/io/placaio/PlacaIO.h"
using namespace biblia::io::placaio;

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace testador {

	class TestadorPlacaIO: public TestadorComSaidaEmTexto {

		private:
			PlacaIO* pPlacaIO;

			void TestadorPlacaIO::pEscreverEstado (int estado);

		public:
			TestadorPlacaIO::TestadorPlacaIO(FluxoDeTexto&);

			virtual TestadorPlacaIO::~TestadorPlacaIO();

			// Executavel
			virtual Executavel& TestadorPlacaIO::executa();
	};
  }
}

#endif
