/*
 * $RCSfile: RenderizadorTelasSpecial.h,v $
 * $Date: 2005/01/13 17:09:51 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_RENDERIZADORTELASSpecial_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_RENDERIZADORTELASSpecial_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef AGES_SPECIAL_UPGRADE_WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/logica/Renderizador.h"
#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/seguranca/ControleLicenca.h"
#include "biblia/visual/imagem2d/ImagemPosicionada.h"
#include "biblia/visual/dinamica/BasicoVisual.h"
#include "biblia/visual/dinamica/ComponenteGrafico.h"
#include "biblia/visual/formulario/renderizadores/RenderizadorDeComponentesEmImagem14Bis.h"
#include "biblia/visual/formulario/AnimacaoComponente.h"
#include "biblia/jogos/specialUpgrade/EstadosSpecial.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaAcumulado.h"
#include "biblia/jogos/specialUpgrade/dados/DadosConfiguracao.h"
#include "biblia/jogos/specialUpgrade/visual/formulario/MontadorDeTelas.h"

using namespace biblia::logica;
using namespace biblia::seguranca;
using namespace biblia::jogos::specialUpgrade;
using namespace biblia::jogos::specialUpgrade::logica;
using namespace biblia::jogos::specialUpgrade::visual;
using namespace biblia::jogos::specialUpgrade::dados;
using namespace biblia::visual;
using namespace biblia::visual::formulario;
using namespace biblia::visual::formulario::renderizadores;
using namespace biblia::visual::dinamica;
using namespace biblia::visual::imagem2d;

namespace biblia {  namespace jogos {
namespace specialUpgrade { namespace visual { namespace formulario {

	class RenderizadorTelasSpecial: public Renderizador {
		private:
			MontadorDeTelas RenderizadorTelasSpecial::pMontadora;
			RenderizadorDeComponentesEmImagem14Bis
					RenderizadorTelasSpecial
						::pRenderizador;

			BasicoVisual* RenderizadorTelasSpecial::pVisual;
			EstadosSpecial* RenderizadorTelasSpecial::pEstados;
			bool RenderizadorTelasSpecial::pPrimeiraVez;

			Ponto* RenderizadorTelasSpecial::pPosicao;
			ImagemPosicionada* RenderizadorTelasSpecial::pImagemPosicionada;
			ComponenteGrafico<ImagemPosicionada>*
					RenderizadorTelasSpecial::pComponente;

		public:
			RenderizadorTelasSpecial
					::RenderizadorTelasSpecial();

			virtual RenderizadorTelasSpecial
					::~RenderizadorTelasSpecial();

			virtual RenderizadorTelasSpecial&
					RenderizadorTelasSpecial
						::define(BasicoVisual&, ChaveSeguranca*,
						         DadosConfiguracao*, DConfiguracao*,
								 CarregadorDeSom*, ControleLicenca&,
								 LogicaAcumulado&,Contador&);

			virtual RenderizadorTelasSpecial&
					RenderizadorTelasSpecial
						::defineEstados(
							EstadosSpecial&);

			virtual MontadorDeTelas& RenderizadorTelasSpecial
					::montadora();

			virtual const MontadorDeTelas& RenderizadorTelasSpecial
					::montadora() const;

			virtual EstadosSpecial&
					RenderizadorTelasSpecial
						::jogo();

			virtual const EstadosSpecial&
					RenderizadorTelasSpecial
						::jogo() const;

			// Renderizador:
			virtual Executavel& RenderizadorTelasSpecial::executa();
	};

}}}}}

#endif // !defined(SBS_AFX_RENDERIZADORTELASSpecial_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_)
