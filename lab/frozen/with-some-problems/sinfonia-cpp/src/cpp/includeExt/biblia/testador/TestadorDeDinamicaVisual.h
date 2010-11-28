/*
 * $RCSfile: TestadorDeDinamicaVisual.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADORDEDINAMICAVISUAL_H__40CE7BA9_38A3_43A2_A46E_7237CD6595C6__INCLUDED_)
#define AFX_TESTADORDEDINAMICAVISUAL_H__40CE7BA9_38A3_43A2_A46E_7237CD6595C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/testador/TestadorComSaidaEmTexto.h"
#include "biblia/io/texto/FluxoDeTexto.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/dinamica/DesenhistaDeResultadoGraficoNaTela.h"
#include "biblia/visual/dinamica/ResultadoGrafico.h"
#include "biblia/visual/cores/Transparente.h"
#include "biblia/visual/fonte/TextoComFonte.h"
#include "biblia/visual/Ponto.h"

using namespace biblia::io::texto;
using namespace biblia::tempo;
using namespace biblia::tempo::unidades;
using namespace biblia::visual::dinamica;
using namespace biblia::visual::cores;

namespace biblia {
  namespace testador {

	class TestadorDeDinamicaVisual: public TestadorComSaidaEmTexto {
		private:
			BasicoVisual& TestadorDeDinamicaVisual::pVisual;

		protected:
			BasicoVisual& TestadorDeDinamicaVisual::visual();
			TestadorDeDinamicaVisual& TestadorDeDinamicaVisual
					::testaImagem();

			TestadorDeDinamicaVisual& TestadorDeDinamicaVisual
					::testaAnimacao();

			TestadorDeDinamicaVisual& TestadorDeDinamicaVisual
					::testaFonte();

			ResultadoGrafico TestadorDeDinamicaVisual::rg;
			DesenhistaDeResultadoGraficoNaTela
					TestadorDeDinamicaVisual::drg;

		public:
			TestadorDeDinamicaVisual
					::TestadorDeDinamicaVisual(
							FluxoDeTexto&, BasicoVisual&);

			virtual TestadorDeDinamicaVisual
					::~TestadorDeDinamicaVisual();

			// Executavel
			virtual Executavel& TestadorDeDinamicaVisual::executa();
	};
  }
}

#endif // !defined(AFX_TESTADORDEDINAMICAVISUAL_H__40CE7BA9_38A3_43A2_A46E_7237CD6595C6__INCLUDED_)
