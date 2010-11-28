/*
 * $RCSfile: DadosJogada.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef DADOS_JOGADA_H
#define DADOS_JOGADA_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace dados{

				namespace util{

					class DadosJogada: public Objeto{

						private:
							ListaInt* bolas;
							ListaInt* cartela1;
							ListaInt* cartela2;
							ListaInt* cartela3;
							ListaInt* cartela4;

							int creditos;
							int aposta;
							int creditosGanhos;
							bool dobro;

							void preencheListaFromString (ListaInt* lista, char* str);

						public:
							DadosJogada::DadosJogada (char* jogadaEmString);
							DadosJogada::~DadosJogada();

							int DadosJogada::qtsBolas();
							int DadosJogada::getBola (int bola);

							int DadosJogada::qtsNumerosCartela (int cartela);
							int DadosJogada::getNumeroCartela (int cartela, int numero);

							int DadosJogada::getCreditos();
							int DadosJogada::getAposta();
							int DadosJogada::getCreditosGanhos();
							bool DadosJogada::getEstaNoDobro();
					};
				}
			}
		}
	}
}

#endif