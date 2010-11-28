/*
 * $RCSfile: DigestHash.h,v $
 * $Date: 2005/01/20 21:29:04 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifndef HASH_H_SW
#define HASH_H_SW

#include<string>

using namespace std;//necessario para classe std::string

namespace biblia {
  namespace seguranca {

	class DigestHash{

		public:
			static int hash (const char* str,int tamanho);
	};
  }
}

#endif