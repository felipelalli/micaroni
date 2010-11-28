/*
 * $RCSfile: UltraLong.h,v $
 * $Date: 2005/01/20 21:29:05 $
 * $Revision: 1.14 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_ULTRALONG_H__AAFCC8C6_74E5_4B7A_A08A_32825F9A5441__INCLUDED_)
#define AFX_ULTRALONG_H__AAFCC8C6_74E5_4B7A_A08A_32825F9A5441__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/tempo/TempoExcecao.h"

using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
  namespace tempo {

	/**
	 * � um n�mero que sempre come�a no zero
	 * e vai at� no m�ximo 2^([4 bytes * 8 bits] * 3) ou 2^96
	 * ou 79.228.162.514.264.337.593.543.950.336
	 * (~= 79 octalh�es).
	 * <p>
	 * � util para opera��es de tempo que n�o
	 * podem ser 'estouradas' com valor m�ximo.
	 * Para que o valor citado exceda o valor
	 * m�ximo s�o necess�rios 2.105.555.278.355.268
	 * (~= 2 tetralh�es) de anos, caso cada passo
	 * seja um <i>hardware clock ticks</i> que s�o
	 * 1.193.181 em um segundo.
	 *
	 * @todo Por enquanto est� implementado
	 *       somente com um long, i. e.,
	 *       demoraria apenas 3.599 segundos
	 *       para que este valor excedesse caso
	 *       o timer fosse em <i>hardware clock
	 *       ticks</i>. Prefira utilizar intervalos
	 *       maiores como 1 milissegundo que
	 *       demoraria ~= 50 dias para exceder ou
	 *       utilize 10 milissegundos para que
	 *       exceda em ~= 500 dias.
	 */
	class UltraLong: public Objeto {
		private:
			unsigned long p1;
			//unsigned long p2; // XXX: Implementar
			//unsigned long p3; // idem.

		public:
			UltraLong::UltraLong();
			UltraLong::UltraLong(const unsigned long int&);
			virtual UltraLong::~UltraLong();

			virtual UltraLong& UltraLong::operator++();    // prefixo
			virtual UltraLong& UltraLong::operator++(int); // sufixo
			virtual UltraLong& UltraLong::operator+=(long);
			virtual UltraLong& UltraLong::operator+=(const UltraLong&);
			virtual UltraLong& UltraLong::operator=(const UltraLong&);
			virtual UltraLong& UltraLong::operator=(const unsigned long&);

			virtual UltraLong UltraLong::operator-(const UltraLong&) const;
			virtual UltraLong UltraLong::operator+(const UltraLong&) const;

			/**
			 * Esta opera��o certamente perder� precis�o
			 * se double for um valor quebrado. Por�m pode ser
			 * �til quando se trata de valores gigantescos.
			 */
			virtual UltraLong UltraLong::operator*(const double&) const;

			/**
			 * Esta opera��o certamente perder� precis�o.
			 * Por�m pode ser �til quando se trata de
			 * valores gigantescos.
			 */
			virtual UltraLong UltraLong::operator/(const double&) const;
			virtual UltraLong UltraLong::operator/(const UltraLong&) const;

			virtual bool UltraLong::operator==(const UltraLong&) const;
			virtual bool UltraLong::operator!=(const UltraLong&) const;
			virtual bool UltraLong::operator<(const UltraLong&) const;
			virtual bool UltraLong::operator<=(const UltraLong&) const;
			virtual bool UltraLong::operator>(const UltraLong&) const;
			virtual bool UltraLong::operator>=(const UltraLong&) const;

			virtual bool UltraLong::operator==(const long&) const;
			virtual bool UltraLong::operator!=(const long&) const;
			virtual bool UltraLong::operator<(const long&) const;
			virtual bool UltraLong::operator<=(const long&) const;
			virtual bool UltraLong::operator>(const long&) const;
			virtual bool UltraLong::operator>=(const long&) const;

			virtual unsigned long UltraLong::emLong() const;

			static UltraLong UltraLong::valorMaximo();
			static UltraLong UltraLong::valorMinimo();

			// Objeto:
			virtual std::string UltraLong::emString() const;
	};
  }

    bool operator==(const long&, const biblia::tempo::UltraLong&);
	bool operator!=(const long&, const biblia::tempo::UltraLong&);
	bool operator<(const long&, const biblia::tempo::UltraLong&);
	bool operator<=(const long&, const biblia::tempo::UltraLong&);
	bool operator>(const long&, const biblia::tempo::UltraLong&);
	bool operator>=(const long&, const biblia::tempo::UltraLong&);

	/**
  	 * @see biblia::tempo::UltraLong#operator*(const double&) const
	 */
	biblia::tempo::UltraLong operator*(
			const double&, const biblia::tempo::UltraLong&);

	/**
	 * @see biblia::tempo::UltraLong#operator/(const double&) const
	 */
	biblia::tempo::UltraLong operator/(
			const double&, const biblia::tempo::UltraLong&);
}

#endif // !defined(AFX_ULTRALONG_H__AAFCC8C6_74E5_4B7A_A08A_32825F9A5441__INCLUDED_)
