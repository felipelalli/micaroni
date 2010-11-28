/**
 * $RCSfile: CondicaoDeComparacao.h,v $
 * $Date: 2005/03/04 00:32:16 $
 * $Revision: 1.11 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_CONDICAODECOMPARACAO_H__AFFE2531_0D40_4620_B14C_DE17864B9A8B__INCLUDED_)
#define AFX_CONDICAODECOMPARACAO_H__AFFE2531_0D40_4620_B14C_DE17864B9A8B__INCLUDED_

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include "biblia/dinamicas/sinfonia/EstadoAlvo.h"
#include "biblia/dinamicas/sinfonia/Evento.h"
#include "biblia/dinamicas/sinfonia/Condicao.h"
#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Relativo à CondicaoDeComparacao.
	 * @see CondicaoDeComparacao
	 */
    class CondicaoDeComparacaoExcecao: public SinfoniaExcecao {};

	/**
	 * É invocado quando dois Estados não podem
	 * ser comparados com o operador específico.
	 *
	 * @see CondicaoDeComparacao
	 */
	class ImpossivelCompararExcecao: public CondicaoDeComparacaoExcecao {};

	/**
	 * Faz a comparação (on-line) entre dois Estados.
	 */
	class CondicaoDeComparacao: public Condicao {
		private:
			EstadoAlvo pEstado1;
			EstadoAlvo pEstado2;
			Identificacao pOperador;

		public:
			/**
			 * Este construtor de cópia leva adiante a referência,
			 * i. e., não faz cópia.
			 */
			CondicaoDeComparacao(const CondicaoDeComparacao&);

			/**
			 * [estado1].campoA = [estado2].campoB
			 * <br>[estado1].campoC < [estado2].campoD
			 * <p>
			 * O resultado da operação passada como parâmetro
			 * tem que ser boleana, caso contrário resultados
			 * inesperados podem acontecer sem aviso de erro!
			 * <p>
			 * Para fazer algo do tipo:
			 * <br>[estado1].campoA + [estado2] < 56 + [estado3]
			 * use {@link EstadoDependente} para calcular
			 * <br>[estado1].campoA + [estado2] e 56 + [estado3]
			 * separadamente e depois unir por uma comparação
			 * através desta classe.
			 *
			 * @see Estado
			 * @see EstadoAlvo
			 * @see EstadoDependente
			 */
			CondicaoDeComparacao(
					const EstadoAlvo& estado1,
					const Identificacao& operacao,
					const EstadoAlvo& estado2);

			virtual ~CondicaoDeComparacao();

			// Condicao:
			/**
			 * @throws ImpossivelCompararExcecao
			 *         É invocado quando o resultado da
			 *         operação não é um boleano.
			 */
			virtual bool verdadeira() const;

			// Copiavel:
			virtual Objeto* geraCopia() const;
			virtual Copiavel& copiaEmSi(const Copiavel& alheio);

			// Objeto:
			/**
			 * Concatena o primeiro Estado,
			 * a operação de comparação e o segundo
			 * Estado, assim ó:
			 * <p>
			 * [A].campoA > [B]
			 */
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_CONDICAODECOMPARACAO_H__AFFE2531_0D40_4620_B14C_DE17864B9A8B__INCLUDED_)
