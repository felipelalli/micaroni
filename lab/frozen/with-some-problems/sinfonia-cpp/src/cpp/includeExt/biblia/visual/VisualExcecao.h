/*
 * $RCSfile: VisualExcecao.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_VISUALEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_VISUALEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
#include <stdexcept>

using namespace biblia::basico;
using namespace std;

namespace biblia {
  namespace visual {
		class VisualExcecao
				:public Excecao
		{
			public:
				VisualExcecao::VisualExcecao() {}
		};

		class GeometricoNaoSuportadoExcecao
				:public VisualExcecao
		{
			public:
				GeometricoNaoSuportadoExcecao
						::GeometricoNaoSuportadoExcecao() {}
		};

		class TipoGeometricoIndefinido
				:public VisualExcecao
		{
			public:
				TipoGeometricoIndefinido
						::TipoGeometricoIndefinido() {}
		};

		class CorNaoSuportadaVisualExcecao
				:public VisualExcecao
		{
			public:
				CorNaoSuportadaVisualExcecao
						::CorNaoSuportadaVisualExcecao() {}
		};

		class ForaDeIntervaloVisualExcecao
				:public VisualExcecao
		{
			public:
				ForaDeIntervaloVisualExcecao
						::ForaDeIntervaloVisualExcecao() {}
		};

		class LimiteExcedidoVisualExcecao
				:public ForaDeIntervaloVisualExcecao
		{
			public:
				LimiteExcedidoVisualExcecao
						::LimiteExcedidoVisualExcecao() {}
		};

		class ValorNegativoVisualExcecao
				:public ForaDeIntervaloVisualExcecao
		{
			public:
				ValorNegativoVisualExcecao
						::ValorNegativoVisualExcecao() {}
		};

		class TamanhoNaoCabivelExcecao
				:public VisualExcecao
		{
			public:
				TamanhoNaoCabivelExcecao
						::TamanhoNaoCabivelExcecao()
				{}
		};

		class OperacaoNaoSuportadaExcecao
				:public VisualExcecao
		{
			public:
				OperacaoNaoSuportadaExcecao
						::OperacaoNaoSuportadaExcecao()
				{}
		};
  }
}

#endif // !defined(AFX_VISUALEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
