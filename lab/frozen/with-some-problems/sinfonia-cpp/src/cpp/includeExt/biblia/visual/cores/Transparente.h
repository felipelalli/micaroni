/*
 * $RCSfile: Transparente.h,v $
 * $Date: 2003/05/29 21:21:52 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_Transparente_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_)
#define AFX_Transparente_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/visual/Cor.h"

namespace biblia {
  namespace visual {
	namespace cores {

		class Transparente: public Cor {
			public:
				Transparente::Transparente(
						double porcentagem = 100.00);

				virtual Transparente::~Transparente();

				/**
				 * Retorna a porcentagem de transparencia.
				 */
				virtual double Transparente::operator()() const;

				/**
				 * Modifica a transparência a partir
				 * de uma nova porcentagem.
				 */
				virtual Transparente& Transparente
						::operator()(const double& porcentagem);
		};
	}
  }
}

#endif // !defined(AFX_Transparente_H__95BD6D50_195C_413F_8D6B_DACB4F1E95FB__INCLUDED_)
