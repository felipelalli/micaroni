/*
 * $RCSfile: LinhaDeUmRelatorio.h,v $
 * $Date: 2005/01/19 17:21:53 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_LINHA_DE_UM_TEXTO_H_SW
#define AGES_SPECIAL_UPGRADE_SBS_LINHA_DE_UM_TEXTO_H_SW

#include <stdlib.h>
#include <string.h>
#include "biblia/jogos/specialUpgrade/antigo/ComponenteDeUmRelatorio.h"

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace antigo {
				/*Possíveis estilos de um texto*/
				#define ESTILO_NORMAL     0
				#define ESTILO_NEGRITO    2
				#define ESTILO_TITULO     4
				#define ESTILO_ILUMINADO  8
				#define ESTILO_PEQUENO   16

				/*
				 * Label é um texto que pode possuir um estilo(Negrito,
				 * itálico, etc);
				 *
				 */
				class Label:public ComponenteDeUmRelatorio{
					private:
						char* pTexto;
						int pEstilo;
					public:
						/*construtores*/
						Label(const char* texto,int estilo=ESTILO_NORMAL,
							  int componenteFilho = 356786);
						/*destrutor*/
						~Label();
						/*retorna o conteúdo do label*/
						const char* texto() const;
						Label& Label::texto(const char* novo);
						/*retorna o estilo de texto do Label*/
						int estilo() const;
						/*permite modificar o estilo*/
						Label& estilo(int estilo);
				};

				class LabelSenha: public Label {
					public:
						/*construtores*/
						LabelSenha(const char* texto,
							  int estilo = ESTILO_NORMAL);
				};

				class Input:public ComponenteDeUmRelatorio{
					private:
						/*String que determina os valores possíveis
						  para um Input*/
						char * pValoresPossiveis;

						/*Vetor que indica o valor escolhido para
						  cada uma das posições do Input*/
						int * pValorAtual;

						/* Indica qual caracter foi escolhido*/
						int pCaracterEscolhido;

						/*Numero de caracters que o Input possui*/
						int pQuantosCaracteres;

						int pEstilo;

						int pProcuraPosicao(char caracter);

					public:
						/*Constutores*/
						Input(const char* valoresPossiveis,
							  int quantosCaracteres,
							  int componenteFilho = 7887);

						/*Destrutor*/
						~Input();

						/*Permite modificar o valor de uma posição de um Input */
						void aumentarValor();
						void diminuirValor();

						/*Permite navegação pelas posições de um Input*/
						void proximoCaracter();
						void caracterAnterior();

						/*Retorna o valor atual de um Input*/
						char* valor() const;

						/*Altera o valor atual do input*/
						void valor(const char * valor);

						/*Retorna qual caracter foi escolhido*/
						int  caracterEscolhido() const;
						Input& caracterEscolhido(int qual);

						int  estilo() const;
						void estilo(int estilo);

						int quantosCaracteres() const {
							return this->pQuantosCaracteres;
						}
				};

				class InputSenha: public Input {
					public:
						InputSenha::InputSenha(
							  const char* valoresPossiveis,
							  int quantosCaracteres);
				};

				class InputNumerico:public ComponenteDeUmRelatorio{
					private:
						int pValorInicialRange;
						int pValorFinalRange;
						int pPasso;
						int pValorAtual;
						int pEstilo;

					public:

						/*constutores*/
						InputNumerico(int valorIncialRange,
									  int valorFinalRange,int passo=1, int estilo=0,
									  int componenteFilho = 3070);

						/*destrutor*/
						~InputNumerico();

						/*permite aumentar o valor de um Input*/
						void aumentarValor();
						/*permite diminuir o valor de um Input*/
						void diminuirValor();
						/*Retorna o valor atual de um Input*/
						int  valor()const;
						void valor(int valor);

						InputNumerico& InputNumerico::mudaValorMinimo(int valorMinimo);
						InputNumerico& InputNumerico::mudaValorMaximo(int valorMaximo);

						int valorMaximo()const;


						int estilo() const;
						void estilo(int estilo);
				};

				class VelocidadeDasBolas:public InputNumerico {
					public:
						VelocidadeDasBolas::VelocidadeDasBolas();
				};
			}
		}
	}
}
#endif
