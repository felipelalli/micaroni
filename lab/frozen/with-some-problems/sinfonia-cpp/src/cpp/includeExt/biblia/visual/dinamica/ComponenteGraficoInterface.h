/*
 * $RCSfile: ComponenteGraficoInterface.h,v $
 * $Date: 2005/01/20 21:29:33 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
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
		 * É o pai de todos os
		 * {@link biblia::visual::dinamica::ComponenteGrafico<class T>
		 * componentes gráficos}.
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
				 * Associa si mesmo à camada.
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
				 * Torna este componente visível ou não.
				 */
				virtual ComponenteGraficoInterface& visivel(const bool);

				/**
				 * Indica que este componente gráfico
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
				 * <b>Atenção ao usar isto. Somente um 'desenhista'
				 * pode usar isto.</b>
				 */
				virtual ComponenteGraficoInterface& descola();

				/**
				 * Copia os mesmos atributos do que é passado como
				 * parâmetro, exceto a camada e o nome.
				 */
				virtual ComponenteGraficoInterface& copiaAtributosDe(
						const ComponenteGraficoInterface&);

				/**
				 * Só deve ser desenhado
				 * se estiver visível.
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
				 * Já foi mesclado e não deve
				 * ser desenhado novamente.
				 * <p>
				 * Equivale a
				 * <code>!flutuante()</code>
				 */
				virtual bool mesclado() const;

				/**
				 * Retorna a qual camada (somente-leitura)
				 * pertence este componente gráfico.
				 */
				virtual const Camada& camada() const;

				/**
				 * Retorna a qual camada pertence
				 * este componente gráfico.
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
