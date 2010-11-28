/*
 * $RCSfile: Posicionado.h,v $
 * $Date: 2004/10/07 17:34:47 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_POSICIONADO_H__B4F94EFF_F40E_4E07_9689_7F446C354C93__INCLUDED_)
#define AFX_POSICIONADO_H__B4F94EFF_F40E_4E07_9689_7F446C354C93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/visual/Ponto.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {

	/**
	 * Deriva desta {@link biblia::basico::Interface}
	 * todo aquele que pode ser posicionado num plano 2D.
	 */
	class Posicionado: public Interface {
		private:
			biblia::visual::Ponto Posicionado::pPosicao;

		protected:
			virtual Ponto& Posicionado::ponto();

		public:
			Posicionado::Posicionado(const Ponto&);
			Posicionado::Posicionado(const Posicionado&);

			virtual Posicionado::~Posicionado();
			virtual const Ponto&
					Posicionado::posicao() const;

			virtual Posicionado& Posicionado
					::reposiciona(const Ponto&);
	};
  }
}

#endif // !defined(AFX_POSICIONADO_H__B4F94EFF_F40E_4E07_9689_7F446C354C93__INCLUDED_)
