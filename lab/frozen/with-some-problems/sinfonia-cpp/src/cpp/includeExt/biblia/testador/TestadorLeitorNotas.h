/*
 * $RCSfile: TestadorLeitorNotas.h,v $
 * $Date: 2004/05/17 22:18:08 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */
/*
#ifndef TESTADOR_LEITOR_NOTAS_H
#define TESTADOR_LEITOR_NOTAS_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;


#include "biblia/io/noteiro/LeitorNotas.h"
#include "biblia/io/noteiro/LeitorNotasSmiles.h"
#include "biblia/io/noteiro/LeitorNotasJCM.h"
using namespace biblia::io::noteiro;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;


namespace biblia {
  namespace testador {

	class TestadorLeitorNotas: public TestadorComSaidaEmTexto {

		private:

			ChaveSeguranca* pChaveSeguranca;

			LeitorNotas* pLeitorNotas;

		public:
			TestadorLeitorNotas::TestadorLeitorNotas(FluxoDeTexto&);

			virtual TestadorLeitorNotas::~TestadorLeitorNotas();

			// Executavel
			virtual Executavel& TestadorLeitorNotas::executa();
	};
  }
}

#endif
*/