/*
 * $RCSfile: DiscoExcecao.h,v $
 * $Date: 2004/01/28 23:46:59 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_DiscoExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_DiscoExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/IOExcecao.h"

using namespace biblia::basico;

namespace biblia {
  namespace io {
	namespace disco {
		class DiscoExcecao
				:public IOExcecao
		{
			public:
				DiscoExcecao::DiscoExcecao() {}
		};

		class ErroNaLeituraDoArquivoBasico
				:public DiscoExcecao
		{
			public:
				ErroNaLeituraDoArquivoBasico
						::ErroNaLeituraDoArquivoBasico() {}
		};

		class ErroNaEscritaDoArquivoBasico
				:public DiscoExcecao
		{
			public:
				ErroNaEscritaDoArquivoBasico
						::ErroNaEscritaDoArquivoBasico() {}
		};

		class IndiceDoArquivoForaDeIntervaloExcecao
				:public DiscoExcecao
		{
			public:
				IndiceDoArquivoForaDeIntervaloExcecao
						::IndiceDoArquivoForaDeIntervaloExcecao() {}
		};
	}
  }
}

#endif // !defined(AFX_DiscoExcecao_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
