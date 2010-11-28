/*
 * $RCSfile: BolaExtra.h,v $
 * $Date: 2005/01/20 21:28:54 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(SBS_AFX_BOLAEXTRA_H__05EA261A_9000_48C7_9F08_6CAEEDB8F216__INCLUDED_)
#define SBS_AFX_BOLAEXTRA_H__05EA261A_9000_48C7_9F08_6CAEEDB8F216__INCLUDED_

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
#include "biblia/jogos/special/logica/Logicas.h"
#include "biblia/jogos/special/dados/UltimasJogadas.h"
#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::tempo;
using namespace biblia::io::disco;
using namespace biblia::jogos::special::logica;
using namespace biblia::jogos::special::dados;

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace estados {

		class BolaExtra: public Objeto {
			private:
				bool BolaExtra::pDeveJogarSozinho;
				bool BolaExtra::pPendente;
				std::deque<int> BolaExtra::pJogadaPendente;
				int BolaExtra::pJaJogouQuantasBolas;

				bool BolaExtra::pSim;
				bool BolaExtra::pCancelou;
				int BolaExtra::pQual;
				int BolaExtra::pPrecoAtual;
				Intervalo BolaExtra::pPiscada;
				int BolaExtra::pTocaSinoDeIgrejaCatolica;

				bool pEstaAnimando;
                bool pTocaVidro;

				Arquivo BolaExtra::pArquivo;

			public:
				BolaExtra::BolaExtra(const Intervalo piscada);
				virtual BolaExtra::~BolaExtra();

                virtual BolaExtra& BolaExtra::deveConsumirSomVidro(bool sim);
                virtual bool BolaExtra::consomeSomVidro();

				virtual BolaExtra& BolaExtra::cancela();
				virtual bool BolaExtra::cancelou() const;

				virtual BolaExtra& BolaExtra::salvaEmArquivoBasico();
				virtual BolaExtra& BolaExtra::ultimaJogada(const std::deque<int>&);
				virtual BolaExtra& BolaExtra::terminouJogada();
				virtual BolaExtra& BolaExtra::forcaJogada(const JogadaSalva&);
				virtual const bool& BolaExtra::pendente() const;
				virtual const bool& BolaExtra::deveJogarSozinho() const;
				virtual const std::deque<int>& BolaExtra::jogadaPendente() const;
				virtual const int& BolaExtra::jaJogouQuantasBolas() const;

				virtual BolaExtra& BolaExtra::sim(bool);
				virtual bool BolaExtra::sim() const;
				virtual bool BolaExtra::nao() const {
					return !this->sim();
				}

				virtual const Intervalo& BolaExtra::piscada() const;
				virtual BolaExtra& BolaExtra::tocaSinoDeIgrejaCatolica();
				virtual const int BolaExtra::deveTocarSinoDeIgrejaCatolica();

				/**
				 * Vai de 0 a 2.
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
