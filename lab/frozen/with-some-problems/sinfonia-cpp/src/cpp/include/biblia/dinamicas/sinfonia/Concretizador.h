/**
 * $RCSfile: Concretizador.h,v $
 * $Date: 2005/03/30 01:23:44 $
 * $Revision: 1.7 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_CONCRETIZADOR_H__2063F913_4CAA_46DD_8844_15D651840468__INCLUDED_)
#define AFX_CONCRETIZADOR_H__2063F913_4CAA_46DD_8844_15D651840468__INCLUDED_

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/fluxo/Semaforo.h>
#include <biblia/fluxo/Executavel.h>
using namespace biblia::fluxo;

#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"
#include "biblia/dinamicas/sinfonia/Resultado.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * � um GeradorDeEventos com v�rios resultados associados
	 * que poder�o ser executados. Toda vez que determinada
	 * {@link Situacao} atrelada a um {@link Resultado}
	 * ocorrer, esse {@link Resultado} ser� executado.
	 *
	 * @see Resultado
	 * @see GeradorDeEventos
	 * @see MediadorDeEstados
	 * @see GeradorDeEventosDependente
	 */
	class Concretizador: public GeradorDeEventos {
		private:
			MapaHash<Lista<Resultado*>*> pResultados;
			Semaforo pEsperaAcabar;
			Semaforo pEsperaExecutar;
			Lixeira pLixo;
			bool pAcabou;
			bool pExecutou;
			MapaHash<bool> pJaExibiuEsteErro;

		public:
			/**
			 * Deve ser passado a este um {@link MediadorDeEstados}
			 * que deve sobreviver enquanto este ainda vive.
			 */
			Concretizador(const MediadorDeEstados&);
			virtual ~Concretizador();

			/**
			 * Adiciona um {@link Resultado} a este Concretizador.
			 *
			 * @param r Esta classe <b>n�o</b> pegar� para si
			 *          a responsabilidade
			 *          de deletar o {@link Resultado} passado.
			 *
			 * @see Resultado
			 */
			virtual Concretizador& adiciona(Resultado* r);

			// Executavel:
			/**
			 * Fica em modo de espera at� que algum
			 * {@link Evento} aconte�a. Toda vez que acontecer,
			 * este executa o {@link Resultado} relacionado.
			 * <i>Deve ser executado em {@link Thread}
			 * para o fluxo n�o ficar preso nesta fun��o.</i>
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop();
	};
  }
 }
}

#endif // !defined(AFX_CONCRETIZADOR_H__2063F913_4CAA_46DD_8844_15D651840468__INCLUDED_)
