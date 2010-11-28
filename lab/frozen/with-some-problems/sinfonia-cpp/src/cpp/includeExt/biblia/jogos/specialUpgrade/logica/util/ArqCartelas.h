/*
 * $RCSfile: ArqCartelas.h,v $
 * $Date: 2005/01/19 17:22:16 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_AGES_SPECIAL_UPGRADE_ARQ_CARTELAS_BINGO_H
#define AGES_SPECIAL_UPGRADE_AGES_SPECIAL_UPGRADE_ARQ_CARTELAS_BINGO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/jogos/specialUpgrade/logica/util/Cartela.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class ArqCartelas: public Objeto{

						private:
							Arquivo pArquivo;

						public:
							ArqCartelas::ArqCartelas();
							ArqCartelas::~ArqCartelas();

							bool ArqCartelas::carregar(biblia::armazenamento::volatil::Lista& lstCartelas, int* aposta);
							void ArqCartelas::salvar(biblia::armazenamento::volatil::Lista& lstCartelas, int aposta);
					};
				}
			}
		}
	}
}

#endif