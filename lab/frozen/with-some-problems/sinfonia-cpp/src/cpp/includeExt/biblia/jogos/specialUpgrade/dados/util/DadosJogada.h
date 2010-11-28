/*
 * $RCSfile: DadosJogada.h,v $
 * $Date: 2005/01/19 17:21:58 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_DADOS_JOGADA_H
#define AGES_SPECIAL_UPGRADE_SBS_DADOS_JOGADA_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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