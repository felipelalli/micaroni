/*
 * $RCSfile: Tamanho.h,v $
 * $Date: 2005/01/20 21:29:32 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_TAMANHO_H__29088501_EE1D_465C_ADB8_87B030530A5E__INCLUDED_)
#define AFX_TAMANHO_H__29088501_EE1D_465C_ADB8_87B030530A5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/VisualExcecao.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace visual {

	class Tamanho: public Objeto {
		private:
			biblia::visual::Ponto Tamanho::pTamanho;

		public:
			Tamanho::Tamanho();
			Tamanho::Tamanho(
					const int& largura,
					const int& altura);

			Tamanho::Tamanho(const Tamanho&);
			virtual Tamanho::~Tamanho();
			virtual const int& Tamanho::largura() const;
			virtual const int& Tamanho::altura() const;

			virtual Tamanho& Tamanho::largura(const int&);
			virtual Tamanho& Tamanho::altura(const int&);

			virtual Tamanho& Tamanho::operator=(const Tamanho&);

			virtual bool Tamanho::operator==(const Tamanho&) const;
			virtual bool Tamanho::operator!=(const Tamanho&) const;

			/**
			 * Se é totalmente menor.
			 */
			virtual bool Tamanho::operator<(const Tamanho&) const;

			/**
			 * Se é totalmente menor.
			 */
			virtual bool Tamanho::operator<=(const Tamanho&) const;

			/**
			 * Se é parcialmente maior.
			 */
			virtual bool Tamanho::operator>(const Tamanho&) const;

			/**
			 * Se é parcialmente maior.
			 */
			virtual bool Tamanho::operator>=(const Tamanho&) const;

			// Objeto:
			virtual std::string Tamanho::emString() const;
	};
  }
}

#endif // !defined(AFX_PONTO_H__29088501_EE1D_465C_ADB8_87B030530A5E__INCLUDED_)
