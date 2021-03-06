/*
 * $RCSfile: Nota.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_NOTA_H__0401FFEB_46A1_462A_B965_C67ADD7FB1C4__INCLUDED_)
#define AFX_NOTA_H__0401FFEB_46A1_462A_B965_C67ADD7FB1C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/basico/Objeto.h"
#include "biblia/util/CData.h"

using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
	namespace jogos {
		namespace superbonus {
			namespace io {
				namespace noteiro {
					class Nota : public Objeto {
						private:
							long Nota::id;
							static long Nota::idGeral;

						public:
							Nota::Nota();
							Nota::Nota(const Nota&);
							virtual ~Nota();

							// Objeto:
							virtual std::string Nota::emString() const;

							virtual bool Nota::mesmo(const Nota&) const;
					};
				}
			}
		}
	}
}

#endif // !defined(AFX_NOTA_H__0401FFEB_46A1_462A_B965_C67ADD7FB1C4__INCLUDED_)
