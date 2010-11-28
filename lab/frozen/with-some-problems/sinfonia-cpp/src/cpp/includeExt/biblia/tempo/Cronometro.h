/*
 * $RCSfile: Cronometro.h,v $
 * $Date: 2003/07/18 23:23:12 $
 * $Revision: 1.11 $
 *
 * Implementa��o da biblioteca B�blia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_CRONOMETRO_H__F5F25ECB_8F70_4724_8B59_6AD44B7A3C1E__INCLUDED_)
#define AFX_CRONOMETRO_H__F5F25ECB_8F70_4724_8B59_6AD44B7A3C1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/util/Debug.h"
#include "biblia/tempo/UniversoDeTempo.h"
#include "biblia/tempo/Intervalo.h"
#include "biblia/tempo/Momento.h"

namespace biblia {
  namespace tempo {

	/**
	 * � um {@link biblia::tempo::UniversoDeTempo
	 * universo de tempo} baseado em outro {@link
	 * biblia::tempo::UniversoDeTempo} (de prefer�ncia
	 * um {@link biblia::tempo::TempoGlobal}) que pode
	 * ser pausado, zerado e cont�m um intervalo desde
	 * a �ltima vez que foi zerado.
	 * <p>
	 * <i>Repare que essa 'recurs�o' pode ser
	 * interessant�ssima em alguns casos.</i>
	 *
	 * @see biblia::tempo::TempoGlobal
	 */
	class Cronometro: public UniversoDeTempo,
					  public Objeto
	{
		private:
			static long Cronometro::pIdGlobal;
			const long Cronometro::pId;
			const UniversoDeTempo& pTempo;
			bool Cronometro::pPausado;
			Momento Cronometro::pMomentoInicial;
			Momento Cronometro::pMomentoQuandoPausou;
			Intervalo Cronometro::pTempoParado;

		protected:
			virtual long Cronometro::id() const;

		public:
			/**
			 * Pode ser um cron�metro baseado
			 * em qualquer universo de tempo:
			 * outro {@link biblia::tempo::Cronometro
			 * cron�metro ou um {@link
			 * biblia::tempo::TempoGlobal}.
			 *
			 * @see biblia::tempo::TempoGlobal
			 */
			Cronometro::Cronometro(
					const UniversoDeTempo&,
					bool pausado);

			/**
			 * Faz uma c�pia exata.
			 */
			Cronometro::Cronometro(const Cronometro&);

			virtual Cronometro::~Cronometro();

			virtual const UniversoDeTempo&
					Cronometro::universo() const;

			virtual Cronometro& Cronometro::reset();
			virtual Cronometro& Cronometro::play();
			virtual Cronometro& Cronometro::pause();
			virtual Intervalo Cronometro::intervalo() const;
			virtual bool Cronometro::pausado() const;

			/* UniversoDeTempo */
			virtual Momento Cronometro::agora() const;

			virtual const UnidadeDeTempo&
					Cronometro::cadaPasso() const;

			virtual bool Cronometro::mesmoUniversoDeTempo(
					const UniversoDeTempo&) const;

			// Objeto:
			virtual std::string Cronometro::emString() const;
	};
  }
}

#endif // !defined(AFX_CRONOMETRO_H__F5F25ECB_8F70_4724_8B59_6AD44B7A3C1E__INCLUDED_)
