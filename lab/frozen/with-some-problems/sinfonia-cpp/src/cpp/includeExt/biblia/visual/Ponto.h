/*
 * $RCSfile: Ponto.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_PONTO_H__29088501_EE1D_465C_ADB8_87B030530A5E__INCLUDED_)
#define AFX_PONTO_H__29088501_EE1D_465C_ADB8_87B030530A5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace visual {
	class Ponto: public Objeto {
		private:
			int Ponto::pX;
			int Ponto::pY;

		public:
			Ponto::Ponto();
			Ponto::Ponto(const int& x, const int& y);
			Ponto::Ponto(const Ponto&);
			virtual Ponto::~Ponto();
			virtual const int& Ponto::x() const;
			virtual const int& Ponto::y() const;
			virtual Ponto& Ponto::x(const int&);
			virtual Ponto& Ponto::y(const int&);
			virtual Ponto& Ponto::xy(
					const int&, const int&);

			virtual Ponto& Ponto::operator=(const Ponto&);

			virtual Ponto Ponto::operator+(const Ponto&) const;
			virtual Ponto Ponto::operator-(const Ponto&) const;
			virtual bool Ponto::operator==(const Ponto&) const;
			virtual bool Ponto::operator!=(const Ponto&) const;
			virtual bool Ponto::operator<(const Ponto&) const;
			virtual bool Ponto::operator<=(const Ponto&) const;
			virtual bool Ponto::operator>(const Ponto&) const;
			virtual bool Ponto::operator>=(const Ponto&) const;

			// Objeto:
			virtual std::string Ponto::emString() const;
	};
  }
}

#endif // !defined(AFX_PONTO_H__29088501_EE1D_465C_ADB8_87B030530A5E__INCLUDED_)
