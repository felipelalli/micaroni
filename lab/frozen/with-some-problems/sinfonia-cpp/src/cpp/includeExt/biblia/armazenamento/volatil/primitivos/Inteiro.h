/*
 * $RCSfile: Inteiro.h,v $
 * $Date: 2005/01/20 21:28:38 $
 * $Revision: 1.13 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Inteiro_h)
#define Inteiro_h

#pragma warning(disable:4244) // warning C4244: 'initializing' : conversion from 'double' to 'int', possible loss of data

#include <string>
#include <cmath>

#ifdef WIN32
#include <limits>//FIXME LINUX: NÃO EXISTE NO LINUX
#endif

#include "biblia/basico/Excecao.h"
#include "biblia/armazenamento/volatil/primitivos/Primitivo.h"
//#include "biblia/armazenamento/volatil/carcacas/DadosSemTipo.h"

using namespace std;
using namespace biblia::basico;
//using namespace biblia::armazenamento::volatil::carcacas;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace primitivos {
        class ConhecedorDePrimitivos;

		/**
		 * Representa um número inteiro.
		 * <p>
		 * <i>Por uma limitação interna, este Inteiro
		 * tem a precisão restrita a 32 bits. Isso
		 * significa que o valor deve estar compreendido entre
		 * -2.147.483.648 e 2.147.483.647 . Essa limitação
		 * transforma "perigosas" contas com números na casa
		 * do bilhão, porém otimiza a velocidade nas contas
		 * os números possíveis. Consute as funções
		 * {@link #valorMinimo()} e {@link #valorMaximo()}
		 * para obter com precisão o valor mínimo e máximo
		 * respectivamente.
		 * </i>
		 */
		class Inteiro: public Primitivo {
			friend class ConhecedorDePrimitivos;

			private:
				int Inteiro::pValor;
				//mutable DadosSemTipo* Inteiro::pDados;
				mutable Objeto* Inteiro::pDados;

  			public:
				Inteiro::Inteiro();
				Inteiro::Inteiro(const int&);

				/**
				 * @throws ForaDoIntervaloExcecao
				 *         Caso o inteiro passado seja
				 *         maior que o valor que este
				 *         inteiro suporta.
				 */
				Inteiro::Inteiro(const unsigned int&);

				/**
				 * @throws ForaDoIntervaloExcecao
				 *         Caso o inteiro passado seja
				 *         maior que o valor que este
				 *         inteiro suporta.
				 */
				Inteiro::Inteiro(const UNSIGNED_INT_64_BIBLIA&);

				/**
				 * @throws ForaDoIntervaloExcecao
				 *         Caso o inteiro passado seja
				 *         maior que o valor que este
				 *         inteiro suporta.
				 */
				Inteiro::Inteiro(const INT_64_BIBLIA&);
				virtual Inteiro::~Inteiro();

				// auxiliar:

				/**
				 * Retorna o valor máximo que um Inteiro
				 * é capaz de armazenar.
				 */
				static Inteiro Inteiro::valorMaximo();

				/**
				 * Retorna o valor mínimo que um Inteiro
				 * é capaz de armazenar.
				 */
				static Inteiro Inteiro::valorMinimo();

				/**
				 * 0..9 e a..z
				 * "0123456789abcdefghijklmnopqrstuvwxyz"
				 */
				static std::string Inteiro::LETRAS;

				/**
				 * "0123456789"
				 */
				static std::string Inteiro::DECIMAL;

				/**
				 * "0123456789abcdef"
				 */
				static std::string Inteiro::HEXA;

				/**
				 * "012345678"
				 */
				static std::string Inteiro::BASE_OITO;

				/**
				 * "01"
				 */
				static std::string Inteiro::BINARIO;

				/**
				 * '-'
				 */
				static char Inteiro::SINAL_NEGATIVO;

				/**
				 * '+'
				 */
				static char Inteiro::SINAL_POSITIVO;

				/**
				 * Representa que não é necessário
				 * colocar sinal para representar
				 * números positivos. E. g.,
				 * 562 é considerado número positivo
				 * apesar do sufixo "+" ausente.
				 */
				static char Inteiro::SINAL_POSITIVO_AUSENTE;

				/**
				 * Transforma este inteiro numa std::string
				 * de base qualquer. O padrão é na base
				 * definida pelos caracteres da constante
				 * {@link Inteiro::DECIMAL}.
				 * <p>
				 * <i>Nota: Esta função está otimizada para
				 * funcionar com os parâmetros padrões.
				 * </i>
				 *
				 * @param caracteres Os caracteres
				 *        que compõe a base completa sempre
				 *		  começando em 0.
				 *
				 * @see #valorDe(const std::string&, const std::string&, const std::string&)
				 */
				virtual const std::string Inteiro
						::emLetras(const std::string& caracteres
							= Inteiro::DECIMAL,
							const char& sinalNegativo
								= Inteiro::SINAL_NEGATIVO,
							const char& sinalPositivo
								= Inteiro::SINAL_POSITIVO_AUSENTE) const;

				/**
				 * Contrói um inteiro a partir de
				 * uma std::string de base qualquer. Por
				 * padrão utiliza a constante
				 * {@link Inteiro::DECIMAL}.
				 * <p>
				 * <i>Nota: Esta função está otimizada para
				 * funcionar com os parâmetros padrões.
				 * </i>
				 *
				 * @throws FormatoInteiroInvalidoExcecao
				 *         Caso esteja num formato
				 *         "ilegível" ou tenha acontecido
				 *         algum "overflow"; consulte o limite
				 *         máximo que este inteiro pode armazenar.
				 *
				 * @see #emLetras(const std::string&, const std::string&)
				 */
				static Inteiro Inteiro::valorDe(
						const std::string& composicaoEmLetras,
						const std::string& caracteres
							= Inteiro::DECIMAL,
							const char& sinalNegativo
								= Inteiro::SINAL_NEGATIVO,
							const char& sinalPositivo
								= Inteiro::SINAL_POSITIVO_AUSENTE);

				// comparações:

				virtual const int& Inteiro::valor() const;
				virtual Inteiro& Inteiro::define(const int&);

				// Informação:
				virtual const Tipo Inteiro::tipo() const {
					return Tipo("int!");
				}

				//virtual const DadosSemTipo& Inteiro::emDados() const;

				// Objeto:
				/**
				 * Resultado equivalente a {@link #emLetras()}.
				 */
				virtual std::string Inteiro::emString() const;

				// Copiavel:
				virtual Objeto* Inteiro::geraCopia() const;
				virtual Copiavel& Inteiro::copiaEmSi(const Copiavel& alheio);

				// Comparavel:
				virtual const bool Inteiro
						::menorQue(const Comparavel& alheio) const;

				// Igualavel:
				virtual const bool Inteiro::igual(
						const Igualavel& alheio) const;
		};
	  }
	}
  }
}

#endif /* Inteiro_h */
