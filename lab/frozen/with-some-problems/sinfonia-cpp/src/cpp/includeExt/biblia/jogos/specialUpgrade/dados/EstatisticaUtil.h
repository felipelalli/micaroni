/*
 * $RCSfile: EstatisticaUtil.h,v $
 * $Date: 2005/01/19 17:21:57 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef AGES_SPECIAL_UPGRADE_SBS_ESTATISTICA_UTIL_H_SW
#define AGES_SPECIAL_UPGRADE_SBS_ESTATISTICA_UTIL_H_SW

#include "biblia/basico/Objeto.h"
#include "biblia/util/CData.h"
#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaCredito.h"
#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
#include "biblia/jogos/specialUpgrade/dados/DEstatistica.h"
#include "biblia/jogos/specialUpgrade/dados/DHistorico.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::armazenamento::volatil;
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/jogos/specialUpgrade/logica/util/Premio.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

namespace biblia {
  namespace jogos {
    namespace specialUpgrade {
	  namespace dados {

		class EstatisticaUtil:public Objeto {

			private:
				DEstatistica* est;
				bool jogandoSozinho;

				void pGravaParcialOuGeral(const char* caminho, double valor, bool parcial=false, bool real=false);
			protected:				
				bool estaJogandoSozinho() const { return this->jogandoSozinho; }

			public:
				EstatisticaUtil::~EstatisticaUtil();
				EstatisticaUtil::EstatisticaUtil(DConfiguracao* configuracao,
								 bool simulado = false);

				EstatisticaUtil& EstatisticaUtil::jogaSozinho(bool = true);

				EstatisticaUtil& EstatisticaUtil::pagou(double quantoEmCreditos, bool dobro, bool bolaExtra);
				EstatisticaUtil& EstatisticaUtil::jogou(int cartelas);
				EstatisticaUtil& EstatisticaUtil::jogouGratis(int cartelas);

				EstatisticaUtil& EstatisticaUtil::ganhouPremioCartela();
				EstatisticaUtil& EstatisticaUtil::ganhouPremioCartelaDobro();

				EstatisticaUtil& EstatisticaUtil::jogouBolaExtra(int cartelas,int valor);
				EstatisticaUtil& EstatisticaUtil::foiParaBolaExtra();

				EstatisticaUtil& EstatisticaUtil::ofereceuBolaExtra();
				EstatisticaUtil& EstatisticaUtil::valorApostado(double valorApostado);

				EstatisticaUtil& EstatisticaUtil::deuPremio (biblia::jogos::specialUpgrade::logica::util::Premio& premio, bool dobro, int aposta);


				EstatisticaUtil& EstatisticaUtil::deuAcumulado(double valor);


				EstatisticaUtil& EstatisticaUtil::colocouNotaDe(int);
				EstatisticaUtil& EstatisticaUtil::parouDeJogar(int creditosAtuais);

				const char* EstatisticaUtil::strPagamentoManualParcial();

				Estatistica* EstatisticaUtil::getEstatistica(){
					return this->est;
				}
		};
	  }
	}
  }
}

#endif
