/*
 * $RCSfile: TestadorLicenca.h,v $
 * $Date: 2004/05/17 22:18:08 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef TESTADOR_LICENCA_H
#define TESTADOR_LICENCA_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/seguranca/ControleLicenca.h"
#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/io/contador/ContadorPlacaIO.h"
using namespace biblia::io::contador;

#include "biblia/io/placaio/PlacaIO.h"
using namespace biblia::io::placaio;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;


namespace biblia {
  namespace testador {

	class TestadorLicenca: public TestadorComSaidaEmTexto {

		private:

			PlacaIO* pPlacaIO;
			Contador* pContador;
			ChaveSeguranca* pChave;
			ControleLicenca* pLicenca;

		public:
			TestadorLicenca::TestadorLicenca(FluxoDeTexto&);

			virtual TestadorLicenca::~TestadorLicenca();

			// Executavel
			virtual Executavel& TestadorLicenca::executa();
	};
  }
}

#endif