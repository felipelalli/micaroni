/*
 * $RCSfile: ExecutavelGenerico.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_EXECUTAVELGENERICO_H__61895345_3388_4F7E_8DA7_94484ECDC642__INCLUDED_)
#define AFX_EXECUTAVELGENERICO_H__61895345_3388_4F7E_8DA7_94484ECDC642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/fluxo/Executavel.h"
#include "biblia/io/disco/SaidaNoDebug.h"

using namespace biblia::fluxo;
using namespace biblia::io::disco;

namespace biblia {
  namespace testador {

	class ExecutavelGenerico: public Executavel {
		private:
			SaidaNoDebug ExecutavelGenerico::pSaida;

		public:
			ExecutavelGenerico::ExecutavelGenerico();
			virtual ExecutavelGenerico::~ExecutavelGenerico();

			// Executavel:
			virtual Executavel& ExecutavelGenerico::executa();
	};
  }
}

#endif // !defined(AFX_EXECUTAVELGENERICO_H__61895345_3388_4F7E_8DA7_94484ECDC642__INCLUDED_)
