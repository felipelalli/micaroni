/*
 * $RCSfile: ArqCartelas.h,v $
 * $Date: 2004/06/16 00:31:27 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef ARQ_CARTELAS_BINGO_H
#define ARQ_CARTELAS_BINGO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/jogos/bingo/logica/util/Cartela.h"
using namespace biblia::jogos::bingo::logica::util;

namespace biblia{

	namespace jogos{

		namespace bingo{

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