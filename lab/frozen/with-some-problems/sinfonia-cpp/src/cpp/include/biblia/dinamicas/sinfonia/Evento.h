/**
 * $RCSfile: Evento.h,v $
 * $Date: 2005/03/22 20:19:12 $
 * $Revision: 1.29 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
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
	 * Relativo � Evento.
	 * @see Evento
	 */
	class EventoExcecao: public SinfoniaExcecao {};

	/**
	 * Significa que se tentou usar opera��es exclusivas
	 * para Eventos que j� foram disparados.
	 *
	 * @see Evento
	 */
	class EventoNaoDisparadoExcecao: public EventoExcecao {};

	/**
	 * Significa que se tentou usar opera��es exclusivas
	 * para Eventos que n�o foram disparados.
	 *
	 * @see Evento
	 */
	class EventoDisparadoExcecao: public EventoExcecao {};

	/**
	 * Significa que se tentou usar opera��es exclusivas
	 * para Eventos que modificam um Estado diretamente.
	 *
	 * @see Evento
	 */
	class EventoIntermediarioExcecao: public EventoExcecao {};

	/**
	 * Um Evento � identificado por um nome (deriva de Rotulado)
	 * e pelo grupo a que pertence, e representa a mudan�a de um Estado
	 * ou algum acontecimento que disparar� outros Eventos.
	 * <p>
	 * Pode estar diretamente ligado a um Estado que ser� modificado
	 * por um ModificadorDeEstado (ver {@link #modificaEstadoDiretamente()})
	 * ou pode ser apenas um Evento {@link #intermediario() intermedi�rio}.
	 * <b>Por padr�o, se este Evento estiver relacionado de alguma forma
	 * a um {@link Estado}, mesmo sendo intermedi�rio, deve possuir o
	 * mesmo nome do {@link Estado}.</b>
	 * <p>
	 * Tamb�m pode estar {@link #disparado() "disparado"} ou pode ser
	 * "somente para consulta" no caso de n�o estar "disparado". "Disparado"
	 * significa que esse Evento foi disparado em algum momento.
	 * <p>
	 * Obs.: N�o � esta classe que associa um Evento a outros caso seja um Evento
	 * intermedi�rio. Para isso, veja {@link GeradorDeEventosDependente}.
	 * <p>
	 * Obs2.: � poss�vel que exista mais de um Evento com o mesmo nome e que
	 * um seja intermedi�rio e o outro n�o. Isso porque um Evento que
	 * modifica um Estado diretamente tamb�m pode ser usado como um
	 * intermedi�rio. Lembre-se que, diferente de um Estado, � poss�vel
	 * haver diversos Eventos com o mesmo nome, cada inst�ncia � uma
	 * representa��o do Evento em momentos diferentes ({@link #momentoDoDisparo()}).
	 * <p>
	 * Exemplo de lan�amento de um Evento:
	 * <pre>
	 {
		Valor nome("l�mpada acesa"); // nome do evento em quest�o
		nome.adicionaApelido("apaga"); // descri��o do evento
		ModificadorDeEstado mde(nome); // mde que modificar� o estado
		mde.adicionaValor(Valor(false)); // definindo o valor como falso, ou seja, apagar�
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
			 * intermedi�rio com o mesmo nome do Estado.
			 */
			static Evento criaEventoIntermediarioRelacionadoAEstado(const Estado&);

			/**
			 * Cria um Evento intermedi�rio rotulado com um nome
			 * que n�o modifica diretamente um Estado.
			 * Cri�-lo n�o significa dispar�-lo, para tal verifique
			 * a fun��o {@link #dispara}.
			 */
			Evento(const Valor& nome);

			/**
			 * Cria um Evento rotulado que modifica um Estado
			 * diretamente. Para cada Estado existem
			 * Eventos correspondentes que o modificam.
			 * Cri�-lo n�o significa dispar�-lo, para tal verifique
			 * a fun��o {@link #dispara}.
			 */
			Evento(const Valor& nome, const ModificadorDeEstado& mde);
			virtual ~Evento();

			/**
			 * O grupo a que este Evento pertence.
			 * Est� na forma de e. g.: "GrupoA.SubgrupoB"
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
			 * � o nome completo deste Evento que o identifica
			 * como �nico no universo. Este deve ser usado
			 * como chave em buscas de chaves �nicas.
			 * <p>
			 * Soma o grupo ao nome deste unido por
			 * um ponto. E. g.: "GrupoA.SubgrupoB.nome deste estado"
			 *
			 * @see #nome()
			 * @see #grupo()
			 */
			virtual const Valor nomeCompleto() const;

			/**
			 * Um Evento Especial pode ser lan�ado
			 * "a qualquer momento" sem constar na
			 * defini��o de din�mica dos Estados
			 * e Eventos.
			 * <p>
			 * Se � especial � lan�ado por um
			 * GeradorDeEventosEspecial
			 * ao inv�s de um GeradorDeEventosDependente.
			 */
			virtual const bool& especial() const;

			/**
			 * Define se � lan�ado por um
			 * GeradorDeEventosEspecial ao inv�s de
			 * um GeradorDeEventosDependente.
			 */
			virtual Evento& especial(const bool&);

			/**
			 * Indica que este Evento est� ligado diretamente
			 * a um Estado e pode ser {@link #executa() executado}.
			 *
			 * @see #intermediario()
			 */
			virtual const bool modificaEstadoDiretamente() const;

			/**
			 * Verifica se este Evento � intermedi�rio, ou seja,
			 * n�o modifica um Estado diretamete.
			 *
			 * @see #modificaEstadoDiretamente()
			 */
			virtual const bool intermediario() const {
				return !this->modificaEstadoDiretamente();
			}

			/**
			 * Deve ser invocado toda vez que este Evento
			 * for disparado. Cria uma c�pia deste (deve
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
			 *         S� � poss�vel se este evento n�o for intermedi�rio.
			 */
			virtual const ModificadorDeEstado& modificador() const;

			/**
			 * Fun��o aux�lio: sup�e que este Evento
			 * modifica diretamente
			 * um Estado e que possui um s� par�metro no
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
			 * Se o nome completo � igual e:
			 * <br>- algum dos dois � um intermedi�rio;
			 * <br>ou
			 * <br>- se os Modificadores de Estado internos s�o iguais.
			 */
			virtual const bool igual(const Igualavel& alheio) const;

			// Objeto:
			/**
			 * Se possui um apelido, coloca-o na frente do nome
			 * original, como: "deixa de estar &lt;preparado para jogar&gt;".
			 * Caso contr�rio, coloca o nome do evento seguido
			 * pelos par�metros (se houver), como por exemplo:
			 * &lt;preparado para jogar&gt;(V). Com o nome do Evento
			 * sempre entre menor e maior. --- Se este Evento
			 * for disparado ({@link #disparado()}) o Momento
			 * ser� anexado ao final da string. --- Se este Evento
			 * for {@link #especial}, um asterisco (&#42) ser� adicionado
			 * ao in�cio da string, e. g.: "&#42 &lt;preparado para jogar&gt;(V)".
			 * Se possuir a��o diferente de "apenas atribui��o" ela ser�
			 * colocada assim: "&lt;preparado para jogar&gt;a��o(1)" e se
			 * possir campo diferente do principal ele ser� colocado assim:
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
