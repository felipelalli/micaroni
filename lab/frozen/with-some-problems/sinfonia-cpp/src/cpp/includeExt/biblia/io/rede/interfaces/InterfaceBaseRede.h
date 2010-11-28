/*
 * $RCSfile: InterfaceBaseRede.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef INTERFACE_BASE_REDE_H
#define INTERFACE_BASE_REDE_H


#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace io{

		namespace rede{

			namespace interfaces{

				class InterfaceBaseRede: public InterfaceRede{

					public:

						InterfaceBaseRede::InterfaceBaseRede();
						virtual InterfaceBaseRede::~InterfaceBaseRede();

						enum Protocolo{
							REDE_ENCERRAR=0x01,
							REDE_STATUS=0x02
						};
				};
			}
		}
	}
}

#endif