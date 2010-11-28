/*
 * $RCSfile: SpriteAntigo.h,v $
 * $Date: 2005/01/19 17:21:54 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_SPRITE_SW_H
#define AGES_SPECIAL_UPGRADE_SBS_SPRITE_SW_H

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/specialUpgrade/antigo/TelaCompleta.h"

using namespace biblia::jogos::specialUpgrade::antigo;
using namespace biblia::basico;

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace antigo {

				class SpriteAntigo : public Objeto {

					private :
						//Vetor com os Bitmaps que compoem o sprite
						BITMAP** pBitmaps;

						int pQuantosQuadros;

						//Quantidade de posicoes do vetor que jah foram
						//alocadas
						int pQuadrosAlocados;

						//Indica se essa lista criou ou nao os bitmaps
						bool pClone;

						// Indica se esse sprite é um vai-e-volta
						bool pVaiEVolta;

						volatile int pQuadroAtual;
						volatile bool pIndo;

					protected :
						//Aloca o vetor a partir do numero de quadros que
						//esta animacao tera'
						SpriteAntigo& SpriteAntigo::adicionaQuadros(char* nomeSprite,
								const int& quantidadeQuadros,
								const Area& area);

					public :

						//Construtores:

						//Cria a partir de um arquivo
						SpriteAntigo::SpriteAntigo(char* nomeArquivoBasico,
								   const int& quantidadeQuadros,
								   const Area& area);

						SpriteAntigo::SpriteAntigo(char* nomeSprite,
									   const int& quantidadeQuadros = 1);

						//Faz um clone virtual de um sprite
						SpriteAntigo::SpriteAntigo(const SpriteAntigo& sprite);

						//Pode ser ou nao ser clone
						SpriteAntigo::SpriteAntigo(int quantidadeMaximaQuadros=10,
								   bool clone = true);

						//Destrutor
						SpriteAntigo::~SpriteAntigo();

						//adiciona mais um quadro
						SpriteAntigo& SpriteAntigo::adicionaQuadro(BITMAP* maisUm);
						SpriteAntigo& SpriteAntigo::adicionaQuadro(BITMAP* figura,
								   Area& area);

						//retorna o numero total de quadros deste sprite
						int SpriteAntigo::quantosQuadros() const;

						//Retorna o numero de quadros alocados
						int SpriteAntigo::quadrosAlocados() const;

						//Retorna o BITMAP* de um determinado quadro
						BITMAP* SpriteAntigo::quadro(int qualQuadro) const;

						//Retorna o quadro atual
						BITMAP* SpriteAntigo::quadroAtual() const;

						//Verifica se esse sprite e' um clone
						bool SpriteAntigo::clone() const {
							return this->pClone;
						}


						int SpriteAntigo::quadroNumero() const {
							return this->pQuadroAtual;
						}

						//Avanca para o proximo quadro
						BITMAP* SpriteAntigo::proximoQuadro();

						//Retorna um quadro
						BITMAP* SpriteAntigo::quadroAnterior();

						//Exclui ultimo quadro
						SpriteAntigo& SpriteAntigo::excluiUltimo();

						//Verifica se é vai e volta:
						bool SpriteAntigo::vaiEVolta();

						//Define se é um sprite vai e volta ou não
						SpriteAntigo& SpriteAntigo::vaiEVolta(bool);

						SpriteAntigo& SpriteAntigo::mudaQuadro(int quadro);
				};
			}
		}
	}
}
#endif
