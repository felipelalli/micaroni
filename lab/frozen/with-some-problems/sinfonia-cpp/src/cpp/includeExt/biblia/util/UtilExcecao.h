/*
 * $RCSfile: UtilExcecao.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.9 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_UTILEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_UTILEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
#include <stdexcept>

using namespace biblia::basico;
using namespace std;

namespace biblia {
  namespace util {
		class UtilExcecao
				:public Excecao
		{
			public:
				UtilExcecao::UtilExcecao() {}
		};

		class WizardExcecao
				:public UtilExcecao
		{
			public:
				WizardExcecao
						::WizardExcecao() {}
		};

		class WizardNaoDefinidoExcecao
				:public WizardExcecao
		{
			public:
				WizardNaoDefinidoExcecao
						::WizardNaoDefinidoExcecao() {}
		};

		class LixeiraExcecao: public UtilExcecao {
			public:
				LixeiraExcecao::LixeiraExcecao() {}
		};

		class ErroAoDeletarElementoExcecao: public LixeiraExcecao {
			public:
				ErroAoDeletarElementoExcecao
						::ErroAoDeletarElementoExcecao() {}
		};

		class StrTokenExcecao
				:public UtilExcecao
		{
			public:
				StrTokenExcecao
						::StrTokenExcecao() {}
		};

		class StringTokenizerExcecao
				:public UtilExcecao
		{
			public:
				StringTokenizerExcecao
						::StringTokenizerExcecao() {}
		};

		class NaoHaMaisElementosExcecao
				:public StringTokenizerExcecao
		{
			public:
				NaoHaMaisElementosExcecao
						::NaoHaMaisElementosExcecao() {}
		};

		class InstrucoesExcecao: public UtilExcecao {
			public:
				InstrucoesExcecao
						::InstrucoesExcecao() {}
		};

		class InstrucaoInvalidaExcecao: public InstrucoesExcecao {
			public:
				InstrucaoInvalidaExcecao
						::InstrucaoInvalidaExcecao() {}
		};

		class InstrucaoIncompativelExcecao: public InstrucoesExcecao {
			public:
				InstrucaoIncompativelExcecao
						::InstrucaoIncompativelExcecao() {}
		};

		class ParametroInexistenteExcecao
				:public InstrucoesExcecao
		{
			public:
				ParametroInexistenteExcecao
						::ParametroInexistenteExcecao() {}
		};

		class InstrucaoForaDoIntervaloExcecao
				:public InstrucoesExcecao
		{
			public:
				InstrucaoForaDoIntervaloExcecao
						::InstrucaoForaDoIntervaloExcecao() {}
		};
  }
}

#endif // !defined(AFX_UTILEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
