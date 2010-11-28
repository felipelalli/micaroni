/*
 * $RCSfile: ConclusivoDeConclusivos.h,v $
 * $Date: 2005/01/20 21:28:42 $
 * $Revision: 1.7 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_ConclusivoDeConclusivos_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_)
#define AFX_ConclusivoDeConclusivos_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include "biblia/fluxo/Conclusivo.h"

using namespace std;

namespace biblia {
  namespace fluxo {

    /**
     * Um ConclusivoDeConclusivos é um {@link
	 * biblia::fluxo::Conclusivo} baseado em outros
	 * {@link biblia::fluxo::Conclusivo conclusivos}.
	 * <p>
	 * Será iniciado quando algum deles iniciar e será
	 * concluído quando todos estiverem concluídos.
	 *
	 * @see biblia::fluxo::Conclusivo
	 */
	 class ConclusivoDeConclusivos: public Conclusivo {
		private:
			std::deque<const Conclusivo*> ConclusivoDeConclusivos
					::pConclusivos;

			std::deque<bool> ConclusivoDeConclusivos
					::pDeletarNoFinal;

		protected:
			const std::deque<const Conclusivo*>& ConclusivoDeConclusivos
					::conclusivos() const;

		public:
			ConclusivoDeConclusivos::ConclusivoDeConclusivos();
			virtual ConclusivoDeConclusivos::~ConclusivoDeConclusivos();

			virtual ConclusivoDeConclusivos& ConclusivoDeConclusivos
					::adiciona(const Conclusivo&, bool deletarNoFinal);

			// Conclusivo:
			virtual Conclusivo& ConclusivoDeConclusivos::conclui();
			virtual Conclusivo& ConclusivoDeConclusivos::inicia();

			virtual Conclusivo& ConclusivoDeConclusivos::progresso(
					double porcentagem);

			virtual Conclusivo& ConclusivoDeConclusivos::progresso(
					int parte, int todo);

			virtual bool ConclusivoDeConclusivos::concluido() const;
			virtual bool ConclusivoDeConclusivos::iniciou() const;

			/**
			 * Retorna o progresso do teste em porcentagem.
			 */
			virtual double ConclusivoDeConclusivos::porcentagem() const;

	};
  }
}

#endif // !defined(AFX_ConclusivoDeConclusivos_H__EB2C6DC6_5FA3_4C25_B8AA_162A2CBFE7D2__INCLUDED_)
