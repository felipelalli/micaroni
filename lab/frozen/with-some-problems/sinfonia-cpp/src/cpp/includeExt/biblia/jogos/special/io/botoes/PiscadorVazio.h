/*
 * $RCSfile: PiscadorVazio.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_PISCADOR_VAZIO_H
#define SBS_PISCADOR_VAZIO_H

#include "biblia/jogos/special/io/botoes/Piscador.h"
using namespace biblia::jogos::special::io::botoes;

namespace biblia {
  namespace jogos {
    namespace special {
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