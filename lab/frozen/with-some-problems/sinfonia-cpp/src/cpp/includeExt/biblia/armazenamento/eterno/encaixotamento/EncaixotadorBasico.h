/*
 * $RCSfile: EncaixotadorBasico.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ENCAIXOTADORBASICO_H__6EF25C1E_F06C_4AAC_8477_F2E1E6A08DF2__INCLUDED_)
#define AFX_ENCAIXOTADORBASICO_H__6EF25C1E_F06C_4AAC_8477_F2E1E6A08DF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/eterno/encaixotamento/Encaixotador.h"
#include "biblia/armazenamento/eterno/encaixotamento/EncaixotadorDeLista.h"
#include "biblia/armazenamento/eterno/encaixotamento/EncaixotadorGenerico.h"
#include "biblia/armazenamento/eterno/encaixotamento/EncaixotadorDeComposto.h"
#include "biblia/armazenamento/eterno/encaixotamento/FabricaDeDiversosEncaixotadores.h"
#include "biblia/armazenamento/eterno/empacotamento/EmpacotadorDeTiposPrimitivos.h"

using namespace biblia::armazenamento::eterno::empacotamento;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {
		class EncaixotadorBasico: public Encaixotador {
			private:
				EncaixotadorGenerico EncaixotadorBasico::pGenerico;
				FabricaDeEncaixotador* EncaixotadorBasico::pFabrica;

			protected:
				virtual EncaixotadorGenerico&
						EncaixotadorBasico::generico();

				virtual const EncaixotadorGenerico&
						EncaixotadorBasico::generico() const;

			public:
				EncaixotadorBasico::EncaixotadorBasico(
						ConhecedorDeCompostos&);

				virtual EncaixotadorBasico::~EncaixotadorBasico();

				// Encaixotador:

				virtual Encaixotador& EncaixotadorBasico
						::encaixota(const Identificacao&,
							const Informacao&);

				virtual Informacao* EncaixotadorBasico
						::desencaixota(const Identificacao&);

				virtual const bool EncaixotadorBasico
						::sabeEncaixotar(const Tipo&) const;

				virtual Encaixotador& EncaixotadorBasico
						::someComPacote(const Identificacao&);

				virtual Encaixotador& EncaixotadorBasico
						::limpaCaixa(const bool&
								apagandoLixeira = true);

				virtual const Caixa& EncaixotadorBasico
						::caixaMontada() const;

				virtual Encaixotador& EncaixotadorBasico
						::sugaCaixaParaSi(Encaixotador&
								encaixotadorQueSeraSugado);

				virtual Encaixotador& EncaixotadorBasico
						::acrescentaEmSi(const Caixa&);
		};
	  }
	}
  }
}

#endif // !defined(AFX_ENCAIXOTADORBASICO_H__6EF25C1E_F06C_4AAC_8477_F2E1E6A08DF2__INCLUDED_)
