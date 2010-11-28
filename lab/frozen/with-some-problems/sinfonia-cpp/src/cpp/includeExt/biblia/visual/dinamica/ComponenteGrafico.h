/*
 * $RCSfile: ComponenteGrafico.h,v $
 * $Date: 2005/01/20 21:29:33 $
 * $Revision: 1.14 $
 *
 * Implementa��o da biblioteca B�blia.
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
		 * Um componente gr�fico pode ser qualquer
		 * coisa que um {@link
		 * biblia::visual::dinamica::DesenhistaDeResultadoGraficoNaTela}
		 * seja capaz de desenhar.
		 * <p>
		 * Este componente pode estar invis�vel, mesclado
		 * ou flutuante. Por defini��o ele inicia flutuante
		 * e uma vez mesclado pode ser descolado.
		 *
		 * @see biblia::visual::dinamica::ResultadoGrafico
		 * @see biblia::visual::dinamica::DesenhistaDeResultadoGraficoNaTela
		 *
		 * @bug N�o consegui implementar no CPP; consegui apenas aqui.
		 */
		template<class QualComponente> class ComponenteGrafico
				:public ComponenteGraficoInterface
		{
			private:
				QualComponente* ComponenteGrafico<
						QualComponente>::pComponente;

			public:
				/**
				 * Cria um componente gr�fico
				 * a partir de alguma inst�ncia
				 * concreta que poder� ser desenhada
				 * no futuro.
				 *
				 * @param instancia Inst�ncia do componente gr�fico.
				 */
				ComponenteGrafico<QualComponente>(
						QualComponente* instancia, const std::string& nome)
					:ComponenteGraficoInterface(nome),
					 pComponente(instancia)
				{}

				/**
				 * Faz uma c�pia mas mant�m a mesma
				 * refer�ncia para a inst�ncia.
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
				 * Retorna o componente modific�vel.
				 */
				virtual QualComponente& componente() {
					return *(this->pComponente);
				}
		};
	}
  }
}

#endif // !defined(AFX_COMPONENTEGRAFICO_H__DF1E13F4_231E_4DBB_8F16_324FAC3D09D2__INCLUDED_)
