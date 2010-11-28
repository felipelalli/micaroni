/*
 * $RCSfile: TelaCompleta.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */


#ifndef TROPICAL_SBS_TELA_COMPLETA_DIRTY_SW_H
#define TROPICAL_SBS_TELA_COMPLETA_DIRTY_SW_H

#include "biblia/mais/allegro/FabricaDeImagensAllegroSegura.h"
#include "biblia/mais/allegro/TelaAllegro.h"
#include "biblia/basico/Objeto.h"
#include "biblia/io/disco/ArquivoBasico.h"
#include "biblia/visual/Area.h"
#include <stdio.h>

using namespace biblia::basico;
using namespace biblia::io::disco;
using namespace biblia::mais::allegro;

namespace biblia {
	namespace jogos {
		namespace frutinha {
			namespace antigo {
				class TelaCompleta : public Objeto {
					private:
						BITMAP* pBuffer;
						BITMAP* pFundo;
						BITMAP* pFundoOriginal;
						BITMAP* pFundoAnterior;
						unsigned int pQuantasAreas;

						bool pSincroniza;
						static ChaveSeguranca* pKey;
						static FabricaDeImagensAllegroSegura* pF;

					protected:
						TelaCompleta& poeNoBuffer(COMPILED_SPRITE*, const Area&);
						TelaCompleta& poeNoBuffer(RLE_SPRITE*,const Area&);
						TelaCompleta& poeNoBuffer(BITMAP*, const Area&);
						TelaCompleta& TelaCompleta::poeNoBuffer(BITMAP* bitmap, const Area& areaOriginal, const Area& areaRedefinida);
						TelaCompleta& poeNoBuffer(BITMAP*, const Area&,
									  const int& transparencia);
						TelaCompleta& poeNoBuffer(RLE_SPRITE*, const Area&,
									  const int& transparencia);

					public:
						TelaCompleta(FabricaDeImagensAllegroSegura&);
						~TelaCompleta();

						static void modoSeguro(ChaveSeguranca* key) {
							TelaCompleta::pKey = key;
						}

						//Acoes:
						TelaCompleta& cola(BITMAP*, const Area&);
						TelaCompleta& cola(BITMAP* bitmap, const Area& area,const Area& area2);
						TelaCompleta& cola(BITMAP*, const Area&, const int& transparencia);
						TelaCompleta& cola(RLE_SPRITE*,const Area&, const int& transparencia);

						TelaCompleta& cola(COMPILED_SPRITE*,const Area&);
						TelaCompleta& cola(RLE_SPRITE*,const Area&);


						TelaCompleta& limpa();
						TelaCompleta& desenha();

						TelaCompleta& redefineFundo(BITMAP* fundo = NULL);
						TelaCompleta& limpaFundo(Area&);
						TelaCompleta& mesclaNoFundo(BITMAP*, const Area&);
						TelaCompleta& mesclaNoFundo(COMPILED_SPRITE*,const Area&);
						TelaCompleta& mesclaNoFundo(RLE_SPRITE*,const Area&);
						TelaCompleta& mesclaNoFundo(BITMAP*, const Area&,
										unsigned int transparencia);

						TelaCompleta& sincroniza();
						TelaCompleta& dessincroniza();
						bool sincronizado() const;

						static BITMAP* carrega(const char* nomeArquivoBasico);

						static BITMAP* criaVazio(const unsigned int& tamanhoX,
									 const unsigned int& tamanhoY);

						static void limpa(BITMAP*);
						static void destroi(BITMAP*);

						static void mescla(BITMAP* origem, BITMAP* destino,
								   const Area& areaOrigem,
								   const Area& areaDestino);

						TelaCompleta& TelaCompleta::mescla(BITMAP* origem, BITMAP* destino,const Area& area,unsigned int transparencia);


						void linhaFundo(int x1, int y1,
										int x2, int y2, int cor);

						void linha(int x1, int y1,
								   int x2, int y2, int cor);

						void circulo(int x, int y,
									 int raio, int cor,
									 bool preenchido = true);

						static void linha(BITMAP* figura, int x1, int y1,
										 int x2, int y2, int cor);

						static void circulo(BITMAP* figura,	int x, int y,
											int raio, int cor,
											bool preenchido = true);

						static int cor(int r, int g, int b);
						static int transparencia(int porcentagem);
						static unsigned int tamanhoX();
						static unsigned int tamanhoY();

						//Verificacoes:
						BITMAP* buffer() const {
							return this->pBuffer;
						}

						BITMAP* fundo() const {
							return this->pFundo;
						}
				};
			}
		}
	}
}
#endif
