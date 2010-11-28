/*
 * $RCSfile: DadosConfiguracao.h,v $
 * $Date: 2004/05/17 21:11:09 $
 * $Revision: 1.16 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef DADOS_CONFIGURACAO_H
#define DADOS_CONFIGURACAO_H

#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/superbonus/dados/Dados.h"
#include "biblia/jogos/superbonus/dados/DHistorico.h"
#include "biblia/jogos/superbonus/dados/Dicionario.h"
#include "biblia/jogos/superbonus/dados/DadosEmRede.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/jogos/superbonus/dados/DEstatisticaEmRede.h"
#include "biblia/jogos/superbonus/dados/DHistoricoEmRede.h"
using namespace biblia::jogos::superbonus::dados;

#include "biblia/jogos/superbonus/dados/util/InterCliDadosRede.h"
using namespace biblia::jogos::superbonus::dados::util;

#include "biblia/jogos/superbonus/io/noteiro/Noteiro.h"
using namespace biblia::jogos::superbonus::io::noteiro;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace dados{

				class DadosConfiguracao: public Objeto{

					private:
						int pMaquina;
						DConfiguracao* pConf;
						GerenciadorRedeWizard* pRede;
						ArqGerenciadorRedeWizard* pArqRede;
						DadosEmRede* pDados;
						DEstatisticaEmRede* pEstatistica;
						DHistoricoEmRede* pHistorico;
						Noteiro* pNoteiro;

						DHistorico* pHistoricoLocal;
						Dicionario* pDicionario;

						InterCliDadosRede* pDadosRede;

						void DadosConfiguracao::p_Deixar_Final_Do_IP (char* ip);

					public:
						DadosConfiguracao::DadosConfiguracao(GerenciadorRedeWizard* rede,ArqGerenciadorRedeWizard* arqRede,DHistorico* historico,Dicionario* dicionario,Noteiro* noteiro);
						DadosConfiguracao::~DadosConfiguracao();

						int  DadosConfiguracao::qtsMaquinasConectadas();
						int  DadosConfiguracao::qtsMaquinasNaRede();
						int  DadosConfiguracao::numeroMaquina (int indice);
						int  DadosConfiguracao::hubMaquina (int indice);
						bool DadosConfiguracao::maquinaLigada (int indice);
						bool DadosConfiguracao::conectada (int indice);
						int  DadosConfiguracao::indiceLocal ();

						int  DadosConfiguracao::qtsMaquinasNaRedeRemota();
						void DadosConfiguracao::trazerMaquinaDaRedeRemota (int maquina, char* ip, int* hub, bool* ligado);
						bool DadosConfiguracao::limparRede ();
						bool DadosConfiguracao::removerMaquina(int maquina);
						bool DadosConfiguracao::adicionarMaquina (int ip, int hub, bool ligado);
						bool DadosConfiguracao::concluirRede ();
						void DadosConfiguracao::mudarIPLocal (int novoIP);

						DadosConfiguracao& DadosConfiguracao::setMaquina (int indice);
						int DadosConfiguracao::getMaquina ();
						DConfiguracao& DadosConfiguracao::getDConfiguracao();
						DEstatisticaEmRede& DadosConfiguracao::getDEstatistica();
						DHistoricoEmRede& DadosConfiguracao::getDHistorico();

						DHistorico& DadosConfiguracao::getDHistoricoLocal();
						Dicionario& DadosConfiguracao::getDicionario();

						void DadosConfiguracao::mudarNoteiro (int qualNoteiro);

						bool DadosConfiguracao::ehServidor();

						ArqGerenciadorRedeWizard& DadosConfiguracao::local();
						const ArqGerenciadorRedeWizard& DadosConfiguracao::local() const;
				};
			}
		}
	}
}

#endif