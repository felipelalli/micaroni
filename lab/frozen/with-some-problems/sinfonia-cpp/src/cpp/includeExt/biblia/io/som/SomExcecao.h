/*
 * $RCSfile: SomExcecao.h,v $
 * $Date: 2004/04/07 20:16:20 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_SOMEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_SOMEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

namespace biblia {
  namespace io {
    namespace som {
		class SomExcecao
				:public Excecao
		{
			protected:
				SomExcecao::SomExcecao() {}
		};

		class VolumeForaDeIntervaloExcecao
				:public SomExcecao
		{
			public:
				VolumeForaDeIntervaloExcecao
						::VolumeForaDeIntervaloExcecao() {}
		};

		class ResultadoSonoroNaoDefinidoExcecao
				:public SomExcecao
		{
			public:
				ResultadoSonoroNaoDefinidoExcecao
						::ResultadoSonoroNaoDefinidoExcecao() {}
		};

		class NaoHaSomParaConsumirExcecao
				:public SomExcecao
		{
			public:
				NaoHaSomParaConsumirExcecao
						::NaoHaSomParaConsumirExcecao() {}
		};

		class SomNaoDefinidoExcecao: public SomExcecao {
			public:
				SomNaoDefinidoExcecao
						::SomNaoDefinidoExcecao() {}
		};
	}
  }
}

#endif // !defined(AFX_SOMEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
