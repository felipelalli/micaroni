/*
 * $RCSfile: ContadorPlacaLoddy.h,v $
 * $Date: 2003/11/25 15:46:54 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef CONTADOR_PlacaLoddy_H
#define CONTADOR_PlacaLoddy_H


#include "biblia/io/placaloddy/PlacaLoddy.h"
using namespace biblia::io::placaloddy;



#include "biblia/armazenamento/eterno/Contador.h"
using namespace biblia::armazenamento::eterno;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#define CONTADOR_APOSTADO_LODDY         1
#define CONTADOR_GANHO_LODDY            2
#define CONTADOR_PAGAMENTO_MANUAL_LODDY 3
#define CONTADOR_ENTRADA_LODDY          4
#define CONTADOR_JOGADA_LODDY           5


namespace biblia{

	namespace io{

		namespace contador{

			class ContadorPlacaLoddy:	public Contador,
									    public Executavel{

				private:				

					Thread* pMinhaThread;
					bool pTerminar;
					bool pTerminou;

					PlacaLoddy* pPlacaLoddy;
				

				public:
					ContadorPlacaLoddy::ContadorPlacaLoddy(PlacaLoddy* placaLoddy);
					ContadorPlacaLoddy::~ContadorPlacaLoddy();


					Executavel& ContadorPlacaLoddy::executa();
			};
		}
	}
}

#endif
