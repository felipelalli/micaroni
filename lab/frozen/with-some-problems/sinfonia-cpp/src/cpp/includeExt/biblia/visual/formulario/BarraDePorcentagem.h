/*
 * $RCSfile: BarraDePorcentagem.h,v $
 * $Date: 2003/05/29 21:03:15 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BARRADEPORCENTAGEM_H__71705506_D516_4E01_9FDB_9856F4D83F23__INCLUDED_)
#define AFX_BARRADEPORCENTAGEM_H__71705506_D516_4E01_9FDB_9856F4D83F23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"

namespace biblia {
  namespace visual {
    namespace formulario {

		class BarraDePorcentagem: public Componente {
			private:
				double BarraDePorcentagem::pProgresso;
				double BarraDePorcentagem::pPasso;

			public:
				BarraDePorcentagem::BarraDePorcentagem();
				virtual BarraDePorcentagem::~BarraDePorcentagem();

				virtual BarraDePorcentagem& BarraDePorcentagem
						::progresso(double);

				virtual const double& BarraDePorcentagem
						::progresso() const;

				virtual const double& BarraDePorcentagem
						::passo() const;

				virtual BarraDePorcentagem& BarraDePorcentagem
						::passo(const double&);

				virtual BarraDePorcentagem& BarraDePorcentagem::sobe();
				virtual BarraDePorcentagem& BarraDePorcentagem::desce();
		};
	}
  }
}

#endif // !defined(AFX_BARRADEPORCENTAGEM_H__71705506_D516_4E01_9FDB_9856F4D83F23__INCLUDED_)
