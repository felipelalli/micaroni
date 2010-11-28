/*
 * $RCSfile: Logicas.h,v $
 * $Date: 2004/05/17 21:58:58 $
 * $Revision: 1.11 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#if !defined(SBS_AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_)
#define SBS_AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;


#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/jogos/special/dados/Dicionario.h"
#include "biblia/jogos/special/dados/DConfiguracao.h"
#include "biblia/jogos/special/dados/DadosConfiguracao.h"
#include "biblia/jogos/special/dados/EstatisticaUtil.h"
#include "biblia/jogos/special/dados/UltimasJogadas.h"
using namespace biblia::jogos::special::dados;

#include "biblia/jogos/special/io/rede/RedeSpecial.h"
using namespace biblia::jogos::special::io::rede;

#include "biblia/jogos/special/logica/LogicaAcumulado.h"
#include "biblia/jogos/special/logica/Contabilizacao.h"
#include "biblia/jogos/special/logica/util/ArqLogicaAcumulado.h"
using namespace biblia::jogos::special::logica::util;

#include "biblia/jogos/special/io/noteiro/Noteiro.h"
using namespace biblia::jogos::special::io::noteiro;

#include "biblia/jogos/bingo/logica/LogicaBolas.h"
#include "biblia/jogos/bingo/logica/LogicaCartelas.h"
#include "biblia/jogos/bingo/logica/LogicaBolaExtra.h"
#include "biblia/jogos/bingo/logica/GerenciadorDePremios.h"
using namespace biblia::jogos::bingo::logica;



namespace biblia {

  namespace jogos {

    namespace special {

	  namespace logica {

		class Logicas: public Objeto {
			private:
				GerenciadorDePremios pGerenciador;
				biblia::jogos::special::dados::Dicionario* pDicionario;
				biblia::jogos::special::dados::DadosConfiguracao* pConfiguracaoEmRede;
				biblia::jogos::special::dados::DConfiguracao* Logicas::pConf;
				biblia::jogos::special::dados::DHistorico* Logicas::pHistorico;
                biblia::jogos::special::dados::EstatisticaUtil* pEstatistica;
				LogicaAcumulado* Logicas::pAcumulado;
				biblia::jogos::bingo::logica::LogicaBolas* Logicas::pBolas;
				LogicaCartelas* Logicas::pCartelas;

				biblia::jogos::bingo::logica::LogicaBolaExtra* Logicas::pBolaExtra;

				LogicaCredito* Logicas::pCreditos;
				Contabilizacao* Logicas::pContabilizacao;
				RedeSpecial* Logicas::pRede;

				biblia::jogos::special::io::noteiro::Noteiro* pNoteiro;

				bool Logicas::pJogandoSozinho;

			public:
				Logicas::Logicas(UniversoDeTempo& universoDeTempo,PlacaDelta* placaDelta);
				virtual Logicas::~Logicas();

				virtual LogicaAcumulado& Logicas::acumulado();
				virtual biblia::jogos::bingo::logica::LogicaBolas& Logicas::bolas();
				virtual LogicaCartelas& Logicas::cartelas();
				virtual GerenciadorDePremios& Logicas::gerenciador();

				virtual biblia::jogos::bingo::logica::LogicaBolaExtra& Logicas::bolaExtra();

				virtual LogicaCredito& Logicas::creditos();
				virtual Contabilizacao& Logicas::contabilizacao();
                virtual biblia::jogos::special::dados::EstatisticaUtil& Logicas::estatistica();
                virtual biblia::jogos::special::dados::DConfiguracao* configuracao() const;
				virtual biblia::jogos::special::dados::DadosConfiguracao* configuracaoEmRede();
				virtual biblia::jogos::special::dados::DHistorico * historico() const;
				virtual biblia::jogos::special::dados::UltimasJogadas& ultimasJogadas() const;

				virtual biblia::jogos::special::io::noteiro::Noteiro* noteiro() const;

				virtual const LogicaAcumulado& Logicas::acumulado() const;
				virtual const biblia::jogos::bingo::logica::LogicaBolas& Logicas::bolas() const;
				virtual const LogicaCartelas& Logicas::cartelas() const;
				virtual const GerenciadorDePremios& Logicas::gerenciador() const;

				virtual const biblia::jogos::bingo::logica::LogicaBolaExtra& Logicas::bolaExtra() const;

				virtual const LogicaCredito& Logicas::creditos() const;
				virtual const Contabilizacao& Logicas::contabilizacao() const;
                virtual const biblia::jogos::special::dados::EstatisticaUtil& Logicas::estatistica() const;

				virtual bool Logicas::jogandoSozinho() const;
				virtual Logicas& Logicas::jogandoSozinho(bool);

		};
	  }
	}
  }
}

#endif // !defined(SBS_AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_)
