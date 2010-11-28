/*
 * $RCSfile: AllegroExcecao.h,v $
 * $Date: 2003/05/29 21:00:03 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_AllegroExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_AllegroExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/mais/MaisExcecao.h"

using namespace biblia::basico;

namespace biblia {
  namespace mais {
	namespace allegro {
		class AllegroExcecao
				:public MaisExcecao
		{
			public:
				AllegroExcecao::AllegroExcecao() {}
		};

		class NaoImplementadoAllegroExcecao
				:public AllegroExcecao
		{
			public:
				NaoImplementadoAllegroExcecao
						::NaoImplementadoAllegroExcecao() {}
		};

		class BasicoVisualExcecao
				:public AllegroExcecao
		{
			public:
				BasicoVisualExcecao
						::BasicoVisualExcecao() {}
		};
	}
  }
}

#endif // !defined(AFX_AllegroExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
