/*
 * $RCSfile: ControladorDeComponentesPorAcao.h,v $
 * $Date: 2003/05/29 21:08:20 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CONTROLADORDECOMPONENTESPORACAO_H__2B00C218_1A2F_4CE0_8C26_A6663F919D6E__INCLUDED_)
#define AFX_CONTROLADORDECOMPONENTESPORACAO_H__2B00C218_1A2F_4CE0_8C26_A6663F919D6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/tempo/UltraLong.h"
#include "biblia/visual/formulario/ControladorDeComponentes.h"
#include "biblia/visual/formulario/Componente.h"
#include "biblia/visual/formulario/Formulario.h"
#include "biblia/visual/formulario/BotaoComponente.h"
#include "biblia/visual/formulario/InputInteiro.h"
#include "biblia/visual/formulario/InputLimitado.h"
#include "biblia/visual/formulario/TabelaComponente.h"
#include "biblia/visual/formulario/Grupo.h"
#include "biblia/visual/formulario/Selecao.h"
#include "biblia/visual/formulario/Paginas.h"
#include "biblia/visual/formulario/BarraDePorcentagem.h"
#include "biblia/visual/formulario/Volume.h"

using namespace biblia::tempo;

namespace biblia {
  namespace visual {
    namespace formulario {

		class ControladorDeComponentesPorAcao
				:public ControladorDeComponentes
		{
			private:
				int ControladorDeComponentesPorAcao::pAcao;

			protected:
				int ControladorDeComponentesPorAcao::ultimaAcao() const;
				ControladorDeComponentesPorAcao&
					ControladorDeComponentesPorAcao::processa(
							Componente& c, int nivel = 0);

			public:
				static int ControladorDeComponentesPorAcao::CARACTERE_ANTERIOR;
				static int ControladorDeComponentesPorAcao::PROXIMO_CARACTERE;
				static int ControladorDeComponentesPorAcao::FOCO_ANTERIOR;
				static int ControladorDeComponentesPorAcao::PROXIMO_FOCO;
				static int ControladorDeComponentesPorAcao::AUMENTA_VALOR;
				static int ControladorDeComponentesPorAcao::DIMINUI_VALOR;
				static int ControladorDeComponentesPorAcao::ENTRA;
				static int ControladorDeComponentesPorAcao::VOLTA;
				static int ControladorDeComponentesPorAcao::NADA;

				ControladorDeComponentesPorAcao
						::ControladorDeComponentesPorAcao();

				virtual ControladorDeComponentesPorAcao
						::~ControladorDeComponentesPorAcao();

				virtual ControladorDeComponentesPorAcao&
						ControladorDeComponentesPorAcao
							::age(int acao);

				// Executavel:
				virtual Executavel&
						ControladorDeComponentesPorAcao
							::executa();
		};
	}
  }
}

#endif // !defined(AFX_CONTROLADORDECOMPONENTESPORACAO_H__2B00C218_1A2F_4CE0_8C26_A6663F919D6E__INCLUDED_)
