/**
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Space
 * Ages Software e Tecnologia, julho de 2005.
 */

#ifndef biblia_dinamicas_sinfonia_GeradorDeEventosBloqueavel
#define biblia_dinamicas_sinfonia_GeradorDeEventosBloqueavel

#include <biblia/fluxo/Semaforo.h>
using namespace biblia::fluxo;

#include "biblia/dinamicas/sinfonia/Valor.h"
#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
    /**
	 * � um {@link GeradorDeEventosEspecial} que tem a seguinte
	 * caracter�stica adicional: sempre quando lan�a um
	 * evento � bloqueado, n�o lan�ando mais eventos
	 * at� que seja desbloqueado novamente. O nome
	 * do Estado de bloqueio deve ser passado como par�metro
	 * no contrutor.
	 *
	 * Quando o Evento capturado tiver sido processado externamente
	 * por completo, deve ser lan�ado um evento
	 * Evento(instanciaDestaClasse.estadoDeBloqueio()
	 *        .nomeCompleto(), ModificadorDeEstado(false)) para que a
	 * inst�ncia libere os pr�ximos eventos. Caso esse evento nunca
	 * for lan�ado, a fun��o ficar� eternamente bloqueada.
	 *
	 * Aten��o: � necess�rio que a classe filha adicione o
	 * estado relacionado ao bloqueio nos "eventos a tratar"
	 * atrav�s da fun��o this->modificaEventosQueTrata().adiciona(...)
	 */
	class GeradorDeEventosBloqueavel
			:public GeradorDeEventosEspecial
	{
		private:
			Semaforo pBloqueio;
			Semaforo pLockIda;
			Semaforo pLockVolta;
			Valor pNomeCompletoDoEstadoDeBloqueio;

		protected:
			/**
			 * @param nomeCompletoDoEstadoDeBloqueio Se o estado
			 *        passado estiver definido como "true" ele est�
			 *        bloqueado, caso contr�rio desbloqueado.
			 */
			GeradorDeEventosBloqueavel(const MediadorDeEstados&,
					const Valor& nomeCompletoDoEstadoDeBloqueio);

			/**
			 * Sempre bloqueia ap�s liberar um evento.
			 */
			virtual GeradorDeEventosBloqueavel& dizQueEstaBloqueado();

			/**
			 * Recebeu um sinal de desbloqueio, libera
			 * pr�ximo evento.
			 */
			virtual GeradorDeEventosBloqueavel& desbloqueia();

			// GeradorDeEventos:
			/**
			 * Para interceptar o evento de desbloqueio.
			 */
			virtual const Evento* esperaAteQueVenhaEvento();

		public:
			virtual ~GeradorDeEventosBloqueavel();

			/**
			 * Retorna o Estado de bloqueio cujo nome �
			 * passado no construtor desta classe.
			 */
			virtual const Estado& estadoDeBloqueio() const;

			// GeradorDeEventos:
			/**
			 * N�o retorna enquanto estiver bloqueado.
			 */
			virtual const Evento* esperaAteQueHajaEvento();

			/**
			 * Libera o sem�foro de bloqueio.
			 */
			virtual GeradorDeEventos& encerra();

			// GeradorDeEventosEspecial:
			/**
			 * Desbloqueia quando recebe um evento
			 * relacionado ao {@link #estadoDeBloqueio}
			 * definindo-o como Valor(false).
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop() = 0;
	};
  }
 }
}

#endif
