/*
 * $RCSfile: DEstatisticaEmRede.h,v $
 * $Date: 2005/01/19 17:21:56 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_DESTATISTICA_EM_REDE_H
#define AGES_SPECIAL_UPGRADE_SBS_DESTATISTICA_EM_REDE_H

#include "biblia/jogos/specialUpgrade/dados/DadosEstatisticaEmRede.h"
#include "biblia/jogos/specialUpgrade/dados/Estatistica.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace dados{

				class DEstatisticaEmRede : public Estatistica{

					private:

						DadosEstatisticaEmRede* pDadosRede;

					public:

						DEstatisticaEmRede::DEstatisticaEmRede (GerenciadorRede* gerenciadorRede);
						DEstatisticaEmRede::~DEstatisticaEmRede();

						virtual Estatistica& DEstatisticaEmRede::abreParcialOuGeral(const char* oQue);
						virtual Estatistica& DEstatisticaEmRede::apagaGeral();
						virtual Estatistica& DEstatisticaEmRede::apagaParcial();

						virtual Estatistica& DEstatisticaEmRede::zeraTudo();

						DEstatisticaEmRede& DEstatisticaEmRede::defineMaquina(int maquina);

				};
			}
		}
	}
}

#endif