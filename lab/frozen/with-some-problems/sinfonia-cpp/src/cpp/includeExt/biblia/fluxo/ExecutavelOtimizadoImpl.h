/*
 * $RCSfile: ExecutavelOtimizadoImpl.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_EXECUTAVELOTIMIZADOIMPL_H__8CAD480D_9978_4EBE_8788_4D6D574E60F6__INCLUDED_)
#define AFX_EXECUTAVELOTIMIZADOIMPL_H__8CAD480D_9978_4EBE_8788_4D6D574E60F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/fluxo/ExecutavelOtimizado.h"

namespace biblia {
  namespace fluxo {

	/**
	 * � um {@link biblia::fluxo::Executavel}
	 * execut�vel otimizado implementado da
	 * maneira menos otimizada poss�vel, i. e., chama
	 * explicitamente a fun��o {@link #executa()} quantas
	 * vezes for necess�rio.
	 */
	class ExecutavelOtimizadoImpl: public ExecutavelOtimizado {
		private:
			Executavel& ExecutavelOtimizadoImpl::pExecutavel;

		public:
			ExecutavelOtimizadoImpl::ExecutavelOtimizadoImpl(Executavel&);
			virtual ExecutavelOtimizadoImpl::~ExecutavelOtimizadoImpl();

			// ExecutavelOtimizado:
			virtual ExecutavelOtimizado& ExecutavelOtimizadoImpl
					::executa(int quantasVezes);

			// Executavel:
			virtual Executavel& ExecutavelOtimizadoImpl
					::executa();
	};
  }
}

#endif // !defined(AFX_EXECUTAVELOTIMIZADOIMPL_H__8CAD480D_9978_4EBE_8788_4D6D574E60F6__INCLUDED_)
