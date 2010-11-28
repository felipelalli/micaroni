/*
 * $RCSfile: GerenciadorLicenca.h,v $
 * $Date: 2003/05/29 21:13:19 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: felipe $)
 */

#include "biblia/jogos/superbonus/antigo/Marcacao.h"
#include "biblia/jogos/superbonus/antigo/MensagemBmp.h"
#include "biblia/jogos/superbonus/antigo/Relatorio.h"
#include "biblia/jogos/superbonus/antigo/ExibidorDeRelatorio.h"
#include "biblia/jogos/superbonus/io/botoes/Botoes.h"
#include "biblia/jogos/superbonus/antigo/Sistema.h"
#include "biblia/seguranca/ControleLicenca.h"

using namespace biblia::seguranca;
using namespace biblia::jogos::superbonus::io::botoes;

#ifndef GERENCIADOR_LICENSA_H_SW
#define GERENCIADOR_LICENSA_H_SW

namespace biblia {
	namespace jogos {
		namespace superbonus {
			namespace antigo {

				class GerenciadorLicenca {
					private:
						ControleLicenca& pControleLicenca;
						Botoes& pBotoes;
						/*fontes usadas para o input*/
						MensagemBmp* pFonteSelecionada;
						MensagemBmp* pFonteConvencional;
						MensagemBmp* pFonteNegrito;
						MensagemBmp* pFonteTitulo;
						MensagemBmp* pFontePequena;

						Marcacao* pFundo;

						Lista* pListaInput;
						Lista* pListaLabel;

						int pQuantosCaracteres;
						int pInputAtual;

						ExibidorDeRelatorio* pExibidor;
						char* pMontaString();

						void pAdicionaLabelNaTabela(int l, int c,Tabela&, Label*);
						void pAdicionaInputNaTabela(int l, int c,Tabela&, Input*);

						void  pProximoInput(bool pedeSenhaAntiga);
						void  pInputAnterior(bool pedeSenhaAntiga);

						void  pProximoCaracter(bool pedeSenhaAntiga);
						void  pCaracterAnterior(bool pedeSenhaAntiga);

						bool pTeclado;
						bool segundaTela;
						TelaCompleta& pTela;

					protected:
						GerenciadorLicenca& GerenciadorLicenca::limpa();

					public:
						GerenciadorLicenca(TelaCompleta& tela,
								ControleLicenca& controle,
								Botoes& botoes);

						~GerenciadorLicenca();
						//cada caracter eh representador por dois inputs
						void GerenciadorLicenca::verificacaoDeLicencaValida(
									int qtsCaracteres, bool pedeSenhaAntiga);

						bool GerenciadorLicenca::aviso(
								int dias);

						ControleLicenca& controle() {
							return this->pControleLicenca;
						}
				};
			}
		}
	}
}
#endif
