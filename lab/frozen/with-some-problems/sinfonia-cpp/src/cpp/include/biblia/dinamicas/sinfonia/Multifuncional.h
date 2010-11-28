/**
 * $RCSfile: Multifuncional.h,v $
 * $Date: 2005/02/23 22:32:50 $
 * $Revision: 1.5 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_MULTIFUNCIONAL_H__594FB0B6_CE4A_4186_A426_9AA7E3F3F278__INCLUDED_)
#define AFX_MULTIFUNCIONAL_H__594FB0B6_CE4A_4186_A426_9AA7E3F3F278__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <biblia/basico/Identificacao.h>
using namespace biblia::basico;

#include <biblia/fluxo/Executavel.h>
using namespace biblia::fluxo;

#include "biblia/dinamicas/sinfonia/Classe.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * A classe funcional é uma classe "genérica"
	 * dos tipos primitivos (bool, int, double, string).
	 * Ela sabe aplicar os operadores básicos como
	 * atribuição, not, or, and, divisão,
	 * multiplicação, subtração, adição e comparações.
	 */
	class Multifuncional: public Classe {
		public:
			/**
			 * É o nome do campo principal de um {@link Multifuncional}.
			 * Um {@link Multifuncional} pode possuir diversos campos
			 * mas o principal é o que fica em evidência.
			 * É definido como <b>&#42 PRINCIPAL</b>.
			 */
			static Valor CAMPO_PRINCIPAL;

			Multifuncional();
			virtual ~Multifuncional();

			// Operações possíveis:
			static Identificacao NOT;
			static Identificacao OR;
			static Identificacao AND;
			static Identificacao DIVIDIDO;
			static Identificacao VEZES;
			static Identificacao MENOS;
			static Identificacao MAIS;
			static Identificacao IGUALDADE;
			static Identificacao DIFERENCA;
			static Identificacao MENOR;
			static Identificacao MAIOR;
			static Identificacao MENOR_OU_IGUAL;
			static Identificacao MAIOR_OU_IGUAL;

			// Classe:
			virtual const Valor aplica(const Valor& valor,
					const Identificacao& acao, const Lista<const Valor*>& valores) const;
	};
  }
 }
}

#endif // !defined(AFX_MULTIFUNCIONAL_H__594FB0B6_CE4A_4186_A426_9AA7E3F3F278__INCLUDED_)
