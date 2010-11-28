/*
 * $RCSfile: Constantes.h,v $
 * $Date: 2005/01/19 17:21:54 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_CONSTANTES_SW_H
#define AGES_SPECIAL_UPGRADE_SBS_CONSTANTES_SW_H

//#define AGES_SPECIAL_UPGRADE_DADOS_EM_OUTRA_PARTICAO

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace dados {

				#define AGES_SPECIAL_UPGRADE_SEPARADOR_TOKEN "->"

#ifndef AGES_SPECIAL_UPGRADE_DADOS_EM_OUTRA_PARTICAO

				#define AGES_SPECIAL_UPGRADE_ARQ_ACUMULADO_SERVIDOR "dat/acumuladoServidor.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_ACUMULADO_CLIENTE  "dat/acumuladoCliente.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LEITOR_NOTAS       "dat/leitorNotas.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CARTELAS           "dat/cartelas.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CONTADOR           "dat/contador.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CREDITO_ATUAL      "dat/creditoAtual.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_DOBRO		       "dat/dobro.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_PREMIOS_INVALIDOS  "dat/premiosInvalidos.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_SAFE               "dat/safe.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CONTADORES_VLT     "dat/contadoresVLT.dat"

				#define AGES_SPECIAL_UPGRADE_ARQ_ULTIMAS_JOGADAS "./dat/ultimasJogadas.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_PREMIOS_DEVIDOS "./dat/premiosDevidos.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LOCK "./dat/Lock.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LICENCA "./dat/licenca.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_USUARIO "dat/usuarios.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_INFO_GERENCIADOR_REDE "dat/InfoGerenciadorRede.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_COBRANCA "dat/cobranca.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CONF_GERENCIADOR_REDE "dat/ConfGerenciadorRede.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LOGICA_ACUMULADO "dat/LogicaAcumulado.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LOGICA_ACUMULADO_CLIENTE "dat/LogicaAcumuladoCliente.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_PROBABILIDADES "dat/probabilidades/Probabilidades.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LEITOR_NOTAS "dat/leitorNotas.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_BOLA_EXTRA "dat/bolaExtra.dat"

				#define AGES_SPECIAL_UPGRADE_XML_HISTORICO "xml/Historico.xml"
				#define AGES_SPECIAL_UPGRADE_XML_DICIONARIO "xml/Dicionario.xml"
				#define AGES_SPECIAL_UPGRADE_ARQ_CONFIGURACAO_XML "./xml/Configuracao.xml"

				#define AGES_SPECIAL_UPGRADE_ARQUIVO_SCRIPT "/home/specialUpgrade/scripts/mudarIP"

				#define AGES_SPECIAL_UPGRADE_SCRIPT_SALVAR_HISTORICO "/home/specialUpgrade/scripts/salvarHistorico"
				#define AGES_SPECIAL_UPGRADE_SCRIPT_RESTAURAR_HISTORICO "/home/specialUpgrade/scripts/restaurarHistorico"

				#define AGES_SPECIAL_UPGRADE_ARQUIVO_SCRIPT_DATA "/home/specialUpgrade/scripts/mudarData"

				#define AGES_SPECIAL_UPGRADE_ARQ_MAC_ADDRESS "macaddress.txt"

				#define AGES_SPECIAL_UPGRADE_ARQ_DEBUG "debug.txt"

#else

				#define AGES_SPECIAL_UPGRADE_ARQ_ACUMULADO_SERVIDOR "/dados/dat/acumuladoServidor.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_ACUMULADO_CLIENTE  "/dados/dat/acumuladoCliente.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LEITOR_NOTAS       "/dados/dat/leitorNotas.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CARTELAS           "/dados/dat/cartelas.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CONTADOR           "/dados/dat/contador.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CREDITO_ATUAL      "/dados/dat/creditoAtual.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_DOBRO		       "/dados/dat/dobro.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_PREMIOS_INVALIDOS  "/dados/dat/premiosInvalidos.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_SAFE               "/dados/dat/safe.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CONTADORES_VLT     "/dados/dat/contadoresVLT.dat"

				#define AGES_SPECIAL_UPGRADE_ARQ_ULTIMAS_JOGADAS "/dados/dat/ultimasJogadas.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_PREMIOS_DEVIDOS "/dados/dat/premiosDevidos.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LOCK "/dados/dat/Lock.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LICENCA "/dados/dat/licenca.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_USUARIO "/dados/dat/usuarios.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_INFO_GERENCIADOR_REDE "/dados/dat/InfoGerenciadorRede.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_COBRANCA "/dados/dat/cobranca.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_CONF_GERENCIADOR_REDE "/dados/dat/ConfGerenciadorRede.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LOGICA_ACUMULADO "/dados/dat/LogicaAcumulado.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LOGICA_ACUMULADO_CLIENTE "/dados/dat/LogicaAcumuladoCliente.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_PROBABILIDADES "/dados/dat/probabilidades/Probabilidades.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_LEITOR_NOTAS "/dados/dat/leitorNotas.dat"
				#define AGES_SPECIAL_UPGRADE_ARQ_BOLA_EXTRA "/dados/dat/bolaExtra.dat"

				#define AGES_SPECIAL_UPGRADE_XML_HISTORICO "/dados/xml/Historico.xml"
				#define AGES_SPECIAL_UPGRADE_XML_DICIONARIO "/dados/xml/Dicionario.xml"
				#define AGES_SPECIAL_UPGRADE_ARQ_CONFIGURACAO_XML "/dados/xml/Configuracao.xml"

				#define AGES_SPECIAL_UPGRADE_ARQUIVO_SCRIPT "/dados/scripts/mudarIP"

				#define AGES_SPECIAL_UPGRADE_SCRIPT_SALVAR_HISTORICO "/dados/scripts/salvarHistorico"
				#define AGES_SPECIAL_UPGRADE_SCRIPT_RESTAURAR_HISTORICO "/dados/scripts/restaurarHistorico"

				#define AGES_SPECIAL_UPGRADE_ARQUIVO_SCRIPT_DATA "/dados/scripts/mudarData"

				#define AGES_SPECIAL_UPGRADE_ARQ_MAC_ADDRESS "/dados/macaddress.txt"

				#define AGES_SPECIAL_UPGRADE_ARQ_DEBUG "/dados/debug.txt"
#endif
				#define AGES_SPECIAL_UPGRADE_SLEEP_THREAD_ACUMULADO 10

				#define AGES_SPECIAL_UPGRADE_CANTOS_ID 1
				#define AGES_SPECIAL_UPGRADE_LINHA_ID 2
				#define AGES_SPECIAL_UPGRADE_CRUZ_PEQUENA_ID 3
				#define AGES_SPECIAL_UPGRADE_T_ID 4
				#define AGES_SPECIAL_UPGRADE_CRUZ_GRANDE_ID 5
				#define AGES_SPECIAL_UPGRADE_QUADRADO_ID 6
				#define AGES_SPECIAL_UPGRADE_LINHA_DUPLA_ID 7
				#define AGES_SPECIAL_UPGRADE_U_ID 8
				#define AGES_SPECIAL_UPGRADE_PERIMETRO_ID 9
				#define AGES_SPECIAL_UPGRADE_BINGO_ID 10
				#define AGES_SPECIAL_UPGRADE_ACUMULADO_ID 11

			}
		}
	}
}

#endif