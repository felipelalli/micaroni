/*
 * $RCSfile: ComponenteGraficoInterface.h,v $
 * $Date: 2005/01/20 21:29:33 $
 * $Revision: 1.8 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_COMPONENTEGRAFICOINTERFACE_H__47E092BA_1BF5_4E1D_A523_B882706FB33D__INCLUDED_)
#define AFX_COMPONENTEGRAFICOINTERFACE_H__47E092BA_1BF5_4E1D_A523_B882706FB33D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/visual/dinamica/Camada.h"

using namespace biblia::basico;

namespace biblia {
  namespace visual {
    namespace dinamica {

		/**
		 * � o pai de todos os
		 * {@link biblia::visual::dinamica::ComponenteGrafico<class T>
		 * componentes gr�ficos}.
		 */
		class ComponenteGraficoInterface: public Objeto {
			private:
				Camada ComponenteGraficoInterface::pCamada;
				std::string ComponenteGraficoInterface::pNome;

				bool ComponenteGraficoInterface::pMesclado;
				bool ComponenteGraficoInterface::pVisivel;
				bool ComponenteGraficoInterface::pDeveMesclar;

			protected:
				/**
				 * Associa si mesmo � camada.
				 */
				ComponenteGraficoInterface
						::ComponenteGraficoInterface(const std::string& nome);

				ComponenteGraficoInterface
					::ComponenteGraficoInterface(
						const ComponenteGraficoInterface&);

			public:
				virtual ComponenteGraficoInterface
						::~ComponenteGraficoInterface();

				/**
				 * Torna este componente vis�vel ou n�o.
				 */
				virtual ComponenteGraficoInterface& visivel(const bool);

				/**
				 * Indica que este componente gr�fico
				 * deve ser mesclado.
				 */
				virtual ComponenteGraficoInterface& deveMesclar();

				/**
				 * Se deve ser mesclado ele retorna true e em seguida
				 * se auto-define como "mesclado".
				 */
				virtual bool consomeSeDeveMesclar();

				/**
				 * Indica que este componente foi descolado do fundo.
				 * <b>Aten��o ao usar isto. Somente um 'desenhista'
				 * pode usar isto.</b>
				 */
				virtual ComponenteGraficoInterface& descola();

				/**
				 * Copia os mesmos atributos do que � passado como
				 * par�metro, exceto a camada e o nome.
				 */
				virtual ComponenteGraficoInterface& copiaAtributosDe(
						const ComponenteGraficoInterface&);

				/**
				 * S� deve ser desenhado
				 * se estiver vis�vel.
				 */
				virtual bool visivel() const;

				/**
				 * Deve ser desenhado sempre.
				 * <p>
				 * Equivale a
				 * <code>!mesclado()</code>
				 */
				virtual bool flutuante() const;

				/**
				 * J� foi mesclado e n�o deve
				 * ser desenhado novamente.
				 * <p>
				 * Equivale a
				 * <code>!flutuante()</code>
				 */
				virtual bool mesclado() const;

				/**
				 * Retorna a qual camada (somente-leitura)
				 * pertence este componente gr�fico.
				 */
				virtual const Camada& camada() const;

				/**
				 * Retorna a qual camada pertence
				 * este componente gr�fico.
				 */
				virtual Camada& camada();

				/**
				 * Nome que identifica este componente.
				 */
				virtual const std::string& nome() const;
		};
	}
  }
}

#endif // !defined(AFX_COMPONENTEGRAFICOINTERFACE_H__47E092BA_1BF5_4E1D_A523_B882706FB33D__INCLUDED_)
