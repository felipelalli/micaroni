/*
 * $RCSfile: Pacote.h,v $
 * $Date: 2005/01/20 21:28:32 $
 * $Revision: 1.9 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Pacote_h)
#define Pacote_h

#include <string>
#include "biblia/basico/Objeto.h"
#include "biblia/basico/Excecao.h"
#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/volatil/Informacao.h"
#include "biblia/armazenamento/volatil/carcacas/DadosSemTipo.h"
#include "biblia/armazenamento/eterno/EternoExcecao.h"

using namespace std;
using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;
using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::eterno;

//#include "biblia/util/Debug.h"
//using namespace biblia::util;

namespace biblia {
  namespace armazenamento {
    namespace eterno {
      namespace empacotamento {

		/**
		 * Representa um Pacote que � fruto de um
		 * ato de "empacotamento" de qualquer Informacao.
		 * <p>
		 * Carrega consigo toda informa��o necess�ria
		 * para se formar uma Informa��o. � importante
		 * entender que nem toda informa��o � "empacot�vel"
		 * num pacote s�. Algumas estruturas s�o complexas
		 * demais e necessitam de mais de um pacote para
		 * serem representadas. Principalmente aquelas que
		 * cont�m tamanho vari�vel. Uma lista, por exemplo,
		 * poderia ser custoso demais se fosse "empacotada"
		 * num pacote s�. Provavelmente ela se transformaria
		 * num "pacote-�ndice" e um "pacote-nomeado"
		 * para cada elemento da lista.
		 * <p>
		 * Este pacote pode ser guardado em formato
		 * de DadosSemTipo (de tamanho fixo)
		 * ou [exclusivo] em std::string (tamanho vari�vel).
		 * A diferen�a b�sica entre os dois � que
		 * um DadosSemTipo possui um tamanho e um
		 * conjunto de bytes qualquer, enquanto uma
		 * std::string possui um conjunto de bytes terminando
		 * no byte 0 (ou NULL). Portanto, no tipo de
		 * dado de tamanho vari�vel n�o � poss�vel
		 * armazenar o byte 0.
		 * <p>
		 * O pacote s� funciona de um modo por vez.
		 * Se este pacote tiver sido constru�do
		 * para dados de tamanho fixo somente a
		 * fun��o dadosByte() funcionar�. Caso tiver
		 * sido constru�do para dados de tamanho
		 * vari�vel somente a fun��o dadosString()
		 * funcionar�. --- Essa possibilidade est� ligada
		 * diretamente � otimiza��o no armazenamento
		 * da informa��o, sendo algumas mais adequadas
		 * para tamanho fixo e outras para vari�vel.
		 * <p>
		 * Atributos de um Pacote:
		 * <br> - <b>tipo dos dados</b>: Tipo
		 * <br> - <b>tipo do armazenamento</b>: tamanho fixo ou vari�vel
		 * <br> - <b>dados</b>: DadosSemTipo ou std::string
		 * <p>
		 *  Do dicion�rio Aur�lio:
		    <p>
			<b>pacote</b> . [Dim. de paca1 (q. v.).] S. m. 1. Pequeno ma�o ou pequeno embrulho: um pacote de dinheiro; um pacote de papel
			pardo. 2. O conjunto de unidades contidas num pacote (1): Um pacote de cigarros cont�m dez ma�os. 3. P. ext. Bras.
			Qualquer coisa semelhante a pacote (1); combina��o de elementos que se relacionam, e que s�o tomados como um todo: Os
			agentes de viagem oferecem excelente pacote para f�rias na Bahia. 4. Fig. Logro, embuste, engano. 5. Market. Conjunto de
			itens relacionados, como, p. ex., programas de TV ou servi�os tur�sticos, comercializados como um todo, usualmente com
			desconto. 6. Bras. Grande quantidade de mercadoria negociada em conjunto e, ger., em transa��o vultosa. 7. Bras. Pop.
			Conjunto de medidas governamentais, sobretudo na �rea econ�mica, adotadas simultaneamente: Espera-se para amanh� novo
			pacote na �rea econ�mica. 8. Inform. Bloco de informa��o preparado para trafegar numa rede de computadores, com um
			cabe�alho que identifica a sua origem e o seu destino; datagrama. [Cf. comuta��o de pacotes.] ~ V. pacotes. Pacote de
			ondas. F�s. 1. Conjunto finito de ondas que transporta energia de um para outro ponto do espa�o; grupo de onda, trem de
			onda. Ir no pacote. Bras. G�r. 1. Ser enganado; deixar-se lograr.
		 */
		 class Pacote: public Objeto {
			private:
				Tipo Pacote::pDeQualTipo;
				DadosSemTipo* Pacote::pDados;
				std::string Pacote::pString;
				bool Pacote::pTamanhoFixo;
				Pacote::Pacote(const Pacote&);
				bool Pacote::pApagarDados;

			public:
				/**
				 * Este Pacote, por padr�o,
				 * fica encarregado de
				 * deletar os DadosSemTipo passado no
				 * construtor. Este construtor
				 * contr�i um pacote de tamanho fixo.
				 *
				 * @param apagarDados indica se
				 *        os dados passados como
				 *        par�metro devem ser ou
				 *        n�o apagados no destrutor.
				 */
				Pacote::Pacote(
						DadosSemTipo*,
						const Tipo& tipo,
						const bool& apagarDados = true);

				/**
				 * Este construtor
				 * contr�i um pacote de
				 * tamanho vari�vel.
				 */
				Pacote::Pacote(
						const std::string& dados,
						const Tipo& tipo);

				virtual Pacote::~Pacote();

				/**
				 * Se este pacote for de tamanho
				 * fixo os dados s�o guardados em bytes,
				 * caso contr�rio s�o guardados em std::string.
				 */
				virtual const bool& Pacote::tamanhoFixo() const;

				/**
				 * @see #tamanhoFixo()
				 */
				virtual const bool Pacote::tamanhoVariavel() const {
					return !this->tamanhoFixo();
				}

				/**
				 * Retorna os dados em forma de bytes.
				 * Somente para dados de tamanho fixo.
				 *
				 * @throw PacoteDeTamanhoVariavelExcecao
				 * @see #tamanhoFixo()
				 */
				virtual const DadosSemTipo& Pacote::dadosByte() const;

				/**
				 * Retorna os dados em forma de std::string.
				 * Somente para dados de tamanho vari�vel.
				 *
				 * @throw PacoteDeTamanhoFixoExcecao
				 * @see #tamanhoFixo()
				 */
				virtual const std::string& Pacote::dadosString() const;

				/**
				 * Tipo ao qual este pacote pertence.
				 */
				virtual const Tipo& Pacote::tipo() const;

				/**
				 * Muda o tipo deste pacote.
				 */
				virtual Pacote& Pacote::mudaTipo(const Tipo&);

				// operadores:
				virtual const bool Pacote
						::operator==(const Pacote&) const;

				virtual const bool Pacote
						::operator!=(const Pacote& p) const
				{
					return !((*this) == p);
				}

				// Objeto:
				virtual std::string Pacote::emString() const;
		};
	  }
	}
  }
}

#endif /* Pacote_h */
