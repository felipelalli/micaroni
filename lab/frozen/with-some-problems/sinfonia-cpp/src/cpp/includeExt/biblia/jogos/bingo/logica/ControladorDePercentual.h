/*
 * $RCSfile: ControladorDePercentual.h,v $
 * $Date: 2003/12/23 21:46:27 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef CONTROLADOR_DE_PERCENTUAL_H
#define CONTROLADOR_DE_PERCENTUAL_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/bingo/logica/GerenciadorDeProbabilidades.h"
#include "biblia/jogos/bingo/logica/GerenciadorDeFluxoDeJogo.h"
using namespace biblia::jogos::bingo::logica;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/special/dados/DEstatistica.h"
#include "biblia/jogos/special/dados/DadosConfiguracao.h"
using namespace biblia::jogos::special::dados;

#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;


namespace biblia{

	namespace jogos{

		namespace bingo{

			namespace logica{

				class ControladorDePercentual: public Executavel{

					private:
						LogicaCartelas&          pCartelas;
						GerenciadorDeFluxoDeJogo pFluxo;
						biblia::jogos::special::dados::DadosConfiguracao&       pDados;
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
						ControladorDePercentual::ControladorDePercentual(GerenciadorDeProbabilidades& gerenciador, biblia::jogos::special::dados::DadosConfiguracao& dados, LogicaCartelas& cartelas);
						ControladorDePercentual::~ControladorDePercentual();

						int ControladorDePercentual::getPremio(bool concorreAcumulado,bool dobro,int cartelas);
						

						Executavel& ControladorDePercentual::executa();
				};
			}
		}
	}
}

#endif