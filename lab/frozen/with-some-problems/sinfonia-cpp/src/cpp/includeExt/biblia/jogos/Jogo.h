/*
 * $RCSfile: Jogo.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_JOGO_H__8066997B_CE4A_4634_9B02_E235E35130A0__INCLUDED_)
#define AFX_JOGO_H__8066997B_CE4A_4634_9B02_E235E35130A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"

using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace jogos {

	/**
	 * Representa um jogo qualquer que pode
	 * ser executado.
	 */
	class Jogo: public Executavel, public Objeto {
		protected:
			Jogo::Jogo();

		public:
			virtual Jogo::~Jogo();

			// Executavel:
			virtual Executavel& Jogo::executa() = 0;
	};
  }
}

#endif // !defined(AFX_JOGO_H__8066997B_CE4A_4634_9B02_E235E35130A0__INCLUDED_)
