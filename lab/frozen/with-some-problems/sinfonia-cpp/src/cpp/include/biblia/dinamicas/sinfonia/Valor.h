/**
 * $RCSfile: Valor.h,v $
 * $Date: 2005/02/23 22:32:51 $
 * $Revision: 1.15 $
 * $Author: felipelalli $
 * Tag: $Name:  $
 * Módulo: biblia.dinamicas.sinfonia-dev
 * Módulo Central: ages
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
	 * que pode possuir vários apelidos. O valor será
	 * armazenado a princípio em string mas
	 * pode ser interpretado como um int, double, bool etc.
	 * <P>
	 * <i>Obs.: Para os boleanos, o que vale é V (maiúsculo)
	 * para verdadeiro e F (maiúsculo) para falso. No caso
	 * de strings, não serão relevantes acentos, caixa alta/baixa.
	 * Underlines (_) serão considerados espaços em branco e
	 * vírgulas serão trocadas por pontos.
	 * <p>
	 * Se quiser usar como string, não use somente números (e.g. 56) nem use
	 * somente a letra "V" e "F" (maiúsculas) porque a comparação
	 * pode ficar comprometida. Para usar uma string literal, i. e.,
	 * considerando a acentuação e caixa alta/baixa, especifique no
	 * construtor.</i>
	 *
	 * @see Irrelevante
	 */
	class Valor: public Informacao, public Comparavel, public Copiavel {
		private:
			string pOriginal;
			string pModificado;

			/**
			 * Para acesso rápido da existência de um apelido.
			 */
			MapaHash<bool> pApelidos;

			/**
			 * Para retorno rápido da lista completa.
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
			 * Transforma em minúscula e retira
			 * a acentuação. Troca os underline (_) e TABS por espaços
			 * em branco e troca as vírgulas por pontos.
			 */
			inline virtual const string modifica(const string&) const;

			/**
			 * Determina o tipo deste Valor apenas para efeito
			 * de comparação.
			 */
			virtual const int determinaTipo();

		protected:
			/**
			 * Cria um Valor que é "irrelevante", i. e.,
			 * não deverá ser levado em conta por ser indefinido
			 * ou por não ser usado na ação em questão.
			 *
			 * @see Irrelevante
			 */
			Valor();

		public:
			static string VERDADEIRO;
			static string FALSO;

			/**
			 * Construtor de cópia.
			 */
			Valor(const Valor&);

			/**
			 * Cria um Valor a partir de uma string.
			 * @param literal Indica que o valor deve ser
			 *				  idêntico ao passado por parâmetro e deve
			 *                ser levado em conta caixa alta/baixa,
			 *                acentuação e espaços.
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
			 * Os valores estão num buffer, i. e., não são recalculados
			 * a cada chamada, pode chamar tranquilo! ;)
			 */
			virtual const Lista<string>& apelidos() const;

			/**
			 * Retorna o valor sem acentos e todo em minúsculas.
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
			 * Verifica se os originais são idênticos.
			 * @see #igual(const Igualavel&)
			 */
			virtual const bool identico(const Valor& valor) const;

			/**
			 * É 0 se não puder ser convertido.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const int emInt() const;

			/**
			 * É 0.0 se não puder ser convertido.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const double emDouble() const;

			/**
			 * Retorna true para V (maiúsculo) e
			 * false para todos os outros casos.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const bool emBool() const;

			/**
			 * Quando é V ou F.
			 */
			virtual const bool pareceSerBoleano() const;

			/**
			 * Quando todos os caracteres são números ou ponto (.).
			 */
			virtual const bool pareceSerNumero() const;

			/**
			 * Quando algum dos dígitos não é número ou ponto (.) nem
			 * a string toda é V ou F.
			 */
			virtual const bool pareceSerString() const;

			/**
			 * Indica se este valor é irrelevante. Se for,
			 * nenhuma operação exceto a comparação (== ou !=)
			 * pode ser feita.
			 *
			 * @see Irrelevante
			 */
			virtual const bool indefinida() const {
				bool retorno = Informacao::indefinida();
				return retorno;
			}

			/**
			 * Gera uma string única e completa
			 * que identifica este Valor como sendo único
			 * pelo seu conteúdo. Leva em conta nome original,
			 * modificado e todos os apelidos.
			 */
			virtual string geraStringUnicaECompleta() const;

			// Comparavel:
			/**
			 * Para efeito de comparação, F é menor que V. Quando
			 * <b>ambos</b> puderem, eles serão convertidos para double ou bool antes
			 * de serem comparados. Caso contrário, utiliza a mesma regra de
			 * comparação de string (string.compare()),
			 * mas com o {@link #valor()}.
			 *
			 * @throws InformacaoNaoDefinidaExcecao
			 *         Caso este Valor esteja indefinido.
			 */
			virtual const bool menorQue(const Comparavel& alheio) const;

			// Igualavel:
			/**
			 * Verifica se é igual ao {@link #valor()}
			 * ou se é igual a algum dos apelidos. Ou se ambos são
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
