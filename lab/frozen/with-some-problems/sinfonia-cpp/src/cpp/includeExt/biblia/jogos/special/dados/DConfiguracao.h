/*
 * $RCSfile: DConfiguracao.h,v $
 * $Date: 2003/10/28 15:59:30 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#include "biblia/basico/Objeto.h"
#include "biblia/util/StrToken.h"
#include "biblia/jogos/special/dados/DadosXML.h"
#include "biblia/jogos/special/dados/Dados.h"

using namespace biblia::basico;
using namespace biblia::util;

#ifndef SBS_DCONFIGURACAO_SW_H
#define SBS_DCONFIGURACAO_SW_H

// Definicoes usadas externamente


//Hardware
#define QUAL_LEITOR_CFG  "Configuracao->Hardware->Leitor->tipo"
#define PORTA_LEITOR_CFG  "Configuracao->Hardware->Leitor->porta"
#define PORTA_DISPLAY_CFG "Configuracao->Hardware->Display->porta"

//Caminhos dos arquivos de configuracao no XML
#define ARQUIVO_ESTATISTICA_CFG             "Configuracao->Arquivos->Estatistica->normal"
#define ARQUIVO_ESTATISTICA_SIMULADO_CFG    "Configuracao->Arquivos->Estatistica->simulado"

//configuracoes de rede
#define IP_CFG       "Configuracao->Rede->ip"
#define PORTA_CFG    "Configuracao->Rede->porta"
#define IP_REDE_CFG  "Configuracao->Rede->Maquinas->ip"
#define IP_ON_CFG    "Configuracao->Rede->Maquinas->on"
#define IP_HUB_CFG   "Configuracao->Rede->Maquinas->hub"
#define TIME_OUT_CFG "Configuracao->Rede->timeout"

//configuracoes de acumulado
#define VALOR_INICIAL_CFG          "Configuracao->Acumulado->valor_inicial_fixo"
#define NOVO_VALOR_INICIAL_CFG     "Configuracao->Acumulado->novo_valor_inicial"
#define VALOR_INICIAL_ATUAL_CFG    "Configuracao->Acumulado->valor_inicial_atual"
#define NAO_CONCORRENDO_CFG        "Configuracao->Acumulado->nao_concorrendo"
#define CONCORRENDO_CFG            "Configuracao->Acumulado->concorrendo"
#define VALOR_MAXIMO_ACUMULADO_CFG "Configuracao->Acumulado->valor_maximo"

//caminhos das probabilidades
#define PROBABILIDADE_NORMAL_CFG "Configuracao->Probabilidade->normal"
#define PROBABILIDADE_DOBRO_CFG  "Configuracao->Probabilidade->dobro"
#define PRENCHIMENTO_CFG         "Configuracao->Probabilidade->preenchimento"

//idem, porém na tela de demonstração
#define DEMONSTRACAO_NORMAL_CFG    "Configuracao->Probabilidade_Demonstracao->normal"
#define DEMONSTRACAO_DOBRO_CFG     "Configuracao->Probabilidade_Demonstracao->dobro"

//prêmios
#define PREMIO_CANTOS_CFG       "->cantos"
#define PREMIO_LINHA_CFG        "->linha"
#define PREMIO_LINHA_DUPLA_CFG  "->linha_dupla"
#define PREMIO_BINGO_CFG        "->bingo"
#define PREMIO_ACUMULADO_CFG    "->acumulado"

#define PREMIO_LINHA_DUPLA_EXTRA_CFG   "->bolaExtra->premiar_linha_dupla"
#define PREMIO_BINGO_EXTRA_CFG         "->bolaExtra->premiar_bingo"

#define PROBABILIDADE_BOLA_EXTRA_LINHA_DUPLA_CFG  "->bolaExtra->linha_dupla"
#define PROBABILIDADE_BOLA_EXTRA_LINHA_DUPLA2_CFG "->bolaExtra->linha_dupla2"
#define PROBABILIDADE_BOLA_EXTRA_BINGO_CFG "->bolaExtra->bingo"
#define PROBABILIDADE_FALTA_UM_PARA_LINHA_CFG "->bolaExtra->linha"

#define PROBABILIDADE_ACEITAR_BOLA_EXTRA_LINHA_DUPLA "->bolaExtra->aceitar_linha_dupla"
#define PROBABILIDADE_ACEITAR_BOLA_EXTRA_BINGO       "->bolaExtra->aceitar_bingo"

#define PORCENTAGEM_PAGAMENTO_NORMAL "Configuracao->Probabilidade->porc_normal"
#define PORCENTAGEM_PAGAMENTO_DOBRO  "Configuracao->Probabilidade->porc_dobro"

//som
#define SOM_VOLUME_BOLAS_CFG          "Configuracao->Som->Volume->bolas"
#define SOM_VOLUME_BOLA_EXTRA_CFG     "Configuracao->Som->Volume->bola_extra"
#define SOM_VOLUME_LINHA_CFG          "Configuracao->Som->Volume->linha"
#define SOM_VOLUME_LINHA_DUPLA_CFG    "Configuracao->Som->Volume->linha_dupla"
#define SOM_VOLUME_BINGO_CFG          "Configuracao->Som->Volume->bingo"
#define SOM_VOLUME_ACUMULADO_CFG      "Configuracao->Som->Volume->acumulado"
#define SOM_VOLUME_DOBRO_CFG          "Configuracao->Som->Volume->dobro"
#define SOM_VOLUME_QUATRO_CANTOS_CFG  "Configuracao->Som->Volume->quatro_cantos"
#define SOM_VOLUME_CARTELA_CFG		  "Configuracao->Som->Volume->cartela"
#define SOM_VOLUME_CREDITO_CFG		  "Configuracao->Som->Volume->creditos"
#define SOM_VOLUME_BOLAS_BATENDO_CFG  "Configuracao->Som->Volume->bolas_batendo"
#define SOM_VOLUME_APOSTA_CFG         "Configuracao->Som->Volume->aposta"
#define SOM_VOLUME_BOLAS_DA_EXTRA_CFG "Configuracao->Som->Volume->bolas_da_extra"
#define SOM_VOLUME_DOBRO_INICIO_CFG   "Configuracao->Som->Volume->dobro_inicio"
#define SOM_VOLUME_NUMERO_CFG         "Configuracao->Som->Volume->numeros"
#define SOM_VOLUME_GERAL_CFG          "Configuracao->Som->Volume->geral"
#define SOM_VOLUME_FALTA_UM_CFG       "Configuracao->Som->Volume->falta_um"
#define SOM_VOLUME_CRED_INSUF_CFG     "Configuracao->Som->Volume->creditos_insuficientes"
#define SOM_VOLUME_TRILHA_CFG         "Configuracao->Som->Volume->trilha"
#define SOM_VOLUME_ALARMES            "Configuracao->Som->Volume->alarme"

// novos sons, do SPECIAL (em ordem alfabética):
#define SOM_VOLUME_AJUDA_CFG "Configuracao->Som->Volume->ajuda"
#define SOM_VOLUME_COBRANCA_CFG "Configuracao->Som->Volume->cobranca"
#define SOM_VOLUME_CRUZ_GRANDE_CFG "Configuracao->Som->Volume->cruzGrande"
#define SOM_VOLUME_CRUZ_PEQUENA_CFG "Configuracao->Som->Volume->cruzPequena"
#define SOM_VOLUME_FLASH_CFG "Configuracao->Som->Volume->flash"
#define SOM_VOLUME_PERIMETRO_CFG "Configuracao->Som->Volume->perimetro"
#define SOM_VOLUME_QUADRADO_CFG "Configuracao->Som->Volume->quadrado"
#define SOM_VOLUME_T_CFG "Configuracao->Som->Volume->t"
#define SOM_VOLUME_U_CFG "Configuracao->Som->Volume->u"
#define SOM_VOLUME_VIDRO_BOLA_EXTRA_CFG "Configuracao->Som->Volume->vidroBolaExtra"

#define MODO_DE_FILAR        "Configuracao->Bolas->modo_filar"
#define BOLA_VELOCIDADE_CFG  "Configuracao->Bolas->velocidade"

//tipos de filada
#define MODO_ORIGINAL 0
#define MODO_MR       1

//intervalos de tempo
#define TEMPO_MODO_AUTOMATICO_CFG  "Configuracao->Tempo->modo_automatico"
#define TEMPO_ACUMULADO_CFG        "Configuracao->Tempo->acumulado"
#define TEMPO_JOGANDO_SOZINHO_CFG  "Configuracao->Tempo->jogando_sozinho"
#define TEMPO_AJUDA_CFG            "Configuracao->Tempo->ajuda"
#define TEMPO_MAXIMO_FILA_CFG      "Configuracao->Tempo->bola_filada"
#define TEMPO_TRILHA_SILENCIO_CFG  "Configuracao->Tempo->silencio_trilha"

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace dados {

		class DConfiguracao: public DadosXML {

			private:
				Dados* DConfiguracao::pDados;

				char pVersao[200];
				char pData[200];

			public:
				DConfiguracao::DConfiguracao(
						const char* arqConfiguracao,
						const char* versao,
						const char* data);

				DConfiguracao::~DConfiguracao();

				DConfiguracao& DConfiguracao::simulacao(bool estahSimulando);

				DConfiguracao& DConfiguracao::defineDados(Dados* dados);

				DConfiguracao& DConfiguracao::voltaDados();

				const char* DConfiguracao::versao() {
					static char v[200];
					strcpy(v, this->pVersao);
					return v;
				}

				const char* DConfiguracao::data() {
					static char d[200];
					strcpy(d, this->pData);
					return d;
				}
		};
	  }
	}
  }
}

#endif
