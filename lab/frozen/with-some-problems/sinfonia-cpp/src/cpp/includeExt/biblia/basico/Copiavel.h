/*
 * $RCSfile: Copiavel.h,v $
 * $Date: 2004/03/29 21:50:59 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_COPIAVEL_H__49BBD776_E305_4EC3_98E4_EA979E744AE0__INCLUDED_)
#define AFX_COPIAVEL_H__49BBD776_E305_4EC3_98E4_EA979E744AE0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Excecao.h"
#include "biblia/basico/Interface.h"

namespace biblia {
  namespace basico {
	/**
 	 * Representa tudo que pode ser copiado.
	 * <p>
	 * Geralmente classes que possuem um
	 * construtor padrão de cópia têm a
	 * característica de serem "copiáveis"; mas apesar
	 * disso, o construtor de cópia padrão fica independente
	 * desta interface, i. e., quem a implementa não
	 * necessita ter um construtor de cópia padrão e a
	 * classe que tem um construtor de cópia padrão não
	 * precisa implementar esta interface.
	 * <p>
	 * Nem sempre a cópia de informações é <i>possível</i> ou
	 * <i>segura</i>, principalmente quando envolve a opção
	 * de copiar ou não referência-por-referência
	 * interna. A princípio esta interface define
	 * que a cópia é completa, i. e., todos os
	 * campos internos são copiados um-a-um e nenhuma
	 * referência é levada adiante. Caso a
	 * implementação específica leve alguma referência
	 * adiante isso deve estar especificado na
	 * documentação.
	 * <p>
	 * <i> Nota: Semelhante à interface
	 * <code>java.lang.Coneable</code> do Java.
	 * </i>
	 */
	class Copiavel: public Interface {
		protected:
			Copiavel::Copiavel() {}

		public:
			virtual Copiavel::~Copiavel() {}

			/**
			 * Gera uma cópia campo-a-campo desta
			 * instância "Copiavel". A implementação
			 * de cópia varia de implementação para
			 * implementação, consulte a documentação
			 * específica da classe em questão. A instância
			 * gerada <b>deve</b> ser apagada de fora.
			 */
			virtual Objeto* geraCopia() const = 0;

			/**
			 * Copia o conteúdo de outro Copiável
			 * <b>sobrescrevendo</b> este.
			 * <p>
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
			 * @throws IncompatibilidadeDeTiposExcecao
			 *         É invocado quando, por incompatibilidade
			 *         de tipos entre a instância passada e esta,
			 *         não é possível copiar o objeto alheio em si.
			 *
			 * @throws bad_cast É invocado quando houver erro
			 *                  na conversão dos tipos.
			 */
			virtual Copiavel& copiaEmSi(const Copiavel& alheio) = 0;

			// Operadores conseqüentes:
			/**
			 * @see #copiaEmSi(const Copiavel&)
			 */
			virtual Copiavel& Copiavel::operator=(const Copiavel& alheio) {
				this->copiaEmSi(alheio);
				return *this;
			}
	};
  }
}

#endif // !defined(AFX_COPIAVEL_H__49BBD776_E305_4EC3_98E4_EA979E744AE0__INCLUDED_)
