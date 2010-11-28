/*
 * $RCSfile: Dimensionavel.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_DIMENSIONAVEL_H__DA157C27_4DC1_41D3_AA94_4967E5C93BB4__INCLUDED_)
#define AFX_DIMENSIONAVEL_H__DA157C27_4DC1_41D3_AA94_4967E5C93BB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/visual/Tamanho.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {

	/**
	 * Deriva desta {@link biblia::basico::Interface}
	 * todo aquele que tem um tamanho.
	 */
	class Dimensionavel: public Interface {
		private:
			biblia::visual::Tamanho Dimensionavel::pTamanho;

		protected:
			Dimensionavel::Dimensionavel(const Tamanho&);
			Dimensionavel::Dimensionavel(const Dimensionavel&);

		public:
			virtual Dimensionavel::~Dimensionavel();
			virtual const Tamanho&
					Dimensionavel::tamanho() const;

			virtual Dimensionavel& Dimensionavel
					::redimensiona(const Tamanho&);
	};
  }
}

#endif // !defined(AFX_DIMENSIONAVEL_H__DA157C27_4DC1_41D3_AA94_4967E5C93BB4__INCLUDED_)
