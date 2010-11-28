/*
 * $RCSfile: ChaveSeguranca.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef CHAVE_SEGURANCA_H_SW
#define CHAVE_SEGURANCA_H_SW

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace seguranca{

		class ChaveSeguranca: public Objeto{

			private:
				unsigned long* pKey;

			public:
				ChaveSeguranca::ChaveSeguranca();
				ChaveSeguranca::ChaveSeguranca(unsigned long* key);
				virtual ChaveSeguranca::~ChaveSeguranca();

				virtual unsigned long* ChaveSeguranca::chave();
				virtual bool ChaveSeguranca::segura();
		};
	}
}

#endif