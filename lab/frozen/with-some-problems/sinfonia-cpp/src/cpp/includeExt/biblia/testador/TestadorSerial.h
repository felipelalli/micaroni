/*
 * $RCSfile: TestadorSerial.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_SERIAL_H
#define TESTADOR_SERIAL_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/io/serial/Com.h"
using namespace biblia::io::serial;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;


namespace biblia {

  namespace testador {

	class TestadorSerial: public TestadorComSaidaEmTexto {

		private:
			Com* pCom;

		public:
			TestadorSerial::TestadorSerial(FluxoDeTexto&);

			virtual TestadorSerial::~TestadorSerial();

			Executavel& TestadorSerial::executa();
	};
  }
}

#endif
