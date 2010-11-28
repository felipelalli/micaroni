/*
 * $RCSfile: InteiroLimitado.h,v $
 * $Date: 2003/11/11 19:18:53 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(InteiroLimitado_h)
#define InteiroLimitado_h

#include "biblia/armazenamento/volatil/Universo.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"

using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace armazenamento{
    namespace volatil {
	  namespace primitivos {
	    namespace universos {
			template<int minimo, int maximo,
					 bool semLimiteMinimo = false,
					 bool semLimiteMaximo = false>
				class InteiroLimitado: public Universo
			{
				private:
					int InteiroLimitado::pMinimo;
					int InteiroLimitado::pMaximo;
					bool InteiroLimitado::pSemMinimo;
					bool InteiroLimitado::pSemMaximo;

				public:
					InteiroLimitado<minimo, maximo,
								    semLimiteMinimo,
									semLimiteMaximo>()
						:pMinimo(minimo), pMaximo(maximo),
						 pSemMinimo(semLimiteMinimo),
						 pSemMaximo(semLimiteMaximo)
					{}

					virtual const bool pertenceA(
							const Informacao& valor) const
					{
						try {
							return this->pertenceA(
									dynamic_cast<const Inteiro&>
										(valor));
						} catch(...) {
							return false;
						}
					}

					virtual const bool pertenceA(
							const Inteiro& valor) const
					{
						bool aprovado = true;

						if (!this->pSemMaximo) {
							if (valor.valor() > this->pMaximo) {
								aprovado = false;
							}
						}

						if (!this->pSemMinimo) {
							if (valor.valor() < this->pMinimo) {
								aprovado = false;
							}
						}

						return aprovado;
					}
			};
		}
	  }
	}
  }
}

#endif /* InteiroLimitado_h */
