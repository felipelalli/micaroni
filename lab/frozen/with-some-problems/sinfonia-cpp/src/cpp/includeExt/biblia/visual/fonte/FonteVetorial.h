/*
 * $RCSfile: FonteVetorial.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_FONTEVETORIAL_H__A5852D54_1627_45FA_8F3E_565B42EA119D__INCLUDED_)
#define AFX_FONTEVETORIAL_H__A5852D54_1627_45FA_8F3E_565B42EA119D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace visual {
    namespace fonte {

		/**
		 * Esta classe possui informações vetoriais
		 * necessárias para desenhar caracteres
		 * independentes.
		 *
		 * @todo Desenvolver esta classe
		 *       com informações vetoriais.
		 */
		class FonteVetorial: public Objeto {
			public:
				FonteVetorial::FonteVetorial();
				virtual FonteVetorial::~FonteVetorial();
		};
	}
  }
}

#endif // !defined(AFX_FONTEVETORIAL_H__A5852D54_1627_45FA_8F3E_565B42EA119D__INCLUDED_)
