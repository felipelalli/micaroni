/*
 * $RCSfile: GerenciadorMaquinaNaRede.h,v $
 * $Date: 2004/06/16 00:31:25 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef GERENCIADOR_MAQUINA_NA_REDE_SW_H
#define GERENCIADOR_MAQUINA_NA_REDE_SW_H


#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/io/rede/MaquinaNaRede.h"
using namespace biblia::io::rede;

#define MAX_HUBS 10

namespace biblia{

	namespace io{

		namespace rede{

			class GerenciadorMaquinaNaRede{

				private:
					biblia::armazenamento::volatil::Lista* pLstMaquina;

					int pMaquinasConectadasPorHub[MAX_HUBS];

				public:
					GerenciadorMaquinaNaRede::GerenciadorMaquinaNaRede();
					virtual GerenciadorMaquinaNaRede::~GerenciadorMaquinaNaRede();

					void GerenciadorMaquinaNaRede::limpar();

					void GerenciadorMaquinaNaRede::adicionarMaquina(MaquinaNaRede* maquina);
					int  GerenciadorMaquinaNaRede::qtsMaquinas();
					MaquinaNaRede* GerenciadorMaquinaNaRede::getMaquina(int indice);
					void GerenciadorMaquinaNaRede::removeMaquina (int indice);

					int GerenciadorMaquinaNaRede::qtsMaquinasConectadas();
					void GerenciadorMaquinaNaRede::qtsMaquinasConectadasPorHub (int* maquinasHub);

					GerenciadorMaquinaNaRede* GerenciadorMaquinaNaRede::trazerMaquinasSemelhantes();
					MaquinaNaRede* GerenciadorMaquinaNaRede::trazerMaquinaComMaiorSequencia();

					bool GerenciadorMaquinaNaRede::existeServidorAtivo();
					int  GerenciadorMaquinaNaRede::indiceServidorAtivo();

					int GerenciadorMaquinaNaRede::indiceMaquinaEleicao();

					bool GerenciadorMaquinaNaRede::redeValida();
			};
		}
	}
}

#endif