/*
 * $RCSfile: DadosEstatisticaEmRede.h,v $
 * $Date: 2004/07/13 21:13:33 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef DADOS_ESTATISTICA_EM_REDE_H
#define DADOS_ESTATISTICA_EM_REDE_H


#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/jogos/superbonus/dados/Dados.h"
using namespace biblia::jogos::superbonus::dados;

#include "biblia/jogos/superbonus/dados/util/InterCliDEstatistica.h"
using namespace biblia::jogos::superbonus::dados::util;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class DadosEstatisticaEmRede: public Dados {

			private:
				int pMaquina;
				InterCliDEstatistica* pInterCliDEstatistica;

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