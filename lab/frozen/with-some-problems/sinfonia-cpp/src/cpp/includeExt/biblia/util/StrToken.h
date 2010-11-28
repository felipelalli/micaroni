/*
 * $RCSfile: StrToken.h,v $
 * $Date: 2005/01/20 21:29:31 $
 * $Revision: 1.10 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include <deque>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"
#include "biblia/util/UtilExcecao.h"
#include "biblia/armazenamento/volatil/Lista.h"

#ifndef STRTOKEN_SW_H
#define STRTOKEN_SW_H

#define SEPARADOR_DE_LISTA_PADRAO_SW "->"

using namespace std;
using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace util {

	/**
	 * @author Fernando Fernandes
	 * @bug Corrigir bug do tracinho.
	 */
	class StrToken: public Objeto{

		private:
			int iAtual;
			biblia::armazenamento::volatil::Lista* pLista;
			std::string pString;

		protected:
			virtual void StrToken::strCharCat (char* str,char caracter);

		public:
			StrToken::StrToken(const std::string& str,
			   		   const char* token
						= SEPARADOR_DE_LISTA_PADRAO_SW);

			virtual StrToken::~StrToken();
			virtual std::string StrToken::next();
			virtual bool StrToken::hasMoreTokens();
			virtual int StrToken::qtsTokens();

			static std::string StrToken::geraString(
					const std::deque<std::string>&, const char* separador
							= SEPARADOR_DE_LISTA_PADRAO_SW);
	};
  }
}

/* EXEMPLO DE USO

  	StrToken* myToken = new StrToken ("ola->bozzao->cacatua do nordeste->ovo preto","->");

	char strM [1000];

	while (myToken->hasMoreTokens()){
		strcpy(strM, myToken->next());
		Debug::info (strM);
	}

	delete myToken;

*/

#endif
