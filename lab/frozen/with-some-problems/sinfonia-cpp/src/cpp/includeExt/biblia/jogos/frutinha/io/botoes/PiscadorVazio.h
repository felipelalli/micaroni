/*
 * $RCSfile: PiscadorVazio.h,v $
 * $Date: 2004/05/31 04:26:32 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef SBS_PISCADOR_VAZIO_H_TROPICAL
#define SBS_PISCADOR_VAZIO_H_TROPICAL

#include "biblia/jogos/frutinha/io/botoes/Piscador.h"
using namespace biblia::jogos::frutinha::io::botoes;

namespace biblia {
  namespace jogos {
    namespace frutinha {
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