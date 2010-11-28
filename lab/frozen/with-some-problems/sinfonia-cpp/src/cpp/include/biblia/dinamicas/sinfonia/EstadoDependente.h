/**
 * $RCSfile: EstadoDependente.h,v $
 * $Date: 2005/03/02 00:30:59 $
 * $Revision: 1.15 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
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
	 * É um Estado que depende diretamente de
	 * outros Estados. Consiste numa sequencia de
	 * Estados interligados por operações que
	 * serão feitas toda vez que se obter
	 * o valor deste Estado.
	 * <p>
	 * Importante: Não existe prioridade de operadores,
	 * eles serão executados na ordem em que forem
	 * encontrados. Portanto, ao fazer por exemplo:
	 * [A].campoA + [B].campoB * [C] é como se fizesse ([A].campoA + [B].campoB) * [C].
	 * <br>Se você quer dar prioridade a alguma operação,
	 * use EstadosDependentes dentro do outro, como
	 * por exemplo:
	 * <br>EstadoDependente([A].campoA, EstadoDependente([B].campoB * [C]))
	 * (em pseudo-código).
	 * <p>
	 * É considerado externo porque não necessita de Eventos
	 * diretos para ser modificado. É um Estado usado em operações dentro
	 * das Condições ({@link Situacao}).
	 *
	 * @see Estado
	 */
	class EstadoDependente: public Estado {
		friend MediadorDeEstados;

		private:
			Lista<Identificacao> pOperacoes;
			Lista<EstadoAlvo> pEstados;
			static UniversoSequencial pSequencial;
			mutable Valor pUltimoValor; // é mutable pq é usado como buffer

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
			 * Adiciona uma operação seguida de um Estado,
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
			 * conter algum valor indefinido, o resultado será
			 * um {@link Irrelevante}.
			 * </i>
			 *
			 * @throws FuncaoNaoImplementadaExcecao Caso o campo
			 *         passado não seja {@link Estado#CAMPO_PRINCIPAL}.
			 */
			virtual const Valor& valor(const Valor& campo
					= Multifuncional::CAMPO_PRINCIPAL) const;

			// funções sem sentido para esta implementação:

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
				e << "EstadoDependente::atribui:: não é possível"
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
				e << "EstadoDependente::universo:: não é possível"
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
				e << "EstadoDependente::universoParaModificar:: não é possível"
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
