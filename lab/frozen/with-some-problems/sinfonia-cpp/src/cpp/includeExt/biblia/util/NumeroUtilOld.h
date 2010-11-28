/*
 * $RCSfile: NumeroUtilOld.h,v $
 * $Date: 2005/01/20 21:29:31 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(SBS_AFX_NUMEROUTIL_OLD_H__AB813702_3DF1_4DED_AB93_06B63BC1EE40__INCLUDED_)
#define SBS_AFX_NUMEROUTIL_OLD_H__AB813702_3DF1_4DED_AB93_06B63BC1EE40__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/util/StrToken.h"
#include "biblia/util/CData.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
  namespace util {
	class NumeroUtilOld: public Objeto {
		protected:
			NumeroUtilOld::NumeroUtilOld();
			virtual NumeroUtilOld::~NumeroUtilOld();

		public:
			static const char* NumeroUtilOld::ponto(long numero);
			static const char* NumeroUtilOld::ponto(double numero);
			static const char* NumeroUtilOld::numeroEmLetras(long numero);
			static const char* NumeroUtilOld::numeroEmCodigo(double numero);
			static std::string NumeroUtilOld::dataEmString(const CData&);
	};
  }
}

#endif // !defined(SBS_AFX_NUMEROUTIL_OLD_H__AB813702_3DF1_4DED_AB93_06B63BC1EE40__INCLUDED_)
