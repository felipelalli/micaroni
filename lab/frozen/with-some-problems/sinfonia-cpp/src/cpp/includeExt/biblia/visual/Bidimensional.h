/*
 * $RCSfile: Bidimensional.h,v $
 * $Date: 2003/05/29 21:03:15 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BIDIMENSIONAL_H__773C66EF_EBE0_428F_9E9B_CE6C78C451EE__INCLUDED_)
#define AFX_BIDIMENSIONAL_H__773C66EF_EBE0_428F_9E9B_CE6C78C451EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/Ponto.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {

    /**
     * Quem deriva desta é porque ocupa uma
	 * determinada área num universo bidimensional (2d).
	 */
	class Bidimensional: public Interface {
		public:
			Bidimensional::Bidimensional();
			virtual Bidimensional::~Bidimensional();

			virtual Area Bidimensional
					::areaQueOcupa() const = 0;

			/**
			 * Retorna o ponto central da figura
			 * relativo ao universo 2d.
			 */
			virtual const Ponto& Bidimensional
					::centro() const;

			/**
			 * Retorna o ponto central da figura
			 * relativo a ela mesma.
			 */
			virtual const Ponto& Bidimensional
					::centroRelativo() const;

			/**
			 * Retorna o ponto inicial relativo ao
			 * universo 2d que deixará a Bidimensional
			 * passada como parâmetro centralizada neste
			 * Bidimensional.
			 */
			virtual const Ponto& Bidimensional
					::centro(const Bidimensional&) const;
	};
  }
}

#endif // !defined(AFX_BIDIMENSIONAL_H__773C66EF_EBE0_428F_9E9B_CE6C78C451EE__INCLUDED_)
