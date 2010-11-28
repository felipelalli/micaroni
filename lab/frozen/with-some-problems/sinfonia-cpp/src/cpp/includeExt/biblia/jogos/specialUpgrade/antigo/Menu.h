/*
 * $RCSfile: Menu.h,v $
 * $Date: 2005/01/19 17:21:53 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_MENU_H_SW
#define AGES_SPECIAL_UPGRADE_SBS_MENU_H_SW

#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/visual/Ponto.h"
#include "biblia/jogos/specialUpgrade/antigo/ComponenteDeUmRelatorio.h"
#include <stdio.h>

using namespace biblia::armazenamento::volatil;
using namespace biblia::visual;

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace antigo {

				class OpcaoMenu {
					private:
						char* pTextoOpcao;
						int pNumeroOpcao;

					public:
						OpcaoMenu(const char* texto,int numeroDaOpcao);
						~OpcaoMenu();

						const char* texto() const;
						int numeroDaOpcao() const;
				};

				/** Menu:
					Implementa um menu de apenas um nível */

				class Menu: public ComponenteDeUmRelatorio {
					private:

						biblia::armazenamento::volatil::Lista* pOpcoes;

						int pOpcaoAtual;
						int pOpcaoEscolhida;
						int pQuantasOpcoes;

						Ponto* pPosicao;

					public:
						Menu(const Ponto&);
						~Menu();

						//Adiciona uma opção no menu
						void adicionaOpcoes(const char* opcao,int numeroDaOpcao,bool temPermissao=true);

						//retorna o nome da opção
						const char* opcao(int qualOpcao) const;

						int numeroDaOpcao(int qualOpcao) const;

						// implementa a navegação
						int proximaOpcao();
						int opcaoAnterior();

						int opcaoAtual() const;

						//seleciona a opção
						void selecionaOpcao();

						const Ponto& posicao() const;

						int consomeOpcao();

						//retorna o numero de opcoes adicionadas a este menu
						int quantasOpcoes() const;

				};
			}
		}
	}
}
#endif