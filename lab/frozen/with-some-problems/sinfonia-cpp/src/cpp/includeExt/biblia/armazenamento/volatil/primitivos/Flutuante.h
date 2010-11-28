/*
 * $RCSfile: Flutuante.h,v $
 * $Date: 2005/01/20 21:28:37 $
 * $Revision: 1.8 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Flutuante_h)
#define Flutuante_h

#include "biblia/armazenamento/volatil/Informacao.h"
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace primitivos {
		class ConhecedorDePrimitivos;

		class Flutuante: public Informacao {
			friend class ConhecedorDePrimitivos;

			private:
				double Flutuante::pValor;

			public:
				Flutuante::Flutuante();
				Flutuante::Flutuante(const double&);
				virtual Flutuante::~Flutuante();

				/**
				 * Função objeto (discutido em
				 * doc/poo-cpp.html §Objetos Função)
				 * que retorna o valor.
				 */
				virtual const double& Flutuante::operator()() const {
					return this->valor();
				}

				virtual const double& Flutuante::valor() const;
				virtual Flutuante& Flutuante::define(const double&);

				virtual const bool Flutuante
						::menorQue(const Flutuante&) const;

				virtual const bool Flutuante
						::mesmo(const Flutuante&) const;

				// operadores
				// veja mesmo(...) e menorQue(...)

				virtual const bool Flutuante
						::operator!=(const Flutuante& outro) const
				{
					return !(*this == outro);
				}

				virtual const bool Flutuante
						::operator==(const Flutuante& outro) const
				{
					return this->mesmo(outro);
				}

				virtual const bool Flutuante
						::operator<(const Flutuante& outro) const
				{
					return this->menorQue(outro);
				}

				virtual const bool Flutuante
						::operator>(const Flutuante& outro) const
				{
					return outro.menorQue(*this);
				}

				virtual const bool Flutuante
						::operator>=(const Flutuante& outro) const
				{
					return this->mesmo(outro)
						|| outro.menorQue(*this);
				}

				virtual const bool Flutuante
						::operator<=(const Flutuante& outro) const
				{
					return this->mesmo(outro)
						|| this->menorQue(outro);
				}

				// atribuição:
				virtual Flutuante& Flutuante::operator=(const Flutuante&);

				// extra/opcional:
				virtual std::string Flutuante
						::emString(std::string
								formatacaoAoEstiloPrintf) const;

				// Informação:
				virtual const Tipo Flutuante::tipo() const {
					return Tipo("double!");
				}

				// Objeto:
				virtual std::string Flutuante::emString() const;
		};
	  }
	}
  }
}

#endif /* Flutuante_h */
