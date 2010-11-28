/*
 * $RCSfile: ArqProbabilidades.h,v $
 * $Date: 2005/01/19 17:22:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_AGES_SPECIAL_UPGRADE_SBS_ARQ_PROBABILIDADES_H
#define AGES_SPECIAL_UPGRADE_AGES_SPECIAL_UPGRADE_SBS_ARQ_PROBABILIDADES_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/io/disco/ArquivoBasico.h"
using namespace biblia::io::disco;

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/tempo/Intervalo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Milissegundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

#ifdef WIN32
#include <io.h>
#include <windows.h>
#else
#include <unistd.h>
#include <errno.h>
#endif

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				namespace util{

					class ArqProbabilidades: public Objeto{


						public:

							static void ArqProbabilidades::salvar (double Vc,  double Vl,  double Vd,  double Vb,  double Va,
									  double PcP, double PlP, double PdP, double PbP, double PaP, double  R,
									  double PcPb,double PlPb,double PdPb,double PbPb,double Rb,
									  double Pxl, double Pxl2,double Pxls,double Xl,  double PaxD,
									  double Pxd, double Pxds,double Xd,  double PaxB,
									  double txtPc,  double txtPl, double txtPd, double txtPb, double txtPa,
									  double txtPcb, double txtPlb,double txtPdb,double txtPbb,
									  double txtPdbe,double txtPbbe);

					};
				}
			}
		}
	}
}

#endif