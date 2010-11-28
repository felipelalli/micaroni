/*
 * $RCSfile: IOExcecao.h,v $
 * $Date: 2004/01/28 23:46:59 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_IOExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_IOExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

namespace biblia {
  namespace io {
		class IOExcecao
				:public Excecao
		{
			public:
				IOExcecao::IOExcecao() {}
		};
  }
}

#endif // !defined(AFX_IOExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
