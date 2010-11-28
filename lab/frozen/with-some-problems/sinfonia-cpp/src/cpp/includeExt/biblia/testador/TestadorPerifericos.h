/*
 * $RCSfile: TestadorPerifericos.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_PERIFERICOS_H
#define TESTADOR_PERIFERICOS_H


#include "biblia/io/placaio/PlacaIO.h"
using namespace biblia::io::placaio;

#include "biblia/io/display/DisplaySpider.h"
using namespace biblia::io::display;

#include "biblia/io/contador/ContadorPlacaIO.h"
using namespace biblia::io::contador;

#include "biblia/io/noteiro/LeitorNotas.h"
#include "biblia/io/noteiro/LeitorNotasSmiles.h"
#include "biblia/io/noteiro/LeitorNotasJCM.h"
using namespace biblia::io::noteiro;

#include "biblia/jogos/superbonus/io/botoes/LuzBotoes.h"
#include "biblia/jogos/superbonus/io/botoes/Botoes.h"
#include "biblia/jogos/superbonus/io/botoes/BotoesPlacaIO.h"
#include "biblia/jogos/superbonus/io/botoes/BotoesAllegro.h"
using namespace biblia::jogos::superbonus::io::botoes;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace testador {

	class TestadorPerifericos: public TestadorComSaidaEmTexto {

		private:
			Display* displaySpider;
			PlacaIO* placaIO;
			Botoes* botoes;
			LeitorNotas* leitor;
			LuzBotoes* luzBotoes;
			Contador* contadorP;


		public:
			TestadorPerifericos::TestadorPerifericos(FluxoDeTexto&);

			virtual TestadorPerifericos::~TestadorPerifericos();

			// Executavel
			virtual Executavel& TestadorPerifericos::executa();
	};
  }
}

#endif
