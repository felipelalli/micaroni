/*
 * $RCSfile: ExibidorDeRelatorio.h,v $
 * $Date: 2004/04/26 20:59:05 $
 * $Revision: 1.1 $
 * $Name:  $
 * $Author: felipe $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#include "biblia/jogos/frutinha/antigo/TelaCompleta.h"
#include "biblia/jogos/frutinha/antigo/Relatorio.h"
#include "biblia/jogos/frutinha/antigo/Marcacao.h"
#include "biblia/jogos/frutinha/antigo/MensagemBmp.h"
#include "biblia/jogos/frutinha/antigo/LinhaDeUmRelatorio.h"
#include "biblia/jogos/frutinha/antigo/Menu.h"

using namespace biblia::visual;

#ifndef TROPICAL_SBS_EXIBIDOR_DE_RELATORIO_H_SW
#define TROPICAL_SBS_EXIBIDOR_DE_RELATORIO_H_SW

namespace biblia{
	namespace jogos {
		namespace frutinha {
			namespace antigo {

				class ExibidorDeRelatorio {

					private:
						TelaCompleta& pTela;

						MensagemBmp& pFonte;
						MensagemBmp& pFonteLuminosa;
						MensagemBmp& pFonteNegrito;
						MensagemBmp& pFonteTitulo;
						MensagemBmp& pFontePequena;

						Marcacao* pBordaDireita;
						Marcacao* pBordaEsquerda;
						Marcacao* pBordaMeio;

						void pPosicionaNaTabela(
								CoisaNaTela& coisa, Tabela& tabela,
								int linha, int coluna);

						CoisaNaTela* pExibeTabela(Tabela& tabela,BITMAP* fundo=NULL,int pX=0,int pY=0,int tX=0,int tY=0);
						CoisaNaTela* pExibeLabel(Label& label);
						CoisaNaTela* pExibeLabelSenha(LabelSenha& label);
						CoisaNaTela* pExibeInput(Input& input);
						CoisaNaTela* pExibeInputSenha(InputSenha& input);
						CoisaNaTela* pExibeInputNumrico(InputNumerico& input);
						CoisaNaTela* pExibeVelocidadeDasBolas(VelocidadeDasBolas& velocidade);
						CoisaNaTela* pExibeMenu(Menu& menu, int tX);

					protected:
						CoisaNaTela* componenteEmCoisa(
								ComponenteDeUmRelatorio*, BITMAP* fundo=NULL,
								int pX=0,int pY=0,int tX=0,int tY=0);

					public:
						ExibidorDeRelatorio(
								TelaCompleta& tela,
								MensagemBmp& fonte,
								MensagemBmp& fonteLuminosa,
								MensagemBmp& fonteNegrito,
								MensagemBmp& fonteTitulo,
								MensagemBmp& fontePequena);

						~ExibidorDeRelatorio();

						ExibidorDeRelatorio& ExibidorDeRelatorio
								::exibe(ComponenteDeUmRelatorio*,
										bool mescla = false);
				};
			}
		}
	}
}
#endif
