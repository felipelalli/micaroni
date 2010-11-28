/*
 * $RCSfile: Lista.h,v $
 * $Date: 2005/01/20 21:28:35 $
 * $Revision: 1.12 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include<deque>
#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/util/Debug.h"



using namespace std;
using namespace biblia::util;
using namespace biblia::basico;

#ifndef LISTA_SW_H
#define LISTA_SW_H

namespace biblia {
	namespace armazenamento {
		namespace volatil {

			/**
			 * @deprecated Use biblia::armazenamento
			 *	::volatil::carcacas::Lista<>
			 */
			class Lista : public Objeto{

				private:
					string pNome;
					std::deque<void*> Lista::pLista;

				public:
					Lista::Lista(string nome);
					virtual Lista::~Lista();

					virtual Lista& Lista::add(void* objeto);
					virtual Lista& Lista::remove (int indice);
					virtual void* operator[](int indice) const;
					virtual int Lista::size() const;
					virtual bool Lista::empty() const { return (bool) !size(); }
			};
		}
	}
}

#endif
