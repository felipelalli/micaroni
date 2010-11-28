/*
 * $RCSfile: Marcacao.h,v $
 * $Date: 2005/01/19 17:21:53 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_Marcacao_SW_H
#define AGES_SPECIAL_UPGRADE_SBS_Marcacao_SW_H

#include "biblia/jogos/specialUpgrade/antigo/CoisaNaTela.h"
using namespace biblia::jogos::specialUpgrade::antigo;

/*
 * É uma filha de CoisaNaTela
 * facilitando a definição das áreas
 * através de arquivos de áreas.
 */
namespace biblia {
	namespace jogos{
		namespace specialUpgrade {
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
