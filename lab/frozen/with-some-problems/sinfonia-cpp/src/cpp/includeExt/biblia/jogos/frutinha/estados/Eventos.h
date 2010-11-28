#ifndef EVENTOS_TROPICAL_H_SW
#define EVENTOS_TROPICAL_H_SW


#include "biblia/util/CData.h"
#include "biblia/util/VerificadorDeDesligamento.h"
using namespace biblia::util;

#include "biblia/io/disco/ArquivoAdicionavel.h"
using namespace biblia::io::disco;

#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
using namespace biblia::armazenamento::volatil::primitivos;


namespace biblia{

	namespace jogos{

		namespace frutinha{

			namespace estados{

				class Eventos: public Objeto{

					private:
						ArquivoAdicionavel pArquivo;
						VerificadorDeDesligamento pVerificadorDeDesligamento;

						std::string Eventos::pAgora();

					public:
						Eventos::Eventos();
						Eventos::~Eventos();

						Eventos& Eventos::ligouMaquina();

						Eventos& Eventos::inseriuNota (int nota);

						Eventos& Eventos::jogou (int* apostaRodilho,
												 int* premios,
												 int  apostado,
												 int  ganho);

						Eventos& Eventos::cobrou (int valor);

						enum Ids{

							ID_LIGOU_MAQUINA   =1,
							ID_DESLIGOU_MAQUINA=2,
							ID_INSERIU_NOTA    =3,
							ID_JOGOU           =4,
							ID_COBROU          =5
						};
				};
			}
		}
	}
}

#endif