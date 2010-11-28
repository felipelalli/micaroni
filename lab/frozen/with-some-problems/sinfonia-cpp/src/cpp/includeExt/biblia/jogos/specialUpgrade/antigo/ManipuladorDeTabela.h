/*
 * $RCSfile: ManipuladorDeTabela.h,v $
 * $Date: 2005/01/19 17:21:53 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_MANIPULADORDETABELA_H__C24A5D33_D30A_46A0_B1F4_CF8EB70D97E1__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_MANIPULADORDETABELA_H__C24A5D33_D30A_46A0_B1F4_CF8EB70D97E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/specialUpgrade/antigo/Tabela.h"

namespace biblia{
	namespace jogos {
		namespace specialUpgrade {
			namespace antigo {

				#define TOTAL_MB -1

				class ManipuladorDeTabela: public Objeto {
					private:
						Tabela& pTabela;

					public:
						ManipuladorDeTabela::ManipuladorDeTabela(Tabela&);
						virtual ManipuladorDeTabela::~ManipuladorDeTabela();

						/**
						 * Pinta cor sim cor não na tabela
						 * sempre na horizontal.
						 */
						virtual ManipuladorDeTabela& ManipuladorDeTabela
								::corSimCorNao(
									int corSim, int corNao,
									int inicio = 0,
									int fim = TOTAL_MB,
									int colunaInicio = 0,
									int colunaFim = TOTAL_MB);

						virtual Tabela& ManipuladorDeTabela::tabela();
				};
			}
		}
	}
}

#endif // !defined(AFX_MANIPULADORDETABELA_H__C24A5D33_D30A_46A0_B1F4_CF8EB70D97E1__INCLUDED_)
