#ifndef ARQ_JOGADAS_SPECIAL
#define ARQ_JOGADAS_SPECIAL



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
  namespace special {
   namespace util {

		class ArqJogadasSpecial: public Objeto{

			private:
				std::string pNomeArquivo;
				ListaString pLstJogadas;

			public:
				ArqJogadasSpecial::ArqJogadasSpecial();
				ArqJogadasSpecial::~ArqJogadasSpecial();

				void ArqJogadasSpecial::adicionaJogada(int creditos, double pagamento);

				void ArqJogadasSpecial::carrega();
				int ArqJogadasSpecial::qtsJogadas();
				int ArqJogadasSpecial::getJogada(int qualJogada);
				double ArqJogadasSpecial::getPagamento (int qualJogada);
				void ArqJogadasSpecial::libera();

		};

   }
  }
 }
}

#endif