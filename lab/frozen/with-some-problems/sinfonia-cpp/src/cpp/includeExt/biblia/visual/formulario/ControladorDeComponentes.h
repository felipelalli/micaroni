/*
 * $RCSfile: ControladorDeComponentes.h,v $
 * $Date: 2003/05/29 21:08:20 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CONTROLADORDECOMPONENTES_H__62B1A8AA_F2F5_4F13_A691_B34FB1996650__INCLUDED_)
#define AFX_CONTROLADORDECOMPONENTES_H__62B1A8AA_F2F5_4F13_A691_B34FB1996650__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/visual/formulario/Componente.h"

using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace visual {
    namespace formulario {

		class ControladorDeComponentes
				:public Executavel, public Objeto
		{
			private:
				Componente* ControladorDeComponentes::pInicio;

			protected:
				ControladorDeComponentes
						::ControladorDeComponentes();

			public:
				virtual ControladorDeComponentes
						::~ControladorDeComponentes();

				virtual const Componente& ControladorDeComponentes
						::inicio() const;

				virtual Componente& ControladorDeComponentes
						::inicio();

				virtual ControladorDeComponentes&
						ControladorDeComponentes::defineInicio
							(Componente*);

				// Executavel:
				virtual Executavel& ControladorDeComponentes
						::executa() = 0;
		};
	}
  }
}

#endif // !defined(AFX_CONTROLADORDECOMPONENTES_H__62B1A8AA_F2F5_4F13_A691_B34FB1996650__INCLUDED_)
