/*
 * $RCSfile: Unicolor.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_UNICOLOR_H__B4F94EFF_F40E_4E07_9689_7F446C354C93__INCLUDED_)
#define AFX_UNICOLOR_H__B4F94EFF_F40E_4E07_9689_7F446C354C93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/visual/Cor.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {

	/**
	 * Deriva desta {@link biblia::basico::Interface}
	 * todo aquele que tem apenas uma cor.
	 */
	class Unicolor: public Interface {
		private:
			biblia::visual::Cor Unicolor::pCor;

		protected:
			Unicolor::Unicolor(const Cor&);
			Unicolor::Unicolor(const Unicolor&);

		public:
			virtual Unicolor::~Unicolor();
			virtual const Cor& Unicolor::cor() const;
			virtual Unicolor& Unicolor::pinta(const Cor&);
	};
  }
}

#endif // !defined(AFX_UNICOLOR_H__B4F94EFF_F40E_4E07_9689_7F446C354C93__INCLUDED_)
