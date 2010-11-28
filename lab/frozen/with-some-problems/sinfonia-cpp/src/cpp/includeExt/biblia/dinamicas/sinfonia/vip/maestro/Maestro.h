/*
 * $RCSfile: Maestro.h,v $
 * $Date: 2005/03/03 03:32:38 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Maestro_h)
#define Maestro_h

#include "biblia/util/Lixeira.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/dinamicas/sinfonia/evento/DistribuidorDeEventos.h"
#include "biblia/dinamicas/sinfonia/evento/RegistroDeEventos.h"
#include "biblia/dinamicas/sinfonia/vip/maquinadeestados/MaquinaDeEstados.h"
#include "biblia/dinamicas/sinfonia/vip/maestro/TransportaParaMaquinaDeEstados.h"
#include "biblia/dinamicas/sinfonia/vip/maestro/TransportaParaRegistroDeEventos.h"
#include "biblia/dinamicas/sinfonia/vip/maestro/TransportaParaLixeira.h"

using namespace biblia::util;
using namespace biblia::fluxo;
using namespace biblia::dinamicas::sinfonia::evento;
using namespace biblia::dinamicas::sinfonia::vip::maquinadeestados;

namespace biblia {
  namespace dinamicas {
	namespace sinfonia {
	  namespace vip {
		namespace maestro {
			/**
			 * Distribui os Eventos para uma Máquina de Estados e contém
			 * funcionalidades de controle dos Eventos.
			 * 
			 * É um DistribuidorDeEventos que possui três
			 * TransportadoresDeEvento específicos (MaquinaDeEstados, Registro
			 * e Lixeira).
			 */
			class Maestro: public DistribuidorDeEventos {
				private:
					MaquinaDeEstados* Maestro::pMaquinaDeEstados;
					Lixeira* Maestro::pLixeira;
					RegistroDeEventos* Maestro::pRegistroDeEventos;
					TransportaParaMaquinaDeEstados* Maestro
							::pTransportaParaMaquinaDeEstados;

					TransportaParaRegistroDeEventos* Maestro
							::pTransportaParaRegistroDeEventos;

					TransportaParaLixeira* Maestro
							::pTransportaParaLixeira;

				public:
					virtual Executavel& Maestro::executa();

			};
		}
	  }
	}
  }
}

#endif /* Maestro_h */
