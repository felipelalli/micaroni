/*
 * $RCSfile: NumerosNaturais.h,v $
 * $Date: 2003/11/11 19:18:53 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(NumerosNaturais_h)
#define NumerosNaturais_h

#include "biblia/armazenamento/volatil/Universo.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
#include "biblia/armazenamento/volatil/primitivos/Flutuante.h"

using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace armazenamento{
    namespace volatil {
	  namespace primitivos {
	    namespace universos {
			class NumerosNaturais: public Universo {
				public:
					NumerosNaturais::NumerosNaturais();

					virtual const bool NumerosNaturais::pertenceA(
							const Informacao& valor) const
					{
						if (valor.indefinida()) {
							return false;
						}

						try {
							return this->pertenceA(
									dynamic_cast<const Inteiro&>
										(valor));
						} catch(...) {
							return false;
						}
					}

					virtual const bool NumerosNaturais::pertenceA(
							const Flutuante& valor) const;

					virtual const bool NumerosNaturais::pertenceA(
							const Inteiro& valor) const;
			};
		}
	  }
	}
  }
}

#endif /* NumerosNaturais_h */
