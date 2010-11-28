/*
 * $RCSfile: PremioSurpresa.h,v $
 * $Date: 2005/02/03 00:54:29 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#ifndef AGES_SPECIAL_UPGRADE_PREMIO_SURPRESA_H
#define AGES_SPECIAL_UPGRADE_PREMIO_SURPRESA_H


#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/sorte/Sorteio.h"
using namespace biblia::sorte;

#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/Cronometro.h"
#include "biblia/tempo/UniversoDeTempo.h"
using namespace biblia::tempo;

#include "biblia/tempo/unidades/Segundo.h"
using namespace biblia::tempo::unidades;

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/specialUpgrade/logica/util/EventosPremioSurpresa.h"
#include "biblia/jogos/specialUpgrade/logica/util/InterCliPremioSurpresa.h"
using namespace biblia::jogos::specialUpgrade::logica::util;



namespace biblia {

	namespace jogos {

		namespace specialUpgrade {

			namespace logica {

				class PremioSurpresa: public Executavel {

					private:						

						Sorteio pSorte;


						//***************************
						// CLIENTE												
						bool				   pPremioLancado;
						int					   pValorPremio;						
						GerenciadorRede*       pRede;
						InterCliPremioSurpresa pInterCliPremioSurpresa;
						Semaforo               pSemaCliente;
						biblia::armazenamento::volatil::Lista pLstEventos;

						bool                   pGanhouPremio;
						int                    pValorGanho;
						//***************************
						void PremioSurpresa::limpaEventos();
						void PremioSurpresa::atualizaEstados();
						//***************************
						static double ProbabilidadeDeTransformarEmPremioSurpresa;
						//
						//***************************
												

						//***************************
						// SERVIDOR
						int        pValorAcumuladoServidor;
						int        pValorPremioServidor;
						bool       pPremioLancadoServidor;
						Cronometro pCronometro;
						Intervalo  pIntervaloLancamento;
						Semaforo   pSemaServidor;
						bool       pJaSorteouProbabilidade [5];
						//***************************
						bool PremioSurpresa::podeLancar();
						void PremioSurpresa::sorteiaPremio();
						void PremioSurpresa::verificaLancamento();						
						//***************************
						static double ProbabilidadesLancamento [5];
						static double QuantasProbabilidades;												
						static double ProbabilidadesValores    [2];
						static int    ValoresPossiveis         [2];
						static int    QuantosValores;
						//
						//***************************


					public:
						PremioSurpresa::PremioSurpresa(GerenciadorRede* rede, UniversoDeTempo& universoDeTempo);
						virtual PremioSurpresa::~PremioSurpresa();

						//***************************
						// CLIENTE						
						bool PremioSurpresa::transformaEmPremioSurpresa(int premio, int valor, int aposta);
						void PremioSurpresa::verificaSePremiaPremioSurpresa(int premio, bool demonstracao);
						//***************************
						bool      PremioSurpresa::premioLancado();
						bool      PremioSurpresa::ganhouPremio();
						int       PremioSurpresa::valorGanho();
						//***************************
						bool      PremioSurpresa::haEvento();
						EventoID* PremioSurpresa::consomeEvento();
						void      PremioSurpresa::adicionaEvento (EventoID* evento);
						int       PremioSurpresa::qtsEventos();
						EventoID& PremioSurpresa::getEvento(int qual);
						//***************************						
						void PremioSurpresa::zera();						
						//
						//***************************


						//***************************
						// SERVIDOR
						void PremioSurpresa::adicionaValorServidor (int valor);
						void PremioSurpresa::premiouPremioSurpresa (int valor);
						int  PremioSurpresa::valorAcumuladoServidor();
						int  PremioSurpresa::valorPremioServidor   ();
						bool PremioSurpresa::premioLancadoServidor ();
						//
						//***************************
						
						Executavel& PremioSurpresa::executa();
				};
			}
		}
	}
}

#endif
