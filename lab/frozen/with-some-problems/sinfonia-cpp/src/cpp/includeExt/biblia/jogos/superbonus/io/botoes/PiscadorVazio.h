/*
 * $RCSfile: PiscadorVazio.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef PISCADOR_VAZIO_H
#define PISCADOR_VAZIO_H

#include "biblia/jogos/superbonus/io/botoes/Piscador.h"
using namespace biblia::jogos::superbonus::io::botoes;

namespace biblia {
  namespace jogos {
    namespace superbonus {
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