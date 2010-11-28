/*
 * $RCSfile: RodadorScript.h,v $
 * $Date: 2005/01/20 21:28:44 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef RODADOR_SCRIPT_H
#define RODADOR_SCRIPT_H


#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#ifndef WIN32
#include <stdlib.h>
#endif

namespace biblia{

	namespace io{

		namespace script{

			class RodadorScript: public Executavel{
				private:
					Thread* pThread;
					bool pTerminouDeRodar;
					bool pSucesso;
					std::string pCaminhoScript;

				public:
					RodadorScript::RodadorScript (std::string caminhoScript);
					RodadorScript::~RodadorScript();

					bool RodadorScript::terminouDeRodar();
					bool RodadorScript::sucesso();
					void RodadorScript::rodar();
					void RodadorScript::esperarTerminarDeRodar();

					Executavel& RodadorScript::executa();
			};
		}
	}
}
#endif