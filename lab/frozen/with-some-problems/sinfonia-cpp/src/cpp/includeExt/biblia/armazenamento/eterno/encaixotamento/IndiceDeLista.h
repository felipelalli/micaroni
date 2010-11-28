/*
 * $RCSfile: IndiceDeLista.h,v $
 * $Date: 2005/01/20 21:28:33 $
 * $Revision: 1.3 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_INDICEDELISTA_H__ADE9E537_8727_486F_A313_30734B8A7942__INCLUDED_)
#define AFX_INDICEDELISTA_H__ADE9E537_8727_486F_A313_30734B8A7942__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/armazenamento/volatil/Informacao.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"

using namespace std;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace encaixotamento {
		/**
		 * Usado por EncaixotadorDeLista.
		 * @see EncaixotadorDeLista
		 */
		class IndiceDeLista: public Informacao {
			private:
				int IndiceDeLista::pTamanho;

			public:
				/**
				 * Cria um índice de uma lista
				 * a partir de uma std::string.
				 */
				IndiceDeLista::IndiceDeLista(const std::string&);

				/**
				 * Cria um índice de uma lista
				 * a partir de uma lista.
				 */
				IndiceDeLista::IndiceDeLista(const Lista<>&);
				virtual IndiceDeLista::~IndiceDeLista();

				virtual const int& IndiceDeLista::tamanho() const;

				// Informacao:

				virtual const Tipo IndiceDeLista::tipo() const {
					return IndiceDeLista::tipoEstatico();
				}

				static const Tipo IndiceDeLista::tipoEstatico() {
					return Tipo("indiceDeLista!");
				}

				// Objeto:
				virtual std::string IndiceDeLista::emString() const;
		};
	  }
	}
  }
}

#endif // !defined(AFX_INDICEDELISTA_H__ADE9E537_8727_486F_A313_30734B8A7942__INCLUDED_)
