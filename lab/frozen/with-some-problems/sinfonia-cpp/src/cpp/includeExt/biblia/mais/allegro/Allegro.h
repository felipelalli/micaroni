/*
 * $RCSfile: Allegro.h,v $
 * $Date: 2005/01/20 21:29:02 $
 * $Revision: 1.12 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_ALLEGRO_H__717AF9B5_4198_4E80_AA80_2906E81B07C5__INCLUDED_)
#define AFX_ALLEGRO_H__717AF9B5_4198_4E80_AA80_2906E81B07C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <allegro.h>
#ifdef WIN32
#include <winalleg.h>
#endif

#include "biblia/basico/Objeto.h"
#include "biblia/io/disco/DiscoExcecao.h"
#include "biblia/io/monitor/Tela.h"
#include "biblia/visual/Cor.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/mais/allegro/ImagemAllegro.h"
#include "biblia/mais/allegro/TelaAllegro.h"
#include "biblia/mais/allegro/AllegroExcecao.h"
#include <string>

using namespace biblia::basico;
using namespace biblia::visual;
using namespace biblia::io::disco;
using namespace biblia::io::monitor;
using namespace std;

namespace biblia {
  namespace mais {
 	namespace allegro {

		class ImagemAllegro; // é necessário pois ela utiliza Allegro.
		class TelaAllegro;   // idem.

		/**
		 * <b>Não utilize esta classe diretamente.
		 * Prefira utilizar {@link
		 * biblia::mais::allegro::FabricaDeImagensAllegroSegura}
		 * para a criação de imagens e {@link
		 * biblia::mais::allegro::CapturadorDeTelaAllegro}
		 * para capturar a {@link biblia::io::monitor::Tela
		 * tela}.</b>
		 * <p>
		 * Representa as funções básicas
		 * que o Allegro é capaz de fazer.
		 * Esta classe é amiga de {@link
		 * biblia::mais::allegro::ImagemAllegro} e
		 * de {@link biblia::mais::allegro::TelaAllegro}
		 * para que algumas operações sejam possíveis.
		 */
		class Allegro: public Objeto {
			private:
				Allegro::Allegro();
				virtual Allegro::~Allegro();

			public:
				static ImagemAllegro* Allegro::carregaDeArquivoBasico
						(const std::string& nomeDoArquivoBasico,
						 const Tela&);

				static ImagemAllegro* Allegro::criaVazio(
						 const Tamanho&, const Tela&);

				/**
				 * Este bitmap deve ser responsabilidade
				 * de quem o está chamando. A imagem gerada
				 * a partir desta função não deletará este
				 * bitmap no destrutor.
				 */
				static ImagemAllegro* Allegro::gera(BITMAP*);

				static TelaAllegro* Allegro
						::capturaTela(
								const Tamanho& resolucao);

				static int Allegro::converteCor(const Cor&);
				static int Allegro::converteCorAlpha(const Cor&);

				static void Allegro::inicializa();
		};
	}
  }
}

#endif // !defined(AFX_ALLEGRO_H__717AF9B5_4198_4E80_AA80_2906E81B07C5__INCLUDED_)
