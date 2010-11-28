/*
 * $RCSfile: SorteioBolas.h,v $
 * $Date: 2005/01/20 21:29:00 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#include "biblia/sorte/Sorteio.h"
#include "biblia/util/Debug.h"
#include <time.h>
#include <stdlib.h>
//#include "biblia/sorte/randomc.h"

using namespace biblia::util;
using namespace biblia::sorte;

#ifndef SORTEIO_SW_H
#define SORTEIO_SW_H

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {

		class SorteioBolas : public Sorteio {
			private:
				bool pRepetir;
				unsigned int pMaxNumeros;
				unsigned int pQtsNumeros;
				unsigned int* pNumeros;
				unsigned int* pNumProb;
				unsigned int pQtsNumProb;
				unsigned int pProb;

			public:
				SorteioBolas::SorteioBolas(std::string nomeProcesso);
				virtual SorteioBolas::~SorteioBolas();
				virtual void SorteioBolas::setProbabilidade (unsigned int* numeros=NULL, unsigned int qtsNumeros=0, unsigned int probabilidade=0);
				virtual void SorteioBolas::zerarNumeros();
				virtual void SorteioBolas::qtsNumeros (unsigned int numeros);
				virtual void SorteioBolas::repetirNumeros(bool repetir);
				virtual int SorteioBolas::sortear (unsigned int inicio, unsigned int fim);

				// fixme: por que não compila sem isto. e o pai?
				virtual double SorteioBolas::sortear();
		};
	  }
	}
  }
}

#endif
