/*
 * $RCSfile: Menu.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef MENU_H_SW
#define MENU_H_SW

#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/visual/Ponto.h"
#include "biblia/jogos/superbonus/antigo/ComponenteDeUmRelatorio.h"
#include <stdio.h>

using namespace biblia::armazenamento::volatil;
using namespace biblia::visual;

namespace biblia {
	namespace jogos {
		namespace superbonus {
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

						Lista* pOpcoes;

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