/*
 * $RCSfile: Intervalo.h,v $
 * $Date: 2005/01/20 21:29:05 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_INTERVALO_H__9D9CC64F_944A_4606_A027_96E93CE43116__INCLUDED_)
#define AFX_INTERVALO_H__9D9CC64F_944A_4606_A027_96E93CE43116__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Momento.h"
#include "biblia/tempo/UnidadeDeTempo.h"

using namespace biblia::basico;

namespace biblia {
  namespace tempo {

	/**
	 * Representa um intervalo de tempo
	 * numa determinada {@link
	 * biblia::tempo::UnidadeDeTempo
	 * unidade de tempo}.
	 *
	 * @see biblia::tempo::UnidadeDeTempo
	 */
	class Intervalo: public Objeto {
		private:
			UltraLong Intervalo::pIntervalo;
			UnidadeDeTempo Intervalo::pUnidade;

		public:
			Intervalo::Intervalo(
					const Momento& anterior,
					const Momento& posterior);

			Intervalo::Intervalo(
					const Momento& unico);

			Intervalo::Intervalo(
					const UltraLong& absoluto,
					const UnidadeDeTempo&);

			virtual Intervalo::~Intervalo();

			virtual bool Intervalo::operator==(const Intervalo&) const;
			virtual bool Intervalo::operator!=(const Intervalo&) const;
			virtual bool Intervalo::operator<(const Intervalo&) const;
			virtual bool Intervalo::operator<=(const Intervalo&) const;
			virtual bool Intervalo::operator>(const Intervalo&) const;
			virtual bool Intervalo::operator>=(const Intervalo&) const;

			virtual const UltraLong& Intervalo::operator()() const;
			virtual Intervalo& Intervalo::operator=(const Intervalo&);
			virtual Intervalo& Intervalo::operator+=(const Intervalo&);
			virtual Intervalo Intervalo
					::operator+(const Intervalo&) const;

			virtual Intervalo Intervalo
					::operator-(const Intervalo&) const;

			/**
			 * Quantas vezes este intervalo cabe dentro
			 * do passado como parâmetro?
			 */
			virtual Intervalo Intervalo
					::operator/(const Intervalo&) const;

			/**
			 * Multiplicação.
			 */
			virtual Intervalo Intervalo::operator*(const double&) const;

			virtual const UnidadeDeTempo&
					Intervalo::unidadeDeTempo() const;

			virtual Intervalo& Intervalo::aumentaIntervalo(
					UltraLong emQuanto = UltraLong(1));

			/**
			 * Retorna o valor desse intervalo
			 * em milionésimos de segundo.
			 */
			virtual UltraLong Intervalo
					::emMilionesimosDeSegundo() const;

			static Intervalo Intervalo
					::converte(const Intervalo&,
							   const UnidadeDeTempo&);

			// Objeto:
			virtual std::string Intervalo::emString() const;
	};
  }
}

#endif // !defined(AFX_INTERVALO_H__9D9CC64F_944A_4606_A027_96E93CE43116__INCLUDED_)
