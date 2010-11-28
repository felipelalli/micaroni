#ifndef AGES_GRUPO_NO_H
#define AGES_GRUPO_NO_H

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

				class GrupoNo: public Objeto{

					private:
						std::string pGrupo;
						NoXML* pNo;

					public:
						GrupoNo::GrupoNo(std::string grupo, NoXML* no=NULL);
						virtual GrupoNo::~GrupoNo();

						virtual std::string GrupoNo::grupo();
						virtual void   GrupoNo::setGrupo(std::string grupo);

						virtual NoXML* GrupoNo::no();
						virtual void   GrupoNo::setNo (NoXML* no);
				};
			}
		}
	}
}


#endif