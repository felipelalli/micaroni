#ifndef ARQ_JOGADAS_TROPICAL
#define ARQ_JOGADAS_TROPICAL



#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;



namespace biblia {
 namespace jogos {
  namespace frutinha {
   namespace visual {
	namespace simulacao {

		class ArqJogadas: public Objeto{

			private:
				std::string pNomeArquivo;
				ListaString pLstJogadas;

			public:
				ArqJogadas::ArqJogadas();
				ArqJogadas::~ArqJogadas();

				void ArqJogadas::adicionaJogada(int creditos, double pagamento);

				void ArqJogadas::carrega();
				int ArqJogadas::qtsJogadas();
				int ArqJogadas::getJogada(int qualJogada);
				double ArqJogadas::getPagamento (int qualJogada);
				void ArqJogadas::libera();

		};

	}
   }
  }
 }
}

#endif