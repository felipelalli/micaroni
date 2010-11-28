/*
 * $RCSfile: Botao.h,v $
 * $Date: 2003/05/29 21:03:14 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_BOTAO_H__43612D3D_5301_4AFC_8281_567244435D27__INCLUDED_)
#define AFX_BOTAO_H__43612D3D_5301_4AFC_8281_567244435D27__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "biblia/basico/Objeto.h"
#include "biblia/util/CData.h"

using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
	namespace jogos {
		namespace superbonus {
			namespace io {
				namespace botoes {
					class Botao : public Objeto {
						private:
							long Botao::id;
							static long Botao::idGeral;

						public:
							Botao::Botao();
							Botao::Botao(const Botao&);
							virtual ~Botao();

							// Objeto:
							virtual std::string Botao::emString() const;

							virtual bool Botao::mesmo(const Botao&) const;
					};
				}
			}
		}
	}
}
#endif // !defined(AFX_BOTAO_H__43612D3D_5301_4AFC_8281_567244435D27__INCLUDED_)
