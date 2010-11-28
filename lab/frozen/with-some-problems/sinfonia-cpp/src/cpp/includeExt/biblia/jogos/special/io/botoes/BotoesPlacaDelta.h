/*
 * $RCSfile: BotoesPlacaDelta.h,v $
 * $Date: 2004/05/17 21:17:35 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef SBS_BOTOES_PLACA_Delta_H
#define SBS_BOTOES_PLACA_Delta_H

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;


#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;


#include "biblia/jogos/special/io/botoes/Botoes.h"
using namespace biblia::jogos::special::io::botoes;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

namespace biblia {

	namespace jogos {

		namespace special {

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
								BTN_CARTELAS          = 3, //H
								BTN_TURBO_BOLA_EXTRA  = 7, //I
								BTN_SUPER_TURBO       = 1, //J
								BTN_JOGAR             = 6, //K
								BTN_COBRAR            = 2, //L
								//BTN_SAIR              = 2, //L
								BTN_AJUDA             = 5, //M
								BTN_APOSTA            = 0, //N								
								BTN_NUMEROS           = 4, //P					
								CHAVE_CONFIGURACAO    = 8,//Q //Chave do pagamento
								PORTA_DINHEIRO        = 11,//R
								CHAVE_COBRANCA        = 9,//S //Chave do Medidor
								PORTA_CPU             = 13,//T
								PORTA_MAQUINA         = 14 //U																
								                           //V //Chave do Sistema
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
