/*
 * $RCSfile: Piscador.h,v $
 * $Date: 2005/01/19 17:22:06 $
 * $Revision: 1.3 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_PISCADOR_H
#define AGES_SPECIAL_UPGRADE_SBS_PISCADOR_H

#include "biblia/armazenamento/volatil/Lista.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/jogos/specialUpgrade/io/botoes/Botoes.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;

#include "biblia/jogos/specialUpgrade/io/botoes/LuzBotoes.h"
using namespace biblia::jogos::specialUpgrade::io::botoes;

#include "biblia/fluxo/Thread.h"
#include "biblia/fluxo/Semaforo.h"
#include "biblia/fluxo/Executavel.h"
using namespace biblia::fluxo;

namespace biblia{

	namespace jogos{

		namespace specialUpgrade{

			namespace io{

				namespace botoes{

					class Piscador: public Executavel{

						protected:

							biblia::armazenamento::volatil::Lista* pLstPiscando;
							biblia::armazenamento::volatil::Lista* pLstAceso;
							biblia::armazenamento::volatil::Lista* pLstApagado;

							Semaforo*  pSema;

							virtual void Piscador::pTirarLstPiscando(const Botao& botao);
							virtual void Piscador::pTirarLstAceso(const Botao& botao);
							virtual void Piscador::pTirarLstApagado(const Botao& botao);
							virtual void Piscador::pTirarLst (biblia::armazenamento::volatil::Lista* lst, const Botao& botao);

							virtual bool Piscador::pExisteLstPisca(const Botao& botao);
							virtual bool Piscador::pExisteLstAceso(const Botao& botao);
							virtual bool Piscador::pExisteLstApaga(const Botao& botao);
							virtual bool Piscador::pExisteLst (biblia::armazenamento::volatil::Lista* lst, const Botao& botao);

							virtual biblia::armazenamento::volatil::Lista* Piscador::pCopiaLstPisca();
							virtual biblia::armazenamento::volatil::Lista* Piscador::pCopiaLstAceso();
							virtual biblia::armazenamento::volatil::Lista* Piscador::pCopiaLstApagado();

						public:
							Piscador::Piscador ();
							virtual Piscador::~Piscador();

							virtual void Piscador::apagarTodos();
							virtual void Piscador::piscar (const Botao& botao);
							virtual void Piscador::acender(const Botao& botao);
							virtual void Piscador::apagar (const Botao& botao);

							virtual bool Piscador::piscando (const Botao& botao);
							virtual bool Piscador::aceso(const Botao& botao);
							virtual bool Piscador::apagado (const Botao& botao);

							virtual Executavel& Piscador::executa()=0;
					};
				}
			}
		}
	}
}

#endif