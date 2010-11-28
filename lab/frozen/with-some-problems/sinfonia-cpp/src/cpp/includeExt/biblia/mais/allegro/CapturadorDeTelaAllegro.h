/*
 * $RCSfile: CapturadorDeTelaAllegro.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#include "biblia/mais/allegro/Allegro.h"

#if !defined(AFX_CAPTURADORDETELAALLEGRO_H__580EDAE4_3825_4FDA_8991_8A9C024D6A70__INCLUDED_)
#define AFX_CAPTURADORDETELAALLEGRO_H__580EDAE4_3825_4FDA_8991_8A9C024D6A70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/monitor/CapturadorDeTela.h"
#include "biblia/io/monitor/Tela.h"
#include "biblia/visual/Tamanho.h"

using namespace biblia::io::monitor;
using namespace biblia::visual;

namespace biblia {
  namespace mais {
 	namespace allegro {

		class CapturadorDeTelaAllegro: public CapturadorDeTela {
			public:
				CapturadorDeTelaAllegro
						::CapturadorDeTelaAllegro();

				virtual CapturadorDeTelaAllegro
						::~CapturadorDeTelaAllegro();

				virtual Tela* CapturadorDeTelaAllegro
						::capturaTela(const Tamanho& resolucao);
		};
	}
  }
}

#endif // !defined(AFX_CAPTURADORDETELAALLEGRO_H__580EDAE4_3825_4FDA_8991_8A9C024D6A70__INCLUDED_)
