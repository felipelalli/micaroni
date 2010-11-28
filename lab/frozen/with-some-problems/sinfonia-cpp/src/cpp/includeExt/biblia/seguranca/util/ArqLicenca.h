/*
 * $RCSfile: ArqLicenca.h,v $
 * $Date: 2004/05/17 21:04:10 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef ARQ_LICENCA_H
#define ARQ_LICENCA_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/seguranca/util/Licenca.h"
using namespace biblia::seguranca::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace seguranca{

		namespace util{

			class ArqLicenca: public Objeto{

				private:
					Arquivo arquivo;
					ChaveSeguranca* pChave;
					Licenca* pLicenca;

					bool pLicencaCadastrada;

					bool ArqLicenca::pCarregar();

				public:

					ArqLicenca::ArqLicenca(ChaveSeguranca* chave);
					ArqLicenca::~ArqLicenca();

					bool ArqLicenca::salvar();

					bool ArqLicenca::licencaCadastrada();

					Licenca* ArqLicenca::getLicenca();
			};
		}
	}
}

#endif