/*
 * $RCSfile: Empacotador.h,v $
 * $Date: 2004/01/20 15:53:28 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Empacotador_h)
#define Empacotador_h

#include "biblia/basico/Fabrica.h"
#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/volatil/Informacao.h"
#include "biblia/armazenamento/volatil/primitivos/ConhecedorDePrimitivos.h"
#include "biblia/armazenamento/eterno/empacotamento/Pacote.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace empacotamento {

		/**
		 * A partir de uma
		 * Informação específica sabe
		 * empacotar (e desempacotar).
		 */
		class Empacotador: public Objeto {
			protected:
				/**
				 * Não pode ser instanciado.
				 */
				Empacotador::Empacotador() {}

			public:
				/**
				 * Gera um novo Pacote
				 * a partir de uma Informacao
				 * devendo ser deletado
				 * de fora.
				 *
				 * @see EmpacotadorNaoSabeManipularEsseTipoExcecao
				 */
				virtual Pacote* Empacotador
						::empacota(const Informacao&) = 0;

				/**
				 * Gera uma nova Informação
				 * a partir de um Pacote
				 * devendo ser deletado
				 * de fora.
				 *
				 * @see EmpacotadorNaoSabeManipularEsseTipoExcecao
				 */
				virtual Informacao* Empacotador
						::desempacota(const Pacote&) = 0;

				/**
				 * Verifica se este empacotador
				 * sabe manipular a informação
				 * de tal tipo.
				 */
				virtual const bool Empacotador
						::sabeManipular(const Tipo&) const = 0;
		};
	  }
	}
  }
}

#endif /* Empacotador_h */
