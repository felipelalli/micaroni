/*
 * $RCSfile: DadosEmRede.h,v $
 * $Date: 2004/06/16 00:31:30 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef SBS_DADOS_EM_REDE_H
#define SBS_DADOS_EM_REDE_H


#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/jogos/special/dados/Dados.h"
using namespace biblia::jogos::special::dados;

#include "biblia/jogos/special/dados/util/InterCliDConfiguracao.h"
using namespace biblia::jogos::special::dados::util;

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace dados {

		class DadosEmRede: public Dados {

			private:
				int pMaquina;
				biblia::jogos::special::dados::util::InterCliDConfiguracao* pInterCliDConfiguracao;

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