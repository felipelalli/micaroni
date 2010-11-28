/*
 * $RCSfile: PiscadorVazio.h,v $
 * $Date: 2005/01/19 17:22:08 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_PISCADOR_VAZIO_H
#define AGES_SPECIAL_UPGRADE_SBS_PISCADOR_VAZIO_H

#include "biblia/jogos/specialUpgrade/io/botoes/Piscador.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
      namespace io {
        namespace botoes {
			class PiscadorVazio: public Piscador{

				public:
					PiscadorVazio::PiscadorVazio ():Piscador() {};
					virtual PiscadorVazio::~PiscadorVazio() {};

					virtual void PiscadorVazio::apagarTodos() {};
					virtual void PiscadorVazio::piscar (const Botao& botao) {};
					virtual void PiscadorVazio::acender(const Botao& botao) {};
					virtual void PiscadorVazio::apagar (const Botao& botao) {};

					virtual bool PiscadorVazio::piscando (const Botao& botao) { return false; };
					virtual bool PiscadorVazio::aceso(const Botao& botao) { return false; };
					virtual bool PiscadorVazio::apagado (const Botao& botao) { return false; };

					virtual Executavel& PiscadorVazio::executa() { return *this;};
			};
		}
	  }
	}
  }
}

#endif