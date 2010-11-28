/**
 * $RCSfile: Som.h,v $
 * $Date: 2005/03/30 01:23:45 $
 * $Revision: 1.3 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
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
	 * Exce��es relativas � SomBiblia.
	 */
	class SomBibliaExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, n�o
	 * foi poss�vel criar a SomBiblia
	 * em quest�o.
	 */
	class ImpossivelCriarSomBibliaExcecao: public SomBibliaExcecao {};

	/**
	 * Associa diretamente um Estado a uma anima��o da B�blia.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe �
	 * relacionada s�o:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - nome da anima��o.
	 * <li><b>x</b> (opcional) - posi��o X.
     * <li><b>y</b> (opcional) - posi��o Y.
	 * <li><b>vis�vel</b> (padr�o SIM)
	 * <li><b>quadros por segundo</b> (padr�o 10) - quantos quadros por segundo.
	 * <li><b>transpar�ncia</b> (opcional) - porcentagem de transparencia.
	 * <li><b>loop</b> (padr�o F) - define se esta anima��o est� em loop ou n�o. Em loop
	 *     ela n�o gera um {@link Evento} ao chegar no final.
	 *     Caso contr�rio, a anima��o p�ra logo ap�s completar o intervalo
	 *     e um Evento � lan�ado.
	 * <li><b>iniciado</b> (padr�o F) - se esta anima��o
	 *     est� em andamento ou n�o. Fica
	 *     verdadeiro toda vez que inicia e falso quando p�ra. Para iniciar
	 *     a Anima��o, � necess�rio lan�ar um {@link Evento} que o modifique
	 *     para verdadeiro, e para par�-lo um que o modifique para falso.
	 *     Toda vez que a anima��o chega no final e n�o est� em loop �
	 *     lan�ado um Evento que p�ra a anima��o.
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
			 * Cria uma Anima��o diretamente relacionada a um
			 * {@link Estado} passado como par�metro. Esse
			 * {@link Estado} deve ser da classe {@link Multifuncional}
			 * e possuir os campos definidos na documenta��o principal
			 * desta classe, <b>com os valores iniciais j� preenchidos</b>.
			 * A anima��o da b�blia a que esta classe est� relacionada
			 * deve estar previamente criada.
			 * <p>
			 * Esta anima��o deve ser {@link #executa executada}
			 * uma vez em Thread para funcionar.
			 *
			 * @throws ImpossivelCriarSomBibliaExcecao � invocado quando
			 *         n�o h� informa��o suficiente para criar a SomBiblia.
			 */
			SomBiblia(const MediadorDeEstados&,
					 ResultadoSonoro&,
					 CarregadorDeSom&,
					 const UniversoDeTempo&,
					 Estado* estadoRelacionado);

			virtual ~SomBiblia();

			/**
			 * Retorna a anima��o relacionada.
			 */
			virtual Som& somRelacionado() const;

			virtual const UniversoDeTempo& SomBiblia::tempo();

			/**
			 * Retorna o nome da anima��o relacionada.
			 */
			virtual const string& nomeDoSomRelacionado() const;

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

#endif // !defined(AFX_ANIMACAO_H__EBCEECAD_06D5_45B9_9427_4D9F355AD651__INCLUDED_)
