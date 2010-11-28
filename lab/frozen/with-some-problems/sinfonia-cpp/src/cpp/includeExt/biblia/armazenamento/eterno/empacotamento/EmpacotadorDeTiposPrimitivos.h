/*
 * $RCSfile: EmpacotadorDeTiposPrimitivos.h,v $
 * $Date: 2005/01/20 21:28:32 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(EmpacotadorDeTiposPrimitivos_h)
#define EmpacotadorDeTiposPrimitivos_h

#include "biblia/armazenamento/eterno/EternoExcecao.h"
#include "biblia/armazenamento/eterno/empacotamento/Empacotador.h"

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace empacotamento {

		class EmpacotadorDeTiposPrimitivos: public Empacotador {
			private:
				ConhecedorDePrimitivos EmpacotadorDeTiposPrimitivos
						::pConhecedorDePrimitivos;

				static std::string EmpacotadorDeTiposPrimitivos
						::STRING_INDEFINIDA;

			public:
				EmpacotadorDeTiposPrimitivos
						::EmpacotadorDeTiposPrimitivos();

				virtual EmpacotadorDeTiposPrimitivos
						::~EmpacotadorDeTiposPrimitivos();

				virtual Pacote* EmpacotadorDeTiposPrimitivos
						::empacota(const Informacao&);

				virtual Informacao* EmpacotadorDeTiposPrimitivos
						::desempacota(const Pacote&);

				virtual const bool EmpacotadorDeTiposPrimitivos
						::sabeManipular(const Tipo&) const;
		};
	  }
	}
  }
}

#endif /* EmpacotadorDeTiposPrimitivos_h */
