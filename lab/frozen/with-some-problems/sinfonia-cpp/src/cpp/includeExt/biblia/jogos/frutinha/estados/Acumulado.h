/*
 * $RCSfile: Acumulado.h,v $
 * $Date: 2004/05/07 01:31:33 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef ACUMULADO_TROPCIAL_H
#define ACUMULADO_TROPCIAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class Acumulado: public Objeto{
					private:
						//double Acumulado::pValor;
						VariavelEmArquivo<double> Acumulado::pValor;
						VariavelEmArquivo<bool> Acumulado::pDeveSumir;

					public:
						Acumulado::Acumulado();
						virtual Acumulado::~Acumulado();

						/* Lanca a anima��o do acumulado com o valor passado */
						Acumulado& Acumulado::lancaAcumulado(double valor);

						/* Tira anima��o do acumulado da tela */
						Acumulado& Acumulado::some();

						/* Indica que o acumulado deve sumir (� consumido) */
						const bool Acumulado::deveSumir();
						Acumulado& Acumulado::deveSumir(bool);

						const double& Acumulado::valor() const;
						const bool Acumulado::estaNoAcumulado() const;
				};
			}
		}
	}
}

#endif