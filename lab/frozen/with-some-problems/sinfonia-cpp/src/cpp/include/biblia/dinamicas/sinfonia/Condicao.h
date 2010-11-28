/**
 * $RCSfile: Condicao.h,v $
 * $Date: 2005/01/13 02:18:09 $
 * $Revision: 1.7 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_CONDICAO_H__0A9D78CC_0A39_4A2D_8DB6_69FBEEBC362A__INCLUDED_)
#define AFX_CONDICAO_H__0A9D78CC_0A39_4A2D_8DB6_69FBEEBC362A__INCLUDED_

#include <biblia/basico/Objeto.h>
#include <biblia/basico/Copiavel.h>
using namespace biblia::basico;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Esta Condicao pode ser verdadeira ou falsa.
	 * Circunst�ncia ou requisito sem o qual determinada
	 * causa n�o pode produzir o seu efeito.
	 *
	 * @see CondicaoComposta
	 * @see CondicaoModificadora
	 * @see CondicaoDeComparacao
	 */
	class Condicao: public Objeto, public Copiavel {
		protected:
			Condicao() {};

		public:
			virtual ~Condicao() {};

			virtual bool falsa() const {
				return !this->verdadeira();
			}

			virtual bool verdadeira() const = 0;

			// Copiavel:
			virtual Objeto* geraCopia() const = 0;
			virtual Copiavel& copiaEmSi(const Copiavel& alheio) = 0;

			// Objeto:
			/**
			 * Retorna V ou F.
			 */
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_CONDICAO_H__0A9D78CC_0A39_4A2D_8DB6_69FBEEBC362A__INCLUDED_)
