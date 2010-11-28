/*
 * $RCSfile: DadosEstatisticaEmRede.h,v $
 * $Date: 2005/01/19 17:21:55 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_DADOS_ESTATISTICA_EM_REDE_H
#define AGES_SPECIAL_UPGRADE_SBS_DADOS_ESTATISTICA_EM_REDE_H


#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/jogos/specialUpgrade/dados/Dados.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/jogos/specialUpgrade/dados/util/InterCliDEstatistica.h"
using namespace biblia::jogos::specialUpgrade::dados::util;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace dados {

		class DadosEstatisticaEmRede: public Dados {

			private:
				int pMaquina;
				biblia::jogos::specialUpgrade::dados::util::InterCliDEstatistica* pInterCliDEstatistica;

			public:
				DadosEstatisticaEmRede::DadosEstatisticaEmRede(GerenciadorRede* gerenciadorRede);
				DadosEstatisticaEmRede::~DadosEstatisticaEmRede();

				virtual Dados& DadosEstatisticaEmRede::defineMaquina (int maquina);

				virtual bool DadosEstatisticaEmRede::ler(const char* caminho, char* resultado);
				virtual bool DadosEstatisticaEmRede::ler(const char* caminho, biblia::armazenamento::volatil::Lista* resultado){return false;};

				virtual Dados& DadosEstatisticaEmRede::escrever(const char* caminho, char* valor);
				virtual Dados& DadosEstatisticaEmRede::escrever(const char* caminho, biblia::armazenamento::volatil::Lista* valores){return *this;};

				virtual Dados& DadosEstatisticaEmRede::abrirArquivoBasico(const char* nomeArquivoBasico);

				virtual DadosEstatisticaEmRede& DadosEstatisticaEmRede::apagaGeral();
				virtual DadosEstatisticaEmRede& DadosEstatisticaEmRede::apagaParcial();

				virtual DadosEstatisticaEmRede& DadosEstatisticaEmRede::zeraTudo();

				virtual Dados& DadosEstatisticaEmRede::abrirArquivo(const char* arquivo){return *this;};
		};
	  }
	}
  }
}

#endif