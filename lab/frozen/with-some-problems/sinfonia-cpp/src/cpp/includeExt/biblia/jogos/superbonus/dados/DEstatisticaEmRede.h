/*
 * $RCSfile: DEstatisticaEmRede.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef DESTATISTICA_EM_REDE_H
#define DESTATISTICA_EM_REDE_H

#include "biblia/jogos/superbonus/dados/DadosEstatisticaEmRede.h"
#include "biblia/jogos/superbonus/dados/Estatistica.h"
using namespace biblia::jogos::superbonus::dados;

#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;


namespace biblia{

	namespace jogos{

		namespace superbonus{

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