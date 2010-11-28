#ifndef EVENTOS_CARTELA_H
#define EVENTOS_CARTELA_H

#include "biblia/armazenamento/volatil/EventoID.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/bingo/logica/util/Premio.h"
#include "biblia/jogos/bingo/logica/util/PontoNaCartela.h"
using namespace biblia::jogos::bingo::logica::util;

namespace biblia{

	namespace jogos{

		namespace bingo{

			namespace logica{

				namespace util{


					class EventoMarcouCartela: public EventoID{
						
						private:
							PontoNaCartela pPontoMarcado;
							static EventoID pId;

						public:
							EventoMarcouCartela::EventoMarcouCartela (const PontoNaCartela& pontoMarcado);
							EventoMarcouCartela::EventoMarcouCartela ();
							EventoMarcouCartela::~EventoMarcouCartela (){};
							const PontoNaCartela& EventoMarcouCartela::pontoMarcado() const;
					};



					class EventoMarcouPremio: public EventoID{
						
						private:
							Premio pPremio;
							static EventoID pId;

						public:
							EventoMarcouPremio::EventoMarcouPremio (const Premio& premioMarcado);
							EventoMarcouPremio::EventoMarcouPremio ();
							EventoMarcouPremio::~EventoMarcouPremio (){};
							const Premio& EventoMarcouPremio::premioMarcado() const;
					};



					class EventoRetirouPremio: public EventoID{
						
						private:
							Premio pPremio;
							static EventoID pId;

						public:
							EventoRetirouPremio::EventoRetirouPremio (const Premio& premioRetirado);
							EventoRetirouPremio::EventoRetirouPremio ();
							EventoRetirouPremio::~EventoRetirouPremio (){};
							const Premio& EventoRetirouPremio::premioRetirado() const;
					};



					class EventoMarcouFaltaUm: public EventoID{
						
						private:
							Premio pPremio;
							static EventoID pId;

						public:
							EventoMarcouFaltaUm::EventoMarcouFaltaUm (const Premio& faltaUmMarcado);
							EventoMarcouFaltaUm::EventoMarcouFaltaUm ();
							EventoMarcouFaltaUm::~EventoMarcouFaltaUm (){};
							const Premio& EventoMarcouFaltaUm::faltaUmMarcado() const;
					};


					class EventoRetirouFaltaUm: public EventoID{
						
						private:
							Premio pPremio;
							static EventoID pId;

						public:
							EventoRetirouFaltaUm::EventoRetirouFaltaUm (const Premio& faltaUmRetirado);
							EventoRetirouFaltaUm::EventoRetirouFaltaUm ();
							EventoRetirouFaltaUm::~EventoRetirouFaltaUm (){};
							const Premio& EventoRetirouFaltaUm::faltaUmRetirado() const;
					};
				}
			}
		}
	}
}

#endif