/*
 * $RCSfile: UltimasJogadas.h,v $
 * $Date: 2004/05/17 22:16:43 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef ULTIMAS_JOGADAS_H
#define ULTIMAS_JOGADAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/armazenamento/volatil/ListaInt.h"
#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#define MAX_JOGADAS 10

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace dados{

				class UltimasJogadas : public Objeto{

					private:

						void UltimasJogadas::salvar();
						void UltimasJogadas::carregar();

						void UltimasJogadas::concatenaListaEmString (ListaInt* lista, char* str);

						ListaString* pLstJogadas;
						Arquivo arquivo;

					public:
						UltimasJogadas::UltimasJogadas ();
						UltimasJogadas::~UltimasJogadas();

						int UltimasJogadas::qtsJogadas();
						virtual UltimasJogadas& UltimasJogadas::zera();
						void UltimasJogadas::getJogada (int qualJogada,char* jogada);

						void UltimasJogadas::addJogada(
							ListaInt* bolas,
							ListaInt* cartela1,
							ListaInt* cartela2,
							ListaInt* cartela3,
							ListaInt* cartela4,
							int creditoAtual,
							int aposta,
							int creditosGanhos,
							bool dobro);
				};
			}
		}
	}
}

#endif