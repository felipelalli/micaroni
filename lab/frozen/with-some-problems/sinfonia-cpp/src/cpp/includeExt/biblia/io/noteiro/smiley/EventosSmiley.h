/*
 * $RCSfile: EventosSmiley.h,v $
 * $Date: 2003/10/28 23:45:27 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef EVENTOS_SMILEY_H
#define EVENTOS_SMILEY_H

#include "biblia/armazenamento/volatil/EventoID.h"
using namespace biblia::armazenamento::volatil;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace smiley{

					class EventoReset: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							EventoReset::EventoReset ();							
							EventoReset::~EventoReset (){};							
					};

					class EventoRead: public EventoID{
						
						private:							
							static EventoID pId;
							int pCanalLido;

						public:
							EventoRead::EventoRead (int canalLido);							
							EventoRead::~EventoRead (){};
							
							int EventoRead::canalLido();
					};

					class EventoCredit: public EventoID{
						
						private:							
							static EventoID pId;
							int pCanalLido;

						public:
							EventoCredit::EventoCredit (int canalLido);							
							EventoCredit::~EventoCredit (){};
							
							int EventoCredit::canalLido();
					};

					class EventoRejecting: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							EventoRejecting::EventoRejecting ();							
							EventoRejecting::~EventoRejecting (){};							
					};

					class EventoRejected: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							EventoRejected::EventoRejected ();							
							EventoRejected::~EventoRejected (){};							
					};

					class EventoStacking: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							EventoStacking::EventoStacking ();							
							EventoStacking::~EventoStacking (){};							
					};
					
					class EventoStacked: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							EventoStacked::EventoStacked ();							
							EventoStacked::~EventoStacked (){};							
					};

					class EventoSafeJam: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							EventoSafeJam::EventoSafeJam ();							
							EventoSafeJam::~EventoSafeJam (){};							
					};

					class EventoUnsafeJam: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							EventoUnsafeJam::EventoUnsafeJam ();							
							EventoUnsafeJam::~EventoUnsafeJam (){};							
					};

					class EventoDisabled: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							EventoDisabled::EventoDisabled ();							
							EventoDisabled::~EventoDisabled (){};							
					};

					class EventoFraudAttemp: public EventoID{
					
						private:							
							static EventoID pId;
							int pQualCanal;

						public:
							EventoFraudAttemp::EventoFraudAttemp (int qualCanal);
							EventoFraudAttemp::~EventoFraudAttemp (){};
							
							int EventoFraudAttemp::qualCanal();
					};

					class EventoStackerFull: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							EventoStackerFull::EventoStackerFull ();							
							EventoStackerFull::~EventoStackerFull (){};							
					};
			}
		}
	}
}

#endif