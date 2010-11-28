/**
 * $RCSfile: Animacao.h,v $
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

#if !defined(AFX_ANIMACAO_H__EBCEECAD_06D5_45B9_9427_4D9F355AD651__INCLUDED_)
#define AFX_ANIMACAO_H__EBCEECAD_06D5_45B9_9427_4D9F355AD651__INCLUDED_

#include <biblia/mais/allegro/BasicoVisualAllegro.h>
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
	class AnimacaoBibliaExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, n�o
	 * foi poss�vel criar a AnimacaoBiblia
	 * em quest�o.
	 */
	class ImpossivelCriarAnimacaoBibliaExcecao: public AnimacaoBibliaExcecao {};

	/**
	 * Associa diretamente um Estado a uma anima��o da B�blia.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe �
	 * relacionada s�o:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - nome da anima��o.
	 * <li><b>x</b> (opcional) - posi��o X.
     * <li><b>y</b> (opcional) - posi��o Y.
	 * <li><b>largura</b> (somente leitura) - largura da imagem.
	 * <li><b>altura</b> (somente leitura) - altura da imagem.
	 * <li><b>vis�vel</b> (padr�o SIM)
	 * <li><b>sentido inverso</b> (padr�o N�O)
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
	 *     Toda vez que a anima��o chega no final (ou in�cio caso esteja
	 *     no sentido inverso) e n�o est� em loop �
	 *     lan�ado um Evento que p�ra a anima��o.
	 * </ul>
	 */
	class AnimacaoBiblia: public GeradorDeEventosEspecial {
		private:
			BasicoVisual& pVisual;
			string pAnimacaoRelacionada;
			Estado* pEstado;

			class GeraEventosParaAnimacao: public Executavel {
				private:
					AnimacaoBiblia* pAnimacaoBiblia;
					bool pFimAnterior;

					bool pTermina;
					bool pTerminou;

				protected:
					const bool fim() const;

				public:
					GeraEventosParaAnimacao();
					virtual void defineThis(AnimacaoBiblia*);
					virtual GeraEventosParaAnimacao& termina();
					virtual const bool& terminou();

					// Executavel:
					virtual Executavel& executa();
			} pGeradorDeEventosParaAnimacao;

			Thread* pGeradorDeEventosParaAnimacaoEmThread;
			friend GeraEventosParaAnimacao;

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
			 * @throws ImpossivelCriarAnimacaoBibliaExcecao � invocado quando
			 *         n�o h� informa��o suficiente para criar a AnimacaoBiblia.
			 */
			AnimacaoBiblia(const MediadorDeEstados&,
					 BasicoVisual&,
					 Estado* estadoRelacionado);

			virtual ~AnimacaoBiblia();

			/**
			 * Retorna a anima��o relacionada.
			 */
			virtual ComponenteGrafico<Video>&
					animacaoRelacionada() const;

			/**
			 * Retorna o nome da anima��o relacionada.
			 */
			virtual const string& nomeDaAnimacaoRelacionada() const;

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
