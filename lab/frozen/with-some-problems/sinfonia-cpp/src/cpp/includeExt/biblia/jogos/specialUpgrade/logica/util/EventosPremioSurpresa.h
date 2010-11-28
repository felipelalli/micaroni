#ifndef AGES_SPECIAL_UPGRADE_EVENTOS_PREMIO_SURPRESA_H
#define AGES_SPECIAL_UPGRADE_EVENTOS_PREMIO_SURPRESA_H

#include "biblia/armazenamento/volatil/EventoID.h"
using namespace biblia::armazenamento::volatil;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{


					class EventoLancouPremio: public EventoID{

						private:							
							static EventoID pId;

						public:
							EventoLancouPremio::EventoLancouPremio();
							EventoLancouPremio::~EventoLancouPremio (){};							
					};



					class EventoGanhouPremio: public EventoID{

						private:							
							static EventoID pId;

						public:							
							EventoGanhouPremio::EventoGanhouPremio ();
							EventoGanhouPremio::~EventoGanhouPremio (){};							
					};



					class EventoNaoGanhouPremio: public EventoID{

						private:							
							static EventoID pId;

						public:							
							EventoNaoGanhouPremio::EventoNaoGanhouPremio ();
							EventoNaoGanhouPremio::~EventoNaoGanhouPremio (){};							
					};
				}
			}
		}
	}
}

#endif