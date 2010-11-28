/*
 * $RCSfile: LogicaBolaExtra.h,v $
 * $Date: 2004/06/16 00:31:26 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef LOGICA_BOLA_EXTRA_BASE_H
#define LOGICA_BOLA_EXTRA_BASE_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/bingo/logica/util/Cartela.h"
using namespace biblia::jogos::bingo::logica::util;

#include "biblia/jogos/bingo/logica/LogicaCartelas.h"
#include "biblia/jogos/bingo/logica/GerenciadorDePremios.h"
using namespace biblia::jogos::bingo::logica;


namespace biblia{
	
	namespace jogos{

		namespace bingo{
		
			namespace logica{

				class LogicaBolaExtra: public Objeto{

					private:
						GerenciadorDePremios& pGerenciador;
						LogicaCartelas& pCartelas;						

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