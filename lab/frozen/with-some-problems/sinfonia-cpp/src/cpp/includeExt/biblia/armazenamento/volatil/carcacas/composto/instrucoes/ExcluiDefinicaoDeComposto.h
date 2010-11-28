/*
 * $RCSfile: ExcluiDefinicaoDeComposto.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_EXCLUIDEFINICAODECOMPOSTO_H__A0880384_DC8D_432D_9CA5_556B4C3C391C__INCLUDED_)
#define AFX_EXCLUIDEFINICAODECOMPOSTO_H__A0880384_DC8D_432D_9CA5_556B4C3C391C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/instrucoes/Instrucao.h"
using namespace biblia::util::instrucoes;

namespace biblia {
 namespace armazenamento {
  namespace volatil {
   namespace carcacas {
    namespace composto {
	 namespace instrucoes {
		class ExcluiDefinicaoDeComposto: public Instrucao {
			public:
				static Identificacao ExcluiDefinicaoDeComposto::COMANDO;
				
				ExcluiDefinicaoDeComposto
						::ExcluiDefinicaoDeComposto(
							const Identificacao&
								qualDefinicaoDeComposto);

				ExcluiDefinicaoDeComposto
						::ExcluiDefinicaoDeComposto(
							const Instrucao& instrucao);

				virtual ExcluiDefinicaoDeComposto
						::~ExcluiDefinicaoDeComposto();

				virtual const Identificacao
						ExcluiDefinicaoDeComposto
							::qualDefinicaoDeComposto() const;
		};
	 }
	}
   }
  }
 }
}

#endif // !defined(AFX_EXCLUIDEFINICAODECOMPOSTO_H__A0880384_DC8D_432D_9CA5_556B4C3C391C__INCLUDED_)
