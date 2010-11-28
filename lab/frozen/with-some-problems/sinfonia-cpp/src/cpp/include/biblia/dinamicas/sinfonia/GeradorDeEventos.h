/**
 * $RCSfile: GeradorDeEventos.h,v $
 * $Date: 2005/03/30 01:23:44 $
 * $Revision: 1.19 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_GERADORDEEVENTOS_H__0376C5B0_E49F_4F61_8083_9827197CC1FD__INCLUDED_)
#define AFX_GERADORDEEVENTOS_H__0376C5B0_E49F_4F61_8083_9827197CC1FD__INCLUDED_

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include <biblia/fluxo/Semaforo.h>
#include <biblia/fluxo/Executavel.h>
using namespace biblia::fluxo;

#include <biblia/util/Debug.h>
using namespace biblia::util;

#include "biblia/dinamicas/sinfonia/util/Lock.h"
using namespace biblia::dinamicas::sinfonia::util;

#include "biblia/dinamicas/sinfonia/Evento.h"
#include "biblia/dinamicas/sinfonia/MediadorDeEstados.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * É responsável por trazer ao software
	 * Eventos que acontecem na Sinfonia. Pode
	 * gerar eventos de volta para a Sinfonia. Este tem acesso
	 * ao {@link MediadorDeEstados}.
	 * <p>
	 * <b>Sinfonia <---> Software</b>
	 *
	 * @see Evento
	 * @see Concretizador
	 * @see MediadorDeEstados
	 * @see Sinfonia
	 */
	class GeradorDeEventos: public Objeto, public Executavel {
		private:
			Semaforo pSemaforo, pSemaforo2;
			Semaforo pSynchronized1, pSynchronized2,
					 pSynchronized3, pSynchronized4;

			Lista<const Evento*> pEventosGerados;
			Lista<const Evento*> pEventosCapturados;
			Lista<Identificacao> pEventosQueTrata;
			const MediadorDeEstados& pMediadorDeEstados;
			bool pEncerrou;
			bool pApenasGerador;
			bool pEncerrouDeFato;
			bool pExecutou;

			/**
			 * Proibido.
			 */
			GeradorDeEventos(const GeradorDeEventos& gde)
				:pMediadorDeEstados(gde.mediadorDeEstados()),
				 pSemaforo(0), pSemaforo2(0),
				 pEncerrou(true),
				 pSynchronized1(1), pSynchronized2(1),
				 pSynchronized3(1), pSynchronized4(1),
				 pApenasGerador(false),
				 pEncerrouDeFato(true)
			{}

			virtual GeradorDeEventos& terminaLoopPrincipal();
			virtual GeradorDeEventos& iniciaLoopPrincipal();

		protected:
			/**
			 * Capta e gera eventos num loop
			 * até que este GeradorDeEventos se encerre.
			 * <i>Deve ser implementado pela classe filha.</i>
			 */
			virtual GeradorDeEventos& captaEGeraEmLoop() = 0;

			/**
			 * Deve ter acesso a um {@link MediadorDeEstados}
			 * que deve sobreviver enquanto este vive: para se
			 * criar Eventos, é necessário ter acesso aos Estados.
			 *
			 * @see #modificaEventosQueTrata
			 * @see MediadorDeEstados
			 */
			GeradorDeEventos(const MediadorDeEstados&,
					bool desabilitaAviso = false);

			// Captura de eventos:

			/**
			 * Fica em modo de espera até que seja gerado algum
			 * {@link Evento}. O {@link Evento} retornado
			 * deve ser deletado externamente. Pode retornar NULL
			 * caso seja {@link #encerra encerrado}.
			 */
			virtual const Evento* esperaAteQueVenhaEvento();

			/**
			 * Verifica quantos eventos estão na lista de espera
			 * para chegarem a este {@link GeradorDeEventos}.
			 */
			virtual const int quantosEventosEmEsperaParaVir() const;

			/**
			 * A classe filha desta deverá adicionar o nome
			 * de quais Eventos esta classe deve receber da
			 * Sinfonia para tratar. Caso não seja adicionado nada
			 * será entendido que ela deve receber todos os eventos
			 * da Sinfonia. Para que ela não receba <b>nenhum</b>
			 * evento a caracterizando como exclusivamente
			 * geradora de eventos (e não captadora) deverá ser
			 * chamada a função: {@link #naoDeveReceberNenhumEvento}.
			 *
			 * @see #naoDeveReceberNenhumEvento
			 */
			virtual Lista<Identificacao>& modificaEventosQueTrata();

			/**
			 * Indica que este gerador de eventos não captará
			 * nenhum Evento.
			 *
			 * @see #modificaEventosQueTrata
			 */
			virtual GeradorDeEventos& naoDeveReceberNenhumEvento();

		public:
			/**
			 * Chama {@link #encerra}(true).
			 */
			virtual ~GeradorDeEventos();
			
			// Para captar eventos:
			/**
			 * Esta função adiciona um {@link Evento} na
			 * lista que será consumida pela função
			 * {@link esperaAteQueVenhaEvento} e libera o
			 * semáforo que a está segurando.
			 * <p>
			 * Pega para si a responsabilidade de
			 * apagar o {@link Evento} passado, faça uma cópia
			 * ao passar.
			 *
			 * @throws EventoNaoDisparadoExcecao
			 */
			virtual GeradorDeEventos& aconteceu(const Evento* e);

			/**
			 * <i>Usado apenas pela Sinfonia.</i>
			 * Retorna uma lista com o nome dos Eventos
			 * que este GeradorDeEventos trata. Caso esteja
			 * vazia é porque este deve ser chamado em qualquer evento
			 * ou porque não capta nenhum evento (no caso de
			 * {@link #naoRecebeNenhumEvento} ser verdadeiro.
			 *
			 * @see #naoRecebeNenhumEvento
			 */
			virtual const Lista<Identificacao>& eventosQueTrata() const;

			/**
			 * <i>Usado apenas pela Sinfonia.</i>
			 * Se falso, este gerador de eventos
			 * também captura eventos.
			 *
			 * @see #eventosQueTrata
			 */
			virtual const bool& naoRecebeNenhumEvento() const;

			// Para gerar eventos:

			/**
			 * Esta função adiciona um {@link Evento} na
			 * lista que será consumida pela função
			 * {@link #esperaAteQueHajaEvento} e libera o
			 * semáforo que a está segurando.
			 * <p>
			 * É geralmente chamado pela classe filha, mas
			 * pode ser também chamado externamente.
			 *
			 * @param e Deve ser passado um {@link Evento} disparado
			 * e uma cópia que poderá ser deletada.
			 *
			 * @throws EventoNaoDisparadoExcecao
			 *
			 * @see #lancaIntermediario
			 * @see #lanca
			 * @see Evento
			 */
			virtual GeradorDeEventos& gera(const Evento* e);

			/**
			 * Lança um {@link Evento} intermediário
			 * de forma simplificada.
			 *
			 * @see #gera
			 */
			virtual GeradorDeEventos& lancaIntermediario(
					const Valor& nomeDoEvento);

			/**
			 * Lança um {@link Evento} que modifica
			 * um {@link Estado} de forma simplificada.
			 *
			 * @see #gera
			 */
			virtual GeradorDeEventos& lanca(
					const Valor& valor,
					const Valor& nomeDoEstado,
					const Valor& campo = Multifuncional::CAMPO_PRINCIPAL,
					const Identificacao& operacao = ModificadorDeEstado::APENAS_ATRIBUI);

			/**
			 * Fica em modo de espera até que seja gerado algum
			 * {@link Evento}. O {@link Evento}
			 * retornado <b>deve</b> ser deletado externamente.
			 * Pode retornar NULL caso seja
			 * {@link #encerra encerrado}.
			 * 
			 * @see Evento
			 */
			virtual const Evento* esperaAteQueHajaEvento();

			/**
			 * Retorna o número de Eventos que estão
			 * aguardando serem consumidos.
			 */
			virtual const int quantosEventosEmEspera() const;

			/**
			 * Indica que este GeradorDeEventos encerrou.
			 *
			 * @see #encerra
			 */
			virtual const bool encerrou() const;

			/**
			 * Encerra este GeradorDeEventos.
			 *
			 * @see #encerrou
			 * @see #~GeradorDeEventos
			 */
			virtual GeradorDeEventos& encerra();

			/**
			 * Acessa o {@link MediadorDeEstados} que este
			 * GeradorDeEventos carrega.
			 */
			virtual const MediadorDeEstados& mediadorDeEstados() const;

			// Executavel:

			/**
			 * Deve ser chamado para iniciar todo o processo.
			 *
			 * @see #captaEGeraEmLoop
			 */
			virtual Executavel& executa();
	};
  }
 }
}

#endif // !defined(AFX_GERADORDEEVENTOS_H__0376C5B0_E49F_4F61_8083_9827197CC1FD__INCLUDED_)
