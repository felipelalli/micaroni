/*
 * $RCSfile: Dados.h,v $
 * $Date: 2004/07/13 21:13:32 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef WIN32
#include <errno.h>
#endif

#ifdef CABECALHO_XML_SW
#undef CABECALHO_XML_SW
#endif
#define CABECALHO_XML_SW "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"

#include "biblia/basico/Objeto.h"
#include "biblia/armazenamento/volatil/Lista.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

#ifndef DADOS_SW_H
#define DADOS_SW_H

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class Dados: public Objeto {

			protected:
				Dados::Dados();

			public:
				virtual Dados::~Dados();

				/*
				 * Abre os arquivos para leitura e para escrita.
				 * Na verdade, apenas os marca para usa-los quando
				 * necessario.
				 *
				 * Deve criar se o arquivo nao existir.
				 */
				virtual Dados& Dados::abrirArquivo(const char* arquivo) = 0;
				virtual Dados& Dados::trunca() { return *this; }

				/*
				 * Le de um certo caminho especificado por:
				 * TagPai->Tag->ultimaTag
				 *
				 * Retorna true se o caminho existe e falso caso contrario.
				 */
				virtual bool Dados::ler(const char* caminho, char* buffer) = 0;
				virtual bool Dados::ler(const char* caminho, biblia::armazenamento::volatil::Lista*) = 0;

				/*
				 * Sobrescreve uma lista em um certo caminho definido por:
				 * TagPai->Tag->ultimaTag
				 */
				virtual Dados& Dados::escrever(const char* caminho, char* oQue) = 0;
				virtual Dados& Dados::escrever(const char* caminho, biblia::armazenamento::volatil::Lista*) = 0;
		};
	  }
	}
  }
}

#endif
