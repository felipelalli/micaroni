/*
 * $RCSfile: GerenciadorLicenca.h,v $
 * $Date: 2004/08/10 15:13:38 $
 * $Revision: 1.2 $
 * $Name:  $
 * $Author: fernandofernandes $
 *
 * Implementação da Nova Bíblia.
 * Streamworks, outubro de 2003.
 */

#include "biblia/jogos/frutinha/antigo/Marcacao.h"
#include "biblia/jogos/frutinha/antigo/MensagemBmp.h"
#include "biblia/jogos/frutinha/antigo/Relatorio.h"
#include "biblia/jogos/frutinha/antigo/ExibidorDeRelatorio.h"
#include "biblia/jogos/frutinha/io/botoes/Botoes.h"
#include "biblia/jogos/frutinha/antigo/Sistema.h"
#include "biblia/seguranca/ControleLicenca.h"

#include "biblia/util/Versao.h"
using namespace biblia::util;

using namespace biblia::seguranca;
using namespace biblia::jogos::frutinha::io::botoes;

#ifndef TROPICAL_SBS_GERENCIADOR_LICENSA_H_SW
#define TROPICAL_SBS_GERENCIADOR_LICENSA_H_SW

namespace biblia {
	namespace jogos {
		namespace frutinha {
			namespace antigo {

				class GerenciadorLicenca {
					private:
						ControleLicenca& pControleLicenca;
						Versao& pVersao;
						Botoes& pBotoes;
						/*fontes usadas para o input*/
						MensagemBmp* pFonteSelecionada;
						MensagemBmp* pFonteConvencional;
						MensagemBmp* pFonteNegrito;
						MensagemBmp* pFonteTitulo;
						MensagemBmp* pFontePequena;

						Marcacao* pFundo;

						biblia::armazenamento::volatil::Lista* pListaInput;
						biblia::armazenamento::volatil::Lista* pListaLabel;

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
								Versao& versao,
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
