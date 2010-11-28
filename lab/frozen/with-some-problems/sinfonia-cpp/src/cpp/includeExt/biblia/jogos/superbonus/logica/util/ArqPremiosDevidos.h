/*
 * $RCSfile: ArqPremiosDevidos.h,v $
 * $Date: 2004/07/13 21:13:36 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef ARQ_PREMIOS_DEVIDOS_H
#define ARQ_PREMIOS_DEVIDOS_H

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/superbonus/logica/Premio.h"
using namespace biblia::jogos::superbonus::logica;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace logica{

				namespace util{

					class ArqPremiosDevidos : public Objeto{

						private:
							biblia::armazenamento::volatil::Lista* pLstPremios;
							Arquivo arquivo;

							void ArqPremiosDevidos::pCarregar();
							void ArqPremiosDevidos::pSalvar();

						public:
							ArqPremiosDevidos::ArqPremiosDevidos();
							ArqPremiosDevidos::~ArqPremiosDevidos();

							bool ArqPremiosDevidos::existePremioDevido();
							void ArqPremiosDevidos::tirarPremioDaLista(Premio& premio);
							void ArqPremiosDevidos::colocarPremioNaLista(Premio& premio);
					};
				}
			}
		}
	}
}

#endif