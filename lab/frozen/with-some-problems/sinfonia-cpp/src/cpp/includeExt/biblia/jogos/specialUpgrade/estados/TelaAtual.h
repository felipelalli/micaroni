/*
 * $RCSfile: TelaAtual.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_TELAATUAL_H__BD853DCE_D557_48F5_8563_C934D42E7E3C__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_TELAATUAL_H__BD853DCE_D557_48F5_8563_C934D42E7E3C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class TelaAtual: public Objeto {
			private:
				static int TelaAtual::TELA_CARREGAMENTO;
				static int TelaAtual::TELA_JOGO;
				static int TelaAtual::TELA_DEMONSTRACAO;
				static int TelaAtual::TELA_CONFIGURACAO;
				static int TelaAtual::TELA_DESTRUICAO;

				int TelaAtual::pTelaAtual;
				int TelaAtual::pTelaDemonstracao;
                bool TelaAtual::pFlash;

				bool pEntrouNaConfiguracao;

			public:
				static int TelaAtual::TELA_DEMONSTRACAO_JOGANDO_SOZINHO;
				static int TelaAtual::TELA_DEMONSTRACAO_AJUDA;
				static int TelaAtual::TELA_DEMONSTRACAO_ACUMULADO;

				bool TelaAtual::full; // piscagem de botões full ou não

				/**
				 * Inicia na tela de carregamento.
				 */
				TelaAtual::TelaAtual();
				virtual TelaAtual::~TelaAtual();

                virtual TelaAtual& TelaAtual::deveConsumirFlash(bool sim);
                virtual bool TelaAtual::consomeFlash();
				virtual bool TelaAtual::carregamento() const;
				virtual TelaAtual& TelaAtual::carregamento(bool sim);
				virtual bool TelaAtual::jogo() const;
				virtual TelaAtual& TelaAtual::jogo(bool sim);
				virtual bool TelaAtual::demonstracao() const;
				virtual TelaAtual& TelaAtual::demonstracao(bool sim);
				virtual bool TelaAtual::configuracao() const;
				virtual TelaAtual& TelaAtual::configuracao(bool sim);
				virtual bool TelaAtual::destruicao() const;
				virtual TelaAtual& TelaAtual::destruicao(bool sim);

				// se estiver na tela de demonstração:
				virtual int TelaAtual::qualTelaDemonstracao() const;
				virtual TelaAtual& TelaAtual::proximaTelaDemonstracao();

				void TelaAtual::setEntrouNaConfiguracao (bool entrou){
					this->pEntrouNaConfiguracao = entrou;
				}

				bool TelaAtual::getEntrouNaConfiguracao (){
					return this->pEntrouNaConfiguracao;
				}
		};
	  }
	}
  }
}

#endif // !defined(AFX_TELAATUAL_H__BD853DCE_D557_48F5_8563_C934D42E7E3C__INCLUDED_)

