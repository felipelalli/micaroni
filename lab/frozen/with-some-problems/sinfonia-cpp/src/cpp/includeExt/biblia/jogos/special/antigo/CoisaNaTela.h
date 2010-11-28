/*
 * $RCSfile: CoisaNaTela.h,v $
 * $Date: 2004/06/18 01:50:27 $
 * $Revision: 1.2 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipelalli $)
 */
#ifndef SBS_COISA_NA_TELA_SW_H
#define SBS_COISA_NA_TELA_SW_H

#ifdef WIN32
#pragma warning(disable:4786) // para tirar o warn bizarro do Visual C++
#pragma warning(disable:4503)
#endif

#include "biblia/basico/Objeto.h"
#include "biblia/jogos/special/antigo/SpriteAntigo.h"
#include "biblia/armazenamento/volatil/Lista.h"

using namespace biblia::basico;
using namespace biblia::armazenamento::volatil;

namespace biblia{
	namespace jogos {
		namespace special {
			namespace antigo {
				class CoisaNaTela: public Objeto {

					private:
						//unsigned int pTempo;
						unsigned int pTransparencia;
						bool pDefinida;

					protected:
						SpriteAntigo* pSprite;

						//utiliza uma lista de area para possibilitar quadros de tamanhos diferentes
						biblia::armazenamento::volatil::Lista* pListaArea;

					public:
						CoisaNaTela::CoisaNaTela();
						CoisaNaTela::~CoisaNaTela();

						virtual SpriteAntigo& CoisaNaTela::define(
								SpriteAntigo* sprite, biblia::armazenamento::volatil::Lista* listaArea,
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
