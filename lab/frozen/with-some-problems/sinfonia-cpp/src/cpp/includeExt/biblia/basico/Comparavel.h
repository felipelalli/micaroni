/*
 * $RCSfile: Comparavel.h,v $
 * $Date: 2004/03/29 21:50:59 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_COMPARAVEL_H__3C550F6F_309B_46A7_8CB8_8ADB768E1819__INCLUDED_)
#define AFX_COMPARAVEL_H__3C550F6F_309B_46A7_8CB8_8ADB768E1819__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Igualavel.h"

namespace biblia {
  namespace basico {
	/**
	 * Representa tudo aquilo que pode ser comparado com
	 * outro Comparavel. Pode ser igual, diferente, menor, maior,
	 * menor ou igual, maior ou igual.
	 * <p>
	 * Implementa os operadores ==, !=, <, >, <= e >=
	 * baseado no resultado abstrato das funções
	 * {@link #igual(const Igualavel&)} e
	 * {@link #menorQue(const Comparavel&)}.
	 * <p>
	 * Provavelmente, tudo que pode ser comparado
	 * é composto de um valor principal mensurável.
	 * <p>
	 * <i> Nota: Semelhante à interface
	 * <code>java.lang.Comparable</code> do Java.
	 * </i>
	 */
	class Comparavel: public Igualavel {
		protected:
			Comparavel::Comparavel() {}
	
		public:
			virtual Comparavel::~Comparavel() {}

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
			 * @return verdadeiro caso este
			 *         possua <i>um conteúdo</i> "menor"
			 *         que um outro Comparavel.
			 *
			 * @throws IncompatibilidadeDeTiposExcecao
			 *         É invocado quando não é possível
			 *         fazer a comparação por incompatibilidade
			 *         de tipos.
			 *
			 * @throws bad_cast É invocado quando houver erro
			 *                  na conversão dos tipos.
			 */
			virtual const bool Comparavel
					::menorQue(const Comparavel& alheio) const = 0;

			// Igualavel:
			virtual const bool Comparavel::igual(
					const Igualavel& alheio) const = 0;

			// Operadores conseqüentes:
			/**
			 * @see #menorQue(const Comparavel&) const
			 */
			virtual const bool Comparavel::operator<(const Comparavel& c) const {
				return this->menorQue(c);
			}

			/**
			 * @see #menorQue(const Comparavel&) const
			 */
			virtual const bool Comparavel::operator>(const Comparavel& c) const {
				return c.menorQue(*this);
			}

			/**
			 * @see #menorQue(const Comparavel&) const
			 * @see igual(const Igualavel&) const
			 */
			virtual const bool Comparavel::operator<=(const Comparavel& c) const {
				return this->igual(c)
					|| this->menorQue(c);
			}

			/**
			 * @see #menorQue(const Comparavel&) const
			 * @see igual(const Igualavel&) const
			 */
			virtual const bool Comparavel::operator>=(const Comparavel& c) const {
				return this->igual(c)
					|| c.menorQue(*this);
			}
	};
  }
}

#endif // !defined(AFX_COMPARAVEL_H__3C550F6F_309B_46A7_8CB8_8ADB768E1819__INCLUDED_)
