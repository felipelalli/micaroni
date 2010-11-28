/*
 * $RCSfile: AnimacaoComponente.h,v $
 * $Date: 2005/01/20 21:29:45 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_ANIMACAOCOMPONENTE_H__A5AA8D40_348D_4BF0_9866_0341DF3E5620__INCLUDED_)
#define AFX_ANIMACAOCOMPONENTE_H__A5AA8D40_348D_4BF0_9866_0341DF3E5620__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/formulario/Componente.h"
#include "biblia/visual/dinamica/ComponenteGrafico.h"
#include "biblia/visual/dinamica/CarregadorDeComponentes.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/animacao/Sprite.h"
#include "biblia/visual/animacao/Video.h"

using namespace biblia::visual::imagem2d;
using namespace biblia::visual::animacao;
using namespace biblia::visual::dinamica;

namespace biblia {
  namespace visual {
    namespace formulario {
		class AnimacaoComponente: public Componente {
			private:
				ComponenteGrafico<Video>* AnimacaoComponente::pComponente;
				Video* AnimacaoComponente::pVideo;
				Sprite* AnimacaoComponente::pSprite;
				std::string AnimacaoComponente::pNome;
				bool AnimacaoComponente::pAnimando;

			public:
				AnimacaoComponente::AnimacaoComponente();
				virtual AnimacaoComponente::~AnimacaoComponente();

				virtual bool AnimacaoComponente::animando() const;
				virtual AnimacaoComponente&
						AnimacaoComponente::animando(bool);

				virtual bool AnimacaoComponente::temVideo() const;
				virtual AnimacaoComponente& AnimacaoComponente
						::nome(const std::string& nome);

				virtual const std::string& AnimacaoComponente::nome() const;
				virtual AnimacaoComponente& AnimacaoComponente
						::defineVideo(CarregadorDeComponentes&,
								FabricaDeImagens&);

				virtual ComponenteGrafico<Video>*
						AnimacaoComponente::video();
		};
	}
  }
}

#endif // !defined(AFX_ANIMACAOCOMPONENTE_H__A5AA8D40_348D_4BF0_9866_0341DF3E5620__INCLUDED_)
