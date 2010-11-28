/*
 * $RCSfile: LogicaCredito.h,v $
 * $Date: 2004/05/17 21:58:08 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include <stdlib.h>
#include <stdio.h>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/jogos/superbonus/logica/Premio.h"
#include "biblia/seguranca/SecureMessage.h"
#include "biblia/io/disco/Arquivo.h"

#ifdef WIN32
#include <io.h>
#else
#include <unistd.h>
#include <errno.h>
#endif


#ifndef LOGICACREDITO_SW_H
#define LOGICACREDITO_SW_H


#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::seguranca;
using namespace biblia::io::disco;


namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {

		class LogicaCredito : public Objeto{

			private:

				unsigned int pCredito;
				static float pCredVal; //Valor em dinheiro de cada credito
				bool pSimulacao;


				void LogicaCredito::gravaCreditos();
				unsigned int LogicaCredito::leCreditos();

				unsigned long* LogicaCredito::pKey;
				Arquivo LogicaCredito::arquivo;

			public:
				LogicaCredito::LogicaCredito(
						bool security = false,
						unsigned long* key = NULL,
						bool simulacao = false);

				LogicaCredito::~LogicaCredito();
				unsigned int LogicaCredito::credito();
				void LogicaCredito::aumentar(unsigned int credito);
				void LogicaCredito::diminuir (unsigned int credito);
				bool LogicaCredito::podeJogar (unsigned int credito);
				void LogicaCredito::zerar ();


				static void         LogicaCredito::AtualizarCredVal(float credVal);
				static unsigned int LogicaCredito::toCredito(double dinheiro);
				static float        LogicaCredito::toDinheiro(unsigned int credito);


		};
	  }
	}
  }
}

#endif
