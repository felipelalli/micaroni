/*
 * $RCSfile: FabricaDeEncaixotador.h,v $
 * $Date: 2004/02/11 23:28:52 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_FABRICADEENCAIXOTADOR_H__4F1E538C_69E3_426C_9985_F2D60E33EF66__INCLUDED_)
#define AFX_FABRICADEENCAIXOTADOR_H__4F1E538C_69E3_426C_9985_F2D60E33EF66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Fabrica.h"
#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/eterno/EternoExcecao.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::eterno;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {
		class FabricaDeEncaixotador: public Fabrica {
			private:
				Tipo FabricaDeEncaixotador::pDeveSaberEsteTipo;
		
			protected:
				virtual const Tipo& FabricaDeEncaixotador
						::deveSaberEsteTipo() const;

			public:
				FabricaDeEncaixotador::FabricaDeEncaixotador();
				virtual FabricaDeEncaixotador::~FabricaDeEncaixotador();

				/**
				 * Prepara esta fábrica para gerar um encaixotador
				 * que sabe encaixotar ou desencaixotar determinado
				 * tipo.
				 *
				 * @throws FabricaNaoSabeFabricarEsseEncaixotador
				 */
				virtual FabricaDeEncaixotador& FabricaDeEncaixotador
						::preparaParaGerarUmEncaixotadorQueSabeEncaixotar(
								const Tipo&);

				virtual const bool FabricaDeEncaixotador
						::sabeCriarEncaixotadorQueSabeEncaixotar(
							const Tipo&) const = 0;

				// Fabrica:
				virtual Objeto* FabricaDeEncaixotador::gera() = 0;
		};
	  }
	}
  }
}

#endif // !defined(AFX_FABRICADEENCAIXOTADOR_H__4F1E538C_69E3_426C_9985_F2D60E33EF66__INCLUDED_)
