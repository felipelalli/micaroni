/*
 * $RCSfile: Logicas.h,v $
 * $Date: 2004/05/17 21:58:59 $
 * $Revision: 1.19 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_)
#define AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/superbonus/dados/Dicionario.h"
#include "biblia/jogos/superbonus/dados/DConfiguracao.h"
#include "biblia/jogos/superbonus/dados/DadosConfiguracao.h"
#include "biblia/jogos/superbonus/io/rede/RedeSuperBonus.h"
#include "biblia/jogos/superbonus/logica/LogicaAcumulado.h"
#include "biblia/jogos/superbonus/logica/LogicaBolas.h"
#include "biblia/jogos/superbonus/logica/LogicaCartela.h"
#include "biblia/jogos/superbonus/logica/LogicaPremio.h"
#include "biblia/jogos/superbonus/logica/LogicaBolaExtra.h"
#include "biblia/jogos/superbonus/logica/Contabilizacao.h"
#include "biblia/jogos/superbonus/dados/EstatisticaUtil.h"
#include "biblia/jogos/superbonus/dados/UltimasJogadas.h"
#include "biblia/jogos/superbonus/logica/util/ArqLogicaAcumulado.h"

#include "biblia/jogos/superbonus/io/noteiro/Noteiro.h"
using namespace biblia::jogos::superbonus::io::noteiro;

using namespace biblia::basico;
using namespace biblia::jogos::superbonus::dados;
using namespace biblia::jogos::superbonus::io::rede;
using namespace biblia::jogos::superbonus::logica::util;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

using namespace biblia::jogos::superbonus::dados;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {

		class Logicas: public Objeto {
			private:
				Dicionario* pDicionario;
				DadosConfiguracao* pConfiguracaoEmRede;
				DConfiguracao* Logicas::pConf;
				DHistorico* Logicas::pHistorico;
                EstatisticaUtil* pEstatistica;
				LogicaAcumulado* Logicas::pAcumulado;
				LogicaBolas* Logicas::pBolas;
				LogicaCartela* Logicas::pCartelas;
				LogicaPremio* Logicas::pPremios;
				LogicaBolaExtra* Logicas::pBolaExtra;
				LogicaCredito* Logicas::pCreditos;
				ProbabilidadesDoJogo* Logicas::pProbabilidades;
				Contabilizacao* Logicas::pContabilizacao;
				RedeSuperBonus* Logicas::pRede;

				Noteiro* pNoteiro;

				bool Logicas::pJogandoSozinho;

			public:
				Logicas::Logicas(UniversoDeTempo& universoDeTempo,PlacaDelta* placa);
				virtual Logicas::~Logicas();

				virtual LogicaAcumulado& Logicas::acumulado();
				virtual LogicaBolas& Logicas::bolas();
				virtual LogicaCartela& Logicas::cartelas();
				virtual LogicaPremio& Logicas::premios();
				virtual LogicaBolaExtra& Logicas::bolaExtra();
				virtual LogicaCredito& Logicas::creditos();
				virtual Contabilizacao& Logicas::contabilizacao();
                virtual EstatisticaUtil& Logicas::estatistica();
                virtual DConfiguracao* configuracao() const;
				virtual DadosConfiguracao* configuracaoEmRede();
				virtual DHistorico * historico() const;
				virtual UltimasJogadas& ultimasJogadas() const;

				virtual Noteiro* noteiro() const;

				virtual const LogicaAcumulado& Logicas::acumulado() const;
				virtual const LogicaBolas& Logicas::bolas() const;
				virtual const LogicaCartela& Logicas::cartelas() const;
				virtual const LogicaPremio& Logicas::premios() const;
				virtual const LogicaBolaExtra& Logicas::bolaExtra() const;
				virtual const LogicaCredito& Logicas::creditos() const;
				virtual const Contabilizacao& Logicas::contabilizacao() const;
                virtual const EstatisticaUtil& Logicas::estatistica() const;

				virtual bool Logicas::jogandoSozinho() const;
				virtual Logicas& Logicas::jogandoSozinho(bool);

		};
	  }
	}
  }
}

#endif // !defined(AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_)
