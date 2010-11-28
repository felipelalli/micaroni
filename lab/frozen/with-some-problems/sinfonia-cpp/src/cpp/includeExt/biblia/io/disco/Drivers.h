#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;


namespace biblia{

	namespace io{

		namespace disco{

			class Drivers: public Objeto{

				private:
					ListaString pLstDrivers;
					void Drivers::pGetDrivers();
					AGES_INT_64 Drivers::pEspacoDisponivel (char* driver);

				public:
					Drivers::Drivers();
					Drivers::~Drivers();

					void Drivers::atualizar();

					int     Drivers::qtsDrivers ();
					char*   Drivers::getDriver (int qual);
					AGES_INT_64 Drivers::espacoDisponivelEmBytes (char* driver);
					AGES_INT_64 Drivers::espacoDisponivelEmKs    (char* driver);
					AGES_INT_64 Drivers::espacoDisponivelEmMegas (char* driver);

			};
		}
	}
}
