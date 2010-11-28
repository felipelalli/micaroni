/*
 * $RCSfile: ArqLogicaAcumulado.h,v $
 * $Date: 2004/05/17 21:07:15 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef ARQ_LOGICA_ACUMULADO_H
#define ARQ_LOGICA_ACUMULADO_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;


#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
using namespace biblia::jogos::superbonus::dados;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace logica{

				namespace util{

					class ArqLogicaAcumulado: public Objeto{

						private:
							double pValor;
							double pValorMaximoAcumulado;

							Semaforo* pSemaforo;
							Arquivo ArqLogicaAcumulado::pArquivo;

							static DConfiguracao* pConf;

						public:
							ArqLogicaAcumulado::ArqLogicaAcumulado();
							ArqLogicaAcumulado::~ArqLogicaAcumulado();

							bool ArqLogicaAcumulado::carregar();
							bool ArqLogicaAcumulado::salvar();

							double ArqLogicaAcumulado::getValor();
							void   ArqLogicaAcumulado::setValor(double valor);
							double ArqLogicaAcumulado::getAndSetValor (double valor);
							void   ArqLogicaAcumulado::addValor(double valor);

							static void ArqLogicaAcumulado::defineConf (DConfiguracao* conf);
							static double ArqLogicaAcumulado::valorMaximoAcumulado ();
					};
				}
			}
		}
	}
}

#endif