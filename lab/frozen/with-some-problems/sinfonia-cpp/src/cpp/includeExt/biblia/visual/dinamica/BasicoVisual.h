/*
 * $RCSfile: BasicoVisual.h,v $
 * $Date: 2003/06/10 19:16:53 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BASICOVISUAL_H__DEDF407E_2F0C_42DF_8D48_482801DA6A64__INCLUDED_)
#define AFX_BASICOVISUAL_H__DEDF407E_2F0C_42DF_8D48_482801DA6A64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/fluxo/ExecutaveisEmSerie.h"
#include "biblia/io/monitor/TelaComFundo.h"
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/dinamica/CarregadorDeComponentes.h"
#include "biblia/visual/dinamica/ResultadoGrafico.h"

using namespace biblia::basico;
using namespace biblia::fluxo;
using namespace biblia::io::monitor;
using namespace biblia::tempo;
using namespace biblia::visual::imagem2d;

namespace biblia {
  namespace visual {
    namespace dinamica {

		/**
		 * Uma instância contendo todo o básico
		 * de um visual. Para encapsular as partes
		 * separadas do visual como um todo e facilitar
		 * na implementação específica delas.
		 */
		class BasicoVisual: public Interface {
			private:
				ResultadoGrafico BasicoVisual::pResultadoGrafico;
				ExecutaveisEmSerie BasicoVisual::pAnimacoes;

			protected:
				BasicoVisual::BasicoVisual();

			public:
				virtual BasicoVisual::~BasicoVisual();
				virtual BasicoVisual& BasicoVisual
						::reinicia() { return *this; }

				virtual CarregadorDeComponentes&
						BasicoVisual::carregador() = 0;

				virtual FabricaDeImagens&
						BasicoVisual::fabrica() = 0;

				virtual TelaComFundo&
						BasicoVisual::tela() = 0;

				virtual UniversoDeTempo&
						BasicoVisual::tempo() = 0;

				virtual ResultadoGrafico&
						BasicoVisual::resultadoGrafico();

				virtual ExecutaveisEmSerie&
						BasicoVisual::animacoes();

				virtual const CarregadorDeComponentes&
						BasicoVisual::carregador() const = 0;

				virtual const FabricaDeImagens&
						BasicoVisual::fabrica() const = 0;

				virtual const TelaComFundo&
						BasicoVisual::tela() const = 0;

				virtual const UniversoDeTempo&
						BasicoVisual::tempo() const = 0;

				virtual const ResultadoGrafico&
						BasicoVisual::resultadoGrafico() const;

				virtual const ExecutaveisEmSerie&
						BasicoVisual::animacoes() const;
		};
	}
  }
}

#endif // !defined(AFX_BASICOVISUAL_H__DEDF407E_2F0C_42DF_8D48_482801DA6A64__INCLUDED_)
