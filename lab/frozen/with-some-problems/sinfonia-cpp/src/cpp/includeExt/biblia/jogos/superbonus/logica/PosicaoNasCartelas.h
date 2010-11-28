/*
 * $RCSfile: PosicaoNasCartelas.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_POSICAONASCARTELAS_H__B96CC182_D216_42A7_9DE7_1BD45D6DC320__INCLUDED_)
#define AFX_POSICAONASCARTELAS_H__B96CC182_D216_42A7_9DE7_1BD45D6DC320__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
	namespace jogos {
		namespace superbonus {
			namespace logica {
				class PosicaoNasCartelas: public Objeto {
					private :
						int pCartela;
						int pLinha;
						int pColuna;
					public:
						PosicaoNasCartelas(int, int, int);
						PosicaoNasCartelas(const PosicaoNasCartelas&);
						~PosicaoNasCartelas();

						int PosicaoNasCartelas::cartela() const;
						int PosicaoNasCartelas::linha() const;
						int PosicaoNasCartelas::coluna() const;

						bool PosicaoNasCartelas::operator==(const PosicaoNasCartelas&) const;
						bool PosicaoNasCartelas::operator!=(const PosicaoNasCartelas&) const;

						// Objeto:
						virtual std::string PosicaoNasCartelas::emString() const;
				};
			}
		}
	}
}
#endif