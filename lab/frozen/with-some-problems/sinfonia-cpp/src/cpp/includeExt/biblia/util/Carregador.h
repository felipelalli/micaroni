/*
 * $RCSfile: Carregador.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CARREGADOR_H__E23A0B75_3634_4E8B_BCC6_1587952BEE13__INCLUDED_)
#define AFX_CARREGADOR_H__E23A0B75_3634_4E8B_BCC6_1587952BEE13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Conclusivo.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/util/Lixeira.h"

using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace util {

	/**
	 * Carrega qualquer coisa
	 * e dá 'suporte' ao progresso de carregamento
	 * e destruição dos objetos.
	 */
	class Carregador: public Executavel, public Objeto {
		private:
			Conclusivo Carregador::pCarregamento;
			Lixeira Carregador::pLixo;

		protected:
			Carregador::Carregador();
			virtual Conclusivo& Carregador::carregamento();

			/**
			 * Quem deste Carregador deriva, deve adicionar
			 * todas as instâncias criadas nesta lixeira()
			 * para quando o destroi() for chamado.
			 */
			virtual Lixeira& Carregador::lixeira();

		public:
			virtual Carregador::~Carregador();

			virtual const Conclusivo& Carregador::carregamento() const;
			virtual const Conclusivo& Carregador::exclusao() const;

			/**
			 * Destrói todos os elementos que este carregador
			 * carregou.
			 * <p>
			 * <i>Implementação: limpa a {@link #lixeira()}.</i>
			 */
			virtual Carregador& Carregador::destroi();

			// Executavel:

			/**
			 * Quando executado, carrega tudo de uma vez.
			 */
			virtual Executavel& Carregador::executa() = 0;
	};
  }
}

#endif // !defined(AFX_CARREGADOR_H__E23A0B75_3634_4E8B_BCC6_1587952BEE13__INCLUDED_)
