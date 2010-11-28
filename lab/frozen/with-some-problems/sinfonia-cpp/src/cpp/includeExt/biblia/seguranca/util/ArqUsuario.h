/*
 * $RCSfile: ArqUsuario.h,v $
 * $Date: 2005/02/03 00:56:44 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#ifndef ARQ_USUARIO_H
#define ARQ_USUARIO_H

#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

#include "biblia/seguranca/ChaveSeguranca.h"
#include "biblia/seguranca/SecureMessage.h"
using namespace biblia::seguranca;

#include "biblia/seguranca/util/TipoUsuario.h"
using namespace biblia::seguranca::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include <string>
using namespace std;

namespace biblia{

	namespace seguranca{

		namespace util{

			class ArqUsuario{

				private:
					std::string pCaminhoTemporario;
					std::string pCaminhoCriptografado;

					ChaveSeguranca* pChaveSeguranca;

				public:
					ArqUsuario::ArqUsuario(ChaveSeguranca* chaveSeguranca);
					ArqUsuario::~ArqUsuario();

					bool ArqUsuario::carregar(biblia::armazenamento::volatil::Lista* lstUsuarios);
					bool ArqUsuario::salvar (biblia::armazenamento::volatil::Lista* lstUsuarios);
			};
		}
	}
}

#endif