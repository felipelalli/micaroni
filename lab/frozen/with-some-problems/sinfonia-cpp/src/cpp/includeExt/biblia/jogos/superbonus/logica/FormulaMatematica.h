/*
 * $RCSfile: FormulaMatematica.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef FORMULA_MATEMATICA_H
#define FORMULA_MATEMATICA_H

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia{

	namespace jogos{

		namespace superbonus{

			namespace logica{

				class FormulaMatematica : public Objeto{

					private:

						double pPercentualPagamento;
						double pPercentualPagamentoNoBonus;

						enum ValoresPremios{

							VALOR_CANTOS      = 1,
							VALOR_LINHA       = 4,
							VALOR_LINHA_DUPLA = 100,
							VALOR_BINGO       = 1000
						};

						double pValorAcumulado;

						double pProbCantos[2];
						double pProbLinha[2];
						double pProbLinhaDupla[2];
						double pProbBingo[2];
						double pProbAcumulado;

						void FormulaMatematica::pZerar(bool dobro);
						void FormulaMatematica::pCalcular (bool dobro);

					public:
						FormulaMatematica::FormulaMatematica  ();
						FormulaMatematica::~FormulaMatematica ();

						void FormulaMatematica::zerar();

						void FormulaMatematica::setPercentualPagamento        (double percentual);
						void FormulaMatematica::setPercentualPagamentoNoBonus (double percentual);

						void FormulaMatematica::setValorAcumulado(int valorEmCreditos);

						void FormulaMatematica::setProbCantos     (double probCantos     ,bool dobro);
						void FormulaMatematica::setProbLinha      (double probLinha      ,bool dobro);
						void FormulaMatematica::setProbLinhaDupla (double probLinhaDupla ,bool dobro);
						void FormulaMatematica::setProbBingo      (double probBingo      ,bool dobro);
						void FormulaMatematica::setProbAcumulado  (double probAcumulado);

						void FormulaMatematica::calcular();

						double FormulaMatematica::getProbCantos     (bool dobro);
						double FormulaMatematica::getProbLinha      (bool dobro);
						double FormulaMatematica::getProbLinhaDupla (bool dobro);
						double FormulaMatematica::getProbBingo      (bool dobro);
						double FormulaMatematica::getProbAcumulado  (int novoValorAcumuladoEmCreditos);
				};
			}
		}
	}
}

#endif