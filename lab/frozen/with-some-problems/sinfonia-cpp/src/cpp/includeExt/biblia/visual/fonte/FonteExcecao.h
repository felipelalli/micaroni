/*
 * $RCSfile: FonteExcecao.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_FONTEEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_FONTEEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/VisualExcecao.h"
using namespace biblia::visual;

namespace biblia {
  namespace visual {
	namespace fonte {
		class FonteExcecao
				:public VisualExcecao
		{
			protected:
				FonteExcecao::FonteExcecao() {}
		};

		class FonteWizardExcecao
				:public FonteExcecao
		{
			protected:
				FonteWizardExcecao::FonteWizardExcecao() {}
		};

		class LetraNaoAssociadaExcecao
				:public FonteExcecao
		{
			public:
				LetraNaoAssociadaExcecao
						::LetraNaoAssociadaExcecao() {}
		};

		class ParametrosInvalidosExcecao
				:public FonteWizardExcecao
		{
			public:
				ParametrosInvalidosExcecao
						::ParametrosInvalidosExcecao() {}
		};

		class ParametrosNaoDefinidosExcecao
				:public FonteWizardExcecao
		{
			public:
				ParametrosNaoDefinidosExcecao
						::ParametrosNaoDefinidosExcecao() {}
		};
	}
  }
}

#endif // !defined(AFX_FONTEEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
