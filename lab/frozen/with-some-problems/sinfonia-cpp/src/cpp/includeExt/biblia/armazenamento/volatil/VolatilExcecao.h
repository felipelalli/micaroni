/*
 * $RCSfile: VolatilExcecao.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.6 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_VOLATILEXCECAO_H__978F2EC5_DA6A_4FC1_B413_C5416B33717D__INCLUDED_)
#define AFX_VOLATILEXCECAO_H__978F2EC5_DA6A_4FC1_B413_C5416B33717D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

namespace biblia {
  namespace armazenamento{
    namespace volatil {
		class VolatilExcecao: public Excecao {
			public:
				VolatilExcecao::VolatilExcecao() {}
		};

		class UniversoExcecao: public VolatilExcecao {
			public:
				UniversoExcecao::UniversoExcecao() {}
		};

		class CarcacasExcecao: public VolatilExcecao {
			public:
				CarcacasExcecao::CarcacasExcecao() {}
		};

		class MapaExcecao: public CarcacasExcecao {
			public:
				MapaExcecao::MapaExcecao() {}
		};

		class DadosDeTamanhoDiferenteExcecao: public VolatilExcecao {
			public:
				DadosDeTamanhoDiferenteExcecao
						::DadosDeTamanhoDiferenteExcecao() {}
		};

		class ChaveInexistenteExcecao: public MapaExcecao {
			public:
				ChaveInexistenteExcecao
						::ChaveInexistenteExcecao() {}
		};

		class ChaveJaExistenteExcecao: public MapaExcecao {
			public:
				ChaveJaExistenteExcecao
						::ChaveJaExistenteExcecao() {}
		};

		class InformacaoExcecao: public VolatilExcecao {
			public:
				InformacaoExcecao::InformacaoExcecao() {}
		};

		class PrimitivoExcecao: public InformacaoExcecao {
			public:
				PrimitivoExcecao::PrimitivoExcecao() {}
		};

		class CompostoExcecao: public InformacaoExcecao {
			public:
				CompostoExcecao::CompostoExcecao() {}
		};

		class FormatoInteiroInvalidoExcecao: public PrimitivoExcecao {
			public:
				FormatoInteiroInvalidoExcecao
						::FormatoInteiroInvalidoExcecao() {}
		};

		class HerancaEmLoopExcecao: public CompostoExcecao {
			public:
				HerancaEmLoopExcecao::HerancaEmLoopExcecao() {}
		};

		class HerancaNaoDefinidaExcecao: public CompostoExcecao {
			public:
				HerancaNaoDefinidaExcecao::HerancaNaoDefinidaExcecao() {}
		};

		class CampoJaExistenteExcecao: public CompostoExcecao {
			public:
				CampoJaExistenteExcecao::CampoJaExistenteExcecao() {}
		};

		class CampoNaoExistenteExcecao: public CompostoExcecao {
			public:
				CampoNaoExistenteExcecao::CampoNaoExistenteExcecao() {}
		};

		class CompostoNaoAbertoExcecao: public CompostoExcecao {
			public:
				CompostoNaoAbertoExcecao::CompostoNaoAbertoExcecao() {}
		};

		class CompostoNaoFechadoExcecao: public CompostoExcecao {
			public:
				CompostoNaoFechadoExcecao::CompostoNaoFechadoExcecao() {}
		};

		class TipoDesconhecidoExcecao: public PrimitivoExcecao {
			public:
				TipoDesconhecidoExcecao::TipoDesconhecidoExcecao() {}
		};

		class UniversoInvalidoExcecao
				:public UniversoExcecao
		{
			public:
				UniversoInvalidoExcecao
						::UniversoInvalidoExcecao() {}
		};

		class ForaDoUniversoExcecao
				:public UniversoExcecao
		{
			public:
				ForaDoUniversoExcecao
						::ForaDoUniversoExcecao() {}
		};

		class InformacaoInvalidaExcecao
				:public InformacaoExcecao
		{
			public:
				InformacaoInvalidaExcecao
						::InformacaoInvalidaExcecao() {}
		};

		class InformacaoNaoDefinidaExcecao
				:public InformacaoExcecao
		{
			public:
				InformacaoNaoDefinidaExcecao
						::InformacaoNaoDefinidaExcecao() {}
		};

		class ListaExcecao
				:public InformacaoExcecao
		{
			public:
				ListaExcecao
						::ListaExcecao() {}
		};

		class IndiceForaDeIntervaloListaExcecao
				:public ListaExcecao
		{
			public:
				IndiceForaDeIntervaloListaExcecao
						::IndiceForaDeIntervaloListaExcecao() {}
		};
	}
  }
}

#endif // !defined(AFX_VOLATILEXCECAO_H__978F2EC5_DA6A_4FC1_B413_C5416B33717D__INCLUDED_)
