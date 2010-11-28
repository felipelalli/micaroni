/*
 * $RCSfile: Marcacao.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#ifndef TROPICAL_SBS_Marcacao_SW_H
#define TROPICAL_SBS_Marcacao_SW_H

#include "biblia/jogos/frutinha/antigo/CoisaNaTela.h"

/*
 * � uma filha de CoisaNaTela
 * facilitando a defini��o das �reas
 * atrav�s de arquivos de �reas.
 */
namespace biblia {
	namespace jogos{
		namespace frutinha {
			namespace antigo {

				class Marcacao: public CoisaNaTela {

					private:
						SpriteAntigo* Marcacao::pMarcacao;
						biblia::armazenamento::volatil::Lista* Marcacao::pListaArea;
						unsigned long int tempoInicialAnimacao;

					public:

						/* ArquivoBasico �nico */
						Marcacao::Marcacao(char * nomeSprite,
								unsigned int quadros,
								char* arquivoAreas, bool vaiEVolta = false);

						/* ArquivoBasicos separados */
						Marcacao::Marcacao(char * nomeSprite,
								unsigned int quadros,
								const Area& area,
								bool vaiEVolta = false);

						Marcacao::~Marcacao();

						bool Marcacao::anima(const unsigned long int tempoAnimacao,const unsigned long int& tempo){
							unsigned int varicaoTempo;
							if(tempo<this->tempoInicialAnimacao){
								this->tempoInicialAnimacao = tempo;
								varicaoTempo = 0;
							}else{
								varicaoTempo  = tempo - this->tempoInicialAnimacao;
							}
							if(varicaoTempo>=tempoAnimacao){
								this->sprite().proximoQuadro();
								this->tempoInicialAnimacao = tempo;
								return true;
							}
							return false;
						}

						void Marcacao::inicializaTempo(){
							this->tempoInicialAnimacao=0;
						}

						unsigned long int Marcacao::tempInicial(){
							return this->tempoInicialAnimacao;
						}

				};
			}
		}
	}
}
#endif
