/*
 * $RCSfile: AnimacaoUtilExcecao.h,v $
 * $Date: 2003/05/29 21:00:03 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_ANIMACAOUTILEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_ANIMACAOUTILEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/animacao/AnimacaoExcecao.h"

using namespace biblia::basico;
using namespace biblia::visual::animacao;

namespace biblia {
  namespace visual {
	namespace animacao {
	  namespace util {
		class AnimacaoUtilExcecao
				:public AnimacaoExcecao
		{
			protected:
				AnimacaoUtilExcecao::AnimacaoUtilExcecao() {}
		};

		class ArquivoDeAreasInvalidoExcecao
				:public AnimacaoUtilExcecao
		{
			public:
				ArquivoDeAreasInvalidoExcecao
						::ArquivoDeAreasInvalidoExcecao() {}
		};
	  }
	}
  }
}

#endif // !defined(AFX_ANIMACAOUTILEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
