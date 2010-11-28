/*
 * $RCSfile: FabricaDeDiversosEncaixotadores.h,v $
 * $Date: 2004/02/02 19:44:52 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_FABRICADEDIVERSOSENCAIXOTADORES_H__E2C859EC_971E_4C34_91A0_EEBE03E28046__INCLUDED_)
#define AFX_FABRICADEDIVERSOSENCAIXOTADORES_H__E2C859EC_971E_4C34_91A0_EEBE03E28046__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/volatil/primitivos/ConhecedorDePrimitivos.h"
#include "biblia/armazenamento/volatil/carcacas/composto/ConhecedorDeCompostos.h"
#include "biblia/armazenamento/eterno/empacotamento/EmpacotadorDeTiposPrimitivos.h"
#include "biblia/armazenamento/eterno/encaixotamento/FabricaDeEncaixotador.h"
#include "biblia/armazenamento/eterno/encaixotamento/EncaixotadorDeComposto.h"
#include "biblia/armazenamento/eterno/encaixotamento/EncaixotadorDeLista.h"
#include "biblia/armazenamento/eterno/encaixotamento/EncaixotadorGenerico.h"

using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::primitivos;
using namespace biblia::armazenamento::volatil::carcacas::composto;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {
		class FabricaDeDiversosEncaixotadores
				:public FabricaDeEncaixotador
		{
			private:
				ConhecedorDeCompostos&
					FabricaDeDiversosEncaixotadores
						::pConhecedorDeCompostos;

			public:
				FabricaDeDiversosEncaixotadores
						::FabricaDeDiversosEncaixotadores(
							ConhecedorDeCompostos&);

				virtual FabricaDeDiversosEncaixotadores
						::~FabricaDeDiversosEncaixotadores();

				// FabricaDeEncaixotador:
				virtual const bool FabricaDeDiversosEncaixotadores
						::sabeCriarEncaixotadorQueSabeEncaixotar(
							const Tipo&) const;

				// Fabrica:
				virtual Objeto* FabricaDeDiversosEncaixotadores::gera();
		};
	  }
	}
  }
}

#endif // !defined(AFX_FABRICADEDIVERSOSENCAIXOTADORES_H__E2C859EC_971E_4C34_91A0_EEBE03E28046__INCLUDED_)
