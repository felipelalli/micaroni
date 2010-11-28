/*
 * $RCSfile: TestadorMatematica.h,v $
 * $Date: 2004/06/09 15:45:54 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef TESTADOR_MATEMATICA_H
#define TESTADOR_MATEMATICA_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/tempo/UniversoSistema.h"
#include "biblia/tempo/UltraLong.h"
#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/jogos/special/logica/Logicas.h"
using namespace biblia::jogos::special::logica;

#include "biblia/jogos/bingo/logica/GerenciadorDeFluxoDeJogo.h"
using namespace biblia::jogos::bingo::logica;

namespace biblia {
  namespace testador {

	class TestadorMatematica: public TestadorComSaidaEmTexto {

		private:
			biblia::jogos::special::logica::Logicas pLogicas;		
			
			GerenciadorDeFluxoDeJogo* pFluxoDeJogo;

			UniversoSistema pUniverso;

			bool TestadorMatematica::pJoga();
			void TestadorMatematica::pJogaDiretoDoGerenciador();
			void TestadorMatematica::pMostrarInfoDiretoDoGerenciador();
			void TestadorMatematica::pGeraListaDePremiosSozinhos(int iPremio,ListaInt& lstPremios);
			void TestadorMatematica::pMostrarPercentuais();
			void TestadorMatematica::pGeraPercentuais();
			void TestadorMatematica::pMostraAjuda();
			void TestadorMatematica::pMostraIntervalosPremiacao();

		public:
			TestadorMatematica::TestadorMatematica(FluxoDeTexto&,UniversoDeTempo&);

			virtual TestadorMatematica::~TestadorMatematica();

			// Executavel
			virtual Executavel& TestadorMatematica::executa();
	};
  }
}

#endif
