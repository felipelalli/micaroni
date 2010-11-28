/*
 * $RCSfile: LogicaAcumulado.h,v $
 * $Date: 2005/01/19 17:22:12 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 *
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_SBS_LOGICAACUMULADO_SW_H
#define AGES_SPECIAL_UPGRADE_SBS_LOGICAACUMULADO_SW_H

#include "biblia/jogos/specialUpgrade/logica/util/InterServLogicaAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterCliLogicaAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/util/ArqLogicaAcumuladoCliente.h"
using namespace biblia::jogos::specialUpgrade::logica::util;


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/specialUpgrade/logica/LogicaCredito.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/util/Subidor.h"
using namespace biblia::util;

namespace biblia {

  namespace jogos {

  	namespace specialUpgrade {

	  namespace logica {

		class LogicaAcumulado : public Objeto,
								public Executavel{

		private:

			biblia::jogos::specialUpgrade::logica::util::InterCliLogicaAcumulado* pInterCliLogicaAcumulado;
			biblia::jogos::specialUpgrade::logica::util::ArqLogicaAcumuladoCliente pArqAcumuladoCliente;

			bool    pTerminar;
			bool    pTerminou;
			Thread* pMinhaThread;

			GerenciadorRedeWizard* pGerenciadorRedeWizard;

			double pValor;

			double pValorMaximoAcumulado;

			Subidor* pSubidor;

			biblia::jogos::specialUpgrade::logica::util::InterServLogicaAcumulado* pInterServLogicaAcumulado;

			static const double LogicaAcumulado::PORC_PARA_ACUMULADO;

		public:

			LogicaAcumulado::LogicaAcumulado(GerenciadorRedeWizard* gerenciadorRedeWizard,biblia::jogos::specialUpgrade::logica::util::InterServLogicaAcumulado* interServLogicaAcumulado);
			virtual LogicaAcumulado::~LogicaAcumulado();

			double LogicaAcumulado::getAcumulado();
			double LogicaAcumulado::premiarAcumulado();
			bool   LogicaAcumulado::setAcumulado(double novoValor);

			void   LogicaAcumulado::adicionarJogada(int qtsCreditos);

			bool   LogicaAcumulado::falhaDeRede();

			Executavel& LogicaAcumulado::executa();

		};
	  }
	}
  }
}

#endif
