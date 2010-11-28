/*
 * $RCSfile: CriadorDeEstadosIniciais.h,v $
 * $Date: 2005/03/03 03:32:27 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(CriadorDeEstadosIniciais_h)
#define CriadorDeEstadosIniciais_h

#include "biblia/basico/Objeto.h"
#include "biblia/util/Wizard.h"
#include "biblia/util/instrucoes/ConjuntoDeInstrucoes.h"
#include "biblia/dinamicas/sinfonia/estado/origem/FabricaDeEstados.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::util::instrucoes;
using namespace biblia::dinamicas::sinfonia::estado::origem;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
      namespace estado {
	    namespace origem {
		  namespace wizard {
			/**
			 * A partir de um conjunto e instruções que
			 * teria possivelmente a
			 * definição de cada estado e seu valor
			 * inicial cria um conjunto de
			 * EstadosIniciais para ser adicionado
			 * a primeira vez na Geladeira
			 * caso ela esteja vazia.
			 */
			class CriadorDeEstadosIniciais
					:public Wizard, public Objeto
			{
				private:
					FabricaDeEstados* CriadorDeEstadosIniciais
							::pFabricaDeEstados;
			};
		  }
		}
	  }
	}
  }
}

#endif /* CriadorDeEstadosIniciais_h */
