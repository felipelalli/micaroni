#ifndef ARQ_FILA_DE_PREMIACAO_H
#define ARQ_FILA_DE_PREMIACAO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

namespace biblia{
	namespace jogos{
		namespace frutinha{
			namespace logica{
				namespace util{

					class ArqFilaDePremiacao: public Objeto{

						private:

						public:

							ArqFilaDePremiacao::ArqFilaDePremiacao();
							ArqFilaDePremiacao::~ArqFilaDePremiacao();

							void ArqFilaDePremiacao::carregar (int* vetPremios,int* indice, std::string qualFila, int qtsPosicoes);
							void ArqFilaDePremiacao::salvar (int* vetPremios,int* indice, std::string qualFila, int qtsPosicoes);

							void ArqFilaDePremiacao::salvarIndice (int* indice, std::string qualFila);



					};

				}
			}
		}
	}
}

#endif