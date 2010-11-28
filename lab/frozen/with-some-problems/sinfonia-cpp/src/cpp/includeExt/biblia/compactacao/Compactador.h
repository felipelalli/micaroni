/*
 * $RCSfile: Compactador.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef COMPACTADOR_H
#define COMPACTADOR_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace compactacao{

		class Compactador : public Objeto{

			public:

				static bool Compactador::compactar (const char* arquivo);
				static bool Compactador::descompactar (const char* arquivo);
		};
	}
}

#endif