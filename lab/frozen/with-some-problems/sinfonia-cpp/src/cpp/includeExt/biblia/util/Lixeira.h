/*
 * $RCSfile: Lixeira.h,v $
 * $Date: 2005/01/20 21:29:31 $
 * $Revision: 1.13 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_LIXEIRA_H__6465D257_9173_424E_87A2_35C9FA13603F__INCLUDED_)
#define AFX_LIXEIRA_H__6465D257_9173_424E_87A2_35C9FA13603F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Conclusivo.h"
#include "biblia/util/UtilExcecao.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace util {

	/**
	 * Para facilitar a exclus�o de
	 * {@link biblia::basico::Objeto}s
	 * em s�rie.
	 * <p>
	 * Armazena um conjunto de ponteiros
	 * para objetos que dever�o ser futuramente
	 * deletados. Quando esta lixeira perde o escopo ou
	 * � deletada, ela automaticamente se
	 * "auto-destr�i", apagando todos os elementos
	 * na ordem contr�ria a que foram adicionados
	 * a ela. Essa ordem contr�ria (do mesmo
	 * jeito que uma pilha) � importante devido
	 * �s depend�ncias das inst�ncias.
	 */
	class Lixeira: public Objeto {
		private:
			std::deque<Objeto*> Lixeira::pObjeto;
			Conclusivo Lixeira::pProgresso;

			/**
			 * Isso pode ser perigoso demais!
			 */
			Lixeira::Lixeira(const Lixeira&) {};

		protected:
			std::deque<Objeto*>& Lixeira::objetos();

		public:
			Lixeira::Lixeira();

			/**
			 * Por padr�o limpa a lixeira
			 * antes de deixar de existir.
			 * <p>
			 * Se voc� quiser acabar com uma
			 * lixeira sem limp�-la recicle
			 * os objetos antes de destru�-la.
			 */
			virtual Lixeira::~Lixeira();

			/**
			 * Indica o progresso de exclus�o
			 * da lixeira. � percept�vel somente
			 * no caso de objetos que demoram
			 * pra ser destru�dos.
			 */
			virtual const Conclusivo& Lixeira::progresso() const;

			/**
			 * Decreta senten�a de morte para o Objeto
			 * passado. Somente a fun��o recicla poder�
			 * salv�-lo!
			 * <p>
			 * Esta lixeira � esperta suficiente
			 * para n�o adicionar duas inst�ncias
			 * repetidas.
			 * <p>
			 * Nota: <i>para tal ela percorre toda
			 * a lista em toda inclus�o, isso pode
			 * ser otimizado utilizando-se um map_hash
			 * ou algo assim.</i>
			 */
			virtual Lixeira& Lixeira::adiciona(Objeto*);

			/**
			 * Ao adicionar uma lixeira alheia nesta,
			 * a lixeira alheia ser� apagada!
			 */
			virtual Lixeira& Lixeira::sugaParaSi(Lixeira&);

			/**
			 * Limpa de tr�s pra frente, i. e., do �ltimo
			 * elemento adicionado at� o primeiro.
			 *
			 * @throws ErroAoDeletarElementoExcecao
			 *         � invocado quando <i>qualquer</i>
			 *         exce��o for lan�ada no momento
			 *         de deletar um elemento da lixeira.
			 *
			 * @param tentandoIgnorarErro Tenta ignorar
			 *        caso ocorra alguma exce��o. Por n�o
			 *        ser garantido e poder causar erros
			 *        estranhos/desconhecidos o uso deste
			 *        recurso � altamente <b>n�o
			 *        recomend�vel</b>.
			 */
			virtual Lixeira& Lixeira::limpa(
					const bool& tentandoIgnorarErro = false);

			/**
			 * Recupera os objetos jogados na lixeira
			 * na ordem em que eles foram colocados nesta.
			 */
			virtual std::deque<Objeto*> Lixeira::recicla();

			/**
			 * Recupera um objeto jogado na lixeira.
			 * @return NULL se n�o encontrar o objeto.
			 */
			virtual Objeto* Lixeira::recicla(const Objeto&);

			// Objeto:
			virtual std::string Lixeira::emString() const;
	};
  }
}

#endif // !defined(AFX_LIXEIRA_H__6465D257_9173_424E_87A2_35C9FA13603F__INCLUDED_)
