/**
 * $RCSfile: Resultado.h,v $
 * $Date: 2004/12/15 01:39:26 $
 * $Revision: 1.1 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_RESULTADO_H__E2A48A2D_FB56_4DF5_8D11_F2EFEC9F104A__INCLUDED_)
#define AFX_RESULTADO_H__E2A48A2D_FB56_4DF5_8D11_F2EFEC9F104A__INCLUDED_

#include <biblia/util/Debug.h>
using namespace biblia::util;

#include "biblia/dinamicas/sinfonia/Situacao.h"
#include "biblia/dinamicas/sinfonia/MediadorDeEstados.h"
#include "biblia/dinamicas/sinfonia/GeradorDeEventos.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * � um Resultado que est� associado a uma determinada
	 * Situacao. Pode ser executado e possui
	 * acesso aos estados atrav�s do {@link MediadorDeEstados
	 * mediador de estados}.
	 *
	 * @see Concretizador
	 * @see Situacao
	 */
	class Resultado: public Executavel, public Objeto {
		private:
			const MediadorDeEstados* pMediador;
			const Situacao* pSituacao;
			GeradorDeEventos* pGerador;

		protected:
			/**
			 * Cria um Resultado a partir de uma Situacao.
			 *
			 * @param s Esta classe <b>n�o</b> pegar� para si a responsabilidade
			 *          de deletar a situa��o passada.
			 *
			 * @see Situacao
			 */
			Resultado(const Situacao* s);

			/**
			 * A classe filha ter� acesso aos {@link Estado}s
			 * para realizar o que precisa.
			 */
			virtual const MediadorDeEstados& mediador() const;

			/**
			 * A classe filha deve adicionar os eventos gerados
			 * neste {@link GeradorDeEventos gerador}.
			 */
			virtual GeradorDeEventos& gerador();

		public:
			virtual const Situacao& situacao() const;

			/**
			 * Ser� chamado pelo {@link Concretizador}.
			 *
			 * @see Concretizador
			 * @see MediadorDeEstados
			 * @see GeradorDeEventosExterno
			 */
			virtual Resultado& define(const MediadorDeEstados&,
					GeradorDeEventos*);

			virtual ~Resultado();

			// Executavel:
			/**
			 * Executa este Resultado. Deve ser
			 * implementado pela classe filha.
			 * Esta fun��o s� deve ser chamada quando
			 * a {@link #situacao} ocorrer.
			 */
			virtual Executavel& executa() = 0;
	};
  }
 }
}

#endif // !defined(AFX_RESULTADO_H__E2A48A2D_FB56_4DF5_8D11_F2EFEC9F104A__INCLUDED_)
