/*
 * $RCSfile: Contabilizacao.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.9 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CONTABILIZACAO_H__3CA5650B_6646_4008_AE53_4E3787F30AC6__INCLUDED_)
#define AFX_CONTABILIZACAO_H__3CA5650B_6646_4008_AE53_4E3787F30AC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/superbonus/logica/LogicaCartela.h"
#include "biblia/jogos/superbonus/logica/LogicaPremio.h"
#include "biblia/jogos/superbonus/logica/LogicaBolaExtra.h"
#include "biblia/jogos/superbonus/logica/LogicaAcumulado.h"
#include "biblia/jogos/superbonus/dados/EstatisticaUtil.h"

using namespace biblia::basico;
using namespace biblia::jogos::superbonus::dados;


namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {
		class Contabilizacao: public Objeto {
			private:
				int Contabilizacao::pSaldo;
				int Contabilizacao::pJogadasGratis;
				bool pContabilizou;

				bool pDeuAcumulado;
				double pValorAcumulado;

			public:
				Contabilizacao::Contabilizacao();
				virtual Contabilizacao::~Contabilizacao();

				virtual Contabilizacao& Contabilizacao::contabilizaPremios(
						LogicaCartela& lCartela,
						LogicaPremio& lPremio,
						LogicaBolaExtra& lBolaExtra,
						LogicaAcumulado& lAcumulado,
						EstatisticaUtil& estatistica,
						bool bonus,
						bool jogandoSozinho);

				virtual int Contabilizacao::saldo() const;
				virtual int Contabilizacao::jogadasGratis() const;
				virtual bool Contabilizacao::contabilizou();
				virtual Contabilizacao& Contabilizacao::zerar();
				virtual bool Contabilizacao::deuAcumulado();
				virtual double Contabilizacao::valorAcumulado();
		};
	  }
	}
  }
}

#endif // !defined(AFX_CONTABILIZACAO_H__3CA5650B_6646_4008_AE53_4E3787F30AC6__INCLUDED_)
