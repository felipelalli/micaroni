/*
 * $RCSfile: Estatistica.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef ESTATISTICA_H
#define ESTATISTICA_H

#include "biblia/jogos/superbonus/dados/DadosXML.h"
using namespace biblia::jogos::superbonus::dados;



/* DEFINICOES EXTERNAS */

/* ESTATISTICA */
#define ZEROU_EST "Estatistica->quando_zerou"
#define NORMAL_EST "Estatistica->Normal->"
#define BOLA_EXTRA_EST "Estatistica->Bola_extra->"
#define DOBRO_EST "Estatistica->Dobro->"
	#define JOGADAS_EST "jogadas"
	#define CARTELAS_JOGADAS_EST "cartelas_jogadas"
	#define CARTELAS_PREMIADAS_EST "cartelas_premiadas"
	#define OFERECIDAS_EST "oferecidas"
	#define IDAS_EST "idas"
	#define PREMIOS_EST "Premios->"
		#define CANTOS_EST "cantos"
		#define LINHA_EST "linha"
		#define LINHA_DUPLA_EST "linha_dupla"
		#define BINGO_EST "bingo"
		#define ACUMULADO_EST "acumulado"

/* CONTABILIDADE */
#define ZEROU_CONT "Contabilidade->quando_zerou"
#define NOTAS_CONT "Contabilidade->Notas->"
	#define N1_CONT "n1"
	#define N2_CONT "n2"
	#define N5_CONT "n5"
	#define N10_CONT "n10"
	#define N50_CONT "n50"
	#define N100_CONT "n100"

#define TOTAL_CONT "Contabilidade->Total->"
	#define VALOR_APOSTADO "apostado"
	#define PAGO_CONT "pago"
	#define RECEBIDO_CONT "recebido"
	#define RETIRADO_CONT "retirado"
	#define QUANTAS_RETIRADAS_CONT "nretiradas"

/* ACUMULADO */
#define DATAS_AC "Acumulado->datas"
#define VALORES_AC "Acumulado->valores"

/* DEFINICOES INTERNAS */

// Para a montagem do diretorio: ./ano-2002/mes-3/dia-5/
#define ANO_EST "ano-"
#define MES_EST "mes-"
#define DIA_EST "dia-"
#define ARQUIVO_EST "-estatistica.xml"
#define ARQUIVO_CONT "-contabilidade.xml"
#define ARQUIVO_AC "-acumulado.xml"

//abertura dos arquivos utilizados nos relatórios de configuração
#define ARQUIVO_ESTATISTICA_PARCIAL   "estatistica-parcial.xml"
#define ARQUIVO_ESTATISTICA_GERAL     "estatistica-geral.xml"
#define ARQUIVO_CONTABILIDADE_PARCIAL "contabilidade-parcial.xml"
#define ARQUIVO_CONTABILIDADE_GERAL   "contabilidade-geral.xml"
#define ARQUIVO_ACUMULADO_GERAL       "acumulado.xml"

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace dados{

				class Estatistica: public DadosXML{


					public:

						Estatistica::Estatistica(){};
						virtual Estatistica::~Estatistica(){};

						virtual Estatistica& Estatistica::abreParcialOuGeral(const char* oQue)=0;
						virtual Estatistica& Estatistica::apagaGeral()=0;
						virtual Estatistica& Estatistica::apagaParcial()=0;

						virtual Estatistica& Estatistica::zeraTudo()=0;
				};
			}
		}
	}
}

#endif