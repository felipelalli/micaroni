/*
 * $RCSfile: VisorMensagem.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_VISORMENSAGEM_H__F110B244_39D1_48FA_A640_87CC855CB50F__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_VISORMENSAGEM_H__F110B244_39D1_48FA_A640_87CC855CB50F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/visual/fonte/Texto.h"

using namespace biblia::basico;
using namespace biblia::tempo;
using namespace biblia::visual::fonte;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class VisorMensagem: public Objeto {
			private:
				Texto VisorMensagem::pTexto;
				bool VisorMensagem::pApagado;
				bool VisorMensagem::pPiscando;
				Intervalo VisorMensagem::pIntervaloDePisque;
				Intervalo VisorMensagem::pIntervaloMsgTemporaria;
				string VisorMensagem::pPremioASerExibidoNaBolaExtra;

				bool VisorMensagem::pMensagemTemporaria;

			public:
				VisorMensagem::VisorMensagem(
						const Intervalo intervaloDePisque,
						const Intervalo intervaloMgsTemp);

				virtual VisorMensagem::~VisorMensagem();

				virtual const Texto& VisorMensagem::texto() const;
				virtual Texto& VisorMensagem::texto();

				/** ver sua definição no renderizador sonoro */
				virtual const string& premioASerExibidoNaBolaExtra() const;
				virtual VisorMensagem& premioASerExibidoNaBolaExtra(const string&);

				virtual bool VisorMensagem::piscando() const;
				virtual bool VisorMensagem::apagado() const;
				virtual bool VisorMensagem::aceso() const {
					return !this->apagado();
				}

				virtual bool VisorMensagem::mensagemTemporaria() const;
				virtual VisorMensagem& VisorMensagem::mensagemTemporaria(bool);

				/**
				 * Troca de aceso para apagado e vice-versa.
				 */
				virtual VisorMensagem& VisorMensagem::troca();

				/**
				 * Manda piscar.
				 */
				virtual VisorMensagem& VisorMensagem::pisca();

				/**
				 * Manda parar de piscar.
				 */
				virtual VisorMensagem& VisorMensagem::paraDePiscar();

				/**
				 * Se false, apaga.
				 */
				virtual VisorMensagem& VisorMensagem
						::acende(bool sim = true);

				virtual const Intervalo& VisorMensagem
						::intervaloDePisque() const;

				virtual const Intervalo& VisorMensagem
						::intervaloMsgTemporaria() const;

		};
	  }
	}
  }
}

#endif // !defined(AFX_VISORMENSAGEM_H__F110B244_39D1_48FA_A640_87CC855CB50F__INCLUDED_)
