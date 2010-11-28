/**
 * $RCSfile: Classe.h,v $
 * $Date: 2005/01/27 22:42:24 $
 * $Revision: 1.12 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_CLASSE_H__81E5C6F7_F587_4826_87F3_7B62205B5699__INCLUDED_)
#define AFX_CLASSE_H__81E5C6F7_F587_4826_87F3_7B62205B5699__INCLUDED_

#include <biblia/basico/Identificacao.h>
using namespace biblia::basico;

#include "biblia/dinamicas/sinfonia/Rotulado.h"
#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/** 
	 * Exce��es relativas � Classe.
	 *
	 * @see Classe
	 */
	class ClasseExcecao: public SinfoniaExcecao {};

	/** 
	 * Quando uma a��o n�o est� dispon�vel
	 * numa Classe qualquer.
	 *
	 * @see Classe
	 */
	class AcaoIndisponivelExcecao: public ClasseExcecao {};

	/**
	 * � a id�ia de uma "classe" bem simplificada,
	 * que consiste em poss�veis a��es que podem ser aplicadas em
	 * valores (da classe Valor, que � bem vers�til e simples).
	 * <p>
	 * Obs.: Por Valor ser uma classe simples (sem a possibilidade de
	 * composi��o de valores) e esta classe trabalhar somente
	 * com valores (e n�o composto de valores) esta �
	 * limitada apenas a esse n�vel b�sico.
	 *
	 * @todo No futuro, fazer com que esta classe e a
	 *       Estado trabalhem com Informa��es e
	 *       n�o somente Valor.
	 *
	 * @see Valor
	 * @see Multifuncional
	 */
	class Classe: public Rotulado {	
		private:
			Lista<Identificacao> pAcoesPossiveis;
			Lista<Identificacao> pCampos;

		protected:
			Classe(const Valor& nome);

			/**
			 * Lista o nome das a��es que esta classe sabe aplicar.
			 * <i>Deve ser atualizado pela classe
			 * filha.</i>
			 */
			Lista<Identificacao>& acoes();

			/**
			 * Lista o nome dos campos que esta classe tem.
			 * <i>Deve ser atualizado pela classe
			 * filha.</i>
			 */
			Lista<Identificacao>& camposParaModificar();

		public:
			virtual ~Classe();

			/**
			 * @throws AcaoIndisponivelExcecao
			 */
			virtual const Valor aplica(const Valor& valorA,
					const Identificacao& acao, const Valor& valorB = Irrelevante()) const
			{
				const Valor* novoValor = (const Valor*) valorB.geraCopia();
				Lista<const Valor*> valores;

				if (valorB != Irrelevante()) {
					valores.adiciona(novoValor);
				}

				Valor retorno(this->aplica(valorA, acao, valores));
				delete novoValor;
				return retorno;
			}

			/**
			 * @throws AcaoIndisponivelExcecao
			 */
			virtual const Valor aplica(const Valor& valor,
					const Identificacao& acao, const Lista<const Valor*>& valores) const = 0;

			/**
			 * Retorna uma lista de a��es poss�veis desta classe.
			 */
			virtual const Lista<Identificacao>& acoesPossiveis() const;

			/**
			 * Retorna uma lista dos nomes dos campos que existem nessa classe.
			 */
			virtual const Lista<Identificacao>& campos() const;
	};
  }
 }
}

#endif // !defined(AFX_CLASSE_H__81E5C6F7_F587_4826_87F3_7B62205B5699__INCLUDED_)
