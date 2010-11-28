/*
 * $RCSfile: Executavel.h,v $
 * $Date: 2003/12/05 18:49:52 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_EXECUTAVEL_H__312F4691_023A_45D7_B450_50DDC0AD8ECD__INCLUDED_)
#define AFX_EXECUTAVEL_H__312F4691_023A_45D7_B450_50DDC0AD8ECD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
using namespace biblia::basico;

namespace biblia {
  namespace fluxo {

	/**
	 * Tudo que pode ser "executado" deve
	 * implementar esta interface.
	 */
	class Executavel: public Interface {
		protected:
			Executavel::Executavel();

		public:
			virtual Executavel::~Executavel();

			/**
			 * Função objeto (discutido em
			 * doc/poo-cpp.html §Objetos Função)
			 * que retorna o valor.
			 */
			virtual Executavel& Executavel::operator()() {
				return this->executa();
			}

			virtual Executavel& Executavel::executa() = 0;
	};
  }
}

#endif // !defined(AFX_EXECUTAVEL_H__312F4691_023A_45D7_B450_50DDC0AD8ECD__INCLUDED_)
