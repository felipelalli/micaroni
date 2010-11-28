/*
 * $RCSfile: RedeSpecial.h,v $
 * $Date: 2005/01/19 17:22:09 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_AFX_REDESpecial_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_AFX_REDESpecial_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_

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
#include "biblia/jogos/specialUpgrade/dados/DEstatistica.h"
#include "biblia/jogos/specialUpgrade/dados/DHistorico.h"
#include "biblia/jogos/specialUpgrade/dados/UltimasJogadas.h"
#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
#include "biblia/jogos/specialUpgrade/dados/util/InterServDConfiguracao.h"
#include "biblia/jogos/specialUpgrade/dados/util/InterServDEstatistica.h"
#include "biblia/jogos/specialUpgrade/dados/util/InterServHistorico.h"
#include "biblia/jogos/specialUpgrade/dados/util/InterServDadosRede.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterCliPremiacaoAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterServPremiacaoAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterServLogicaAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterServPremioSurpresa.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/PremioSurpresa.h"

#include "biblia/tempo/UniversoDeTempo.h"
using namespace biblia::tempo;

using namespace biblia::basico;
using namespace biblia::seguranca;
using namespace biblia::io::rede;
using namespace biblia::io::rede::util;
using namespace biblia::io::rede::interfaces::interfacesServidor;
using namespace biblia::jogos::specialUpgrade::dados;
using namespace biblia::jogos::specialUpgrade::dados::util;
using namespace biblia::jogos::specialUpgrade::logica;
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/GerenciadorDeProbabilidades.h"
using namespace biblia::jogos::specialUpgrade::logica;

namespace biblia {
  namespace jogos {
	namespace specialUpgrade {
   	  namespace io {
		namespace rede {

			class RedeSpecial: public Objeto {
				private:
					biblia::jogos::specialUpgrade::dados::DConfiguracao* RedeSpecial
							::pConfiguracao;

					biblia::jogos::specialUpgrade::dados::Estatistica* pEstatistica;
					biblia::jogos::specialUpgrade::dados::DHistorico* pHistorico;
					biblia::jogos::specialUpgrade::dados::UltimasJogadas* pUltimasJogadas;

					GerenciadorDeProbabilidades& pGerenciador;

					ChaveSeguranca* pChaveSeguranca;

					biblia::jogos::specialUpgrade::logica::util::InterCliPremiacaoAcumulado* pInterCliPremiacaoAcumulado;
					biblia::jogos::specialUpgrade::logica::util::InterServPremiacaoAcumulado* pInterServPremiacaoAcumulado;
					biblia::jogos::specialUpgrade::logica::util::InterServPremioSurpresa* pInterServPremioSurpresa;
					biblia::jogos::specialUpgrade::logica::util::InterServLogicaAcumulado* pInterServLogicaAcumulado;
					biblia::jogos::specialUpgrade::dados::util::InterServDConfiguracao* pInterServDConfiguracao;
					biblia::jogos::specialUpgrade::dados::util::InterServDEstatistica* pInterServDEstatistica;
					biblia::jogos::specialUpgrade::dados::util::InterServHistorico* pInterServHistorico;
					biblia::jogos::specialUpgrade::dados::util::InterServDadosRede* pInterServDadosRede;
					ArqGerenciadorRedeWizard* pArqGerenciadorRedeWizard;
					GerenciadorRedeWizard* pGerenciadorRedeWizard;

					RedeServidor* pRedeServidor;
					GerenciadorRede* pGerenciadorRede;

				public:
					static unsigned long RedeSpecial::key[];

					RedeSpecial::RedeSpecial(
							UniversoDeTempo& universoDeTempo,
							biblia::jogos::specialUpgrade::dados::DConfiguracao*,
							biblia::jogos::specialUpgrade::dados::Estatistica*,
							biblia::jogos::specialUpgrade::dados::DHistorico*,
							biblia::jogos::specialUpgrade::dados::UltimasJogadas*,
							GerenciadorDeProbabilidades& gerenciador,
							biblia::jogos::specialUpgrade::logica::LogicaAcumulado**,
							biblia::jogos::specialUpgrade::logica::PremioSurpresa**);

					virtual GerenciadorRede* RedeSpecial::gerenciador();
					virtual biblia::jogos::specialUpgrade::logica::util::InterCliPremiacaoAcumulado* RedeSpecial::interCliPremiacaoAcumulado();

					virtual GerenciadorRedeWizard* RedeSpecial::gerenciadorWizard();
					virtual ArqGerenciadorRedeWizard* RedeSpecial::arqGerenciadorRedeWizard();
					virtual biblia::jogos::specialUpgrade::logica::util::InterServLogicaAcumulado* RedeSpecial::interServLogicaAcumulado();

					virtual RedeSpecial::~RedeSpecial();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_REDESpecial_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_)
