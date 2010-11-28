/*
 * $RCSfile: Sistema.h,v $
 * $Date: 2005/01/13 17:09:47 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_SISTEMA_H__11015010_E57F_46DE_B859_45693572F514__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_SISTEMA_H__11015010_E57F_46DE_B859_45693572F514__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/specialUpgrade/antigo/TelaCompleta.h"
#include "biblia/jogos/specialUpgrade/antigo/CoisaNaTela.h"
#include "biblia/jogos/specialUpgrade/antigo/MensagemBmp.h"
#include "biblia/jogos/specialUpgrade/antigo/Marcacao.h"

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{
	namespace jogos {
		namespace specialUpgrade {
			namespace antigo {

				class Sistema {
					protected:
						Sistema::Sistema(){};

					public:
						virtual Sistema::~Sistema(){};
						static void Sistema::mensagem(
								const char*, TelaCompleta&, bool opaco = false, BITMAP* onde = NULL);

						static void Sistema::telaDeInicializacao(TelaCompleta&);
				};
			}
		}
	}
}

#endif // !defined(AFX_SISTEMA_H__11015010_E57F_46DE_B859_45693572F514__INCLUDED_)
