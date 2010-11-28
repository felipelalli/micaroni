/*
 * $RCSfile: Processo.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.6 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_PROCESSO_H__BA3A5BCC_ADBF_4B19_81D4_41574A6D78FF__INCLUDED_)
#define AFX_PROCESSO_H__BA3A5BCC_ADBF_4B19_81D4_41574A6D78FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Objeto.h"
#include "biblia/util/CData.h"
#include "biblia/fluxo/Executavel.h"
#include "biblia/fluxo/Thread.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/unidades/Milissegundo.h"

using namespace biblia::basico;
using namespace biblia::util;
using namespace biblia::tempo;
using namespace biblia::tempo::unidades;

namespace biblia {
  namespace fluxo {

	/**
	 * Classe meramente auxiliar
	 * que representa um Processo
	 * baseado em um {@link
	 * biblia::fluxo::Executavel}.
	 * <p>
	 * Pode ser independente (baseado em Thread),
	 * pode ser em loop e pode ter um intervalo
	 * de tempo (sleep) entre cada loop.
	 * <p>
	 * Torna um {@link biblia::fluxo::Executavel}
	 * que tem fluxo �nico (in�cio, meio e fim) male�vel
	 * abrindo a possibilidade de fazer com que esse
	 * execut�vel seja executado em loop e em processo
	 * paralelo, utilizando {@link biblia::fluxo::Thread}.
	 *
	 * @see biblia::fluxo::Executavel
	 * @see biblia::fluxo::Thread
	 * @see biblia::fluxo::Temporizador
	 */
	class Processo: public Objeto, public Executavel {
		private:
			bool Processo::pLoop;
			bool Processo::pIndependente;
			bool Processo::pMandouParar;
			bool Processo::pParou;
			bool Processo::pIniciou;

			Executavel& Processo::pExecutavel;
			Thread* Processo::pThread;
			Intervalo Processo::pSleep;

		public:
			/**
			 * Cria um processo a partir de um
			 * execut�vel.
			 *
			 * @param e Execut�vel que este processo
			 *          est� apoiado. <i>N�o pode ser ele
			 *          mesmo</i>.
			 *
			 * @param independente Indica se este processo
			 *                     � independente. Se for,
			 *                     quando a fun��o executa
			 *                     for chamada uma Thread �
			 *                     criada e o fluxo continua.
			 *
			 * @param loop Indica que o processo est� em loop.
			 *             Se sim ele permanecer� no loop at�
			 *             que a fun��o para() seja invocada.
			 *
			 * @param tempoDeAtualizacao � o tempo que o processo
			 *                           ficar� em modo de espera
			 *                           ap�s executar o processo
			 *                           de cada loop.
			 */
			Processo::Processo(
					Executavel& e,
					bool independente = false,
					bool loop = false,
						Intervalo tempoDeAtualizacao
							= Intervalo(0, Milissegundo()));

			Processo::Processo(const Processo&);

			virtual Processo::~Processo();
			virtual Processo& Processo::para();
			virtual bool Processo::executando() const;

			// Executavel:
			virtual Executavel& Processo::executa();
	};
  }
}

#endif // !defined(AFX_PROCESSO_H__BA3A5BCC_ADBF_4B19_81D4_41574A6D78FF__INCLUDED_)
