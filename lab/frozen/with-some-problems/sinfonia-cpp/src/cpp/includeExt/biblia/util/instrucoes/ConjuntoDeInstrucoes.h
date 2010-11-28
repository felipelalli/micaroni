/*
 * $RCSfile: ConjuntoDeInstrucoes.h,v $
 * $Date: 2004/01/28 23:46:59 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#if !defined(ConjuntoDeInstrucoes_h)
#define ConjuntoDeInstrucoes_h

#include "biblia/basico/Objeto.h"
#include "biblia/util/instrucoes/Instrucao.h"
#include "biblia/armazenamento/volatil/carcacas/Lista.h"
#include "biblia/armazenamento/volatil/primitivos/Inteiro.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil::carcacas;
using namespace biblia::armazenamento::volatil::primitivos;

namespace biblia {
  namespace util {
    namespace instrucoes {
		/*
		 * � um conjunto de instru��es ordenadas.
		 * <p>� usado para agrupar instru��es e
		 * quando sua ordem � importante.
		 */
		class ConjuntoDeInstrucoes: public Objeto {
			private:
				Lista<Instrucao> ConjuntoDeInstrucoes::pInstrucoes;

			public:
				ConjuntoDeInstrucoes::ConjuntoDeInstrucoes();

				/**
				 * Cria um conjunto de instru��es com
				 * uma instru��o inicial. Isso pode
				 * facilitar na quest�o pr�tica quando
				 * um construtor recebe um conjunto de
				 * instru��es e voc� precisa passar uma
				 * instru��o s�.
				 */
				ConjuntoDeInstrucoes::ConjuntoDeInstrucoes(
						const Instrucao&);

				virtual ConjuntoDeInstrucoes::~ConjuntoDeInstrucoes();

				virtual ConjuntoDeInstrucoes& ConjuntoDeInstrucoes
						::adiciona(const Instrucao&);

				virtual const Instrucao& ConjuntoDeInstrucoes
						::instrucao(const Inteiro&) const;

				virtual const int ConjuntoDeInstrucoes
						::quantasInstrucoes() const;

				// Objeto:

				/**
				 * Retorna: {1. instrucao1,
				 *          2. instrucao2, ...}
				 * <p>
				 * Esta fun��o pode ser lenta.
				 */
				virtual std::string ConjuntoDeInstrucoes
						::emString() const;
		};
	}
  }
}

#endif /* ConjuntoDeInstrucoes_h */
