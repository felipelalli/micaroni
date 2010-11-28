/*
 * $RCSfile: Sistema.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(TROPICAL_SBS_AFX_SISTEMA_H__11015010_E57F_46DE_B859_45693572F514__INCLUDED_)
#define TROPICAL_SBS_AFX_SISTEMA_H__11015010_E57F_46DE_B859_45693572F514__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/jogos/frutinha/antigo/TelaCompleta.h"
#include "biblia/jogos/frutinha/antigo/CoisaNaTela.h"
#include "biblia/jogos/frutinha/antigo/MensagemBmp.h"
#include "biblia/jogos/frutinha/antigo/Marcacao.h"

namespace biblia{
	namespace jogos {
		namespace frutinha {
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
