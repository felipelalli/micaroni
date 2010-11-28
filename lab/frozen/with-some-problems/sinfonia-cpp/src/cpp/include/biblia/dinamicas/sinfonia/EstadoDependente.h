/**
 * $RCSfile: EstadoDependente.h,v $
 * $Date: 2005/03/02 00:30:59 $
 * $Revision: 1.15 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_ESTADODEPENDENTE_H__DC5FAE7D_175B_44A6_BE92_C884AA390079__INCLUDED_)
#define AFX_ESTADODEPENDENTE_H__DC5FAE7D_175B_44A6_BE92_C884AA390079__INCLUDED_

#include <biblia/armazenamento/volatil/carcacas/Lista.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/dinamicas/sinfonia/Valor.h"
#include "biblia/dinamicas/sinfonia/EstadoAlvo.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	class MediadorDeEstados;

	/**
	 * � um Estado que depende diretamente de
	 * outros Estados. Consiste numa sequencia de
	 * Estados interligados por opera��es que
	 * ser�o feitas toda vez que se obter
	 * o valor deste Estado.
	 * <p>
	 * Importante: N�o existe prioridade de operadores,
	 * eles ser�o executados na ordem em que forem
	 * encontrados. Portanto, ao fazer por exemplo:
	 * [A].campoA + [B].campoB * [C] � como se fizesse ([A].campoA + [B].campoB) * [C].
	 * <br>Se voc� quer dar prioridade a alguma opera��o,
	 * use EstadosDependentes dentro do outro, como
	 * por exemplo:
	 * <br>EstadoDependente([A].campoA, EstadoDependente([B].campoB * [C]))
	 * (em pseudo-c�digo).
	 * <p>
	 * � considerado externo porque n�o necessita de Eventos
	 * diretos para ser modificado. � um Estado usado em opera��es dentro
	 * das Condi��es ({@link Situacao}).
	 *
	 * @see Estado
	 */
	class EstadoDependente: public Estado {
		friend MediadorDeEstados;

		private:
			Lista<Identificacao> pOperacoes;
			Lista<EstadoAlvo> pEstados;
			static UniversoSequencial pSequencial;
			mutable Valor pUltimoValor; // � mutable pq � usado como buffer

		protected:
			/**
			 * Cria um EstadoDependente baseado num
			 * primeiro Estado.
			 * <br><i>Esse Estado deve "sobreviver"
			 * enquanto este EstadoDependente vive.</i>
			 * Somente um {@link MediadorDeEstados} pode criar
			 * um EstadoDependente.
			 *
			 * @see MediadorDeEstados#criaEstadoDependente
			 */
			EstadoDependente(const EstadoAlvo& primeiroEstado);

		public:
			virtual ~EstadoDependente();

			/**
			 * Adiciona uma opera��o seguida de um Estado,
			 * por exemplo: + [B]
			 * <br><i>Esse Estado deve "sobreviver"
			 * enquanto este EstadoDependente vive.</i>
			 */
			virtual EstadoDependente& adicionaEstado(
					const Identificacao& operacao, const EstadoAlvo&);

			// Estado:

			/**
			 * Calcula o valor atual a partir dos outros Estados.
			 * <i>Nota importante: Caso algum dos
			 * {@link EstadoAlvo Estados-Alvos} envolvidos
			 * conter algum valor indefinido, o resultado ser�
			 * um {@link Irrelevante}.
			 * </i>
			 *
			 * @throws FuncaoNaoImplementadaExcecao Caso o campo
			 *         passado n�o seja {@link Estado#CAMPO_PRINCIPAL}.
			 */
			virtual const Valor& valor(const Valor& campo
					= Multifuncional::CAMPO_PRINCIPAL) const;

			// fun��es sem sentido para esta implementa��o:

			virtual const Momento& ultimaModificacao() const {
				FuncaoNaoImplementadaExcecao e;
				e << "EstadoDependente::ultimaModificacao::"
						" nao disponivel!";

				throw e;
			}

			/**
			 * @return {@link Estado#CAMPO_PRINCIPAL}
			 */
			virtual const Lista<Identificacao>& campos() const {
				static Lista<Identificacao> l(Multifuncional::CAMPO_PRINCIPAL.valor());
				return l;
			}

			/**
			 * @throws FuncaoNaoImplementadaExcecao
			 */
			virtual Estado& atribui(const Valor&, const UniversoDeTempo&,
					const Valor& = Multifuncional::CAMPO_PRINCIPAL)
			{
				FuncaoNaoImplementadaExcecao e;
				e << "EstadoDependente::atribui:: n�o � poss�vel"
						" atribuir valor a um EstadoDependente.";

				throw e;
				return *this;
			}

			/**
			 *  @throws FuncaoNaoImplementadaExcecao
			 */
			virtual const UniversoMultifuncional& universo(
					const Valor& = Multifuncional::CAMPO_PRINCIPAL) const
			{
				FuncaoNaoImplementadaExcecao e;
				e << "EstadoDependente::universo:: n�o � poss�vel"
						" pegar o Universo de um EstadoDependente.";

				throw e;
			}

			/**
			 * @throws FuncaoNaoImplementadaExcecao
			 */
			virtual UniversoMultifuncional& universoParaModificar(
					const Valor& = Multifuncional::CAMPO_PRINCIPAL)
			{
				FuncaoNaoImplementadaExcecao e;
				e << "EstadoDependente::universoParaModificar:: n�o � poss�vel"
						" modificar o Universo deste EstadoDependente.";

				throw e;
			}

			// Objeto:
			/**
			 * Concatena numa string os estados intercalados
			 * pelos operadores, por exemplo:
			 * "[A] + [B] * [C]"
			 */
			virtual string emString(const Valor& campo) const;
	};
  }
 }
}

#endif // !defined(AFX_ESTADODEPENDENTE_H__DC5FAE7D_175B_44A6_BE92_C884AA390079__INCLUDED_)
