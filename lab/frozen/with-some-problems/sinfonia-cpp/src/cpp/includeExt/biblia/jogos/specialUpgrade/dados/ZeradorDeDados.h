/*
 * $RCSfile: ZeradorDeDados.h,v $
 * $Date: 2005/01/13 17:09:47 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: fernandofernandes $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002.
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_ZERADORDEDADOS_H__A7257400_1778_4248_A481_2953849375D2__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_ZERADORDEDADOS_H__A7257400_1778_4248_A481_2953849375D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/jogos/specialUpgrade/dados/DadosConfiguracao.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaAcumulado.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::jogos::specialUpgrade::logica;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
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
