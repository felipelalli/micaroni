/*
 * $RCSfile: EstatisticaUtil.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef ESTATISTICA_UTIL_H_SW
#define ESTATISTICA_UTIL_H_SW

#include "biblia/basico/Objeto.h"
#include "biblia/util/CData.h"
#include "biblia/armazenamento/volatil/Lista.h"
#include "biblia/jogos/superbonus/logica/LogicaCredito.h"
#include "biblia/jogos/superbonus/logica/LogicaPremio.h"
#include "biblia/jogos/superbonus/logica/Premio.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/jogos/superbonus/dados/DEstatistica.h"
#include "biblia/jogos/superbonus/dados/DHistorico.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::armazenamento::volatil;
using namespace biblia::jogos::superbonus::logica;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace dados {

		class EstatisticaUtil:public Objeto {

			private:
				DEstatistica* est;
				LogicaPremio* premio;
				bool jogandoSozinho;

				void pGravaParcialOuGeral(const char* caminho, double valor, bool parcial=false, bool real=false);
			protected:
				EstatisticaUtil& EstatisticaUtil::pagou(double quantoEmDinheiro);
				bool estaJogandoSozinho() const { return this->jogandoSozinho; }

			public:
				EstatisticaUtil::~EstatisticaUtil();
				EstatisticaUtil::EstatisticaUtil(DConfiguracao* configuracao,
								 LogicaPremio* logicaPremio,
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

				EstatisticaUtil& EstatisticaUtil::deuCantos();
				EstatisticaUtil& EstatisticaUtil::deuLinha();
				EstatisticaUtil& EstatisticaUtil::deuLinhaDupla();
				EstatisticaUtil& EstatisticaUtil::deuBingo();
				EstatisticaUtil& EstatisticaUtil::deuAcumulado(double valor,double valorInicial);
				EstatisticaUtil& EstatisticaUtil::deuLinhaDuplaNaBolaExtra();
				EstatisticaUtil& EstatisticaUtil::deuBingoNaBolaExtra();
				EstatisticaUtil& EstatisticaUtil::deuCantosNoDobro();
				EstatisticaUtil& EstatisticaUtil::deuLinhaNoDobro();
				EstatisticaUtil& EstatisticaUtil::deuLinhaDuplaNoDobro();
				EstatisticaUtil& EstatisticaUtil::deuBingoNoDobro();

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
