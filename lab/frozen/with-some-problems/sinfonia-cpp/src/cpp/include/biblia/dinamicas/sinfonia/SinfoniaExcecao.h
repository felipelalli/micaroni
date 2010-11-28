/**
 * $RCSfile: SinfoniaExcecao.h,v $
 * $Date: 2005/01/05 23:30:35 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */
#if !defined(AFX_SINFONIAEXCECAO_H__D4A22FAC_DA5B_4404_B002_F45B651E0C0F__INCLUDED_)
#define AFX_SINFONIAEXCECAO_H__D4A22FAC_DA5B_4404_B002_F45B651E0C0F__INCLUDED_

#include <biblia/basico/Excecao.h>
using namespace biblia::basico;

#include <biblia/tempo/UniversoDeTempo.h>
#include <biblia/tempo/UnidadeDeTempo.h>
using namespace biblia::tempo;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Exce��es relativas � Sinfonia.
	 *
	 * @see Sinfonia
	 */
	class SinfoniaExcecao: public Excecao {};

	// * Obs.: Esta pr�xima classe est� aqui porque a SinfoniaExcecao
	// � inclu�da por quase todos. Mas isso pode ser revisto.

	/**
	 * � um UniversoDeTempo que conta de um em um,
	 * para ser usado quando n�o se tem um UniversoDeTempo
	 * dispon�vel.
	 */
	class UniversoSequencial: public UniversoDeTempo {
		private:
			static int pVezes;

			static class Vezes: public UnidadeDeTempo {
				public:
					Vezes();
					virtual ~Vezes();
			} pPasso;

		public:
			virtual Momento agora() const;
			virtual const UnidadeDeTempo& cadaPasso() const;
			virtual bool mesmoUniversoDeTempo(const UniversoDeTempo&) const;
	};
  }
 }
}

#endif // !defined(AFX_SINFONIAEXCECAO_H__D4A22FAC_DA5B_4404_B002_F45B651E0C0F__INCLUDED_)
