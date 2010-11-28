/*
 * $RCSfile: ListaJogadas.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_LISTA_JOGADAS_H
#define SBS_LISTA_JOGADAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/special/simulador/DadosJogadas.h"
using namespace biblia::jogos::special::simulador;

namespace biblia{

	namespace jogos{

		namespace special{

			namespace simulador{

				class ListaJogadas: public Objeto{

					private:

						Lista* pListaJogadas;

						int pJogadaAtual;

					public:
						ListaJogadas::ListaJogadas();
						ListaJogadas::~ListaJogadas();

						void ListaJogadas::adicionarJogada (DadosJogadas* jogada);
						DadosJogadas* ListaJogadas::getJogada (int qualJogada);
						int ListaJogadas::qtsJogadas();

						bool ListaJogadas::existeNovaJogada();
						DadosJogadas* ListaJogadas::lerNovaJogada();

						void ListaJogadas::limpar();
				};
			}
		}
	}
}

#endif