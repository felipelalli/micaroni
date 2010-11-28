/*
 * $RCSfile: Momento.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_MOMENTO_H__F5A1B985_0CFA_4622_BF78_0DEA64F881B1__INCLUDED_)
#define AFX_MOMENTO_H__F5A1B985_0CFA_4622_BF78_0DEA64F881B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/UltraLong.h"
#include "biblia/tempo/UniversoDeTempo.h"

using namespace biblia::basico;

namespace biblia {
  namespace tempo {

	/**
	 * Representa um momento num
	 * {@link biblia::tempo::UniversoDeTempo
	 * universo de tempo}.
	 * <p>
	 * <i>Um momento não é mensurável, é
	 * apenas um momento em algum universo.</i>
	 *
	 * @see biblia::tempo::Intervalo
	 */
	class Momento: public Objeto {
		private:
			UltraLong Momento::pMomento;
			const UniversoDeTempo* Momento::pUniverso;

		public:
			Momento::Momento(const UltraLong&,
				             const UniversoDeTempo&);

			Momento::Momento(const Momento&);

			virtual Momento::~Momento();

			/**
			 * Antes de.
			 */
			virtual bool Momento::operator<(const Momento&) const;

			/**
			 * Após.
			 */
			virtual bool Momento::operator>(const Momento&) const;

			/**
			 * Antes ou no mesmo momento de.
			 */
			virtual bool Momento::operator<=(const Momento&) const;

			/**
			 * Após ou no mesmo momento de.
			 */
			virtual bool Momento::operator>=(const Momento&) const;

			/**
			 * Mesmo momento de.
			 */
			virtual bool Momento::operator==(const Momento&) const;

			virtual const UltraLong& Momento
					::operator()() const;

			virtual Momento& Momento::proximoMomento(
					UltraLong quanto = UltraLong(1));

			virtual Momento& Momento
					::operator=(const Momento&);

			virtual const UniversoDeTempo& Momento
					::universo() const;

			virtual Momento& Momento
					::mudaUniverso(const UniversoDeTempo&);
	};
  }
}

#endif // !defined(AFX_MOMENTO_H__F5A1B985_0CFA_4622_BF78_0DEA64F881B1__INCLUDED_)
