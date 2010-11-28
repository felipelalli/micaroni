/*
 * $RCSfile: BolasAndando.h,v $
 * $Date: 2005/01/13 17:09:51 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_BOLASANDANDO_H__75A97C4E_8B57_4E28_ABE5_FA2A588E4523__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_BOLASANDANDO_H__75A97C4E_8B57_4E28_ABE5_FA2A588E4523__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef AGES_SPECIAL_UPGRADE_WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#endif

#include <deque>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/fluxo/ExecutavelOtimizado.h"
#include "biblia/jogos/specialUpgrade/visual/BolaAndando.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::fluxo;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace visual {

		class BolasAndando: public ExecutavelOtimizado {
			private:
				deque<BolaAndando> BolasAndando::pBolas;
				bool BolasAndando::pAndando;
				int BolasAndando::pXFinal[4];
				int BolasAndando::pXInicial;
				int BolasAndando::pTamanhoDaBola;
				bool BolasAndando::pTodasPararam;

			public:
				BolasAndando::BolasAndando(
						int xInicial, int xFinal,
						int tamanhoDaBola);

				virtual BolasAndando::~BolasAndando();

				virtual BolasAndando& BolasAndando
						::zera();

				virtual BolasAndando& BolasAndando
						::coloca(int bola, int posicao);

				virtual BolasAndando& BolasAndando
						::anda();

				virtual const bool& BolasAndando
						::andando() const;

				virtual const bool& BolasAndando
						::todasPararam() const;

				virtual bool BolasAndando
						::temBola(const int qual) const;

				virtual const deque<BolaAndando>&
						BolasAndando::bolas() const;

				// ExecutavelOtimizado:

				virtual ExecutavelOtimizado& BolasAndando
						::executa(int quantasVezes);
		};
	  }
	}
  }
}

#endif // !defined(AFX_BOLASANDANDO_H__75A97C4E_8B57_4E28_ABE5_FA2A588E4523__INCLUDED_)
