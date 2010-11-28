/*
 * $RCSfile: Componente.h,v $
 * $Date: 2005/01/20 21:29:46 $
 * $Revision: 1.12 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_COMPONENTE_H__55F99AC0_24B1_49B3_9665_398E3E488615__INCLUDED_)
#define AFX_COMPONENTE_H__55F99AC0_24B1_49B3_9665_398E3E488615__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <map>
#include <deque>
#include <string>
#include <typeinfo>
#include "biblia/basico/Objeto.h"
#include "biblia/visual/Bidimensional.h"
#include "biblia/visual/Posicionado.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/visual/Cor.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/formulario/PosicaoXYRelativa.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::visual;

namespace biblia {
  namespace visual {
    namespace formulario {
		/**
		 * Todos que desta derivam são componentes
		 * que serão capazes de ser "controlados" por um
		 * {@link biblia::visual::formulario::ControladorDeComponentes}
		 * e "renderizados" por um {@link biblia::visual
		 * ::formulario::RenderizadorDeComponentes}. Os controlador
		 * e renderizador devem conhecer o componente, ao menos até um
		 * certo nível.
		 */
		class Componente:public Objeto,
						 public Bidimensional
		{
			private:
				const Posicionado* Componente::pPosicao;
				const Tamanho* Componente::pTamanho;
				bool Componente::pPodeFoco;
				bool Componente::pFoco;
				bool Componente::pOculto;
				bool Componente::pHabilitado;
				Cor Componente::pCor;
				std::deque<Componente*> Componente::pFilhos;
				std::map<std::string, Componente*> Componente::pNomes;

			protected:
				Componente::Componente();

			public:
				virtual Componente::~Componente();

				/**
				 * Define uma nova posição.
				 * <b>Deleta</b> no destrutor!
				 */
				virtual Componente& Componente::posicao(
						const Posicionado*);

				virtual Componente& Componente::posicao(
						const Ponto&);

				/**
				 * Define um novo tamanho.
				 * <b>Deleta</b> no destrutor!
				 */
				virtual Componente& Componente::tamanho(
						const Tamanho*);

				virtual Componente& Componente::tamanho(
						const Tamanho&);

				virtual Componente& Componente::podeFoco(bool);
				virtual Componente& Componente::foco(bool);
				virtual Componente& Componente::oculto(bool);
				virtual Componente& Componente::habilitado(bool);
				virtual Componente& Componente::cor(const Cor&);
				/**
				 * Arranca somente os filhos diretos.
				 */
				virtual Componente& Componente::arrancaFilhos();

				/**
				 * Arranca os filhos e os "netos".
				 */
				virtual Componente& Componente::arrancaTodosOsFilhos();

				virtual std::deque<Componente*>& Componente::filhos();
				virtual bool Componente::haFilho(const std::string& nome) const;
				virtual Componente& Componente::filho(const std::string& nome);
				virtual Componente& Componente::procuraFilho(const std::string& nome);
				virtual Componente& Componente::adicionaFilho(
						Componente&, const std::string& nome);

				virtual const Ponto& Componente::posicao() const;
				virtual const Tamanho& Componente::tamanho() const;
				virtual const bool Componente::podeFoco() const;
				virtual const bool& Componente::foco() const;
				virtual const bool& Componente::oculto() const;
				virtual const bool& Componente::habilitado() const;
				virtual const Cor& Componente::cor() const;
				virtual const std::deque<Componente*>&
						Componente::filhos() const;

				// Bidimensional:
				virtual Area Componente::areaQueOcupa() const;

				// Objeto:
				virtual std::string Componente::emString() const;
		};
	}
  }
}

#endif // !defined(AFX_COMPONENTE_H__55F99AC0_24B1_49B3_9665_398E3E488615__INCLUDED_)
