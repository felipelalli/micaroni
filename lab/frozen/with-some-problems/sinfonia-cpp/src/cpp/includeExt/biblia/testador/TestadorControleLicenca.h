/*
 * $RCSfile: TestadorControleLicenca.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_CONTROLE_LICENCA_H
#define TESTADOR_CONTROLE_LICENCA_H

#include "biblia/io/teclado/Teclado.h"
using namespace biblia::io::teclado;

#include "biblia/seguranca/ControleLicenca.h"
using namespace biblia::seguranca;

#include "biblia/armazenamento/eterno/Contador.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/io/placaio/PlacaIO.h"
using namespace biblia::io::placaio;

#include "biblia/io/contador/ContadorPlacaIO.h"
using namespace biblia::io::contador;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/io/rede/RedeUtil.h"
using namespace biblia::io::rede;

namespace biblia {
  namespace testador {

	class TestadorControleLicenca: public TestadorComSaidaEmTexto {

		private:

			ChaveSeguranca* pChaveSeguranca;

			PlacaIO* pPlacaIO;

			Contador* pContador;

			ControleLicenca* pControleLicenca;

		public:
			TestadorControleLicenca::TestadorControleLicenca(FluxoDeTexto&);

			virtual TestadorControleLicenca::~TestadorControleLicenca();

			// Executavel
			virtual Executavel& TestadorControleLicenca::executa();
	};
  }
}

#endif
