/**
 * $RCSfile: Universo.h,v $
 * $Date: 2004/12/10 00:25:02 $
 * $Revision: 1.10 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_UNIVERSO_H__FEB0436F_F222_4786_ADED_6899116724E9__INCLUDED_)
#define AFX_UNIVERSO_H__FEB0436F_F222_4786_ADED_6899116724E9__INCLUDED_

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include "biblia/dinamicas/sinfonia/Valor.h"
#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Exceções relacionadas a um Universo.
	 *
	 * @see Universo
	 */
	class UniversoExcecao: public SinfoniaExcecao {};

	/**
	 * É quando um valor não pertence
	 * a um Universo.
	 *
	 * @see Universo
	 */
	class ValorForaDeIntervaloExcecao: public UniversoExcecao {};

	class Vazio;
	class PodeTudo;

	/**
	 * Representa um Universo que pode conter
	 * ou não determinado Valor.
	 *
	 * @see Valor
	 */
	class Universo: public Objeto {
		protected:
			Universo();

		public:
			/**
			 * Não pode nada.
			 */
			static const Vazio VAZIO;

			/**
			 * Aceita qualquer coisa.
			 */
			static const PodeTudo PODE_TUDO;

			virtual ~Universo();

			/**
			 * Verifica se o valor está contido neste Universo.
			 */
			virtual const bool estaContido(const Valor&) const = 0;

			/**
			 * Captura o valor correspondente para o uso de apelidos.
			 * Por padrão deve retornar o valor Irrelevante caso
			 * não haja correspondente.
			 */
			virtual const Valor& correspondente(const Valor&) const = 0;
	};

	/**
	 * Um Universo que não contém nada.
	 */
	class Vazio: public Universo {
			virtual const bool estaContido(const Valor&) const {
				return false;
			}

			virtual const Valor& correspondente(const Valor&) const {
				static Irrelevante i;
				return i;
			}
	};

	/**
	 * Um Universo que contém qualquer coisa.
	 */
	class PodeTudo: public Universo {
			virtual const bool estaContido(const Valor&) const {
				return true;
			}

			virtual const Valor& correspondente(const Valor&) const {
				static Irrelevante i;
				return i;
			}
	};
  }
 }
}

#endif // !defined(AFX_UNIVERSO_H__FEB0436F_F222_4786_ADED_6899116724E9__INCLUDED_)
