/*
 * $RCSfile: Realizador.h,v $
 * $Date: 2003/10/27 19:22:42 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_REALIZADOR_H__498C0114_9C9A_4EFE_8DF3_E6F6ED946C9A__INCLUDED_)
#define AFX_REALIZADOR_H__498C0114_9C9A_4EFE_8DF3_E6F6ED946C9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"

using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace logica {

	/**
	 * Baseado em algum resultado faz
	 * de fato o que deve ser feito.
	 * <p>
	 * Geralmente empilha os eventos nos dispositivos
	 * de saída.
	 *
	 * @deprecated veja o pacote biblia::dinamicas::sinfonia
	 */
	class Realizador: public Executavel, public Objeto {
		public:
			Realizador::Realizador();
			virtual Realizador::~Realizador();

			// Executavel:
			virtual Executavel& Realizador::executa() = 0;
	};
  }
}

#endif // !defined(AFX_REALIZADOR_H__498C0114_9C9A_4EFE_8DF3_E6F6ED946C9A__INCLUDED_)
