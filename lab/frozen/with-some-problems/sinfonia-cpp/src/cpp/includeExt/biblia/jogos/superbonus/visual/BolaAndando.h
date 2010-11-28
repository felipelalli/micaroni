/*
 * $RCSfile: BolaAndando.h,v $
 * $Date: 2003/05/29 21:03:14 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BOLAANDANDO_H__21AF8E0E_62B3_4378_8CD4_BE6A48108536__INCLUDED_)
#define AFX_BOLAANDANDO_H__21AF8E0E_62B3_4378_8CD4_BE6A48108536__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace visual {

		class BolaAndando: public Objeto {
			private:
				int BolaAndando::pXFinal;
				int BolaAndando::pXAtual;
				int BolaAndando::pPosicao; // 0,1 ou 2
				int BolaAndando::pBola;

			public:
				BolaAndando::BolaAndando(
						int bola, int posicao,
						int xAtual, int xFinal);

				virtual BolaAndando::~BolaAndando();
				virtual BolaAndando& BolaAndando
						::atualiza(int quantas = 1);

				virtual bool BolaAndando
						::chegouNoFim() const;

				virtual const int& BolaAndando::bola() const;
				virtual const int& BolaAndando::x() const;
				virtual const int& BolaAndando::posicao() const;

		};
	  }
	}
  }
}

#endif // !defined(AFX_BOLAANDANDO_H__21AF8E0E_62B3_4378_8CD4_BE6A48108536__INCLUDED_)
