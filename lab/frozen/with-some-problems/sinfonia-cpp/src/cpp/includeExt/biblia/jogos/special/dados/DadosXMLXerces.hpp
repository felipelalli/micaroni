/*
 * $RCSfile: DadosXMLXerces.hpp,v $
 * $Date: 2005/01/20 21:28:53 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef SBS_DADOS_XML_XERCES_SW_H
#define SBS_DADOS_XML_XERCES_SW_H

//#ifdef WIN32
//#define _DLL
//#endif

#include "biblia/jogos/special/dados/Dados.h"
#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include <stdlib.h>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/parsers/DOMParser.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>

using namespace biblia::armazenamento::volatil;
using namespace biblia::fluxo;
using namespace biblia::io::disco;

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace dados {

		class DadosXMLXerces:public Dados {

			private:
				DOM_Document	DadosXMLXerces::domDocument;
				char			DadosXMLXerces::pArquivoBasico[300];
				static long		DadosXMLXerces::pVezes;

				void DadosXMLXerces::limpaInstancia();
				void DadosXMLXerces::escreveNode(FILE * file, DOM_Node no,int level);

			protected:
				static Semaforo* DadosXMLXerces::semaforo;

				int DadosXMLXerces::buscaEmNodeList(const DOM_NodeList lista, DOMString procurada);
				void DadosXMLXerces::entendeRequisicao(const char * _requisicao, biblia::armazenamento::volatil::Lista * elementos);

				// apaga elementos que estejam no caminho especificado
				virtual DadosXMLXerces& DadosXMLXerces::apagar(const char* caminho);

				// salva tudo
				virtual DadosXMLXerces& DadosXMLXerces::salvar();

				static const char* DadosXMLXerces::transcode(const DOMString& estd::stringue);

			public:
				DadosXMLXerces::DadosXMLXerces(char * _fileName = NULL);
				DadosXMLXerces::~DadosXMLXerces();
				virtual Dados& DadosXMLXerces::abrirArquivo(const char* arquivo);

				// retorna false se nao existe o caminho ou ele nao possui texto
				virtual bool DadosXMLXerces::ler(const char* caminho, char* resutadobusca);
				virtual bool DadosXMLXerces::ler(const char* caminho, biblia::armazenamento::volatil::Lista* resultadobusca);

				// cria caminho se nao existir e substitui os valores que la se encontram
				// diferente das funcoes de adicionar, essas funcoes salvam automaticamente:
				virtual Dados& DadosXMLXerces::escrever(const char* caminho, char* valor);
				virtual Dados& DadosXMLXerces::escrever(const char* caminho, biblia::armazenamento::volatil::Lista* valores);

				/**//**///

				// adiciona novos elementos no XML, mesmo que exista um igual ele nao sobrescreve
				virtual DadosXMLXerces& DadosXMLXerces::adicionar(const char* caminho, char* valor);
				virtual DadosXMLXerces& DadosXMLXerces::adicionar(const char* caminho, biblia::armazenamento::volatil::Lista* valores);
		};
	  }
	}
  }
}

#endif
