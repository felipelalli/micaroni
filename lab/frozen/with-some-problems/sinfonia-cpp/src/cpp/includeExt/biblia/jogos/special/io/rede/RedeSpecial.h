/*
 * $RCSfile: RedeSpecial.h,v $
 * $Date: 2004/04/25 01:24:50 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#if !defined(AFX_REDESpecial_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_)
#define AFX_REDESpecial_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_

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
#include "biblia/jogos/special/dados/DEstatistica.h"
#include "biblia/jogos/special/dados/DHistorico.h"
#include "biblia/jogos/special/dados/UltimasJogadas.h"
#include "biblia/jogos/special/dados/DConfiguracao.h"
#include "biblia/jogos/special/dados/util/InterServDConfiguracao.h"
#include "biblia/jogos/special/dados/util/InterServDEstatistica.h"
#include "biblia/jogos/special/dados/util/InterServHistorico.h"
#include "biblia/jogos/special/dados/util/InterServDadosRede.h"
#include "biblia/jogos/special/logica/util/InterCliPremiacaoAcumulado.h"
#include "biblia/jogos/special/logica/util/InterServPremiacaoAcumulado.h"
#include "biblia/jogos/special/logica/util/InterServLogicaAcumulado.h"
#include "biblia/jogos/special/logica/LogicaAcumulado.h"

using namespace biblia::basico;
using namespace biblia::seguranca;
using namespace biblia::io::rede;
using namespace biblia::io::rede::util;
using namespace biblia::io::rede::interfaces::interfacesServidor;
using namespace biblia::jogos::special::dados;
using namespace biblia::jogos::special::dados::util;
using namespace biblia::jogos::special::logica;
using namespace biblia::jogos::special::logica::util;

#include "biblia/jogos/bingo/logica/GerenciadorDeProbabilidades.h"
using namespace biblia::jogos::bingo::logica;

namespace biblia {
  namespace jogos {
	namespace special {
   	  namespace io {
		namespace rede {

			class RedeSpecial: public Objeto {
				private:
					biblia::jogos::special::dados::DConfiguracao* RedeSpecial
							::pConfiguracao;

					biblia::jogos::special::dados::Estatistica* pEstatistica;
					biblia::jogos::special::dados::DHistorico* pHistorico;
					biblia::jogos::special::dados::UltimasJogadas* pUltimasJogadas;

					GerenciadorDeProbabilidades& pGerenciador;

					ChaveSeguranca* pChaveSeguranca;

					biblia::jogos::special::logica::util::InterCliPremiacaoAcumulado* pInterCliPremiacaoAcumulado;
					biblia::jogos::special::logica::util::InterServPremiacaoAcumulado* pInterServPremiacaoAcumulado;
					biblia::jogos::special::logica::util::InterServLogicaAcumulado* pInterServLogicaAcumulado;
					biblia::jogos::special::dados::util::InterServDConfiguracao* pInterServDConfiguracao;
					biblia::jogos::special::dados::util::InterServDEstatistica* pInterServDEstatistica;
					biblia::jogos::special::dados::util::InterServHistorico* pInterServHistorico;
					biblia::jogos::special::dados::util::InterServDadosRede* pInterServDadosRede;
					ArqGerenciadorRedeWizard* pArqGerenciadorRedeWizard;
					GerenciadorRedeWizard* pGerenciadorRedeWizard;

					RedeServidor* pRedeServidor;
					GerenciadorRede* pGerenciadorRede;

				public:
					static unsigned long RedeSpecial::key[];

					RedeSpecial::RedeSpecial(
							biblia::jogos::special::dados::DConfiguracao*,
							biblia::jogos::special::dados::Estatistica*,
							biblia::jogos::special::dados::DHistorico*,
							biblia::jogos::special::dados::UltimasJogadas*,
							GerenciadorDeProbabilidades& gerenciador,
							biblia::jogos::special::logica::LogicaAcumulado**);

					virtual GerenciadorRede* RedeSpecial::gerenciador();
					virtual biblia::jogos::special::logica::util::InterCliPremiacaoAcumulado* RedeSpecial::interCliPremiacaoAcumulado();

					virtual GerenciadorRedeWizard* RedeSpecial::gerenciadorWizard();
					virtual ArqGerenciadorRedeWizard* RedeSpecial::arqGerenciadorRedeWizard();
					virtual biblia::jogos::special::logica::util::InterServLogicaAcumulado* RedeSpecial::interServLogicaAcumulado();

					virtual RedeSpecial::~RedeSpecial();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_REDESpecial_H__68A690D4_7664_431C_9B0C_98764D018904__INCLUDED_)
