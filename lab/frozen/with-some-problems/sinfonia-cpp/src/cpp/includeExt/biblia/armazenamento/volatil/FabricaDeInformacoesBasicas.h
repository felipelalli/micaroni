/*
 * $RCSfile: FabricaDeInformacoesBasicas.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_FABRICADEINFORMACOESBASICAS_H__C28429F8_3F31_4E09_88FC_81948034F836__INCLUDED_)
#define AFX_FABRICADEINFORMACOESBASICAS_H__C28429F8_3F31_4E09_88FC_81948034F836__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/armazenamento/volatil/FabricaDeInformacao.h"
#include "biblia/armazenamento/volatil/FabricaDeInformacaoAprendiz.h"
#include "biblia/armazenamento/volatil/primitivos/ConhecedorDePrimitivos.h"
#include "biblia/armazenamento/volatil/carcacas/FabricaDeLista.h"
#include "biblia/armazenamento/volatil/carcacas/composto/FabricaDeComposto.h"
#include "biblia/armazenamento/volatil/carcacas/composto/ConhecedorDeCompostos.h"

using namespace biblia::armazenamento::volatil::primitivos;
using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::volatil::carcacas::composto;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
		/** 
		 * Cont�m uma FabricaDeInformacoesAprendiz que
		 * j� conhece as f�bricas: ConhecedorDePrimitivos,
		 * FabricaDeLista e FabricaDeComposto.
		 * <p>
		 * Esta f�brica de informa��es b�sicas cria
		 * as f�bricas que utiliza, exceto a
		 * ConhecedorDeCompostos que deve ser
		 * passada de fora no construtor. � assim
		 * porque esta classe n�o pode carregar a
		 * "responsabilidade" de criar o (possivelmente) �nico
		 * ConhecedorDeCompostos dessa aplica��o/m�dulo.
		 * Lembre-se que um ConhecedorDeCompostos carrega
		 * consigo as "carca�as" dos Compostos, chamadas
		 * de DefinicaoDeComposto. --- No construtor
		 * desta classe, esta j� se "auto-define" no
		 * ConhecedorDeCompostos como sendo a FabricaDeInformacao
		 * padr�o para os elementos do conhecedor de compostos,
		 * portanto n�o � necess�rio fazer essa defini��o de fora.
		 * <p>
		 * N�o se preocupe com a aparente "limita��o"
		 * desta classe porque ela � totalmente
		 * expans�vel atrav�s da "f�brica aprendiz"
		 * que carrega consigo. Voc� ainda tem a op��o
		 * de fazer com que esta f�brica "desaprenda"
		 * o que aprendeu quando contru�da chamando
		 * a fun��o "desaprende()" da f�brica aprendiz.
		 *
		 * @see FabricaDeLista
		 * @see FabricaDeComposto
		 * @see ConhecedorDePrimitivos
		 */
		class FabricaDeInformacoesBasicas: public FabricaDeInformacao {
			private:
				FabricaDeInformacaoAprendiz
						FabricaDeInformacoesBasicas::pFabricaAprendiz;

				ConhecedorDeCompostos* FabricaDeInformacoesBasicas
						::pConhecedorDeCompostos;

				/**
				 * Proibido.
				 */
				FabricaDeInformacoesBasicas
						::FabricaDeInformacoesBasicas(
							const FabricaDeInformacoesBasicas&);

			public:
				FabricaDeInformacoesBasicas
						::FabricaDeInformacoesBasicas(
							ConhecedorDeCompostos&);

				virtual FabricaDeInformacoesBasicas
						::~FabricaDeInformacoesBasicas();

				virtual FabricaDeInformacaoAprendiz&
						FabricaDeInformacoesBasicas::fabricaAprendiz();

				virtual const FabricaDeInformacaoAprendiz&
						FabricaDeInformacoesBasicas::fabricaAprendiz() const;

				virtual const ConhecedorDeCompostos&
						FabricaDeInformacoesBasicas
							::conhecedorDeCompostos() const;

				virtual ConhecedorDeCompostos& FabricaDeInformacoesBasicas
						::conhecedorDeCompostos();

				// FabricaDeInformacao:
				virtual const bool FabricaDeInformacoesBasicas
						::sabeGerarUm(const Tipo&) const;

				// Fabrica:
				virtual Objeto* FabricaDeInformacoesBasicas::gera();
		};
	}
  }
}

#endif // !defined(AFX_FABRICADEINFORMACOESBASICAS_H__C28429F8_3F31_4E09_88FC_81948034F836__INCLUDED_)
