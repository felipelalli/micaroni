/*
 * $RCSfile: TempoGlobalAllegro.h,v $
 * $Date: 2003/06/10 19:16:53 $
 * $Revision: 1.8 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TEMPOGLOBALALLEGRO_H__037FA2E6_0DBD_4CDA_87C1_7ED141B55A48__INCLUDED_)
#define AFX_TEMPOGLOBALALLEGRO_H__037FA2E6_0DBD_4CDA_87C1_7ED141B55A48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <exception>
#include <typeinfo>
#include "biblia/basico/Objeto.h"
#include "biblia/mais/allegro/Allegro.h"
#include "biblia/mais/allegro/AllegroExcecao.h"
#include "biblia/tempo/TempoGlobal.h"
#include "biblia/tempo/UnidadeDeTempo.h"
#include "biblia/tempo/TempoExcecao.h"

using namespace biblia::basico;
using namespace biblia::tempo;

namespace biblia {
 namespace mais {
   namespace allegro {

	    void cronometro_global_allegro(void* tempoGlobal);

		class TempoGlobalAllegro: public TempoGlobal, Objeto {
			private:
				UnidadeDeTempo TempoGlobalAllegro::pUnidade;
				double TempoGlobalAllegro::pVezes;
				UltraLong TempoGlobalAllegro::pMomento;
				bool TempoGlobalAllegro::pPausado;
				const long TempoGlobalAllegro::pId;

				static long TempoGlobalAllegro::pIdGlobal;

			protected:
				long TempoGlobalAllegro::id() const;
				virtual TempoGlobalAllegro& TempoGlobalAllegro
						::instalaCronometros();

			public:
				TempoGlobalAllegro::TempoGlobalAllegro(
						const UnidadeDeTempo&);

				virtual TempoGlobalAllegro::~TempoGlobalAllegro();

				/* Características específicas de TempoGlobalAllegro. */

				virtual TempoGlobalAllegro& TempoGlobalAllegro::reset();
				virtual TempoGlobalAllegro& TempoGlobalAllegro::pause();
				virtual bool TempoGlobalAllegro::pausado() const;
				virtual TempoGlobalAllegro& TempoGlobalAllegro::play();

				/* Características comuns de TempoGlobal. */

				virtual TempoGlobal& TempoGlobalAllegro
						::reinicia();

				virtual TempoGlobal& TempoGlobalAllegro
						::acelerado(const double& vezes);

				virtual const double& TempoGlobalAllegro
						::acelerado() const;

				virtual TempoGlobal& TempoGlobalAllegro::proximoPasso();

				/* UniversoDeTempo */

				virtual Momento TempoGlobalAllegro::agora() const;
				virtual const UnidadeDeTempo&
						TempoGlobalAllegro::cadaPasso() const;

				virtual bool TempoGlobalAllegro::mesmoUniversoDeTempo(
						const UniversoDeTempo&) const;
		};
   }
 }
}

#endif // !defined(AFX_TEMPOGLOBALALLEGRO_H__037FA2E6_0DBD_4CDA_87C1_7ED141B55A48__INCLUDED_)
