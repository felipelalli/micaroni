/*
 * $RCSfile: ConclusivoTemporizado.h,v $
 * $Date: 2005/03/21 15:10:13 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(CONCLUSIVO_TEMPORIZADO_AFX_CONCLUSIVO_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_)
#define CONCLUSIVO_TEMPORIZADO_AFX_CONCLUSIVO_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/fluxo/Conclusivo.h"
using namespace biblia::fluxo;

#include "biblia/tempo/CronometroSistema.h"
using namespace biblia::tempo;



namespace biblia {
  namespace fluxo {

	class ConclusivoTemporizado: public Conclusivo {

		private:
			CronometroSistema pCronometro;
			double pPercXTempo;
			mutable double pPercXTempoAce;
			mutable double pTempoVerificacao;

		public:
			ConclusivoTemporizado::ConclusivoTemporizado();			
			virtual ConclusivoTemporizado::~ConclusivoTemporizado();

			virtual Conclusivo& ConclusivoTemporizado::inicia();
			virtual double ConclusivoTemporizado::porcentagem() const;
			Conclusivo& ConclusivoTemporizado::progresso(double porcentagem);

			virtual double ConclusivoTemporizado::porcentagemReal() const;
			virtual double ConclusivoTemporizado::percXTempo() const;
			virtual double ConclusivoTemporizado::percXTempoAce() const;
			virtual double ConclusivoTemporizado::duracao() const;
			virtual double ConclusivoTemporizado::tempoRestante() const;

	};
  }
}

#endif // !defined(CONCLUSIVO_TEMPORIZADO_AFX_CONCLUSIVO_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_)


