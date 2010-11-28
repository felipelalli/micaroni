/*
 * $RCSfile: DesenhistaDeResultadoGraficoNaTela.h,v $
 * $Date: 2005/01/20 21:29:34 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_DESENHISTADERESULTADOGRAFICONATELA_H__31FFC27F_D829_4D52_B0B4_ED19509F51D8__INCLUDED_)
#define AFX_DESENHISTADERESULTADOGRAFICONATELA_H__31FFC27F_D829_4D52_B0B4_ED19509F51D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <map>
#include <typeinfo>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Lixeira.h"
#include "biblia/logica/Realizador.h"
#include "biblia/io/monitor/TelaComFundo.h"
#include "biblia/visual/imagem2d/ImagemPosicionada.h"
#include "biblia/visual/imagem2d/FabricaDeImagens.h"
#include "biblia/visual/animacao/Video.h"
#include "biblia/visual/fonte/TextoComFonte.h"
#include "biblia/visual/fonte/FonteImagem.h"
#include "biblia/visual/fonte/RenderizadorDeFonteImagem.h"
#include "biblia/visual/dinamica/DinamicaExcecao.h"
#include "biblia/visual/dinamica/ResultadoGrafico.h"
#include "biblia/visual/dinamica/ComponenteGrafico.h"
#include "biblia/visual/dinamica/ComponenteGraficoInterface.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::logica;
using namespace biblia::io::monitor;
using namespace biblia::visual::imagem2d;
using namespace biblia::visual::animacao;
using namespace biblia::visual::fonte;

namespace biblia {
  namespace visual {
    namespace dinamica {

		/**
		 * Classe principal do pacote 'dinâmica de visual'
		 * que desenhará de fato o {@link
		 * biblia::visual::dinamica::ResultadoGrafico}.
		 * <p>
		 * Este desenhista de resultado gráfico sabe
		 * desenhar os seguintes componentes:
		 * <UL type=disc>
		 * <LI>{@link biblia::visual::imagem2d::ImagemPosicionada};
		 * <LI>{@link biblia::visual::animacao::Video};
		 * <LI>{@link biblia::visual::fonte::TextoComFonte
		 *     <FonteImagem>}.
		 * </UL>TextoComFonte
		 *
		 * @see biblia::logica::Realizador
		 * @see biblia::visual::dinamica::DinamicaExcecao
		 * @todo Esta classe pode ser *muito* mais otimizada,
		 *        excluindo os elementos que sobrepõe um ao outro.
		 */
		class DesenhistaDeResultadoGraficoNaTela
				:public Realizador
		{
			private:
				FabricaDeImagens* DesenhistaDeResultadoGraficoNaTela
						::pFabrica;

				TelaComFundo* DesenhistaDeResultadoGraficoNaTela
						::pTela;

				ResultadoGrafico* DesenhistaDeResultadoGraficoNaTela
						::pResultado;

				bool DesenhistaDeResultadoGraficoNaTela::pRestaurouFundo;

				map<std::string, Imagem*>
						DesenhistaDeResultadoGraficoNaTela
							::pTextosAntigos;

				Lixeira DesenhistaDeResultadoGraficoNaTela
						::pLixeiraDosTextosAntigos;

				/**
				 * Não existe cópia disto.
				 *
				DesenhistaDeResultadoGraficoNaTela
						::DesenhistaDeResultadoGraficoNaTela
							(const DesenhistaDeResultadoGraficoNaTela&);
				*/

			protected:
				virtual FabricaDeImagens& DesenhistaDeResultadoGraficoNaTela
						::fabrica();

				virtual TelaComFundo& DesenhistaDeResultadoGraficoNaTela
						::tela();

				virtual ResultadoGrafico& DesenhistaDeResultadoGraficoNaTela
						::resultado();

				virtual DesenhistaDeResultadoGraficoNaTela&
						DesenhistaDeResultadoGraficoNaTela
							::desenha(ComponenteGraficoInterface*,
									  bool mescla = false);

			public:
				DesenhistaDeResultadoGraficoNaTela
						::DesenhistaDeResultadoGraficoNaTela
							(FabricaDeImagens* = NULL,
							 TelaComFundo* = NULL,
							 ResultadoGrafico* = NULL);

				virtual DesenhistaDeResultadoGraficoNaTela
						::~DesenhistaDeResultadoGraficoNaTela();

				virtual DesenhistaDeResultadoGraficoNaTela&
							DesenhistaDeResultadoGraficoNaTela
								::outraFabrica(FabricaDeImagens*);

				virtual DesenhistaDeResultadoGraficoNaTela&
							DesenhistaDeResultadoGraficoNaTela
								::outraTela(TelaComFundo*);

				virtual DesenhistaDeResultadoGraficoNaTela&
							DesenhistaDeResultadoGraficoNaTela
								::outroResultado(ResultadoGrafico*);

				/**
				 * Deve ser chamado toda vez que algum
				 * 'ciclo' iniciar. Esta função faz com que
				 * o fundo seja restaurado e os componentes
				 * 'descolados'.
				 */
				virtual DesenhistaDeResultadoGraficoNaTela&
							DesenhistaDeResultadoGraficoNaTela
								::restauraFundo();

				/**
				 * Limpa o buffer dos textos antigos.
				 */
				virtual DesenhistaDeResultadoGraficoNaTela&
							DesenhistaDeResultadoGraficoNaTela
								::limpaBuffer();

				// Executavel:

				/**
				 * <h1>Função Principal</h1>
				 * Percorre o ResultadoGrafico desenhando
				 * coisa por coisa.
				 */
				virtual Executavel& DesenhistaDeResultadoGraficoNaTela
						::executa();
		};
	}
  }
}

#endif // !defined(AFX_DESENHISTADERESULTADOGRAFICONATELA_H__31FFC27F_D829_4D52_B0B4_ED19509F51D8__INCLUDED_)
