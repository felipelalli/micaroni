/*
 * $RCSfile: Linha.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_LINHA_H__9AC817B7_C7C0_4C56_B803_C706F9994408__INCLUDED_)
#define AFX_LINHA_H__9AC817B7_C7C0_4C56_B803_C706F9994408__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Geometrico.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/cores/Vermelho.h"

namespace biblia {
  namespace visual {
 	namespace geometricos {

		class Linha: public Geometrico {
			private:
				Ponto Linha::pPontoFinal;

			public:
				Linha::Linha(const Linha&);
				Linha::Linha(
						const Ponto& pontoInicial,
						const Ponto& pontoFinal,
						Cor = cores::Vermelho(),
						bool preenchido = false);

				virtual Linha::~Linha();
				virtual const Ponto& Linha::pontoFinal() const;
				virtual Linha& Linha::pontoFinal(const Ponto&);

				virtual Linha& Linha::operator=(const Linha&);

				/**
				 * Não compara a cor e nem se está preenchido.
				 */
				virtual bool Linha::operator==(const Linha&) const;

				virtual Area Linha::areaQueOcupa() const;
		};
	}
  }
}

#endif // !defined(AFX_LINHA_H__9AC817B7_C7C0_4C56_B803_C706F9994408__INCLUDED_)
