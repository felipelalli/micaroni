/*
 * $RCSfile: MonitorExcecao.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(MonitorExcecao_H)
#define MonitorExcecao_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/IOExcecao.h"

using namespace biblia::basico;
using namespace biblia::io;

namespace biblia {
  namespace io {
	namespace monitor {
		class MonitorExcecao
				:public IOExcecao
		{
			public:
				MonitorExcecao::MonitorExcecao() {}
		};

		class ResolucaoNaoSuportadaExcecao
				:public MonitorExcecao
		{
			public:
				ResolucaoNaoSuportadaExcecao
						::ResolucaoNaoSuportadaExcecao()
				{}
		};

		class ErroAoIniciarModoGraficoExcecao
				:public MonitorExcecao
		{
			public:
				ErroAoIniciarModoGraficoExcecao
						::ErroAoIniciarModoGraficoExcecao()
				{}
		};

		class TelaNaoInicializadaExcecao
				:public MonitorExcecao
		{
			public:
				TelaNaoInicializadaExcecao
						::TelaNaoInicializadaExcecao()
				{}
		};

		class NumeroDeTelasExcedidoExcecao
				:public MonitorExcecao
		{
			public:
				NumeroDeTelasExcedidoExcecao
						::NumeroDeTelasExcedidoExcecao()
				{}
		};

		class FundoIndefinidoExcecao
				:public MonitorExcecao
		{
			public:
				FundoIndefinidoExcecao
						::FundoIndefinidoExcecao()
				{}
		};

		class FundoDefinidoExcecao
				:public MonitorExcecao
		{
			public:
				FundoDefinidoExcecao
						::FundoDefinidoExcecao()
				{}
		};
	}
  }
}

#endif // !defined(MonitorExcecao_H)
