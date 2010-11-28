/*
 * $RCSfile: TipoIdentificado.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_TIPOIDENTIFICADO_H__E172AE87_2214_4496_AFF7_C92821497737__INCLUDED_)
#define AFX_TIPOIDENTIFICADO_H__E172AE87_2214_4496_AFF7_C92821497737__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/armazenamento/volatil/Tipo.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace carcacas {
	    namespace composto {
			/**
			 * Semelhante ao conceito de "definição de atributo"
			 * da POO: agrupa uma identificação
			 * de um Tipo a uma Identificacao, identificando
			 * o tipo.
			 *
			 * @see DefinicaoDeComposto
			 */
			class TipoIdentificado: public Objeto {
				private:
					Identificacao TipoIdentificado
							::pIdentidade;

					Tipo TipoIdentificado
							::pTipo;

				public:
					TipoIdentificado::TipoIdentificado(
							const Identificacao& identificacao,
							const Tipo& tipo);

					virtual TipoIdentificado::~TipoIdentificado();

					virtual const Identificacao& TipoIdentificado
							::identificacao() const;

					virtual const Tipo& TipoIdentificado
							::tipo() const;

					virtual TipoIdentificado&
							TipoIdentificado
								::operator=(const
									TipoIdentificado& i);

					// Objeto:

					virtual std::string TipoIdentificado::emString() const;
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_TIPOIDENTIFICADO_H__E172AE87_2214_4496_AFF7_C92821497737__INCLUDED_)
