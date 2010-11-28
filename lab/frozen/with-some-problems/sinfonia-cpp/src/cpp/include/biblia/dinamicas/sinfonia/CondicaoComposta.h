/**
 * $RCSfile: CondicaoComposta.h,v $
 * $Date: 2005/01/13 02:18:09 $
 * $Revision: 1.6 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_CONDICAOCOMPOSTA_H__72CD1EDD_E0C2_4FC4_966B_5FCDFD74EF90__INCLUDED_)
#define AFX_CONDICAOCOMPOSTA_H__72CD1EDD_E0C2_4FC4_966B_5FCDFD74EF90__INCLUDED_

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/armazenamento/volatil/carcacas/Lista.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/dinamicas/sinfonia/Condicao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Representa as possibilidades:
	 * AND (e), OR (ou), XOR (ou exclusivo) ou EQ (igual).
	 */
	enum Ligacao {AND, OR, XOR, EQ, DIF};

	/**
	 * Uma Condicao que � composta de uma ou mais
	 * Condicoes unidas por uma Ligacao.
	 *
	 * @see Ligacao
	 * @see Condicao
	 */
	class CondicaoComposta: public Condicao {
		private:
			Lixeira pLixo;
			Lista<Ligacao> pLigacoes;
			Lista<Condicao*> pCondicoes;

			CondicaoComposta();

		public:
			/**
			 * Cria uma CondicaoComposta a partir
			 * de uma primeira.
			 * <p>
			 * <i>Cuidado: este construtor
			 * pode confundir com o de c�pia, portanto,
			 * para copiar, use apenas a fun��o {@link #geraCopia()}.</i>
			 */
			CondicaoComposta(const Condicao& primeiraCondicao);

			virtual ~CondicaoComposta();

			/**
			 * Adiciona uma Condicao a esta CondicaoComposta.
			 *
			 * Obs.: Pega para si a responsabilidade
			 * de excluir a condi��o passada.
			 */
			virtual CondicaoComposta& adiciona(
					const Ligacao& ligacao, const Condicao&);

			// Condicao:
			virtual bool verdadeira() const;

			// Copiavel:
			virtual Objeto* geraCopia() const;
			virtual Copiavel& copiaEmSi(const Copiavel& alheio);

			// Objeto:
			/**
			 * Retorna <b><code>(cond1 OPERADOR cond2)</code></b>.
			 */
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_CONDICAOCOMPOSTA_H__72CD1EDD_E0C2_4FC4_966B_5FCDFD74EF90__INCLUDED_)
