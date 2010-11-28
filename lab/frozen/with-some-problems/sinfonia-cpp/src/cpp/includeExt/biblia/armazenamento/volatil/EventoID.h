/*
 * $RCSfile: EventoID.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_EVENTOID_H__269554D6_CC6B_4B79_A1A0_9F7DDE26E688__INCLUDED_)
#define AFX_EVENTOID_H__269554D6_CC6B_4B79_A1A0_9F7DDE26E688__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <typeinfo>
#include "biblia/armazenamento/volatil/Evento.h"

namespace biblia {
  namespace armazenamento {
 	namespace volatil {

		class EventoID: public Evento {
			private:
				long EventoID::id;
				static long EventoID::idGeral;

			public:
				EventoID::EventoID();
				EventoID::EventoID(const EventoID&);
				virtual EventoID::~EventoID();

				// Objeto:
				virtual std::string EventoID::emString() const;

				// Evento:
				virtual bool EventoID
						::mesmo(const Evento&) const;
		};
	}
  }
}

#endif // !defined(AFX_EVENTOID_H__269554D6_CC6B_4B79_A1A0_9F7DDE26E688__INCLUDED_)
