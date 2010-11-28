/*
 * $RCSfile: ComponenteExecutavel.h,v $
 * $Date: 2003/05/29 21:08:20 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_COMPONENTEEXECUTAVEL_H__5D0A8F63_7372_4985_A907_3A5AFDE8F265__INCLUDED_)
#define AFX_COMPONENTEEXECUTAVEL_H__5D0A8F63_7372_4985_A907_3A5AFDE8F265__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/ExecutaveisEmSerie.h"

using namespace biblia::fluxo;

namespace biblia {
  namespace visual {
    namespace formulario {

		class ComponenteExecutavel
				:public Executavel,
				 public Componente
		{
			private:
				ExecutaveisEmSerie ComponenteExecutavel::pExecutaveis;

			protected:
				ComponenteExecutavel::ComponenteExecutavel();

			public:
				virtual ComponenteExecutavel::~ComponenteExecutavel();
				virtual ExecutaveisEmSerie& ComponenteExecutavel
						::executaveis();

				virtual const ExecutaveisEmSerie& ComponenteExecutavel
						::executaveis() const;

				// Executavel:
				virtual Executavel& ComponenteExecutavel::executa();
		};
	}
  }
}

#endif // !defined(AFX_COMPONENTEEXECUTAVEL_H__5D0A8F63_7372_4985_A907_3A5AFDE8F265__INCLUDED_)
