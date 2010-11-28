/*
 * $RCSfile: VisorTitulo.h,v $
 * $Date: 2005/01/26 22:11:12 $
 * $Revision: 1.3 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: cvsroot $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_VISORTITULO_H__FF4EB80C_1EB4_47E3_9E47_7F44ECCD5E66__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_VISORTITULO_H__FF4EB80C_1EB4_47E3_9E47_7F44ECCD5E66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"

using namespace biblia::basico;
using namespace biblia::tempo;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class VisorTitulo: public Objeto {
			private:
				bool VisorTitulo::pDobro;
				bool VisorTitulo::pBingo;
				bool VisorTitulo::pLinhaDupla;
				bool VisorTitulo::pU;
				bool VisorTitulo::pPerimetro;
				bool VisorTitulo::pBolaExtra;
				bool VisorTitulo::pPrimeiraJogadaNoDobro;
				bool pTemSomTocando;
				bool pDeveExibirProximasJogadasGratis;
				Intervalo VisorTitulo::pAnimacaoOnda;
                Intervalo VisorTitulo::pAnimacaoBingo;

			public:
				VisorTitulo::VisorTitulo(
						const Intervalo intervaloAnimacaoOnda,
                        const Intervalo intervaloAnimacaoBingo);

				virtual VisorTitulo::~VisorTitulo();

				virtual VisorTitulo& VisorTitulo::bolaExtra(bool sim);
				virtual VisorTitulo& VisorTitulo::dobro(bool sim);
				virtual VisorTitulo& VisorTitulo::acumulado(bool sim);
                virtual VisorTitulo& VisorTitulo::bingo(bool sim);
				virtual VisorTitulo& VisorTitulo::linhaDupla(bool sim);
				virtual VisorTitulo& VisorTitulo::u(bool sim);
				virtual VisorTitulo& VisorTitulo::temSomTocando(bool sim);
				virtual VisorTitulo& VisorTitulo::perimetro(bool sim);
				virtual VisorTitulo& VisorTitulo::deveExibirProximasJogadasGratis(bool sim);
				virtual VisorTitulo& VisorTitulo::apagaPremios();

				virtual VisorTitulo& VisorTitulo
						::primeiraJogadaNoDobro(bool sim);

				virtual bool VisorTitulo::dobro() const;
				virtual bool VisorTitulo::acumulado() const;

				virtual const Intervalo& VisorTitulo
						::intervaloAnimacaoOnda() const;

                virtual const Intervalo& VisorTitulo
						::intervaloAnimacaoBingo() const;

                virtual bool VisorTitulo::bingo() const;
				virtual bool VisorTitulo::linhaDupla() const;
				virtual bool VisorTitulo::u() const;
				virtual bool VisorTitulo::perimetro() const;
				virtual bool VisorTitulo::temSomTocando() const;
				virtual bool VisorTitulo::deveExibirProximasJogadasGratis() const;

				virtual bool VisorTitulo::bolaExtra() const;
				virtual bool VisorTitulo::primeiraJogadaNoDobro() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_VISORTITULO_H__FF4EB80C_1EB4_47E3_9E47_7F44ECCD5E66__INCLUDED_)
