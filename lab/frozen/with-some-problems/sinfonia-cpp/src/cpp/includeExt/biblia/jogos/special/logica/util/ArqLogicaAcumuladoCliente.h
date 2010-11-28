/*
 * $RCSfile: ArqLogicaAcumuladoCliente.h,v $
 * $Date: 2004/05/17 21:07:12 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef SBS_ARQ_LOGICA_ACUMULADO_CLIENTE_H
#define SBS_ARQ_LOGICA_ACUMULADO_CLIENTE_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace jogos{

		namespace special{

			namespace logica{

				namespace util{

					class ArqLogicaAcumuladoCliente: public Objeto{

						private:
							double pValor;
							Semaforo* pSemaforo;
							Arquivo ArqLogicaAcumuladoCliente::pArquivo;

						public:
							ArqLogicaAcumuladoCliente::ArqLogicaAcumuladoCliente();
							ArqLogicaAcumuladoCliente::~ArqLogicaAcumuladoCliente();

							bool ArqLogicaAcumuladoCliente::carregar();
							bool ArqLogicaAcumuladoCliente::salvar();

							double ArqLogicaAcumuladoCliente::getValor();
							void   ArqLogicaAcumuladoCliente::addValor(double valor);
							void   ArqLogicaAcumuladoCliente::subValor(double valor);

					};
				}
			}
		}
	}
}

#endif