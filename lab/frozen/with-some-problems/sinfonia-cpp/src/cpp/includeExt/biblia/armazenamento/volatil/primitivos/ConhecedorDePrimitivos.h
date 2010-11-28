/*
 * $RCSfile: ConhecedorDePrimitivos.h,v $
 * $Date: 2005/01/20 21:28:37 $
 * $Revision: 1.7 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
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
		 * Sempre que possível prefira utilizar
		 * esta classe para a criação dos tipos
		 * primitivos.
		 * <p>
		 * A partir de uma identificação do tipo (typeid,
		 * Identificação) cria uma
		 * instância desse tipo específico.
		 */
		class ConhecedorDePrimitivos: public FabricaDeInformacao {
			public:
				/**
				 * Para efeito de comparação, identifica
				 * um boleano.
				 */
				static Tipo	ConhecedorDePrimitivos::boleano();

				/**
				 * Para efeito de comparação, identifica
				 * um flutuante.
				 */
				static Tipo	ConhecedorDePrimitivos::flutuante();

				/**
				 * Para efeito de comparação, identifica
				 * um inteiro.
				 */
				static Tipo ConhecedorDePrimitivos::inteiro();

				/**
				 * Para efeito de comparação, identifica
				 * um relativo (%).
				 */
				static Tipo	ConhecedorDePrimitivos::relativo();

				/**
				 * Para efeito de comparação, identifica
				 * uma std::string.
				 */
				static Tipo	ConhecedorDePrimitivos::string();

				/**
				 * Verifica se uma Informação é
				 * um tipo primitivo.
				 */
				static const bool ConhecedorDePrimitivos
						::ePrimitivo(const Informacao& i)
				{
					return ConhecedorDePrimitivos
							::ePrimitivo(i.tipo());
				}

				/**
				 * Verifica se um 'Tipo' é
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
