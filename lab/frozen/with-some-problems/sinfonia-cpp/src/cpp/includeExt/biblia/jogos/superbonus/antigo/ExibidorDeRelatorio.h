/*
 * $RCSfile: ExibidorDeRelatorio.h,v $
 * $Date: 2004/05/17 21:34:08 $
 * $Revision: 1.4 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/jogos/superbonus/antigo/TelaCompleta.h"
#include "biblia/jogos/superbonus/antigo/Relatorio.h"
#include "biblia/jogos/superbonus/antigo/Marcacao.h"
#include "biblia/jogos/superbonus/antigo/MensagemBmp.h"
#include "biblia/jogos/superbonus/antigo/LinhaDeUmRelatorio.h"
#include "biblia/jogos/superbonus/antigo/Menu.h"

using namespace biblia::visual;

#include "biblia/geral/Constantes.h"
using namespace biblia::geral;

#ifndef EXIBIDOR_DE_RELATORIO_H_SW
#define EXIBIDOR_DE_RELATORIO_H_SW

namespace biblia{
	namespace jogos {
		namespace superbonus {
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
