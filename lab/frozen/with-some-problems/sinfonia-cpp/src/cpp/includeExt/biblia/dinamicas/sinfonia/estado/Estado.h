/*
 * $RCSfile: Estado.h,v $
 * $Date: 2005/03/03 03:32:25 $
 * $Revision: 1.4 $
 * $Name:  $
 * $Author: felipelalli $
 *
 * Implementação da Nova Bíblia.
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
		 * É lido/entendido a partir de
		 * Comparações com outros Estados.
		 * 
		 * Possui uma Informação que representa o seu valor.
		 * 
		 * Se for constante ele representa um
		 * MomentoDoEstado (uma cópia de
		 * algum estado "vivo")
		 * 
		 * <i>Use de preferência tipos primitivos (exceto Composto) por
		 * causa das operações feitas com o Estado.</i>
		 */
		class Estado: public Objeto {
			private:
				Momento* Estado::pMomento;
				Identificacao* Estado::pIdentificadoPor;
				Informacao* Estado::pInformacao;
				Identificacao* Estado::pIdentificacaoString;

			public:
				/**
				 * veja a outra função compara
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
				 *   ele faz a devida comparação e
				 *   retorna;
				 * 
				 * - caso contrário faz a comparação
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
				 * ou a cópia de um Estado.
				 */
				const bool& Estado::congelado() const;

				/**
				 * Se for constante retorna o momento
				 * em que foi "congelado",  caso
				 * contrário retorna a data atual.
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
