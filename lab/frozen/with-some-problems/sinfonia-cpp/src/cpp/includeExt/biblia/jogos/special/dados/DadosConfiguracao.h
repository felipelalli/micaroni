/*
 * $RCSfile: DadosConfiguracao.h,v $
 * $Date: 2004/06/16 00:31:30 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef SBS_DADOS_CONFIGURACAO_H
#define SBS_DADOS_CONFIGURACAO_H

#include "biblia/io/rede/util/ArqGerenciadorRedeWizard.h"
#include "biblia/io/rede/util/GerenciadorRedeWizard.h"
using namespace biblia::io::rede::util;

#include "biblia/jogos/special/dados/Dados.h"
#include "biblia/jogos/special/dados/DHistorico.h"
#include "biblia/jogos/special/dados/Dicionario.h"
#include "biblia/jogos/special/dados/DadosEmRede.h"
#include "biblia/jogos/special/dados/DConfiguracao.h"
#include "biblia/jogos/special/dados/DEstatisticaEmRede.h"
#include "biblia/jogos/special/dados/DHistoricoEmRede.h"
using namespace biblia::jogos::special::dados;

#include "biblia/jogos/special/dados/util/InterCliDadosRede.h"
using namespace biblia::jogos::special::dados::util;

#include "biblia/jogos/special/io/noteiro/Noteiro.h"
using namespace biblia::jogos::special::io::noteiro;

namespace biblia{

	namespace jogos{

		namespace special{

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

						biblia::jogos::special::dados::util::InterCliDadosRede* pDadosRede;

						void DadosConfiguracao::p_Deixar_Final_Do_IP (char* ip);

					public:
						DadosConfiguracao::DadosConfiguracao(GerenciadorRedeWizard* rede,ArqGerenciadorRedeWizard* arqRede,DHistorico* historico,Dicionario* dicionario,biblia::jogos::special::io::noteiro::Noteiro* noteiro);
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