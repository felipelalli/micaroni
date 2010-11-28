/*
 * $RCSfile: LogicaBolaExtra.h,v $
 * $Date: 2004/07/13 21:13:35 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef LOGICABOLA_EXTRA_SW_H
#define LOGICABOLA_EXTRA_SW_H

#define FILA_BOLA_EXTRA_BINGO 0
#define FILA_BOLA_EXTRA_LINHA_DUPLA 1

#include "biblia/basico/Objeto.h"
#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/jogos/superbonus/logica/Premio.h"
#include "biblia/jogos/superbonus/logica/LogicaCartela.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;
using namespace biblia::jogos::superbonus::dados;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {

		class LogicaBolaExtra: public Objeto{

			private:
				static int vTableLinhaDupla[20];
				static int vTableBingo[7];

				int pPremios[4];
				int pUltimosPremios[4];

				biblia::armazenamento::volatil::Lista* pFilaDeBolasExtrasCompradasParaLinhaDupla;
				biblia::armazenamento::volatil::Lista* pFilaDeBolasExtrasCompradasParaBingo;

				int pTamanhoMaximoDaFila;

				void inicializaFila(DConfiguracao&,int qualFila);

			public:
				LogicaBolaExtra(DConfiguracao&,int tamanhoDaAmostragem=10);
				~LogicaBolaExtra();

				void colocaNaFilaDeBolasExtra(bool comprou,int qualFila);
				double percentualDeCompra(int qualFila);

				static int LogicaBolaExtra::valorBola (int aposta, int numBola,int premio,int linhasArmadas=1);

				char* LogicaBolaExtra::strFila (int qualFila);

				LogicaBolaExtra& LogicaBolaExtra::zera();
				int LogicaBolaExtra::premio(int cartela);
				LogicaBolaExtra& LogicaBolaExtra::iniciaPremios(LogicaCartela&);
				LogicaBolaExtra& LogicaBolaExtra::atualizaPremios(LogicaCartela&);

		};
	  }
	}
  }
}

#endif