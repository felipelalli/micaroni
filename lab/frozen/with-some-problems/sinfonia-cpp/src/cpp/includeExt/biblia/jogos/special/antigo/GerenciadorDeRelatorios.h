/*
 * $RCSfile: GerenciadorDeRelatorios.h,v $
 * $Date: 2004/06/29 22:19:10 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#include "biblia/jogos/special/antigo/ExibidorDeRelatorio.h"
#include "biblia/jogos/special/antigo/Relatorio.h"
#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/jogos/special/logica/Logicas.h"
#include "biblia/jogos/special/dados/Dicionario.h"
#include "biblia/jogos/special/io/botoes/Botoes.h"
#include "biblia/jogos/special/io/botoes/Piscador.h"
#include "biblia/jogos/special/antigo/Menu.h"
#include "biblia/jogos/special/antigo/ManipuladorDeTabela.h"
#include "biblia/jogos/special/antigo/Sistema.h"
#include "biblia/jogos/special/util/NumeroUtil.h"
#include "biblia/seguranca/Usuario.h"
#include <math.h>

using namespace biblia::jogos::special::util;
using namespace biblia::jogos::special::logica;
using namespace biblia::jogos::special::io::botoes;
using namespace biblia::armazenamento::volatil;

#ifndef SBS_GERENCIADOR_DE_RELATORIO_H_SW
#define SBS_GERENCIADOR_DE_RELATORIO_H_SW

namespace biblia{
	namespace jogos {
		namespace special {
			namespace antigo {

				#define RELATORIO_CONTABILIDADE     0
				#define RELATORIO_ESTATISTICA       1
				#define RELATORIO_DATA              2
				#define RELATORIO_HARDWARE          3
				#define RELATORIO_HISTORICO         4
				#define RELATORIO_LICENCA           5
				#define RELATORIO_IP                6
				#define RELATORIO_RESET             7
				#define RELATORIO_SOM               8
				#define RELATORIO_ACUMULADO         9
				#define RELATORIO_CONTADORES       10
				#define RELATORIO_ENVIAR_CONF      11
				#define RELATORIO_INF_SOFTWARE     12
				#define RELATORIO_CONTROLE_BOLAS   13
				#define RELATORIO_MUDAR_SENHA      14

				#define RELATORIO_HISTORICO_EVENTOS    32
				#define RELATORIO_HISTORICO_PAGAMENTOS 33
				#define RELATORIO_HISTORICO_ACUMULADOS 34
				#define RELATORIO_HISTORICO_JOGADAS    35
				#define RELATORIO_ACUMULADO_INICIO     41
				#define RELATORIO_ACUMULADO_VALOR      42

				#define SEM_INFORMACAO "?"

				class GerenciadorDeRelatorios {
					private:

						DConfiguracao& pConfiguracao;
						DEstatistica*  pEstatistica;
						Dicionario* pDicionario;
						DHistorico& pHistorico;
						Logicas& pLogicas;
						TipoUsuario& pTipoUsuario;

						int pJogadaAtual;

						Relatorio* pRelatorio;
						ExibidorDeRelatorio* pExibidor;

						biblia::armazenamento::volatil::Lista* pListaInputs;
						biblia::armazenamento::volatil::Lista* pListaLabels;
						biblia::armazenamento::volatil::Lista* pListaTabelas;
						biblia::armazenamento::volatil::Lista* pListaInputNumericos;
						biblia::armazenamento::volatil::Lista* pListaMenus;

						biblia::armazenamento::volatil::Lista* pTabelasInternas;

						TelaCompleta& pTela;
						int pInputAtual;

						int pPaginaAtual;
						int pQuantasPaginas;
						Tabela* tabelaMaior;

						int pInputAtualNaPagina;
						int pQuantosInputNaPagina;

						//libera as listas
						void reseta();

						void GerenciadorDeRelatorios::pProximoInputNumerico();
						void GerenciadorDeRelatorios::pInputNumericoAnterior();
						void GerenciadorDeRelatorios::pProximoInput();
						void GerenciadorDeRelatorios::pInputAnterior();
						void GerenciadorDeRelatorios::pProximoCaracter();
						void GerenciadorDeRelatorios::pCaracterAnterior();

						double GerenciadorDeRelatorios::pLeValoresContabilidade(
								const char* arquivo,
								const char* oQue,
								const char* condicao);

						double GerenciadorDeRelatorios::pLeValoresEstatistica(
  								const char* arquivo,
								const char* oQue,
								const char* condicao);

						const char* GerenciadorDeRelatorios::pConverteInteiroParaString(long valor);
						const char* GerenciadorDeRelatorios
								::pConverteRealParaString(double valor, bool dinheiro = false);

						void pAdicionaLabelNumaTabela(int linha, int coluna, Tabela& tabela,Label* label);
						void pAdicionaInputNumaTabela(int linha, int coluna, Tabela& tabela,Input* input);
						void pAdicionaInputNumericoNumaTabela(int linha, int coluna, Tabela& tabela,InputNumerico* input);

						void GerenciadorDeRelatorios
								::pAdicionaMenuNumaTabela(
										int linha, int coluna,
										Tabela& tabela, Menu* menu);

						void pMontaTabelasInternasHistoricoEventos();
						void pMontaTabelasInternasHistoricoPagamentos();
						void pMontaTabelasInternasHistoricoAcumulados();

						/*rotinas os relatório de contabilidade*/
						void pExibeValoresRelatorioContabilidade(Tabela&, int coluna,char* arquivo);
						void pMontaRelatorioContabilidade();
						void pMontaRelatorioSoftware();
						void pMontaRelatorioContadores();
						void pMontaRelatorioBolas();
						void pAtualizaRelatorioBolas();

						/*rotinas do relatório de estatística*/
						void pExibeEstatisticaPremios(int l,int c,Tabela&,long qtdePremio,long totalPremios);
						void pExibeValoresRelatorioEstatistica(Tabela&,int coluna,char* arquivo);
						void pMontaRelatorioEstatistica();

						void pMontaRelatorioSom();
						void pMontaRelatorioData();
						void pModificaSom();
						void pAtualizaData();
						void pMontaRelatorioHardware();
						void pAtualizaStatusHardware();
						void pMontaRelatorioReset();
						void pMontaRelatorioEnviarConf();
						void pMontaRelatorioIp();
						void pMontaRelatorioListaIP();
						void pMontaRelatorioHistoricoPagamentos();
						void pMontaRelatorioHistoricoEventos();
						void pMontaRelatorioHistoricoAcumulados();
						void pMontaRelatorioHistorico();
						void pMontaRelatorioAcumuladoInicio();
						void pMontaRelatorioAcumuladoValor();
						void pMontaRelatorioAcumulado();
						void pMontaPaginaAtual();

						void semUltimasJogadas();

						void pProximaPagina();
						void pPaginaAnterior();

						void pMontaPaginasDeIP();
						bool pModificaIP();
						void pModificaConfiguracoesIP();
						void pModificaData();
						bool pModificaHardware();
						void pMontaRelatorioMudaSenha();
						void pMontaRelatorioMudaSenhaMaster();
						void pRetiraCaracterSenha();
						void pColocaCaracterSenha();
						void pMudaSenha();
						void pMudaSenhaMaster();

						void pEnviaRede();
						void pEnviaSom();
						void pEnviaAcumulado();
						void pEnviaBolas();
						void pEnviaData();
						void pEnviaUsuarios();

						bool pTeclado;
						Marcacao& pFundo;

						void pCopiaStatusPlaca(char* destino, bool porta);
						void pCopiaStatusDisplay(char* destino, bool porta);
						void pCopiaStatusLeitor(char* destino, bool porta);
						void pCopiaMensagemLeitor(char* destino);

					public:
						GerenciadorDeRelatorios(
								TelaCompleta& tela,
								MensagemBmp& fonte,
								MensagemBmp& fonteEscolhida,
								MensagemBmp& fonteNegrito,
								MensagemBmp& fonteTitulo,
								MensagemBmp& fontePequena,
								Marcacao& fundo,
								Logicas& logicas,
								DHistorico& historico,
								TipoUsuario& usuario,
								bool teclado = false);

						~GerenciadorDeRelatorios();

						void executa(int qualRelatorio, Botoes&, Piscador&);
				};
			}
		}
	}
}
#endif
