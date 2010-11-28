/*
 * $RCSfile: Sistema.h,v $
 * $Date: 2004/05/17 22:11:02 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AFX_SISTEMA_H__11015010_E57F_46DE_B859_45693572F514__INCLUDED_)
#define AFX_SISTEMA_H__11015010_E57F_46DE_B859_45693572F514__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/superbonus/antigo/TelaCompleta.h"
#include "biblia/jogos/superbonus/antigo/CoisaNaTela.h"
#include "biblia/jogos/superbonus/antigo/MensagemBmp.h"
#include "biblia/jogos/superbonus/antigo/Marcacao.h"

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{
	namespace jogos {
		namespace superbonus {
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
