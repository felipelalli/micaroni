/*
 * $RCSfile: ResultadoGrafico.h,v $
 * $Date: 2004/06/29 22:19:14 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_RESULTADOGRAFICO_H__C47882E3_CF39_4167_A0C3_E8D007BF5C54__INCLUDED_)
#define AFX_RESULTADOGRAFICO_H__C47882E3_CF39_4167_A0C3_E8D007BF5C54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <typeinfo>
#include "biblia/basico/Objeto.h"
#include "biblia/visual/dinamica/Camada.h"
#include "biblia/visual/dinamica/DinamicaExcecao.h"
#include "biblia/visual/dinamica/ComponenteGrafico.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {
    namespace dinamica {

		/**
		 * Deve ser usado por algo que seja
		 * capaz de desenhar derivados de
		 * {@link biblia::visual::dinamica::ComponenteGraficoInterface}.
		 * <p>
		 * <i>Obs.: Não use este objeto para ficar manipulando
		 * os seus componentes gráficos. Isso pode ocasionar
		 * um overhead desnecessário! Use variáveis externas, listas,
		 * mapa, hash, seja lá o que for. Lembre-se que este
		 * resultado gráfico apenas agrupa todos os componentes
		 * que devem ser desenhados (ou não em caso de invisibilidade).
		 * Outra coisa importante: ele agrupa através das camadas. Portanto,
		 * se as camadas forem modificadas ('zoneadas') externamente, ele
		 * poderá 'se perder'.</i>
		 *
		 * @see biblia::visual::dinamica::DesenhistaDeResultadoGraficoNaTela
		 */
		class ResultadoGrafico: public Objeto {
			private:
				ComponenteGraficoInterface*
						ResultadoGrafico::pComponenteBase;

				Camada* ResultadoGrafico::pCamadaAtual;

			public:
				ResultadoGrafico::ResultadoGrafico();
				virtual ResultadoGrafico::~ResultadoGrafico();

				/**
				 * Adiciona um ComponenteGrafico<class T>
				 * qualquer em cima ou em baixo dos que já
				 * estão aqui.
				 */
				virtual ResultadoGrafico&
						ResultadoGrafico::adiciona(
							ComponenteGraficoInterface*,
							bool emCima = true);

				/**
				 * Retira algum componente desse resultado.
				 */
				virtual ResultadoGrafico&
						ResultadoGrafico::retira(
							ComponenteGraficoInterface*);

				/**
				 * Retorna true se não tem próximo componente
				 * ativo acima do atual.
				 */
				virtual bool ResultadoGrafico::temProximo() const;

				/**
				 * Vai para a base dos componentes
				 * gráficos.
				 */
				virtual ResultadoGrafico&
						ResultadoGrafico::vaiPraBase();

				/**
				 * Retorna o próximo componente ativo
				 * de cima do componente atual.
				 */
				virtual ComponenteGraficoInterface*
						ResultadoGrafico::proximoComponente();
		};
	}
  }
}

#endif // !defined(AFX_RESULTADOGRAFICO_H__C47882E3_CF39_4167_A0C3_E8D007BF5C54__INCLUDED_)
