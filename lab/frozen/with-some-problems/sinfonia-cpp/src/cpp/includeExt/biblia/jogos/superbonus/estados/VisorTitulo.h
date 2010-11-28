/*
 * $RCSfile: VisorTitulo.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_VISORTITULO_H__FF4EB80C_1EB4_47E3_9E47_7F44ECCD5E66__INCLUDED_)
#define AFX_VISORTITULO_H__FF4EB80C_1EB4_47E3_9E47_7F44ECCD5E66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"

using namespace biblia::basico;
using namespace biblia::tempo;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace estados {

		class VisorTitulo: public Objeto {
			private:
				bool VisorTitulo::pDobro;
				bool VisorTitulo::pBingo;
				bool VisorTitulo::pBolaExtra;
				bool VisorTitulo::pPrimeiraJogadaNoDobro;
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
				virtual VisorTitulo& VisorTitulo
						::primeiraJogadaNoDobro(bool sim);

				virtual bool VisorTitulo::dobro() const;
				virtual bool VisorTitulo::acumulado() const;

				virtual const Intervalo& VisorTitulo
						::intervaloAnimacaoOnda() const;

                virtual const Intervalo& VisorTitulo
						::intervaloAnimacaoBingo() const;

                virtual bool VisorTitulo::bingo() const;
				virtual bool VisorTitulo::bolaExtra() const;
				virtual bool VisorTitulo::primeiraJogadaNoDobro() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_VISORTITULO_H__FF4EB80C_1EB4_47E3_9E47_7F44ECCD5E66__INCLUDED_)
