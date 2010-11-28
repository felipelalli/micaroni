/**
 * $RCSfile: MouseBiblia.h,v $
 * $Date: 2005/03/31 23:45:27 $
 * $Revision: 1.5 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_MOUSEBIBLIA_H__906D1F82_32FE_4A89_9EFF_819630AB4D00__INCLUDED_)
#define AFX_MOUSEBIBLIA_H__906D1F82_32FE_4A89_9EFF_819630AB4D00__INCLUDED_

#include <biblia/mais/allegro/MouseAllegro.h>
using namespace biblia::mais::allegro;

#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"
using namespace biblia::dinamicas::sinfonia;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace gde {
	/**
	 * Exceções relativas à AnimacaoBiblia.
	 */
	class MouseBibliaExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, não
	 * foi possível criar a MouseBiblia
	 * em questão.
	 */
	class ImpossivelCriarMouseBibliaExcecao: public MouseBibliaExcecao {};

	/**
	 * Representa um Mouse associado ao seu
	 * Estado correspondente. É associado (através do
	 * campo principal) ao nome
	 * de um Estado que deve possuir obrigatoriamente
	 * os campos <b>x</b>, <b>y</b> e <b>visível</b>,
	 * que será a seta do mouse.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe é
	 * relacionada são:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - nome completo do Estado que deve
	 *                                possuir os campos
	 *                                <b>x</b>, <b>y</b> e <b>visível</b>
	 *                                para serem modificados de
	 *								  acordo com a posição do mouse.
	 *
	 * <li><b>botão esquerdo pressionado</b>
	 * <li><b>botão direito pressionado</b>
	 * <li><b>botão central pressionado</b>
	 * <li><b>rodinha</b> - posição da rodinha do mouse
	 * </ul>
	 */
	class MouseBiblia: public GeradorDeEventosEspecial {
		private:
			Estado* pEstado;
			string pNomeDoEstadoRelacionado;
			MouseAllegro pMa;
			const UniversoDeTempo& pTempo;

			class GeraEventosParaMouse: public Executavel {
				private:
					MouseBiblia* pMouseBiblia;
					bool pTermina;
					bool pTerminou;

				public:
					GeraEventosParaMouse();
					virtual void defineThis(MouseBiblia*);

					virtual GeraEventosParaMouse& termina();
					virtual const bool& terminou();

					// Executavel:
					virtual Executavel& executa();
			} pGeradorDeEventosParaMouse;

			Thread* pGeradorDeEventosParaMouseEmThread;
			friend GeraEventosParaMouse;

		public:
			MouseBiblia(const MediadorDeEstados&,
					 const UniversoDeTempo&,
					 Estado* estadoRelacionado);

			virtual ~MouseBiblia();

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

#endif // !defined(AFX_MOUSEBIBLIA_H__906D1F82_32FE_4A89_9EFF_819630AB4D00__INCLUDED_)
