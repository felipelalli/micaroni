/*
 * $RCSfile: UniversoDeTempo.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#include "biblia/tempo/Momento.h"

#if !defined(AFX_UNIVERSODETEMPO_H__430A79F2_2C51_4D79_BDE8_0EFEB9B7A3BD__INCLUDED_)
#define AFX_UNIVERSODETEMPO_H__430A79F2_2C51_4D79_BDE8_0EFEB9B7A3BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/tempo/UnidadeDeTempo.h"

using namespace biblia::basico;

namespace biblia {
  namespace tempo {

	class Momento;

	/**
	 * Representa um universo de tempo que fornece
	 * um momento a partir da função {@link #agora()}.
	 * É possível também descobrir em que {@link
	 * biblia::tempo::UnidadeDeTempo unidade de
	 * tempo} este universo de tempo progride.
	 * <p>
	 * Para operações com {@link biblia::tempo::Intervalo
	 * intervalo de tempo} e com {@link biblia::tempo::Momento
	 * momentos} é necessário compatibilidade de universos.
	 * <p>
	 * <i>Obs.: A classe {@link biblia::tempo::Momento}
	 * conhece esta classe e é tão ligada a ela que
	 * poderia até ser uma classe interna desta.</i>
	 *
	 * @see biblia::tempo::Momento
	 * @see biblia::tempo::Intervalo
	 * @see biblia::tempo::UnidadeDeTempo
	 */
	class UniversoDeTempo: public Interface {
		protected:
			UniversoDeTempo::UniversoDeTempo();

		public:
			virtual UniversoDeTempo::~UniversoDeTempo();

			/**
			 * Retorna um {@link biblia::tempo::UltraLong}
			 * representando o tempo de agora.
			 */
			virtual Momento UniversoDeTempo::agora() const = 0;

			/**
			 * Em que {@link biblia::tempo::UnidadeDeTempo
			 * unidade de tempo} este TempoGlobal dá seus
			 * passos.
			 */
			virtual const UnidadeDeTempo&
					UniversoDeTempo::cadaPasso() const = 0;

			/**
			 * Verifica se este UniversoDeTempo é o mesmo
			 * que outro.
			 */
			virtual bool UniversoDeTempo::mesmoUniversoDeTempo(
					const UniversoDeTempo&) const = 0;
	};
  }
}

#endif // !defined(AFX_UNIVERSODETEMPO_H__430A79F2_2C51_4D79_BDE8_0EFEB9B7A3BD__INCLUDED_)
