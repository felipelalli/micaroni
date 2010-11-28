#ifndef NO_XML_XERCES_H
#define NO_XML_XERCES_H

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

#include "biblia/armazenamento/volatil/xml/NoXML.h"
using namespace biblia::armazenamento::volatil::xml;


namespace biblia{

	namespace mais{

		namespace xerces{

			class NoXMLXerces: public NoXML{

				private:
					DOMNode* pNode;

				public:
					NoXMLXerces::NoXMLXerces (DOMNode* node);
					virtual NoXMLXerces::~NoXMLXerces ();

					virtual std::string NoXMLXerces::nome();
					virtual std::string NoXMLXerces::valor();
					virtual bool   NoXMLXerces::possuiFilhos();
					virtual NoXML* NoXMLXerces::primeiroFilho();
					virtual NoXML* NoXMLXerces::proximoNo();
			};
		}
	}
}

#endif