/*
 * $RCSfile: TestadorRedeBasico.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TESTADOR_REDE_BASICO_H
#define TESTADOR_REDE_BASICO_H


#include "biblia/io/rede/RedeServidor.h"
#include "biblia/io/rede/RedeCliente.h"
using namespace biblia::io::rede;

#include "biblia/io/rede/interfaces/interfacesCliente/InterCliRedeTeste.h"
using namespace biblia::io::rede::interfaces::interfacesCliente;

#include "biblia/io/rede/interfaces/interfacesServidor/InterServRedeTeste.h"
using namespace biblia::io::rede::interfaces::interfacesServidor;

#include "biblia/testador/TestadorComSaidaEmTexto.h"
using namespace biblia::testador;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace testador {

	class TestadorRedeBasico: public TestadorComSaidaEmTexto {

		private:

			ChaveSeguranca* pChaveSeguranca;

			InterCliRedeTeste*  pInterCliRedeTeste;
			InterServRedeTeste* pInterServRedeTeste;

			RedeServidor* pRedeServidor;
			RedeCliente*  pRedeCliente;

		public:
			TestadorRedeBasico::TestadorRedeBasico(FluxoDeTexto&);

			virtual TestadorRedeBasico::~TestadorRedeBasico();

			// Executavel
			virtual Executavel& TestadorRedeBasico::executa();
	};
  }
}

#endif
