/*
 * $RCSfile: Universo.h,v $
 * $Date: 2005/01/20 21:28:35 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Universo_h)
#define Universo_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Interface.h"
#include "biblia/armazenamento/volatil/Informacao.h"

using namespace biblia::basico;

namespace biblia {
  namespace armazenamento{
    namespace volatil {

		/**
		 * Representa um Universo de valores de uma
		 * determinada Informacao.
		 * <p>Uma Informacao � associada a um Universo que diz
		 * se determinado valor pertence a ele ou n�o.
		 * <p>Essa classe conhece a classe
		 * Informacao.
		 * <p><i>Para que a classe
		 * InformacaoRestrita<> funcione adequadamente
		 * � importante que as classes
		 * que desta derivam possuam um construtor
		 * padr�o (sem argumentos).</i>
		 */
		class Universo: public Interface, public Objeto {
			public:
				/**
				 * Verifica se a informa��o passada
				 * como par�metro pertence a este
				 * Universo.
				 */
				virtual const bool Universo::pertenceA(
						const Informacao& valor) const = 0;

				/**
				 * @ throws ForaDoUniversoExcecao
				 */
				virtual const Universo& Universo
						::valida(const Informacao& valor) const
				{
					if (!this->pertenceA(valor)) {
						ForaDoUniversoExcecao e;
						e << std::string() + "Universo"
							+ "::valida(...)::"
							+ " informa��o fora do universo v�lido!"
							+ " Informa��o: "
							+ valor
							+ " - Universo: "
							+ *this;

						throw e;
					}

					return *this;
				}
		};

		/**
		 * Universo especial: sempre retorna verdadeiro,
		 * aceita qualquer informa��o.
		 */
		class Todos: public Universo {
			const bool Todos::percenteA(
					const Informacao& valor) const
			{
				return true;
			}
		};
	}
  }
}

#endif /* Universo_h */
