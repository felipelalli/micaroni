/*
 * $RCSfile: LeitorNotasPlacaDelta.h,v $
 * $Date: 2004/05/17 21:10:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef CLEITORNOTASJCM_H_SW
#define CLEITORNOTASJCM_H_SW

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placaDelta;

#include "biblia/io/noteiro/LeitorNotas.h"
using namespace biblia::io::noteiro;

#include "biblia/io/noteiro/util/CRC16JCM.h"
#include "biblia/io/noteiro/util/CRC16Smiles.h"
using namespace biblia::io::noteiro::util;

namespace biblia{

	namespace io{

		namespace noteiro{

			class LeitorNotasPlacaDelta : public LeitorNotas {

				private:


				public:
					LeitorNotasPlacaDelta::LeitorNotasPlacaDelta (PlacaDelta& placaDelta);
					LeitorNotasPlacaDelta::~LeitorNotasPlacaDelta ();

					Executavel& LeitorNotasPlacaDelta::executa ();					

					void LeitorNotasJCM::ligar(const char* porta);
					void LeitorNotasJCM::desligar();
			};
		}
	}
}
#endif
