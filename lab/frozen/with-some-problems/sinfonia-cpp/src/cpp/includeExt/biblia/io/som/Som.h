/*
 * $RCSfile: Som.h,v $
 * $Date: 2005/01/20 21:28:45 $
 * $Revision: 1.5 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */

#if !defined(AFX_SOM_H__40E5D365_C478_4E1B_B587_00E3E87F00A3__INCLUDED_)
#define AFX_SOM_H__40E5D365_C478_4E1B_B587_00E3E87F00A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include "biblia/basico/Objeto.h"

using namespace std;
using namespace biblia::basico;

namespace biblia {
  namespace io {
    namespace som {

		/**
		 * Representa um som bem simples. Deve-se
		 * derivar desta um som específico.
		 *
		 * @see biblia::io::som::ComponenteSonoro
		 */
		class Som: public Objeto {
			private:
				std::string Som::pChave;

			protected:
				Som::Som(const std::string chave);

			public:
				static int Som::PRIORIDADE_PARALELA;

				virtual Som::~Som();
				virtual bool Som::mesmaChave(const Som& som) const;
				virtual bool Som::mesmaChave(
						const std::string& chave) const;

				/**
				 * Toca em tal volume. Se tiver outro tocando
				 * ele 'toca por cima'. Use -1 para que o som
				 * seja 'paralelo'.
				 */
				virtual Som& Som::play(
						double volume = 100.0,
						int prioridade = PRIORIDADE_PARALELA) = 0;

				virtual Som& Som::stop() = 0;
				virtual Som& Som::paraTudo() = 0;
				virtual bool Som::tocando() const = 0;
				virtual bool Som::temSomTocandoMaiorQue(
						int prioridade) const = 0;

				// Objeto:
				virtual std::string Som::emString() const;
		};
	}
  }
}

#endif // !defined(AFX_SOM_H__40E5D365_C478_4E1B_B587_00E3E87F00A3__INCLUDED_)
