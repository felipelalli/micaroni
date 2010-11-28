/*
 * $RCSfile: FabricaDeInformacaoAprendiz.h,v $
 * $Date: 2005/01/20 21:28:34 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_FABRICADEINFORMACAOAPRENDIZ_H__5F4F70ED_B12D_4351_BAEB_01A64D3A7807__INCLUDED_)
#define AFX_FABRICADEINFORMACAOAPRENDIZ_H__5F4F70ED_B12D_4351_BAEB_01A64D3A7807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/Lixeira.h"
#include "biblia/armazenamento/volatil/FabricaDeInformacao.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"

using namespace biblia::util;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
		/**
		 * � uma FabricaDeInformacao gen�rica que "aprende"
		 * a fabricar informa��es a partir de outras f�bricas.
		 * A princ�pio ela <b>n�o sabe nada</b>; algu�m
		 * de fora deve ensin�-la.
		 */
		class FabricaDeInformacaoAprendiz: public FabricaDeInformacao {
			private:
				Lista<FabricaDeInformacao*>
						FabricaDeInformacaoAprendiz::pFabricas;

				Lixeira FabricaDeInformacaoAprendiz::pLixo;

			public:
				FabricaDeInformacaoAprendiz::FabricaDeInformacaoAprendiz();
				virtual FabricaDeInformacaoAprendiz
						::~FabricaDeInformacaoAprendiz();

				/**
				 * Desaprende tudo que aprendeu at� o momento.
				 */
				virtual FabricaDeInformacaoAprendiz&
						FabricaDeInformacaoAprendiz::desaprende();

				// FabricaDeInformacao:

				/**
				 * "Ensina" esta f�brica a fabricar elementos
				 * que a f�brica alheia sabe. O efeito �
				 * acumulativo, i. e., quanto mais f�bricas
				 * "ensinadas" mais informa��es
				 * esta saber� fabricar.
				 * <p>
				 * D� prioridade �s f�bricas que foram
				 * adicionadas (ou "aprendidas") por �ltimo.
				 * <p>
				 * Pega para si a responsabilidade de deletar
				 * a nova f�brica passada como par�metro; portanto
				 * � importante criar uma nova f�brica sempre
				 * que se for ensinar esta.
				 */
				virtual FabricaDeInformacaoAprendiz&
						FabricaDeInformacaoAprendiz
							::ensina(FabricaDeInformacao*);

				virtual const bool FabricaDeInformacaoAprendiz
						::sabeGerarUm(const Tipo&) const;

				// Fabrica:
				virtual Objeto* FabricaDeInformacaoAprendiz::gera();

				// Objeto:
				virtual std::string FabricaDeInformacaoAprendiz::emString() const;
		};
	}
  }
}

#endif // !defined(AFX_FABRICADEINFORMACAOAPRENDIZ_H__5F4F70ED_B12D_4351_BAEB_01A64D3A7807__INCLUDED_)
