/*
 * $RCSfile: ComponentesUnidos.h,v $
 * $Date: 2005/01/20 21:29:34 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_COMPONENTESUNIDOS_H__8C15CD95_B036_4A41_BC9C_072B2AF06C43__INCLUDED_)
#define AFX_COMPONENTESUNIDOS_H__8C15CD95_B036_4A41_BC9C_072B2AF06C43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/volatil/carcacas/Lista.h"
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/visual/dinamica/ComponenteGraficoInterface.h"

namespace biblia {
  namespace visual {
    namespace dinamica {
		/**
		 * É um conjunto de componentes que funcionam como um
		 * só. Tudo que for feito com este ComponenteGraficoInterface,
		 * será feito em todos. Quando eles são adicionados, nada
		 * é mudado até que alguma função de modificação seja invocada
		 * ou até que a função "sincronizaTodos()" seja invocada.
		 */
		class ComponentesUnidos: public ComponenteGraficoInterface {
			private:
				biblia::armazenamento::volatil::carcacas::Lista<ComponenteGraficoInterface*> pElementos;

			public:
				ComponentesUnidos::ComponentesUnidos(const std::string& nome);
				virtual ComponentesUnidos::~ComponentesUnidos();

				/**
				 * O primeiro elemento adicionado é o "carro-chefe",
				 * i. e., quando a função "sincronizaTodos()" for invocada
				 * o primeiro será usado como parâmetro. E caso a função
				 * "sincronizaTodos()" não for invocada, os atributos deste
				 * ComponenteGraficoInterface serão os mesmos do primeiro
				 * elemento.
				 */
				ComponentesUnidos& ComponentesUnidos
						::adiciona(ComponenteGraficoInterface*);

				/**
				 * Sincroniza todos os componentes baseado
				 * no primeiro.
				 */
				ComponentesUnidos& ComponentesUnidos::sincronizaTodos();

				// ComponenteGraficoInterface

				virtual ComponenteGraficoInterface& visivel(const bool);
				virtual ComponenteGraficoInterface& deveMesclar();
				virtual bool consomeSeDeveMesclar();
				virtual ComponenteGraficoInterface& descola();

				/**
				 * Não é possível manipular camadas em conjunto.
				 * @throws FuncaoNaoImplementadaExcecao Sempre.
				 */
				virtual const Camada& camada() const {
					throw FuncaoNaoImplementadaExcecao();
				}

				/**
				 * Não é possível manipular camadas em conjunto.
				 * @throws FuncaoNaoImplementadaExcecao Sempre.
				 */
				virtual Camada& camada() {
					throw FuncaoNaoImplementadaExcecao();
				}
		};
	}
  }
}

#endif // !defined(AFX_COMPONENTESUNIDOS_H__8C15CD95_B036_4A41_BC9C_072B2AF06C43__INCLUDED_)
