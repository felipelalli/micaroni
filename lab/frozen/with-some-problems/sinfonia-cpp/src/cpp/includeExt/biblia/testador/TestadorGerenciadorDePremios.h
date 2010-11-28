/*
 * $RCSfile: TestadorGerenciadorDePremios.h,v $
 * $Date: 2003/07/08 00:18:08 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef TESTADOR_GERENCIADOR_DE_PREMIOS_H
#define TESTADOR_GERENCIADOR_DE_PREMIOS_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/UltraLong.h"
#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;


#include "biblia/jogos/bingo/logica/LogicaCartelas.h"
#include "biblia/jogos/bingo/logica/GerenciadorDePremios.h"
using namespace biblia::jogos::bingo::logica;

#include "biblia/jogos/bingo/logica/util/CarregadorDeProbabilidades.h"
using namespace biblia::jogos::bingo::logica::util;


namespace biblia {
  namespace testador {

	class TestadorGerenciadorDePremios: public TestadorComSaidaEmTexto {

		private:
			LogicaCartelas* pCartelas;
			GerenciadorDePremios pGerenciador;

			void TestadorGerenciadorDePremios::pIniciaCartelas();
			void TestadorGerenciadorDePremios::pMarcaCartelas();
			void TestadorGerenciadorDePremios::pConsomeEventosCartela();

			void TestadorGerenciadorDePremios::pInfoJogo();
			void TestadorGerenciadorDePremios::pMostraPremios();
			void TestadorGerenciadorDePremios::pMostraPremios(biblia::jogos::bingo::logica::util::Premio& premio);

		public:
			TestadorGerenciadorDePremios::TestadorGerenciadorDePremios(FluxoDeTexto&);

			virtual TestadorGerenciadorDePremios::~TestadorGerenciadorDePremios();

			// Executavel
			virtual Executavel& TestadorGerenciadorDePremios::executa();
	};
  }
}

#endif
