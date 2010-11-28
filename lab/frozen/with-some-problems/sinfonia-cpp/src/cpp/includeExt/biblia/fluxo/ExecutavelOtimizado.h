/*
 * $RCSfile: ExecutavelOtimizado.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
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
	 * � um {@link biblia::fluxo::Executavel} que
	 * tem a fun��o {@link #executa(int quantasVezes)}
	 * que executa o execut�vel quantas vezes forem
	 * necess�rias. � utilizado em situa��es que pode
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
			 * Executa quantas vezes forem necess�rias
			 * esse execut�vel. Algumas coisas podem
			 * ter otimiza��es espec�ficas para isso.
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
