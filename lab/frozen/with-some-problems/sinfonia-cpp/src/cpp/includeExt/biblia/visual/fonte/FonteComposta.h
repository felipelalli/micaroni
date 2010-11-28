/*
 * $RCSfile: FonteComposta.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_FONTECOMPOSTA_H__4E105C88_F5B0_43A5_831C_5C417BD5C192__INCLUDED_)
#define AFX_FONTECOMPOSTA_H__4E105C88_F5B0_43A5_831C_5C417BD5C192__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include "biblia/basico/Objeto.h"
#include "biblia/visual/fonte/FonteImagem.h"
#include "biblia/visual/fonte/FonteVetorial.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {
    namespace fonte {

		/**
		 * Contém uma fonte de imagem e uma fonte vetorial
		 * da mesma espécie (mesmo tipo, mesma família ou idêntica)
		 * e cada uma será usada dependendo de seu tamanho ou
		 * necessidade específica.
		 */
		class FonteComposta: public Objeto {
			private:
				FonteImagem& FonteComposta::pFonteImagem;
				FonteVetorial& FonteComposta::pFonteVetorial;

			public:
				FonteComposta::FonteComposta(
						FonteImagem&, FonteVetorial&);

				virtual FonteComposta::~FonteComposta();

				virtual FonteImagem& FonteComposta::fonteImagem();
				virtual FonteVetorial& FonteComposta::fonteVetorial();
		};
	}
  }
}

#endif // !defined(AFX_FONTECOMPOSTA_H__4E105C88_F5B0_43A5_831C_5C417BD5C192__INCLUDED_)
