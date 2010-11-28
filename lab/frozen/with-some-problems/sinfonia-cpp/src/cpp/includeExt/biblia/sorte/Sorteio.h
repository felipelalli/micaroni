/*
 * $RCSfile: Sorteio.h,v $
 * $Date: 2005/01/20 21:29:04 $
 * $Revision: 1.16 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef SORTEIO_NOVO_SB_H
#define SORTEIO_NOVO_SB_H

#include "biblia/sorte/randomc.h"
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

#include "biblia/armazenamento/eterno/VariavelEmArquivo.h"
using namespace biblia::armazenamento::eterno;

using namespace biblia::basico;
using namespace biblia::util;

namespace biblia {
  namespace sorte {

	class Sorteio: public Objeto {
		private:
			static bool Sorteio::pInicializado;

			std::string pNomeProcesso;
			VariavelEmArquivo<int> pQtsSorteios;
			VariavelEmArquivo<int> pSemente;



		protected:
			TRandomMersenne* Sorteio::sorte;

			void Sorteio::pIncSorteios();

			//TRandomMotRot Sorteio::sorte;

			/**
			 * Sorteia um número de 0 A N-1.
			 */
			unsigned int Sorteio::int_rand(unsigned int n);

		public:
			Sorteio::Sorteio(std::string nomeProcesso);
			virtual Sorteio::~Sorteio();

			/**
			 * Sorteia um número entre inicio e fim (inclusive).
			 */
			virtual int Sorteio::sortear(
					unsigned int inicio,
					unsigned int fim);

			/**
			 * Sorteia um número >= 0 e < 1.
			 */
			virtual double Sorteio::sortear();

			/**
			 * Parâmetro: vetor com diversas
			 * probabilidades, de 0 a 1.
			 * Retorno: Esta função sorteia um número e
			 * o "encontra" dentro do vetor, retornando
			 * a posição do índice ou -1 quando não o
			 * encontra. Se a soma do vetor for maior
			 * que um, os últimos (após a soma 1) serão ignorados
			 * e se a soma for menor que 1 pode ser que a probabilidade
			 * sorteada não esteja em nenhum caso.
			 *
			 * A 0,1
			 * B 0,25
			 * C 0,05
			 * D 0,6
			 *
			 * número sorteado: 0,4
			 * 0,4 < A+B+C+D
			 * ou seja, está em D.
			 *
			 * @deprecated Não devia estar aqui.
			 */
			virtual int Sorteio::sortearVetProb (double* vetProb,int qtsProb);
	};
  }
}

#endif
