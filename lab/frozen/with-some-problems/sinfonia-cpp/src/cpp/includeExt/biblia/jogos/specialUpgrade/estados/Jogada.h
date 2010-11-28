/*
 * $RCSfile: Jogada.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_JOGADA_H__971B3920_3170_4FD5_B773_A16B9C3E7FEE__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_JOGADA_H__971B3920_3170_4FD5_B773_A16B9C3E7FEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/fluxo/Conclusivo.h"

using namespace biblia::basico;
using namespace biblia::fluxo;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class Jogada: public Objeto {
			private:
				Conclusivo Jogada::pProgresso;
				int Jogada::pTipoJogada;
				bool Jogada::pPodeJogar;
				bool Jogada::pMaisDevagar;
				bool Jogada::pMudouNumeros;
				bool Jogada::pSaiuDaDemonstracao;
				bool Jogada::pEmEspera;

			public:
				static const int Jogada::NORMAL;
				static const int Jogada::TURBO;
				static const int Jogada::SUPER_TURBO;

				Jogada::Jogada();
				virtual Jogada::~Jogada();

				virtual int tipoJogadaAtual() const;
				virtual Jogada& mudouNumeros(bool);
				virtual bool mudouNumeros();
				virtual Jogada& tipoJogadaAtual(int);
				virtual bool podeJogar();
				virtual bool saiuDaDemonstracao() const;
				virtual Jogada& saiuDaDemonstracao(bool);
				virtual Jogada& podeJogar(bool);
				virtual Jogada& Jogada::maisDevagar(bool);
				virtual bool Jogada::maisDevagar() const;

				/**
				 * Indica que a jogada está em espera, i.e.,
				 * equivale praticamente a
				 * <code>
				 *       !this->progresso().iniciou()
				 *       || this->progresso().concluido()
				 * </code>
				 * <i>Porém esta função <b>garante</b> que não esteja
				 * entre uma jogada e outra do TURBO ou SUPER_TURBO.</i>
				 */
				virtual Jogada& Jogada::emEspera(bool);

				/**
				 * @see #emEspera(bool)
				 */
				virtual bool Jogada::emEspera() const;

				virtual const Conclusivo& Jogada::progresso() const;
				virtual Conclusivo& Jogada::progresso();
		};
	  }
	}
  }
}

#endif // !defined(AFX_JOGADA_H__971B3920_3170_4FD5_B773_A16B9C3E7FEE__INCLUDED_)
