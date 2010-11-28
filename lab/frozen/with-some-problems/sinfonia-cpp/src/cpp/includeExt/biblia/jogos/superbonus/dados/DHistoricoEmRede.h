/*
 * $RCSfile: DHistoricoEmRede.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef DHISTORICO_EM_REDE_H
#define DHISTORICO_EM_REDE_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/superbonus/dados/util/InterCliHistorico.h"
using namespace biblia::jogos::superbonus::dados::util;

#include "biblia/io/rede/GerenciadorRede.h"
using namespace biblia::io::rede;

#include "biblia/armazenamento/volatil/ListaString.h"
using namespace biblia::armazenamento::volatil;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace dados{

				class DHistoricoEmRede : public Objeto{

					private:

						InterCliHistorico* pInterCliHistorico;

						int p_Qual_Maquina;
						int p_Qual_Historico;
						int p_Quantas_Linhas;
						int p_Quantas_Linhas_Por_Pagina;
						int p_Quantas_Paginas;
						int p_Pagina_Atual;

						ListaString* p_Lista_Linhas_Da_Pagina;

					public:

						DHistoricoEmRede::DHistoricoEmRede (GerenciadorRede* gerenciadorRede);
						DHistoricoEmRede::~DHistoricoEmRede();

						void         DHistoricoEmRede::define_Maquina                   (int qual_maquina);
						void         DHistoricoEmRede::define_Quantas_Linhas_Por_Pagina (int quantas_linhas);
						int          DHistoricoEmRede::traz_Quantas_Linhas_Por_Pagina   (){return this->p_Quantas_Linhas_Por_Pagina;};
						void         DHistoricoEmRede::define_Historico                 (int qual_historico);
						int          DHistoricoEmRede::traz_Historico                   (){return this->p_Qual_Historico;};
						int          DHistoricoEmRede::quantas_Paginas                  ();
						ListaString* DHistoricoEmRede::pagina                           (int qual_Pagina);
						int          DHistoricoEmRede::paginaAtual ();

						bool DHistoricoEmRede::adicionaEvento (long codigoEvento, const char* usuario = "-", const char* descricao = "-");
				};
			}
		}
	}
}

#endif