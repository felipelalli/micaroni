/*
 * $RCSfile: EncaixotadorGenerico.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ENCAIXOTADOR_G_H__E1691C00_FEE5_477B_8158_9FB35B3BEB6E__INCLUDED_)
#define AFX_ENCAIXOTADOR_G_H__E1691C00_FEE5_477B_8158_9FB35B3BEB6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/eterno/empacotamento/EmpacotadorAprendiz.h"
#include "biblia/armazenamento/eterno/encaixotamento/Encaixotador.h"

using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::eterno::empacotamento;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {

		/**
		 * É um encaixotador genérico
		 * que suporta N empacotadores
		 * e N encaixotadores.
		 * <p>
		 * Dá prioridade aos empacotadores. Se
		 * estes não souberem empacotar, esta
		 * classe 'apela' para o recurso dos
		 * encaixotadores. --- essa prioridade
		 * se dá pelo fato de que uma 'caixa'
		 * é um tipo mais complexo que 'pacote'.
		 *
		 * @see EncaixotadorBasico
		 */
		class EncaixotadorGenerico: public Encaixotador {
			private:
				EmpacotadorAprendiz EncaixotadorGenerico
						::pEmpacotadorAprendiz;

				Lista<Encaixotador*> EncaixotadorGenerico
						::pEncaixotadores;

				Lixeira EncaixotadorGenerico::pLixeira;

			protected:
				virtual Lista<Encaixotador*>& EncaixotadorGenerico
						::encaixotadores();

				virtual const Lista<Encaixotador*>& EncaixotadorGenerico
						::encaixotadores() const;

			public:
				EncaixotadorGenerico::EncaixotadorGenerico();
				virtual EncaixotadorGenerico::~EncaixotadorGenerico();

				virtual EmpacotadorAprendiz& EncaixotadorGenerico
						::empacotadorAprendiz();

				virtual const EmpacotadorAprendiz& EncaixotadorGenerico
						::empacotadorAprendiz() const;

				/**
				 * Dá prioridade aos encaixotadores adicionados
				 * por último.
				 *
				 * @throws EncaixotadorNaoSabeManipularEsseTipoExcecao
				 */
				virtual Encaixotador& EncaixotadorGenerico
						::procuraEncaixotadorQueSabeManipular(
							const Tipo&) const;

				/**
				 * Os encaixotadores adicionados a este deverão
				 * ser de uso exclusivo deste EncaixotadorGenerico.
				 * I. e., estes adicionados serão modificados
				 * por esta classe livremente, crie novos empacotadores
				 * para que esta possa usá-los sem perigo.
				 * <p>
				 * Esta classe pega pra si a responsabilidade
				 * de apagar o encaixotador alheio, portanto
				 * <b>não</b> se preocupe em deletá-lo externamente.
				 */
				virtual EncaixotadorGenerico& EncaixotadorGenerico
						::adicionaEncaixotadorAlheio(Encaixotador*);

				// Encaixotador:

				virtual Encaixotador& EncaixotadorGenerico
						::encaixota(const Identificacao&,
							const Informacao&);

				virtual Informacao* EncaixotadorGenerico
						::desencaixota(const Identificacao&);

				virtual const bool EncaixotadorGenerico
						::sabeEncaixotar(const Tipo&) const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_ENCAIXOTADOR_G_H__E1691C00_FEE5_477B_8158_9FB35B3BEB6E__INCLUDED_)
