/*
 * $RCSfile: Primitivo.h,v $
 * $Date: 2004/03/29 21:50:59 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(AFX_PRIMITIVO_H__956F6933_DDF5_4D38_9F9A_E6D16F08D58B__INCLUDED_)
#define AFX_PRIMITIVO_H__956F6933_DDF5_4D38_9F9A_E6D16F08D58B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Copiavel.h"
#include "biblia/basico/Comparavel.h"
#include "biblia/armazenamento/volatil/Informacao.h"

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace primitivos {
		class ConhecedorDePrimitivos;

		/**
		 * Agrupa conceitualmente todos
		 * os tipos primitivos definido neste
		 * pacote. Também indica que todo pritimivo
		 * é copiável e comparável.
		 */
		class Primitivo: public Informacao, 
				public Copiavel,
				public Comparavel
		{
			friend class ConhecedorDePrimitivos;

			protected:
				Primitivo::Primitivo();

			public:
				virtual Primitivo::~Primitivo();

			// Copiavel:
			virtual Objeto* Primitivo::geraCopia() const = 0;
			virtual Copiavel& Primitivo::copiaEmSi(const Copiavel& alheio) = 0;

			// Comparavel:
			virtual const bool Primitivo
					::menorQue(const Comparavel& alheio) const = 0;

			// Igualavel:
			virtual const bool Primitivo::igual(
					const Igualavel& alheio) const = 0;
		};
	  }
	}
  }
}

#endif // !defined(AFX_PRIMITIVO_H__956F6933_DDF5_4D38_9F9A_E6D16F08D58B__INCLUDED_)
