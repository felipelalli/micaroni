/*
 * $RCSfile: Bonus.h,v $
 * $Date: 2004/05/17 21:14:33 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AFX_BONUS_H__CC2A01A9_105B_418D_98FA_F5136487D51B__INCLUDED_)
#define AFX_BONUS_H__CC2A01A9_105B_418D_98FA_F5136487D51B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/tempo/Intervalo.h"

using namespace biblia::basico;
using namespace biblia::tempo;

#include "biblia/io/disco/Arquivo.h"
using namespace biblia::io::disco;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace estados {

		class Bonus: public Objeto {
			private:
				Intervalo Bonus::pPiscada;
				Intervalo Bonus::pAnimacao2x;
				int Bonus::pJogadasGratis;
				bool Bonus::pAceso;
				bool Bonus::pDeveLancar2x;
				void Bonus::pSalvarEmArquivoBasico();
				bool Bonus::pEstaNoDobro;

				Arquivo pArquivo;

			public:
				Bonus::Bonus(const Intervalo piscada,
							 const Intervalo animacao2x);

				virtual Bonus::~Bonus();

				virtual const Intervalo& Bonus::piscada() const;
				virtual const Intervalo& Bonus::animacao2x() const;

				virtual Bonus& Bonus::pisca();
				virtual Bonus& Bonus::acende(bool sim = true);
				virtual const bool& Bonus::aceso() const;
				virtual const bool Bonus::apagado() const {
					return !this->aceso();
				}

				virtual bool Bonus::consomeDeveLancar2x();

				virtual Bonus& Bonus::lanca2x();
				virtual Bonus& Bonus::jogadasGratis(int quantas);
				virtual Bonus& Bonus::maisJogadasGratis(bool demonstracao,int quantas = 2);
				virtual Bonus& Bonus::menosJogadasGratis(bool demonstracao,int quantas = 1);
				virtual const int& Bonus::jogadasGratis() const;
				virtual bool Bonus::estaNoDobro ();
				virtual Bonus& Bonus::setEstaNoDobro(bool dobro);
		};
	  }
	}
  }
}

#endif // !defined(AFX_BONUS_H__CC2A01A9_105B_418D_98FA_F5136487D51B__INCLUDED_)
