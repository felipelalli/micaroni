/*
 * $RCSfile: Subidor.h,v $
 * $Date: 2003/07/31 21:20:49 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SUBIDOR_H
#define SUBIDOR_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#define SLEEP_ACUMULADO_MIN   10
#define SLEEP_ACUMULADO_MAX  400
#define SLEEP_ACUMULADO		   5

namespace biblia{

	namespace util{

		/**
		 * @fixme Tirar deste util e colocar num util
		 *        dentro do jogo específico. Isso não
		 *        é um 'util' genérico para a bíblia
		 *        porque contém coisas específicas como
		 *        SLEEP_ACUMULADO_MAX, por exemplo.
		 */
		class Subidor : public Objeto, public Executavel{

			private:

				long pSleep;
				double pValorAtual;
				double pValorFinal;

				Semaforo* pSema;
				Thread* pThread;

				bool pTerminar;
				bool pTerminou;

			public:

				Subidor::Subidor();
				Subidor::~Subidor();

				void Subidor::setValorAtual(double valorAtual);
				void Subidor::setValorFinal(double valorFinal);

				double Subidor::getValor();

				Executavel& Subidor::executa ();

		};
	}
}


#endif