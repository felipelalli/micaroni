/*
 * $RCSfile: CapturadorDeTela.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CAPTURADORDETELA_H__B4B893E9_D0F3_4CE6_BC97_2FBBA0B670B4__INCLUDED_)
#define AFX_CAPTURADORDETELA_H__B4B893E9_D0F3_4CE6_BC97_2FBBA0B670B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/io/monitor/Tela.h"

using namespace biblia::basico;
using namespace biblia::visual;
using namespace biblia::io::monitor;

namespace biblia {
  namespace io {
  	namespace monitor {

		/**
		 * É responsável por gerar uma
		 * {@link biblia::io::monitor::Tela}.
		 */
		class CapturadorDeTela: public Interface {
			protected:
				CapturadorDeTela::CapturadorDeTela() {};

			public:
				virtual CapturadorDeTela::~CapturadorDeTela() {};
				virtual Tela* CapturadorDeTela
						::capturaTela(const Tamanho& resolucao) = 0;
		};
	}
  }
}

#endif // !defined(AFX_CAPTURADORDETELA_H__B4B893E9_D0F3_4CE6_BC97_2FBBA0B670B4__INCLUDED_)
