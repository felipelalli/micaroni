/*
 * $RCSfile: Acumulado.h,v $
 * $Date: 2005/01/13 17:09:48 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_ACUMULADO_H__C3D66AB4_1E4D_4F2C_A29E_B9255137A078__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_ACUMULADO_H__C3D66AB4_1E4D_4F2C_A29E_B9255137A078__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace estados {

		class Acumulado: public Objeto {
			private:
				bool Acumulado::pDeuAcumulado;
				int Acumulado::pVidraca;
				int Acumulado::pLancamento;
				int Acumulado::pExplosao;
				double Acumulado::pUltimoValor;

			public:
				Acumulado::Acumulado();
				virtual Acumulado::~Acumulado();

				virtual Acumulado& Acumulado
						::deuAcumulado(bool deu, double ultimoValor);

				virtual bool Acumulado
						::deuAcumulado() const;

				virtual int Acumulado::vidraca();
				virtual int Acumulado::lancamento();
				virtual int Acumulado::explosao();
				virtual double Acumulado::ultimoValor() const;

				virtual Acumulado& Acumulado
						::quebra();

				virtual Acumulado& Acumulado
						::lanca();

				virtual Acumulado& Acumulado
						::explode();
		};
	  }
	}
  }
}

#endif // !defined(AFX_ACUMULADO_H__C3D66AB4_1E4D_4F2C_A29E_B9255137A078__INCLUDED_)
