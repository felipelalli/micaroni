/*
 * $RCSfile: ResultadoSonoro.h,v $
 * $Date: 2005/01/20 21:28:45 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_RESULTADOSONORO_H__49A0D38F_ADAE_40DF_BC25_78B370040C91__INCLUDED_)
#define AFX_RESULTADOSONORO_H__49A0D38F_ADAE_40DF_BC25_78B370040C91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/io/som/ComponenteSonoro.h"
#include "biblia/io/som/SomExcecao.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
  namespace io {
    namespace som {

		class ResultadoSonoro: public Objeto {
			private:
				std::deque<ComponenteSonoro> ResultadoSonoro
						::pSonsATocar;

				bool ResultadoSonoro::pParaTudo;

			public:
				ResultadoSonoro::ResultadoSonoro();
				virtual ResultadoSonoro::~ResultadoSonoro();

				/**
				 * Adiciona na fila de sons esse som.
				 */
				virtual ResultadoSonoro& ResultadoSonoro
						::toca(ComponenteSonoro);

				virtual ResultadoSonoro& ResultadoSonoro
						::toca(ComponenteSonoro, bool); //

				virtual ResultadoSonoro& ResultadoSonoro
						::paraTudo();

				virtual bool ResultadoSonoro
						::consomeDevePararTudo();

				virtual bool ResultadoSonoro::haSom() const;
				virtual ComponenteSonoro ResultadoSonoro
						::consomeSom();
		};
	}
  }
}

#endif // !defined(AFX_RESULTADOSONORO_H__49A0D38F_ADAE_40DF_BC25_78B370040C91__INCLUDED_)
