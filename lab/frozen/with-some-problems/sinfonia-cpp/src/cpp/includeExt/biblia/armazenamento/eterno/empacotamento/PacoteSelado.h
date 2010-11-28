/*
 * $RCSfile: PacoteSelado.h,v $
 * $Date: 2005/01/20 21:28:33 $
 * $Revision: 1.8 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(PacoteSelado_h)
#define PacoteSelado_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/eterno/empacotamento/Pacote.h"
#include "biblia/armazenamento/volatil/carcacas/Dicionario.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace empacotamento {
		/**
  		 * É um Pacote identificado.
		 * <p>
		 * <i>Selado</i>
		 * nesse contexto não significa
		 * "fechado", "trancado", "concluído"
		 * mas significa "identificado",
		 * "estampado", "marcado" etc.
		 * <p>
		 * <b>selado</b>
		 * <i>de selo</i>
		 * adj.,
		 * que tem selo;
		 * <p>
		 * <b>selar</b>
		 * <i>de selo</i>
		 * v. tr.,
		 * pôr selo em;
		 * estampilhar;
		 * carimbar;
		 * aplicar um sinete em;
		 * tornar válido.
		 */
		class PacoteSelado: public Objeto {
			private:
				Identificacao PacoteSelado::pId;
				Pacote* PacoteSelado::pPacote;

				/**
				 * Proibido.
				 */
				PacoteSelado::PacoteSelado(const PacoteSelado&);

			public:
				/**
				 * Não pega para si a responsabilidade
				 * de deletar o pacote passado.
				 */
				PacoteSelado::PacoteSelado(
						const Identificacao&,
						Pacote*);

				virtual PacoteSelado::~PacoteSelado();

				virtual const Identificacao&
						PacoteSelado::identificacao() const;

				virtual const Pacote&
						PacoteSelado::pacote() const;

				// Objeto:
				virtual std::string PacoteSelado::emString() const;
		};
	  }
	}
  }
}

#endif /* PacoteSelado_h */
