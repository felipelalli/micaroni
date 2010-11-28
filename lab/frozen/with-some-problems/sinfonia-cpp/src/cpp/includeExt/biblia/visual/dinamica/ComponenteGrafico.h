/*
 * $RCSfile: ComponenteGrafico.h,v $
 * $Date: 2005/01/20 21:29:33 $
 * $Revision: 1.14 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_COMPONENTEGRAFICO_H__DF1E13F4_231E_4DBB_8F16_324FAC3D09D2__INCLUDED_)
#define AFX_COMPONENTEGRAFICO_H__DF1E13F4_231E_4DBB_8F16_324FAC3D09D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/visual/dinamica/ComponenteGraficoInterface.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {
    namespace dinamica {

		/**
		 * Um componente gráfico pode ser qualquer
		 * coisa que um {@link
		 * biblia::visual::dinamica::DesenhistaDeResultadoGraficoNaTela}
		 * seja capaz de desenhar.
		 * <p>
		 * Este componente pode estar invisível, mesclado
		 * ou flutuante. Por definição ele inicia flutuante
		 * e uma vez mesclado pode ser descolado.
		 *
		 * @see biblia::visual::dinamica::ResultadoGrafico
		 * @see biblia::visual::dinamica::DesenhistaDeResultadoGraficoNaTela
		 *
		 * @bug Não consegui implementar no CPP; consegui apenas aqui.
		 */
		template<class QualComponente> class ComponenteGrafico
				:public ComponenteGraficoInterface
		{
			private:
				QualComponente* ComponenteGrafico<
						QualComponente>::pComponente;

			public:
				/**
				 * Cria um componente gráfico
				 * a partir de alguma instância
				 * concreta que poderá ser desenhada
				 * no futuro.
				 *
				 * @param instancia Instância do componente gráfico.
				 */
				ComponenteGrafico<QualComponente>(
						QualComponente* instancia, const std::string& nome)
					:ComponenteGraficoInterface(nome),
					 pComponente(instancia)
				{}

				/**
				 * Faz uma cópia mas mantém a mesma
				 * referência para a instância.
				 */
				ComponenteGrafico<QualComponente>(
						const ComponenteGrafico<QualComponente>& irmao)
					:ComponenteGraficoInterface(irmao),
					 pComponente(irmao.pComponente)
				{}

				virtual ~ComponenteGrafico<QualComponente>() {}

				/**
				 * Retorna o componente.
				 */
				virtual const QualComponente& componente() const {
					return *(this->pComponente);
				}

				/**
				 * Retorna o componente modificável.
				 */
				virtual QualComponente& componente() {
					return *(this->pComponente);
				}
		};
	}
  }
}

#endif // !defined(AFX_COMPONENTEGRAFICO_H__DF1E13F4_231E_4DBB_8F16_324FAC3D09D2__INCLUDED_)
