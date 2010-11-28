/*
 * $RCSfile: Logicas.h,v $
 * $Date: 2005/01/19 17:22:14 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/mais/allegro/Allegro.h"
using namespace biblia::mais::allegro;

#if !defined(AGES_SPECIAL_UPGRADE_SBS_AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_)
#define AGES_SPECIAL_UPGRADE_SBS_AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#include "biblia/jogos/specialUpgrade/dados/DadosSpecial.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/jogos/specialUpgrade/dados/Dicionario.h"
#include "biblia/jogos/specialUpgrade/dados/DConfiguracao.h"
#include "biblia/jogos/specialUpgrade/dados/DadosConfiguracao.h"
#include "biblia/jogos/specialUpgrade/dados/EstatisticaUtil.h"
#include "biblia/jogos/specialUpgrade/dados/UltimasJogadas.h"
using namespace biblia::jogos::specialUpgrade::dados;

#include "biblia/jogos/specialUpgrade/io/rede/RedeSpecial.h"
using namespace biblia::jogos::specialUpgrade::io::rede;

#include "biblia/jogos/specialUpgrade/logica/LogicaAcumulado.h"
#include "biblia/jogos/specialUpgrade/logica/Contabilizacao.h"
#include "biblia/jogos/specialUpgrade/logica/util/ArqLogicaAcumulado.h"
using namespace biblia::jogos::specialUpgrade::logica::util;

#include "biblia/jogos/specialUpgrade/io/noteiro/Noteiro.h"
using namespace biblia::jogos::specialUpgrade::io::noteiro;

#include "biblia/jogos/specialUpgrade/logica/PremioSurpresa.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaBolas.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaCartelas.h"
#include "biblia/jogos/specialUpgrade/logica/LogicaBolaExtra.h"
#include "biblia/jogos/specialUpgrade/logica/GerenciadorDePremios.h"
using namespace biblia::jogos::specialUpgrade::logica;

#include "biblia/io/placaDelta/PlacaDelta.h"
using namespace biblia::io::placadelta;


namespace biblia {

  namespace jogos {

    namespace specialUpgrade {

	  namespace logica {

		class Logicas: public Objeto {
			private:
				GerenciadorDePremios pGerenciador;

				biblia::jogos::specialUpgrade::dados::Dicionario* pDicionario;
				biblia::jogos::specialUpgrade::dados::DadosConfiguracao* pConfiguracaoEmRede;
				biblia::jogos::specialUpgrade::dados::DConfiguracao* Logicas::pConf;
				biblia::jogos::specialUpgrade::dados::DHistorico* Logicas::pHistorico;
                biblia::jogos::specialUpgrade::dados::EstatisticaUtil* pEstatistica;

				biblia::jogos::specialUpgrade::logica::PremioSurpresa*  Logicas::pPremioSurpresa;
				biblia::jogos::specialUpgrade::logica::LogicaBolas*     Logicas::pBolas;
				biblia::jogos::specialUpgrade::logica::LogicaBolaExtra* Logicas::pBolaExtra;

				LogicaAcumulado* Logicas::pAcumulado;				
				LogicaCartelas*  Logicas::pCartelas;
				

				

				LogicaCredito* Logicas::pCreditos;
				Contabilizacao* Logicas::pContabilizacao;
				RedeSpecial* Logicas::pRede;

				biblia::jogos::specialUpgrade::io::noteiro::Noteiro* pNoteiro;

				bool Logicas::pJogandoSozinho;

			public:
				Logicas::Logicas(UniversoDeTempo& universoDeTempo,PlacaDelta* placaDelta);
				virtual Logicas::~Logicas();

				virtual LogicaAcumulado& Logicas::acumulado();
				virtual biblia::jogos::specialUpgrade::logica::LogicaBolas& Logicas::bolas();
				virtual LogicaCartelas& Logicas::cartelas();
				virtual GerenciadorDePremios& Logicas::gerenciador();

				virtual biblia::jogos::specialUpgrade::logica::LogicaBolaExtra& Logicas::bolaExtra();

				virtual LogicaCredito& Logicas::creditos();
				virtual Contabilizacao& Logicas::contabilizacao();
                virtual biblia::jogos::specialUpgrade::dados::EstatisticaUtil& Logicas::estatistica();
                virtual biblia::jogos::specialUpgrade::dados::DConfiguracao* configuracao() const;
				virtual biblia::jogos::specialUpgrade::dados::DadosConfiguracao* configuracaoEmRede();
				virtual biblia::jogos::specialUpgrade::dados::DHistorico * historico() const;
				virtual biblia::jogos::specialUpgrade::dados::UltimasJogadas& ultimasJogadas() const;

				biblia::jogos::specialUpgrade::logica::PremioSurpresa& Logicas::premioSurpresa();

				virtual biblia::jogos::specialUpgrade::io::noteiro::Noteiro* noteiro() const;

				virtual const LogicaAcumulado& Logicas::acumulado() const;
				virtual const biblia::jogos::specialUpgrade::logica::LogicaBolas& Logicas::bolas() const;
				virtual const LogicaCartelas& Logicas::cartelas() const;
				virtual const GerenciadorDePremios& Logicas::gerenciador() const;

				virtual const biblia::jogos::specialUpgrade::logica::LogicaBolaExtra& Logicas::bolaExtra() const;

				virtual const LogicaCredito& Logicas::creditos() const;
				virtual const Contabilizacao& Logicas::contabilizacao() const;
                virtual const biblia::jogos::specialUpgrade::dados::EstatisticaUtil& Logicas::estatistica() const;

				virtual bool Logicas::jogandoSozinho() const;
				virtual Logicas& Logicas::jogandoSozinho(bool);

				RedeSpecial& Logicas::rede(){
					return *this->pRede;
				}

		};
	  }
	}
  }
}

#endif // !defined(SBS_AFX_LOGICAS_H__5A5D2348_653D_4E58_9804_C15ABEDB6B60__INCLUDED_)
