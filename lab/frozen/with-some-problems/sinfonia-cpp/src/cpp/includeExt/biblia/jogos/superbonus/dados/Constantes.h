/*
 * $RCSfile: Constantes.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef CONSTANTES_SW_H
#define CONSTANTES_SW_H

//#define DADOS_EM_OUTRA_PARTICAO

namespace biblia {
	namespace jogos {
		namespace superbonus {
			namespace dados {

				#define SEPARADOR_TOKEN "->"

#ifndef DADOS_EM_OUTRA_PARTICAO

				#define ARQ_ACUMULADO_SERVIDOR "dat/acumuladoServidor.dat"
				#define ARQ_ACUMULADO_CLIENTE  "dat/acumuladoCliente.dat"
				#define ARQ_LEITOR_NOTAS       "dat/leitorNotas.dat"
				#define ARQ_CARTELAS           "dat/cartelas.dat"
				#define ARQ_CONTADOR           "dat/contador.dat"
				#define ARQ_CREDITO_ATUAL      "dat/creditoAtual.dat"
				#define ARQ_DOBRO		       "dat/dobro.dat"
				#define ARQ_PREMIOS_INVALIDOS  "dat/premiosInvalidos.dat"
				#define ARQ_SAFE               "dat/safe.dat"
				#define ARQ_CONTADORES_VLT     "dat/contadoresVLT.dat"

				#define ARQ_ULTIMAS_JOGADAS "./dat/ultimasJogadas.dat"
				#define ARQ_PREMIOS_DEVIDOS "./dat/premiosDevidos.dat"
				#define ARQ_LOCK "./dat/Lock.dat"
				#define ARQ_LICENCA "./dat/licenca.dat"
				#define ARQ_USUARIO "dat/usuarios.dat"
				#define ARQ_INFO_GERENCIADOR_REDE "dat/InfoGerenciadorRede.dat"
				#define ARQ_COBRANCA "dat/cobranca.dat"
				#define ARQ_CONF_GERENCIADOR_REDE "dat/ConfGerenciadorRede.dat"
				#define ARQ_LOGICA_ACUMULADO "dat/LogicaAcumulado.dat"
				#define ARQ_LOGICA_ACUMULADO_CLIENTE "dat/LogicaAcumuladoCliente.dat"
				#define ARQ_PROBABILIDADES "dat/probabilidades/Probabilidades.dat"
				#define ARQ_LEITOR_NOTAS "dat/leitorNotas.dat"
				#define ARQ_BOLA_EXTRA "dat/bolaExtra.dat"

				#define XML_HISTORICO "xml/Historico.xml"
				#define XML_DICIONARIO "xml/Dicionario.xml"
				#define ARQ_CONFIGURACAO_XML "./xml/Configuracao.xml"

				#define ARQUIVO_SCRIPT "/home/bingo/scripts/mudarIP"

				#define SCRIPT_SALVAR_HISTORICO "/home/bingo/scripts/salvarHistorico"
				#define SCRIPT_RESTAURAR_HISTORICO "/home/bingo/scripts/restaurarHistorico"

				#define ARQUIVO_SCRIPT_DATA "/home/bingo/scripts/mudarData"

				#define ARQ_MAC_ADDRESS "macaddress.txt"

				#define ARQ_DEBUG "debug.txt"

#else

				#define ARQ_ACUMULADO_SERVIDOR "/dados/dat/acumuladoServidor.dat"
				#define ARQ_ACUMULADO_CLIENTE  "/dados/dat/acumuladoCliente.dat"
				#define ARQ_LEITOR_NOTAS       "/dados/dat/leitorNotas.dat"
				#define ARQ_CARTELAS           "/dados/dat/cartelas.dat"
				#define ARQ_CONTADOR           "/dados/dat/contador.dat"
				#define ARQ_CREDITO_ATUAL      "/dados/dat/creditoAtual.dat"
				#define ARQ_DOBRO		       "/dados/dat/dobro.dat"
				#define ARQ_PREMIOS_INVALIDOS  "/dados/dat/premiosInvalidos.dat"
				#define ARQ_SAFE               "/dados/dat/safe.dat"
				#define ARQ_CONTADORES_VLT     "/dados/dat/contadoresVLT.dat"

				#define ARQ_ULTIMAS_JOGADAS "/dados/dat/ultimasJogadas.dat"
				#define ARQ_PREMIOS_DEVIDOS "/dados/dat/premiosDevidos.dat"
				#define ARQ_LOCK "/dados/dat/Lock.dat"
				#define ARQ_LICENCA "/dados/dat/licenca.dat"
				#define ARQ_USUARIO "/dados/dat/usuarios.dat"
				#define ARQ_INFO_GERENCIADOR_REDE "/dados/dat/InfoGerenciadorRede.dat"
				#define ARQ_COBRANCA "/dados/dat/cobranca.dat"
				#define ARQ_CONF_GERENCIADOR_REDE "/dados/dat/ConfGerenciadorRede.dat"
				#define ARQ_LOGICA_ACUMULADO "/dados/dat/LogicaAcumulado.dat"
				#define ARQ_LOGICA_ACUMULADO_CLIENTE "/dados/dat/LogicaAcumuladoCliente.dat"
				#define ARQ_PROBABILIDADES "/dados/dat/probabilidades/Probabilidades.dat"
				#define ARQ_LEITOR_NOTAS "/dados/dat/leitorNotas.dat"
				#define ARQ_BOLA_EXTRA "/dados/dat/bolaExtra.dat"

				#define XML_HISTORICO "/dados/xml/Historico.xml"
				#define XML_DICIONARIO "/dados/xml/Dicionario.xml"
				#define ARQ_CONFIGURACAO_XML "/dados/xml/Configuracao.xml"

				#define ARQUIVO_SCRIPT "/dados/scripts/mudarIP"

				#define SCRIPT_SALVAR_HISTORICO "/dados/scripts/salvarHistorico"
				#define SCRIPT_RESTAURAR_HISTORICO "/dados/scripts/restaurarHistorico"

				#define ARQUIVO_SCRIPT_DATA "/dados/scripts/mudarData"

				#define ARQ_MAC_ADDRESS "/dados/macaddress.txt"

				#define ARQ_DEBUG "/dados/debug.txt"
#endif
				#define SLEEP_THREAD_ACUMULADO 10

			}
		}
	}
}

#endif