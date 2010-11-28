/*
 * $RCSfile: Processador.h,v $
 * $Date: 2004/03/30 21:09:21 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementa��o da Nova B�blia.
 * Streamworks, outubro de 2003.
 */

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#pragma warning(disable:4290) // SLTport: C++ Exception Specification ignored
#endif

#if !defined(AFX_PROCESSADOR_H__0B833749_9228_49C0_9AF4_1F7B28D1DD1D__INCLUDED_)
#define AFX_PROCESSADOR_H__0B833749_9228_49C0_9AF4_1F7B28D1DD1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "biblia/basico/Fabrica.h"
#include "biblia/util/instrucoes/Instrucao.h"

using namespace biblia::basico;

namespace biblia {
  namespace util {
    namespace instrucoes {
		/**
		 * � capaz de processar uma
		 * {@link biblia::util::instrucoes::Instrucao
		 * instru��o} de cada vez gerando um
		 * resultado que pode ser capturado
		 * atrav�s da fun��o {@link #gera()}.
		 */
		class Processador: public Fabrica {
			public:
				Processador::Processador() {};
				virtual Processador::~Processador() {};

				/**
				 * Processa uma instru��o que pode gerar
				 * resutado que pode ser resgatado
				 * atrav�s da fun��o gera().
				 *
				 * @see #gera()
				 */
				virtual Processador& Processador
						::processa(const Instrucao&) = 0;

				// Fabrica:

				/**
				 * Gera um resultado proveniente
				 * da fun��o processa().
				 *
				 * @see #processa(const Instrucao)
				 */
				virtual Objeto* Processador::gera() = 0;
		};
	}
  }
}

#endif // !defined(AFX_PROCESSADOR_H__0B833749_9228_49C0_9AF4_1F7B28D1DD1D__INCLUDED_)
