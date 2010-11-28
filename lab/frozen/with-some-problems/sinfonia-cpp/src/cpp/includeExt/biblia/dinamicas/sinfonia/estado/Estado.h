/*
 * $RCSfile: Estado.h,v $
 * $Date: 2005/03/03 03:32:25 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(Estado_h)
#define Estado_h

#include "biblia/basico/Objeto.h"
#include "biblia/basico/Identificacao.h"
#include "biblia/tempo/Momento.h"
#include "biblia/armazenamento/volatil/Informacao.h"
#include "biblia/dinamicas/sinfonia/estado/Comparacao.h"

using namespace biblia::basico;
using namespace biblia::tempo;
using namespace biblia::armazenamento::volatil;

namespace biblia {
  namespace dinamicas {
    namespace sinfonia {
      namespace estado {
		/**
		 * � lido/entendido a partir de
		 * Compara��es com outros Estados.
		 * 
		 * Possui uma Informa��o que representa o seu valor.
		 * 
		 * Se for constante ele representa um
		 * MomentoDoEstado (uma c�pia de
		 * algum estado "vivo")
		 * 
		 * <i>Use de prefer�ncia tipos primitivos (exceto Composto) por
		 * causa das opera��es feitas com o Estado.</i>
		 */
		class Estado: public Objeto {
			private:
				Momento* Estado::pMomento;
				Identificacao* Estado::pIdentificadoPor;
				Informacao* Estado::pInformacao;
				Identificacao* Estado::pIdentificacaoString;

			public:
				/**
				 * veja a outra fun��o compara
				 */
				virtual const bool Estado
						::compara(const Comparacao&, const Estado&) const;

				/**
				 * Sabe se 'comparar' com outro Estado.
				 * 
				 * funcionamento interno:
				 * - se internamente for um Composto de
				 *   apenas um Elemento e esse
				 *   Elemento for de um Tipo primitivo
				 *   ele faz a devida compara��o e
				 *   retorna;
				 * 
				 * - caso contr�rio faz a compara��o
				 *   em todos os elementos do
				 *   Composto recursivamente.
				 */
				virtual Comparacao Estado
						::compara(const Estado& outro) const;

				const bool& Estado::especial() const;
				const bool& Estado::generico() const;
				const bool& Estado::eterno() const;

				/**
				 * Representa um Estado constante,
				 * ou a c�pia de um Estado.
				 */
				const bool& Estado::congelado() const;

				/**
				 * Se for constante retorna o momento
				 * em que foi "congelado",  caso
				 * contr�rio retorna a data atual.
				 */
				virtual Momento Estado::Momento() const;
				virtual Estado& Estado::descongela();

				virtual const bool& Estado::possuiEstadosFilhos() const;
		};
	  }
	}
  }
}

#endif /* Estado_h */
