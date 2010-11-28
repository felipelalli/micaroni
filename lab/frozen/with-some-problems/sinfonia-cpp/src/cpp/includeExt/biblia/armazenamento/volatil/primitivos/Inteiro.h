/*
 * $RCSfile: Inteiro.h,v $
 * $Date: 2005/01/20 21:28:38 $
 * $Revision: 1.13 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Inteiro_h)
#define Inteiro_h

#pragma warning(disable:4244) // warning C4244: 'initializing' : conversion from 'double' to 'int', possible loss of data

#include <string>
#include <cmath>

#ifdef WIN32
#include <limits>//FIXME LINUX: N�O EXISTE NO LINUX
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
		 * Representa um n�mero inteiro.
		 * <p>
		 * <i>Por uma limita��o interna, este Inteiro
		 * tem a precis�o restrita a 32 bits. Isso
		 * significa que o valor deve estar compreendido entre
		 * -2.147.483.648 e 2.147.483.647 . Essa limita��o
		 * transforma "perigosas" contas com n�meros na casa
		 * do bilh�o, por�m otimiza a velocidade nas contas
		 * os n�meros poss�veis. Consute as fun��es
		 * {@link #valorMinimo()} e {@link #valorMaximo()}
		 * para obter com precis�o o valor m�nimo e m�ximo
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
				 * Retorna o valor m�ximo que um Inteiro
				 * � capaz de armazenar.
				 */
				static Inteiro Inteiro::valorMaximo();

				/**
				 * Retorna o valor m�nimo que um Inteiro
				 * � capaz de armazenar.
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
				 * Representa que n�o � necess�rio
				 * colocar sinal para representar
				 * n�meros positivos. E. g.,
				 * 562 � considerado n�mero positivo
				 * apesar do sufixo "+" ausente.
				 */
				static char Inteiro::SINAL_POSITIVO_AUSENTE;

				/**
				 * Transforma este inteiro numa std::string
				 * de base qualquer. O padr�o � na base
				 * definida pelos caracteres da constante
				 * {@link Inteiro::DECIMAL}.
				 * <p>
				 * <i>Nota: Esta fun��o est� otimizada para
				 * funcionar com os par�metros padr�es.
				 * </i>
				 *
				 * @param caracteres Os caracteres
				 *        que comp�e a base completa sempre
				 *		  come�ando em 0.
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
				 * Contr�i um inteiro a partir de
				 * uma std::string de base qualquer. Por
				 * padr�o utiliza a constante
				 * {@link Inteiro::DECIMAL}.
				 * <p>
				 * <i>Nota: Esta fun��o est� otimizada para
				 * funcionar com os par�metros padr�es.
				 * </i>
				 *
				 * @throws FormatoInteiroInvalidoExcecao
				 *         Caso esteja num formato
				 *         "ileg�vel" ou tenha acontecido
				 *         algum "overflow"; consulte o limite
				 *         m�ximo que este inteiro pode armazenar.
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

				// compara��es:

				virtual const int& Inteiro::valor() const;
				virtual Inteiro& Inteiro::define(const int&);

				// Informa��o:
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
