/**
 * $RCSfile: AreaClicavel.h,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
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
	 * Exce��es relativas � AreaClicavel.
	 */
	class AreaClicavelExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, n�o
	 * foi poss�vel criar a AreaClicavel
	 * em quest�o.
	 */
	class ImpossivelCriarAreaClicavelExcecao: public AreaClicavelExcecao {};

	/**
	 * Representa uma �rea clic�vel na tela associado ao seu
	 * Estado correspondente. � associado (atrav�s do
	 * campo principal) ao nome do Estado do Mouse.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe �
	 * relacionada s�o:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - nome completo do Estado relativo
	 *                                ao Mouse.
	 *
	 * <li><b>x</b> - posi��o X da �rea retangular
	 * <li><b>y</b> - posi��o Y da �rea
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
			 * Deve ser executado uma �nica vez em Thread.
			 * Fica esperando algum {@link Evento} que corresponda
			 * com o {@link Estado} deste relacionado e toma
			 * as devidas provid�ncias.
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
