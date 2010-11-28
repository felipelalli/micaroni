/*
 * $RCSfile: BotoesPlacaLoddy.h,v $
 * $Date: 2003/11/25 03:22:23 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#ifndef SBS_BOTOES_PLACA_LODDY_H
#define SBS_BOTOES_PLACA_LODDY_H

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/io/placaloddy/PlacaLoddy.h"
using namespace biblia::io::placaloddy;

#include "biblia/jogos/special/io/botoes/Botoes.h"
using namespace biblia::jogos::special::io::botoes;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

namespace biblia {

	namespace jogos {

		namespace special {

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
								BTN_CARTELAS          = 1, //H
								BTN_TURBO_BOLA_EXTRA  = 2, //I
								BTN_SUPER_TURBO       = 3, //J
								BTN_JOGAR             = 4, //K
								BTN_COBRAR            = 5, //L
								BTN_AJUDA             = 6, //M
								BTN_APOSTA            = 7, //N								
								BTN_NUMEROS           = 9, //P					
								CHAVE_CONFIGURACAO    = 12,//Q //Chave do pagamento
								PORTA_DINHEIRO        = 11,//R
								CHAVE_COBRANCA        = 10,//S //Chave do Medidor
								PORTA_CPU             = 13,//T
								PORTA_MAQUINA         = 14 //U																
								                           //V //Chave do Sistema
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
