/*
 * $RCSfile: EternizadorDePacotes.h,v $
 * $Date: 2004/02/16 23:29:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
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
		 * Eterniza uma Caixa que � um conjunto de
		 * pacotes selados. � um eternizador 'de pacotes'
		 * e n�o 'de caixa' porque os pacotes podem
		 * ser eternizados e resgatados separadamente.
		 * <p>
		 * O conceito de 'forma eterna' e 'forma vol�til'
		 * apresentado aqui nesta classe n�o representa
		 * o significado literal das palavras eterna e vol�til.
		 * Dependendo da implementa��o, pode ser que a
		 * 'forma eterna' n�o seja 'eterna' de fato.
		 * <p>
		 * Significado literal (retirado de
		 * http://www.priberam.pt/dlpo/ em 2/2/4):
		 * <p>
		 * <b>eterno</b> - do Lat. <i>aeternu</i>
		 * <br>adj., 
		 * <br>	   que n�o tem princ�pio nem fim;
		 * <br>    que n�o tem fim;
		 * <br>    inalter�vel;
		 * <br>    imortalizado, c�lebre;
		 * <p>
		 * <b>vol�til</b> - do Lat. <i>volatile</i>
		 * <br>fig.,
		 * <br>	   vol�vel;
		 * <br>    que se pode reduzir a g�s ou a vapor;
		 * <p>
		 * Um Pacote 'eternizado' significa, no contexto
		 * desta classe, que o pacote foi 'congelado',
		 * 'estatizado', 'paralizado' em algum lugar/dispositivo
		 * (este definido por alguma classe que implementa
		 * esta interface). Um Pacote em sua forma 'vol�til'
		 * significa que este est� na mem�ria, armazenado
		 * dentro de um PacoteSelado que pode ficar dentro
		 * de uma Caixa. --- Quando um Pacote est� em sua forma
		 * vol�til ele pode ser modificado atrav�s de uma Caixa.
		 * Quem tem acesso � inst�ncia do pacote, pode mud�-lo.
		 * Por�m, quem pode mudar o Pacote quando est� em sua forma
		 * eterna � s� o dispostivo que o armazena; esse dispositivo
		 * pode ser o disco, outro software, a rede, a mem�ria etc.
		 * <p>
		 * Cont�m um controle interno para
		 * verificar qual pacote foi
		 * modificado e apenas gravar
		 * os pacotes modificados quando
		 * executado.
		 * <p>
		 * <b>Beba com modera��o:</b>
		 * Um processo de 'eterniza��o' ou 'deseterniza��o'
		 * pode ser um processo muito lento dependendo
		 * do I/O em quest�o; � importante utilizar
		 * as inst�ncias desta classe o menor
		 * n�mero de vezes poss�vel.
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
				 * �ltima caixa que foi sincronizada para
				 * consulta. Esta caixa � acumulativa, i. e.,
				 * toda vez que algum pacote � sincronizado
				 * esta caixa <b>n�o</b> � apagada.
				 * <p>
				 * <b>Cuidado:</b>
				 * Se quiser garantir que esta caixa esteja
				 * sincronizada utilize a fun��o
				 * {@link #estaDessincronizado()} ou (preferencialmente)
				 * sincronize este eternizador antes de chamar esta fun��o.
				 * Esta fun��o n�o faz essa verifica��o autom�tica
				 * porque provavelmente o tempo de verifica��o
				 * (de se est� sincronizada) �
				 * o mesmo que o tempo de sincroniza��o:
				 * a informa��o teria que ser lida em sua
				 * 'forma eterna' e esta caixa perderia
				 * a fun��o/o conceito de "buffer",
				 * de "�ltima caixa que foi sincronizada", como
				 * foi definida.
				 */
				virtual const Caixa& EternizadorDePacotes::caixa() const;

				/**
				 * Os pacotes selados passados como par�metro
				 * dentro da Caixa ser�o eternizados caso
				 * toda a {@link �ltima caixa sincronizada caixa()}
				 * esteja sincronizada.
				 * <p>
				 * A princ�pio esta fun��o
				 * � acumulativa, i. e., acrescenta/substitui
				 * pacotes e n�o apaga os que n�o existirem
				 * na caixa passada como par�metro. Por�m essa
				 * garantia depende da implementa��o espec�fica.
				 * Veja a fun��o {@link apagaDiferenca(const Caixa&)}
				 * caso queira apagar pacotes que est�o eternizados.
				 * <p>
				 * Antes de come�ar a 'eternizar', verifica
				 * se n�o h� nenhum pacote 'dessincronizado' e
				 * 'marca' os pacotes que dever�o ser gravados
				 * comparando-os com a {@link �ltima
				 * caixa sincronizada caixa()}.
				 * <p>
				 * Para otimiza��o da velocidade de
				 * execu��o desta fun��o verifique
				 * o significado dos par�metros
				 * opcionais. --- Esses
				 * par�metros est�o definidos por
				 * padr�o com a configura��o julgada
				 * a mais <b>segura</b> e n�o necessariamente
				 * a mais <b>r�pida</b>. Essas defini��es
				 * 'padr�es' podem ser mudadas na interface
				 * da classe filha.
				 * <p>
				 * <i>Nota para quem usa:
				 * O processo de eternizar pode
				 * ser lento demais, portanto chame
				 * essa fun��o somente quando for
				 * indispens�vel, ou a utilize em
				 * processos paralelos.
				 * </i>
				 *
				 * @param forcar
				 *		  For�a a eterniza��o
				 *        dos pacotes selados sem
				 *        a verifica��o se est�o
				 *        dessincronizados ou n�o.
				 *        Definir este par�metro
				 *        como verdadeiro pode
				 *        diminuir significativamente
				 *		  a velocidade desta fun��o.
				 *        --- Pode ser �til quando a forma
				 *        eterna � mudada a todo instante
		         *        impossibilitando a atualiza��o
				 *        das informa��es, caso essas
				 *        n�o necessitam de garantia
				 *        de integridade e sincroniza��o
				 *        das informa��es. --- Pode ser
				 *        �til tamb�m quando se tem uma
				 *        certeza pr�via que os pacotes
				 *        est�o devidamente sincronizados.
				 *
				 * @param verificaSeMudou
				 *		  Se definida com o valor
				 *        'falso' evita a verifica��o
				 *        pr�via de modifica��o do pacote
				 *        antes de eternizar, eternizando
				 *        todos os pacotes passados. Pode
				 *        diminuir ou aumentar
				 *        significativamente a velocidade
				 *        desta fun��o. --- Pode ser �til
				 *        quando j� se sabe externamente
				 *        que os pacotes passados s�o
				 *        apenas os que mudaram ou quando
				 *        se julga que a 'eterniza��o'
				 *        direta compensa o custo de verificar.
				 *
				 * @throws FormaEternaModificadaExcecao
				 *         � invocado somente se o parametro
				 *         'forcar' for falso. � lan�ado
				 *         caso os pacotes
				 *         desta caixa n�o estejam
				 *         sincronizados com sua forma
				 *         eterna. Essa fun��o n�o chama
				 *         automaticamente a fun��o
				 *         sincroniza(), que nesse caso
				 *         deve ser chamada antes desta
				 *         ser chamada. Essa exce��o carrega
				 *         uma lista de todos os pacotes
				 *         que est�o dessincronizados.
				 */
				virtual EternizadorDePacotes&
						EternizadorDePacotes
							::eterniza(const Caixa&,
								       const bool& forcar = false,
									   const bool& verificaSeMudou
											= true) = 0;

				/**
				 * Apaga os elementos em sua forma
				 * eterna que n�o est�o nesta caixa.
				 * Lembre-se de passar <b>todos</b>
				 * os pacotes que voc� quer <b>manter</b>
				 * em sua forma eterna. Os que n�o
				 * estiverem na caixa passada ser�o
				 * apagados em sua forma eterna e
				 * <b>deixar�o de existir 'pra sempre'</b>.
				 * <p>
				 * Se n�o for custoso
				 * demais armazenar um pacote, deixe
				 * para chamar esta fun��o apenas no
				 * encerramento da aplica��o ou de tempos
				 * em tempos (caso a aplica��o n�o termine
				 * nunca); isso porque apagar pacotes pode ser
				 * lento demais e serve apenas para economizar
				 * espa�o no dispositivo em quest�o.
				 */
				virtual EternizadorDePacotes&
						EternizadorDePacotes
							::apagaDiferenca(
								const Caixa& todaACaixa) = 0;

				/**
				 * Responde se o PacoteSelado em quest�o
				 * est� diferente do PacoteSelado
				 * que est� em sua 'forma eterna'.
				 * <p>
				 * N�o � necess�rio chamar esta fun��o
				 * antes de mandar sincronizar o pacote
				 * em quest�o. A fun��o que sincroniza
				 * o pacote j� deve saber fazer isso
				 * antes de 'puxar' o novo valor de fato.
				 *
				 * @throws PacoteNaoEncontradoExcecao
				 */
				virtual const bool EternizadorDePacotes
						::estaDessincronizado(
							const Identificacao&
							qualPacote) const = 0;

				/**
				 * Responde se h� pelo menos
				 * um pacote dessincronizado com a vers�o
				 * eternizada.
				 * <p>
				 * N�o � necess�rio chamar esta fun��o
				 * antes de sincronizar este eternizador.
				 * Isso pode causar lentid�o desnecess�ria.
				 * A fun��o que sincroniza j� deve saber
				 * sincronizar apenas os pacotes que foram
				 * modificados em sua forma eterna.
				 * <p>
				 * <i>Esta fun��o p�ra de processar no primeiro
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
				 * {@link �ltima caixa sincronizada
				 * caixa()}.
				 * <p>
				 * <i>Nota a quem implementa:
				 * � importante que esta fun��o seja
				 * o mais otimizada poss�vel porque
				 * todas as informa��es da caixa ser�o
				 * percorridas e verificadas.
				 *
				 * @throws PacoteNaoEncontradoExcecao
				 */
				virtual EternizadorDePacotes& EternizadorDePacotes
						::sincroniza(const Identificacao&
									 qualPacote) = 0;

				/**
				 * Sincroniza todos os pacotes que
				 * est�o na forma eterna trazendo-os
				 * para a forma vol�til.
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
