/**
 * $RCSfile: Estado.h,v $
 * $Date: 2005/03/07 21:31:45 $
 * $Revision: 1.36 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
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
	 * Exceções relativas ao Estado.
	 */
	class EstadoExcecao: public SinfoniaExcecao {};

	/**
	 * É invocado quando algum Campo for requisitado
	 * mas não foi previamente definido.
	 */
	class CampoInexistenteExcecao: public EstadoExcecao {};

	/**
	 * É invocado quando se tentar mudar
	 * pela segunda vez o valor de um Estado constante.
	 */
	class EstadoConstanteExcecao: public EstadoExcecao {};

	/**
	 * Caracteriza o estado de um momento do software.
	 * <p>
	 * Um Estado possui um nome (deriva de Rotulado),
	 * um grupo, uma Classe (que por padrão é a Multifuncional), um Valor
	 * e um Universo a que pertence (possíveis valores).
	 * <p>
	 * Pode ser executado sobre esse Estado uma
	 * ação qualquer (definida por uma Identificacao),
	 * que esteja disponível na Classe a que
	 * este pertence, retornando um novo
	 * valor ou ele mesmo no caso da atribuição.
	 * <p>
	 * Um Estado pode possuir mais de um campo caso sua
	 * estrutura interna necessite disso, mas o uso normal
	 * supõe que ele possui apenas o campo principal
	 * definido por CAMPO_PRINCIPAL.
	 * <p>
	 * A cópia não é possível porque pode ser demorada
	 * demais. Use ponteiros e referências.
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
			 * A cópia não é possível porque pode ser demorada
			 * demais. Use ponteiros e referências.
			 */
			Estado(const Estado&):Rotulado("_"), pGrupo("_"),
								  pNomeCompleto("_"), pClasse(NULL) {}

		public:
			/**
			 * Usado para definir a classe padrão
			 * de todo {@link Estado}.
			 */
			static Multifuncional MULTIFUNCIONAL;

			/**
			 * Nome do Estado que é constante. Todo
			 * estado constante possui o mesmo nome.
			 */
			static Valor CONSTANTE;

			/**
			 * Um valor definido por <b>meta nome</b>
			 * que representa um campo especial de
			 * todo Estado que retorna o seu próprio
			 * nome completo.
			 */
			static Valor META_NOME;

			/**
			 * Por padrão, é da classe Multifuncional, que aceita
			 * os tipos primitivos: boolean, int, double e string.
			 * Define o Universo {@link UniversoMultifuncional} como padrão que pode
			 * ser modificado externamente através da função
			 * {@link #universo()}. A princípio está definido como
			 * se não fosse modificado externamente, mas isso pode ser
			 * redefinido pela função {@link #externo}.
			 * Também por padrão começa sem nenhum grupo, mas isso deve
			 * ser definido após sua criação pela função {@link #grupo}.
			 * <p>
			 * <i>Obs.: não pega para si a responsabilidade de deletar a Classe passada.</i>
			 * <br><i>Obs.2: por enquanto só suporta {@link UniversoMultifuncional}.
			 */
			Estado(const Valor& nome,
				   const Classe* = (const Classe*) &Estado::MULTIFUNCIONAL);

			virtual ~Estado();

			/**
			 * Se é modificado externamente.
			 */
			virtual const bool& externo() const;

			/**
			 * Define se é modificado externamente. <i>Cuidado
			 * com Estados que são modificados externamente sem
			 * Eventos! Não saber exatamente seu comportamento pode ocasionar
			 * erros inesperados.</i>
			 */
			virtual Estado& externo(const bool&);

			/**
			 * Indica se esse estado é constante. Se for, só
			 * será possível atribuir um valor numa primeira vez.
			 */
			virtual const bool& constante() const;

			/**
			 * Define este Estado como constante. É impossível
			 * desfazer essa ação.
			 */
			virtual Estado& defineComoConstante();

			/**
			 * O grupo a que este Estado pertence.
			 * Está na forma de e. g.: "GrupoA.SubgrupoB"
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
			 * É o nome completo deste Estado que o identifica
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
			 * A que Classe pertence esse Estado.
			 * Uma Classe agrupa um conjunto de funcionalidades
			 * que são possíveis aplicar sobre qualquer valor.
			 */
			virtual const Classe& classe() const;

			/**
			 * Retorna o momento em que esse Estado foi modificado.
			 */
			virtual const Momento& ultimaModificacao() const;

			/**
			 * Retorna um valor desse Estado. Se o "campo" não
			 * for especificado, retorna o principal por padrão.
			 *
			 * @throws CampoInexistenteExcecao
			 *
			 * @see #atribui
			 * @see #campos()
			 */
			virtual const Valor& valor(const Valor& campo
					= Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Retorna os possíveis campos deste Estado, inclusive
			 * o principal (se existir) definido
			 * pela constante {@link Estado#CAMPO_PRINCIPAL}.
			 * <p>
			 * Um Estado simples pode possuir apenas o campo principal,
			 * definido por {@link Estado#CAMPO_PRINCIPAL}. Se sua estrutura
			 * for complexa (composta) ele pode possuir mais de
			 * um campo. Por exemplo: se este Estado representasse
			 * uma lista, cada campo seria o índice da lista
			 * e inclusive (nesse caso específico) essa função não seria
			 * recomendada pois poderia retornar muitos valores
			 * (todos os índices).
			 */
			virtual const Lista<Identificacao>& campos() const;

			/**
			 * Executa uma ação sobre esse Estado usando o valor em questão
			 * como parâmetro único ou sem nenhum parâmetro. <b>ATENÇÃO:
			 * esta função não atribui automaticamente o resultado. Para tal,
			 * utilize a função {@link #atribui} passando o retorno desta.</b>
			 * <p>
			 * Equivale a <code>this->classe().aplica(this->valor(qualCampo), acao, valores);</code>.
			 *
			 * @throws AcaoIndisponivelExcecao A compatibilidade da ação depende das ações
			 *		   disponíveis na Classe a que esse Estado pertence. 
			 *
			 * @throws ValorForaDeIntervalo Veja o Universo que esse Estado pertence.
			 * @return Depende da ação executada.
			 */
			virtual const Valor executa(const Identificacao& acao,
					const Valor& valor = Irrelevante(),
					const Valor& qualCampo = Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Executa uma ação sobre esse Estado usando os valores em questão
			 * como parâmetros. <b>ATENÇÃO:
			 * esta função não atribui automaticamente o resultado. Para tal,
			 * utilize a função {@link #atribui} passando o retorno desta.</b>
			 *
			 * @throws AcaoIndisponivelExcecao A compatibilidade da ação depende das ações
			 *		   disponíveis na Classe a que esse Estado pertence.
			 *
			 * @throws ValorForaDeIntervaloExcecao Veja o Universo a que esse Estado pertence.
			 * @return Depende da ação executada.
			 */
			virtual const Valor executa(const Identificacao& acao,
									const Lista<const Valor*>& valores,
									const Valor& qualCampo
										= Multifuncional::CAMPO_PRINCIPAL) const;

			/**
			 * Atribui um valor a este Estado no campo principal
			 * por padrão ou no campo especificado.
			 *
			 * @throws ForaDeIntervaloExcecao Veja o Universo que esse Estado pertence.
			 */
			virtual Estado& atribui(const Valor& valor, const UniversoDeTempo&,
					const Valor& campo = Multifuncional::CAMPO_PRINCIPAL);

			/**
			 * Prefira utilizar a função {@link #atribui} passando
			 * um {@link UniversoDeTempo} como parâmetro ao invés desta.
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
			 * para ser modificado externamente. Use esta função
			 * quando você quiser restringir ou abranger o universo.
			 *
			 * @see #valoresPossiveis()
			 */
			virtual UniversoMultifuncional& universoParaModificar(
					const Valor& campo = Multifuncional::CAMPO_PRINCIPAL);

			// Objeto:

			/**
			 * Veja {@link #emString} com parâmetro.
			 */
			virtual string emString() const {
				return this->emString(Multifuncional
					::CAMPO_PRINCIPAL);
			}

			/**
			 * Se o valor principal for boleano e sua
			 * correspondência no "Universo"
			 * possuir pelo menos um apelido, usa o primeiro apelido
			 * seguido do nome do Estado, e. g.: se o Estado se chama
			 * "esperando" e o primeiro apelido é "está", esta função
			 * retorna "está [esperando]". Se não for boleano, usa o
			 * próprio nome original do valor principal, sempre entre
			 * colchetes, seguido do valor (campo principal)
			 * entre parênteses, assim: "[estado](valor)". Coloca um
			 * asterisco (&#42) na frente caso seja externo, como por exemplo:
			 * "* [estado](valor)". Se estiver especificado um
			 * campo diferente de {@link Multifuncional#CAMPO_PRINCIPAL}
			 * no parâmetro único a string passa a ser
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
