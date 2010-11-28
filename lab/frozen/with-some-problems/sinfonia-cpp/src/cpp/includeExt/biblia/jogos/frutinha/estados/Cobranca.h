/*
 * $RCSfile: Cobranca.h,v $
 * $Date: 2005/01/20 21:28:47 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef COBRANCA_TROPCIAL_H
#define COBRANCA_TROPCIAL_H

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

				class Cobranca: public Objeto{

					private:
						/*bool pEstaNaCobranca;
						int pValor;*/

						bool pInvisivel;
						VariavelEmArquivo<bool> pEstaNaCobranca;
						VariavelEmArquivo<int> pValor;

					public:
						Cobranca::Cobranca();
						virtual Cobranca::~Cobranca();

						Cobranca& Cobranca::lanca(
								int valor, bool invisivel = false);

						Cobranca& Cobranca::some();

						Cobranca& Cobranca::invisivel(bool);
						const bool Cobranca::invisivel() const;
						bool Cobranca::estaNaCobranca();
						int  Cobranca::valor();
				};
			}
		}
	}
}

#endif