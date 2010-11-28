/*
 * $RCSfile: Raio.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_RAIO_H__934FB87C_4D5D_48A6_A186_AF3E2378EF95__INCLUDED_)
#define AFX_RAIO_H__934FB87C_4D5D_48A6_A186_AF3E2378EF95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/visual/VisualExcecao.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {
	class Raio: public Objeto {
		private:
			int Raio::pRaio;

		public:
			Raio::Raio();
			Raio::Raio(const int&);

			Raio::Raio(const Raio&);
			virtual Raio::~Raio();

			virtual const int& Raio::operator()() const;
			virtual Raio& Raio::operator=(const Raio&);
			virtual bool Raio::operator==(const Raio&) const;
	};
  }
}

#endif // !defined(AFX_RAIO_H__934FB87C_4D5D_48A6_A186_AF3E2378EF95__INCLUDED_)
