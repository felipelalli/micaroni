/*
 * $RCSfile: BolaExtra.h,v $
 * $Date: 2005/01/26 22:11:12 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_BOLAEXTRA_H__05EA261A_9000_48C7_9F08_6CAEEDB8F216__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_BOLAEXTRA_H__05EA261A_9000_48C7_9F08_6CAEEDB8F216__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/UltraLong.h"
//#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/io/disco/Arquivo.h"
#include "biblia/util/Debug.h"
#include "biblia/util/StrToken.h"
#include "biblia/jogos/specialUpgrade/logica/Logicas.h"
#include "biblia/jogos/specialUpgrade/dados/UltimasJogadas.h"
#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::tempo;
using namespace biblia::io::disco;
using namespace biblia::jogos::specialUpgrade::logica;
using namespace biblia::jogos::specialUpgrade::dados;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class BolaExtra: public Objeto {
			private:
				bool BolaExtra::pDeveJogarSozinho;
				bool pAutorizaJogarSozinho;
				bool BolaExtra::pPendente;
				deque<int> BolaExtra::pJogadaPendente;
				int BolaExtra::pJaJogouQuantasBolas;

				bool BolaExtra::pSim;
				bool BolaExtra::pCancelou;
				int BolaExtra::pQual;
				int BolaExtra::pPrecoAtual;
				Intervalo BolaExtra::pPiscada;
				int BolaExtra::pTocaSinoDeIgrejaCatolica;

				bool pEstaAnimando;
                bool pTocaVidro;
				bool pTocaCano;

				Arquivo BolaExtra::pArquivo;

			public:
				BolaExtra::BolaExtra(const Intervalo piscada);
				virtual BolaExtra::~BolaExtra();

                virtual BolaExtra& BolaExtra::deveConsumirSomVidro(bool sim);
                virtual bool BolaExtra::consomeSomVidro();

				virtual BolaExtra& BolaExtra::deveConsumirSomAbreCano (bool sim);
				virtual bool BolaExtra::consomeSomCano();

				virtual BolaExtra& BolaExtra::cancela();
				virtual bool BolaExtra::cancelou() const;

				virtual BolaExtra& BolaExtra::salvaEmArquivoBasico();
				virtual BolaExtra& BolaExtra::ultimaJogada(const deque<int>&);
				virtual BolaExtra& BolaExtra::terminouJogada();
				virtual BolaExtra& BolaExtra::forcaJogada(const JogadaSalva&);
				virtual const bool& BolaExtra::pendente() const;
				virtual const bool& BolaExtra::deveJogarSozinho() const;
				virtual const deque<int>& BolaExtra::jogadaPendente() const;
				virtual const int& BolaExtra::jaJogouQuantasBolas() const;

				// pra deixar jogar sozinho apenas depois que mandou girar cartelas
				BolaExtra& BolaExtra::autorizaJogarSozinho(const bool& sim);
				const bool& BolaExtra::autorizaJogarSozinho() const;

				virtual BolaExtra& BolaExtra::sim(bool);
				virtual bool BolaExtra::sim() const;
				virtual bool BolaExtra::nao() const {
					return !this->sim();
				}

				virtual const Intervalo& BolaExtra::piscada() const;
				virtual BolaExtra& BolaExtra::tocaSinoDeIgrejaCatolica();
				virtual const int BolaExtra::deveTocarSinoDeIgrejaCatolica();

				/**
				 * Vai de 0 a 5.
				 */
				virtual int BolaExtra::qual() const;
				virtual BolaExtra& BolaExtra::zera();
				virtual BolaExtra& BolaExtra::soltaUma();

				virtual BolaExtra& BolaExtra::definePreco(Logicas&);

				virtual int BolaExtra::preco() const;

				virtual bool BolaExtra::estaAnimando();

				virtual void BolaExtra::setEstaAnimando (bool estaAnimando);
		};
	  }
	}
  }
}

#endif // !defined(SBS_AFX_BOLAEXTRA_H__05EA261A_9000_48C7_9F08_6CAEEDB8F216__INCLUDED_)
