/*
 * $RCSfile: FonteImagemWizard.h,v $
 * $Date: 2005/01/20 21:29:45 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_FONTEIMAGEMWIZARD_H__B183E487_128C_49A5_9AE4_D1E4B31A484D__INCLUDED_)
#define AFX_FONTEIMAGEMWIZARD_H__B183E487_128C_49A5_9AE4_D1E4B31A484D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <string>
#include "biblia/util/Wizard.h"
#include "biblia/util/CData.h"
#include "biblia/visual/animacao/AnimacaoDeImagens.h"
#include "biblia/visual/fonte/FonteExcecao.h"
#include "biblia/visual/fonte/FonteImagem.h"

using namespace std;
using namespace biblia::util;
using namespace biblia::visual::animacao;

namespace biblia {
  namespace visual {
    namespace fonte {

		/**
		 * Cria uma FonteImagem a partir de uma
		 * std::string de letras válidas e uma animação
		 * de imagens.
		 * <p>
		 * Essa animação de imagens deve ser excluída
		 * externamente de alguma forma. A FonteImagem
		 * gerada não é capaz de se "auto-destruir".
		 *
		 * @see biblia::visual::animacao::SpriteWizard
		 */
		class FonteImagemWizard: public Wizard {
			private:
				Objeto* FonteImagemWizard::pResultado;
				AnimacaoDeImagens* FonteImagemWizard::pAnimacao;
				std::string FonteImagemWizard::pLetras;

			public:
				FonteImagemWizard::FonteImagemWizard();
				virtual FonteImagemWizard::~FonteImagemWizard();

				virtual FonteImagemWizard& FonteImagemWizard
						::define(const std::string& letras,
								 AnimacaoDeImagens&);

				// Wizard:
				virtual Objeto* FonteImagemWizard
						::resultado() const;

				// Executavel:

				/**
				 * Executa a partir dos dados
				 * predefinidos e gera um resultado.
				 *
				 * @see #resultado() const
				 */
				virtual Executavel& FonteImagemWizard::executa();
		};
	}
  }
}

#endif // !defined(AFX_FONTEIMAGEMWIZARD_H__B183E487_128C_49A5_9AE4_D1E4B31A484D__INCLUDED_)
