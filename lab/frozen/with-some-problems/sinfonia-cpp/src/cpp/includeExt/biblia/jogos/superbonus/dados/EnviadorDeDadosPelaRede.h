/*
 * $RCSfile: EnviadorDeDadosPelaRede.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_ENVIADORDEDADOSPELAREDE_H__D7AB25B2_4F10_48C0_A09C_54BE9057AC0C__INCLUDED_)
#define AFX_ENVIADORDEDADOSPELAREDE_H__D7AB25B2_4F10_48C0_A09C_54BE9057AC0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/jogos/superbonus/dados/DadosConfiguracao.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"

using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class EnviadorDeDadosPelaRede: public Objeto, public Executavel {
			private:
				DadosConfiguracao* EnviadorDeDadosPelaRede::pConfiguracao;
				DConfiguracao* EnviadorDeDadosPelaRede::pConfiguracaoLocal;

			protected:
				virtual EnviadorDeDadosPelaRede& EnviadorDeDadosPelaRede::enviaVolume();
				virtual EnviadorDeDadosPelaRede& EnviadorDeDadosPelaRede::enviaAcumulado();
				virtual EnviadorDeDadosPelaRede& EnviadorDeDadosPelaRede::enviaRede();
				virtual EnviadorDeDadosPelaRede& EnviadorDeDadosPelaRede::enviaUsuarios();

			public:
				EnviadorDeDadosPelaRede::EnviadorDeDadosPelaRede(
						DadosConfiguracao&, DConfiguracao& local);

				virtual EnviadorDeDadosPelaRede::~EnviadorDeDadosPelaRede();

				virtual DadosConfiguracao& EnviadorDeDadosPelaRede::dados();
				virtual DConfiguracao& EnviadorDeDadosPelaRede::dadosLocal();
				virtual EnviadorDeDadosPelaRede& EnviadorDeDadosPelaRede::define(
						DadosConfiguracao&, DConfiguracao& local);

				// Executavel:
				virtual Executavel& EnviadorDeDadosPelaRede::executa();
		};
	  }
	}
  }
}

#endif // !defined(AFX_ENVIADORDEDADOSPELAREDE_H__D7AB25B2_4F10_48C0_A09C_54BE9057AC0C__INCLUDED_)
