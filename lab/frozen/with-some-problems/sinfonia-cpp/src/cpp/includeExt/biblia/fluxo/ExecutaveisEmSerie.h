/*
 * $RCSfile: ExecutaveisEmSerie.h,v $
 * $Date: 2005/01/20 21:28:42 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_EXECUTAVEISEMSERIE_H__74593DD6_48B1_4C32_902F_683A6789D50D__INCLUDED_)
#define AFX_EXECUTAVEISEMSERIE_H__74593DD6_48B1_4C32_902F_683A6789D50D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include "biblia/fluxo/Executavel.h"
#include "biblia/util/Debug.h"

using namespace std;
using namespace biblia::util;

namespace biblia {
  namespace fluxo {

	/**
	 * Executa vários {@link biblia::fluxo::Executavel
	 * executáveis} em série. Pode ser muito útil para
	 * executáveis que necessitam de constante atualização.
	 */
	class ExecutaveisEmSerie: public Executavel {
		private:
			std::deque<Executavel*> ExecutaveisEmSerie::pExecutaveis;

		public:
			ExecutaveisEmSerie::ExecutaveisEmSerie();
			virtual ExecutaveisEmSerie::~ExecutaveisEmSerie();
			virtual ExecutaveisEmSerie& ExecutaveisEmSerie
					::adiciona(Executavel&);

			// Executavel:
			Executavel& ExecutaveisEmSerie::executa();
	};
  }
}

#endif // !defined(AFX_EXECUTAVEISEMSERIE_H__74593DD6_48B1_4C32_902F_683A6789D50D__INCLUDED_)
