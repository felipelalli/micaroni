/*
 * $RCSfile: GerenciadorLicenca.h,v $
 * $Date: 2005/01/19 17:21:52 $
 * $Revision: 1.3 $
 *
 * Implementação da biblioteca Bíblia.
 * Streamworks, outubro de 2002. ($Name:  $ , $Author: fernandofernandes $)
 */

#include "biblia/jogos/specialUpgrade/antigo/Marcacao.h"
#include "biblia/jogos/specialUpgrade/antigo/MensagemBmp.h"
#include "biblia/jogos/specialUpgrade/antigo/Relatorio.h"
#include "biblia/jogos/specialUpgrade/antigo/ExibidorDeRelatorio.h"
#include "biblia/jogos/specialUpgrade/io/botoes/Botoes.h"
#include "biblia/jogos/specialUpgrade/antigo/Sistema.h"
#include "biblia/seguranca/ControleLicenca.h"

#include "biblia/util/Versao.h"
using namespace biblia::util;

using namespace biblia::seguranca;
using namespace biblia::jogos::specialUpgrade::io::botoes;

#ifndef AGES_SPECIAL_UPGRADE_SBS_GERENCIADOR_LICENSA_H_SW
#define AGES_SPECIAL_UPGRADE_SBS_GERENCIADOR_LICENSA_H_SW

namespace biblia {
	namespace jogos {
		namespace specialUpgrade {
			namespace antigo {

				class GerenciadorLicenca {
					private:
						Versao& pVersao;
						ControleLicenca& pControleLicenca;
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
