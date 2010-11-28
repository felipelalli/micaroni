/**
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
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
	 * É um {@link GeradorDeEventosEspecial} que tem a seguinte
	 * característica adicional: sempre quando lança um
	 * evento é bloqueado, não lançando mais eventos
	 * até que seja desbloqueado novamente. O nome
	 * do Estado de bloqueio deve ser passado como parâmetro
	 * no contrutor.
	 *
	 * Quando o Evento capturado tiver sido processado externamente
	 * por completo, deve ser lançado um evento
	 * Evento(instanciaDestaClasse.estadoDeBloqueio()
	 *        .nomeCompleto(), ModificadorDeEstado(false)) para que a
	 * instância libere os próximos eventos. Caso esse evento nunca
	 * for lançado, a função ficará eternamente bloqueada.
	 *
	 * Atenção: é necessário que a classe filha adicione o
	 * estado relacionado ao bloqueio nos "eventos a tratar"
	 * através da função this->modificaEventosQueTrata().adiciona(...)
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
			 *        passado estiver definido como "true" ele está
			 *        bloqueado, caso contrário desbloqueado.
			 */
			GeradorDeEventosBloqueavel(const MediadorDeEstados&,
					const Valor& nomeCompletoDoEstadoDeBloqueio);

			/**
			 * Sempre bloqueia após liberar um evento.
			 */
			virtual GeradorDeEventosBloqueavel& dizQueEstaBloqueado();

			/**
			 * Recebeu um sinal de desbloqueio, libera
			 * próximo evento.
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
			 * Retorna o Estado de bloqueio cujo nome é
			 * passado no construtor desta classe.
			 */
			virtual const Estado& estadoDeBloqueio() const;

			// GeradorDeEventos:
			/**
			 * Não retorna enquanto estiver bloqueado.
			 */
			virtual const Evento* esperaAteQueHajaEvento();

			/**
			 * Libera o semáforo de bloqueio.
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
