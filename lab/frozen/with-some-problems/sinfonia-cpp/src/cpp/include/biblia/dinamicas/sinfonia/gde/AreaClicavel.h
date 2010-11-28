/**
 * $RCSfile: AreaClicavel.h,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_AREACLICAVEL_H__B744BEC3_0D74_4116_A46C_FC76FAF6A01F__INCLUDED_)
#define AFX_AREACLICAVEL_H__B744BEC3_0D74_4116_A46C_FC76FAF6A01F__INCLUDED_

#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"
using namespace biblia::dinamicas::sinfonia;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace gde {
	/**
	 * Exceções relativas à AreaClicavel.
	 */
	class AreaClicavelExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, não
	 * foi possível criar a AreaClicavel
	 * em questão.
	 */
	class ImpossivelCriarAreaClicavelExcecao: public AreaClicavelExcecao {};

	/**
	 * Representa uma área clicável na tela associado ao seu
	 * Estado correspondente. É associado (através do
	 * campo principal) ao nome do Estado do Mouse.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe é
	 * relacionada são:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - nome completo do Estado relativo
	 *                                ao Mouse.
	 *
	 * <li><b>x</b> - posição X da área retangular
	 * <li><b>y</b> - posição Y da área
	 * <li><b>largura</b>
	 * <li><b>altura</b>
	 * <li><b>habilitada</b>
	 * <li><b>mouse sobre</b> (somente leitura)
	 * <li><b>clicado sobre</b> (somente leitura)
	 * </ul>
	 */
	class AreaClicavel: public GeradorDeEventosEspecial {
		private:
			Estado* pEstado;
			const UniversoDeTempo& pTempo;

		public:
			AreaClicavel(const MediadorDeEstados&,
					 const UniversoDeTempo&,
					 Estado* estadoRelacionado);

			virtual ~AreaClicavel();

			// GeradorDeEventos:
			/**
			 * Deve ser executado uma única vez em Thread.
			 * Fica esperando algum {@link Evento} que corresponda
			 * com o {@link Estado} deste relacionado e toma
			 * as devidas providências.
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop();

			// Objeto:
			virtual string emString() const;
	};
   }
  }
 }
}

#endif // !defined(AFX_AREACLICAVEL_H__B744BEC3_0D74_4116_A46C_FC76FAF6A01F__INCLUDED_)
