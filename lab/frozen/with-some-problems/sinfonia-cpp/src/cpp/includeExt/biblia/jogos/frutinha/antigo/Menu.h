/*
 * $RCSfile: Menu.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#ifndef TROPICAL_SBS_MENU_H_SW
#define TROPICAL_SBS_MENU_H_SW

#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/visual/Ponto.h"
#include "biblia/jogos/frutinha/antigo/ComponenteDeUmRelatorio.h"
#include <stdio.h>

using namespace biblia::armazenamento::volatil;
using namespace biblia::visual;

namespace biblia {
	namespace jogos {
		namespace frutinha {
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
					Implementa um menu de apenas um n�vel */

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

						//Adiciona uma op��o no menu
						void adicionaOpcoes(const char* opcao,int numeroDaOpcao,bool temPermissao=true);

						//retorna o nome da op��o
						const char* opcao(int qualOpcao) const;

						int numeroDaOpcao(int qualOpcao) const;

						// implementa a navega��o
						int proximaOpcao();
						int opcaoAnterior();

						int opcaoAtual() const;

						//seleciona a op��o
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