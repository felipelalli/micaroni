/*
 * $RCSfile: ComandosSmiley.h,v $
 * $Date: 2003/10/28 23:45:27 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef COMANDOS_SMILEY_H
#define COMANDOS_SMILEY_H

#include "biblia/armazenamento/volatil/EventoID.h"
using namespace biblia::armazenamento::volatil;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace smiley{

					class ComandoReset: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							ComandoReset::ComandoReset ();							
							ComandoReset::~ComandoReset (){};							
					};

					class ComandoHostProtocolVersion: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							ComandoHostProtocolVersion::ComandoHostProtocolVersion ();							
							ComandoHostProtocolVersion::~ComandoHostProtocolVersion (){};														
					};

					class ComandoPoll: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							ComandoPoll::ComandoPoll ();							
							ComandoPoll::~ComandoPoll (){};							
					};

					class ComandoGetSerialNumber: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							ComandoGetSerialNumber::ComandoGetSerialNumber ();							
							ComandoGetSerialNumber::~ComandoGetSerialNumber (){};							
					};

					class ComandoSync: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							ComandoSync::ComandoSync ();							
							ComandoSync::~ComandoSync (){};							
					};

					class ComandoDisable: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							ComandoDisable::ComandoDisable ();							
							ComandoDisable::~ComandoDisable (){};							
					};
					
					class ComandoEnable: public EventoID{
						
						private:							
							static EventoID pId;

						public:
							ComandoEnable::ComandoEnable ();							
							ComandoEnable::~ComandoEnable (){};							
					};

					class ComandoSetInhibits: public EventoID{
					
						private:							
							static EventoID pId;
							int pNotasHabilitadas;

						public:
							ComandoSetInhibits::ComandoSetInhibits (int notasHabilitadas);							
							ComandoSetInhibits::~ComandoSetInhibits (){};	
							
							int ComandoSetInhibits::notasHabilitadas(){
								return this->pNotasHabilitadas;
							}
					};

					class ComandoDisplayOn: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoDisplayOn::ComandoDisplayOn ();							
							ComandoDisplayOn::~ComandoDisplayOn (){};							
					};

					class ComandoDisplayOff: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoDisplayOff::ComandoDisplayOff ();							
							ComandoDisplayOff::~ComandoDisplayOff (){};							
					};

					class ComandoSetUpRequest: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoSetUpRequest::ComandoSetUpRequest ();
							ComandoSetUpRequest::~ComandoSetUpRequest (){};							
					};

					class ComandoReject: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoReject::ComandoReject ();							
							ComandoReject::~ComandoReject (){};							
					};
					
					class ComandoUnitData: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoUnitData::ComandoUnitData ();							
							ComandoUnitData::~ComandoUnitData (){};							
					};
					
					class ComandoChannelValueData: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoChannelValueData::ComandoChannelValueData ();							
							ComandoChannelValueData::~ComandoChannelValueData (){};							
					};
					
					class ComandoChannelSecurityData: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoChannelSecurityData::ComandoChannelSecurityData ();							
							ComandoChannelSecurityData::~ComandoChannelSecurityData (){};							
					};
					
					class ComandoChannelReTeachData: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoChannelReTeachData::ComandoChannelReTeachData ();							
							ComandoChannelReTeachData::~ComandoChannelReTeachData (){};							
					};
					
					class ComandoLastRejectCode: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoLastRejectCode::ComandoLastRejectCode ();							
							ComandoLastRejectCode::~ComandoLastRejectCode (){};							
					};

					
					class ComandoHold: public EventoID{
					
						private:							
							static EventoID pId;

						public:
							ComandoHold::ComandoHold ();							
							ComandoHold::~ComandoHold (){};							
					};
			}
		}
	}
}

#endif