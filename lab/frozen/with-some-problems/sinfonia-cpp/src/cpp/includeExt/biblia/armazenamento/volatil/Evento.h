/*
 * $RCSfile: Evento.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_EVENTO_H__08B6BD18_BD75_4319_8E68_6EF8B23F5D4F__INCLUDED_)
#define AFX_EVENTO_H__08B6BD18_BD75_4319_8E68_6EF8B23F5D4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/util/CData.h"

using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
  namespace armazenamento {
 	namespace volatil {

		class Evento: public Objeto {
			private:
				CData Evento::pMomento;

			protected:
				Evento::Evento();
				Evento::Evento(const Evento&);

			public:
				virtual Evento::~Evento();
				virtual const CData& Evento
						::momentoEmQueFoiCriado() const;

				virtual bool Evento
						::mesmo(const Evento&) const = 0;
		};
	}
  }
}

#endif // !defined(AFX_EVENTO_H__08B6BD18_BD75_4319_8E68_6EF8B23F5D4F__INCLUDED_)
