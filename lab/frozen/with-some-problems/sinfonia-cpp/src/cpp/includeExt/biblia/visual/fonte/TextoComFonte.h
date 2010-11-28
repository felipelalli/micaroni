/*
 * $RCSfile: TextoComFonte.h,v $
 * $Date: 2004/04/21 02:00:05 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TEXTOCOMFONTE_H__8F2A997F_43E1_4481_8242_5B09C64E2F5C__INCLUDED_)
#define AFX_TEXTOCOMFONTE_H__8F2A997F_43E1_4481_8242_5B09C64E2F5C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/visual/Posicionado.h"
#include "biblia/visual/fonte/Texto.h"

using namespace biblia::basico;
using namespace biblia::visual;

namespace biblia {
  namespace visual {
    namespace fonte {

		/**
		 * Texto com fonte <i>flutuante</i> (posicionado)
		 * pronto para ser desenhado na tela.
		 * <p>
		 * Pode/deve ser posicionado por alguém de fora.
		 *
		 * @bug Problema de template ao lincar.
		 */
		template<class Fonte> class TextoComFonte
				:public Posicionado, public Objeto
		{
			private:
				Fonte* TextoComFonte::pFonte;
				Texto TextoComFonte::pTexto;

			public:
				TextoComFonte<Fonte>(const Texto t, Fonte* f,
									 const Ponto& p)
						:pTexto(t), pFonte(f), Posicionado(p)
				{}

				virtual ~TextoComFonte<Fonte>() {};

				virtual Fonte& fonte() {
					return *(this->pFonte);
				}

				virtual const Fonte& fonte() const {
					return *(this->pFonte);
				}

				virtual Texto& texto() {
					return this->pTexto;
				}

				virtual const Texto& texto() const {
					return this->pTexto;
				}

				// Objeto:
				virtual std::string emString() const {
					return Objeto::emString() + ": "
							+ this->texto()
							+ this->fonte();
				}
		};
	}
  }
}

#endif // !defined(AFX_TEXTOCOMFONTE_H__8F2A997F_43E1_4481_8242_5B09C64E2F5C__INCLUDED_)
