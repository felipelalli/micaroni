/*
 * $RCSfile: Copiavel.h,v $
 * $Date: 2004/03/29 21:50:59 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
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
	 * construtor padr�o de c�pia t�m a
	 * caracter�stica de serem "copi�veis"; mas apesar
	 * disso, o construtor de c�pia padr�o fica independente
	 * desta interface, i. e., quem a implementa n�o
	 * necessita ter um construtor de c�pia padr�o e a
	 * classe que tem um construtor de c�pia padr�o n�o
	 * precisa implementar esta interface.
	 * <p>
	 * Nem sempre a c�pia de informa��es � <i>poss�vel</i> ou
	 * <i>segura</i>, principalmente quando envolve a op��o
	 * de copiar ou n�o refer�ncia-por-refer�ncia
	 * interna. A princ�pio esta interface define
	 * que a c�pia � completa, i. e., todos os
	 * campos internos s�o copiados um-a-um e nenhuma
	 * refer�ncia � levada adiante. Caso a
	 * implementa��o espec�fica leve alguma refer�ncia
	 * adiante isso deve estar especificado na
	 * documenta��o.
	 * <p>
	 * <i> Nota: Semelhante � interface
	 * <code>java.lang.Coneable</code> do Java.
	 * </i>
	 */
	class Copiavel: public Interface {
		protected:
			Copiavel::Copiavel() {}

		public:
			virtual Copiavel::~Copiavel() {}

			/**
			 * Gera uma c�pia campo-a-campo desta
			 * inst�ncia "Copiavel". A implementa��o
			 * de c�pia varia de implementa��o para
			 * implementa��o, consulte a documenta��o
			 * espec�fica da classe em quest�o. A inst�ncia
			 * gerada <b>deve</b> ser apagada de fora.
			 */
			virtual Objeto* geraCopia() const = 0;

			/**
			 * Copia o conte�do de outro Copi�vel
			 * <b>sobrescrevendo</b> este.
			 * <p>
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
			 * @throws IncompatibilidadeDeTiposExcecao
			 *         � invocado quando, por incompatibilidade
			 *         de tipos entre a inst�ncia passada e esta,
			 *         n�o � poss�vel copiar o objeto alheio em si.
			 *
			 * @throws bad_cast � invocado quando houver erro
			 *                  na convers�o dos tipos.
			 */
			virtual Copiavel& copiaEmSi(const Copiavel& alheio) = 0;

			// Operadores conseq�entes:
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
