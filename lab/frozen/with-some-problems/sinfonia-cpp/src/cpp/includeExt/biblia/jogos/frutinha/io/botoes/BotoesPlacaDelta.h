/*
 * $RCSfile: BotoesPlacaDelta.h,v $
 * $Date: 2005/01/20 17:44:47 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef FRUTINHA_BOTOES_PLACA_DELTA_H
#define FRUTINHA_BOTOES_PLACA_DELTA_H

#include "biblia/io/placadelta/PlacaDelta.h"
using namespace biblia::io::placadelta;


#include "biblia/fluxo/Semaforo.h"
using namespace biblia::fluxo;


#include "biblia/jogos/frutinha/io/botoes/Botoes.h"
using namespace biblia::jogos::frutinha::io::botoes;

#define QTS_BOTOES_DELTA 20

namespace biblia {

	namespace jogos {

		namespace frutinha {

			namespace io {

				namespace botoes {

					class BotoesPlacaDelta :   public Botoes{

						private:

							PlacaDelta& pPlacaDelta;

							Semaforo pSema;

							bool pVetBotoes[QTS_BOTOES_DELTA];
							bool pVetBotoesPressionados[QTS_BOTOES_DELTA];
							bool pVetEstadoAnterior[QTS_BOTOES_DELTA];

							enum Constantes{
								TECLA_MUDA_APOSTA1  		= 0,
								TECLA_MUDA_APOSTA2			= 1, 								
								TECLA_MUDA_APOSTA3			= 4, 
								TECLA_MUDA_APOSTA4			= 5, 			
								TECLA_MUDA_APOSTA5			= 8,
								TECLA_COBRAR				= 6,
								TECLA_AJUDA					= 7, 								
								TECLA_AUTOMATICO			= 3,
								TECLA_APOSTA_MAXIMA			= 2,
								TECLA_JOGAR					= 9, 																
								TECLA_CHAVE_CONFIGURACAO	= 10,
								TECLA_CHAVE_COBRANCA		= 11,

								TECLA_SAIR					= 103 //FIXME: defnir botão 
							};

							int BotoesPlacaDelta::converteBotaoEmTecla(const Botao&) const;
							Botao BotoesPlacaDelta::converteTeclaEmBotao(int tecla) const;

						public:
							BotoesPlacaDelta::BotoesPlacaDelta(PlacaDelta& placaDelta);
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
