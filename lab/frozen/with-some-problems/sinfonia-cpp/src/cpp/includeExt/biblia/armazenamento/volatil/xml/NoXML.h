#ifndef NO_XML_VOLATIL_H
#define NO_XML_VOLATIL_H


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include <string>
using namespace std;


namespace biblia{

	namespace armazenamento{

		namespace volatil{

			namespace xml{

				class NoXML: public Objeto{

					public:
						NoXML::NoXML(){};
						virtual NoXML::~NoXML(){};

						virtual std::string NoXML::nome()=0;
						virtual std::string NoXML::valor()=0;
						virtual bool   NoXML::possuiFilhos()=0;
						virtual NoXML* NoXML::primeiroFilho()=0;
						virtual NoXML* NoXML::proximoNo()=0;

				};
			}
		}
	}
}

#endif