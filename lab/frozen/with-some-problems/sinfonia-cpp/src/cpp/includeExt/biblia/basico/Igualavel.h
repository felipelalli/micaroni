/*
 * $RCSfile: Igualavel.h,v $
 * $Date: 2004/03/29 21:50:59 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
	 * <i>conteúdo</i> do objeto; para verificar
	 * se é a <i>mesma instância</i> utilize a função
	 * {@link biblia::basico::Objeto::mesmaInstancia(const Objeto*) const}
	 * da classe {@link biblia::basico::Objeto}.
	 * <p>
	 * Implementa os operadores == e != baseado no resultado
	 * (não aqui implementado) da função
	 * {@link #igual(const Igualavel&)}.
	 * Considera que o operador diferente (!=) é
	 * equivalente a !(obj1 == obj2).
	 * <p>
	 * <i> Nota: Semelhante à definição da função
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
			 * <i>Nota para implementação:
			 * Seja ClasseFilha o nome da classe
			 * que implementará esta interface. Veja
			 * um exemplo de como lançar a exceção
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
			 *         possua <i>o mesmo conteúdo</i> que este
			 *         (não sendo necessariamente a mesma
			 *         instância).
			 *
			 * @throws IncompatibilidadeDeTiposExcecao
			 *         É invocado quando não é possível
			 *         fazer a comparação por incompatibilidade
			 *         de tipos.
			 *
			 * @throws bad_cast É invocado quando houver erro
			 *                  na conversão dos tipos.
			 */
			virtual const bool Igualavel::igual(
					const Igualavel& alheio) const = 0;

			// Operadores conseqüentes:
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
