/**
 * $RCSfile: RegraDeEstados.h,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.4 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_REGRADEESTADOS_H__CB8E6459_B260_4C46_95F9_350F07CC0092__INCLUDED_)
#define AFX_REGRADEESTADOS_H__CB8E6459_B260_4C46_95F9_350F07CC0092__INCLUDED_

#include <biblia/tempo/UniversoDeTempo.h>
using namespace biblia::tempo;

#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"
using namespace biblia::dinamicas::sinfonia;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace gde {
	/**
	 * Cria uma regra entre determinados estados. Os estados
	 * adicionados a esta tem que ser boleanos e somente
	 * um pode estar verdadeiro. Assim, quando um for definido como verdadeiro
	 * este {@link GeradorDeEventosEspecial} gera
	 * os {@link Evento}s para definir os outros
	 * como falso.
	 */
	class RegraDeEstados: public GeradorDeEventosEspecial {
		private:
			const UniversoDeTempo& pTempo;

		public:
			/**
			 * Cria uma regra de estados.
			 *
			 * @param exclusivosEntreSi Se os estados são exclusivos entre si,
			 *        i. e., se um se tornar verdadeiro, os outros tornar-se-ão
			 *        falsos.
			 */
			RegraDeEstados(const MediadorDeEstados&,
						   const UniversoDeTempo&);

			virtual ~RegraDeEstados();

			/**
			 * Adiciona um {@link Estado} a esta regra.
			 */
			virtual RegraDeEstados& adicionaEstado(const Valor& nomeCompletoDoEstado);

			// GeradorDeEventos:

			/**
			 * Deve ser executado uma vez em Thread.
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop();
	};
   }
  }
 }
}

#endif // !defined(AFX_REGRADEESTADOS_H__CB8E6459_B260_4C46_95F9_350F07CC0092__INCLUDED_)
