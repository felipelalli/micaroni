#ifndef INTERFACE_SERVIDOR_SW
#define INTERFACE_SERVIDOR_SW

#include "biblia/io/rede/InterfaceRede.h"
using namespace biblia::io::rede;

namespace biblia{

	namespace io{

		namespace rede{

			class InterfaceServidor{
				
				private:
					InterfaceRede* pInterfaceRede;

				public:

					InterfaceServidor::InterfaceServidor();
					virtual InterfaceServidor::~InterfaceServidor();										
					
					void InterfaceServidor::setInterfaceRede(InterfaceRede* interfaceRede);					

					InterfaceRede* InterfaceServidor::getInterfaceRede();

					virtual bool InterfaceServidor::processarRequisicao (char* buffer)=0;					
			};
		}
	}
}

#endif