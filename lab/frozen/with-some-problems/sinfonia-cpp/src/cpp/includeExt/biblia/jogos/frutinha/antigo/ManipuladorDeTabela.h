/*
 * $RCSfile: ManipuladorDeTabela.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(TROPICAL_SBS_AFX_MANIPULADORDETABELA_H__C24A5D33_D30A_46A0_B1F4_CF8EB70D97E1__INCLUDED_)
#define TROPICAL_SBS_AFX_MANIPULADORDETABELA_H__C24A5D33_D30A_46A0_B1F4_CF8EB70D97E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/frutinha/antigo/Tabela.h"

namespace biblia{
	namespace jogos {
		namespace frutinha {
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
