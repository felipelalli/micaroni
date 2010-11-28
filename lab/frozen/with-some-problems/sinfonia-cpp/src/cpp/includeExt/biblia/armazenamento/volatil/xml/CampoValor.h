#ifndef AGES_CAMPO_VALOR_H
#define AGES_CAMPO_VALOR_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include <string>
using namespace std;


namespace biblia{

	namespace armazenamento{

		namespace volatil{

			namespace xml{

				class CampoValor: public Objeto{

					private:
						std::string pCampo;
						std::string pValor;

					public:
						CampoValor::CampoValor(std::string campo, std::string valor="__nadinha__");
						virtual CampoValor::~CampoValor();

						virtual std::string CampoValor::campo();
						virtual void   CampoValor::setCampo(std::string campo);

						virtual std::string CampoValor::valor();
						virtual void   CampoValor::setValor(std::string valor);

						virtual bool   CampoValor::semValor();


				};
			}
		}
	}
}


#endif