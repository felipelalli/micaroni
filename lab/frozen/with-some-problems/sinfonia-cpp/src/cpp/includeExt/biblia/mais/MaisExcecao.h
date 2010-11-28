/*
 * $RCSfile: MaisExcecao.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_MAISEXCECAO_H__A84F9AD1_A3E5_48C2_A935_6F62D3F83DB3__INCLUDED_)
#define AFX_MAISEXCECAO_H__A84F9AD1_A3E5_48C2_A935_6F62D3F83DB3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

namespace biblia {
  namespace mais {

		class MaisExcecao:public Excecao {
			public:
				MaisExcecao::MaisExcecao() {}
		};

		class OperacaoNaoSuportadaExcecao
				:public MaisExcecao
		{
			public:
				OperacaoNaoSuportadaExcecao
						::OperacaoNaoSuportadaExcecao() {}
		};
  }
}

#endif // !defined(AFX_MAISEXCECAO_H__A84F9AD1_A3E5_48C2_A935_6F62D3F83DB3__INCLUDED_)
