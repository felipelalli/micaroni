/**
 * $RCSfile: SinfoniaExcecao.h,v $
 * $Date: 2005/01/05 23:30:35 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
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
	 * Exceções relativas à Sinfonia.
	 *
	 * @see Sinfonia
	 */
	class SinfoniaExcecao: public Excecao {};

	// * Obs.: Esta próxima classe está aqui porque a SinfoniaExcecao
	// é incluída por quase todos. Mas isso pode ser revisto.

	/**
	 * É um UniversoDeTempo que conta de um em um,
	 * para ser usado quando não se tem um UniversoDeTempo
	 * disponível.
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
