/*
 * $RCSfile: BotoesPlacaIO.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_BOTOES_PLACA_IO_H
#define SBS_BOTOES_PLACA_IO_H

#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;

#include "biblia/io/placaio/PlacaIO.h"
using namespace biblia::io::placaio;

#include "biblia/jogos/special/io/botoes/Botoes.h"
using namespace biblia::jogos::special::io::botoes;

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

namespace biblia {

	namespace jogos {

		namespace special {

			namespace io {

				namespace botoes {

					class BotoesPlacaIO :   public Botoes{

						private:

							PlacaIO* pPlacaIO;

							Semaforo* pSema;

							bool pVetBotoes[NUM_PLACAS][NUM_SAIDAS];
							bool pVetBotoesPressionados[NUM_PLACAS][NUM_SAIDAS];
							int pEstadoAnterior[NUM_PLACAS];

							enum Constantes{
								BTN_COBRAR            = 1,
								BTN_AJUDA             = 2,
								BTN_CARTELAS          = 3,
								BTN_TURBO_BOLA_EXTRA  = 4,
								BTN_NUMEROS           = 5,
								BTN_APOSTA            = 6,
								BTN_SUPER_TURBO       = 7,
								BTN_JOGAR             = 8,
								CHAVE_COBRANCA        = 9,
								CHAVE_CONFIGURACAO    = 10,
								PORTA_MAQUINA         = 11,
								PORTA_DINHEIRO        = 12,
								PORTA_CPU             = 13
							};

							int BotoesPlacaIO::converteBotaoEmTecla(const Botao&) const;
							Botao BotoesPlacaIO::converteTeclaEmBotao(int tecla) const;

						public:
							BotoesPlacaIO::BotoesPlacaIO(PlacaIO* placaIO);
							BotoesPlacaIO::~BotoesPlacaIO();

							virtual Executavel& BotoesPlacaIO::executa();
							virtual bool BotoesPlacaIO::pressionado(const Botao&);
					};
				}
			}
		}
	}
}
#endif
