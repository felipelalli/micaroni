#ifndef VERIFICADOR_DE_NOVOS_DISPOSITIVOS_SW_H
#define VERIFICADOR_DE_NOVOS_DISPOSITIVOS_SW_H


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/io/disco/Drivers.h"
using namespace biblia::io::disco;


namespace biblia{

	namespace io{

		namespace disco{

			class VerificadorDeNovosDispositivos : public Objeto{

				private:

					Drivers pDrivers;

					ListaString pLstDispositivosIniciais;
					ListaString pLstNovosDispositivos;
					

				public:

					VerificadorDeNovosDispositivos::VerificadorDeNovosDispositivos();
					VerificadorDeNovosDispositivos::~VerificadorDeNovosDispositivos();
					
					bool VerificadorDeNovosDispositivos::existeNovoDispositivo();

					int VerificadorDeNovosDispositivos::qtsNovosDispositivos();
					char* VerificadorDeNovosDispositivos::getCaminhoDispositivo(int qual);				
			};
		}
	}
}

#endif