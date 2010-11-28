/*
 * $RCSfile: EternizadorDePacotes.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(EternizadorDePacotes_h)
#define EternizadorDePacotes_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/armazenamento/eterno/EternoExcecao.h"
#include "biblia/armazenamento/eterno/empacotamento/Caixa.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::eterno;
using namespace biblia::armazenamento::eterno::empacotamento;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace eternizacao {

		/**
		 * Eterniza uma Caixa que é um conjunto de
		 * pacotes selados. É um eternizador 'de pacotes'
		 * e não 'de caixa' porque os pacotes podem
		 * ser eternizados e resgatados separadamente.
		 * <p>
		 * O conceito de 'forma eterna' e 'forma volátil'
		 * apresentado aqui nesta classe não representa
		 * o significado literal das palavras eterna e volátil.
		 * Dependendo da implementação, pode ser que a
		 * 'forma eterna' não seja 'eterna' de fato.
		 * <p>
		 * Significado literal (retirado de
		 * http://www.priberam.pt/dlpo/ em 2/2/4):
		 * <p>
		 * <b>eterno</b> - do Lat. <i>aeternu</i>
		 * <br>adj., 
		 * <br>	   que não tem princípio nem fim;
		 * <br>    que não tem fim;
		 * <br>    inalterável;
		 * <br>    imortalizado, célebre;
		 * <p>
		 * <b>volátil</b> - do Lat. <i>volatile</i>
		 * <br>fig.,
		 * <br>	   volúvel;
		 * <br>    que se pode reduzir a gás ou a vapor;
		 * <p>
		 * Um Pacote 'eternizado' significa, no contexto
		 * desta classe, que o pacote foi 'congelado',
		 * 'estatizado', 'paralizado' em algum lugar/dispositivo
		 * (este definido por alguma classe que implementa
		 * esta interface). Um Pacote em sua forma 'volátil'
		 * significa que este está na memória, armazenado
		 * dentro de um PacoteSelado que pode ficar dentro
		 * de uma Caixa. --- Quando um Pacote está em sua forma
		 * volátil ele pode ser modificado através de uma Caixa.
		 * Quem tem acesso à instância do pacote, pode mudá-lo.
		 * Porém, quem pode mudar o Pacote quando está em sua forma
		 * eterna é só o dispostivo que o armazena; esse dispositivo
		 * pode ser o disco, outro software, a rede, a memória etc.
		 * <p>
		 * Contém um controle interno para
		 * verificar qual pacote foi
		 * modificado e apenas gravar
		 * os pacotes modificados quando
		 * executado.
		 * <p>
		 * <b>Beba com moderação:</b>
		 * Um processo de 'eternização' ou 'deseternização'
		 * pode ser um processo muito lento dependendo
		 * do I/O em questão; é importante utilizar
		 * as instâncias desta classe o menor
		 * número de vezes possível.
		 */
		class EternizadorDePacotes: public Objeto {
			private:
				Caixa EternizadorDePacotes::pCaixa;

			protected:
				EternizadorDePacotes::EternizadorDePacotes();
				virtual Caixa& EternizadorDePacotes::ultimaCaixa();

			public:
				virtual EternizadorDePacotes::~EternizadorDePacotes();

				/**
				 * Última caixa que foi sincronizada para
				 * consulta. Esta caixa é acumulativa, i. e.,
				 * toda vez que algum pacote é sincronizado
				 * esta caixa <b>não</b> é apagada.
				 * <p>
				 * <b>Cuidado:</b>
				 * Se quiser garantir que esta caixa esteja
				 * sincronizada utilize a função
				 * {@link #estaDessincronizado()} ou (preferencialmente)
				 * sincronize este eternizador antes de chamar esta função.
				 * Esta função não faz essa verificação automática
				 * porque provavelmente o tempo de verificação
				 * (de se está sincronizada) é
				 * o mesmo que o tempo de sincronização:
				 * a informação teria que ser lida em sua
				 * 'forma eterna' e esta caixa perderia
				 * a função/o conceito de "buffer",
				 * de "última caixa que foi sincronizada", como
				 * foi definida.
				 */
				virtual const Caixa& EternizadorDePacotes::caixa() const;

				/**
				 * Os pacotes selados passados como parâmetro
				 * dentro da Caixa serão eternizados caso
				 * toda a {@link última caixa sincronizada caixa()}
				 * esteja sincronizada.
				 * <p>
				 * A princípio esta função
				 * é acumulativa, i. e., acrescenta/substitui
				 * pacotes e não apaga os que não existirem
				 * na caixa passada como parâmetro. Porém essa
				 * garantia depende da implementação específica.
				 * Veja a função {@link apagaDiferenca(const Caixa&)}
				 * caso queira apagar pacotes que estão eternizados.
				 * <p>
				 * Antes de começar a 'eternizar', verifica
				 * se não há nenhum pacote 'dessincronizado' e
				 * 'marca' os pacotes que deverão ser gravados
				 * comparando-os com a {@link última
				 * caixa sincronizada caixa()}.
				 * <p>
				 * Para otimização da velocidade de
				 * execução desta função verifique
				 * o significado dos parâmetros
				 * opcionais. --- Esses
				 * parâmetros estão definidos por
				 * padrão com a configuração julgada
				 * a mais <b>segura</b> e não necessariamente
				 * a mais <b>rápida</b>. Essas definições
				 * 'padrões' podem ser mudadas na interface
				 * da classe filha.
				 * <p>
				 * <i>Nota para quem usa:
				 * O processo de eternizar pode
				 * ser lento demais, portanto chame
				 * essa função somente quando for
				 * indispensável, ou a utilize em
				 * processos paralelos.
				 * </i>
				 *
				 * @param forcar
				 *		  Força a eternização
				 *        dos pacotes selados sem
				 *        a verificação se estão
				 *        dessincronizados ou não.
				 *        Definir este parâmetro
				 *        como verdadeiro pode
				 *        diminuir significativamente
				 *		  a velocidade desta função.
				 *        --- Pode ser útil quando a forma
				 *        eterna é mudada a todo instante
		         *        impossibilitando a atualização
				 *        das informações, caso essas
				 *        não necessitam de garantia
				 *        de integridade e sincronização
				 *        das informações. --- Pode ser
				 *        útil também quando se tem uma
				 *        certeza prévia que os pacotes
				 *        estão devidamente sincronizados.
				 *
				 * @param verificaSeMudou
				 *		  Se definida com o valor
				 *        'falso' evita a verificação
				 *        prévia de modificação do pacote
				 *        antes de eternizar, eternizando
				 *        todos os pacotes passados. Pode
				 *        diminuir ou aumentar
				 *        significativamente a velocidade
				 *        desta função. --- Pode ser útil
				 *        quando já se sabe externamente
				 *        que os pacotes passados são
				 *        apenas os que mudaram ou quando
				 *        se julga que a 'eternização'
				 *        direta compensa o custo de verificar.
				 *
				 * @throws FormaEternaModificadaExcecao
				 *         É invocado somente se o parametro
				 *         'forcar' for falso. É lançado
				 *         caso os pacotes
				 *         desta caixa não estejam
				 *         sincronizados com sua forma
				 *         eterna. Essa função não chama
				 *         automaticamente a função
				 *         sincroniza(), que nesse caso
				 *         deve ser chamada antes desta
				 *         ser chamada. Essa exceção carrega
				 *         uma lista de todos os pacotes
				 *         que estão dessincronizados.
				 */
				virtual EternizadorDePacotes&
						EternizadorDePacotes
							::eterniza(const Caixa&,
								       const bool& forcar = false,
									   const bool& verificaSeMudou
											= true) = 0;

				/**
				 * Apaga os elementos em sua forma
				 * eterna que não estão nesta caixa.
				 * Lembre-se de passar <b>todos</b>
				 * os pacotes que você quer <b>manter</b>
				 * em sua forma eterna. Os que não
				 * estiverem na caixa passada serão
				 * apagados em sua forma eterna e
				 * <b>deixarão de existir 'pra sempre'</b>.
				 * <p>
				 * Se não for custoso
				 * demais armazenar um pacote, deixe
				 * para chamar esta função apenas no
				 * encerramento da aplicação ou de tempos
				 * em tempos (caso a aplicação não termine
				 * nunca); isso porque apagar pacotes pode ser
				 * lento demais e serve apenas para economizar
				 * espaço no dispositivo em questão.
				 */
				virtual EternizadorDePacotes&
						EternizadorDePacotes
							::apagaDiferenca(
								const Caixa& todaACaixa) = 0;

				/**
				 * Responde se o PacoteSelado em questão
				 * está diferente do PacoteSelado
				 * que está em sua 'forma eterna'.
				 * <p>
				 * Não é necessário chamar esta função
				 * antes de mandar sincronizar o pacote
				 * em questão. A função que sincroniza
				 * o pacote já deve saber fazer isso
				 * antes de 'puxar' o novo valor de fato.
				 *
				 * @throws PacoteNaoEncontradoExcecao
				 */
				virtual const bool EternizadorDePacotes
						::estaDessincronizado(
							const Identificacao&
							qualPacote) const = 0;

				/**
				 * Responde se há pelo menos
				 * um pacote dessincronizado com a versão
				 * eternizada.
				 * <p>
				 * Não é necessário chamar esta função
				 * antes de sincronizar este eternizador.
				 * Isso pode causar lentidão desnecessária.
				 * A função que sincroniza já deve saber
				 * sincronizar apenas os pacotes que foram
				 * modificados em sua forma eterna.
				 * <p>
				 * <i>Esta função pára de processar no primeiro
				 * pacote que estiver dessincronizado.</i>
				 */
				virtual const bool EternizadorDePacotes
						::estaDessincronizado() const = 0;

				/**
				 * Sincroniza o pacotes selado
				 * com a sua 'forma eterna'.
				 * <p>
				 * Traz do 'eterno' se o PacoteSelado
				 * foi modificado em sua 'forma eterna'
				 * e o coloca dentro da
				 * {@link última caixa sincronizada
				 * caixa()}.
				 * <p>
				 * <i>Nota a quem implementa:
				 * É importante que esta função seja
				 * o mais otimizada possível porque
				 * todas as informações da caixa serão
				 * percorridas e verificadas.
				 *
				 * @throws PacoteNaoEncontradoExcecao
				 */
				virtual EternizadorDePacotes& EternizadorDePacotes
						::sincroniza(const Identificacao&
									 qualPacote) = 0;

				/**
				 * Sincroniza todos os pacotes que
				 * estão na forma eterna trazendo-os
				 * para a forma volátil.
				 *
				 * @see #sincroniza(const Identificacao&
				 *					 qualPacote)
				 */
				virtual EternizadorDePacotes& EternizadorDePacotes
						::sincronizaTudo() = 0;
		};
	  }
	}
  }
}

#endif /* EternizadorDePacotes_h */
