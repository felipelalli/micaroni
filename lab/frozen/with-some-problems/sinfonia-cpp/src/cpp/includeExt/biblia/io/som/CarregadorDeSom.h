/*
 * $RCSfile: CarregadorDeSom.h,v $
 * $Date: 2005/01/20 21:28:44 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_CARREGADORDESOM_H__E77183C0_BD24_4D64_B83E_0ACA2D93C477__INCLUDED_)
#define AFX_CARREGADORDESOM_H__E77183C0_BD24_4D64_B83E_0ACA2D93C477__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <map>
#include <deque>
#include "biblia/util/Carregador.h"
#include "biblia/io/som/Som.h"
#include "biblia/io/som/FabricaDeSons.h"
#include "biblia/io/som/SomExcecao.h"

namespace biblia {
  namespace io {
    namespace som {

		class CarregadorDeSom: public Carregador {
			private:
				FabricaDeSons& CarregadorDeSom::pFabrica;
				map<std::string, Som*> CarregadorDeSom::pSons;

				/* Lista das coisas a carregar: */
				std::deque<string> CarregadorDeSom::pChaves;
				std::deque<string> CarregadorDeSom::pNomeDoArquivoBasico;

			public:
				CarregadorDeSom::CarregadorDeSom(FabricaDeSons&);
				virtual CarregadorDeSom::~CarregadorDeSom();

				virtual FabricaDeSons& CarregadorDeSom::fabrica();
				virtual CarregadorDeSom& CarregadorDeSom
						::carregaSom(const std::string& chave,
									 const std::string& nomeDoArquivoBasico);

				bool CarregadorDeSom::jaCarregado(
						const std::string& chave) const;

				virtual Som& CarregadorDeSom
						::som(const std::string& chave);

				// Carregador:
				virtual Executavel& CarregadorDeSom
						::executa();
		};
	}
  }
}

#endif // !defined(AFX_CARREGADORDESOM_H__E77183C0_BD24_4D64_B83E_0ACA2D93C477__INCLUDED_)
