/*
 * $RCSfile: AnimacaoFlic.h,v $
 * $Date: 2005/01/20 21:29:02 $
 * $Revision: 1.2 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_ANIMACAOFLIC_H__75595D4D_77CB_4A66_BED2_3EC461F02400__INCLUDED_)
#define AFX_ANIMACAOFLIC_H__75595D4D_77CB_4A66_BED2_3EC461F02400__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/mais/allegro/Allegro.h"
#include "biblia/mais/allegro/FabricaDeImagensAllegroSegura.h"
#include "biblia/mais/MaisExcecao.h"
#include "biblia/visual/animacao/AnimacaoDeImagens.h"

using namespace biblia::mais;
using namespace biblia::mais::allegro;
using namespace biblia::visual::animacao;

namespace biblia {
  namespace mais {
 	namespace allegro {
		/**
		 * Anima��o FLIC do Allegro.
		 *
		 * @todo Tentativa de fazer o FLIC do Allegro, mas n�o
		 *       deu certo. Parece que o tamanho m�ximo pode
		 *       ser apenas 320�200 etc.
		 *
		 * @fixme
		 * @bug N�o funciona!
		 */
		class AnimacaoFlic: public AnimacaoDeImagens {
			private:
				std::string AnimacaoFlic::pArquivo;
				FabricaDeImagensAllegroSegura& AnimacaoFlic::pFabrica;
				ImagemAllegro* AnimacaoFlic::pImagemAllegro;
				ImagemPosicionada* AnimacaoFlic::pImagem;

			protected:
				AnimacaoFlic& AnimacaoFlic::operacaoNaoSuportada();

			public:
				AnimacaoFlic::AnimacaoFlic(
						FabricaDeImagensAllegroSegura&,
						const std::string& arquivo,
						const Ponto& p,
						bool emLoop);

				virtual AnimacaoFlic::~AnimacaoFlic();

				// AnimacaoDeImagens:
				virtual const ImagemPosicionada&
						AnimacaoFlic::imagem() const;

				// Animacao:
				virtual Animacao& AnimacaoFlic::reinicia();

				virtual bool AnimacaoFlic::inicio() const;
				virtual bool AnimacaoFlic::fim() const;

				// opera��es n�o suportadas:
				virtual Animacao& AnimacaoFlic::inverteSentido();
				virtual Animacao& AnimacaoFlic::sentidoInverso(bool sim);
				virtual Animacao& AnimacaoFlic::vaiEVolta(bool sim);

				// ExecutavelOtimizado:
				virtual ExecutavelOtimizado& AnimacaoFlic
						::executa(int quantasVezes);

				// AnimacaoDeQuadros:
				virtual unsigned int AnimacaoFlic
						::quantosQuadros() const;

				virtual AnimacaoDeQuadros& AnimacaoFlic
						::vaiPara(unsigned int quadro);

				virtual unsigned int AnimacaoFlic
						::quadroAtual() const;

				// Bidimensional:
				virtual Area AnimacaoFlic
						::areaQueOcupa() const;

				// Posicionado:
				virtual Posicionado& AnimacaoFlic
						::reposiciona(const Ponto&);
		};
	}
  }
}

#endif // !defined(AFX_ANIMACAOFLIC_H__75595D4D_77CB_4A66_BED2_3EC461F02400__INCLUDED_)
