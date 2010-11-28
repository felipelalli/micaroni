/*
 * $RCSfile: LogicaAcumulado.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.12 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 *
 */

#ifndef LOGICAACUMULADO_SW_H
#define LOGICAACUMULADO_SW_H

#include "biblia/jogos/superbonus/logica/util/InterServLogicaAcumulado.h"
#include "biblia/jogos/superbonus/logica/util/InterCliLogicaAcumulado.h"
#include "biblia/jogos/superbonus/logica/util/ArqLogicaAcumuladoCliente.h"
using namespace biblia::jogos::superbonus::logica::util;


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/superbonus/logica/LogicaCredito.h"
using namespace biblia::jogos::superbonus::logica;

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

  	namespace superbonus {

	  namespace logica {

		class LogicaAcumulado : public Objeto,
								public Executavel{

		private:

			InterCliLogicaAcumulado* pInterCliLogicaAcumulado;
			ArqLogicaAcumuladoCliente pArqAcumuladoCliente;

			bool    pTerminar;
			bool    pTerminou;
			Thread* pMinhaThread;

			GerenciadorRedeWizard* pGerenciadorRedeWizard;

			double pValor;

			double pValorMaximoAcumulado;

			Subidor* pSubidor;

			InterServLogicaAcumulado* pInterServLogicaAcumulado;

			static const double LogicaAcumulado::PORC_PARA_ACUMULADO;

		public:

			LogicaAcumulado::LogicaAcumulado(GerenciadorRedeWizard* gerenciadorRedeWizard,InterServLogicaAcumulado* interServLogicaAcumulado);
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
