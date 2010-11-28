/*
 * $RCSfile: TestadorCompactacao.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_COMPACTACAO_H
#define TESTADOR_COMPACTACAO_H

#include "biblia/compactacao/CompactadorGZip.h"
using namespace biblia::compactacao;

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace testador {

	class TestadorCompactacao: public TestadorComSaidaEmTexto {

		private:

			ChaveSeguranca* pChaveSeguranca;

		public:
			TestadorCompactacao::TestadorCompactacao(FluxoDeTexto&);

			virtual TestadorCompactacao::~TestadorCompactacao();

			// Executavel
			virtual Executavel& TestadorCompactacao::executa();
	};
  }
}

#endif
