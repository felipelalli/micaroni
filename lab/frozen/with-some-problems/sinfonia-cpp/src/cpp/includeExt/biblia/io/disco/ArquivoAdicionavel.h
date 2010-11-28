#ifndef ARQUIVO_ADICIONAVEL_SW_H
#define ARQUIVO_ADICIONAVEL_SW_H


#include <string>
using namespace std;


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;



namespace biblia{

	namespace io{

		namespace disco{			

			class ArquivoAdicionavel: public Objeto{

				private:

					static int qtsAbertos;
					static Semaforo pSemaAberto;			

					std::string pCaminho;
					int    pArquivo;


				public:

					ArquivoAdicionavel::ArquivoAdicionavel (std::string caminho);
					ArquivoAdicionavel::~ArquivoAdicionavel();

					void ArquivoAdicionavel::abre();
					void ArquivoAdicionavel::fecha();

					void ArquivoAdicionavel::adiciona(std::string texto);
					void ArquivoAdicionavel::adicionaLinha(std::string texto);
			};
		};
	};
};

#endif