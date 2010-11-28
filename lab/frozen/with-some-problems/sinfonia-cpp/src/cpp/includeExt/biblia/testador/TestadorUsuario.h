/*
 * $RCSfile: TestadorUsuario.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_USUARIO_H
#define TESTADOR_USUARIO_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/seguranca/Usuario.h"
using namespace biblia::seguranca;

#include "biblia/seguranca/util/TipoUsuario.h"
using namespace biblia::seguranca::util;


namespace biblia {

  namespace testador {

	class TestadorUsuario: public TestadorComSaidaEmTexto {

		private:
			Usuario* pUsuario;

		public:
			TestadorUsuario::TestadorUsuario(FluxoDeTexto&);

			virtual TestadorUsuario::~TestadorUsuario();

			Executavel& TestadorUsuario::executa();
	};
  }
}

#endif
