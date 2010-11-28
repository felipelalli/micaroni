/*
 * $RCSfile: Igualavel.h,v $
 * $Date: 2004/03/29 21:50:59 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_IGUALAVEL_H__E16C56E4_7420_4802_91AD_B189A25E4930__INCLUDED_)
#define AFX_IGUALAVEL_H__E16C56E4_7420_4802_91AD_B189A25E4930__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Excecao.h"
#include "biblia/basico/Interface.h"

namespace biblia {
  namespace basico {
	/**
	 * Representa tudo aquilo que pode ser igual a ou
	 * diferente de um outro Igualavel. Compara o
	 * <i>conte�do</i> do objeto; para verificar
	 * se � a <i>mesma inst�ncia</i> utilize a fun��o
	 * {@link biblia::basico::Objeto::mesmaInstancia(const Objeto*) const}
	 * da classe {@link biblia::basico::Objeto}.
	 * <p>
	 * Implementa os operadores == e != baseado no resultado
	 * (n�o aqui implementado) da fun��o
	 * {@link #igual(const Igualavel&)}.
	 * Considera que o operador diferente (!=) �
	 * equivalente a !(obj1 == obj2).
	 * <p>
	 * <i> Nota: Semelhante � defini��o da fun��o
	 * <code>boolean equals(Object)</code>
	 * da classe <code>java.lang.Object</code> do Java.
	 * </i>
	 */
	class Igualavel: public Interface {
		protected:
			Igualavel::Igualavel() {};

		public:
			virtual Igualavel::~Igualavel() {};

			/**
			 * <i>Nota para implementa��o:
			 * Seja ClasseFilha o nome da classe
			 * que implementar� esta interface. Veja
			 * um exemplo de como lan�ar a exce��o
			 * IncompatibilidadeDeTiposExcecao no
			 * caso de incompatibilidade de tipos:
			 *
			 * <code>
			 * 	try {
					const ClasseFilha& objeto
							= dynamic_cast<const ClasseFilha&>(alheio);

					// uso do objeto
				} catch (const bad_cast&) {
					IncompatibilidadeDeTiposExcecao e;
					throw e;
				}
			 * </code>
			 * </i>
			 *
			 * @return verdadeiro caso o Igualavel comparado
			 *         possua <i>o mesmo conte�do</i> que este
			 *         (n�o sendo necessariamente a mesma
			 *         inst�ncia).
			 *
			 * @throws IncompatibilidadeDeTiposExcecao
			 *         � invocado quando n�o � poss�vel
			 *         fazer a compara��o por incompatibilidade
			 *         de tipos.
			 *
			 * @throws bad_cast � invocado quando houver erro
			 *                  na convers�o dos tipos.
			 */
			virtual const bool Igualavel::igual(
					const Igualavel& alheio) const = 0;

			// Operadores conseq�entes:
			/**
			 * @see #igual(const Igualavel&) const
			 */
			virtual const bool Igualavel::operator==(const Igualavel& i) const {
				return this->igual(i);
			}

			/**
			 * @see #igual(const Igualavel&) const
			 */
			virtual const bool Igualavel::operator!=(const Igualavel& i) const {
				return !this->igual(i);
			}
	};
  }
}

#endif // !defined(AFX_IGUALAVEL_H__E16C56E4_7420_4802_91AD_B189A25E4930__INCLUDED_)
