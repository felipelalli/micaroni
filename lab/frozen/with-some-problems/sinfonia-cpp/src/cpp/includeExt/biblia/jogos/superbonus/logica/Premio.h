/*
 * $RCSfile: Premio.h,v $
 * $Date: 2003/05/29 21:18:33 $
 * $Revision: 1.6 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#ifndef PREMIO_SW_H
#define PREMIO_SW_H

#define NENHUM      100
#define CANTOS      101
#define LINHA       102
#define LINHA_DUPLA 103
#define BINGO       104
#define ACUMULADO   105

#define CANTOS_DOBRO      106
#define LINHA_DOBRO       107
#define LINHA_DUPLA_DOBRO 108
#define BINGO_DOBRO       109


#define FALTA_UM_BINGO       97
#define FALTA_UM_LINHA_DUPLA 98
#define FALTA_UM             99

#include <stdlib.h>

#include "biblia/basico/Objeto.h"
using namespace biblia::basico;

#include "biblia/util/StrToken.h"
using namespace biblia::util;

namespace biblia {
  namespace jogos {
    namespace superbonus {
	  namespace logica {

		class Premio : public Objeto
		{
			private:
				unsigned int pPremio;
				unsigned int pCartela;
				unsigned int pLinha;
				unsigned int pColuna;
				unsigned int pColFaltaUm [3];
				bool pLinhaPreenchida [3];

				unsigned int pQtdBolasNecessarias;

			public:
				Premio::Premio ();
				Premio::Premio (char* strPremio);

				Premio::~Premio ();

				unsigned int Premio::getPremio() const;
				unsigned int Premio::getCartela() const;
				unsigned int Premio::getLinha() const;
				unsigned int Premio::getColuna() const;
				unsigned int Premio::getColFaltaUm (unsigned int linha) const;
				unsigned int Premio::qtsFaltaUm ();
				bool         Premio::getLinhaPreenchida (unsigned int linha);
				unsigned int Premio::qtdBolasNecessarias ();

				void Premio::setCartela (unsigned int cartela);
				void Premio::setPremio  (unsigned int premio);
				void Premio::setLinha   (unsigned int linha);
				void Premio::setColuna  (unsigned int coluna);
				void Premio::setFaltaUm (unsigned int linha, unsigned int coluna);
				void Premio::setLinhaPreenchida (unsigned int linha);

				void Premio::zerar();

				char* Premio::toString ();
				void Premio::fromString (const char* strPremio);

				static char* Premio::strPremio (int premio);

		};
	  }
	}
  }
}

#endif