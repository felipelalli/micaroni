/**
 * $RCSfile: Som.h,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AGES_BIBLIA_SINFONIA_SOM_H)
#define AGES_BIBLIA_SINFONIA_SOM_H

#include <biblia/io/som/ResultadoSonoro.h>
#include <biblia/io/som/CarregadorDeSom.h>
using namespace biblia::io::som;

#include "biblia/dinamicas/sinfonia/GeradorDeEventosEspecial.h"
using namespace biblia::dinamicas::sinfonia;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
   namespace gde {
	/**
	 * Exceções relativas à SomBiblia.
	 */
	class SomBibliaExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, não
	 * foi possível criar a SomBiblia
	 * em questão.
	 */
	class ImpossivelCriarSomBibliaExcecao: public SomBibliaExcecao {};

	/**
	 * Associa diretamente um Estado a uma animação da Bíblia.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe é
	 * relacionada são:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - nome da animação.
	 * <li><b>x</b> (opcional) - posição X.
     * <li><b>y</b> (opcional) - posição Y.
	 * <li><b>visível</b> (padrão SIM)
	 * <li><b>quadros por segundo</b> (padrão 10) - quantos quadros por segundo.
	 * <li><b>transparência</b> (opcional) - porcentagem de transparencia.
	 * <li><b>loop</b> (padrão F) - define se esta animação está em loop ou não. Em loop
	 *     ela não gera um {@link Evento} ao chegar no final.
	 *     Caso contrário, a animação pára logo após completar o intervalo
	 *     e um Evento é lançado.
	 * <li><b>iniciado</b> (padrão F) - se esta animação
	 *     está em andamento ou não. Fica
	 *     verdadeiro toda vez que inicia e falso quando pára. Para iniciar
	 *     a Animação, é necessário lançar um {@link Evento} que o modifique
	 *     para verdadeiro, e para pará-lo um que o modifique para falso.
	 *     Toda vez que a animação chega no final e não está em loop é
	 *     lançado um Evento que pára a animação.
	 * </ul>
	 */
	class SomBiblia: public GeradorDeEventosEspecial {
		private:
			CarregadorDeSom& pCarregadorDeSom;
			ResultadoSonoro& pResultadoSonoro;
			const UniversoDeTempo& pTempo;
			string pSomRelacionado;
			Estado* pEstado;

			class GeraEventosParaSom: public Executavel {
				private:
					SomBiblia* pSomBiblia;
					bool pTocandoAnterior;

					bool pTermina;
					bool pTerminou;

				public:
					GeraEventosParaSom();
					virtual void defineThis(SomBiblia*);
					virtual GeraEventosParaSom& termina();
					virtual const bool& terminou();

					// Executavel:
					virtual Executavel& executa();
			} pGeradorDeEventosParaSom;

			Thread pGeradorDeEventosParaSomEmThread;
			friend GeraEventosParaSom;

		public:
			/**
			 * Cria uma Animação diretamente relacionada a um
			 * {@link Estado} passado como parâmetro. Esse
			 * {@link Estado} deve ser da classe {@link Multifuncional}
			 * e possuir os campos definidos na documentação principal
			 * desta classe, <b>com os valores iniciais já preenchidos</b>.
			 * A animação da bíblia a que esta classe está relacionada
			 * deve estar previamente criada.
			 * <p>
			 * Esta animação deve ser {@link #executa executada}
			 * uma vez em Thread para funcionar.
			 *
			 * @throws ImpossivelCriarSomBibliaExcecao É invocado quando
			 *         não há informação suficiente para criar a SomBiblia.
			 */
			SomBiblia(const MediadorDeEstados&,
					 ResultadoSonoro&,
					 CarregadorDeSom&,
					 const UniversoDeTempo&,
					 Estado* estadoRelacionado);

			virtual ~SomBiblia();

			/**
			 * Retorna a animação relacionada.
			 */
			virtual Som& somRelacionado() const;

			virtual const UniversoDeTempo& SomBiblia::tempo();

			/**
			 * Retorna o nome da animação relacionada.
			 */
			virtual const string& nomeDoSomRelacionado() const;

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

#endif // !defined(AFX_ANIMACAO_H__EBCEECAD_06D5_45B9_9427_4D9F355AD651__INCLUDED_)
