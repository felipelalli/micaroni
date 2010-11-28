/*
 * $RCSfile: DadosConfiguracao.h,v $
 * $Date: 2005/01/19 17:21:55 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_SBS_DADOS_CONFIGURACAO_H
#define AGES_SPECIAL_UPGRADE_SBS_DADOS_CONFIGURACAO_H

#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/specialUpgrade/dados/Dados.h"
#include "biblia/jogos/specialUpgrade/dados/DHistorico.h"
#include "biblia/jogos/specialUpgrade/dados/Dicionario.h"
#include "biblia/jogos/specialUpgrade/dados/DadosEmRede.h"
#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
#include "biblia/jogos/specialUpgrade/dados/DEstatisticaEmRede.h"
#include "biblia/jogos/specialUpgrade/dados/DHistoricoEmRede.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/jogos/specialUpgrade/dados/util/InterCliDadosRede.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

#include "biblia/jogos/specialUpgrade/io/noteiro/Noteiro.h"
using namespace biblia::jogos::specialUpgrade::io::noteiro;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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

						biblia::jogos::specialUpgrade::dados::util::InterCliDadosRede* pDadosRede;

						void DadosConfiguracao::p_Deixar_Final_Do_IP (char* ip);

					public:
						DadosConfiguracao::DadosConfiguracao(GerenciadorRedeWizard* rede,ArqGerenciadorRedeWizard* arqRede,DHistorico* historico,Dicionario* dicionario,biblia::jogos::specialUpgrade::io::noteiro::Noteiro* noteiro);
						DadosConfiguracao::~DadosConfiguracao();

						int  DadosConfiguracao::qtsMaquinasConectadas();
						int  DadosConfiguracao::qtsMaquinasNaRede();
						int  DadosConfiguracao::numeroMaquina (int indice);
						int  DadosConfiguracao::hubMaquina (int indice);
						bool DadosConfiguracao::maquinaLigada (int indice);
						bool DadosConfiguracao::conectada (int indice);
						int  DadosConfiguracao::indiceLocal ();

						void DadosConfiguracao::mudarIPLocal (int novoIP);
						void DadosConfiguracao::mudarTipoRede (bool local);
						bool DadosConfiguracao::getTipoRedeLocal ();

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