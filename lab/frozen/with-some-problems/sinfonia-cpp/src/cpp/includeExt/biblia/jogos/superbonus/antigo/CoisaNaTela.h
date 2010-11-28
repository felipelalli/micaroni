/*
 * $RCSfile: CoisaNaTela.h,v $
 * $Date: 2003/05/29 21:08:18 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */
#ifndef COISA_NA_TELA_SW_H
#define COISA_NA_TELA_SW_H

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/superbonus/antigo/SpriteAntigo.h"
#include "biblia/armazenamento/volatil/Lista.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

namespace biblia{
	namespace jogos {
		namespace superbonus {
			namespace antigo {
				class CoisaNaTela: public Objeto {

					private:
						//unsigned int pTempo;
						unsigned int pTransparencia;
						bool pDefinida;

					protected:
						SpriteAntigo* pSprite;

						//utiliza uma lista de area para possibilitar quadros de tamanhos diferentes
						Lista* pListaArea;

					public:
						CoisaNaTela::CoisaNaTela();
						CoisaNaTela::~CoisaNaTela();

						virtual SpriteAntigo& CoisaNaTela::define(
								SpriteAntigo* sprite, Lista* listaArea,
								unsigned int transparencia = 0);

						virtual bool CoisaNaTela::definida();
						virtual SpriteAntigo& CoisaNaTela::sprite();
						virtual Area& CoisaNaTela::area();

						virtual Area& CoisaNaTela::area(unsigned int qualArea);
						virtual unsigned int CoisaNaTela::transparencia() const;
						virtual BITMAP* CoisaNaTela::imagem();

						virtual CoisaNaTela& CoisaNaTela::move(
								const int& x, const int& y);

						virtual CoisaNaTela& CoisaNaTela::moveAbsoluto(
								const int& x, const int& y);

						virtual CoisaNaTela& CoisaNaTela::
							transparencia(const unsigned int& transparencia);

						virtual CoisaNaTela& CoisaNaTela::desenha(TelaCompleta& tela);

						virtual CoisaNaTela& CoisaNaTela::desenha(TelaCompleta& tela, Area& areaRedefinida);

						virtual CoisaNaTela& CoisaNaTela::desenha(
								TelaCompleta& tela, unsigned int qualQuadro);

						virtual CoisaNaTela& CoisaNaTela::liberaSprite();
						virtual CoisaNaTela& CoisaNaTela::liberaArea();

						CoisaNaTela& CoisaNaTela::libera() {
							this->liberaSprite();
							this->liberaArea();
							return *this;
						}
				};
			}
		}
	}
}
#endif
