/*
 * $RCSfile: FluxoExcecao.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_FLUXOEXCECAO_H__B0BFAAFD_1445_4FF3_A87B_FC69408795D6__INCLUDED_)
#define AFX_FLUXOEXCECAO_H__B0BFAAFD_1445_4FF3_A87B_FC69408795D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

namespace biblia {
  namespace fluxo {

	class FluxoExcecao: public Excecao {
		public:
			FluxoExcecao::FluxoExcecao() {};
			virtual FluxoExcecao::~FluxoExcecao() {};
	};

	class ConclusivoExcecao: public FluxoExcecao {
		public:
			ConclusivoExcecao::ConclusivoExcecao() {};
			virtual ConclusivoExcecao::~ConclusivoExcecao() {};
	};

	class ConclusivoJaConcluidoConclusivoExcecao: public ConclusivoExcecao {
		public:
			ConclusivoJaConcluidoConclusivoExcecao
				::ConclusivoJaConcluidoConclusivoExcecao() {};

			virtual ConclusivoJaConcluidoConclusivoExcecao
					::~ConclusivoJaConcluidoConclusivoExcecao() {};
	};

	class ConclusivoAindaNaoConcluidoConclusivoExcecao: public ConclusivoExcecao {
		public:
			ConclusivoAindaNaoConcluidoConclusivoExcecao
				::ConclusivoAindaNaoConcluidoConclusivoExcecao() {};

			virtual ConclusivoAindaNaoConcluidoConclusivoExcecao
					::~ConclusivoAindaNaoConcluidoConclusivoExcecao() {};
	};

	class ProgressoRetornouConclusivoExcecao: public ConclusivoExcecao {
		public:
			ProgressoRetornouConclusivoExcecao
				::ProgressoRetornouConclusivoExcecao() {};

			virtual ProgressoRetornouConclusivoExcecao
					::~ProgressoRetornouConclusivoExcecao() {};
	};

	class ConclusivoDeConclusivosExcecao: public ConclusivoExcecao {
		public:
			ConclusivoDeConclusivosExcecao
				::ConclusivoDeConclusivosExcecao() {};

			virtual ConclusivoDeConclusivosExcecao
					::~ConclusivoDeConclusivosExcecao() {};
	};

	class FuncaoNaoSuportadaConclusivoDeConclusivosExcecao:
			public ConclusivoDeConclusivosExcecao
	{
		public:
			FuncaoNaoSuportadaConclusivoDeConclusivosExcecao
				::FuncaoNaoSuportadaConclusivoDeConclusivosExcecao() {};

			virtual FuncaoNaoSuportadaConclusivoDeConclusivosExcecao
					::~FuncaoNaoSuportadaConclusivoDeConclusivosExcecao() {};
	};
  }
}

#endif // !defined(AFX_FLUXOEXCECAO_H__B0BFAAFD_1445_4FF3_A87B_FC69408795D6__INCLUDED_)
