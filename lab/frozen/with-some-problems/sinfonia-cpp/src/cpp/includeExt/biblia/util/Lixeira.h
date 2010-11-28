/*
 * $RCSfile: Lixeira.h,v $
 * $Date: 2005/01/20 21:29:31 $
 * $Revision: 1.13 $
 *
 * Implementação da biblioteca Bíblia.
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
	 * Para facilitar a exclusão de
	 * {@link biblia::basico::Objeto}s
	 * em série.
	 * <p>
	 * Armazena um conjunto de ponteiros
	 * para objetos que deverão ser futuramente
	 * deletados. Quando esta lixeira perde o escopo ou
	 * é deletada, ela automaticamente se
	 * "auto-destrói", apagando todos os elementos
	 * na ordem contrária a que foram adicionados
	 * a ela. Essa ordem contrária (do mesmo
	 * jeito que uma pilha) é importante devido
	 * às dependências das instâncias.
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
			 * Por padrão limpa a lixeira
			 * antes de deixar de existir.
			 * <p>
			 * Se você quiser acabar com uma
			 * lixeira sem limpá-la recicle
			 * os objetos antes de destruí-la.
			 */
			virtual Lixeira::~Lixeira();

			/**
			 * Indica o progresso de exclusão
			 * da lixeira. É perceptível somente
			 * no caso de objetos que demoram
			 * pra ser destruídos.
			 */
			virtual const Conclusivo& Lixeira::progresso() const;

			/**
			 * Decreta sentença de morte para o Objeto
			 * passado. Somente a função recicla poderá
			 * salvá-lo!
			 * <p>
			 * Esta lixeira é esperta suficiente
			 * para não adicionar duas instâncias
			 * repetidas.
			 * <p>
			 * Nota: <i>para tal ela percorre toda
			 * a lista em toda inclusão, isso pode
			 * ser otimizado utilizando-se um map_hash
			 * ou algo assim.</i>
			 */
			virtual Lixeira& Lixeira::adiciona(Objeto*);

			/**
			 * Ao adicionar uma lixeira alheia nesta,
			 * a lixeira alheia será apagada!
			 */
			virtual Lixeira& Lixeira::sugaParaSi(Lixeira&);

			/**
			 * Limpa de trás pra frente, i. e., do último
			 * elemento adicionado até o primeiro.
			 *
			 * @throws ErroAoDeletarElementoExcecao
			 *         É invocado quando <i>qualquer</i>
			 *         exceção for lançada no momento
			 *         de deletar um elemento da lixeira.
			 *
			 * @param tentandoIgnorarErro Tenta ignorar
			 *        caso ocorra alguma exceção. Por não
			 *        ser garantido e poder causar erros
			 *        estranhos/desconhecidos o uso deste
			 *        recurso é altamente <b>não
			 *        recomendável</b>.
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
			 * @return NULL se não encontrar o objeto.
			 */
			virtual Objeto* Lixeira::recicla(const Objeto&);

			// Objeto:
			virtual std::string Lixeira::emString() const;
	};
  }
}

#endif // !defined(AFX_LIXEIRA_H__6465D257_9173_424E_87A2_35C9FA13603F__INCLUDED_)
