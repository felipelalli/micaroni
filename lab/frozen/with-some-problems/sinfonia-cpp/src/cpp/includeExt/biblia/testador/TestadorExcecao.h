/*
 * $RCSfile: TestadorExcecao.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TESTADOREXCECAO_H__F4A7D584_6CBA_497F_AE80_49183AE85B51__INCLUDED_)
#define AFX_TESTADOREXCECAO_H__F4A7D584_6CBA_497F_AE80_49183AE85B51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

namespace biblia {
  namespace testador {

	class TestadorExcecao: public Excecao {
		public:
			TestadorExcecao::TestadorExcecao();
			virtual TestadorExcecao::~TestadorExcecao();
	};

	class TesteAindaNaoInicializadoTestadorExcecao
			:public TestadorExcecao
	{
		public:
			TesteAindaNaoInicializadoTestadorExcecao
					::TesteAindaNaoInicializadoTestadorExcecao() {}
	};
  }
}

#endif // !defined(AFX_TESTADOREXCECAO_H__F4A7D584_6CBA_497F_AE80_49183AE85B51__INCLUDED_)
