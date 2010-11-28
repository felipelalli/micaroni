/*
 * $RCSfile: DadosEmRede.h,v $
 * $Date: 2004/07/13 21:13:33 $
 * $Revision: 1.9 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef DADOS_EM_REDE_H
#define DADOS_EM_REDE_H


#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/jogos/superbonus/dados/Dados.h"
using namespace biblia::jogos::superbonus::dados;

#include "biblia/jogos/superbonus/dados/util/InterCliDConfiguracao.h"
using namespace biblia::jogos::superbonus::dados::util;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class DadosEmRede: public Dados {

			private:
				int pMaquina;
				InterCliDConfiguracao* pInterCliDConfiguracao;

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