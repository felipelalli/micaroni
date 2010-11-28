/*
 * $RCSfile: ArqPremiosDevidos.h,v $
 * $Date: 2004/05/17 21:07:17 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef ARQ_PREMIOS_DEVIDOS_BASE_H
#define ARQ_PREMIOS_DEVIDOS_BASE_H

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace jogos{

		namespace bingo{

			namespace logica{

				namespace util{

					class ArqPremiosDevidos : public Objeto{

						private:
							ListaInt pLstPremios;
							Arquivo arquivo;

							void ArqPremiosDevidos::pCarregar();
							void ArqPremiosDevidos::pSalvar();

						public:
							ArqPremiosDevidos::ArqPremiosDevidos();
							ArqPremiosDevidos::~ArqPremiosDevidos();

							bool ArqPremiosDevidos::existePremioDevido();
							int ArqPremiosDevidos::tirarPremioDaLista();
							void ArqPremiosDevidos::colocarPremioNaLista(int premio);
					};
				}
			}
		}
	}
}

#endif