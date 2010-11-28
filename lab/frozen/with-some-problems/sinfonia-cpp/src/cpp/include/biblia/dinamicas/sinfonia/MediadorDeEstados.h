/**
 * $RCSfile: MediadorDeEstados.h,v $
 * $Date: 2005/03/18 00:20:44 $
 * $Revision: 1.20 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_MEDIADORDEESTADOS_H__B20075BF_99EE_49C6_91CD_E138D36B75EB__INCLUDED_)
#define AFX_MEDIADORDEESTADOS_H__B20075BF_99EE_49C6_91CD_E138D36B75EB__INCLUDED_

#include <biblia/basico/Objeto.h>
using namespace biblia::basico;

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/tempo/Momento.h>
#include <biblia/tempo/UniversoDeTempo.h>
using namespace biblia::tempo;

#include <biblia/armazenamento/volatil/carcacas/MapaHash.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/dinamicas/sinfonia/Estado.h"
#include "biblia/dinamicas/sinfonia/Evento.h"
#include "biblia/dinamicas/sinfonia/EstadoDependente.h"
#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Exce��es relativas ao MediadorDeEstados.
	 *
	 * @see MediadorDeEstados
	 */
	class MediadorDeEstadosExcecao: public SinfoniaExcecao {};

	/**
	 * Quando se tenta acessar um Estado inexistente
	 * no MediadorDeEstados.
	 *
	 * @see MediadorDeEstados
	 */
	class EstadoInexistenteExcecao: public MediadorDeEstadosExcecao {};

	/**
	 * � quem cuida dos Estados. Os Estados s�o acessados
	 * atrav�s deste MediadorDeEstados que s� permite acesso somente-leitura
	 * ou permite tamb�m que seja enviado algum Evento para
	 * que este possa modificar os Estados, garantindo assim que
	 * exista um Evento nesse processo de mudan�a.
	 *
	 * @see Estado
	 * @see Evento
	 * @see Sinfonia
	 */
	class MediadorDeEstados: public Objeto {
		private:
			mutable MapaHash<Estado*> pEstados;
			mutable MapaHash<Estado*> pConstantes;
			Lista<Identificacao> pNomeEstados;
			const UniversoDeTempo& pUniverso;
			mutable Lixeira pLixo;
			MapaHash<bool> pJaExibiuEsteErro;
			MapaHash<bool> pJaExibiuEsteErro2;

		public:
			/**
			 * Nome usado para definir o estado do evento atual.
			 * @see #estadoDoEventoAtual
			 */
			static Valor ESTADO_DO_EVENTO_ATUAL;

			/**
			 * O UniversoDeTempo passado deve "sobreviver" enquanto
			 * este n�o "morre".
			 */
			MediadorDeEstados(const UniversoDeTempo&);
			virtual ~MediadorDeEstados();

			// Deve ser feito logo ap�s a cria��o, defini��es iniciais:

			/**
			 * Adiciona um {@link Estado} a este MediadorDeEstados. N�o � poss�vel
			 * adicionar Estado cujo nome completo j� tenha sido adicionado.
			 * Por padr�o, pega para si a responsabilidade de deletar o Estado.
			 *
			 * @throws ChaveJaExistenteExcecao Caso o {@link Estado} passado
			 *         j� tenha sido adicionado anteriormente.
			 */
			virtual MediadorDeEstados& adicionaEstado(
					Estado*, const bool& ficaResponsavelPelaDelecao = true);

			// Acesso ao Estado

			/**
			 * Retorna o nome de todos os Estados.
			 *
			 * @see #estado
			 */
			virtual const Lista<Identificacao>& nomeDeTodosEstados() const;

			/**
			 * Obt�m acesso somente-leitura de um Estado.
			 *
			 * @see #nomeDeTodosEstados
			 */
			virtual const Estado& estado(const Valor& nomeCompleto) const;

			/**
			 * Verifica se existe algum Estado criado com o nome
			 * passado como par�metro.
			 */
			virtual const bool existeEstado(const Valor& nomeCompleto) const;

			/**
			 * Cria um {@link EstadoDependente} que n�o deve ser deletado externamente.
			 * @see EstadoDependente#EstadoDependente
			 */
			virtual EstadoDependente* criaEstadoDependente(
					const Estado* baseadoEm, const Valor& campo
						= Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Obt�m um Estado constante de valor fixo passado como
			 * par�metro, geralmente usado para fazer compara��es constantes
			 * como [estado] = 56. No caso, 56 seria um Estado constante
			 * de valor 56.
			 * <p>
			 * Veja alternativa para valores constantes
			 * em {@link EstadoAlvo#constante}. Essa alternativa
			 * n�o � v�lida para Estados dependentes.
			 */
			virtual const Estado& estadoConstante(const Valor& valorDoEstado) const;

			/**
			 * Retorna uma refer�ncia para o local que ficar�
			 * o Estado do �ltimo Evento aplicado a este
			 * MediadorDeEstados. Esse Estado sempre conter� os
			 * mesmos campos e valores do Estado que ser�
			 * modificado pelo Evento em quest�o. <b>� uma
			 * pr�via do que aconteceria com o Estado ap�s
			 * a aplica��o do Evento passado na fun��o
			 * {@link #defineEstadoDoEventoAtual}.</b>
			 * <p>
			 * Um exemplo real:
			 *<pre>
	&lt;a��o do usu�rio&gt;
		& ![Cartelas.girando]
		& ![meio da jogada]
		& [preparado para jogar]
		& (<b>&lt;a��o do usu�rio&gt;</b> = jogar
		   | <b>&lt;a��o do usu�rio&gt;</b> = bola extra
		   | <b>&lt;a��o do usu�rio&gt;</b> = super turbo
		   | [tipo da jogada] = turbo
		   | ([Botoes.super turbo] = pressionado
			  & [tipo da jogada] = super turbo))
		-> &lt;pode jogar&gt;(V)
			   </pre>
				No exemplo, esta fun��o seria o <a��o do usu�rio>
				que est� dentro da condi��o.
			 *
			 * <br><i>
			 * Obs.: Suporte a mais de um campo
			 * ainda n�o implementado. S� usa o principal por enquanto.
			 * <br>
			 * Obs.2: O nome ser� sempre {@link MediadorDeEstados#ESTADO_DO_EVENTO_ATUAL}
			 * + a string do nome em quest�o.
			 * </i>
			 *
			 * @see #defineEstadoDoEventoAtual
			 */
			virtual const Estado& estadoDoEventoAtual(const Valor& nomeCompleto) const;

			/**
			 * Simula um Estado que pode ser lido pela fun��o
			 * {@link #estadoDoEventoAtual} de acordo com o {@link Evento}
			 * passado.
			 *
			 * @see #estadoDoEventoAtual
			 */
			virtual MediadorDeEstados& defineEstadoDoEventoAtual(const Evento&);

			/**
			 * S� � poss�vel aplicar Eventos que n�o s�o intermedi�rios,
			 * ou seja, modificam diretamente um Estado. Os Eventos intermedi�rios
			 * ser�o ignorados. --- Eventos que n�o est�o disparados tamb�m
			 * n�o podem ser aplicados, por�m nesse caso a exce��o
			 * EventoNaoDisparadoExcecao � lan�ada. Eventos que modificam
			 * estados que n�o existem ser�o ignorados por�m um warn ser�
			 * lan�ado ao sistema.
			 *
			 * @throws EventoNaoDisparadoExcecao
			 */
			virtual MediadorDeEstados& aplica(const Evento&);

			/**
			 * Retorna o UniversoDeTempo associado a este
			 * MediadorDeEstados.
			 */
			virtual inline const UniversoDeTempo& universo() const;
	};
  }
 }
}

