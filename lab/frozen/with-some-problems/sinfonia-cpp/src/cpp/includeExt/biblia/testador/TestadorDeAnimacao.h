/*
 * $RCSfile: TestadorDeAnimacao.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADORDEANIMACAO_H__4A91C0C6_1D4F_462E_ABF4_EBA8F79CA6F6__INCLUDED_)
#define AFX_TESTADORDEANIMACAO_H__4A91C0C6_1D4F_462E_ABF4_EBA8F79CA6F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/monitor/TelaComFundo.h"
#include "biblia/io/texto/FluxoDeTexto.h"
#include "biblia/sorte/Sorteio.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/HardwareClockTicks.h"
#include "biblia/visual/geometricos/Retangulo.h"
#include "biblia/visual/animacao/Video.h"
#include "biblia/visual/animacao/AnimacaoDeImagens.h"
#include "biblia/testador/TestadorComSaidaEmTexto.h"

using namespace biblia::tempo;
using namespace biblia::sorte;
using namespace biblia::tempo::unidades;
using namespace biblia::io::monitor;
using namespace biblia::visual::animacao;

namespace biblia {
  namespace testador {

	class TestadorDeAnimacao: public TestadorComSaidaEmTexto {
		private:
			Cronometro TestadorDeAnimacao::pTempo;
			Video* TestadorDeAnimacao::pVideo1, *pVideo2, *pVideo3;
			TelaComFundo& TestadorDeAnimacao::pTela;

		protected:
			Cronometro& TestadorDeAnimacao::tempo();
			Video& TestadorDeAnimacao::video(int qual);
			TelaComFundo& TestadorDeAnimacao::tela();

			// Ações:
			TestadorDeAnimacao& TestadorDeAnimacao::anda();
			TestadorDeAnimacao& TestadorDeAnimacao::louco();
			TestadorDeAnimacao& TestadorDeAnimacao::batendo();

		public:
			TestadorDeAnimacao::TestadorDeAnimacao(
					FluxoDeTexto&, TelaComFundo&,
					const UniversoDeTempo&,
					AnimacaoDeImagens& a1,
					AnimacaoDeImagens& a2,
					AnimacaoDeImagens& a3);

			virtual TestadorDeAnimacao::~TestadorDeAnimacao();

			// Executavel:
			virtual Executavel& TestadorDeAnimacao::executa();
	};
  }
}

#endif // !defined(AFX_TESTADORDEANIMACAO_H__4A91C0C6_1D4F_462E_ABF4_EBA8F79CA6F6__INCLUDED_)
