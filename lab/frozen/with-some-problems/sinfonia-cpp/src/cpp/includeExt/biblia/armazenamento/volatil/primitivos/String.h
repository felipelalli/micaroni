/*
 * $RCSfile: String.h,v $
 * $Date: 2005/01/20 21:28:39 $
 * $Revision: 1.9 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(String_h)
#define String_h

#include <string>
#include "biblia/armazenamento/volatil/Informacao.h"

using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento {
    namespace volatil {
	  namespace primitivos {
		class ConhecedorDePrimitivos;

		class String: public Informacao {
			friend class ConhecedorDePrimitivos;

			private:
				std::string String::pValor;

			public:
				String::String();
				String::String(const std::string&);

				/**
				 * Por quest�es de praticidade.
				 * @see #String(const std::string&)
				 */
				String::String(const char*);

				virtual String::~String();

				virtual const unsigned int String
						::tamanho() const;

				/**
				 * Fun��o objeto (discutido em
				 * doc/poo-cpp.html �Objetos Fun��o)
				 * que retorna o valor.
				 */
				virtual const std::string& String::operator()() const {
					return this->valor();
				}

				/**
				 * Fun��o objeto (discutido em
				 * doc/poo-cpp.html �Objetos Fun��o)
				 * que retorna o valor.
				 */
				virtual std::string& String::operator()() {
					return this->valor();
				}

				virtual std::string& String::valor();
				virtual const std::string& String::valor() const;
				virtual String& String::define(const std::string& = "");

				virtual const bool String
						::menorQue(const String&) const;

				virtual const bool String
						::mesmo(const String&) const;

				// operadores
				// veja mesmo(...) e menorQue(...)

				virtual const bool String
						::operator!=(const String& outro) const
				{
					return !(*this == outro);
				}

				virtual const bool String
						::operator==(const String& outro) const
				{
					return this->mesmo(outro);
				}

				virtual const bool String
						::operator<(const String& outro) const
				{
					return this->menorQue(outro);
				}

				virtual const bool String
						::operator>(const String& outro) const
				{
					return outro.menorQue(*this);
				}

				virtual const bool String
						::operator>=(const String& outro) const
				{
					return this->mesmo(outro)
						|| outro.menorQue(*this);
				}

				virtual const bool String
						::operator<=(const String& outro) const
				{
					return this->mesmo(outro)
						|| this->menorQue(outro);
				}

				// atribui��o:
				virtual String& String::operator=(const String&);
				virtual String& String::operator+=(const String&);

				// Informa��o:
				virtual const Tipo String::tipo() const {
					return Tipo("std::string!");
				}

				// Objeto:
				virtual std::string String::emString() const;
		};
	  }
	}
  }
}

#endif /* String_h */
