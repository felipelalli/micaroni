/*
 * $RCSfile: MilionesimoDeSegundo.h,v $
 * $Date: 2004/02/26 18:57:32 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_MILIONESIMODESEGUNDO_H__A6AD2DCF_2934_4CDD_8B7E_508BAD21AB40__INCLUDED_)
#define AFX_MILIONESIMODESEGUNDO_H__A6AD2DCF_2934_4CDD_8B7E_508BAD21AB40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/tempo/UnidadeDeTempo.h"

namespace biblia {
  namespace tempo {
  	namespace unidades {
		class MilionesimoDeSegundo: public UnidadeDeTempo {
			public:
				MilionesimoDeSegundo::MilionesimoDeSegundo();
				virtual MilionesimoDeSegundo::~MilionesimoDeSegundo();
		};
	}
  }
}

#endif // !defined(AFX_MILIONESIMODESEGUNDO_H__A6AD2DCF_2934_4CDD_8B7E_508BAD21AB40__INCLUDED_)
