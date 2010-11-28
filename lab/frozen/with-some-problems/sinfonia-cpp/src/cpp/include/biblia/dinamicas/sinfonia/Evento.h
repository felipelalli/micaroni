/**
 * $RCSfile: Evento.h,v $
 * $Date: 2005/03/22 20:19:12 $
 * $Revision: 1.29 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_EVENTO_H__447AB505_F632_43E7_9C18_E0804E717F4F__INCLUDED_)
#define AFX_EVENTO_H__447AB505_F632_43E7_9C18_E0804E717F4F__INCLUDED_

#include <string>
using namespace std;

#include <biblia/fluxo/Thread.h>
using namespace biblia::fluxo;

#include <biblia/basico/Igualavel.h>
using namespace biblia::basico;

#include <biblia/tempo/Momento.h>
#include <biblia/tempo/Intervalo.h>
#include <biblia/tempo/UniversoDeTempo.h>
using namespace biblia::tempo;

#include <biblia/tempo/unidades/Milissegundo.h>
using namespace biblia::tempo::unidades;

#include "biblia/dinamicas/sinfonia/Rotulado.h"
#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"
#include "biblia/dinamicas/sinfonia/ModificadorDeEstado.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Relativo à Evento.
	 * @see Evento
	 */
	class EventoExcecao: public SinfoniaExcecao {};

	/**
	 * Significa que se tentou usar operações exclusivas
	 * para Eventos que já foram disparados.
	 *
	 * @see Evento
	 */
	class EventoNaoDisparadoExcecao: public EventoExcecao {};

	/**
	 * Significa que se tentou usar operações exclusivas
	 * para Eventos que não foram disparados.
	 *
	 * @see Evento
	 */
	class EventoDisparadoExcecao: public EventoExcecao {};

	/**
	 * Significa que se tentou usar operações exclusivas
	 * para Eventos que modificam um Estado diretamente.
	 *
	 * @see Evento
	 */
	class EventoIntermediarioExcecao: public EventoExcecao {};

	/**
	 * Um Evento é identificado por um nome (deriva de Rotulado)
	 * e pelo grupo a que pertence, e representa a mudança de um Estado
	 * ou algum acontecimento que disparará outros Eventos.
	 * <p>
	 * Pode estar diretamente ligado a um Estado que será modificado
	 * por um ModificadorDeEstado (ver {@link #modificaEstadoDiretamente()})
	 * ou pode ser apenas um Evento {@link #intermediario() intermediário}.
	 * <b>Por padrão, se este Evento estiver relacionado de alguma forma
	 * a um {@link Estado}, mesmo sendo intermediário, deve possuir o
	 * mesmo nome do {@link Estado}.</b>
	 * <p>
	 * Também pode estar {@link #disparado() "disparado"} ou pode ser
	 * "somente para consulta" no caso de não estar "disparado". "Disparado"
	 * significa que esse Evento foi disparado em algum momento.
	 * <p>
	 * Obs.: Não é esta classe que associa um Evento a outros caso seja um Evento
	 * intermediário. Para isso, veja {@link GeradorDeEventosDependente}.
	 * <p>
	 * Obs2.: É possível que exista mais de um Evento com o mesmo nome e que
	 * um seja intermediário e o outro não. Isso porque um Evento que
	 * modifica um Estado diretamente também pode ser usado como um
	 * intermediário. Lembre-se que, diferente de um Estado, é possível
	 * haver diversos Eventos com o mesmo nome, cada instância é uma
	 * representação do Evento em momentos diferentes ({@link #momentoDoDisparo()}).
	 * <p>
	 * Exemplo de lançamento de um Evento:
	 * <pre>
	 {
		Valor nome("lâmpada acesa"); // nome do evento em questão
		nome.adicionaApelido("apaga"); // descrição do evento
		ModificadorDeEstado mde(nome); // mde que modificará o estado
		mde.adicionaValor(Valor(false)); // definindo o valor como falso, ou seja, apagará
		Evento&#42 apagaLampada = Evento(mde).dispara(universoDeTempo); // dispara o Evento
		algumGeradorDeEventos->gera(apagaLampada); // gera o evento em si
	 }
	   </pre>
	 * @see ModificadorDeEstado
	 * @see Estado
	 * @see GeradorDeEventos
     * @see GeradorDeEventosDependente
     *
	 * @version $Revision: 1.29 $, $Date: 2005/03/22 20:19:12 $ (GMT-3)
	 * @author <a href="mailto:micaroni@gmail.com?subject=$RCSfile: Evento.h,v $">Felipe Micaroni Lalli</a>
	 * @author modificado por $Author: felipelalli $
	 */
	class Evento: public Rotulado, public Igualavel, public Copiavel {
		private:
			ModificadorDeEstado* pModificador;
			Momento* pMomento;
			bool pEspecial;
			Valor pGrupo;

		protected:
			/**
			 * Para copiar, use {@link #geraCopia}.
			 */
			Evento(const Evento&);

		public:
			/**
			 * A partir de um {@link Estado}, cria um {@link Evento}
			 * intermediário com o mesmo nome do Estado.
			 */
			static Evento criaEventoIntermediarioRelacionadoAEstado(const Estado&);

			/**
			 * Cria um Evento intermediário rotulado com um nome
			 * que não modifica diretamente um Estado.
			 * Criá-lo não significa dispará-lo, para tal verifique
			 * a função {@link #dispara}.
			 */
			Evento(const Valor& nome);

			/**
			 * Cria um Evento rotulado que modifica um Estado
			 * diretamente. Para cada Estado existem
			 * Eventos correspondentes que o modificam.
			 * Criá-lo não significa dispará-lo, para tal verifique
			 * a função {@link #dispara}.
			 */
			Evento(const Valor& nome, const ModificadorDeEstado& mde);
			virtual ~Evento();

			/**
			 * O grupo a que este Evento pertence.
			 * Está na forma de e. g.: "GrupoA.SubgrupoB"
			 *
			 * @see #nome()
			 * @see #nomeCompleto()
			 */
			virtual const Valor& grupo() const;

			/**
			 * Define o grupo a que este Evento pertence. Deve
			 * estar na forma de e. g.: "GrupoA.SubgrupoB"
			 */
			virtual Evento& grupo(const Valor&);

			/**
			 * É o nome completo deste Evento que o identifica
			 * como único no universo. Este deve ser usado
			 * como chave em buscas de chaves únicas.
			 * <p>
			 * Soma o grupo ao nome deste unido por
			 * um ponto. E. g.: "GrupoA.SubgrupoB.nome deste estado"
			 *
			 * @see #nome()
			 * @see #grupo()
			 */
			virtual const Valor nomeCompleto() const;

			/**
			 * Um Evento Especial pode ser lançado
			 * "a qualquer momento" sem constar na
			 * definição de dinâmica dos Estados
			 * e Eventos.
			 * <p>
			 * Se é especial é lançado por um
			 * GeradorDeEventosEspecial
			 * ao invés de um GeradorDeEventosDependente.
			 */
			virtual const bool& especial() const;

			/**
			 * Define se é lançado por um
			 * GeradorDeEventosEspecial ao invés de
			 * um GeradorDeEventosDependente.
			 */
			virtual Evento& especial(const bool&);

			/**
			 * Indica que este Evento está ligado diretamente
			 * a um Estado e pode ser {@link #executa() executado}.
			 *
			 * @see #intermediario()
			 */
			virtual const bool modificaEstadoDiretamente() const;

			/**
			 * Verifica se este Evento é intermediário, ou seja,
			 * não modifica um Estado diretamete.
			 *
			 * @see #modificaEstadoDiretamente()
			 */
			virtual const bool intermediario() const {
				return !this->modificaEstadoDiretamente();
			}

			/**
			 * Deve ser invocado toda vez que este Evento
			 * for disparado. Cria uma cópia deste (deve
			 * ser deletado externamente) e retorna.
			 *
			 * @see #momentoDoDisparo()
			 */
			virtual Evento* dispara(const UniversoDeTempo&) const;

			/**
			 * Verifica se este Evento foi disparado
			 * em algum momento.
			 *
			 * @see #momentoDoDisparo()
			 */
			virtual const bool disparado() const;

			/**
			 * Retorna o momento em que este Evento foi
			 * disparado.
			 *
			 * @throws EventoNaoDisparadoExcecao
			 * @see #disparado()
			 * @see #dispara
			 */
			virtual const Momento& momentoDoDisparo() const;

			/**
			 * @throws EventoIntermediarioExcecao
			 *         Só é possível se este evento não for intermediário.
			 */
			virtual const ModificadorDeEstado& modificador() const;

			/**
			 * Função auxílio: supõe que este Evento
			 * modifica diretamente
			 * um Estado e que possui um só parâmetro no
			 * modificador.
			 *
			 * @throws EventoIntermediarioExcecao
			 * @throws IndiceForaDeIntervaloListaExcecao
			 */
			virtual const Valor parametro() const {
				return this->modificador().parametroUnico().valorAlvo();
			}

			// Igualavel:
			/**
			 * Se o nome completo é igual e:
			 * <br>- algum dos dois é um intermediário;
			 * <br>ou
			 * <br>- se os Modificadores de Estado internos são iguais.
			 */
			virtual const bool igual(const Igualavel& alheio) const;

			// Objeto:
			/**
			 * Se possui um apelido, coloca-o na frente do nome
			 * original, como: "deixa de estar &lt;preparado para jogar&gt;".
			 * Caso contrário, coloca o nome do evento seguido
			 * pelos parâmetros (se houver), como por exemplo:
			 * &lt;preparado para jogar&gt;(V). Com o nome do Evento
			 * sempre entre menor e maior. --- Se este Evento
			 * for disparado ({@link #disparado()}) o Momento
			 * será anexado ao final da string. --- Se este Evento
			 * for {@link #especial}, um asterisco (&#42) será adicionado
			 * ao início da string, e. g.: "&#42 &lt;preparado para jogar&gt;(V)".
			 * Se possuir ação diferente de "apenas atribuição" ela será
			 * colocada assim: "&lt;preparado para jogar&gt;ação(1)" e se
			 * possir campo diferente do principal ele será colocado assim:
			 * "&lt;preparado para jogar&gt;(campo=V)".
			 */
			virtual string emString() const;

			// Copiavel:
			virtual Objeto* geraCopia() const;
			virtual Copiavel& copiaEmSi(const Copiavel& alheio);
	};
  }
 }
}

#endif // !defined(AFX_EVENTO_H__447AB505_F632_43E7_9C18_E0804E717F4F__INCLUDED_)

/*

                       .RW.   .  .             
                     +### .  .               
                 .  i#W+##  .                
                   t#M  I#B                  
           .     .i#M    R#I                 
         .  .    i#W     .M#=                
               .t##        ##:               
          .   .+#W    .  . .##   .           
              t#B.   .    . ;##.             
           . i#M.    .     . t#B.            
         . .t#W    .         .Y#Y:           
           i#M           .  . .B#+           
          I#B.                  ##:          
         t#B.                    ## . .      
       .I##.,:::ttttiIVRVXRBM######M .       
      .,#MW#####BRXRRRYtttt+=;:,:,:          
       . .     .           .        . 

*/
