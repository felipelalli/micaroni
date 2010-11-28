/**
 * $RCSfile: Multifuncional.h,v $
 * $Date: 2005/02/23 22:32:50 $
 * $Revision: 1.5 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
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
	 * A classe funcional � uma classe "gen�rica"
	 * dos tipos primitivos (bool, int, double, string).
	 * Ela sabe aplicar os operadores b�sicos como
	 * atribui��o, not, or, and, divis�o,
	 * multiplica��o, subtra��o, adi��o e compara��es.
	 */
	class Multifuncional: public Classe {
		public:
			/**
			 * � o nome do campo principal de um {@link Multifuncional}.
			 * Um {@link Multifuncional} pode possuir diversos campos
			 * mas o principal � o que fica em evid�ncia.
			 * � definido como <b>&#42 PRINCIPAL</b>.
			 */
			static Valor CAMPO_PRINCIPAL;

			Multifuncional();
			virtual ~Multifuncional();

			// Opera��es poss�veis:
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
