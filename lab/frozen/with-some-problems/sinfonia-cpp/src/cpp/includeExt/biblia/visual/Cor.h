/*
 * $RCSfile: Cor.h,v $
 * $Date: 2003/11/17 19:52:15 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_COR_H__00E8D755_6AB4_4223_A2F4_0530901A22B8__INCLUDED_)
#define AFX_COR_H__00E8D755_6AB4_4223_A2F4_0530901A22B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/visual/VisualExcecao.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {
	class Cor: public Objeto {
		private:
			int r, g, b, a;

		public:
			Cor::Cor();
			Cor::Cor(const Cor&);
			Cor::Cor(const int& vermelho,
					 const int& verde,
					 const int& azul,
					 const int transparencia = 0);

			virtual Cor::~Cor();

			virtual const int& Cor::vermelho() const;
			virtual const int& Cor::verde() const;
			virtual const int& Cor::azul() const;
			virtual const int& Cor::transparencia() const;

			virtual Cor Cor::operator+(const Cor&) const;
			virtual Cor& Cor::operator=(const Cor&);

			virtual bool Cor::operator==(const Cor&) const;
			virtual bool Cor::operator!=(const Cor&) const;

			static int Cor::valorMaximo();
			static int Cor::valorDe(double porcentagem);
			static Cor Cor::criaCor(double vermelho,
					double verde, double azul,
					double transparencia = 0.0);

			static double Cor::porcentagemDe(int valor);
	};
  }
}

#endif // !defined(AFX_COR_H__00E8D755_6AB4_4223_A2F4_0530901A22B8__INCLUDED_)
