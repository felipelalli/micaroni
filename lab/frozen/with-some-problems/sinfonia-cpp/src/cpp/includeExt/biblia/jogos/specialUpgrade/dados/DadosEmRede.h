/*
 * $RCSfile: DadosEmRede.h,v $
 * $Date: 2005/01/19 17:21:55 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_DADOS_EM_REDE_H
#define AGES_SPECIAL_UPGRADE_SBS_DADOS_EM_REDE_H


#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/dados/Dados.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/jogos/specialUpgrade/dados/util/InterCliDConfiguracao.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace dados {

		class DadosEmRede: public Dados {

			private:
				int pMaquina;
				biblia::jogos::specialUpgrade::dados::util::InterCliDConfiguracao* pInterCliDConfiguracao;

			public:
				DadosEmRede::DadosEmRede(GerenciadorRede* gerenciadorRede);
				DadosEmRede::~DadosEmRede();

				virtual Dados& DadosEmRede::defineMaquina (int maquina);

				virtual bool DadosEmRede::ler(const char* caminho, char* resultado);
				virtual bool DadosEmRede::ler(const char* caminho, biblia::armazenamento::volatil::Lista* resultado){return false;};

				virtual Dados& DadosEmRede::escrever(const char* caminho, char* valor);
				virtual Dados& DadosEmRede::escrever(const char* caminho, biblia::armazenamento::volatil::Lista* valores){return *this;};

				virtual Dados& DadosEmRede::abrirArquivo(const char* nomeArquivoBasico);
		};
	  }
	}
  }
}

#endif