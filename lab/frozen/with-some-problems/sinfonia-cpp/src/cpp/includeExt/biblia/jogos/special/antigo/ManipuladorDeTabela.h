/*
 * $RCSfile: ManipuladorDeTabela.h,v $
 * $Date: 2003/06/26 00:52:31 $
 * $Revision: 1.1 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(SBS_AFX_MANIPULADORDETABELA_H__C24A5D33_D30A_46A0_B1F4_CF8EB70D97E1__INCLUDED_)
#define SBS_AFX_MANIPULADORDETABELA_H__C24A5D33_D30A_46A0_B1F4_CF8EB70D97E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/special/antigo/Tabela.h"

namespace biblia{
	namespace jogos {
		namespace special {
			namespace antigo {

				#define TOTAL_MB -1

				class ManipuladorDeTabela: public Objeto {
					private:
						Tabela& pTabela;

					public:
						ManipuladorDeTabela::ManipuladorDeTabela(Tabela&);
						virtual ManipuladorDeTabela::~ManipuladorDeTabela();

						/**
						 * Pinta cor sim cor n�o na tabela
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
