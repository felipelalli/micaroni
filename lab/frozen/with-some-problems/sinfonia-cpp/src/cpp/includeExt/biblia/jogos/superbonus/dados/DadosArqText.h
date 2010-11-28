/*
 * $RCSfile: DadosArqText.h,v $
 * $Date: 2005/01/20 21:28:58 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef DADOS_ARQ_TEXT_SW
#define DADOS_ARQ_TEXT_SW

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <map>
#include <string>
#include "biblia/jogos/superbonus/dados/Dados.h"
#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/util/StrToken.h"
#include "biblia/util/Lixeira.h"
#include "biblia/io/disco/Arquivo.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::fluxo;
using namespace biblia::io::disco;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class DadosArqText : public Dados {
			private:
				class Tag {
					private:
						char * pCaminho;
						biblia::armazenamento::volatil::Lista* pValores;
					public:
						Tag::Tag(const char* caminho);
						Tag::~Tag();

						void Tag::criaInstancia(const char* valor);
						void Tag::excluiInstancia(const int& qualInstancia);
						void Tag::excluiTodasAsInstancias();

						const char* valor(const int& qualInstancia) const;
						void Tag::alteraValor(const int& qualInstancia, const char* valor);

						int Tag::quantasInstancias() const;
						const char* Tag::caminho() const;
				};

//				ArquivoBasico  pArquivoBasico;
				static map<std::string, Arquivo*> pArquivos;
				static int pQuantasInstancias;
				Lixeira lixo;

				char pNomeArquivoBasico[500];

				Semaforo* semaforo;

				biblia::armazenamento::volatil::Lista pTags;

				bool achouTag(const char* caminho, int* onde);
				int DadosArqText::adicionaTag(const char* caminho);

				void liberaLista();
				void DadosArqText::salvar();

			public:
				DadosArqText::DadosArqText(const char* nomeArquivoBasico = NULL);
				DadosArqText::~DadosArqText();

				virtual Dados& DadosArqText::abrirArquivo(const char* nomeArquivoBasico);
				virtual Dados& DadosArqText::trunca();

				virtual bool DadosArqText::ler(const char* caminho, char* resultado);
				virtual bool DadosArqText::ler(const char* caminho, biblia::armazenamento::volatil::Lista* resultado);

				virtual Dados& DadosArqText::escrever(const char* caminho, char* valor);
				virtual Dados& DadosArqText::escrever(const char* caminho, biblia::armazenamento::volatil::Lista* valores);
		};
	  }
	}
  }
}

#endif
