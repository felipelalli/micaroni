/**
 * $RCSfile: UniversoMultifuncional.h,v $
 * $Date: 2005/01/27 22:42:26 $
 * $Revision: 1.6 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_UNIVERSOMULTIFUNCIONAL_H__792E6EEE_A147_4044_B52C_37D382BA88CC__INCLUDED_)
#define AFX_UNIVERSOMULTIFUNCIONAL_H__792E6EEE_A147_4044_B52C_37D382BA88CC__INCLUDED_

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/armazenamento/volatil/carcacas/MapaHash.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/dinamicas/sinfonia/Universo.h"
#include "biblia/dinamicas/sinfonia/Multifuncional.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * � um Universo que controla as restri��es dos tipos b�sicos,
	 * como um conjunto de string poss�veis, proibidas ou um
	 * intervalo poss�vel de valor (maior que, menor que etc.).
	 * <p>
	 * A princ�pio aceita qualquer valor, at� que alguma
	 * restri��o seja feita. Se for adicionado pelo menos uma possibilidade
	 * atrav�s da fun��o "adicionaPossibilidade" ser�o aceitas
	 * <b>somente</b> as possibilidades que forem adicionadas.
	 * Caso seja adicionado alguma proibi��o atrav�s da fun��o
	 * "adicionaNaoPodeSer" todos os elementos ser�o permitidos,
	 * exceto os que forem adicionados por esta fun��o. Caso seja
	 * adicionado possibilidades e proibi��es, os valores poss�veis
	 * ser�o o conjunto dos adicionados por "adicionaPossibilidade"
	 * exceto os que estiverem no conjunto "adicionaNaoPodeSer".
	 */
	class UniversoMultifuncional: public Universo {
		private:
			/**
			 * Para um acesso instant�neo.
			 */
			MapaHash<const Valor*> pPossibilidades;
			MapaHash<const Valor*> pNaoPodeSer;
			Lixeira pLixo;
			Valor pMenorQue;
			Valor pMaiorQue;

		public:
			/**
			 * A princ�pio aceita todas as possibilidades
			 * e depois de criado vai sendo restringido
			 * a partir das fun��es definidas.
			 */
			UniversoMultifuncional();
			virtual ~UniversoMultifuncional();

			virtual UniversoMultifuncional& maiorQue(const Valor&);
			virtual UniversoMultifuncional& menorQue(const Valor&);
			virtual UniversoMultifuncional& maiorOuIgualA(const Valor&);
			virtual UniversoMultifuncional& menorOuIgualA(const Valor&);

			/**
			 * Adiciona um valor que este Universo n�o pode aceitar.
			 * @see #adicionaPossibilidade(const Valor&)
			 */
			virtual UniversoMultifuncional& adicionaNaoPodeSer(const Valor&);

			/**
			 * Adiciona uma possibilidade a este Universo.
			 * @see #adicionaNaoPodeSer(const Valor&)
			 */
			virtual UniversoMultifuncional& adicionaPossibilidade(const Valor&);

			/**
			 * Apenas para consulta, porque � lento e n�o cont�m
			 * os apelidos.
			 *
			 * @return deve ser deletado externamente.
			 */
			virtual Lista<Identificacao>* possibilidades() const;

			/**
			 * Apenas para consulta, porque � lento e n�o cont�m
			 * os apelidos.
			 *
			 * @return deve ser deletado externamente.
			 */
			virtual Lista<Identificacao>* naoPodeAssumir() const;

			// Universo:
			virtual const bool estaContido(const Valor&) const;
			virtual const Valor& correspondente(const Valor&) const;

			// Objeto:
			/**
			 * Retorna no formato:
			 * <br>aceita somente: {a, b, c, ...}
			 *     e n�o aceita {d, e, f, ...}
			 */
			virtual string emString() const;
	};
  }
 }
}

#endif // !defined(AFX_UNIVERSOMULTIFUNCIONAL_H__792E6EEE_A147_4044_B52C_37D382BA88CC__INCLUDED_)
