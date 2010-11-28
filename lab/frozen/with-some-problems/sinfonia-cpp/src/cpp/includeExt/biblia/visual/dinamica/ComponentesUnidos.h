/*
 * $RCSfile: ComponentesUnidos.h,v $
 * $Date: 2005/01/20 21:29:34 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
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
		 * � um conjunto de componentes que funcionam como um
		 * s�. Tudo que for feito com este ComponenteGraficoInterface,
		 * ser� feito em todos. Quando eles s�o adicionados, nada
		 * � mudado at� que alguma fun��o de modifica��o seja invocada
		 * ou at� que a fun��o "sincronizaTodos()" seja invocada.
		 */
		class ComponentesUnidos: public ComponenteGraficoInterface {
			private:
				biblia::armazenamento::volatil::carcacas::Lista<ComponenteGraficoInterface*> pElementos;

			public:
				ComponentesUnidos::ComponentesUnidos(const std::string& nome);
				virtual ComponentesUnidos::~ComponentesUnidos();

				/**
				 * O primeiro elemento adicionado � o "carro-chefe",
				 * i. e., quando a fun��o "sincronizaTodos()" for invocada
				 * o primeiro ser� usado como par�metro. E caso a fun��o
				 * "sincronizaTodos()" n�o for invocada, os atributos deste
				 * ComponenteGraficoInterface ser�o os mesmos do primeiro
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
				 * N�o � poss�vel manipular camadas em conjunto.
				 * @throws FuncaoNaoImplementadaExcecao Sempre.
				 */
				virtual const Camada& camada() const {
					throw FuncaoNaoImplementadaExcecao();
				}

				/**
				 * N�o � poss�vel manipular camadas em conjunto.
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
