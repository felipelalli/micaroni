/*
 * $RCSfile: FabricaDeComposto.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_FABRICADECOMPOSTO_H__FF689F0C_13D7_459D_BE3B_968AB5633353__INCLUDED_)
#define AFX_FABRICADECOMPOSTO_H__FF689F0C_13D7_459D_BE3B_968AB5633353__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/volatil/FabricaDeInformacao.h"
#include "biblia/armazenamento/volatil/carcacas/composto/ConhecedorDeCompostos.h"
#include "biblia/armazenamento/volatil/carcacas/composto/instrucoes/CriaComposto.h"

using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::carcacas::composto::instrucoes;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace carcacas {
	    namespace composto {
			class FabricaDeComposto: public FabricaDeInformacao {
				private:
					ConhecedorDeCompostos* FabricaDeComposto::pConhecedor;
					bool FabricaDeComposto::pApagar;

				protected:
					ConhecedorDeCompostos& FabricaDeComposto
							::conhecedorDeCompostos();

					const ConhecedorDeCompostos& FabricaDeComposto
							::conhecedorDeCompostos() const;

				public:
					FabricaDeComposto::FabricaDeComposto(
							ConhecedorDeCompostos*,
							bool apagarNoFinal = false);

					virtual FabricaDeComposto::~FabricaDeComposto();

					// FabricaDeInformacao:
					virtual const bool FabricaDeComposto
							::sabeGerarUm(const Tipo&) const;

					// Fabrica:
					virtual Objeto* FabricaDeComposto::gera();
			};
		}
	  }
	}
  }
}

#endif // !defined(AFX_FABRICADECOMPOSTO_H__FF689F0C_13D7_459D_BE3B_968AB5633353__INCLUDED_)
