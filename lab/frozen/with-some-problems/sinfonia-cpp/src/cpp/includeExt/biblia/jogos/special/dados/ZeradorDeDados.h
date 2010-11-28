/*
 * $RCSfile: ZeradorDeDados.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002.
 */

#if !defined(SBS_AFX_ZERADORDEDADOS_H__A7257400_1778_4248_A481_2953849375D2__INCLUDED_)
#define SBS_AFX_ZERADORDEDADOS_H__A7257400_1778_4248_A481_2953849375D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/jogos/special/dados/DadosConfiguracao.h"
#include "biblia/jogos/special/logica/LogicaAcumulado.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::jogos::special::logica;

namespace biblia {
  namespace jogos {
    namespace special {
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
