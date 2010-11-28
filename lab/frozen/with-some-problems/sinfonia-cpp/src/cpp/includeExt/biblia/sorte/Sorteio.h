/*
 * $RCSfile: Sorteio.h,v $
 * $Date: 2005/01/20 21:29:04 $
 * $Revision: 1.16 $
 *
 * Implementa��o da biblioteca B�blia.
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
			 * Sorteia um n�mero de 0 A N-1.
			 */
			unsigned int Sorteio::int_rand(unsigned int n);

		public:
			Sorteio::Sorteio(std::string nomeProcesso);
			virtual Sorteio::~Sorteio();

			/**
			 * Sorteia um n�mero entre inicio e fim (inclusive).
			 */
			virtual int Sorteio::sortear(
					unsigned int inicio,
					unsigned int fim);

			/**
			 * Sorteia um n�mero >= 0 e < 1.
			 */
			virtual double Sorteio::sortear();

			/**
			 * Par�metro: vetor com diversas
			 * probabilidades, de 0 a 1.
			 * Retorno: Esta fun��o sorteia um n�mero e
			 * o "encontra" dentro do vetor, retornando
			 * a posi��o do �ndice ou -1 quando n�o o
			 * encontra. Se a soma do vetor for maior
			 * que um, os �ltimos (ap�s a soma 1) ser�o ignorados
			 * e se a soma for menor que 1 pode ser que a probabilidade
			 * sorteada n�o esteja em nenhum caso.
			 *
			 * A 0,1
			 * B 0,25
			 * C 0,05
			 * D 0,6
			 *
			 * n�mero sorteado: 0,4
			 * 0,4 < A+B+C+D
			 * ou seja, est� em D.
			 *
			 * @deprecated N�o devia estar aqui.
			 */
			virtual int Sorteio::sortearVetProb (double* vetProb,int qtsProb);
	};
  }
}

#endif
