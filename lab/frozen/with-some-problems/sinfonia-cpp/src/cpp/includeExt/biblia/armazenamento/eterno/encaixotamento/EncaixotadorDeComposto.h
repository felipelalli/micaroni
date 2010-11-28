/*
 * $RCSfile: EncaixotadorDeComposto.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_ENCAIXOTADORDECOMPOSTO_H__AE7599E9_E5A9_454B_874F_429AC6F405C8__INCLUDED_)
#define AFX_ENCAIXOTADORDECOMPOSTO_H__AE7599E9_E5A9_454B_874F_429AC6F405C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/volatil/carcacas/composto/Composto.h"
#include "biblia/armazenamento/volatil/carcacas/composto/ConhecedorDeCompostos.h"
#include "biblia/armazenamento/volatil/carcacas/composto/instrucoes/CriaComposto.h"
#include "biblia/armazenamento/eterno/encaixotamento/Encaixotador.h"
#include "biblia/armazenamento/eterno/encaixotamento/IndiceDeComposto.h"
#include "biblia/armazenamento/eterno/encaixotamento/FabricaDeEncaixotador.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil::carcacas::composto;
using namespace biblia::armazenamento::volatil::carcacas::composto::instrucoes;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {
		class EncaixotadorDeComposto: public Encaixotador {
			private:
				ConhecedorDeCompostos& EncaixotadorDeComposto
						::pConhecedorDeCompostos;

				FabricaDeEncaixotador* EncaixotadorDeComposto
						::pFabricaDeEncaixotador;

			protected:
				virtual FabricaDeEncaixotador& EncaixotadorDeComposto
						::fabricaDeEncaixotador() const;

				virtual const Identificacao EncaixotadorDeComposto
						::geraIdentificadorParaElemento(
							const Identificacao& id,
							const Identificacao& nomeDoCampo) const;

				virtual ConhecedorDeCompostos& EncaixotadorDeComposto
						::conhecedorDeCompostos();

			public:
				/** 
				 * Se utiliza de um conhecedor de compostos
				 * para a cria��o de composto e a consulta
				 * a defini��es de composto. � necess�rio
				 * que esse conhecedor de compostos esteja
				 * 'vivo' at� que este 'morra'.
				 * <p>
				 * Precisa de uma f�brica de encaixotadores
				 * para encaixotar/desencaixotar os elementos
				 * desse composto.
				 */
				EncaixotadorDeComposto
						::EncaixotadorDeComposto(
							ConhecedorDeCompostos&,
							FabricaDeEncaixotador*);

				virtual EncaixotadorDeComposto
						::~EncaixotadorDeComposto();

				// Encaixotador:
				virtual Encaixotador& EncaixotadorDeComposto
						::encaixota(const Identificacao&,
							const Informacao&);

				/**
				 * O novo Composto deve ser apagado de fora.
				 * <b>N�o</b> apague seus elementos porque
				 * eles j� est�o "pendurados" na lixeira
				 * que a InformacaoConteiner carrega. Se voc�
				 * quer apagar manualmente esses elementos,
				 * n�o se esque�a de ent�o recicl�-los antes
				 * de apag�-los.
				 */
				virtual Informacao* EncaixotadorDeComposto
						::desencaixota(const Identificacao&);

				virtual const bool EncaixotadorDeComposto
						::sabeEncaixotar(const Tipo&) const;

				static const bool EncaixotadorDeComposto
						::sabeEncaixotarEstatico(const Tipo&);

				virtual const bool EncaixotadorDeComposto
						::sabeDesencaixotar(const Tipo&) const;

				static const bool EncaixotadorDeComposto
						::sabeDesencaixotarEstatico(const Tipo&);
		};
	  }
	}
  }
}

#endif // !defined(AFX_ENCAIXOTADORDECOMPOSTO_H__AE7599E9_E5A9_454B_874F_429AC6F405C8__INCLUDED_)
