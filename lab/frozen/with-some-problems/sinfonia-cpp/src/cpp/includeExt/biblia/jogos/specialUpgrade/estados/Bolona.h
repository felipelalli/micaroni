/*
 * $RCSfile: Bolona.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_BOLONA_H__640D9EC2_1854_4E67_9BA9_4082AA488EC0__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_BOLONA_H__640D9EC2_1854_4E67_9BA9_4082AA488EC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/tempo/Intervalo.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::tempo;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class Bolona: public Objeto {
			private:
				int Bolona::pBolaAtual;
				Intervalo Bolona::pAnimacao;
				bool Bolona::pAnimando;
                double Bolona::pVelocidade;

			public:
				Bolona::Bolona(const Intervalo animacao);
				virtual Bolona::~Bolona();

				/**
				 * Vai de 1 a x
				 * ou -1 quando não tem bola
				 * atual.
				 */
				virtual const int& Bolona::bolaAtual() const;

				virtual Bolona& Bolona::zera();
				virtual Bolona& Bolona::lancaBola(const int qual);
				virtual Intervalo Bolona::intervaloAnimacao() const;
				virtual bool Bolona::acabouDeAnimar() const;
				virtual Bolona& Bolona::animando(bool);
                virtual Bolona& Bolona::velocidade(double);
		};
	  }
	}
  }
}

#endif // !defined(AFX_BOLONA_H__640D9EC2_1854_4E67_9BA9_4082AA488EC0__INCLUDED_)
