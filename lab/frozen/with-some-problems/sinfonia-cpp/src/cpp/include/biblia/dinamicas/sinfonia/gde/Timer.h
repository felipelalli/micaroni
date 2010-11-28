/**
 * $RCSfile: Timer.h,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.10 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_TIMER_H__1B515308_806D_491B_B1EB_3C75D8484F68__INCLUDED_)
#define AFX_TIMER_H__1B515308_806D_491B_B1EB_3C75D8484F68__INCLUDED_

#include <biblia/mais/allegro/Allegro.h>
using namespace biblia::mais::allegro;

#include <biblia/basico/Identificacao.h>
using namespace biblia::basico;

#include <biblia/tempo/Intervalo.h>
using namespace biblia::tempo;

#include <biblia/tempo/unidades/Segundo.h>
using namespace biblia::tempo::unidades;

#include "biblia/dinamicas/sinfonia/Estado.h"
#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"
#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"
using namespace biblia::dinamicas::sinfonia;

#include "biblia/dinamicas/sinfonia/util/Lock.h"
using namespace biblia::dinamicas::sinfonia::util;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace gde {
	/**
	 * Exce��es relativas ao Timer.
	 */
	class TimerExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, n�o foi poss�vel criar o timer
	 * em quest�o.
	 */
	class ImpossivelCriarTimerExcecao: public TimerExcecao {};

	/* CPPDOC_BEGIN_EXCLUDE */
	void timer(void* t);
	/* CPPDOC_END_EXCLUDE */

	/**
	 * � um Timer que lan�a um Evento que soma um (+1)
	 * a um Estado relacionado que � um contador de quantas vezes
	 * esse timer foi disparado. Pode estar em loop ou
	 * pode parar quando for disparado uma �nica vez.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe �
	 * relacionada s�o:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - quantas vezes esse
	 *     timer foi disparado. Inicia com 0 e o tempo total em execu��o em
	 *     milion�simos de segundo pode ser calculado multiplicando este campo
	 *     pelos campos <i>em milionesimos de segundo</i>
	 *     e <i>intervalo</i>.
	 * <li><b>em milion�simos de segundo</b> - rela��o da
	 *     unidade do intervalo deste timer para milion�simos de segundo.
	 *     O intervalo total em milion�simos de segundo deste timer
	 *     � esse campo vezes (�) o campo <i>intervalo</i>.
	 * <li><b>intervalo</b> - um n�mero que define o intervalo
	 *     que este timer ser� disparado. O intervalo total em
	 *     milion�simos de segundo � esse campo vezes
	 *     (�) o campo <i>em milionesimos de segundo</i>.
	 * <li><b>unidade</b> (opcional) - uma string definindo o nome da unidade. N�o
	 *     deve ser usado para c�lculos, � um valor meramente ilustrativo. Para
	 *     calcular o intervalo total em milion�simos de segundo use o campo
	 *     <i>em milionesimos de segundo</i> e <i>intervalo</i>.
	 * <li><b>loop</b> - define se este timer est� em loop ou n�o. Em loop
	 *     ele gera um {@link Evento} que soma 1 no campo principal
	 *     toda vez que passar o intervalo definido.
	 *     Caso contr�rio, este p�ra logo ap�s completar o intervalo.
	 * <li><b>iniciado</b> - se este timer est� em andamento ou n�o. Fica
	 *     verdadeiro toda vez que inicia e falso quando p�ra. Para iniciar
	 *     o Timer, � necess�rio lan�ar um {@link Evento} que o modifique
	 *     para verdadeiro, e para par�-lo um que o modifique para falso.
	 * <li><b>pausado</b> - se este timer est� pausado ou n�o. <b>fun��o
	 *     ainda n�o implementada!</b>
	 * <li><b>lan�a evento</b> - verdadeiro se este timer
	 *     deve lan�ar um evento para cada campo modificado ou falso caso
	 *     o {@link Estado} seja modificado diretamente sem que seja disparado
	 *     evento para a Sinfonia. Definir como falso pode otimizar bastante
	 *     o processamento da Sinfonia por�m limita bastante o uso dos recursos
	 *     de {@link Evento}s da Sinfonia.
	 * </ul>
	 */
	class Timer: public GeradorDeEventosEspecial {
		friend void timer(void*);

		private:
			Estado* pEstado;
			const UniversoDeTempo& pUniverso;
			int pQuantasVezes;
			Intervalo pIntervalo;
			bool pLancaEvento;
			bool pEmLoop;
			bool pIniciado;
			bool pEncerrou;
			bool pPausado;
			bool pIniciaParado;
			Semaforo pSemaTimer;

			class UnidadeGenerica: public UnidadeDeTempo {
				public:
					UnidadeGenerica(double milionesimosDeSegundo)
						:UnidadeDeTempo(milionesimosDeSegundo)
					{}

					UnidadeGenerica(double milionesimosDeSegundo,
									const Identificacao& nome)
						:UnidadeDeTempo(milionesimosDeSegundo, nome.emString())
					{}
			};

			Timer& defineEventosQueTrata();

		protected:
			/**
			 * P�ra de executar este timer.
			 */
			virtual Timer& para();

			/**
			 * Inicia a execu��o deste timer.
			 */
			virtual Timer& inicia();

		public:
			/**
			 * Cria um Timer diretamente relacionado a um
			 * {@link Estado} passado como par�metro. Esse
			 * {@link Estado} deve ser da classe {@link Multifuncional}
			 * e possuir os campos definidos na documenta��o principal
			 * desta classe, <b>com os valores iniciais j� preenchidos</b>.
			 * <p>
			 * O {@link Estado} passado � automaticamente definido como
			 * <b>externo</b> caso o campo <b>lan�a evento</b> seja falso.
			 * Este timer deve ser {@link #executa executado}
			 * uma vez em thread para funcionar.
			 *
			 * @throws ImpossivelCriarTimerExcecao � invocado quando
			 *         n�o h� informa��o suficiente para criar o Timer.
			 */
			Timer(const UniversoDeTempo&, const MediadorDeEstados&,
				  Estado* estadoRelacionado);

			/**
			 * Cria um Timer diretamente relacionado a um
			 * {@link Estado} passado como par�metro. Esse
			 * {@link Estado} deve ser da classe {@link Multifuncional}
			 * e possuir os campos definidos na documenta��o principal
			 * desta classe, <b>com os valores iniciais n�o necessariamente
			 * preenchidos</b>. Este construtor fica encarregado de definir
			 * esses campos atrav�s dos par�metros passados. <i>Obs.:
			 * Eles ser�o sobrescritos caso j� tenham sido definidos.</i>
			 * <p>
			 * O {@link Estado} passado � automaticamente definido como
			 * <b>externo</b> caso o campo <b>lan�a evento</b> seja falso.
			 * Este timer deve ser {@link #executa executado}
			 * uma vez em thread para funcionar.
			 */
			Timer(const UniversoDeTempo&, const MediadorDeEstados&,
				  Estado* estadoRelacionado,
				  const Intervalo&, const bool& lancaEvento,
				  const bool& emLoop, const bool& iniciaParado = true);

			virtual ~Timer();

			// Consulta:
			const Intervalo& intervalo() const;

			/**
			 * Indica se este Timer lan�a evento ou n�o. Se n�o
			 * lan�a, o {@link #estadoRelacionado Estado a este relacionado}
			 * � considerado externo.
			 */
			const bool& lancaEvento() const;

			const bool& emLoop() const;
			const bool& iniciado() const;
			const bool parado() const;
			const bool emAndamento() const;
			const bool& pausado() const;
			const int& quantasVezes() const;
			const Estado& estadoRelacionado() const;

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

#endif // !defined(AFX_TIMER_H__1B515308_806D_491B_B1EB_3C75D8484F68__INCLUDED_)
