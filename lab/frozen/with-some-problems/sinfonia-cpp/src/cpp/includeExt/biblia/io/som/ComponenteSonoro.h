/*
 * $RCSfile: ComponenteSonoro.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_COMPONENTESONORO_H__03BCB518_1C87_4562_B191_96F66DC84E95__INCLUDED_)
#define AFX_COMPONENTESONORO_H__03BCB518_1C87_4562_B191_96F66DC84E95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/io/som/Som.h"
#include "biblia/io/som/SomExcecao.h"

using namespace biblia::basico;

namespace biblia {
  namespace io {
    namespace som {

		class ComponenteSonoro: public Objeto {
			private:
				Som& ComponenteSonoro::pAssociadoA;
				double ComponenteSonoro::pPorcentagemVolume;
				bool ComponenteSonoro::pEmLoop;
				bool ComponenteSonoro::pParalelo;
				int ComponenteSonoro::pPrioridade;

			public:
				ComponenteSonoro::ComponenteSonoro(
						Som&, double volume = 100.0,
						int prioridade = 0,
						bool emLoop = false,
						bool paralelo = false);

				virtual ComponenteSonoro::~ComponenteSonoro();

				virtual Som& ComponenteSonoro::som();
				virtual const Som& ComponenteSonoro::som() const;

				virtual const double& ComponenteSonoro::volume() const;
				virtual const bool& ComponenteSonoro::emLoop() const;
				virtual const bool& ComponenteSonoro::paralelo() const;
				virtual const int& ComponenteSonoro::prioridade() const;

				virtual ComponenteSonoro& ComponenteSonoro
						::volume(double);

				virtual ComponenteSonoro& ComponenteSonoro
						::emLoop(bool);

				virtual ComponenteSonoro& ComponenteSonoro
						::paralelo(bool);

				virtual ComponenteSonoro& ComponenteSonoro
						::prioridade(int);
		};
	}
  }
}

#endif // !defined(AFX_COMPONENTESONORO_H__03BCB518_1C87_4562_B191_96F66DC84E95__INCLUDED_)
