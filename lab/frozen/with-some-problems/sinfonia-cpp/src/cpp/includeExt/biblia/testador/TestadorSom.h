/*
 * $RCSfile: TestadorSom.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_SOM_H
#define TESTADOR_SOM_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/mais/fmod/FMod.h"
using namespace biblia::mais::fmod;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;


namespace biblia {

  namespace testador {

	class TestadorSom: public TestadorComSaidaEmTexto {

		private:
			FMod* pSom;

		public:
			TestadorSom::TestadorSom(FluxoDeTexto&);

			virtual TestadorSom::~TestadorSom();

			Executavel& TestadorSom::executa();
	};
  }
}

#endif
