#ifndef ARQUIVO_XML_XERCES_MAIS_SW
#define ARQUIVO_XML_XERCES_MAIS_SW


#include <xercesc/parsers/XercesDOMParser.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/sax/HandlerBase.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/util/PlatformUtils.hpp>

#if defined(XERCES_NEW_IOSTREAMS)
#include <iostream>
#else
#include <iostream.h>
#endif


XERCES_CPP_NAMESPACE_USE


#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/armazenamento/volatil/xml/ArquivoXML.h"
using namespace biblia::armazenamento::volatil::xml;

#include "biblia/armazenamento/volatil/xml/NoXML.h"
using namespace biblia::armazenamento::volatil::xml;

#include "biblia/mais/xerces/NoXMLXerces.h"
using namespace biblia::mais::xerces;


namespace biblia{

	namespace mais{

		namespace xerces{

			class ArquivoXMLXerces: public ArquivoXML{

				private:
					bool pIniciado;
					bool pCarregado;

					xercesc_2_6::DOMDocument*     pDocumento;
					XercesDOMParser* parser;
					ErrorHandler*    errHandler;

					bool ArquivoXMLXerces::pCarregaArquivo();

					char* ArquivoXMLXerces::pNomeTipoNo (short tipoNo);

				public:
					ArquivoXMLXerces::ArquivoXMLXerces(std::string arquivo);
					virtual ArquivoXMLXerces::~ArquivoXMLXerces();

					virtual NoXML* ArquivoXMLXerces::noPrincipal();

					void ArquivoXMLXerces::escreveXML(NoXML* no, std::string nivel = "");
			};
		}
	}
}

#endif