/*
 * $RCSfile: Boleano.h,v $
 * $Date: 2004/02/26 18:49:18 $
 * $Revision: 1.11 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Boleano_h)
#define Boleano_h

#include "biblia/armazenamento/volatil/Informacao.h"
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace primitivos {
		class ConhecedorDePrimitivos;

		class Boleano: public Informacao {
			friend class ConhecedorDePrimitivos;

			private:
				bool Boleano::pValor;

			public:
				Boleano::Boleano();
				Boleano::Boleano(const bool&);
				virtual Boleano::~Boleano();

				/**
				 * Função objeto (discutido em
				 * doc/poo-cpp.html §Objetos Função)
				 * que retorna o valor.
				 */
				virtual const bool& Boleano::operator()() const {
					return this->valor();
				}

				virtual const bool& Boleano::valor() const;

				virtual Boleano& Boleano::define(
						const bool& novoValor);

				/**
				 * Por definição <b>false</b> é
				 * menor que <b>true</b>.
				 */
				virtual const bool Boleano
						::menorQue(const Boleano&) const;

				virtual const bool Boleano
						::mesmo(const Boleano&) const;

				// operadores
				// veja mesmo(...) e menorQue(...)

				virtual const bool Boleano
						::operator!=(const Boleano& outro) const
				{
					return !(*this == outro);
				}

				virtual const bool Boleano
						::operator==(const Boleano& outro) const
				{
					return this->mesmo(outro);
				}

				virtual const bool Boleano
						::operator<(const Boleano& outro) const
				{
					return this->menorQue(outro);
				}

				virtual const bool Boleano
						::operator>(const Boleano& outro) const
				{
					return outro.menorQue(*this);
				}

				virtual const bool Boleano
						::operator>=(const Boleano& outro) const
				{
					return this->mesmo(outro)
						|| outro.menorQue(*this);
				}

				virtual const bool Boleano
						::operator<=(const Boleano& outro) const
				{
					return this->mesmo(outro)
						|| this->menorQue(outro);
				}

				// atribuição:
				virtual Boleano& Boleano::operator=(const Boleano&);

				// Informação:
				virtual const Tipo Boleano::tipo() const {
					return Tipo("bool!");
				}

				// Objeto:
				virtual std::string Boleano::emString() const;
		};
	  }
	}
  }
}

#endif /* Boleano_h */
