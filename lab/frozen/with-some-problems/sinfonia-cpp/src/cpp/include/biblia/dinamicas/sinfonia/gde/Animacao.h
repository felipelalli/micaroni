/**
 * $RCSfile: Animacao.h,v $
 * $Date: 2005/03/31 23:45:27 $
 * $Revision: 1.5 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
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
	 * Exceções relativas à AnimacaoBiblia.
	 */
	class AnimacaoBibliaExcecao: public SinfoniaExcecao {};

	/**
	 * Quando, por algum motivo, não
	 * foi possível criar a AnimacaoBiblia
	 * em questão.
	 */
	class ImpossivelCriarAnimacaoBibliaExcecao: public AnimacaoBibliaExcecao {};

	/**
	 * Associa diretamente um Estado a uma animação da Bíblia.
	 * <p>
	 * Os campos do {@link Estado} a que esta classe é
	 * relacionada são:
	 * <br><ul>
	 * <li><b>(campo principal)</b> - nome da animação.
	 * <li><b>x</b> (opcional) - posição X.
     * <li><b>y</b> (opcional) - posição Y.
	 * <li><b>largura</b> (somente leitura) - largura da imagem.
	 * <li><b>altura</b> (somente leitura) - altura da imagem.
	 * <li><b>visível</b> (padrão SIM)
	 * <li><b>sentido inverso</b> (padrão NÃO)
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
	 *     Toda vez que a animação chega no final (ou início caso esteja
	 *     no sentido inverso) e não está em loop é
	 *     lançado um Evento que pára a animação.
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
			 * @throws ImpossivelCriarAnimacaoBibliaExcecao É invocado quando
			 *         não há informação suficiente para criar a AnimacaoBiblia.
			 */
			AnimacaoBiblia(const MediadorDeEstados&,
					 BasicoVisual&,
					 Estado* estadoRelacionado);

			virtual ~AnimacaoBiblia();

			/**
			 * Retorna a animação relacionada.
			 */
			virtual ComponenteGrafico<Video>&
					animacaoRelacionada() const;

			/**
			 * Retorna o nome da animação relacionada.
			 */
			virtual const string& nomeDaAnimacaoRelacionada() const;

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
