/*
 * $RCSfile: SecureMessage.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef SECUREMESSAGE_H_SW
#define SECUREMESSAGE_H_SW

#include "biblia/seguranca/Criptografia.h"
#include "biblia/seguranca/DigestHash.h"
#include "biblia/seguranca/ChaveSeguranca.h"
using namespace biblia::seguranca;


namespace biblia {
  namespace seguranca {

	class SecureMessage{
		public:
			static void criptografar  (ChaveSeguranca* chaveSeguranca,char* bufferOrigem,int tamOrigem,char** bufferDestino,int* tamDestino,bool hexa=false);
			static bool decriptografar(ChaveSeguranca* chaveSeguranca,char* bufferOrigem,int tamOrigem,char** bufferDestino,int* tamDestino,bool hexa=false);
	};
  }
}

#endif