/*
 * $RCSfile: Paginas.h,v $
 * $Date: 2005/01/20 21:29:46 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_PAGINAS_H__F1665B1F_3008_4E24_8181_74F3FE8FDF7D__INCLUDED_)
#define AFX_PAGINAS_H__F1665B1F_3008_4E24_8181_74F3FE8FDF7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class Paginas: public Componente {
			private:
				int Paginas::pPaginaAtual;

			public:
				Paginas::Paginas();
				virtual Paginas::~Paginas();
				virtual Componente& Paginas::paginaAtual();
				virtual const Componente& Paginas::paginaAtual() const;
				virtual Paginas& Paginas::proxima();
				virtual Paginas& Paginas::anterior();
				virtual Componente& Paginas::vaiPara(const std::string& filho);
		};
	}
  }
}

#endif // !defined(AFX_PAGINAS_H__F1665B1F_3008_4E24_8181_74F3FE8FDF7D__INCLUDED_)
