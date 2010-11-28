/*
 * $RCSfile: ContadorPlacaDelta.h,v $
 * $Date: 2004/04/25 22:44:00 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */
#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;


#ifndef CONTADOR_PlacaDelta_H
#define CONTADOR_PlacaDelta_H


#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;



#include "biblia/armazenamento/eterno/Contador.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#define CONTADOR_APOSTADO_Delta         1
#define CONTADOR_GANHO_Delta            2
#define CONTADOR_PAGAMENTO_MANUAL_Delta 3
#define CONTADOR_ENTRADA_Delta          4
#define CONTADOR_JOGADA_Delta           5


namespace biblia{

	namespace io{

		namespace contador{

			class ContadorPlacaDelta:	public Contador,
									    public Executavel{

				private:				

					Thread* pMinhaThread;
					bool pTerminar;
					bool pTerminou;

					PlacaDelta& pPlacaDelta;
				

				public:
					ContadorPlacaDelta::ContadorPlacaDelta(PlacaDelta& placaDelta);
					ContadorPlacaDelta::~ContadorPlacaDelta();


					Executavel& ContadorPlacaDelta::executa();
			};
		}
	}
}

#endif
