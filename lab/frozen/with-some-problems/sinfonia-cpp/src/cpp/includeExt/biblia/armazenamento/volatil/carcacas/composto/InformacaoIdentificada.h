/*
 * $RCSfile: InformacaoIdentificada.h,v $
 * $Date: 2004/02/02 19:44:52 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(InformacaoIdentificada_h)
#define InformacaoIdentificada_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/volatil/Informacao.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace carcacas {
	    namespace composto {
			/**
			 * Agrupa conceitualmente uma Informacao
			 * a uma Identificacao, identificando
			 * a informação.
			 *
			 * @see Composto
			 */
			class InformacaoIdentificada: public Objeto {
				private:
					Informacao* InformacaoIdentificada
							::pInformacao;

					Identificacao
							InformacaoIdentificada
								::pIdentidade;

				public:
					InformacaoIdentificada
							::InformacaoIdentificada(
									const Identificacao&,
									Informacao*);

					virtual InformacaoIdentificada
							::~InformacaoIdentificada();

					virtual const Identificacao& InformacaoIdentificada
							::identificacao() const;

					virtual const Informacao& InformacaoIdentificada
							::informacao() const;

					virtual Informacao& InformacaoIdentificada
							::informacao();

					virtual InformacaoIdentificada&
							InformacaoIdentificada
								::operator=(const
									InformacaoIdentificada& i);
			};
		}
	  }
	}
  }
}

#endif /* InformacaoIdentificada_h */
