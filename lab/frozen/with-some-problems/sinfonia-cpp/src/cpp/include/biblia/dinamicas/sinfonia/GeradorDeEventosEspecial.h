/**
 * $RCSfile: GeradorDeEventosEspecial.h,v $
 * $Date: 2005/03/30 01:23:44 $
 * $Revision: 1.12 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_GERADORDEEVENTOSESPECIAL_H__DE19DBA4_80EA_4255_89BA_907A9C80C878__INCLUDED_)
#define AFX_GERADORDEEVENTOSESPECIAL_H__DE19DBA4_80EA_4255_89BA_907A9C80C878__INCLUDED_

#include "biblia/dinamicas/sinfonia/GeradorDeEventos.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Gera/Captura Eventos de uma forma espec�fica, definida
	 * por programa��o derivando-se desta classe.
	 * <p>
	 * Veja um exemplo de como um {@link Evento} pode
	 * ser lan�ado na documenta��o do {@link Evento}.
	 *
	 * @see Evento
	 * @see GeradorDeEventosDependente
	 */
	class GeradorDeEventosEspecial: public GeradorDeEventos {
		protected:
			/**
			 * Deve ter acesso a um {@link MediadorDeEstados}
			 * que deve sobreviver enquanto este vive: para se
			 * criar Eventos, � necess�rio ter acesso aos Estados.
			 *
			 * @see MediadorDeEstados
			 */
			GeradorDeEventosEspecial(const MediadorDeEstados&);

		public:
			virtual ~GeradorDeEventosEspecial();

			// Executavel:
			/**
			 * Gera eventos. Fica preso nesta fun��o
			 * at� que receba comando externo para
			 * {@link GeradorDeEventos#encerra encerrar}.
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop() = 0;
	};
  }
 }
}

#endif // !defined(AFX_GERADORDEEVENTOSESPECIAL_H__DE19DBA4_80EA_4255_89BA_907A9C80C878__INCLUDED_)
