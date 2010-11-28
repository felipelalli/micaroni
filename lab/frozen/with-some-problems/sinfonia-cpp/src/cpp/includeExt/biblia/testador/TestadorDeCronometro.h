/*
 * $RCSfile: TestadorDeCronometro.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADORDECRONOMETRO_H__93CC315B_6E8A_4F99_8CFB_142D2A15271C__INCLUDED_)
#define AFX_TESTADORDECRONOMETRO_H__93CC315B_6E8A_4F99_8CFB_142D2A15271C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/testador/TestadorComSaidaEmTexto.h"
#include "biblia/io/texto/FluxoDeTexto.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/unidades/Segundo.h"

using namespace biblia::io::texto;

namespace biblia {
  namespace testador {

	class TestadorDeCronometro: public TestadorComSaidaEmTexto {
		private:
			Cronometro& TestadorDeCronometro
					::pCronometro;

		protected:
			virtual Cronometro& TestadorDeCronometro
					::cronometro();

		public:
			TestadorDeCronometro::TestadorDeCronometro(
					FluxoDeTexto&, Cronometro&);

			virtual TestadorDeCronometro
					::~TestadorDeCronometro();

			// Executavel:
			virtual Executavel& TestadorDeCronometro::executa();
	};
  }
}

#endif // !defined(AFX_TESTADORDECRONOMETRO_H__93CC315B_6E8A_4F99_8CFB_142D2A15271C__INCLUDED_)
