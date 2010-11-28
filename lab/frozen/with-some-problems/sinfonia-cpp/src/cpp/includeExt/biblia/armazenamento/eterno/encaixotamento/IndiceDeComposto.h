/*
 * $RCSfile: IndiceDeComposto.h,v $
 * $Date: 2005/01/20 21:28:33 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_INDICEDECOMPOSTO_H__098D83C2_9BE0_458A_AB5C_0430F41E9952__INCLUDED_)
#define AFX_INDICEDECOMPOSTO_H__098D83C2_9BE0_458A_AB5C_0430F41E9952__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/volatil/Informacao.h"
#include "biblia/armazenamento/volatil/carcacas/composto/Composto.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::carcacas::composto;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {
		/**
		 * Usado por EncaixotadorDeComposto.
		 * @see EncaixotadorDeComposto
		 */
		class IndiceDeComposto: public Informacao {
			private:
				Identificacao IndiceDeComposto
						::pQualDefinicaoDeComposto;

			public:
				/**
				 * Cria um índice de um composto
				 * a partir de uma std::string.
				 */
				IndiceDeComposto::IndiceDeComposto(const std::string&);

				/**
				 * Cria um índice de um composto
				 * a partir de uma Identificacao.
				 */
				IndiceDeComposto::IndiceDeComposto(const Composto&);

				virtual IndiceDeComposto::~IndiceDeComposto();

				virtual const Identificacao& IndiceDeComposto
						::qualDefinicaoDeComposto() const;

				// Informacao:

				virtual const Tipo IndiceDeComposto::tipo() const {
					return IndiceDeComposto::tipoEstatico();
				}

				static const Tipo IndiceDeComposto::tipoEstatico() {
					return Tipo("indiceDeComposto!");
				}

				// Objeto:
				virtual std::string IndiceDeComposto::emString() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_INDICEDECOMPOSTO_H__098D83C2_9BE0_458A_AB5C_0430F41E9952__INCLUDED_)
