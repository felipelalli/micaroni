/*
 * $RCSfile: Vitrola.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_VITROLA_H__059AA28D_B5A5_4E6B_9CCD_02C036913537__INCLUDED_)
#define AFX_VITROLA_H__059AA28D_B5A5_4E6B_9CCD_02C036913537__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/Debug.h"
#include "biblia/logica/Realizador.h"
#include "biblia/io/som/Som.h"
#include "biblia/io/som/ResultadoSonoro.h"

using namespace biblia::util;
using namespace biblia::logica;

namespace biblia {
  namespace io {
    namespace som {

		class Vitrola: public Realizador {
			private:
				ResultadoSonoro* Vitrola::pResultado;
				Som* Vitrola::pSomPadrao;

			protected:
				ResultadoSonoro& Vitrola::resultado();

			public:
				Vitrola::Vitrola(ResultadoSonoro* = NULL);
				virtual Vitrola::~Vitrola();

				virtual Vitrola& Vitrola
						::outroResultado(ResultadoSonoro*);

				// Realizador:
				virtual Executavel& Vitrola::executa();
		};
	}
  }
}

#endif // !defined(AFX_VITROLA_H__059AA28D_B5A5_4E6B_9CCD_02C036913537__INCLUDED_)
