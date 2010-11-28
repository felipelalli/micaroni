/**
 * $RCSfile: Estado.h,v $
 * $Date: 2005/03/07 21:31:45 $
 * $Revision: 1.36 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_ESTADO_H__BD1AC713_75BD_4AB0_981C_27067A96BA91__INCLUDED_)
#define AFX_ESTADO_H__BD1AC713_75BD_4AB0_981C_27067A96BA91__INCLUDED_

#include <string>
using namespace std;

#include <biblia/util/Lixeira.h>
using namespace biblia::util;

#include <biblia/tempo/Momento.h>
#include <biblia/tempo/UniversoDeTempo.h>
using namespace biblia::tempo;

#include <biblia/armazenamento/volatil/carcacas/Lista.h>
#include <biblia/armazenamento/volatil/carcacas/MapaHash.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include "biblia/dinamicas/sinfonia/Valor.h"
#include "biblia/dinamicas/sinfonia/Classe.h"
#include "biblia/dinamicas/sinfonia/Universo.h"
#include "biblia/dinamicas/sinfonia/Rotulado.h"
#include "biblia/dinamicas/sinfonia/Multifuncional.h"
#include "biblia/dinamicas/sinfonia/UniversoMultifuncional.h"
#include "biblia/dinamicas/sinfonia/SinfoniaExcecao.h"

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Exce��es relativas ao Estado.
	 */
	class EstadoExcecao: public SinfoniaExcecao {};

	/**
	 * � invocado quando algum Campo for requisitado
	 * mas n�o foi previamente definido.
	 */
	class CampoInexistenteExcecao: public EstadoExcecao {};

	/**
	 * � invocado quando se tentar mudar
	 * pela segunda vez o valor de um Estado constante.
	 */
	class EstadoConstanteExcecao: public EstadoExcecao {};

	/**
	 * Caracteriza o estado de um momento do software.
	 * <p>
	 * Um Estado possui um nome (deriva de Rotulado),
	 * um grupo, uma Classe (que por padr�o � a Multifuncional), um Valor
	 * e um Universo a que pertence (poss�veis valores).
	 * <p>
	 * Pode ser executado sobre esse Estado uma
	 * a��o qualquer (definida por uma Identificacao),
	 * que esteja dispon�vel na Classe a que
	 * este pertence, retornando um novo
	 * valor ou ele mesmo no caso da atribui��o.
	 * <p>
	 * Um Estado pode possuir mais de um campo caso sua
	 * estrutura interna necessite disso, mas o uso normal
	 * sup�e que ele possui apenas o campo principal
	 * definido por CAMPO_PRINCIPAL.
	 * <p>
	 * A c�pia n�o � poss�vel porque pode ser demorada
	 * demais. Use ponteiros e refer�ncias.
	 *
	 * @see Evento
	 * @see MediadorDeEstados
	 * @see #CAMPO_PRINCIPAL
	 * @see EstadoAlvo
	 *
	 * @version $Revision: 1.36 $, $Date: 2005/03/07 21:31:45 $ (GMT-3)
	 * @author <a href="mailto:micaroni@gmail.com?subject=$RCSfile: Estado.h,v $">Felipe Micaroni Lalli</a>
	 * @author modificado por $Author: felipelalli $
	 */
	class Estado: public Rotulado {
		private:
			const Classe* pClasse;
			bool pExterno;
			bool pConstante;
			Lista<Identificacao> pQuaisCampos;
			MapaHash<Valor*> pCampos;
			Valor pGrupo;
			Momento* pUltimaMudanca;
			mutable Lixeira pLixo;
			mutable MapaHash<UniversoMultifuncional*> pUniversos;
			mutable Valor pNomeCompleto; // buffer

		protected:
			/**
			 * A c�pia n�o � poss�vel porque pode ser demorada
			 * demais. Use ponteiros e refer�ncias.
			 */
			Estado(const Estado&):Rotulado("_"), pGrupo("_"),
								  pNomeCompleto("_"), pClasse(NULL) {}

		public:
			/**
			 * Usado para definir a classe padr�o
			 * de todo {@link Estado}.
			 */
			static Multifuncional MULTIFUNCIONAL;

			/**
			 * Nome do Estado que � constante. Todo
			 * estado constante possui o mesmo nome.
			 */
			static Valor CONSTANTE;

			/**
			 * Um valor definido por <b>meta nome</b>
			 * que representa um campo especial de
			 * todo Estado que retorna o seu pr�prio
			 * nome completo.
			 */
			static Valor META_NOME;

			/**
			 * Por padr�o, � da classe Multifuncional, que aceita
			 * os tipos primitivos: boolean, int, double e string.
			 * Define o Universo {@link UniversoMultifuncional} como padr�o que pode
			 * ser modificado externamente atrav�s da fun��o
			 * {@link #universo()}. A princ�pio est� definido como
			 * se n�o fosse modificado externamente, mas isso pode ser
			 * redefinido pela fun��o {@link #externo}.
			 * Tamb�m por padr�o come�a sem nenhum grupo, mas isso deve
			 * ser definido ap�s sua cria��o pela fun��o {@link #grupo}.
			 * <p>
			 * <i>Obs.: n�o pega para si a responsabilidade de deletar a Classe passada.</i>
			 * <br><i>Obs.2: por enquanto s� suporta {@link UniversoMultifuncional}.
			 */
			Estado(const Valor& nome,
				   const Classe* = (const Classe*) &Estado::MULTIFUNCIONAL);

			virtual ~Estado();

			/**
			 * Se � modificado externamente.
			 */
			virtual const bool& externo() const;

			/**
			 * Define se � modificado externamente. <i>Cuidado
			 * com Estados que s�o modificados externamente sem
			 * Eventos! N�o saber exatamente seu comportamento pode ocasionar
			 * erros inesperados.</i>
			 */
			virtual Estado& externo(const bool&);

			/**
			 * Indica se esse estado � constante. Se for, s�
			 * ser� poss�vel atribuir um valor numa primeira vez.
			 */
			virtual const bool& constante() const;

			/**
			 * Define este Estado como constante. � imposs�vel
			 * desfazer essa a��o.
			 */
			virtual Estado& defineComoConstante();

			/**
			 * O grupo a que este Estado pertence.
			 * Est� na forma de e. g.: "GrupoA.SubgrupoB"
			 *
			 * @see #nome()
			 * @see #nomeCompleto()
			 */
			virtual const Valor& grupo() const;

			/**
			 * Define o grupo a que este Estado pertence. Deve
			 * estar na forma de e. g.: "GrupoA.SubgrupoB"
			 */
			virtual Estado& grupo(const Valor&);

			/**
			 * � o nome completo deste Estado que o identifica
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
			 * A que Classe pertence esse Estado.
			 * Uma Classe agrupa um conjunto de funcionalidades
			 * que s�o poss�veis aplicar sobre qualquer valor.
			 */
			virtual const Classe& classe() const;

			/**
			 * Retorna o momento em que esse Estado foi modificado.
			 */
			virtual const Momento& ultimaModificacao() const;

			/**
			 * Retorna um valor desse Estado. Se o "campo" n�o
			 * for especificado, retorna o principal por padr�o.
			 *
			 * @throws CampoInexistenteExcecao
			 *
			 * @see #atribui
			 * @see #campos()
			 */
			virtual const Valor& valor(const Valor& campo
					= Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Retorna os poss�veis campos deste Estado, inclusive
			 * o principal (se existir) definido
			 * pela constante {@link Estado#CAMPO_PRINCIPAL}.
			 * <p>
			 * Um Estado simples pode possuir apenas o campo principal,
			 * definido por {@link Estado#CAMPO_PRINCIPAL}. Se sua estrutura
			 * for complexa (composta) ele pode possuir mais de
			 * um campo. Por exemplo: se este Estado representasse
			 * uma lista, cada campo seria o �ndice da lista
			 * e inclusive (nesse caso espec�fico) essa fun��o n�o seria
			 * recomendada pois poderia retornar muitos valores
			 * (todos os �ndices).
			 */
			virtual const Lista<Identificacao>& campos() const;

			/**
			 * Executa uma a��o sobre esse Estado usando o valor em quest�o
			 * como par�metro �nico ou sem nenhum par�metro. <b>ATEN��O:
			 * esta fun��o n�o atribui automaticamente o resultado. Para tal,
			 * utilize a fun��o {@link #atribui} passando o retorno desta.</b>
			 * <p>
			 * Equivale a <code>this->classe().aplica(this->valor(qualCampo), acao, valores);</code>.
			 *
			 * @throws AcaoIndisponivelExcecao A compatibilidade da a��o depende das a��es
			 *		   dispon�veis na Classe a que esse Estado pertence. 
			 *
			 * @throws ValorForaDeIntervalo Veja o Universo que esse Estado pertence.
			 * @return Depende da a��o executada.
			 */
			virtual const Valor executa(const Identificacao& acao,
					const Valor& valor = Irrelevante(),
					const Valor& qualCampo = Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Executa uma a��o sobre esse Estado usando os valores em quest�o
			 * como par�metros. <b>ATEN��O:
			 * esta fun��o n�o atribui automaticamente o resultado. Para tal,
			 * utilize a fun��o {@link #atribui} passando o retorno desta.</b>
			 *
			 * @throws AcaoIndisponivelExcecao A compatibilidade da a��o depende das a��es
			 *		   dispon�veis na Classe a que esse Estado pertence.
			 *
			 * @throws ValorForaDeIntervaloExcecao Veja o Universo a que esse Estado pertence.
			 * @return Depende da a��o executada.
			 */
			virtual const Valor executa(const Identificacao& acao,
									const Lista<const Valor*>& valores,
									const Valor& qualCampo
										= Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Atribui um valor a este Estado no campo principal
			 * por padr�o ou no campo especificado.
			 *
			 * @throws ForaDeIntervaloExcecao Veja o Universo que esse Estado pertence.
			 */
			virtual Estado& atribui(const Valor& valor, const UniversoDeTempo&,
					const Valor& campo = Multifuncional::CAMPO_PRINCIPAL);

			/**
			 * Prefira utilizar a fun��o {@link #atribui} passando
			 * um {@link UniversoDeTempo} como par�metro ao inv�s desta.
			 */
			virtual Estado& atribui(const Valor& valor,
					const Valor& campo = Multifuncional::CAMPO_PRINCIPAL);

			/**
			 * Retorna o UniversoMultifuncional (somente-leitura)
			 * a que esse Estado pertence para consulta
			 * externa.
			 */
			virtual const UniversoMultifuncional& universo(
					const Valor& campo = Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Retorna o UniversoMultifuncional a que esse Estado pertence
			 * para ser modificado externamente. Use esta fun��o
			 * quando voc� quiser restringir ou abranger o universo.
			 *
			 * @see #valoresPossiveis()
			 */
			virtual UniversoMultifuncional& universoParaModificar(
					const Valor& campo = Multifuncional::CAMPO_PRINCIPAL);

			// Objeto:

			/**
			 * Veja {@link #emString} com par�metro.
			 */
			virtual string emString() const {
				return this->emString(Multifuncional
					::CAMPO_PRINCIPAL);
			}

			/**
			 * Se o valor principal for boleano e sua
			 * correspond�ncia no "Universo"
			 * possuir pelo menos um apelido, usa o primeiro apelido
			 * seguido do nome do Estado, e. g.: se o Estado se chama
			 * "esperando" e o primeiro apelido � "est�", esta fun��o
			 * retorna "est� [esperando]". Se n�o for boleano, usa o
			 * pr�prio nome original do valor principal, sempre entre
			 * colchetes, seguido do valor (campo principal)
			 * entre par�nteses, assim: "[estado](valor)". Coloca um
			 * asterisco (&#42) na frente caso seja externo, como por exemplo:
			 * "* [estado](valor)". Se estiver especificado um
			 * campo diferente de {@link Multifuncional#CAMPO_PRINCIPAL}
			 * no par�metro �nico a string passa a ser
			 * "[estado].nomeDoCampo(valor)".
			 */
			virtual string emString(const Valor& campo) const;
	};
  }
 }
}

#endif // !defined(AFX_ESTADO_H__BD1AC713_75BD_4AB0_981C_27067A96BA91__INCLUDED_)

/*
                        .   .  .        ,...:;,             .                   
                .              ,VW###############Rt:.   ,     .                 
                     .. .  .tM##R+. .     .    .=IB###MRi:.                     
                  .   . +R##Bt,                  ..  .+YB#R  . .                
                    .I###Y:                               X#B                   
                 .  X#R.                              .     Y#V=                
            ..     ##+                  .        .  .     . ,M##X .             
               ..+##                                .    .IW######=  . .        
           . .. R#I .                            .    , t##########+ .          
        . .    ##,.                                  ,X#############Y           
            . R#=                            .     +#################i .        
             =#B..                             . X####################          
            .##   .                        .  ;Y######################R.        
            ##=                             :B#########################         
           R#X          .                 t###########################M.        
           ##=            .            .M##############################V        
          .=#B.                  .  .=X################################t        
          . ##:.                   t###################################         
         . .t#X          .       V#####################################         
             ##            .  ;B######################################I         
             ,##.           tM########################################          
              ;##.       .I##########################################+          
            .  ;##..   :RW##########################################;           
             .  .##. +#############################################,.           
               . ,###############################################R,. .          
                   i############################################t               
                .   .+#######################################Wt  .              
               .     ..+R##################################Bi.  .    .          
            .            ,iR############################Bt,                     
                            .=YB####################MY;.                        
                          ..     .,=IYYIBMBRVYII;:.                             
                                     .          .                   
*/
