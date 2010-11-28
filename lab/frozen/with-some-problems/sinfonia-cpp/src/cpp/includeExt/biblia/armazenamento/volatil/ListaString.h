#ifndef LISTA_STRING_H
#define LISTA_STRING_H
/*
 * $RCSfile: ListaString.h,v $
 * $Date: 2004/05/31 04:00:02 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/armazenamento/volatil/Lista.h"

namespace biblia {
	namespace armazenamento {
		namespace volatil {

			/**
			 * @deprecated Use biblia::armazenamento
			 *	::volatil::primitivos::Lista<>
			 */
			class ListaString{

				private:
					Lista* pLista;

				public:
					ListaString::ListaString(string nome);
					ListaString::~ListaString();

					void ListaString::add (const char* valor);
					void ListaString::remove (int indice);
					char* operator[](int indice) const;
					int ListaString::size() const;
					bool ListaString::empty() const { return (bool) !this->pLista->size(); }
					void ListaString::clear();

			};
		}
	}
}

#endif