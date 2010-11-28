/*
 * $RCSfile: ArqLeitorNotas.h,v $
 * $Date: 2004/05/17 21:05:00 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef ARQ_LEITOR_NOTAS_H
#define ARQ_LEITOR_NOTAS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace io{

		namespace noteiro{

			namespace util{

				class ArqLeitorNotas: public Objeto{
					private:
						ChaveSeguranca* pChaveSeguranca;
						Arquivo ArqLeitorNotas::arquivo;

					public:
						ArqLeitorNotas::ArqLeitorNotas(ChaveSeguranca* chaveSeguranca);
						ArqLeitorNotas::~ArqLeitorNotas();

						bool ArqLeitorNotas::carregar(biblia::armazenamento::volatil::Lista* lstNotas);
						bool ArqLeitorNotas::salvar (biblia::armazenamento::volatil::Lista* lstNotas);
				};
			}
		}
	}
}

#endif