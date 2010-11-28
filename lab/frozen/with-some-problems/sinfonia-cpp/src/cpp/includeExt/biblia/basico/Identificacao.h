/*
 * $RCSfile: Identificacao.h,v $
 * $Date: 2005/01/20 21:28:40 $
 * $Revision: 1.7 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
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
	 * Representa uma identificação (conhecida/classificada por uma
	 * terceira classe) imutável que pode ser comparada com outra
	 * identificação.
	 */
	class Identificacao: public Objeto {
		friend class FabricaDeIdentificacao;

		private:
			std::string Identificacao::pId;

		public:
			/**
			 * Por questões de compatibilidade
			 * e praticidade.
			 */
			Identificacao::Identificacao();

			/**
			 * Por questões de praticidade.
			 * @see #Identificacao(const std::string&)
			 */
			Identificacao::Identificacao(const char*);

			/**
			 * Construtor oficial. É público por
			 * questões de praticidade, prefira utilizar
			 * fábrica para criar uma identificação.
			 */
			Identificacao::Identificacao(const std::string&);
			virtual Identificacao::~Identificacao();

			virtual const bool Identificacao
					::menorQue(const Identificacao& outra) const;

			virtual const bool Identificacao
					::mesma(const Identificacao& outra) const;

			// operadores de comparação
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
			 * Esta função retorna uma std::string única
			 * relativa a esta identificação.
			 * <p>
			 * Esta std::string é uma cópia fiel de seu
			 * conteúdo porém deve ser evitada para
			 * que efeitos de polimorfismos se
			 * tornem interessantes. Prefira utilizar
			 * comparações e a FabricaDeIdentificacao
			 * ao invés de diretamente esta função.
			 * Ela existe e está pública porque há
			 * casos indispensáveis de seu uso.
			 * <p>
			 * Nota: <i>muitas vezes seu conteúdo poderá
			 * ser (humanamente) ilegível porque sua
			 * principal característica é poder ser
			 * entendida através de comparações
			 * e não pelo conteúdo da std::string em si.</i>
			 */
			virtual std::string Identificacao::emString() const;

			/**
			 * Questões de compatibilidade com o conceito
			 * de objeto-função.
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
