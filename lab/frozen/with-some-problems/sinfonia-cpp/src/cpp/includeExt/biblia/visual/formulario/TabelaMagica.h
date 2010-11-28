/*
 * $RCSfile: TabelaMagica.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TABELAMAGICA_H__476E7AC0_AEC4_4057_9615_44E7A72B44B0__INCLUDED_)
#define AFX_TABELAMAGICA_H__476E7AC0_AEC4_4057_9615_44E7A72B44B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/visual/Cor.h"
#include "biblia/visual/formulario/TabelaComponente.h"

using namespace biblia::basico;
using namespace biblia::visual;

namespace biblia {
  namespace visual {
    namespace formulario {

		class TabelaMagica: public Objeto {
				private:
					Tabela& pTabela;

				public:
					TabelaMagica::TabelaMagica(Tabela&);
					virtual TabelaMagica::~TabelaMagica();

					/**
					 * Pinta cor sim e 'cornão' na tabela
					 * sempre na horizontal.
					 */
					virtual TabelaMagica&
							TabelaMagica
								::corSimCorNao(
									Cor corSim, Cor corNao,
									int inicio = 0,
									int fim = -1,
									int colunaInicio = 0,
									int colunaFim = -1);

					virtual Tabela& TabelaMagica::tabela();
		};
	}
  }
}

#endif // !defined(AFX_TABELAMAGICA_H__476E7AC0_AEC4_4057_9615_44E7A72B44B0__INCLUDED_)
