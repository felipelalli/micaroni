/*
 * $RCSfile: RunLock.h,v $
 * $Date: 2004/05/17 22:09:49 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef RUN_LOCK_H
#define RUN_LOCK_H

#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace io{

		namespace disco{

			class RunLock : public Objeto{

				private:
					ChaveSeguranca* pChave;

				public:
					RunLock::RunLock(ChaveSeguranca* chave);
					RunLock::~RunLock();

					bool RunLock::podeRodar();

			};
		}
	}
}

#endif