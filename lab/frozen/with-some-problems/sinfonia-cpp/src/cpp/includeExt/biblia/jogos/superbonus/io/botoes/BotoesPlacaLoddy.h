/*
 * $RCSfile: BotoesPlacaLoddy.h,v $
 * $Date: 2003/06/13 19:03:02 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef BOTOES_PLACA_LODDY_H
#define BOTOES_PLACA_LODDY_H

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/io/placaloddy/PlacaLoddy.h"
using namespace biblia::io::placaloddy;

#include "biblia/jogos/superbonus/io/botoes/Botoes.h"
using namespace biblia::jogos::superbonus::io::botoes;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

namespace biblia {

	namespace jogos {

		namespace superbonus {

			namespace io {

				namespace botoes {

					class BotoesPlacaLoddy :   public Botoes{

						private:

							PlacaLoddy* pPlacaLoddy;

							Semaforo* pSema;

							bool pVetBotoes[QTS_BOTOES];
							bool pVetBotoesPressionados[QTS_BOTOES];
							bool pVetEstadoAnterior[QTS_BOTOES];

							enum Constantes{
								BTN_COBRAR            = 3,
								BTN_AJUDA             = 9,
								BTN_CARTELAS          = 2,
								BTN_TURBO_BOLA_EXTRA  = 4,
								BTN_NUMEROS           = 7,
								BTN_APOSTA            = 1,
								BTN_SUPER_TURBO       = 6,
								BTN_JOGAR             = 5,
								CHAVE_COBRANCA        = 12,
								CHAVE_CONFIGURACAO    = 10,
								PORTA_MAQUINA         = 14,
								PORTA_DINHEIRO        = 11,
								PORTA_CPU             = 13
							};

							int BotoesPlacaLoddy::converteBotaoEmTecla(const Botao&) const;
							Botao BotoesPlacaLoddy::converteTeclaEmBotao(int tecla) const;

						public:
							BotoesPlacaLoddy::BotoesPlacaLoddy(PlacaLoddy* placaLoddy);
							BotoesPlacaLoddy::~BotoesPlacaLoddy();

							virtual Executavel& BotoesPlacaLoddy::executa();
							virtual bool BotoesPlacaLoddy::pressionado(const Botao&);
					};
				}
			}
		}
	}
}
#endif
