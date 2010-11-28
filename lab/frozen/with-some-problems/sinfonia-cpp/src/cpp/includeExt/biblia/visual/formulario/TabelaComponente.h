/*
 * $RCSfile: TabelaComponente.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TABELA_H__7CAC082B_9E4F_4E50_A853_A7D6C03E932A__INCLUDED_)
#define AFX_TABELA_H__7CAC082B_9E4F_4E50_A853_A7D6C03E932A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/tempo/UltraLong.h"
#include "biblia/visual/formulario/Componente.h"
#include "biblia/visual/formulario/CelulaComponente.h"

#define CELULA_MAXIMO_BB 1000
using namespace biblia::tempo;

namespace biblia {
  namespace visual {
    namespace formulario {
		class Tabela: public Componente {
			private:
				Celula* Tabela::pCelulas
						[CELULA_MAXIMO_BB][CELULA_MAXIMO_BB];

				int Tabela::pTamanhoLinha[CELULA_MAXIMO_BB];
				int Tabela::pTamanhoColuna[CELULA_MAXIMO_BB];

			public:
				Tabela::Tabela();
				virtual Tabela::~Tabela();

				virtual Celula& Tabela::celula(
						const int& linha, const int& coluna);

				virtual const Celula& Tabela::celula(
						const int& linha, const int& coluna) const;

				virtual Tabela& Tabela::reestrutura();
				virtual Tabela& Tabela::criaLinha(int quantas = 1);
				virtual Tabela& Tabela::criaColuna(int quantas = 1);
				virtual int Tabela::linhas() const;
				virtual int Tabela::colunas() const;

				virtual Tabela& Tabela::tamanhoLinha(
						const int& qualLinha, const int tamanho);

				virtual Tabela& Tabela::tamanhoColuna(
					const int& qualColuna, const int tamanho);

				virtual int Tabela::tamanhoLinha(const int& qualLinha) const;
				virtual int Tabela::tamanhoColuna(const int& qualColuna) const;
		};
	}
  }
}

#endif // !defined(AFX_TABELA_H__7CAC082B_9E4F_4E50_A853_A7D6C03E932A__INCLUDED_)
