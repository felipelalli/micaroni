/*
 * $RCSfile: TestadorDeVisual.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADORDEVISUAL_H__4E62296D_8365_4ACA_BE1F_C3D4CB0B1068__INCLUDED_)
#define AFX_TESTADORDEVISUAL_H__4E62296D_8365_4ACA_BE1F_C3D4CB0B1068__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <cmath>
#include "biblia/testador/TestadorComSaidaEmTexto.h"
#include "biblia/fluxo/Processo.h"
#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/io/disco/DiscoExcecao.h"
#include "biblia/io/texto/FluxoDeTexto.h"
#include "biblia/io/monitor/TelaComFundo.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/geometricos/Linha.h"
#include "biblia/visual/geometricos/Circulo.h"
#include "biblia/visual/geometricos/Retangulo.h"
#include "biblia/visual/cores/Amarelo.h"
#include "biblia/visual/cores/Magenta.h"
#include "biblia/visual/cores/Vermelho.h"
#include "biblia/visual/cores/Transparente.h"

using namespace biblia::fluxo;
using namespace biblia::tempo::unidades;
using namespace biblia::io::texto;
using namespace biblia::io::monitor;
using namespace biblia::io::disco;
using namespace biblia::visual::imagem2d;

namespace biblia {
  namespace testador {

	/**
	 * Testa as classes visuais e também
	 * a de tela.
	 *
	 * @todo Não está muito completo, mas
	 *       dá pra quebrar um galho por enquanto.
	 */
	class TestadorDeVisual: public TestadorComSaidaEmTexto {
		private:
			TelaComFundo& TestadorDeVisual
					::pTela;

			FabricaDeImagens& TestadorDeVisual
					::pFabricaDeImagens;

			// Interno:
			Imagem* TestadorDeVisual::pFundo;

		protected:
			virtual TelaComFundo& TestadorDeVisual
					::tela();

			virtual FabricaDeImagens& TestadorDeVisual
					::fabricaDeImagens();

			// Etapas do teste:
			virtual TestadorDeVisual& TestadorDeVisual
					::testaGeometricos();

			virtual TestadorDeVisual& TestadorDeVisual
					::testaImagens(bool comEfeitos = false);

			virtual TestadorDeVisual& TestadorDeVisual
					::testaEfeitos();

		public:
			TestadorDeVisual::TestadorDeVisual(
					TelaComFundo&,
					FabricaDeImagens&,
					FluxoDeTexto&);

			virtual TestadorDeVisual::~TestadorDeVisual();

			// Executavel:
			virtual Executavel& TestadorDeVisual::executa();
	};
  }
}

#endif // !defined(AFX_TESTADORDEVISUAL_H__4E62296D_8365_4ACA_BE1F_C3D4CB0B1068__INCLUDED_)
