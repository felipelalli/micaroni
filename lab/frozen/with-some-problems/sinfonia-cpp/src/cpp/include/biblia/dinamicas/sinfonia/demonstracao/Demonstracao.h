/**
 * $RCSfile: Demonstracao.h,v $
 * $Date: 2005/03/04 00:38:03 $
 * $Revision: 1.1 $
 * $Author: cvsroot $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AGES_BIBLIA_SINFONIA_DEMONSTRACAO_H)
#define AGES_BIBLIA_SINFONIA_DEMONSTRACAO_H

#include <biblia/mais/allegro/Allegro.h>
using namespace biblia::mais::allegro;

#include <biblia/mais/allegro/BasicoVisualAllegro.h>
using namespace biblia::mais::allegro;


#include <biblia/io/som/CarregadorDeSom.h>
#include <biblia/io/som/ResultadoSonoro.h>
#include <biblia/io/som/Vitrola.h>
using namespace biblia::io::som;

#include <biblia/mais/fmod/FabricaDeSonsFMod.h>
using namespace biblia::mais::fmod;


#include "biblia/dinamicas/sinfonia/ScriptDinamica.h"
using namespace biblia::dinamicas::sinfonia;

#include <biblia/basico/Objeto.h>
#include <biblia/basico/Excecao.h>
using namespace biblia::basico;

#include <biblia/fluxo/Thread.h>
#include <biblia/fluxo/Executavel.h>
using namespace biblia::fluxo;

#include <biblia/util/Debug.h>
using namespace biblia::util;

#include <biblia/tempo/unidades/Milissegundo.h>
using namespace biblia::tempo::unidades;

#include <biblia/visual/dinamica/DesenhistaDeResultadoGraficoNaTela.h>
#include <biblia/visual/dinamica/CarregadorWizard.h>
using namespace biblia::visual::dinamica;

#include "biblia/dinamicas/sinfonia/Sinfonia.h"
#include "biblia/dinamicas/sinfonia/ScriptDinamica.h"
using namespace biblia::dinamicas::sinfonia;

#include "biblia/dinamicas/sinfonia/gde/Timer.h"
#include "biblia/dinamicas/sinfonia/gde/TecladoAllegro.h"
using namespace biblia::dinamicas::sinfonia::gde;

//#include "biblia/dinamicas/sinfonia/miniaplicacao/GenesisTeste.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace demonstracao {
	/**
	 * Uma aplicação teste usando a sinfonia.
	 */
	class Demonstracao: public Executavel, public Objeto {
		public:
			Demonstracao();
			virtual ~Demonstracao();

			// Executavel:
			virtual Executavel& executa();
	};
   }
  }
 }
}

#endif // !defined(AFX_MINIAPLICACAO_H__4D45CD66_2240_4D69_93B1_5B745F09E71F__INCLUDED_)
