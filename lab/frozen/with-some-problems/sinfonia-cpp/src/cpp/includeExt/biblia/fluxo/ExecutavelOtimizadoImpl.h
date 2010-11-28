/*
 * $RCSfile: ExecutavelOtimizadoImpl.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
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
	 * É um {@link biblia::fluxo::Executavel}
	 * executável otimizado implementado da
	 * maneira menos otimizada possível, i. e., chama
	 * explicitamente a função {@link #executa()} quantas
	 * vezes for necessário.
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
