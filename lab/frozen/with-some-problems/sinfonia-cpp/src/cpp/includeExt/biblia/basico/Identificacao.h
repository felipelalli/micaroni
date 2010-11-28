/*
 * $RCSfile: Identificacao.h,v $
 * $Date: 2005/01/20 21:28:40 $
 * $Revision: 1.7 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Identificacao_h)
#define Identificacao_h

#include <string>
#include "biblia/basico/Objeto.h"

using namespace std;

namespace biblia {
  namespace basico {
    class FabricaDeIdentificacao;

	/**
	 * Representa uma identifica��o (conhecida/classificada por uma
	 * terceira classe) imut�vel que pode ser comparada com outra
	 * identifica��o.
	 */
	class Identificacao: public Objeto {
		friend class FabricaDeIdentificacao;

		private:
			std::string Identificacao::pId;

		public:
			/**
			 * Por quest�es de compatibilidade
			 * e praticidade.
			 */
			Identificacao::Identificacao();

			/**
			 * Por quest�es de praticidade.
			 * @see #Identificacao(const std::string&)
			 */
			Identificacao::Identificacao(const char*);

			/**
			 * Construtor oficial. � p�blico por
			 * quest�es de praticidade, prefira utilizar
			 * f�brica para criar uma identifica��o.
			 */
			Identificacao::Identificacao(const std::string&);
			virtual Identificacao::~Identificacao();

			virtual const bool Identificacao
					::menorQue(const Identificacao& outra) const;

			virtual const bool Identificacao
					::mesma(const Identificacao& outra) const;

			// operadores de compara��o
			// veja mesma(...) e menorQue(...)

			virtual const bool Identificacao
					::operator!=(const Identificacao& outra) const
			{
				return !this->mesma(outra);
			}

			virtual const bool Identificacao
					::operator==(const Identificacao& outra) const
			{
				return this->mesma(outra);
			}

			virtual const bool Identificacao
					::operator<(const Identificacao& outra) const
			{
				return this->menorQue(outra);
			}

			virtual const bool Identificacao
					::operator>(const Identificacao& outra) const
			{
				return outra.menorQue(*this);
			}

			virtual const bool Identificacao
					::operator>=(const Identificacao& outra) const
			{
				return this->mesma(outra)
					|| outra.menorQue(*this);
			}

			virtual const bool Identificacao
					::operator<=(const Identificacao& outra) const
			{
				return this->mesma(outra)
					|| this->menorQue(outra);
			}

			// outros operadores
			virtual Identificacao& Identificacao
					::operator=(const Identificacao& outra);

			// Objeto:

			/**
			 * Esta fun��o retorna uma std::string �nica
			 * relativa a esta identifica��o.
			 * <p>
			 * Esta std::string � uma c�pia fiel de seu
			 * conte�do por�m deve ser evitada para
			 * que efeitos de polimorfismos se
			 * tornem interessantes. Prefira utilizar
			 * compara��es e a FabricaDeIdentificacao
			 * ao inv�s de diretamente esta fun��o.
			 * Ela existe e est� p�blica porque h�
			 * casos indispens�veis de seu uso.
			 * <p>
			 * Nota: <i>muitas vezes seu conte�do poder�
			 * ser (humanamente) ileg�vel porque sua
			 * principal caracter�stica � poder ser
			 * entendida atrav�s de compara��es
			 * e n�o pelo conte�do da std::string em si.</i>
			 */
			virtual std::string Identificacao::emString() const;

			/**
			 * Quest�es de compatibilidade com o conceito
			 * de objeto-fun��o.
			 *
			 * @see #emString() const
			 */
			virtual std::string Identificacao::operator()() const {
				return this->emString();
			}
	};
  }
}

#endif /* Identificacao_h */
