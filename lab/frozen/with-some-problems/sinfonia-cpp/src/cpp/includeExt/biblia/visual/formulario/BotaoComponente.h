/*
 * $RCSfile: BotaoComponente.h,v $
 * $Date: 2003/05/29 21:03:15 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BOTAO_H__1EFCCECE_A9D8_4A16_B3DF_DBA080F68735__INCLUDED_)
#define AFX_BOTAO_H__1EFCCECE_A9D8_4A16_B3DF_DBA080F68735__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/ComponenteExecutavel.h"
#include "biblia/visual/formulario/Label.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class Botao: public ComponenteExecutavel {
			private:
				LabelComponente Botao::pFace;
				LabelComponente Botao::pFacePressionada;
				LabelComponente Botao::pFaceDesabilitada;
				bool Botao::pPressionado;

			public:
				Botao::Botao();
				virtual Botao::~Botao();
				virtual LabelComponente& Botao::face();
				virtual const LabelComponente& Botao::face() const;
				virtual LabelComponente& Botao::facePressionada();
				virtual const LabelComponente& Botao::facePressionada() const;
				virtual LabelComponente& Botao::faceDesabilitada();
				virtual const LabelComponente& Botao::faceDesabilitada() const;

				virtual const bool& Botao::pressionado() const;
				virtual Botao& Botao::pressionado(bool);
		};
	}
  }
}

#endif // !defined(AFX_BOTAO_H__1EFCCECE_A9D8_4A16_B3DF_DBA080F68735__INCLUDED_)
