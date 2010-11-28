/*
 * $RCSfile: TempoExcecao.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TEMPOEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_TEMPOEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

namespace biblia {
  namespace tempo {
		class TempoExcecao
				:public Excecao
		{
			public:
				TempoExcecao::TempoExcecao() {}
		};

		class ValorNegativoTempoExcecao
				:public TempoExcecao
		{
			public:
				ValorNegativoTempoExcecao
						::ValorNegativoTempoExcecao() {}
		};

		class ValorExcedidoTempoExcecao
				:public TempoExcecao
		{
			public:
				ValorExcedidoTempoExcecao
						::ValorExcedidoTempoExcecao() {}
		};

		class MomentosDeUniversosDiferentesTempoExcecao
				:public TempoExcecao
		{
			public:
				MomentosDeUniversosDiferentesTempoExcecao
					::MomentosDeUniversosDiferentesTempoExcecao()
				{}
		};
  }
}

#endif // !defined(AFX_TEMPOEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
