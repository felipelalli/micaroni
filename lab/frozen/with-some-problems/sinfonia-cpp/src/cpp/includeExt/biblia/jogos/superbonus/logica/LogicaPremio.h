/*
 * $RCSfile: LogicaPremio.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#include <stdlib.h>
#include <stdio.h>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/jogos/superbonus/logica/Premio.h"

#ifndef LOGICAPREMIO_SW_H
#define LOGICAPREMIO_SW_H

#define MAX_APOSTA 20

using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {

		class LogicaPremio : public Objeto{

			private:
				unsigned short pAposta;
				unsigned int pBaseCantos;
				unsigned int pBaseLinha;
				unsigned int pBaseLinhaDupla;
				unsigned int pBaseBingo;

			public:

				LogicaPremio::LogicaPremio (unsigned int   baseCantos      = 1,
											unsigned int   baseLinha       = 4,
											unsigned int   baseLinhaDupla  = 100,
											unsigned int   baseBingo       = 1000,
											unsigned short aposta          = 1);

				LogicaPremio::~LogicaPremio();

				void LogicaPremio::atualizarBases (unsigned int   baseCantos      = 1,
												   unsigned int   baseLinha       = 4,
												   unsigned int   baseLinhaDupla  = 100,
												   unsigned int   baseBingo       = 1000,
												   unsigned short aposta          = 1);

				unsigned int LogicaPremio::aposta();

				void LogicaPremio::aumentarAposta ();

				void LogicaPremio::diminuirAposta ();

				unsigned int LogicaPremio::valorPremio (unsigned int premio);

				const char* LogicaPremio::premio(const int& premio) const;
		};
	  }
	}
  }
}

#endif
