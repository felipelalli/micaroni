/*
 * $RCSfile: LogicaSimulador.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef LOGICA_SIMULADOR_H
#define LOGICA_SIMULADOR_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/jogos/superbonus/logica/Logicas.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/jogos/superbonus/simulador/ListaJogadas.h"
using namespace biblia::jogos::superbonus::simulador;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace simulador{

				class LogicaSimulador: public Executavel, public Objeto{

					private:

						Logicas* pLogicas;

						double pProbCompraBELinhaDupla;
						double pProbCompraBEBingo;

						double pConcorreAcumulado;
						double pEstaNoDobro;
						int    pQtsJogadasDobro;

						double LogicaSimulador::pGetProbBE (int premio);

						ListaJogadas* pJogadas;

					public:
						LogicaSimulador::LogicaSimulador();
						LogicaSimulador::~LogicaSimulador();

						void LogicaSimulador::setCreditos (int creditos);
						void LogicaSimulador::setAposta   (int aposta);
						void LogicaSimulador::setCartelas (int qtsCartelas);
						void LogicaSimulador::setProbCompraBolaExtra (int premio, double prob);

						ListaJogadas* LogicaSimulador::getJogadas();

						Executavel& LogicaSimulador::executa();
				};
			}
		}
	}
}

#endif