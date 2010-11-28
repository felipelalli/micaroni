/*
 * $RCSfile: CarregadorWizard.h,v $
 * $Date: 2005/03/21 15:10:12 $
 * $Revision: 1.12 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AFX_CARREGADORWIZARD_H__110EA536_B2C0_42A2_8EDF_F3531F17000D__INCLUDED_)
#define AFX_CARREGADORWIZARD_H__110EA536_B2C0_42A2_8EDF_F3531F17000D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <deque>
#include <string>
#include "biblia/util/Wizard.h"
#include "biblia/util/StrToken.h"
#include "biblia/fluxo/ExecutaveisEmSerie.h"
#include "biblia/io/disco/Arquivo.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/io/disco/DiscoExcecao.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/dinamica/ResultadoGrafico.h"
#include "biblia/visual/dinamica/CarregadorDeComponentes.h"

#include "biblia/tempo/CronometroSistema.h"
using namespace biblia::tempo;

using namespace std;
using namespace biblia::util;
using namespace biblia::fluxo;
using namespace biblia::visual;
using namespace biblia::io::disco;

namespace biblia {
  namespace visual {
    namespace dinamica {

		/**
		 * Modifica um {@link
		 * biblia::visual::dinamica::CarregadorDeComponentes}
		 * e um {@link biblia::visual::dinamica::ResultadoGrafico}
		 * a partir de um arquivo texto no seguinte formato:
		 *
		 * <pre>
		 * z x-y nome.sem.espaco endereco/fisico.bmp endereco/fisico.txt
		 * .
		 * .
		 * .
		 * </pre>
		 *
		 * <p>Onde <b>z</b> pode ser <b>a</b> para anima��o,
		 * <b>i</b> para imagem, <b>f</b> para fonte,
		 * <b>c</b> para clone de imagem, <b>k</b> para
		 * clone de anima��o e <b>s</b> para anima��o
		 * separada.
		 *
		 * <p><b>x</b> e <b>y</b> representa sua posi��o inicial
		 * e <b>nome.sem.espaco</b> � uma chave �nica para
		 * acesso ao componente.
		 *
		 * <p><b>endereco/fisico.bmp</b> � o endere�o f�sico
		 * do arquivo no disco. <b>endereco/fisico.txt</b> representa
		 * o endere�o f�sico do arquivo de �reas no caso de ser
		 * anima��o ou fonte. Esse arquivo de �reas deve estar no
		 * formato especificado em {@link
		 * biblia::visual::animacao::util::ArquivoBasicoDeAreas}
		 * para anima��es e veja {@link
		 * biblia::visual::fonte::util::ArquivoBasicoDeAreasFonte} para
		 * as fontes.
		 */
		class CarregadorWizard: public Wizard, public Objeto {
			private:
				CarregadorDeComponentes& CarregadorWizard::cc;
				ResultadoGrafico& CarregadorWizard::rg;
				ExecutaveisEmSerie& CarregadorWizard::pAnimacoes;

				std::string CarregadorWizard::pNomeArquivoBasico;
				ArquivoBasico CarregadorWizard::pArquivoBasico;

				AGES_INT_64 pTamanhoTotal;
				AGES_INT_64 pTamanhoCarregado;

				int pQtsImagens;
				int pQtsAnimacoesSeparadas;
				int pQtsAnimacoes;
				int pQtsFontes;
				int pQtsTextos;
				int pQtsClonesImagem;
				int pQtsClonesAnimacao;

				int pQtsImagensTotal;
				int pQtsAnimacoesSeparadasTotal;
				int pQtsAnimacoesTotal;
				int pQtsFontesTotal;
				int pQtsTextosTotal;
				int pQtsClonesImagemTotal;
				int pQtsClonesAnimacaoTotal;

				CronometroSistema* pCronImagens;
				CronometroSistema* pCronAnimacoesSeparadas;
				CronometroSistema* pCronAnimacoes;
				CronometroSistema* pCronFontes;
				CronometroSistema* pCronTextos;
				CronometroSistema* pCronClonesImagem;
				CronometroSistema* pCronClonesAnimacao;

				double pPercentualCarregado;

			public:
				static const char CarregadorWizard::COMENTARIO;
				static const char CarregadorWizard::IMAGEM;
				static const char CarregadorWizard::ANIMACAO;
				static const char CarregadorWizard::ANIMACAO_SEPARADA;
				static const char CarregadorWizard::FONTE;
				static const char CarregadorWizard::TEXTO;
				static const char CarregadorWizard::CLONE_IMAGEM;
				static const char CarregadorWizard::CLONE_ANIMACAO;
				static const char CarregadorWizard::DIRETORIO_RAIZ;

				/**
				 * Passe um execut�vel em s�rie
				 * vazio para que esta classe o preencha
				 * com as anima��es. Este ExecutavelEmSerie
				 * ser� util para executar as anima��es de
				 * uma s� vez.
				 */
				CarregadorWizard::CarregadorWizard(
						CarregadorDeComponentes&,
						ResultadoGrafico&,
						ExecutaveisEmSerie& animacoes,
						const std::string& arquivoDeAreas);

				virtual CarregadorWizard::~CarregadorWizard();

				// Wizard:
				/**
				 * Retorna o endere�o do CarregadorDeComponentes
				 * passado como par�metro no construtor.
				 * <p>
				 * <i>Esta fun��o est� 'in�til' neste contexto j�
				 * que os objetos passados no par�metro do construtor
				 * j� s�o modificados; portanto n�o a utilize.</i>
				 */
				virtual Objeto* CarregadorWizard::resultado() const;

				// Executavel:

				/**
				 * L� o arquivo carregando os componentes
				 * e adicionando no ResultadoGrafico.
				 */
				virtual Executavel& CarregadorWizard::executa();

				int CarregadorWizard::tamanhoTotal(){
					return (int) this->pTamanhoTotal;
				}

				int CarregadorWizard::tamanhoCarregado(){
					return (int) this->cc.fabrica().tamanhoCarregado();
				}

				int CarregadorWizard::qtsImagens(){ 
					return this->pQtsImagens;
				}

				int CarregadorWizard::qtsAnimacoesSeparadas (){ 
					return this->pQtsAnimacoesSeparadas;
				}

				int CarregadorWizard::qtsAnimacoes() { 
					return this->pQtsAnimacoes;
				}

				int CarregadorWizard::qtsFontes (){ 
					return this->pQtsFontes;
				}

				int CarregadorWizard::qtsTextos() { 
					return this->pQtsTextos;
				}

				int CarregadorWizard::qtsClonesImagem() {
					return this->pQtsClonesImagem;
				}

				int CarregadorWizard::qtsClonesAnimacao() { 
					return this->pQtsClonesAnimacao;
				}

				double CarregadorWizard::tempoImagens(){ 
					return (double)this->pCronImagens->intervalo().emMilionesimosDeSegundo().emLong()/(double)1000000;
				}

				double CarregadorWizard::tempoAnimacoesSeparadas (){ 
					return (double)this->pCronAnimacoesSeparadas->intervalo().emMilionesimosDeSegundo().emLong()/(double)1000000;
				}

				double CarregadorWizard::tempoAnimacoes() { 
					return (double)this->pCronAnimacoes->intervalo().emMilionesimosDeSegundo().emLong()/(double)1000000;
				}

				double CarregadorWizard::tempoFontes (){ 
					return (double)this->pCronFontes->intervalo().emMilionesimosDeSegundo().emLong()/(double)1000000;
				}

				double CarregadorWizard::tempoTextos() { 
					return (double)this->pCronTextos->intervalo().emMilionesimosDeSegundo().emLong()/(double)1000000;
				}

				double CarregadorWizard::tempoClonesImagem() {
					 return (double)this->pCronClonesImagem->intervalo().emMilionesimosDeSegundo().emLong()/(double)1000000;
				}

				double CarregadorWizard::tempoClonesAnimacao() { 
					 return (double)this->pCronClonesAnimacao->intervalo().emMilionesimosDeSegundo().emLong()/(double)1000000;
				}

				void CarregadorWizard::atualizaPercentualDeCarregamento();


		};
	}
  }
}

#endif // !defined(AFX_CARREGADORWIZARD_H__110EA536_B2C0_42A2_8EDF_F3531F17000D__INCLUDED_)
