/*
 * $RCSfile: Testador.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADOR_H__12151822_CEC6_44B0_A5B7_C8B92EF2E03A__INCLUDED_)
#define AFX_TESTADOR_H__12151822_CEC6_44B0_A5B7_C8B92EF2E03A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Conclusivo.h"
#include "biblia/testador/TestadorExcecao.h"

using namespace biblia::fluxo;

namespace biblia {
  namespace testador {

	/**
	 * Testa alguma classe e indica se houve
	 * {@link #sucesso() const} ou não.
	 */
	class Testador: public Executavel {
		private:
			bool Testador::pSucesso;
			Conclusivo Testador::pConclusivo;

		protected:
			virtual Testador& Testador::sucesso(bool);
			virtual Conclusivo& Testador::progresso();

		public:
			Testador::Testador();
			virtual Testador::~Testador();

			/**
			 * @throws biblia::testador::TesteAindaNaoFinalizadoExcecao
			 *         É invocado quando o teste ainda não acabou.
			 */
			virtual bool Testador::sucesso() const;

			/**
			 * Retorna o progresso do teste em porcentagem.
			 */
			virtual const Conclusivo& Testador::progresso() const;

			// Executavel
			virtual Executavel& Testador::executa() = 0;
	};
  }
}

#endif // !defined(AFX_TESTADOR_H__12151822_CEC6_44B0_A5B7_C8B92EF2E03A__INCLUDED_)
