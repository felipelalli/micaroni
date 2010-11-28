/*
 * $RCSfile: RedeSuperBonus.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_REDESUPERBONUS_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_)
#define AFX_REDESUPERBONUS_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/io/rede/RedeServidor.h"
#include "biblia/io/rede/GerenciadorRede.h"
#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
#include "biblia/io/rede/interfaces/interfacesServidor/InterServGerenciadorRede.h"
#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/jogos/superbonus/dados/DEstatistica.h"
#include "biblia/jogos/superbonus/dados/DHistorico.h"
#include "biblia/jogos/superbonus/dados/UltimasJogadas.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/jogos/superbonus/dados/util/InterServDConfiguracao.h"
#include "biblia/jogos/superbonus/dados/util/InterServDEstatistica.h"
#include "biblia/jogos/superbonus/dados/util/InterServHistorico.h"
#include "biblia/jogos/superbonus/dados/util/InterServDadosRede.h"
#include "biblia/jogos/superbonus/logica/ProbabilidadesDoJogo.h"
#include "biblia/jogos/superbonus/logica/util/InterCliPremiacaoAcumulado.h"
#include "biblia/jogos/superbonus/logica/util/InterServPremiacaoAcumulado.h"
#include "biblia/jogos/superbonus/logica/util/InterServLogicaAcumulado.h"


using namespace biblia::basico;
using namespace biblia::seguranca;
using namespace biblia::io::rede;
using namespace biblia::io::rede::util;
using namespace biblia::io::rede::interfaces::interfacesServidor;
using namespace biblia::jogos::superbonus::dados;
using namespace biblia::jogos::superbonus::dados::util;
using namespace biblia::jogos::superbonus::logica;
using namespace biblia::jogos::superbonus::logica::util;

namespace biblia {
  namespace jogos {
	namespace superbonus {
   	  namespace io {
		namespace rede {

			class RedeSuperBonus: public Objeto {
				private:
					DConfiguracao* RedeSuperBonus
							::pConfiguracao;

					Estatistica* pEstatistica;
					DHistorico* pHistorico;
					UltimasJogadas* pUltimasJogadas;

					ProbabilidadesDoJogo* RedeSuperBonus
							::pProbabilidades;

					ChaveSeguranca* pChaveSeguranca;

					InterCliPremiacaoAcumulado* pInterCliPremiacaoAcumulado;
					InterServPremiacaoAcumulado* pInterServPremiacaoAcumulado;
					InterServLogicaAcumulado* pInterServLogicaAcumulado;
					InterServDConfiguracao* pInterServDConfiguracao;
					InterServDEstatistica* pInterServDEstatistica;
					InterServHistorico* pInterServHistorico;
					InterServDadosRede* pInterServDadosRede;
					ArqGerenciadorRedeWizard* pArqGerenciadorRedeWizard;
					GerenciadorRedeWizard* pGerenciadorRedeWizard;

					RedeServidor* pRedeServidor;
					GerenciadorRede* pGerenciadorRede;

				public:
					static unsigned long RedeSuperBonus::key[];

					RedeSuperBonus::RedeSuperBonus(
							DConfiguracao*,
							Estatistica*,
							DHistorico*,
							UltimasJogadas*,
							ProbabilidadesDoJogo*);

					virtual GerenciadorRede* RedeSuperBonus::gerenciador();
					virtual InterCliPremiacaoAcumulado* RedeSuperBonus::interCliPremiacaoAcumulado();

					virtual GerenciadorRedeWizard* RedeSuperBonus::gerenciadorWizard();
					virtual ArqGerenciadorRedeWizard* RedeSuperBonus::arqGerenciadorRedeWizard();
					virtual InterServLogicaAcumulado* RedeSuperBonus::interServLogicaAcumulado();

					virtual RedeSuperBonus::~RedeSuperBonus();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_REDESUPERBONUS_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_)
