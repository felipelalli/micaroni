/*
 * $RCSfile: Fogo.h,v $
 * $Date: 2005/01/13 17:09:51 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_FOGO_H__FF038A85_FE30_46F8_A9FC_6F277311BA56__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_FOGO_H__FF038A85_FE30_46F8_A9FC_6F277311BA56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/fluxo/ExecutavelOtimizado.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Posicionado.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::fluxo;
using namespace biblia::visual;

namespace biblia {
  namespace jogos {
	namespace specialUpgrade {
	  namespace visual {
		class Fogo: public Objeto,
				    public ExecutavelOtimizado
		{
			private:
				Ponto Fogo::pPonto;
				Ponto Fogo::pIncrementacao;

			public:
				Fogo::Fogo();
				virtual Fogo::~Fogo();

				virtual Fogo& Fogo::inicia
						(Ponto pontoInicial,
						 Ponto incrementacao);

				// ExecutavelOtimizado:
				virtual ExecutavelOtimizado& Fogo
						::executa(int quantasVezes);

				virtual const Ponto Fogo::posicao() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_FOGO_H__FF038A85_FE30_46F8_A9FC_6F277311BA56__INCLUDED_)
