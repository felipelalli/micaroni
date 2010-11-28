/*
 * $RCSfile: Marcacao.h,v $
 * $Date: 2004/06/18 01:50:27 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef SBS_Marcacao_SW_H
#define SBS_Marcacao_SW_H

#include "biblia/jogos/special/antigo/CoisaNaTela.h"
using namespace biblia::jogos::special::antigo;

/*
 * É uma filha de CoisaNaTela
 * facilitando a definição das áreas
 * através de arquivos de áreas.
 */
namespace biblia {
	namespace jogos{
		namespace special {
			namespace antigo {

				class Marcacao: public CoisaNaTela {

					private:
						SpriteAntigo* Marcacao::pMarcacao;
						biblia::armazenamento::volatil::Lista* Marcacao::pListaArea;
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
