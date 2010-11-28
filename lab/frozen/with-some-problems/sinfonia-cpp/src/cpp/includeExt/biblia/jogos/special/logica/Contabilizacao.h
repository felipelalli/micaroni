/*
 * $RCSfile: Contabilizacao.h,v $
 * $Date: 2003/07/21 19:40:47 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernando $)
 */

#if !defined(SBS_AFX_CONTABILIZACAO_H__3CA5650B_6646_4008_AE53_4E3787F30AC6__INCLUDED_)
#define SBS_AFX_CONTABILIZACAO_H__3CA5650B_6646_4008_AE53_4E3787F30AC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;


#include "biblia/jogos/special/logica/LogicaAcumulado.h"
using namespace biblia::jogos::special::logica;

#include "biblia/jogos/special/dados/EstatisticaUtil.h"
using namespace biblia::jogos::special::dados;

#include "biblia/jogos/bingo/logica/util/Premio.h"
using namespace biblia::jogos::bingo::logica::util;

#include "biblia/jogos/bingo/logica/LogicaCartelas.h"
using namespace biblia::jogos::bingo::logica;





namespace biblia {
  namespace jogos {
    namespace special {
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
						LogicaCartelas& lCartela,
						LogicaAcumulado& lAcumulado,
						biblia::jogos::special::dados::EstatisticaUtil& estatistica,
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

#endif // !defined(SBS_AFX_CONTABILIZACAO_H__3CA5650B_6646_4008_AE53_4E3787F30AC6__INCLUDED_)
