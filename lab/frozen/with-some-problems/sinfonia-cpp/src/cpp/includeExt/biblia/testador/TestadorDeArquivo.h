/*
 * $RCSfile: TestadorDeArquivo.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADORDEARQUIVO_H__FC2D236D_E488_4FED_B0A8_D391773EF5FF__INCLUDED_)
#define AFX_TESTADORDEARQUIVO_H__FC2D236D_E488_4FED_B0A8_D391773EF5FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/disco/Arquivo.h"
#include "biblia/testador/TestadorComSaidaEmTexto.h"

using namespace biblia::io::disco;

namespace biblia {
  namespace testador {
	class TestadorDeArquivo: public TestadorComSaidaEmTexto {
		private:
			Arquivo& TestadorDeArquivo::arquivo;

		public:
			TestadorDeArquivo::TestadorDeArquivo(
					FluxoDeTexto&, Arquivo&);

			virtual TestadorDeArquivo::~TestadorDeArquivo();

			// Executavel:
			virtual Executavel& TestadorDeArquivo::executa();
	};
  }
}

#endif // !defined(AFX_TESTADORDEARQUIVO_H__FC2D236D_E488_4FED_B0A8_D391773EF5FF__INCLUDED_)
