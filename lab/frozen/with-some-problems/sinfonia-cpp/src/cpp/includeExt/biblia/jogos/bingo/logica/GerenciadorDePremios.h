/*
 * $RCSfile: GerenciadorDePremios.h,v $
 * $Date: 2004/06/16 00:31:26 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef GERENCIADOR_DE_PREMIOS_H
#define GERENCIADOR_DE_PREMIOS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/bingo/logica/util/Cartela.h"
#include "biblia/jogos/bingo/logica/util/EventosCartela.h"
#include "biblia/jogos/bingo/logica/util/CarregadorDePremios.h"
using namespace biblia::jogos::bingo::logica::util;

#include "biblia/jogos/bingo/logica/LogicaCartelas.h"
using namespace biblia::jogos::bingo::logica;


#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{
	
	namespace jogos{

		namespace bingo{
		
			namespace logica{	

				class LogicaCartelas;

				class GerenciadorDePremios: public Objeto{
					
					private:
						CarregadorDePremios pCarregador;						

					public:
						GerenciadorDePremios::GerenciadorDePremios();
						GerenciadorDePremios::~GerenciadorDePremios();

						CarregadorDePremios& GerenciadorDePremios::getCarregador();

						void GerenciadorDePremios::atualizaCartela(Cartela& cartela, LogicaCartelas& logicaCartelas, bool bolaExtra, bool concorreAcumulado, int qtsNumerosMarcados);

						void GerenciadorDePremios::gerarListaDePremios (biblia::jogos::bingo::logica::util::Premio& premioNaCartela, biblia::armazenamento::volatil::Lista& pLstPremios, biblia::armazenamento::volatil::Lista& pLstFaltaUm, bool bolaExtra,bool concorreAcumulado, int qtsNumerosMarcados);
						void GerenciadorDePremios::filtrarListaDePremios (biblia::armazenamento::volatil::Lista& pLstPremios);						
						void GerenciadorDePremios::filtrarListaDeFaltaUm (biblia::armazenamento::volatil::Lista& pLstFaltaUm, biblia::armazenamento::volatil::Lista& pLstPremios);

				};
			}
		}
	}
}
#endif
