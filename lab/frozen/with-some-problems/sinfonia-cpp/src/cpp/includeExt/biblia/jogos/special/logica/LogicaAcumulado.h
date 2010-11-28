/*
 * $RCSfile: LogicaAcumulado.h,v $
 * $Date: 2003/07/21 19:40:47 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 *
 */

#ifndef SBS_LOGICAACUMULADO_SW_H
#define SBS_LOGICAACUMULADO_SW_H

#include "biblia/jogos/special/logica/util/InterServLogicaAcumulado.h"
#include "biblia/jogos/special/logica/util/InterCliLogicaAcumulado.h"
#include "biblia/jogos/special/logica/util/ArqLogicaAcumuladoCliente.h"
using namespace biblia::jogos::special::logica::util;


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/special/logica/LogicaCredito.h"
using namespace biblia::jogos::special::logica;

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

  	namespace special {

	  namespace logica {

		class LogicaAcumulado : public Objeto,
								public Executavel{

		private:

			biblia::jogos::special::logica::util::InterCliLogicaAcumulado* pInterCliLogicaAcumulado;
			biblia::jogos::special::logica::util::ArqLogicaAcumuladoCliente pArqAcumuladoCliente;

			bool    pTerminar;
			bool    pTerminou;
			Thread* pMinhaThread;

			GerenciadorRedeWizard* pGerenciadorRedeWizard;

			double pValor;

			double pValorMaximoAcumulado;

			Subidor* pSubidor;

			biblia::jogos::special::logica::util::InterServLogicaAcumulado* pInterServLogicaAcumulado;

			static const double LogicaAcumulado::PORC_PARA_ACUMULADO;

		public:

			LogicaAcumulado::LogicaAcumulado(GerenciadorRedeWizard* gerenciadorRedeWizard,biblia::jogos::special::logica::util::InterServLogicaAcumulado* interServLogicaAcumulado);
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
