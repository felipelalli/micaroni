/*
 * $RCSfile: TelaComFundo.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.9 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TELACOMFUNDO_H__B90B9A48_D8C1_4360_BF9F_F07D19257D4C__INCLUDED_)
#define AFX_TELACOMFUNDO_H__B90B9A48_D8C1_4360_BF9F_F07D19257D4C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/monitor/Tela.h"
#include "biblia/io/monitor/MonitorExcecao.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Tamanho.h"
#include "biblia/visual/imagem2d/ImagemPosicionada.h"
#include "biblia/visual/VisualExcecao.h"

using namespace biblia::visual;
using namespace biblia::visual::imagem2d;

namespace biblia {
  namespace io {
  	namespace monitor {

		/**
		 * A TelaComFundo possui um fundo
		 * que pode ser modificado a partir
		 * de algumas funções desta classe,
		 * porém deve manter guardado o fundo
		 * original.
		 */
		class TelaComFundo: public Tela {
			public:
				TelaComFundo::TelaComFundo(
						const Tamanho& resolucao);

				virtual TelaComFundo::~TelaComFundo();
				virtual const Imagem& TelaComFundo
						::fundoOriginal() const = 0;

				virtual const Imagem& TelaComFundo
						::fundo() const = 0;

				virtual const bool TelaComFundo
						::fundoDefinido() const = 0;

				/**
				 * Deve ser a primeira função a ser
				 * chamada após ser instanciada. O fundo
				 * não é definido no construtor porque
				 * para se carregar uma imagem é necessário
				 * que a tela esteja inicializada.
				 */
				virtual TelaComFundo& TelaComFundo
						::defineFundo(Imagem* fundoOriginal) = 0;

				/**
				 * Redefine o fundo para outro fundo.
				 * O fundo original passa a ser este
				 * novo fundo.
				 */
				virtual TelaComFundo& TelaComFundo
						::redefineFundo(const Imagem&) = 0;

				/**
				 * Redefine o fundo para o original,
				 * i. e., ignora tudo que foi mesclado
				 * após sua inicialização.
				 */
				virtual TelaComFundo& TelaComFundo
						::redefineFundo() = 0;

				/**
				 * Restaura uma parte do fundo ou
				 * o fundo todo caso o tamanho
				 * e a posição inicial seja (0, 0).
				 */
				virtual TelaComFundo& TelaComFundo
						::restauraFundo(Area = Area(
									   Ponto(0, 0),
									   Tamanho(0, 0))) = 0;

				/**
				 * Mescla uma imagem no fundo.
				 */
				virtual TelaComFundo& TelaComFundo
						::mesclaNoFundo(
							const ImagemPosicionada&) = 0;
		};
	}
  }
}

#endif // !defined(AFX_TELACOMFUNDO_H__B90B9A48_D8C1_4360_BF9F_F07D19257D4C__INCLUDED_)
