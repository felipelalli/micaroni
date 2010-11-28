/*
 * $RCSfile: LogicaCartelas.h,v $
 * $Date: 2004/06/16 00:31:27 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef LOGICA_CARTELAS_BASE_H
#define LOGICA_CARTELAS_BASE_H


//FIXME: AQUI NAO DEVERIA CHAMAR NADA DO SPECIAL
#include "biblia/jogos/special/logica/SorteioBolas.h"
using namespace biblia::jogos::special::logica;

#include "biblia/jogos/bingo/logica/util/ArqCartelas.h"
#include "biblia/jogos/bingo/logica/util/EventosCartela.h"
using namespace biblia::jogos::bingo::logica::util;

#include "biblia/jogos/bingo/logica/GerenciadorDePremios.h"
using namespace biblia::jogos::bingo::logica;

namespace biblia{
	
	namespace jogos{

		namespace bingo{
		
			namespace logica{

				class GerenciadorDePremios;

				class LogicaCartelas : public Objeto{

					private:

						biblia::jogos::special::logica::SorteioBolas pSorteio;

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