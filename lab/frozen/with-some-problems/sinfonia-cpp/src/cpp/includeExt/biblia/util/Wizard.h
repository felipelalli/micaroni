/*
 * $RCSfile: Wizard.h,v $
 * $Date: 2005/03/16 20:24:19 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#if !defined(AFX_WIZARD_H__F366A688_DBE7_4972_93E9_1E11D60658CE__INCLUDED_)
#define AFX_WIZARD_H__F366A688_DBE7_4972_93E9_1E11D60658CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/ConclusivoTemporizado.h"

using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace util {

	/**
	 * Tudo que � Wizard tem um come�o, meio
	 * e fim ({@link #progresso() const}) e ap�s
	 * conclu�do gera um {@link #resultado() const}.
	 */
	class Wizard: public Executavel {
		private:
			ConclusivoTemporizado Wizard::pProgresso;

		protected:
			Wizard::Wizard():pProgresso() {};
			virtual ConclusivoTemporizado& Wizard::progresso();

		public:
			virtual Wizard::~Wizard() {};

			/**
			 * Retorna o progresso deste Wizard.
			 */
			virtual const ConclusivoTemporizado& Wizard::progresso() const;

			/**
			 * Retorna uma inst�ncia do resultado
			 * deste Wizard se estiver conclu�do.
			 * Deve ser deletado externamente.
			 *
			 * @return <code>NULL</code> se ainda
			 *         n�o estiver conclu�do.
			 *
			 * @see #executa()
			 * @see #progresso() const
			 */
			virtual Objeto* Wizard::resultado() const = 0;

			// Executavel:

			/**
			 * Executa este Wizard gerando um
			 * {@link #resultado() resultado}.
			 *
			 * @see #progresso()
			 * @see #progresso() const
			 */
			virtual Executavel& Wizard::executa() = 0;
	};
  }
}

#endif // !defined(AFX_WIZARD_H__F366A688_DBE7_4972_93E9_1E11D60658CE__INCLUDED_)
