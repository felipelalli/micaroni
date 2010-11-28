/*
 * $RCSfile: Area.h,v $
 * $Date: 2003/05/29 21:00:03 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_AREA_H__27B4B76A_E958_4588_B6B4_BD6B015CFDC0__INCLUDED_)
#define AFX_AREA_H__27B4B76A_E958_4588_B6B4_BD6B015CFDC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Tamanho.h"

using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
  namespace visual {

	/**
	 * Representa uma área <b>retangular</b>
	 * simples.
	 */
	class Area: public Objeto {
		private:
			biblia::visual::Ponto pPonto;
			biblia::visual::Tamanho pTamanho;

		public:
			Area::Area();
			Area::Area(const Area&);
			Area::Area(const Ponto&, const Tamanho&);
			virtual Area::~Area();

			virtual int Area::x() const;
			virtual int Area::y() const;
			virtual int Area::largura() const;
			virtual int Area::altura() const;
			virtual const Ponto Area::pontoInicial() const;
			virtual const Ponto Area::pontoFinal() const;
			virtual const Tamanho Area::tamanho() const;
			virtual bool Area::contem(const Area&) const;
			virtual bool Area::contem(const Ponto&) const;
			virtual bool Area::conflitoCom(const Area&) const;

			virtual Area& Area::operator=(const Area&);
			virtual bool Area::operator==(const Area&) const;

			// Objeto:
			virtual std::string Area::emString() const;
	};
  }
}

#endif // !defined(AFX_AREA_H__27B4B76A_E958_4588_B6B4_BD6B015CFDC0__INCLUDED_)
