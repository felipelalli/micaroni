#ifndef VERIFICADOR_DE_DISPOSITIVO_COM_LICENCA_SW
#define VERIFICADOR_DE_DISPOSITIVO_COM_LICENCA_SW


#include "biblia/io/disco/Arquivo.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/io/disco/VerificadorDeNovosDispositivos.h"
using namespace biblia::io::disco;

#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/seguranca/ControleLicenca.h"
using namespace biblia::seguranca;


namespace biblia{

	namespace seguranca{

		class ControleLicenca;

		class VerificadorDeDispositivoComLicenca : public Executavel{

			private:

				ControleLicenca& pLicenca;
				VerificadorDeNovosDispositivos pVerificador;

				bool pJaExecutouProcesso;

			public:

				VerificadorDeDispositivoComLicenca::VerificadorDeDispositivoComLicenca(ControleLicenca& licenca);
				VerificadorDeDispositivoComLicenca::~VerificadorDeDispositivoComLicenca();


				Executavel& VerificadorDeDispositivoComLicenca::executa();
		};
	}
}

#endif