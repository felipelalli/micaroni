/*
 * $RCSfile: DinamicaExcecao.h,v $
 * $Date: 2003/05/29 21:08:20 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_DINAMICAEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
#define AFX_DINAMICAEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Excecao.h"
using namespace biblia::basico;

namespace biblia {
  namespace visual {
	namespace dinamica {
		class DinamicaExcecao: public Excecao {
			protected:
				DinamicaExcecao::DinamicaExcecao() {}
		};

		class CamadaExcecao: public DinamicaExcecao {
			protected:
				CamadaExcecao::CamadaExcecao() {}
		};

		class ResultadoGraficoExcecao: public DinamicaExcecao {
			protected:
				ResultadoGraficoExcecao::ResultadoGraficoExcecao() {}
		};

		class DesenhistaDeResultadoGraficoNaTelaExcecao
				: public DinamicaExcecao
		{
			protected:
				DesenhistaDeResultadoGraficoNaTelaExcecao
						::DesenhistaDeResultadoGraficoNaTelaExcecao() {}
		};

		class CarregadorDeComponentesExcecao
				: public DinamicaExcecao
		{
			protected:
				CarregadorDeComponentesExcecao
						::CarregadorDeComponentesExcecao() {}
		};

		class NaoPertenceAMesmaListaDeCamadasExcecao
				:public CamadaExcecao
		{
			public:
				NaoPertenceAMesmaListaDeCamadasExcecao
						::NaoPertenceAMesmaListaDeCamadasExcecao() {}
		};

		class NaoTemAbaixoExcecao
				:public CamadaExcecao
		{
			public:
				NaoTemAbaixoExcecao
						::NaoTemAbaixoExcecao() {}
		};

		class NaoTemAcimaExcecao
				:public CamadaExcecao
		{
			public:
				NaoTemAcimaExcecao
						::NaoTemAcimaExcecao() {}
		};

		class NaoEstaAssociadaExcecao
				:public CamadaExcecao
		{
			public:
				NaoEstaAssociadaExcecao
						::NaoEstaAssociadaExcecao() {}
		};

		class LoopExcecao
				:public CamadaExcecao
		{
			public:
				LoopExcecao::LoopExcecao() {}
		};

		class NaoTemProximoExcecao
				:public ResultadoGraficoExcecao
		{
			public:
				NaoTemProximoExcecao
						::NaoTemProximoExcecao() {}
		};

		class NaoTemTelaDefinidaExcecao
				:public DesenhistaDeResultadoGraficoNaTelaExcecao
		{
			public:
				NaoTemTelaDefinidaExcecao
						::NaoTemTelaDefinidaExcecao() {}
		};

		class NaoTemResultadoGraficoDefinidoExcecao
				:public DesenhistaDeResultadoGraficoNaTelaExcecao
		{
			public:
				NaoTemResultadoGraficoDefinidoExcecao
						::NaoTemResultadoGraficoDefinidoExcecao() {}
		};

		class NaoTemFabricaDeImagensDefinidaExcecao
				:public DesenhistaDeResultadoGraficoNaTelaExcecao
		{
			public:
				NaoTemFabricaDeImagensDefinidaExcecao
						::NaoTemFabricaDeImagensDefinidaExcecao() {}
		};

		class ComponenteGraficoNaoSuportadoExcecao
				:public DesenhistaDeResultadoGraficoNaTelaExcecao
		{
			public:
				ComponenteGraficoNaoSuportadoExcecao
						::ComponenteGraficoNaoSuportadoExcecao() {}
		};

		class ArquivoBasicoDeFonteMalFormadoExcecao
				:public CarregadorDeComponentesExcecao
		{
			public:
				ArquivoBasicoDeFonteMalFormadoExcecao
						::ArquivoBasicoDeFonteMalFormadoExcecao() {}
		};

		class ChaveNaoDefinidiaExcecao
				:public CarregadorDeComponentesExcecao
		{
			public:
				ChaveNaoDefinidiaExcecao
						::ChaveNaoDefinidiaExcecao() {}
		};

		class ChaveJaDefinidiaExcecao
				:public CarregadorDeComponentesExcecao
		{
			public:
				ChaveJaDefinidiaExcecao
						::ChaveJaDefinidiaExcecao() {}
		};

		class CarregadorWizardExcecao: public DinamicaExcecao {
			protected:
				CarregadorWizardExcecao::CarregadorWizardExcecao() {}
		};

		class ArquivoBasicoMalFormadoExcecao: public CarregadorWizardExcecao {
			public:
				ArquivoBasicoMalFormadoExcecao::ArquivoBasicoMalFormadoExcecao() {}
		};
	}
  }
}

#endif // !defined(AFX_DINAMICAEXCECAO_H__3AE8798D_3346_4086_9F92_FCEEF8118A39__INCLUDED_)
