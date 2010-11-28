/**
 * $RCSfile: MouseBiblia.h,v $
 * $Date: 2005/03/31 23:45:27 $
 * $Revision: 1.5 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
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
	 * Exce��es relativas � AnimacaoBiblia.
	 */
	class MouseBibliaExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, n�o
	 * foi poss�vel criar a MouseBiblia
	 * em quest�o.
	 */
	class ImpossivelCriarMouseBibliaExcecao: public MouseBibliaExcecao {};

	/**
	 * Representa um Mouse associado ao seu
	 * Estado correspondente. � associado (atrav�s do
	 * campo principal) ao nome
	 * de um Estado que deve possuir obrigatoriamente
	 * os campos <b>x</b>, <b>y</b> e <b>vis�vel</b>,
	 * que ser� a seta do mouse.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe �
	 * relacionada s�o:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - nome completo do Estado que deve
	 *                                possuir os campos
	 *                                <b>x</b>, <b>y</b> e <b>vis�vel</b>
	 *                                para serem modificados de
	 *								  acordo com a posi��o do mouse.
	 *
	 * <li><b>bot�o esquerdo pressionado</b>
	 * <li><b>bot�o direito pressionado</b>
	 * <li><b>bot�o central pressionado</b>
	 * <li><b>rodinha</b> - posi��o da rodinha do mouse
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

#endif // !defined(AFX_MOUSEBIBLIA_H__906D1F82_32FE_4A89_9EFF_819630AB4D00__INCLUDED_)
