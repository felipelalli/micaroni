/*
 * $RCSfile: Dicionario.h,v $
 * $Date: 2005/01/20 21:28:59 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_DICIONARIO_H__1F5AAD00_F788_4537_B98A_AC1409905257__INCLUDED_)
#define AFX_DICIONARIO_H__1F5AAD00_F788_4537_B98A_AC1409905257__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/jogos/superbonus/dados/DadosXML.h"
#include "biblia/jogos/superbonus/dados/DadosArqText.h"
#include "biblia/jogos/superbonus/dados/Dados.h"
#include "biblia/util/CData.h"

using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;


namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class Dicionario: public DadosXML {
			private:
				Dados* Dicionario::pDados;
				biblia::armazenamento::volatil::Lista* Dicionario::pChaves;
				biblia::armazenamento::volatil::Lista* Dicionario::pConteudo;

			public:
				Dicionario::Dicionario();
				virtual Dicionario::~Dicionario();

				const char* Dicionario::conteudo(const char* chave);
		};
	  }
	}
  }
}

#endif // !defined(AFX_DICIONARIO_H__1F5AAD00_F788_4537_B98A_AC1409905257__INCLUDED_)
