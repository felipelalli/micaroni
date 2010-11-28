/*
 * $RCSfile: ZeradorDeDados.h,v $
 * $Date: 2003/06/03 21:02:01 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002.
 */

#if !defined(AFX_ZERADORDEDADOS_H__A7257400_1778_4248_A481_2953849375D2__INCLUDED_)
#define AFX_ZERADORDEDADOS_H__A7257400_1778_4248_A481_2953849375D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/jogos/superbonus/dados/DadosConfiguracao.h"
#include "biblia/jogos/superbonus/logica/LogicaAcumulado.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::jogos::superbonus::logica;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class ZeradorDeDados: public Objeto, public Executavel {
			private:
				DadosConfiguracao* ZeradorDeDados::pConfiguracao;
				LogicaAcumulado* ZeradorDeDados::pLogicaAcumulado;

			public:
				ZeradorDeDados::ZeradorDeDados(
						DadosConfiguracao&, LogicaAcumulado&);

				virtual ZeradorDeDados::~ZeradorDeDados();

				virtual DadosConfiguracao& ZeradorDeDados::dados();
				virtual Executavel& ZeradorDeDados::executa();
		};
	  }
	}
  }
}

#endif // !defined(AFX_ZERADORDEDADOS_H__A7257400_1778_4248_A481_2953849375D2__INCLUDED_)
