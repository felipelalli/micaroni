/*
 * $RCSfile: TempoGlobal.h,v $
 * $Date: 2003/06/10 19:16:53 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#if !defined(AFX_TEMPOGLOBAL_H__A6514CDE_D28E_4B80_B829_2D621D66FC0B__INCLUDED_)
#define AFX_TEMPOGLOBAL_H__A6514CDE_D28E_4B80_B829_2D621D66FC0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Interface.h"
#include "biblia/tempo/Momento.h"
#include "biblia/tempo/UnidadeDeTempo.h"
#include "biblia/tempo/UniversoDeTempo.h"

namespace biblia {
  namespace tempo {

	/**
	 * Representa um tempo global para controle
	 * de tudo que precisa utilizar o tempo numa
	 * aplicação. Este tempo supõe que o tempo só
	 * passa, nunca retrocede.
	 */
	class TempoGlobal: public UniversoDeTempo {
		protected:
			TempoGlobal::TempoGlobal();

		public:
			virtual TempoGlobal::~TempoGlobal();

			/**
			 * Define que este tempo global está
			 * acelerado em <i>n</i> vezes. Se o valor
			 * for zero, o efeito é o mesmo de se
			 * dar pause.
			 *
			 * @throws ValorNegativoTempoExcecao
			 *         É invocado caso o número de
			 *         vezes seja negativo.
			 */
			virtual TempoGlobal& TempoGlobal
					::acelerado(const double& vezes) = 0;

			/**
			 * Retorna 1 para normal, < 1 para desacelerado
			 * e > 1 para acelerado. O valor retornado
			 * sempre é > 0.
			 */
			virtual const double& TempoGlobal
					::acelerado() const = 0;

			virtual TempoGlobal& TempoGlobal::proximoPasso() = 0;

			/**
			 * Reinicia o os cronometros.
			 */
			virtual TempoGlobal& TempoGlobal::reinicia() { return *this; }

			/* Universo de Tempo */

			virtual Momento TempoGlobal::agora() const = 0;

			virtual const UnidadeDeTempo&
					TempoGlobal::cadaPasso() const = 0;

			virtual bool TempoGlobal::mesmoUniversoDeTempo(
					const UniversoDeTempo&) const = 0;
	};
  }
}

#endif // !defined(AFX_TEMPOGLOBAL_H__A6514CDE_D28E_4B80_B829_2D621D66FC0B__INCLUDED_)
