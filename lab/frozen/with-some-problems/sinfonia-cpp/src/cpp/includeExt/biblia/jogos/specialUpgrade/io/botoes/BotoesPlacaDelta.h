/*
 * $RCSfile: BotoesPlacaDelta.h,v $
 * $Date: 2005/01/19 17:22:04 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_SBS_BOTOES_PLACA_Delta_H
#define AGES_SPECIAL_UPGRADE_SBS_BOTOES_PLACA_Delta_H

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;

#include "biblia/jogos/specialUpgrade/io/botoes/Botoes.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

namespace biblia {

	namespace jogos {

		namespace specialUpgrade {

			namespace io {

				namespace botoes {

					class BotoesPlacaDelta :   public Botoes{

						private:

							PlacaDelta* pPlacaDelta;

							Semaforo* pSema;

							bool pVetBotoes[QTS_BOTOES_PLACA_DELTA];
							bool pVetBotoesPressionados[QTS_BOTOES_PLACA_DELTA];
							bool pVetEstadoAnterior[QTS_BOTOES_PLACA_DELTA];

							enum Constantes{
								BTN_JOGAR             = 0,
								BTN_CARTELAS          = 1,
								BTN_NUMEROS           = 2,
								BTN_AJUDA             = 3,
								BTN_SUPER_TURBO       = 4,
								BTN_APOSTA            = 5,
								BTN_COBRAR            = 6,
								BTN_TURBO_BOLA_EXTRA  = 7,
								CHAVE_CONFIGURACAO    = 8,
								CHAVE_COBRANCA        = 9,																																																
								PORTA_DINHEIRO        = 10,								
								PORTA_CPU             = 11,
								PORTA_MAQUINA         = 12
								                        
							};

							int BotoesPlacaDelta::converteBotaoEmTecla(const Botao&) const;
							Botao BotoesPlacaDelta::converteTeclaEmBotao(int tecla) const;

						public:
							BotoesPlacaDelta::BotoesPlacaDelta(PlacaDelta* placaDelta);
							BotoesPlacaDelta::~BotoesPlacaDelta();

							virtual Executavel& BotoesPlacaDelta::executa();
							virtual bool BotoesPlacaDelta::pressionado(const Botao&);
					};
				}
			}
		}
	}
}
#endif
