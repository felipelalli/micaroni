/*
 * $RCSfile: TestadorDeTemporizador.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADORDETEMPORIZADOR_H__946D9FAB_46FB_47B7_9499_822E4B278D78__INCLUDED_)
#define AFX_TESTADORDETEMPORIZADOR_H__946D9FAB_46FB_47B7_9499_822E4B278D78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/testador/TestadorComSaidaEmTexto.h"
#include "biblia/tempo/Temporizador.h"
#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"

using namespace biblia::tempo;

namespace biblia {
  namespace testador {

	class TestadorDeTemporizador: public TestadorComSaidaEmTexto {
		private:
			Temporizador& TestadorDeTemporizador
					::pTemporizador;

		protected:
			virtual Temporizador& TestadorDeTemporizador
					::temporizador();

		public:
			TestadorDeTemporizador::TestadorDeTemporizador(
					FluxoDeTexto&, Temporizador&);

			virtual TestadorDeTemporizador::~TestadorDeTemporizador();

			// Executavel:
			virtual Executavel& TestadorDeTemporizador::executa();
	};
  }
}

#endif // !defined(AFX_TESTADORDETEMPORIZADOR_H__946D9FAB_46FB_47B7_9499_822E4B278D78__INCLUDED_)
