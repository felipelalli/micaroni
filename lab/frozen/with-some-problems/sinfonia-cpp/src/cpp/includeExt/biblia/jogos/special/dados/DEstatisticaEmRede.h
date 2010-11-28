/*
 * $RCSfile: DEstatisticaEmRede.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_DESTATISTICA_EM_REDE_H
#define SBS_DESTATISTICA_EM_REDE_H

#include "biblia/jogos/special/dados/DadosEstatisticaEmRede.h"
#include "biblia/jogos/special/dados/Estatistica.h"
using namespace biblia::jogos::special::dados;

#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace special{

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