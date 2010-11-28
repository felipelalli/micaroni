/*
 * $RCSfile: InterfaceCliente.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTERFACE_CLIENTE_SW
#define INTERFACE_CLIENTE_SW


#include "biblia/io/rede/ComunicadorRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace io{

		namespace rede{

			class InterfaceCliente{

				private:
					ComunicadorRede* pRedeCliente;

				protected:
					ComunicadorRede* InterfaceCliente::getRede();

				public:

					InterfaceCliente::InterfaceCliente(ComunicadorRede* redeCliente);
					virtual InterfaceCliente::~InterfaceCliente();
			};
		}
	}
}

#endif