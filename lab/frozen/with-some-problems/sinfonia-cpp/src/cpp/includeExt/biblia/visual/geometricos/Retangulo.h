/*
 * $RCSfile: Retangulo.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_RETANGULO_H__1AC46D65_5627_4C93_B497_D6CC1164F3A9__INCLUDED_)
#define AFX_RETANGULO_H__1AC46D65_5627_4C93_B497_D6CC1164F3A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Geometrico.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/visual/Raio.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Cor.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/cores/Vermelho.h"

using namespace biblia::visual;

namespace biblia {
  namespace visual {
	namespace geometricos {

		class Retangulo: public Geometrico {

			private:
				Tamanho Retangulo::pTamanho;

			public:
				Retangulo::Retangulo(const Retangulo&);
				Retangulo::Retangulo(
						const Ponto& pontoInicial,
						const Tamanho& tamanho,
						Cor = cores::Vermelho(),
						bool preenchido = false);

				virtual Retangulo::~Retangulo();

				virtual const Tamanho& Retangulo::tamanho() const;
				virtual Retangulo& Retangulo::tamanho(const Tamanho&);
				virtual Retangulo& Retangulo::operator=(const Retangulo&);

				/**
				 * Não compara a cor e nem se está preenchido.
				 */
				virtual bool Retangulo::operator==(const Retangulo&) const;
				virtual Area Retangulo::areaQueOcupa() const;
		};
	}
  }
}

#endif // !defined(AFX_RETANGULO_H__1AC46D65_5627_4C93_B497_D6CC1164F3A9__INCLUDED_)
