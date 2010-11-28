/*
 * $RCSfile: NumeroUtil.h,v $
 * $Date: 2005/01/20 21:29:01 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_NUMEROUTIL_H__AB813702_3DF1_4DED_AB93_06B63BC1EE40__INCLUDED_)
#define AFX_NUMEROUTIL_H__AB813702_3DF1_4DED_AB93_06B63BC1EE40__INCLUDED_

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
  namespace jogos {
    namespace superbonus {
	  namespace util {

		class NumeroUtil: public Objeto {
			protected:
				NumeroUtil();
				virtual ~NumeroUtil();

			public:
				static const char* NumeroUtil::ponto(long numero);
				static const char* NumeroUtil::ponto(double numero);

				static const char* NumeroUtil::
						numeroEmLetras(long numero);

				static const char* NumeroUtil::
						numeroEmCodigo(double numero);

				static std::string NumeroUtil::
						dataEmString(const CData&);
		};
	  }
	}
  }
}

#endif // !defined(AFX_NUMEROUTIL_H__AB813702_3DF1_4DED_AB93_06B63BC1EE40__INCLUDED_)
