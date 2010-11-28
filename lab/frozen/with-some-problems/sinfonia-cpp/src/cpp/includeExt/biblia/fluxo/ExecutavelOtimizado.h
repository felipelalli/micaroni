/*
 * $RCSfile: ExecutavelOtimizado.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_EXECUTAVELOTIMIZADO_H__3525DA2E_6F2C_4A0C_87D6_B0B9FAB7C27A__INCLUDED_)
#define AFX_EXECUTAVELOTIMIZADO_H__3525DA2E_6F2C_4A0C_87D6_B0B9FAB7C27A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/fluxo/Executavel.h"

namespace biblia {
  namespace fluxo {

	/**
	 * É um {@link biblia::fluxo::Executavel} que
	 * tem a função {@link #executa(int quantasVezes)}
	 * que executa o executável quantas vezes forem
	 * necessárias. É utilizado em situações que pode
	 * haver algum 'atraso' de processamento.
	 *
	 * @see biblia::fluxo::Executavel
	 * @see biblia::fluxo::ExecutavelOtimizadoImpl
	 */
	class ExecutavelOtimizado: public Executavel {
		protected:
			ExecutavelOtimizado::ExecutavelOtimizado();

		public:
			virtual ExecutavelOtimizado::~ExecutavelOtimizado();

			/**
			 * Executa quantas vezes forem necessárias
			 * esse executável. Algumas coisas podem
			 * ter otimizações específicas para isso.
			 */
			virtual ExecutavelOtimizado& ExecutavelOtimizado
					::executa(int quantasVezes) = 0;

			// Executavel:

			/**
			 * Executa apenas uma vez.
			 */
			virtual Executavel& ExecutavelOtimizado::executa();
	};
  }
}

#endif // !defined(AFX_EXECUTAVELOTIMIZADO_H__3525DA2E_6F2C_4A0C_87D6_B0B9FAB7C27A__INCLUDED_)
