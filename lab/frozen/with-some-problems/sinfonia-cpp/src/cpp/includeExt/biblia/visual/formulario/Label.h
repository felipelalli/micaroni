/*
 * $RCSfile: Label.h,v $
 * $Date: 2003/05/29 21:18:35 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_LABEL_H__63573A0F_9915_40BA_BA5F_F92788E0CA2F__INCLUDED_)
#define AFX_LABEL_H__63573A0F_9915_40BA_BA5F_F92788E0CA2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"
#include "biblia/visual/fonte/Texto.h"
#include "biblia/visual/imagem2d/Imagem.h"

using namespace biblia::visual::imagem2d;
using namespace biblia::visual::fonte;

namespace biblia {
  namespace visual {
    namespace formulario {

		class LabelComponente: public Componente {
			private:
				Texto LabelComponente::pTexto;
				const Imagem* LabelComponente::pImagem;
				int LabelComponente::pFonte;

			public:
				static const int LabelComponente::NORMAL;
				static const int LabelComponente::TITULO;

				LabelComponente::LabelComponente();
				virtual LabelComponente::~LabelComponente();

				virtual Texto& LabelComponente::texto();
				virtual const Texto& LabelComponente::texto() const;
				virtual const bool LabelComponente::temImagem() const;
				virtual LabelComponente& LabelComponente::imagem(const Imagem&);
				virtual LabelComponente& LabelComponente::removeImagem();
				virtual const Imagem& LabelComponente::imagem() const;
				virtual int LabelComponente::fonte() const;
				virtual LabelComponente& LabelComponente::fonte(int);
		};
	}
  }
}

#endif // !defined(AFX_LABEL_H__63573A0F_9915_40BA_BA5F_F92788E0CA2F__INCLUDED_)
