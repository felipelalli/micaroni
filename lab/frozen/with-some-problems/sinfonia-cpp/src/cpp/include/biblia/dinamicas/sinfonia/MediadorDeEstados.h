/**
 * $RCSfile: MediadorDeEstados.h,v $
 * $Date: 2005/03/18 00:20:44 $
 * $Revision: 1.20 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
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
	 * Exceções relativas ao MediadorDeEstados.
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
	 * É quem cuida dos Estados. Os Estados são acessados
	 * através deste MediadorDeEstados que só permite acesso somente-leitura
	 * ou permite também que seja enviado algum Evento para
	 * que este possa modificar os Estados, garantindo assim que
	 * exista um Evento nesse processo de mudança.
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
			 * este não "morre".
			 */
			MediadorDeEstados(const UniversoDeTempo&);
			virtual ~MediadorDeEstados();

			// Deve ser feito logo após a criação, definições iniciais:

			/**
			 * Adiciona um {@link Estado} a este MediadorDeEstados. Não é possível
			 * adicionar Estado cujo nome completo já tenha sido adicionado.
			 * Por padrão, pega para si a responsabilidade de deletar o Estado.
			 *
			 * @throws ChaveJaExistenteExcecao Caso o {@link Estado} passado
			 *         já tenha sido adicionado anteriormente.
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
			 * Obtém acesso somente-leitura de um Estado.
			 *
			 * @see #nomeDeTodosEstados
			 */
			virtual const Estado& estado(const Valor& nomeCompleto) const;

			/**
			 * Verifica se existe algum Estado criado com o nome
			 * passado como parâmetro.
			 */
			virtual const bool existeEstado(const Valor& nomeCompleto) const;

			/**
			 * Cria um {@link EstadoDependente} que não deve ser deletado externamente.
			 * @see EstadoDependente#EstadoDependente
			 */
			virtual EstadoDependente* criaEstadoDependente(
					const Estado* baseadoEm, const Valor& campo
						= Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Obtém um Estado constante de valor fixo passado como
			 * parâmetro, geralmente usado para fazer comparações constantes
			 * como [estado] = 56. No caso, 56 seria um Estado constante
			 * de valor 56.
			 * <p>
			 * Veja alternativa para valores constantes
			 * em {@link EstadoAlvo#constante}. Essa alternativa
			 * não é válida para Estados dependentes.
			 */
			virtual const Estado& estadoConstante(const Valor& valorDoEstado) const;

			/**
			 * Retorna uma referência para o local que ficará
			 * o Estado do último Evento aplicado a este
			 * MediadorDeEstados. Esse Estado sempre conterá os
			 * mesmos campos e valores do Estado que será
			 * modificado pelo Evento em questão. <b>É uma
			 * prévia do que aconteceria com o Estado após
			 * a aplicação do Evento passado na função
			 * {@link #defineEstadoDoEventoAtual}.</b>
			 * <p>
			 * Um exemplo real:
			 *<pre>
	&lt;ação do usuário&gt;
		& ![Cartelas.girando]
		& ![meio da jogada]
		& [preparado para jogar]
		& (<b>&lt;ação do usuário&gt;</b> = jogar
		   | <b>&lt;ação do usuário&gt;</b> = bola extra
		   | <b>&lt;ação do usuário&gt;</b> = super turbo
		   | [tipo da jogada] = turbo
		   | ([Botoes.super turbo] = pressionado
			  & [tipo da jogada] = super turbo))
		-> &lt;pode jogar&gt;(V)
			   </pre>
				No exemplo, esta função seria o <ação do usuário>
				que está dentro da condição.
			 *
			 * <br><i>
			 * Obs.: Suporte a mais de um campo
			 * ainda não implementado. Só usa o principal por enquanto.
			 * <br>
			 * Obs.2: O nome será sempre {@link MediadorDeEstados#ESTADO_DO_EVENTO_ATUAL}
			 * + a string do nome em questão.
			 * </i>
			 *
			 * @see #defineEstadoDoEventoAtual
			 */
			virtual const Estado& estadoDoEventoAtual(const Valor& nomeCompleto) const;

			/**
			 * Simula um Estado que pode ser lido pela função
			 * {@link #estadoDoEventoAtual} de acordo com o {@link Evento}
			 * passado.
			 *
			 * @see #estadoDoEventoAtual
			 */
			virtual MediadorDeEstados& defineEstadoDoEventoAtual(const Evento&);

			/**
			 * Só é possível aplicar Eventos que não são intermediários,
			 * ou seja, modificam diretamente um Estado. Os Eventos intermediários
			 * serão ignorados. --- Eventos que não estão disparados também
			 * não podem ser aplicados, porém nesse caso a exceção
			 * EventoNaoDisparadoExcecao é lançada. Eventos que modificam
			 * estados que não existem serão ignorados porém um warn será
			 * lançado ao sistema.
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