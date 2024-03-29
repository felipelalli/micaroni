/*
 * $RCSfile: DadosJogadas.h,v $
 * $Date: 2003/06/26 00:52:40 $
 * $Revision: 1.1 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SBS_DADOS_JOGADAS_H
#define SBS_DADOS_JOGADAS_H

#include "biblia/armazenamento/volatil/ListaInt.h"
using namespace biblia::armazenamento::volatil;

namespace biblia{

	namespace jogos{

		namespace special{

			namespace simulador{

				class DadosJogadas: public Objeto{

					private:

						int  pAposta;
						int  pCreditos;
						int  pCartelas;
						bool pDobro;
						int  pJogada;

						ListaInt* pLstPremios;
						ListaInt* pLstBolaExtra;

					public:
						DadosJogadas::DadosJogadas();
						DadosJogadas::~DadosJogadas();

						int  DadosJogadas::creditos();
						int  DadosJogadas::aposta();
						int  DadosJogadas::cartelas();
						bool DadosJogadas::dobro();
						int  DadosJogadas::jogada();

						int  DadosJogadas::qtsPremios();
						int  DadosJogadas::qualPremio (int qualPremio);
						bool DadosJogadas::premioBolaExtra (int qualPremio);

						void DadosJogadas::setCreditos(int creditos);
						void DadosJogadas::setAposta (int aposta);
						void DadosJogadas::setCartelas (int cartela);
						void DadosJogadas::setDobro (bool dobro);
						void DadosJogadas::setJogada (int jogada);
						void DadosJogadas::adicionarPremio (int premio, bool bolaExtra);
				};
			}
		}
	}
}

#endif