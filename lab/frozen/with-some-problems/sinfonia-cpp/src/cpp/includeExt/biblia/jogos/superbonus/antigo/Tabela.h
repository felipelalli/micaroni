/*
 * $RCSfile: Tabela.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef TABELA_H_SW
#define TABELA_H_SW

#include "biblia/jogos/superbonus/antigo/ComponenteDeUmRelatorio.h"
#include "biblia/armazenamento/volatil/Lista.h"

using namespace biblia::armazenamento::volatil;

namespace biblia {
	namespace jogos {
		namespace superbonus {
			namespace antigo {
				/*Alinhamento horizontal*/
				#define ALINHAMENTO_A_ESQUERDA  0
				#define ALINHAMENTO_A_DIREITA   1

				/*Alinhamento vertical*/
				#define ALINHAMENTO_NO_TOPO  2
				#define ALINHAMENTO_NO_FUNDO 3

				/*Alinhamentotanto vertical quanto horizontal*/
				#define ALINHAMENTO_CENTRALIZADO 5

				class Celula{
					private:
						int pCor;
						int pAlinhamento;
						int pTamanhoX,pTamanhoY;

						ComponenteDeUmRelatorio* pConteudo;
						bool pBorda;

					public:
						Celula(int tamanhoX, int tamanhoY,
								int cor=0,int alinhamento=ALINHAMENTO_A_ESQUERDA);

						~Celula();

						void tamanhoX(int tamanho);
						void tamanhoY(int tamanho);

						int tamanhoX() const;
						int tamanhoY() const;

						void cor(int qualCor);
						int cor() const;

						void conteudo(ComponenteDeUmRelatorio* componente);
						ComponenteDeUmRelatorio* conteudo() const;
						bool temConteudo() const;

						void borda(bool comBorda);
						bool borda() const;

						void alinhamento(int qualAlinhamento);
						int alinhamento() const;
				};


				class Linha{
					private:
						Lista* pCelulas;
						int pAlturaLinha;
					public:
						Linha(int alturaLinha);
						~Linha();

						void adicionaCelula(int tamanhoX, int cor=0, int alinhamento=ALINHAMENTO_A_ESQUERDA);
						void removeCelula();

						int quantasCelulas() const;

						void pintaCelulas(int cor);

						void colocaBorda();
						void tiraBorda();

						Celula& celula(int qualCelula) const;
						Celula& operator[](int qualCelula) const;

						void altura(int altura);
						int altura() const;
				};


				/*
				 * Uma Tabela serve como container para ComponenentesDeUmRelatorio.
				 * Os apontadores para componenentes de um relatório não são liberados
				 * pela Tabela.
				 */
				class Tabela: public ComponenteDeUmRelatorio{
					private:
						Lista* pLinhas;
						int pQuantasColunas;
						int pCor;
						int pTransparencia;

					public:
						Tabela(int qtdeLinha=1,int qtdeColuna=1,int cor=0,
								int transparencia = 100);

						~Tabela();

						void adicionaLinha(int altura);
   						void adicionaColuna(int tamanho);

						void excluiLinha();
						void excluiColuna();

						/*rotinas relacionadas às cores das células*/
						void pintaCelula(int cor, int linha, int coluna);
						void pintaLinha(int cor, int linha);
						int  cor(int linha, int coluna) const;

						void transparencia(int porcentagem);
						int transparencia() const;

						/*funções relacionadas ao alinhamento da célula*/
						int alinhamento(int linha, int coluna)const;
						void alinhamento(int linha, int coluna, int alinhamento);
						void alinhamento(int l1, int c1, int l2, int c2, int alinhamento);


						/*rotinas relacionadas às bordas da tabela*/
						void colocaBordaCelula(int linha, int coluna);
						void tiraBordaCelula(int linha, int coluna);
						void colocaBordaLinha(int linha);
						void tiraBordaLinha(int linha);
						void tiraBorda();

						bool temBorda(int linha, int coluna) const;

						/*rotinas reacionadas ao conteúdo das células da tabela*/
						ComponenteDeUmRelatorio* conteudo(int linha, int coluna) const;
						void conteudo(int linha, int coluna, ComponenteDeUmRelatorio* oQue);
						bool temConteudo(int linha, int coluna) const;

						/*rotinas relacionadas às dimensões da tabela*/
						int quantasLinhas() const;
						int quantasColunas() const;
    					int alturaTabela() const;
						int larguraTabela() const;
						int alturaLinha(int linha) const;
						int tamanhoColuna(int coluna) const;
						void modificaAlturaLinha(int linha, int altura);
						void modificaTamanhoColuna(int coluna, int tamanho);
				};
			}
		}
	}
}
#endif