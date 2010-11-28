/*
 * $RCSfile: Estados.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_ESTADOS_H__9DA23105_1155_413E_A16E_BE50453C9292__INCLUDED_)
#define AFX_ESTADOS_H__9DA23105_1155_413E_A16E_BE50453C9292__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/unidades/Segundo.h"
#include "biblia/tempo/unidades/Milissegundo.h"
#include "biblia/jogos/superbonus/estados/BolaExtra.h"
#include "biblia/jogos/superbonus/estados/Bolas.h"
#include "biblia/jogos/superbonus/estados/Bolona.h"
#include "biblia/jogos/superbonus/estados/Bonus.h"
#include "biblia/jogos/superbonus/estados/Cartelas.h"
#include "biblia/jogos/superbonus/estados/Cobranca.h"
#include "biblia/jogos/superbonus/estados/ConcorreAcumulado.h"
#include "biblia/jogos/superbonus/estados/Jogada.h"
#include "biblia/jogos/superbonus/estados/PlacaDePremios.h"
#include "biblia/jogos/superbonus/estados/TelaAtual.h"
#include "biblia/jogos/superbonus/estados/VisorCreditos.h"
#include "biblia/jogos/superbonus/estados/VisorMensagem.h"
#include "biblia/jogos/superbonus/estados/VisorTitulo.h"
#include "biblia/jogos/superbonus/estados/Ajuda.h"
#include "biblia/jogos/superbonus/estados/Acumulado.h"
#include "biblia/jogos/superbonus/estados/Configuracao.h"

using namespace biblia::basico;
using namespace biblia::tempo;
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace estados {

		/**
		 * Une todos os estados do jogo
		 * nesta classe.
		 */
		class Estados: public Objeto {
			private:
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

				bool Estados::pTerminaJogo;

			public:
				Estados::Estados();
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
		};
	  }
	}
  }
}

#endif // !defined(AFX_ESTADOS_H__9DA23105_1155_413E_A16E_BE50453C9292__INCLUDED_)
