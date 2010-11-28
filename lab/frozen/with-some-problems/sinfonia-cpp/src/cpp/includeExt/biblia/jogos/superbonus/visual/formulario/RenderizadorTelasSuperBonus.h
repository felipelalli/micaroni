/*
 * $RCSfile: RenderizadorTelasSuperBonus.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.12 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_RENDERIZADORTELASSUPERBONUS_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_)
#define AFX_RENDERIZADORTELASSUPERBONUS_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
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
#include "biblia/jogos/superbonus/EstadosSuperBonus.h"
#include "biblia/jogos/superbonus/logica/LogicaAcumulado.h"
#include "biblia/jogos/superbonus/dados/DadosConfiguracao.h"
#include "biblia/jogos/superbonus/visual/formulario/MontadorDeTelas.h"

using namespace biblia::logica;
using namespace biblia::seguranca;
using namespace biblia::jogos::superbonus;
using namespace biblia::jogos::superbonus::logica;
using namespace biblia::jogos::superbonus::visual;
using namespace biblia::jogos::superbonus::dados;
using namespace biblia::visual;
using namespace biblia::visual::formulario;
using namespace biblia::visual::formulario::renderizadores;
using namespace biblia::visual::dinamica;
using namespace biblia::visual::imagem2d;

namespace biblia {  namespace jogos {
namespace superbonus { namespace visual { namespace formulario {

	class RenderizadorTelasSuperBonus: public Renderizador {
		private:
			MontadorDeTelas RenderizadorTelasSuperBonus::pMontadora;
			RenderizadorDeComponentesEmImagem14Bis
					RenderizadorTelasSuperBonus
						::pRenderizador;

			BasicoVisual* RenderizadorTelasSuperBonus::pVisual;
			EstadosSuperBonus* RenderizadorTelasSuperBonus::pEstados;
			bool RenderizadorTelasSuperBonus::pPrimeiraVez;

			Ponto* RenderizadorTelasSuperBonus::pPosicao;
			ImagemPosicionada* RenderizadorTelasSuperBonus::pImagemPosicionada;
			ComponenteGrafico<ImagemPosicionada>*
					RenderizadorTelasSuperBonus::pComponente;

		public:
			RenderizadorTelasSuperBonus
					::RenderizadorTelasSuperBonus();

			virtual RenderizadorTelasSuperBonus
					::~RenderizadorTelasSuperBonus();

			virtual RenderizadorTelasSuperBonus&
					RenderizadorTelasSuperBonus
						::define(BasicoVisual&, ChaveSeguranca*,
						         DadosConfiguracao*, DConfiguracao*,
								 CarregadorDeSom*, ControleLicenca&,
								 LogicaAcumulado&);

			virtual RenderizadorTelasSuperBonus&
					RenderizadorTelasSuperBonus
						::defineEstados(
							EstadosSuperBonus&);

			virtual MontadorDeTelas& RenderizadorTelasSuperBonus
					::montadora();

			virtual const MontadorDeTelas& RenderizadorTelasSuperBonus
					::montadora() const;

			virtual EstadosSuperBonus&
					RenderizadorTelasSuperBonus
						::jogo();

			virtual const EstadosSuperBonus&
					RenderizadorTelasSuperBonus
						::jogo() const;

			// Renderizador:
			virtual Executavel& RenderizadorTelasSuperBonus::executa();
	};

}}}}}

#endif // !defined(AFX_RENDERIZADORTELASSUPERBONUS_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_)
