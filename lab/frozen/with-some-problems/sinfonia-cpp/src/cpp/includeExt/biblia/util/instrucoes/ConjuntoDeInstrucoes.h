/*
 * $RCSfile: ConjuntoDeInstrucoes.h,v $
 * $Date: 2004/01/28 23:46:59 $
 * $Revision: 1.5 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
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
		 * É um conjunto de instruções ordenadas.
		 * <p>É usado para agrupar instruções e
		 * quando sua ordem é importante.
		 */
		class ConjuntoDeInstrucoes: public Objeto {
			private:
				Lista<Instrucao> ConjuntoDeInstrucoes::pInstrucoes;

			public:
				ConjuntoDeInstrucoes::ConjuntoDeInstrucoes();

				/**
				 * Cria um conjunto de instruções com
				 * uma instrução inicial. Isso pode
				 * facilitar na questão prática quando
				 * um construtor recebe um conjunto de
				 * instruções e você precisa passar uma
				 * instrução só.
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
				 * Esta função pode ser lenta.
				 */
				virtual std::string ConjuntoDeInstrucoes
						::emString() const;
		};
	}
  }
}

#endif /* ConjuntoDeInstrucoes_h */
