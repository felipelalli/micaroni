/*
 * $RCSfile: CarregadorDeComponentes.h,v $
 * $Date: 2005/03/22 02:14:37 $
 * $Revision: 1.18 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_CARREGADORDECOMPONENTES_H__1B356582_FF62_4BD3_8326_747A4AB28F5A__INCLUDED_)
#define AFX_CARREGADORDECOMPONENTES_H__1B356582_FF62_4BD3_8326_747A4AB28F5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <map>
#include <deque>
#include "biblia/util/Carregador.h"
#include "biblia/util/StrToken.h"
#include "biblia/util/Lixeira.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/visual/imagem2d/ImagemPosicionada.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/animacao/Video.h"
#include "biblia/visual/animacao/SpriteWizard.h"
#include "biblia/visual/animacao/util/ArquivoDeAreas.h"
#include "biblia/visual/fonte/FonteImagem.h"
#include "biblia/visual/fonte/TextoComFonte.h"
#include "biblia/visual/dinamica/ComponenteGrafico.h"
#include "biblia/visual/dinamica/ComponentesUnidos.h"
#include "biblia/armazenamento/volatil/carcacas/MapaHash.h"

using namespace std;
using namespace biblia::util;
using namespace biblia::io::disco;
using namespace biblia::tempo;
using namespace biblia::tempo::unidades;
using namespace biblia::visual::imagem2d;
using namespace biblia::visual::animacao;
using namespace biblia::visual::animacao::util;
using namespace biblia::visual::fonte;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace visual {
    namespace dinamica {

		/**
		 * Carrega componentes <b>gráficos</b>:
		 * <UL type=disc>
		 * <LI>{@link biblia::visual::dinamica::ComponenteGrafico<ImagemPosicionada>};
		 * <LI>{@link biblia::visual::dinamica::ComponenteGrafico<Video>};
		 * <LI>{@link biblia::visual::fonte::ComponenteGrafico<TextoComFonte<FonteImagem>>};
		 * <LI>{@link biblia::visual::fonte::FonteImagem}.
		 * </UL>
		 * <p>
		 * É usado também para a manipulação dos componentes
		 * de modo rápido (pois utiliza tabela hash internamente).
		 */
		class CarregadorDeComponentes: public Carregador {
			private:
				MapaHash<ComponenteGrafico<ImagemPosicionada>*>
						CarregadorDeComponentes::pImagens;

				MapaHash<ComponenteGrafico<Video>*>
						CarregadorDeComponentes::pAnimacoes;

				MapaHash<ComponenteGrafico<TextoComFonte<FonteImagem> >*>
						CarregadorDeComponentes::pTextos;

				MapaHash<FonteImagem*> CarregadorDeComponentes::pFontes;

				/**
				 * Armazena os "grupos" formados por coringas
				 * como "*", "animacao.*" etc.
				 */
				MapaHash<ComponenteGraficoInterface*> pCoringas;

				FabricaDeImagens& CarregadorDeComponentes::pFabrica;
				UniversoDeTempo& CarregadorDeComponentes::pTempo;
				SpriteWizard CarregadorDeComponentes::pSpriteWizard;

				// Lista das coisas a carregar:
				std::deque<int> CarregadorDeComponentes::pTipo;
				std::deque<string> CarregadorDeComponentes::pChaves;
				std::deque<string> CarregadorDeComponentes::pNomeDoArquivoBasico;
				std::deque<string> CarregadorDeComponentes
						::pNomeDoArquivoBasicoDeAreas;

				MapaHash<string> pArquivosDeArea;

				// informação adicional:
				std::string CarregadorDeComponentes::pUltimoCarregado;
				int CarregadorDeComponentes::pTotal;

			public:
				static int CarregadorDeComponentes::IMAGEM;
				static int CarregadorDeComponentes::ANIMACAO;
				static int CarregadorDeComponentes::ANIMACAO_SEPARADA;
				static int CarregadorDeComponentes::FONTE;
				static int CarregadorDeComponentes::TEXTO;
				static int CarregadorDeComponentes::CLONE_IMAGEM;
				static int CarregadorDeComponentes::CLONE_ANIMACAO;

				CarregadorDeComponentes::CarregadorDeComponentes(
						FabricaDeImagens&, UniversoDeTempo&);

				virtual CarregadorDeComponentes
						::~CarregadorDeComponentes();

				virtual const std::string& CarregadorDeComponentes
						::ultimoCarregado() const;

				virtual const int& CarregadorDeComponentes
						::total() const;

				virtual CarregadorDeComponentes& CarregadorDeComponentes
						::carregaImagem(const std::string& chave,
										const std::string& nomeDoArquivoBasico);

				virtual FabricaDeImagens& CarregadorDeComponentes::fabrica();
				virtual UniversoDeTempo& CarregadorDeComponentes::tempo();

				/**
				 * @see biblia::visual::animacao::util::ArquivoBasicoDeAreas.
				 */
				virtual CarregadorDeComponentes& CarregadorDeComponentes
						::carregaAnimacao(const std::string& chave,
										  const std::string& nomeDoArquivoBasico,
										  const std::string& arquivoDeAreas);

				/**
				 * @see biblia::visual::animacao::util::ArquivoBasicoDeAreas.
				 */
				virtual CarregadorDeComponentes& CarregadorDeComponentes
						::carregaAnimacaoSeparada(
								const std::string& chave,
								const std::string& nomeDoArquivo,
								const std::string& numeroDeQuadros,
								const std::string& arquivoDeAreas);

				/**
				 * @see biblia::visual::fonte::util::ArquivoBasicoDeAreasFonte.
				 */
				virtual CarregadorDeComponentes& CarregadorDeComponentes
						::carregaFonte(const std::string& chave,
									   const std::string& nomeDoArquivoBasico,
									   const std::string& arquivoDeAreas);

				/**
				 * A fonte já deve estar carregada anteriormente.
				 */
				virtual CarregadorDeComponentes& CarregadorDeComponentes
						::carregaTexto(const std::string& chave,
									   const std::string& chaveDaFonte);

				/**
				 * A imagem já deve estar carregada anteriormente.
				 */
				virtual CarregadorDeComponentes& CarregadorDeComponentes
						::carregaCloneImagem(const std::string& chave,
									         const std::string& chaveDaImagem);

				/**
				 * A animação já deve estar carregada anteriormente.
				 */
				virtual CarregadorDeComponentes& CarregadorDeComponentes
						::carregaCloneAnimacao(const std::string& chave,
									           const std::string& chaveDaAnimacao);

				/**
				 * Retorna a imagem.
				 */
				virtual ComponenteGrafico<ImagemPosicionada>&
						CarregadorDeComponentes::imagem(const std::string& chave);

				/**
				 * Retorna a animação.
				 */
				virtual ComponenteGrafico<Video>&
						CarregadorDeComponentes::animacao(const std::string& chave);

				/**
				 * Retorna a fonte.
				 */
				virtual FonteImagem& CarregadorDeComponentes
						::fonte(const std::string& chave);

				/**
				 * Retorna o texto.
				 */
				virtual ComponenteGrafico<TextoComFonte<FonteImagem> >&
						CarregadorDeComponentes::texto(const std::string& chave);

				/**
				 * Retorna um componente qualquer. Se houver mais
				 * de um tipo de componente com o mesmo nome, ele
				 * retorna um conjunto de Componentes representado
				 * por ComponentesUnidos.
				 * <p>
				 * <i>O coringa "*" funciona para todos os componentes.</i>
				 */
				virtual ComponenteGraficoInterface& CarregadorDeComponentes
						::componente(const std::string& chave);

				virtual bool CarregadorDeComponentes
						::imagemJaCarregada(const std::string& chave) const;

				virtual bool CarregadorDeComponentes
						::animacaoJaCarregada(const std::string& chave) const;

				virtual bool CarregadorDeComponentes
						::fonteJaCarregada(const std::string& chave) const;

				virtual bool CarregadorDeComponentes
						::textoJaCarregado(const std::string& chave) const;

				// Carregador:
				virtual Carregador& CarregadorDeComponentes::destroi();

				// Executavel:
				virtual Executavel& CarregadorDeComponentes::executa();
		};
	}
  }
}

#endif // !defined(AFX_CARREGADORDECOMPONENTES_H__1B356582_FF62_4BD3_8326_747A4AB28F5A__INCLUDED_)
