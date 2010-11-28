/*
 * $RCSfile: EventosRodilho.h,v $
 * $Date: 2003/12/09 22:15:31 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef EVENTOS_RODILHO_H
#define EVENTOS_RODILHO_H

#include "biblia/armazenamento/volatil/EventoID.h"
using namespace biblia::armazenamento::volatil;

namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				namespace eventos{
					
					class EventoAtualizaRodilho: public EventoID{

						private:
							int pLinha;
							int pColuna;
							static EventoID pId;

						public:
							EventoAtualizaRodilho::EventoAtualizaRodilho(int linha=0, int coluna=0);
							EventoAtualizaRodilho::~EventoAtualizaRodilho();

							int EventoAtualizaRodilho::getLinha();
							int EventoAtualizaRodilho::getColuna();
					};

					class EventoAtualizaPremio: public EventoID{

						private:
							int pLinha;
							static EventoID pId;

						public:
							EventoAtualizaPremio::EventoAtualizaPremio(int linha=0);
							EventoAtualizaPremio::~EventoAtualizaPremio();

							int EventoAtualizaPremio::getLinha();						  
					};				
				}
			}
		}
	}
}

#endif
