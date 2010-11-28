/**
 * $RCSfile: Valor.h,v $
 * $Date: 2005/02/23 22:32:51 $
 * $Revision: 1.15 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * M�dulo: biblia.dinamicas.sinfonia-dev
 * M�dulo Central: ages
 *
 * Sinfonia
 * Ages Software Technology, outubro de 2004.
 */

#if !defined(AFX_VALOR_H__430C22FA_D9A5_41A6_85B8_4A695C918A69__INCLUDED_)
#define AFX_VALOR_H__430C22FA_D9A5_41A6_85B8_4A695C918A69__INCLUDED_

#include <string>
#include <ctype.h>
using namespace std;

#include <biblia/basico/Objeto.h>
#include <biblia/basico/Identificacao.h>
using namespace biblia::basico;

#include <biblia/armazenamento/volatil/carcacas/Lista.h>
#include <biblia/armazenamento/volatil/carcacas/MapaHash.h>
using namespace biblia::armazenamento::volatil::carcacas;

#include <biblia/armazenamento/volatil/primitivos/Inteiro.h>
#include <biblia/armazenamento/volatil/primitivos/Flutuante.h>
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
 namespace dinamicas {
  namespace sinfonia {
	/**
	 * Representa um valor primitivo qualquer "sem tipo"
	 * que pode possuir v�rios apelidos. O valor ser�
	 * armazenado a princ�pio em string mas
	 * pode ser interpretado como um int, double, bool etc.
	 * <P>
	 * <i>Obs.: Para os boleanos, o que vale � V (mai�sculo)
	 * para verdadeiro e F (mai�sculo) para falso. No caso
	 * de strings, n�o ser�o relevantes acentos, caixa alta/baixa.
	 * Underlines (_) ser�o considerados espa�os em branco e
	 * v�rgulas ser�o trocadas por pontos.
	 * <p>
	 * Se quiser usar como string, n�o use somente n�meros (e.g. 56) nem use
	 * somente a letra "V" e "F" (mai�sculas) porque a compara��o
	 * pode ficar comprometida. Para usar uma string literal, i. e.,
	 * considerando a acentua��o e caixa alta/baixa, especifique no
	 * construtor.</i>
	 *
	 * @see Irrelevante
	 */
	class Valor: public Informacao, public Comparavel, public Copiavel {
		private:
			string pOriginal;
			string pModificado;

			/**
			 * Para acesso r�pido da exist�ncia de um apelido.
			 */
			MapaHash<bool> pApelidos;

			/**
			 * Para retorno r�pido da lista completa.
			 */
			Lista<string> pListaDeApelidos;
			int pTipoParaComparacao;

			static int IRRELEVANTE;
			static int DESCONHECIDO;
			static int BOOL;
			static int DOUBLE;
			static int STRING;

		protected:
			/**
			 * Transforma em min�scula e retira
			 * a acentua��o. Troca os underline (_) e TABS por espa�os
			 * em branco e troca as v�rgulas por pontos.
			 */
			inline virtual const string modifica(const string&) const;

			/**
			 * Determina o tipo deste Valor apenas para efeito
			 * de compara��o.
			 */
			virtual const int determinaTipo();

		protected:
			/**
			 * Cria um Valor que � "irrelevante", i. e.,
			 * n�o dever� ser levado em conta por ser indefinido
			 * ou por n�o ser usado na a��o em quest�o.
			 *
			 * @see Irrelevante
			 */
			Valor();

		public:
			static string VERDADEIRO;
			static string FALSO;

			/**
			 * Construtor de c�pia.
			 */
			Valor(const Valor&);

			/**
			 * Cria um Valor a partir de uma string.
			 * @param literal Indica que o valor deve ser
			 *				  id�ntico ao passado por par�metro e deve
			 *                ser levado em conta caixa alta/baixa,
			 *                acentua��o e espa�os.
			 */
			Valor(const string&, const bool& literal = false);

			/**
			 * @see #Valor(const string&, const bool& literal)
			 */
			Valor(const char*, const bool& literal = false);

			/**
			 * Cria um Valor a partir de um inteiro.
			 */
			Valor(const int&);

			/**
			 * Cria um Valor a partir de um flutuante.
			 */
			Valor(const double&);

			/**
			 * Cria um Valor a partir de um boleano.
			 */
			Valor(const bool&);
			virtual ~Valor();

			/**
			 * Adiciona um apelido a este valor. Os apelidos
			 * podem ser somente strings.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual Valor& adicionaApelido(const string&);

			/**
			 * Retorna todos os apelidos deste valor numa lista.
			 * Os valores est�o num buffer, i. e., n�o s�o recalculados
			 * a cada chamada, pode chamar tranquilo! ;)
			 */
			virtual const Lista<string>& apelidos() const;

			/**
			 * Retorna o valor sem acentos e todo em min�sculas.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const string& valor() const;

			/**
			 * Retorna a string original (passada no construtor).
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const string& original() const;

			/**
			 * Verifica se os originais s�o id�nticos.
			 * @see #igual(const Igualavel&)
			 */
			virtual const bool identico(const Valor& valor) const;

			/**
			 * � 0 se n�o puder ser convertido.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const int emInt() const;

			/**
			 * � 0.0 se n�o puder ser convertido.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const double emDouble() const;

			/**
			 * Retorna true para V (mai�sculo) e
			 * false para todos os outros casos.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const bool emBool() const;

			/**
			 * Quando � V ou F.
			 */
			virtual const bool pareceSerBoleano() const;

			/**
			 * Quando todos os caracteres s�o n�meros ou ponto (.).
			 */
			virtual const bool pareceSerNumero() const;

			/**
			 * Quando algum dos d�gitos n�o � n�mero ou ponto (.) nem
			 * a string toda � V ou F.
			 */
			virtual const bool pareceSerString() const;

			/**
			 * Indica se este valor � irrelevante. Se for,
			 * nenhuma opera��o exceto a compara��o (== ou !=)
			 * pode ser feita.
			 *
			 * @see Irrelevante
			 */
			virtual const bool indefinida() const {
				bool retorno = Informacao::indefinida();
				return retorno;
			}

			/**
			 * Gera uma string �nica e completa
			 * que identifica este Valor como sendo �nico
			 * pelo seu conte�do. Leva em conta nome original,
			 * modificado e todos os apelidos.
			 */
			virtual string geraStringUnicaECompleta() const;

			// Comparavel:
			/**
			 * Para efeito de compara��o, F � menor que V. Quando
			 * <b>ambos</b> puderem, eles ser�o convertidos para double ou bool antes
			 * de serem comparados. Caso contr�rio, utiliza a mesma regra de
			 * compara��o de string (string.compare()),
			 * mas com o {@link #valor()}.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const bool menorQue(const Comparavel& alheio) const;

			// Igualavel:
			/**
			 * Verifica se � igual ao {@link #valor()}
			 * ou se � igual a algum dos apelidos. Ou se ambos s�o
			 * irrelevantes.
			 *
			 * @see #identico(const Valor&)
			 */
			virtual const bool igual(const Igualavel& alheio) const;

			// Objeto:
			/**
			 * Retorna {@link #valor}.
			 *
			 * @see #valor()
			 */
			virtual string emString() const;

			// Copiavel:
			virtual Objeto* geraCopia() const;
			virtual Copiavel& copiaEmSi(const Copiavel& alheio);
	};

	/**
	 * Representa um Valor irrelevante
	 * ou indefinido.
	 */
	class Irrelevante: public Valor {
		public:
			Irrelevante():Valor() {}

			virtual ~Irrelevante() {}

			/**
			 * Retorna "-???-".
			 */
			virtual string emString() const {
				return "-???-";
			}
	};
  }
 }
}

#endif // !defined(AFX_VALOR_H__430C22FA_D9A5_41A6_85B8_4A695C918A69__INCLUDED_)
