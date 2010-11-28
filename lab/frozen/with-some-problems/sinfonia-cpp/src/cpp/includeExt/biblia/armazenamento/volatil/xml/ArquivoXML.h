#ifndef ARQUIVO_XML_ARMAZENAMENTO_VOLATIL_SW
#define ARQUIVO_XML_ARMAZENAMENTO_VOLATIL_SW


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/xml/NoXML.h"
using namespace biblia::armazenamento::volatil::xml;


#include <string>
using namespace std;


namespace biblia{

	namespace armazenamento{

		namespace volatil{

			namespace xml{

				class ArquivoXML:public Objeto{

					private:
						std::string pArquivo;

					protected:
						bool pCarregado;
						std::string ArquivoXML::getArquivo();

					public:
						ArquivoXML::ArquivoXML(std::string arquivo);
						virtual ArquivoXML::~ArquivoXML();

						virtual bool ArquivoXML::carregado();

						virtual NoXML* ArquivoXML::noPrincipal()=0;
				};
			}
		}
	}
}

#endif