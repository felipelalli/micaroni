/*
 * $RCSfile: EstatisticaUtil.h,v $
 * $Date: 2004/06/09 15:45:24 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#ifndef SBS_ESTATISTICA_UTIL_H_SW
#define SBS_ESTATISTICA_UTIL_H_SW

#include "biblia/basico/Objeto.h"
#include "biblia/util/CData.h"
#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/jogos/special/logica/LogicaCredito.h"
#include "biblia/jogos/special/dados/DConfiguracao.h"
#include "biblia/jogos/special/dados/DEstatistica.h"
#include "biblia/jogos/special/dados/DHistorico.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::armazenamento::volatil;
using namespace biblia::jogos::special::logica;

#include "biblia/jogos/bingo/logica/util/Premio.h"
using namespace biblia::jogos::bingo::logica::util;

namespace biblia {
  namespace jogos {
    namespace special {
	  namespace dados {

		class EstatisticaUtil:public Objeto {

			private:
				DEstatistica* est;
				bool jogandoSozinho;

				void pGravaParcialOuGeral(const char* caminho, double valor, bool parcial=false, bool real=false);
			protected:
				EstatisticaUtil& EstatisticaUtil::pagou(double quantoEmCreditos, bool dobro, bool bolaExtra);
				bool estaJogandoSozinho() const { return this->jogandoSozinho; }

			public:
				EstatisticaUtil::~EstatisticaUtil();
				EstatisticaUtil::EstatisticaUtil(DConfiguracao* configuracao,
								 bool simulado = false);

				EstatisticaUtil& EstatisticaUtil::jogaSozinho(bool = true);

				EstatisticaUtil& EstatisticaUtil::jogou(int cartelas);
				EstatisticaUtil& EstatisticaUtil::jogouGratis(int cartelas);

				EstatisticaUtil& EstatisticaUtil::ganhouPremioCartela();
				EstatisticaUtil& EstatisticaUtil::ganhouPremioCartelaDobro();

				EstatisticaUtil& EstatisticaUtil::jogouBolaExtra(int cartelas,int valor);
				EstatisticaUtil& EstatisticaUtil::foiParaBolaExtra();

				EstatisticaUtil& EstatisticaUtil::ofereceuBolaExtra();
				EstatisticaUtil& EstatisticaUtil::valorApostado(double valorApostado);

				EstatisticaUtil& EstatisticaUtil::deuPremio (biblia::jogos::bingo::logica::util::Premio& premio, bool dobro, int aposta);


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
