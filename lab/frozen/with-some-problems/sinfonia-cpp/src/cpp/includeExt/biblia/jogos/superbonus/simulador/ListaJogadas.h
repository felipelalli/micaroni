/*
 * $RCSfile: ListaJogadas.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef LISTA_JOGADAS_H
#define LISTA_JOGADAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/superbonus/simulador/DadosJogadas.h"
using namespace biblia::jogos::superbonus::simulador;

namespace biblia{

	namespace jogos{

		namespace superbonus{

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