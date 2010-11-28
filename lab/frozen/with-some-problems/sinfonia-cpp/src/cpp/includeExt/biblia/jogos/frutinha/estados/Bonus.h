/*
 * $RCSfile: Bonus.h,v $
 * $Date: 2004/03/29 21:50:59 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef BONUS_TROPCIAL_H
#define BONUS_TROPCIAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class Bonus: public Objeto{

					private:
						/*int pPremio;
						int pAposta;
						bool pEstaAnimando;
						*/
						VariavelEmArquivo<int> pPremio;
						VariavelEmArquivo<int> pAposta;
						VariavelEmArquivo<bool> pEstaAnimando;

					public:
						Bonus::Bonus();
						virtual Bonus::~Bonus();

						/* Lanca a animação do bonus com o valor passado */
						Bonus& Bonus::lancaBonus(int premio);

						/* Tira animação do bonus da tela */
						Bonus& Bonus::some();

						const int& Bonus::premio() const;
						const bool Bonus::estaNoBonus() const;

						bool Bonus::estaAnimando();
						Bonus& Bonus::setEstaAnimando (bool animando);

						Bonus& Bonus::setAposta (int aposta);
						int Bonus::aposta();
				};
			}
		}
	}
}

#endif