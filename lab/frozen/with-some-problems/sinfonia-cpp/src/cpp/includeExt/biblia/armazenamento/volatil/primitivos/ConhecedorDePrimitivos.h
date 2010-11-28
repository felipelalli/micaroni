/*
 * $RCSfile: ConhecedorDePrimitivos.h,v $
 * $Date: 2005/01/20 21:28:37 $
 * $Revision: 1.7 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(ConhecedorDePrimitivos_h)
#define ConhecedorDePrimitivos_h

#include "biblia/basico/Identificacao.h"
#include "biblia/basico/FabricaDeIdentificacao.h"
#include "biblia/armazenamento/volatil/Tipo.h"
#include "biblia/armazenamento/volatil/Universo.h"
#include "biblia/armazenamento/volatil/FabricaDeInformacao.h"
#include "biblia/armazenamento/volatil/primitivos/Boleano.h"
#include "biblia/armazenamento/volatil/primitivos/Flutuante.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"
#include "biblia/armazenamento/volatil/primitivos/Relativo.h"
#include "biblia/armazenamento/volatil/primitivos/String.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace armazenamento{
    namespace volatil {
	  namespace primitivos {
		/**
		 * Pode produzir qualquer um dos
		 * tipos primitivos deste pacote.
		 * <p>
		 * Sempre que poss�vel prefira utilizar
		 * esta classe para a cria��o dos tipos
		 * primitivos.
		 * <p>
		 * A partir de uma identifica��o do tipo (typeid,
		 * Identifica��o) cria uma
		 * inst�ncia desse tipo espec�fico.
		 */
		class ConhecedorDePrimitivos: public FabricaDeInformacao {
			public:
				/**
				 * Para efeito de compara��o, identifica
				 * um boleano.
				 */
				static Tipo	ConhecedorDePrimitivos::boleano();

				/**
				 * Para efeito de compara��o, identifica
				 * um flutuante.
				 */
				static Tipo	ConhecedorDePrimitivos::flutuante();

				/**
				 * Para efeito de compara��o, identifica
				 * um inteiro.
				 */
				static Tipo ConhecedorDePrimitivos::inteiro();

				/**
				 * Para efeito de compara��o, identifica
				 * um relativo (%).
				 */
				static Tipo	ConhecedorDePrimitivos::relativo();

				/**
				 * Para efeito de compara��o, identifica
				 * uma std::string.
				 */
				static Tipo	ConhecedorDePrimitivos::string();

				/**
				 * Verifica se uma Informa��o �
				 * um tipo primitivo.
				 */
				static const bool ConhecedorDePrimitivos
						::ePrimitivo(const Informacao& i)
				{
					return ConhecedorDePrimitivos
							::ePrimitivo(i.tipo());
				}

				/**
				 * Verifica se um 'Tipo' �
				 * um tipo primitivo.
				 */
				static const bool ConhecedorDePrimitivos
						::ePrimitivo(const Tipo&);

				ConhecedorDePrimitivos::ConhecedorDePrimitivos();

				virtual ConhecedorDePrimitivos
						::~ConhecedorDePrimitivos();

				// FabricaDeInformacao:
				virtual const bool ConhecedorDePrimitivos
						::sabeGerarUm(const Tipo& tipo) const
				{
					return ConhecedorDePrimitivos::ePrimitivo(tipo);
				}

				// Fabrica:

				/**
				 * Gera um tipo primitivo.
				 */
				virtual Objeto* ConhecedorDePrimitivos::gera();

				/**
				 * Gera um tipo primitivo.
				 */
				virtual Informacao* ConhecedorDePrimitivos
						::geraPrimitivo()
				{
					return (Informacao*) this->gera();
				}
		};
	  }
	}
  }
}

#endif /* ConhecedorDePrimitivos_h */
