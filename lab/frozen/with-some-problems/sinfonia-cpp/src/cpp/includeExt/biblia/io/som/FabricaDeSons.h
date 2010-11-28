/*
 * $RCSfile: FabricaDeSons.h,v $
 * $Date: 2005/01/20 21:28:44 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_FABRICADESONS_H__4C510E66_FF2E_475A_B1E9_4959D8D7A504__INCLUDED_)
#define AFX_FABRICADESONS_H__4C510E66_FF2E_475A_B1E9_4959D8D7A504__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/io/som/Som.h"

using namespace biblia::basico;

namespace biblia {
  namespace io {
    namespace som {

		class FabricaDeSons: public Interface {
			public:
				FabricaDeSons::FabricaDeSons();
				virtual FabricaDeSons::~FabricaDeSons();

				/**
				 * Retorna um som instanciado.
				 */
				virtual Som* FabricaDeSons::carregaDeArquivoBasico(
						const std::string& caminhoENomeDoArquivoBasico) = 0;
		};
	}
  }
}

#endif // !defined(AFX_FABRICADESONS_H__4C510E66_FF2E_475A_B1E9_4959D8D7A504__INCLUDED_)
