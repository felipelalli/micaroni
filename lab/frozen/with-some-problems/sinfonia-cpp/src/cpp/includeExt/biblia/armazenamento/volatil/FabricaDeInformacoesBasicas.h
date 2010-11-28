/*
 * $RCSfile: FabricaDeInformacoesBasicas.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
		 * Contém uma FabricaDeInformacoesAprendiz que
		 * já conhece as fábricas: ConhecedorDePrimitivos,
		 * FabricaDeLista e FabricaDeComposto.
		 * <p>
		 * Esta fábrica de informações básicas cria
		 * as fábricas que utiliza, exceto a
		 * ConhecedorDeCompostos que deve ser
		 * passada de fora no construtor. É assim
		 * porque esta classe não pode carregar a
		 * "responsabilidade" de criar o (possivelmente) único
		 * ConhecedorDeCompostos dessa aplicação/módulo.
		 * Lembre-se que um ConhecedorDeCompostos carrega
		 * consigo as "carcaças" dos Compostos, chamadas
		 * de DefinicaoDeComposto. --- No construtor
		 * desta classe, esta já se "auto-define" no
		 * ConhecedorDeCompostos como sendo a FabricaDeInformacao
		 * padrão para os elementos do conhecedor de compostos,
		 * portanto não é necessário fazer essa definição de fora.
		 * <p>
		 * Não se preocupe com a aparente "limitação"
		 * desta classe porque ela é totalmente
		 * expansível através da "fábrica aprendiz"
		 * que carrega consigo. Você ainda tem a opção
		 * de fazer com que esta fábrica "desaprenda"
		 * o que aprendeu quando contruída chamando
		 * a função "desaprende()" da fábrica aprendiz.
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
