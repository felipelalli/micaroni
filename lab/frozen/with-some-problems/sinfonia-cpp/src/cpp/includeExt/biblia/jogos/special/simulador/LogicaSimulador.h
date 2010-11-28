/*
 * $RCSfile: LogicaSimulador.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_LOGICA_SIMULADOR_H
#define SBS_LOGICA_SIMULADOR_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/jogos/special/logica/Logicas.h"
using namespace biblia::jogos::special::logica;

#include "biblia/jogos/special/simulador/ListaJogadas.h"
using namespace biblia::jogos::special::simulador;

namespace biblia{

	namespace jogos{

		namespace special{

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