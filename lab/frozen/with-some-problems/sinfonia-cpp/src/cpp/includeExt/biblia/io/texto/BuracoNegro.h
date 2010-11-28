/*
 * $RCSfile: BuracoNegro.h,v $
 * $Date: 2003/05/29 21:03:14 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BURACONEGRO_H__F2350743_2376_4A0F_B58B_CD9740E6DB4F__INCLUDED_)
#define AFX_BURACONEGRO_H__F2350743_2376_4A0F_B58B_CD9740E6DB4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/texto/FluxoDeTexto.h"

namespace biblia {
  namespace io {
	namespace texto {
		/**
		 * É um {@link biblia::io::texto::FluxoDeTexto
		 * fluxo de texto} sem destino.
		 */
		class BuracoNegro: public FluxoDeTexto {
			public:
				BuracoNegro::BuracoNegro();
				virtual BuracoNegro::~BuracoNegro();

				// FluxoDeTexto:
				virtual Executavel& BuracoNegro::executa();
		};
	}
  }
}

#endif // !defined(AFX_BURACONEGRO_H__F2350743_2376_4A0F_B58B_CD9740E6DB4F__INCLUDED_)
