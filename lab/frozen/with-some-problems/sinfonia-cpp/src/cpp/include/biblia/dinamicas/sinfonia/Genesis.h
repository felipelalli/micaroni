/**
 * $RCSfile: Genesis.h,v $
 * $Date: 2005/01/11 23:41:24 $
 * $Revision: 1.2 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_GENESIS_H__E0CF8E9F_F262_41A8_B612_54D82F191657__INCLUDED_)
#define AFX_GENESIS_H__E0CF8E9F_F262_41A8_B612_54D82F191657__INCLUDED_

#include <biblia/basico/Objeto.h>
#include <biblia/basico/Fabrica.h>
using namespace biblia::basico;

#include "biblia/dinamicas/sinfonia/Sinfonia.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	class Sinfonia;

	/**
	 * <b>É aqui onde tudo começa.</b>
	 * É uma {@link Fabrica} que gera uma {@link Sinfonia}
	 * toda montada.
	 *
	 * @see Sinfonia
	 * @see ScriptDinamica
	 */
	class Genesis: public Fabrica, public Conclusivo {
		protected:
			Genesis();

		public:
			virtual ~Genesis();

			/**
			 * Gera uma Sinfonia toda montada.
			 */
			virtual Sinfonia* geraSinfonia() = 0;

			/**
			 * Apaga todas as dinâmicas de uma {@link Sinfonia}
			 * e as cria de novo. Os estados que já existem
			 * permanecem os mesmos (inclusive os valores),
			 * os novos são criados e os que não existem mais
			 * <b>não</b> são deletados.
			 */
			virtual Genesis& recarrega(Sinfonia*) = 0;

			// Fabrica:
			virtual Objeto* gera() {
				return (Objeto*) this->geraSinfonia();
			}
	};
  }
 }
}

#endif // !defined(AFX_GENESIS_H__E0CF8E9F_F262_41A8_B612_54D82F191657__INCLUDED_)
