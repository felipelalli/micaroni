/*
 * $RCSfile: Dicionario.h,v $
 * $Date: 2005/01/13 17:09:47 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_DICIONARIO_H__1F5AAD00_F788_4537_B98A_AC1409905257__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_DICIONARIO_H__1F5AAD00_F788_4537_B98A_AC1409905257__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string.h>
#include "biblia/jogos/specialUpgrade/dados/DadosXML.h"
#include "biblia/jogos/specialUpgrade/dados/DadosArqText.h"
#include "biblia/jogos/specialUpgrade/dados/Dados.h"
#include "biblia/util/CData.h"

using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;


namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
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
