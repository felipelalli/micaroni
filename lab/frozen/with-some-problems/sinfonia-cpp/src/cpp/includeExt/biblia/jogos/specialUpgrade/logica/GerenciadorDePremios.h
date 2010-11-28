/*
 * $RCSfile: GerenciadorDePremios.h,v $
 * $Date: 2005/01/19 17:22:11 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#ifndef AGES_SPECIAL_UPGRADE_GERENCIADOR_DE_PREMIOS_H
#define AGES_SPECIAL_UPGRADE_GERENCIADOR_DE_PREMIOS_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/jogos/specialUpgrade/logica/util/Cartela.h"
#include "biblia/jogos/specialUpgrade/logica/util/EventosCartela.h"
#include "biblia/jogos/specialUpgrade/logica/util/CarregadorDePremios.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/LogicaCartelas.h"
using namespace biblia::jogos::specialUpgrade::logica;


#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

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

						void GerenciadorDePremios::gerarListaDePremios (biblia::jogos::specialUpgrade::logica::util::Premio& premioNaCartela, biblia::armazenamento::volatil::Lista& pLstPremios, biblia::armazenamento::volatil::Lista& pLstFaltaUm, bool bolaExtra,bool concorreAcumulado, int qtsNumerosMarcados);
						void GerenciadorDePremios::filtrarListaDePremios (biblia::armazenamento::volatil::Lista& pLstPremios);
						void GerenciadorDePremios::filtrarListaDeFaltaUm (biblia::armazenamento::volatil::Lista& pLstFaltaUm, biblia::armazenamento::volatil::Lista& pLstPremios);

				};
			}
		}
	}
}
#endif
