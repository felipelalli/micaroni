/*
 * $RCSfile: LuzBotoes.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.4 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef LUZ_BOTOES_H
#define LUZ_BOTOES_H

#include "biblia/jogos/superbonus/io/botoes/Botoes.h"
using namespace biblia::jogos::superbonus::io::botoes;

#include "biblia/io/placaio/PlacaIO.h"
using namespace biblia::io::placaio;

#include "biblia/io/DispositivoDeSaida.h"
using namespace biblia::io;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace io{

				namespace botoes{

					class LuzBotoes{

						private:
							PlacaIO* pPlacaIO;

							enum Constantes{
								BTN_COBRAR           =1,
								BTN_AJUDA            =2,
								BTN_CARTELAS         =3,
								BTN_TURBO_BOLA_EXTRA =4,
								BTN_NUMEROS          =5,
								BTN_APOSTA           =6,
								BTN_SUPER_TURBO      =7,
								BTN_JOGAR            =8,
								CHAVE_COBRANCA       =9,
								CHAVE_CONFIGURACAO   =10,
								SENSOR_PORTA_MAQUINA =11,
								SENSOR_PORTA_DINHEIRO=12
							};

							Semaforo* pSema;

							int LuzBotoes::converteBotaoEmTecla(const Botao&) const;
							Botao LuzBotoes::converteTeclaEmBotao(int tecla) const;

							bool pVetLuzes[NUM_PLACAS][NUM_SAIDAS];

						public:
							LuzBotoes::LuzBotoes (PlacaIO* placaIO);
							virtual LuzBotoes::~LuzBotoes();

							bool LuzBotoes::aceso (const Botao&);
							void LuzBotoes::mudarBotao (const Botao&, bool acende);
					};
				}
			}
		}
	}
}

#endif