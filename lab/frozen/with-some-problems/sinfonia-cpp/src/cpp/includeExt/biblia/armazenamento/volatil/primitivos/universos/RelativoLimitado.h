/*
 * $RCSfile: RelativoLimitado.h,v $
 * $Date: 2003/11/11 19:18:53 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(RelativoLimitado_h)
#define RelativoLimitado_h

#include "biblia/armazenamento/volatil/Universo.h"
#include "biblia/armazenamento/volatil/primitivos/Relativo.h"

using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::primitivos;

//#include "biblia/util/Debug.h"
//using namespace biblia::util;

namespace biblia {
  namespace armazenamento{
    namespace volatil {
	  namespace primitivos {
	    namespace universos {
//			template<double minimo, double maximo,
			template<int minimo, int maximo,
					 bool semLimiteParaMinimo = false,
					 bool semLimiteParaMaximo = false>
				class RelativoLimitado: public Universo
			{
				private:
					//double RelativoLimitado::pMinimo;
					//double RelativoLimitado::pMaximo;
					int RelativoLimitado::pMinimo; // FIXME: devia ser double
					int RelativoLimitado::pMaximo; // pau na compilação no MSVC 7.0
					bool RelativoLimitado::pSemMinimo;
					bool RelativoLimitado::pSemMaximo;

				public:
					RelativoLimitado<minimo, maximo,
								     semLimiteParaMinimo,
									 semLimiteParaMaximo>()
						:pMinimo(minimo), pMaximo(maximo),
						 pSemMinimo(semLimiteParaMinimo),
						 pSemMaximo(semLimiteParaMaximo)
					{}
 
					virtual const bool pertenceA(
							const Informacao& valor) const
					{
						try {
							return this->pertenceA(
									dynamic_cast<const Relativo&>
										(valor));
						} catch(...) {
							return false;
						}
					}

					virtual const bool pertenceA(
							const Relativo& valor) const
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

#endif /* RelativoLimitado_h */
