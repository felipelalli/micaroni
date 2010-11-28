/*
 * $RCSfile: TestadorComSaidaEmTexto.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADORCOMSAIDAEMTEXTO_H__099459CC_91B0_446D_84D9_14B66DB3E839__INCLUDED_)
#define AFX_TESTADORCOMSAIDAEMTEXTO_H__099459CC_91B0_446D_84D9_14B66DB3E839__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/testador/Testador.h"
#include "biblia/io/texto/FluxoDeTexto.h"

using namespace biblia::io::texto;

namespace biblia {
  namespace testador {

	class TestadorComSaidaEmTexto: public Testador {
		private:
			FluxoDeTexto& TestadorComSaidaEmTexto
					::pSaida;

		protected:
			TestadorComSaidaEmTexto
					::TestadorComSaidaEmTexto(FluxoDeTexto&);

		public:
			virtual TestadorComSaidaEmTexto
					::~TestadorComSaidaEmTexto();

			virtual FluxoDeTexto& TestadorComSaidaEmTexto
					::saida();
	};
  }
}

#endif // !defined(AFX_TESTADORCOMSAIDAEMTEXTO_H__099459CC_91B0_446D_84D9_14B66DB3E839__INCLUDED_)
