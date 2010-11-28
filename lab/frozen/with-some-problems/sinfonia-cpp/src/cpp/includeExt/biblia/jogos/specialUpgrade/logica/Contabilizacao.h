/*
 * $RCSfile: Contabilizacao.h,v $
 * $Date: 2005/01/20 17:43:38 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_CONTABILIZACAO_H__3CA5650B_6646_4008_AE53_4E3787F30AC6__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_CONTABILIZACAO_H__3CA5650B_6646_4008_AE53_4E3787F30AC6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;


#include "biblia/jogos/specialUpgrade/logica/LogicaAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/jogos/specialUpgrade/dados/EstatisticaUtil.h"
#include "biblia/jogos/specialUpgrade/dados/DadosSpecial.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/jogos/specialUpgrade/logica/util/Premio.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/logica/LogicaCartelas.h"
#include "biblia/jogos/specialUpgrade/logica/PremioSurpresa.h"
using namespace biblia::jogos::specialUpgrade::logica;





namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
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
						//DadosSpecial& dados,
						EstatisticaUtil& estatistica,
						PremioSurpresa& premioSurpresa,
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
