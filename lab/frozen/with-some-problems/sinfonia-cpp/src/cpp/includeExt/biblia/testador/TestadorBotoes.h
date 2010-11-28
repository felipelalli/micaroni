/*
 * $RCSfile: TestadorBotoes.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_BOTOES_H
#define TESTADOR_BOTOES_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/jogos/superbonus/io/botoes/Botoes.h"
#include "biblia/jogos/superbonus/io/botoes/BotoesPlacaIO.h"
#include "biblia/jogos/superbonus/io/botoes/BotoesAllegro.h"
using namespace biblia::jogos::superbonus::io::botoes;

#include "biblia/io/placaio/PlacaIO.h"
using namespace biblia::io::placaio;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;


namespace biblia {

  namespace testador {

	class TestadorBotoes: public TestadorComSaidaEmTexto {

		private:
			Botoes* pBotoes;

		public:
			TestadorBotoes::TestadorBotoes(FluxoDeTexto&);

			virtual TestadorBotoes::~TestadorBotoes();

			Executavel& TestadorBotoes::executa();
	};
  }
}

#endif
