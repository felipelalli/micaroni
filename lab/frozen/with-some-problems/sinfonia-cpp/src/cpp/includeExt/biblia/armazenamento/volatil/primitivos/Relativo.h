/*
 * $RCSfile: Relativo.h,v $
 * $Date: 2005/01/20 21:28:38 $
 * $Revision: 1.9 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Relativo_h)
#define Relativo_h

#include "biblia/armazenamento/volatil/Informacao.h"
using namespace biblia::armazenamento::volatil;

#include "biblia/util/Debug.h"
using namespace biblia::util;

#include "biblia/armazenamento/volatil/primitivos/Flutuante.h"
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace primitivos {
		class ConhecedorDePrimitivos;

		class Relativo: public Informacao {
			friend class ConhecedorDePrimitivos;

			private:
				double Relativo::pParte;
				int Relativo::pTodo;

			public:
				static const Relativo Relativo::TODO;
				static const Relativo Relativo::ZERO;

				Relativo::Relativo();
				Relativo::Relativo(
						const double& parte,
						const int& todo);

				virtual Relativo::~Relativo();

				/**
				 * Função objeto (discutido em
				 * doc/poo-cpp.html §Objetos Função)
				 * que retorna o valor.
				 */
				virtual const double Relativo::operator()() const;

				/**
				 * Representa o valor deste
				 * relativo em porcentagem (%).
				 * <p>
				 * O resultado é a divisão entre parte
				 * e todo multiplicado por 100.
				 */
				virtual const double Relativo::valor() const;

				virtual const double& Relativo::parte() const;
				virtual const int& Relativo::todo() const;

				virtual Relativo& Relativo
						::define(const double& parte,
								 const int& todo);

				virtual const bool Relativo
						::menorQue(const Relativo&) const;

				virtual const bool Relativo
						::mesmo(const Relativo&) const;

				// operadores
				// veja mesmo(...) e menorQue(...)

				virtual const bool Relativo
						::operator!=(const Relativo& outro) const
				{
					return !(*this == outro);
				}

				virtual const bool Relativo
						::operator==(const Relativo& outro) const
				{
					return this->mesmo(outro);
				}

				virtual const bool Relativo
						::operator<(const Relativo& outro) const
				{
					return this->menorQue(outro);
				}

				virtual const bool Relativo
						::operator>(const Relativo& outro) const
				{
					return outro.menorQue(*this);
				}

				virtual const bool Relativo
						::operator>=(const Relativo& outro) const
				{
					return this->mesmo(outro)
						|| outro.menorQue(*this);
				}

				virtual const bool Relativo
						::operator<=(const Relativo& outro) const
				{
					return this->mesmo(outro)
						|| this->menorQue(outro);
				}

				// atribuição:
				virtual Relativo& Relativo::operator=(const Relativo&);

				// Informação:
				virtual const Tipo Relativo::tipo() const {
					return Tipo("%!");
				}

				// Objeto:
				virtual std::string Relativo::emString() const;
		};
	  }
	}
  }
}

#endif /* Relativo_h */
