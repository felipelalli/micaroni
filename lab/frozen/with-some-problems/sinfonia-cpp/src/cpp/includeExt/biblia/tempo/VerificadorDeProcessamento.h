/*
 * $RCSfile: VerificadorDeProcessamento.h,v $
 * $Date: 2005/01/20 21:29:26 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef VERIFICADOR_DE_PROCESSAMENTO
#define VERIFICADOR_DE_PROCESSAMENTO

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include <string>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


namespace biblia {
  namespace tempo {

	class VerificadorDeProcessamento: public Objeto {

		private:
			std::string  pNomeProcesso;
			bool    pEscrever;
			double  pTempoMaximo;
			double  pTempoTotal;
			double  pMediaDeTempo;
			double  pVezes;
			clock_t pInicio;
			int     pIgnorarQuantos;
			int     pQtsIgnorados;
			int     arq;

		public:
			VerificadorDeProcessamento::VerificadorDeProcessamento(std::string nomeProcesso, bool escrever=true, int ignorarQuantos=0);
			virtual VerificadorDeProcessamento::~VerificadorDeProcessamento();

			virtual void VerificadorDeProcessamento::iniciou();
			virtual void VerificadorDeProcessamento::terminou();

			virtual double VerificadorDeProcessamento::tempoMaximo();
			virtual double VerificadorDeProcessamento::mediaDeTempo();
	};
  }
}


#endif
