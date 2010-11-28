/*
 * $RCSfile: FabricaDeInformacaoAprendiz.h,v $
 * $Date: 2005/01/20 21:28:34 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
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
		 * É uma FabricaDeInformacao genérica que "aprende"
		 * a fabricar informações a partir de outras fábricas.
		 * A princípio ela <b>não sabe nada</b>; alguém
		 * de fora deve ensiná-la.
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
				 * Desaprende tudo que aprendeu até o momento.
				 */
				virtual FabricaDeInformacaoAprendiz&
						FabricaDeInformacaoAprendiz::desaprende();

				// FabricaDeInformacao:

				/**
				 * "Ensina" esta fábrica a fabricar elementos
				 * que a fábrica alheia sabe. O efeito é
				 * acumulativo, i. e., quanto mais fábricas
				 * "ensinadas" mais informações
				 * esta saberá fabricar.
				 * <p>
				 * Dá prioridade às fábricas que foram
				 * adicionadas (ou "aprendidas") por último.
				 * <p>
				 * Pega para si a responsabilidade de deletar
				 * a nova fábrica passada como parâmetro; portanto
				 * é importante criar uma nova fábrica sempre
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
