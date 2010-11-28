/*
 * $RCSfile: Ajuda.h,v $
 * $Date: 2005/01/20 21:28:47 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef AJUDA_TROPCIAL_H
#define AJUDA_TROPCIAL_H

#include <string>
using namespace std;

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class Ajuda: public Objeto{

					private:
						/*
						bool pEstaNaAjuda;
						int pQualPagina;
						*/
						VariavelEmArquivo<bool> pEstaNaAjuda;
						VariavelEmArquivo<int> pQualPagina;

						enum Definicoes{
							QTS_PAGINAS = 2
						};

					public:
						Ajuda::Ajuda();
						virtual Ajuda::~Ajuda();

						Ajuda& Ajuda::estaNaAjuda (bool sim_nao);
						Ajuda& Ajuda::proximaPagina ();

						bool Ajuda::estaNaAjuda();
						int  Ajuda::paginaAtual();
						int  Ajuda::qtsPaginas();

						std::string Ajuda::nomeDaPagina(int qualPagina);
				};
			}
		}
	}
}

#endif