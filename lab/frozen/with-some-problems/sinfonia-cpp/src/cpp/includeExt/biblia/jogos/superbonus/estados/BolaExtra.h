/*
 * $RCSfile: BolaExtra.h,v $
 * $Date: 2005/01/20 21:28:59 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_BOLAEXTRA_H__05EA261A_9000_48C7_9F08_6CAEEDB8F216__INCLUDED_)
#define AFX_BOLAEXTRA_H__05EA261A_9000_48C7_9F08_6CAEEDB8F216__INCLUDED_

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
#include "biblia/jogos/superbonus/logica/Logicas.h"
#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::tempo;
using namespace biblia::io::disco;
using namespace biblia::jogos::superbonus::logica;
using namespace biblia::jogos::superbonus::dados;

namespace biblia {
  namespace jogos {
    namespace superbonus {
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

                bool pBolaExtraParaBingo;
                bool pBolaExtraParaLinhaDupla;

				Arquivo BolaExtra::pArquivo;

			public:
				BolaExtra::BolaExtra(const Intervalo piscada);
				virtual BolaExtra::~BolaExtra();

				virtual BolaExtra& BolaExtra::cancela();
				virtual bool BolaExtra::cancelou() const;

				virtual BolaExtra& BolaExtra::salvaEmArquivoBasico();
				virtual BolaExtra& BolaExtra::ultimaJogada(const std::deque<int>&);
				virtual BolaExtra& BolaExtra::terminouJogada();
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
                virtual BolaExtra& BolaExtra::verificaPremiosAConcorrer(Logicas&);

				virtual int BolaExtra::preco() const;

                virtual bool BolaExtra::bolaExtraParaBingo() const;
                virtual bool  BolaExtra::bolaExtraParaLinhaDupla() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_BOLAEXTRA_H__05EA261A_9000_48C7_9F08_6CAEEDB8F216__INCLUDED_)
