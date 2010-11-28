/*
 * $RCSfile: SpriteWizard.h,v $
 * $Date: 2005/01/20 21:29:33 $
 * $Revision: 1.9 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_SPRITEWIZARD_H__DCF14018_97F8_442B_B225_DEB796344935__INCLUDED_)
#define AFX_SPRITEWIZARD_H__DCF14018_97F8_442B_B225_DEB796344935__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/util/Wizard.h"
#include "biblia/util/UtilExcecao.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/VisualExcecao.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/animacao/Sprite.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::visual;
using namespace biblia::visual::imagem2d;

namespace biblia {
  namespace visual {
 	namespace animacao {

		/**
		 * Gera {@link biblia::visual::animacao::Sprite}s
		 * de forma 'm�gica', a partir dos par�metros
		 * das fun��es <code>define</code>.
		 */
		class SpriteWizard: public Wizard {
			private:
				static const int SpriteWizard::NADA;
				static const int SpriteWizard::MESMA_FIGURA_MESMA_AREA;
				static const int SpriteWizard::MESMA_FIGURA_AREAS_VARIADAS;
				static const int SpriteWizard::VARIAS_FIGURAS;

				Sprite* SpriteWizard::pResultado;
				FabricaDeImagens& SpriteWizard::pFabrica;

				unsigned int SpriteWizard::pQuadros;
				std::string SpriteWizard::pNomeDoArquivoBasico;
				std::string SpriteWizard::pExtensao;
				std::deque<Area> SpriteWizard::pAreas;

				/* Interno */
				volatile int SpriteWizard::pModo;
				std::string SpriteWizard::pFormato;

			public:
				SpriteWizard::SpriteWizard(FabricaDeImagens&);
				virtual SpriteWizard::~SpriteWizard();

				// Define par�metros:

				/**
				 * Nesse caso um s� arquivo deve conter
				 * todas as figuras da anima��o com
				 * a mesma �rea, da esquerda para direita.
				 */
				virtual SpriteWizard& SpriteWizard::define(
						const std::string& nomeDoArquivoBasico,
						unsigned int quadros,
						const Area& deCadaQuadro);

				/**
				 * @see #define(
				 *		const std::string& nomeDoArquivoBasico,
				 *		unsigned int quadros,
				 *		const Area& deCadaQuadro)
				 */
				virtual SpriteWizard& SpriteWizard::define(
						const std::string& nomeDoArquivoBasico,
						unsigned int quadros,
						const Tamanho& deCadaQuadro);

				/**
				 * Nesse caso um s� arquivo deve conter
				 * todas as figuras da anima��o com
				 * �reas diferentes, passadas pela lista.
				 * <p>
				 * <i>Lembre-se: A posi��o definida na
				 * �rea � levada em conta. Portanto as figuras
				 * podem estar dispostas em qualquer ordem
				 * dentro da figura maior.</i>
				 */
				virtual SpriteWizard& SpriteWizard::define(
						const std::string& nomeDoArquivoBasico,
						const std::deque<Area>&);

				/**
				 * O formato do nome do arquivo em disco
				 * deve ser f("%s%d.%s", nomeDoArquivoBasico,
				 * quadroAtual, extensao) come�ando
				 * do zero.
				 * <p>
				 * <i>E.g.: os arquivos devem chamar
				 * 'arquivo0.ext', 'arquivo1.ext',
				 * 'arquivo2.ext' etc.</i>
				 * <p>
				 * <i>Obs.: A {@link
				 * biblia::visual::imagem2d::FabricaDeImagens} deve
				 * ser capaz de abrir o arquivo no formato passado.</i>
				 */
				virtual SpriteWizard& SpriteWizard::define(
						const std::string& nomeDoArquivoBasico,
						const std::string& extensao,
						unsigned int quadros = 1,
						const std::string formato = "%s%d.%s");

				// Wizard:
				/**
				 * Retorna uma inst�ncia de {@link
				 * biblia::visual::animacao::Sprite}.
				 * � necess�rio que a fun��o {@link
				 * #executa()} seja executada anteriormente.
				 */
				virtual Objeto* SpriteWizard::resultado() const;

				// Executavel:

				/**
				 * Antes de executar � necess�rio definir
				 * os par�metros.
				 *
				 * @see #resultado() const
				 * @see #define(const std::string& nomeDoArquivoBasico,
				 *			const std::string& extensao,
				 *			unsigned int quadros)
				 *
				 * @see #define(const std::string& nomeDoArquivoBasico,
				 * 			unsigned int quadros,
				 * 			const std::deque<const Area>&)
				 */
				virtual Executavel& SpriteWizard::executa();
		};
	}
  }
}

#endif // !defined(AFX_SPRITEWIZARD_H__DCF14018_97F8_442B_B225_DEB796344935__INCLUDED_)
