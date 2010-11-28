/*
 * $RCSfile: Marcacao.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef Marcacao_SW_H
#define Marcacao_SW_H

#include "biblia/jogos/superbonus/antigo/CoisaNaTela.h"
using namespace biblia::jogos::superbonus::antigo;

/*
 * É uma filha de CoisaNaTela
 * facilitando a definição das áreas
 * através de arquivos de áreas.
 */
namespace biblia {
	namespace jogos{
		namespace superbonus {
			namespace antigo {

				class Marcacao: public CoisaNaTela {

					private:
						SpriteAntigo* Marcacao::pMarcacao;
						Lista* Marcacao::pListaArea;
						unsigned long int tempoInicialAnimacao;

					public:

						/* ArquivoBasico único */
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
