/*
 * $RCSfile: LogicaBolaExtra.h,v $
 * $Date: 2005/01/19 17:22:13 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_LOGICA_BOLA_EXTRA_BASE_H
#define AGES_SPECIAL_UPGRADE_LOGICA_BOLA_EXTRA_BASE_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/specialUpgrade/logica/util/Cartela.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/LogicaCartelas.h"
#include "biblia/jogos/specialUpgrade/logica/GerenciadorDePremios.h"
using namespace biblia::jogos::specialUpgrade::logica;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				class LogicaBolaExtra: public Objeto{

					private:
						GerenciadorDePremios& pGerenciador;
						LogicaCartelas& pCartelas;

						int LogicaBolaExtra::aredonda (double valor);

					public:
						LogicaBolaExtra::LogicaBolaExtra (GerenciadorDePremios& gerenciador, LogicaCartelas& cartelas);
						LogicaBolaExtra::~LogicaBolaExtra();

						bool LogicaBolaExtra::podeBolaExtra();
						int LogicaBolaExtra::valorBolaExtra();

						int LogicaBolaExtra::sValorBolaExtra(biblia::armazenamento::volatil::Lista& lstPremios,ListaInt& lstCartelas);
				};
			}
		}
	}
}

#endif