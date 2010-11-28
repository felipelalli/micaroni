/*
 * $RCSfile: MensagemBmp.h,v $
 * $Date: 2004/06/18 01:50:28 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/special/antigo/CoisaNaTela.h"

using namespace biblia::basico;

#ifndef SBS_MENSAGEM_BMP_SW_H
#define SBS_MENSAGEM_BMP_SW_H

namespace biblia {
	namespace jogos {
		namespace special {
			namespace antigo {

				class MensagemBmp: public Objeto {
					private:
						//sprite que define o formato dos caracteres
						SpriteAntigo* pFonte;
						//tamanho de cada caracter
						biblia::armazenamento::volatil::Lista* pListaArea;
						//bool pEhNumero;
						char pSequencia[1000];
						char pNomeArquivoBasico[300];
						unsigned int MensagemBmp::posicao(char caracter);

					public:

						/* As imagens passadas para o construtor devem
						 * respeitar o seguinte formato:
						 *
						 * Bloco1        |Bloco2    | Bloco3
						 * ABCDEFGH....Z |0123456789| ,.:?!
						 *
						 * O 3.o bloco fica reservado para carcteres
						 * "especiais"
						 *///old

						/*
						 * Agora na verdade, com o novo construtor
						 * deve-se passar o formato desejado. Pode
						 * ter até 1000 caracteres.
						 */


						//recebe o nome do arquivo do qual serao extraidos os
						//caracteres e o tamanho de cada caracter e a posicao
						//inicial do corte do bitmap.
						MensagemBmp::MensagemBmp(char * fonte, short int quadros,
								char * arquivoAreas, const char* sequencia = NULL);

						//Desaloca  a memoria utilizada pelo sprite e pela
						//area
						MensagemBmp::~MensagemBmp();

						//Retorna uma coisa na tela que contemo texto
						//que foi passado para a funcao
						CoisaNaTela * MensagemBmp::escreve(const char * texto);
				};
			}
		}
	}
}
#endif
