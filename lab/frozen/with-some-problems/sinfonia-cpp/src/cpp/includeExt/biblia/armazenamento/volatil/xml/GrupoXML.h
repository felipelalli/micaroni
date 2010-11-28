#ifndef AGES_GRUPO_XML_H
#define AGES_GRUPO_XML_H


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;


#include "biblia/armazenamento/volatil/carcacas/Lista.h"
using namespace biblia::armazenamento::volatil::carcacas;


#include "biblia/armazenamento/volatil/xml/NoXML.h"
#include "biblia/armazenamento/volatil/xml/CampoValor.h"
#include "biblia/armazenamento/volatil/xml/GrupoNo.h"
using namespace biblia::armazenamento::volatil::xml;


#include <string>
using namespace std;



namespace biblia{

	namespace armazenamento{

		namespace volatil{

			namespace xml{

				class GrupoXML: public Objeto{

					private:
						biblia::armazenamento::volatil::carcacas::Lista<CampoValor*> pLstCampos;
						biblia::armazenamento::volatil::carcacas::Lista<GrupoNo*> pLstGrupos;

					public:
						GrupoXML::GrupoXML(NoXML* no,char* campos[] =NULL,int quantosCampos=0, char* grupos[]=NULL, int quantosGrupos=0);
						virtual GrupoXML::~GrupoXML();

						virtual CampoValor* GrupoXML::getCampo(std::string campo);
						virtual GrupoNo*    GrupoXML::getGrupo(std::string grupo);
				};
			}
		}
	}
}


#endif