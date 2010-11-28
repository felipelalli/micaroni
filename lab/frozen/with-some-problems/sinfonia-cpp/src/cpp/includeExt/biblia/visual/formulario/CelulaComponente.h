/*
 * $RCSfile: CelulaComponente.h,v $
 * $Date: 2003/05/29 21:08:20 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CELULACOMPONENTE_H__F71B485D_3349_4F47_8748_881DE2B5CB05__INCLUDED_)
#define AFX_CELULACOMPONENTE_H__F71B485D_3349_4F47_8748_881DE2B5CB05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"

namespace biblia {
  namespace visual {
    namespace formulario {
		/**
		 * Seu tamanho depende da Tabela.
		 */
		class Celula: public Componente {
			public:
				Celula::Celula();
				virtual Celula::~Celula();
		};
	}
  }
}

#endif // !defined(AFX_CELULACOMPONENTE_H__F71B485D_3349_4F47_8748_881DE2B5CB05__INCLUDED_)
