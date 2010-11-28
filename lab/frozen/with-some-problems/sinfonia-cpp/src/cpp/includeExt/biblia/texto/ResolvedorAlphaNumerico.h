/*
 * $RCSfile: ResolvedorAlphaNumerico.h,v $
 * $Date: 2005/01/20 21:29:27 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_RESOLVEDORALPHANUMERICO_H__8994452F_BDA4_4189_8A21_40AC69531209__INCLUDED_)
#define AFX_RESOLVEDORALPHANUMERICO_H__8994452F_BDA4_4189_8A21_40AC69531209__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/Debug.h"
#include "biblia/texto/ResolvedorDeNomes.h"
#include "biblia/seguranca/DigestMD5.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"

using namespace biblia::util;
using namespace biblia::seguranca;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace texto {
	/**
	 * Transforma qualquer nome num nome
	 * alpha-numérico.
	 */
	class ResolvedorAlphaNumerico: public ResolvedorDeNomes {
		private:
			std::string ResolvedorAlphaNumerico::pCaracteres;
			char ResolvedorAlphaNumerico::pSinalDeMenos;

		public:
			ResolvedorAlphaNumerico::ResolvedorAlphaNumerico(
					const std::string& caracteres = "",
					const char& sinalDeMenos = '\0');

			virtual ResolvedorAlphaNumerico::~ResolvedorAlphaNumerico();

			// ResolvedorDeNomes:
			virtual const std::string ResolvedorAlphaNumerico
					::resolve(const std::string& nome);

			static ResolvedorAlphaNumerico& ResolvedorAlphaNumerico::singleton();
	};
  }
}

#endif // !defined(AFX_RESOLVEDORALPHANUMERICO_H__8994452F_BDA4_4189_8A21_40AC69531209__INCLUDED_)
