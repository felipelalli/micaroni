/*
 * $RCSfile: RenderizadorTelasFrutinha.h,v $
 * $Date: 2004/05/14 19:59:16 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(SBS_AFX_RAENDERIZADORTELASSpecial_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_)
#define SBS_AFX_RAENDERIZADORTELASSpecial_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_

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
#include "biblia/jogos/frutinha/visual/configuracao/MontadorDeTelas.h"
#include "biblia/jogos/frutinha/estados/EstadosTropical.h"

 /*
#include "biblia/jogos/special/EstadosSpecial.h"
#include "biblia/jogos/special/logica/LogicaAcumulado.h"
#include "biblia/jogos/special/dados/DadosConfiguracao.h"
*/

using namespace biblia::logica;
using namespace biblia::seguranca;
//using namespace biblia::jogos::special;
//using namespace biblia::jogos::special::logica;
//using namespace biblia::jogos::special::visual;
//using namespace biblia::jogos::special::dados;
using namespace biblia::visual;
using namespace biblia::visual::dinamica;
using namespace biblia::visual::imagem2d;
using namespace biblia::visual::formulario;
using namespace biblia::visual::formulario::renderizadores;
using namespace biblia::jogos::frutinha::visual;
using namespace biblia::jogos::frutinha::estados;

namespace biblia {  namespace jogos {
namespace frutinha { namespace visual { namespace configuracao {

	class RenderizadorTelasFrutinha: public Renderizador {
		private:
			MontadorDeTelas RenderizadorTelasFrutinha::pMontadora;
			RenderizadorDeComponentesEmImagem14Bis
					RenderizadorTelasFrutinha
						::pRenderizador;

			BasicoVisual* RenderizadorTelasFrutinha::pVisual;
			EstadosTropical* RenderizadorTelasFrutinha::pEstados;
			bool RenderizadorTelasFrutinha::pPrimeiraVez;

			Ponto* RenderizadorTelasFrutinha::pPosicao;
			ImagemPosicionada* RenderizadorTelasFrutinha::pImagemPosicionada;
			ComponenteGrafico<ImagemPosicionada>*
					RenderizadorTelasFrutinha::pComponente;

		public:
			RenderizadorTelasFrutinha
					::RenderizadorTelasFrutinha();

			virtual RenderizadorTelasFrutinha
					::~RenderizadorTelasFrutinha();

			virtual RenderizadorTelasFrutinha&
					RenderizadorTelasFrutinha
						::define(BasicoVisual&, CarregadorDeSom*,
								 ChaveSeguranca*, ControleLicenca*);

			//virtual RenderizadorTelasFrutinha&
			//		RenderizadorTelasFrutinha
			//			::define(BasicoVisual&, ChaveSeguranca*,
			//			         DadosConfiguracao*, DConfiguracao*,
			//					 CarregadorDeSom*, ControleLicenca&,
			//					 LogicaAcumulado&);

			virtual RenderizadorTelasFrutinha&
					RenderizadorTelasFrutinha
						::defineEstados(EstadosTropical&);

			virtual MontadorDeTelas& RenderizadorTelasFrutinha
					::montadora();

			virtual const MontadorDeTelas& RenderizadorTelasFrutinha
					::montadora() const;

			virtual EstadosTropical& RenderizadorTelasFrutinha::jogo();

			virtual const EstadosTropical& RenderizadorTelasFrutinha
					::jogo() const;

			// Renderizador:
			virtual Executavel& RenderizadorTelasFrutinha::executa();
	};

}}}}}

#endif // !defined(SBS_AFX_RAENDERIZADORTELASSpecial_H__39F4B234_8A57_48CB_ADF3_24655C7175E6__INCLUDED_)
