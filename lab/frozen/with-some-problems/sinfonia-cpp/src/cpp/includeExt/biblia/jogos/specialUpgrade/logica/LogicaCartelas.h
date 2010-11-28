/*
 * $RCSfile: LogicaCartelas.h,v $
 * $Date: 2005/01/19 17:22:13 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_LOGICA_CARTELAS_BASE_H
#define AGES_SPECIAL_UPGRADE_LOGICA_CARTELAS_BASE_H


//FIXME: AQUI NAO DEVERIA CHAMAR NADA DO SPECIAL
#include "biblia/jogos/specialUpgrade/logica/SorteioBolas.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/jogos/specialUpgrade/logica/util/ArqCartelas.h"
#include "biblia/jogos/specialUpgrade/logica/util/EventosCartela.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/GerenciadorDePremios.h"
using namespace biblia::jogos::specialUpgrade::logica;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace logica{

				class GerenciadorDePremios;

				class LogicaCartelas : public Objeto{

					private:

						biblia::jogos::specialUpgrade::logica::SorteioBolas pSorteio;

						ArqCartelas pArqCartelas;
						biblia::armazenamento::volatil::Lista* pLstCartelas;
						GerenciadorDePremios& pGerenciador;

						int pAposta;

						int pQtsNumerosMarcados;

						biblia::armazenamento::volatil::Lista* pLstEventoPremio;

						void LogicaCartelas::pOrdenar (unsigned int* numeros, unsigned int inicio, unsigned int fim);

						bool pDeveLimpar; //FIXME: essa variavel nao deveria estar aqui, mesmo caso das funcoes abaixo

					public:
						LogicaCartelas::LogicaCartelas(GerenciadorDePremios& gerenciador);
						LogicaCartelas::~LogicaCartelas();

						int LogicaCartelas::qtsCartelas();
						int LogicaCartelas::qtsCartelasAtivas();

						Cartela& LogicaCartelas::getCartela(int indice);
						Cartela& LogicaCartelas::getCartelaAtiva (int indice);

						void LogicaCartelas::ativaCartela (int indice, bool ativar);

						void LogicaCartelas::colocaNumero (int numero, bool bolaExtra=false, bool concorreAcumulado=false);						

						void LogicaCartelas::zerar ();

						void LogicaCartelas::sortearNumeros(bool repetirNumeros = false);

						bool LogicaCartelas::haFaltaUm ();

						void LogicaCartelas::restaurar(){};

						void LogicaCartelas::salvar(){};

						void LogicaCartelas::proxCartelaAtiva();

						void LogicaCartelas::setCartelasAtivas(int qtsCartelas){
							for (int iCartela = 0; iCartela < 4; iCartela++){
								if (iCartela <= (qtsCartelas-1)){
									this->getCartela(iCartela).ativar (true);
								}else{
									this->getCartela(iCartela).ativar (false);
								}
							}
						}

						void LogicaCartelas::setAposta(int aposta){
							this->pAposta = aposta;
						}

						bool LogicaCartelas::haEventoDePremio();
						void LogicaCartelas::adicionaEventoDePremio(EventoMarcouPremio* evento);
						EventoMarcouPremio* LogicaCartelas::consomeEventoDePremio();


						unsigned int LogicaCartelas::aposta();

						void LogicaCartelas::aumentarAposta ();

						void LogicaCartelas::diminuirAposta ();


						//FIXME: essas funcoes vieram do logica cartela do superbonus,
						//deveriam estar em outro lugar
						void LogicaCartelas::deveLimpar(bool);
						bool LogicaCartelas::deveLimpar() const;
						void LogicaCartelas::limpou();
				};
			}
		}
	}
}

#endif