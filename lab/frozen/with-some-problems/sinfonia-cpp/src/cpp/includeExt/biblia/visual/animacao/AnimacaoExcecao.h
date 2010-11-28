/*
 * $RCSfile: AnimacaoExcecao.h,v $
 * $Date: 2003/05/29 21:00:03 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_ANIMACAOEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_ANIMACAOEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/VisualExcecao.h"

using namespace biblia::basico;
using namespace std;

namespace biblia {
  namespace visual {
	namespace animacao {
		class AnimacaoExcecao
				:public VisualExcecao
		{
			public:
				AnimacaoExcecao::AnimacaoExcecao() {}
		};

		class NaoContemImagensAnimacaoExcecao
				:public AnimacaoExcecao
		{
			public:
				NaoContemImagensAnimacaoExcecao
						::NaoContemImagensAnimacaoExcecao() {}
		};

		class QuadroForaDeIntervaloAnimacaoExcecao
				:public AnimacaoExcecao
		{
			public:
				QuadroForaDeIntervaloAnimacaoExcecao
						::QuadroForaDeIntervaloAnimacaoExcecao() {}
		};
	}
  }
}

#endif // !defined(AFX_ANIMACAOEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
