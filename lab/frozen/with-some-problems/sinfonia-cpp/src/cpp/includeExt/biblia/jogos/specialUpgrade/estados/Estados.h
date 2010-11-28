/*
 * $RCSfile: Estados.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_ESTADOS_H__9DA23105_1155_413E_A16E_BE50453C9292__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_ESTADOS_H__9DA23105_1155_413E_A16E_BE50453C9292__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/jogos/specialUpgrade/estados/BolaExtra.h"
#include "biblia/jogos/specialUpgrade/estados/Bolas.h"
#include "biblia/jogos/specialUpgrade/estados/Bolona.h"
#include "biblia/jogos/specialUpgrade/estados/Bonus.h"
#include "biblia/jogos/specialUpgrade/estados/Cartelas.h"
#include "biblia/jogos/specialUpgrade/estados/Cobranca.h"
#include "biblia/jogos/specialUpgrade/estados/ConcorreAcumulado.h"
#include "biblia/jogos/specialUpgrade/estados/Jogada.h"
#include "biblia/jogos/specialUpgrade/estados/PlacaDePremios.h"
#include "biblia/jogos/specialUpgrade/estados/TelaAtual.h"
#include "biblia/jogos/specialUpgrade/estados/VisorCreditos.h"
#include "biblia/jogos/specialUpgrade/estados/VisorMensagem.h"
#include "biblia/jogos/specialUpgrade/estados/VisorTitulo.h"
#include "biblia/jogos/specialUpgrade/estados/Ajuda.h"
#include "biblia/jogos/specialUpgrade/estados/Acumulado.h"
#include "biblia/jogos/specialUpgrade/estados/Configuracao.h"
#include "biblia/jogos/specialUpgrade/estados/Simulador.h"

using namespace biblia::basico;
using namespace biblia::tempo;
using namespace biblia::tempo::unidades;

#include "biblia/util/Versao.h"
using namespace biblia::util;

#include "biblia/jogos/specialUpgrade/logica/LogicaCartelas.h"
using namespace biblia::jogos::specialUpgrade::logica;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		/**
		 * Une todos os estados do jogo
		 * nesta classe.
		 */
		class Estados: public Objeto {
			private:
				Versao Estados::pVersao;
				BolaExtra Estados::pBolaExtra;
				Bolas Estados::pBolas;
				Bolona Estados::pBolona;
				Bonus Estados::pBonus;
				Cartelas Estados::pCartelas;
				Cobranca Estados::pCobranca;
				ConcorreAcumulado Estados::pConcorreAcumulado;
				Jogada Estados::pJogada;
				PlacaDePremios Estados::pPlacaDePremios;
				TelaAtual Estados::pTelaAtual;
				VisorCreditos Estados::pVisorCreditos;
				VisorMensagem Estados::pVisorMensagem;
				VisorTitulo Estados::pVisorTitulo;
                Ajuda Estados::pAjuda;
				Acumulado Estados::pAcumulado;
				Configuracao Estados::pConfiguracao;
				Simulador Estados::pSimulador;

				bool Estados::pTerminaJogo;

			public:
				Estados::Estados(UniversoDeTempo& universoDeTempo);
				virtual Estados::~Estados();

				virtual BolaExtra& Estados::bolaExtra();
				virtual Bolas& Estados::bolas();
				virtual Bolona& Estados::bolona();
				virtual Bonus& Estados::bonus();
				virtual Cartelas& Estados::cartelas();
				virtual Cobranca& Estados::cobranca();
				virtual ConcorreAcumulado& Estados::concorreAcumulado();
				virtual Jogada& Estados::jogada();
				virtual PlacaDePremios& Estados::placaDePremios();
				virtual TelaAtual& Estados::telaAtual();
				virtual VisorCreditos& Estados::visorCreditos();
				virtual VisorMensagem& Estados::visorMensagem();
				virtual VisorTitulo& Estados::visorTitulo();
                virtual Ajuda& Estados::ajuda();
				virtual Acumulado& Estados::acumulado();
				virtual Configuracao& Estados::configuracao();
				virtual Simulador& Estados::simulador();
				virtual Versao& Estados::versao();

                virtual Estados& Estados::terminaJogo(bool);

				virtual const BolaExtra& Estados::bolaExtra() const;
				virtual const Bolas& Estados::bolas() const;
				virtual const Bolona& Estados::bolona() const;
				virtual const Bonus& Estados::bonus() const;
				virtual const Cartelas& Estados::cartelas() const;
				virtual const Cobranca& Estados::cobranca() const;
				virtual const ConcorreAcumulado& Estados::concorreAcumulado() const;
				virtual const Jogada& Estados::jogada() const;
				virtual const PlacaDePremios& Estados::placaDePremios() const;
				virtual const TelaAtual& Estados::telaAtual() const;
				virtual const VisorCreditos& Estados::visorCreditos() const;
				virtual const VisorMensagem& Estados::visorMensagem() const;
				virtual const VisorTitulo& Estados::visorTitulo() const;
                virtual const Ajuda& Estados::ajuda() const;
				virtual const Acumulado& Estados::acumulado() const;
				virtual const bool& Estados::terminaJogo() const;
				virtual const Configuracao& Estados::configuracao() const;
				virtual const Simulador& Estados::simulador() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_ESTADOS_H__9DA23105_1155_413E_A16E_BE50453C9292__INCLUDED_)