#endif // !defined(AFX_MEDIADORDEESTADOS_H__B20075BF_99EE_49C6_91CD_E138D36B75EB__INCLUDED_)

/*
                         ,: . I: ,  . .                       
                           ..X##+   .  .                      
                        . : Y#. #:..  .                       
                          .Y#  .=#:  .                        
                      . ..I#, .. ;#...                        
                     ... I#  .    =#. .         ..      . .   
                   .  . t# . .  .  +#=            .       . ..
          .     .  . . t#   ,        #,..    ., .=.;tIVM#=.   
         .  . .    . .tW ..,:;+ItYXIIR#YXWMRRBBWBWBXI=;#X. . .
        .  . :;IYXW#RR##W##BXVIiI+t+=,t#  .. .        #Y     .
        ####WBIt=t,.;#.   . .      ..  =#: ..  .  ..:#:  .  . 
        ,#.   ..   =#..  .  .        .  =#; .. ..  Y#  .      
         :#=    . i#:. .  ..      . . .  i#: .    MW ,        
         .;#= .  +#=  .. .       .      ..=#. . .#V .  .      
        .. ,#+. .#+  ..          . .  , .. Y# .:#= ...        
          .. #=;#=    ,            .      . Y#t#, . . .       
         .  ..W#:                    . ..    ##   ,.  ..      
        .. , :##; . ,                      .#I+#..  . .       
        . ...#=:#=   ..            .    , ,#i  Y#.     ,      
        .. .#+  .#i .                 .  +#+ .. ;# . .,       
        . :#= .  ,#I , .          . .   Y#, ..  .I#.. ..      
         .#=   ..  #+. . .   .. .   . .WW  .  ,.  V# .        
 .,  ,   #:.     .  #I     .       . ,#t           t#.. .     
.  .. ,R##RBWMMBBMRYY#XYYVXYXVY+=;t.;#V;==;;;:;:;,:.R#.,      
     . ;:.::,.;;;.==;,#I.;;=::iYYI+##+itYVRBMWMBMMW#VBi       
. .      .    .  .    :#t   .    .YR   .         .     ,      
       . , .     . ...  #I   ... WB ..         .. .  .        
     .            .. .   #I ,  :#Y .. :    .     .            
       .. .  .  .   .  .. #I..+#; .   .        .     .        
           .   . .  .      #It#      . .           .  .       
                         :  WX.    .                          
                          . . ..           
*/