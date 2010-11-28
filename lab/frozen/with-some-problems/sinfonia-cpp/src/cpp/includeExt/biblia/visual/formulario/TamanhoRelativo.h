/*
 * $RCSfile: TamanhoRelativo.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TAMANHORELATIVO_H__FDEFFC09_288A_40AC_9589_43091BD3A9C9__INCLUDED_)
#define AFX_TAMANHORELATIVO_H__FDEFFC09_288A_40AC_9589_43091BD3A9C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Tamanho.h"
#include "biblia/visual/formulario/Componente.h"

using namespace biblia::visual;

namespace biblia {
  namespace visual {
    namespace formulario {

		class TamanhoRelativo: public Tamanho {
			private:
				const Componente* TamanhoRelativo::pComponente;
				double TamanhoRelativo::pPorcentagemX;
				double TamanhoRelativo::pPorcentagemY;

			protected:
				const Componente& TamanhoRelativo::componente() const;

			public:
				TamanhoRelativo::TamanhoRelativo();
				virtual TamanhoRelativo::~TamanhoRelativo();

				virtual TamanhoRelativo& TamanhoRelativo
						::componente(const Componente&);

				virtual const double& TamanhoRelativo::porcentagemX() const;
				virtual const double& TamanhoRelativo::porcentagemY() const;
				virtual TamanhoRelativo& TamanhoRelativo
						::porcentagem(double x, double y);

				// Tamanho:
				virtual const int& TamanhoRelativo::largura() const;
				virtual const int& TamanhoRelativo::altura() const;
		};
	}
  }
}

#endif // !defined(AFX_TAMANHORELATIVO_H__FDEFFC09_288A_40AC_9589_43091BD3A9C9__INCLUDED_)
