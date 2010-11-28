/*
 * $RCSfile: Renderizador.h,v $
 * $Date: 2004/05/31 03:15:29 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_RENDERIZADOR_H__E57C40C1_2EAA_45FF_80CB_DBF01F87533C__INCLUDED_)
#define AFX_RENDERIZADOR_H__E57C40C1_2EAA_45FF_80CB_DBF01F87533C__INCLUDED_

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
	 * A partir de informações, gera um resultado
	 * para que algum realizador possa efetuá-lo.
	 *
	 * @deprecated veja o pacote biblia::dinamicas::sinfonia
	 */
	class Renderizador: public Executavel, public Objeto {
		public:
			Renderizador::Renderizador();
			virtual Renderizador::~Renderizador();

			// Executavel:
			virtual Executavel& Renderizador::executa() = 0;
	};
  }
}

#endif // !defined(AFX_RENDERIZADOR_H__E57C40C1_2EAA_45FF_80CB_DBF01F87533C__INCLUDED_)
