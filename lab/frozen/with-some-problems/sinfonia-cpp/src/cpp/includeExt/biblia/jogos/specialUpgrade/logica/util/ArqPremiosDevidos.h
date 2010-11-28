/*
 * $RCSfile: ArqPremiosDevidos.h,v $
 * $Date: 2005/01/19 17:22:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_AGES_SPECIAL_UPGRADE_ARQ_PREMIOS_DEVIDOS_BASE_H
#define AGES_SPECIAL_UPGRADE_AGES_SPECIAL_UPGRADE_ARQ_PREMIOS_DEVIDOS_BASE_H

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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