/*
 * $RCSfile: Circulo.h,v $
 * $Date: 2003/05/29 21:08:20 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CIRCULO_H__CC66858D_A9DA_4381_AE6E_12A0EBBBD58F__INCLUDED_)
#define AFX_CIRCULO_H__CC66858D_A9DA_4381_AE6E_12A0EBBBD58F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Geometrico.h"
#include "biblia/visual/Raio.h"
#include "biblia/visual/Ponto.h"
#include "biblia/visual/Cor.h"
#include "biblia/visual/Area.h"
#include "biblia/visual/cores/Vermelho.h"

using namespace biblia::visual;

namespace biblia {
  namespace visual {
	namespace geometricos {

		class Circulo: public Geometrico {

			private:
				Raio Circulo::pRaio;

			public:
				Circulo::Circulo(const Circulo&);
				Circulo::Circulo(
						const Ponto& centro,
						const Raio& raio,
						Cor = cores::Vermelho(),
						bool preenchido = false);

				virtual Circulo::~Circulo();
				virtual const Raio& Circulo::raio() const;
				virtual const Circulo& Circulo::raio(const Raio&);

				virtual Circulo& Circulo::operator=(const Circulo&);

				/**
				 * Não compara a cor e nem se está preenchido.
				 */
				virtual bool Circulo::operator==(const Circulo&) const;
				virtual Area Circulo::areaQueOcupa() const;

				virtual std::string Circulo::emString() const;
		};
	}
  }
}

#endif // !defined(AFX_CIRCULO_H__CC66858D_A9DA_4381_AE6E_12A0EBBBD58F__INCLUDED_)
