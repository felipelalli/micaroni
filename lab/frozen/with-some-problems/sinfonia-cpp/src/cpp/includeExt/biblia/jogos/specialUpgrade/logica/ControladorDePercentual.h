/*
 * $RCSfile: ControladorDePercentual.h,v $
 * $Date: 2005/01/19 17:22:10 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_CONTROLADOR_DE_PERCENTUAL_H
#define AGES_SPECIAL_UPGRADE_CONTROLADOR_DE_PERCENTUAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/specialUpgrade/logica/GerenciadorDeProbabilidades.h"
#include "biblia/jogos/specialUpgrade/logica/GerenciadorDeFluxoDeJogo.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/specialUpgrade/dados/DEstatistica.h"
#include "biblia/jogos/specialUpgrade/dados/DadosConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;


namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				class ControladorDePercentual: public Executavel{

					private:
						LogicaCartelas&          pCartelas;
						GerenciadorDeFluxoDeJogo pFluxo;
						biblia::jogos::specialUpgrade::dados::DadosConfiguracao&       pDados;
						GerenciadorDeProbabilidades&    pGerenciador;

						//Variáveis para thread que traz o retido da rede
						Thread* pThread;
						bool pTerminar;
						bool pTerminou;
						Semaforo pSemaRetido;

						//TODO: Esta lista tem que ser salva em arquivo
						ListaInt pLstPremiosDevidos;

						int pRetidoRede;

						int ControladorDePercentual::pTrazerRetidoRede();
						bool ControladorDePercentual::pPodePremio(int premio);

					public:
						ControladorDePercentual::ControladorDePercentual(GerenciadorDeProbabilidades& gerenciador, biblia::jogos::specialUpgrade::dados::DadosConfiguracao& dados, LogicaCartelas& cartelas);
						ControladorDePercentual::~ControladorDePercentual();

						int ControladorDePercentual::getPremio(bool concorreAcumulado,bool dobro,int cartelas);


						Executavel& ControladorDePercentual::executa();
				};
			}
		}
	}
}

#endif