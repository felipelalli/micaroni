#ifndef LISTA_INT_H
#define LISTA_INT_H

/*
 * $RCSfile: ListaInt.h,v $
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
			class ListaInt{

				private:
					Lista* pLista;

				public:
					ListaInt::ListaInt(string nome);
					ListaInt::~ListaInt();

					void ListaInt::add (int valor);
					void ListaInt::remove (int indice);
					int operator[](int indice) const;
					int ListaInt::size() const;
					void ListaInt::clear();
					bool ListaInt::empty() const { return (bool) !this->pLista->size(); }

			};
		}
	}
}

#endif