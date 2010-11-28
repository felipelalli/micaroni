/*
 * $RCSfile: Criptografia.h,v $
 * $Date: 2005/01/20 21:29:03 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef CRIPTOGRAFIA_H_SW
#define CRIPTOGRAFIA_H_SW

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;

namespace biblia {
  namespace seguranca {

	class Criptografia{

		public:
			static void pDecrypt (ChaveSeguranca* chaveSeguranca, unsigned long text[]);
			static void pEncrypt (ChaveSeguranca* chaveSeguranca, unsigned long text[]);

			static void criptografar  (ChaveSeguranca* chaveSeguranca,const char* bufferOrigem,int tamOrigem,char** bufferDestino,int* tamDestino,bool ignorarTam=false);
			static bool decriptografar(ChaveSeguranca* chaveSeguranca,const char* bufferOrigem,int tamOrigem,char** bufferDestino,int* tamDestino,bool ignorarTam=false);
			static void toHexaString  (const char* buffer,int tamanho,char** result,int* tamResult);
			static void fromHexaString(const char* buffer,int tamanho,char** result,int* tamResult);
	};
  }
}

#endif